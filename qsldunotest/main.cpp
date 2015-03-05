#include <QCoreApplication>
#include <QDebug>
#include <QByteArray>

#include <QSql>
#include <QSqlQuery>
#include <QSqlError>
#include <QSqlDatabase>

#include "qslduno.h"


///////////////////////////////////////////////////////////////////////////////
/// \brief testAES128
///
/// test aes128 bit encryption
///////////////////////////////////////////////////////////////////////////////
void testAES128(){
    QSqlDatabase mydb = QSqlDatabase::addDatabase("QSLDUNO","testAES128");
    mydb.setDatabaseName("testAES128.db"); //database file
    mydb.setPassword("123456"); //password
    if (!mydb.open()) {
        qDebug() << "cannot open database";
        return ;
    } else {
        qDebug() << "database successfully opened";
    }

    //activate aes128 cipher not necessary it is activated by default

    qDebug() << "activating aes128 extension";
    mydb.exec("PRAGMA activate_extensions='see-aes128';");
    if(!mydb.lastError().text().isEmpty()) qDebug() <<"ERROR : " << mydb.lastError().text();

    //Lets create a table
    QSqlQuery query(mydb);
    if(!mydb.tables().contains("test",Qt::CaseInsensitive)){
        qDebug()<<"CREATING TABLE: " << "create table test (id integer primary key, number int);";
        query.exec("create table test (id integer primary key, number int);");

        qDebug() << "Inserting some random values";
        for(int i=0; i<100;++i){
            qsrand(i);//seed
            query.exec(
                        QString("insert into test (number) values (%1);").arg(qrand())
                       );
        }
    }


    if(!query.lastError().text().isEmpty()){
        qDebug() <<"ERROR : " <<query.lastError();
    }

    qDebug() << "select * from test;";
    query.exec("select * from test;");
    while (query.next()) {
        qDebug() <<"ID : " <<query.value(0).toInt() << " RANDOM NUMBER : " << query.value(1).toInt();
    }
    mydb.close();

}


///////////////////////////////////////////////////////////////////////////////
/// \brief testAES256
///
/// test aes256 bit encryption
///////////////////////////////////////////////////////////////////////////////
void testAES256(){
    QSqlDatabase mydb = QSqlDatabase::addDatabase("QSLDUNO","testAES256");
    mydb.setDatabaseName("testAES256.db"); //database file
    mydb.setPassword("123456"); //password
    if (!mydb.open()) {
        qDebug() << "cannot open database";
        return ;
    } else {
        qDebug() << "database successfully opened";
    }

    //activate aes128 cipher not necessary it is activated by default

    qDebug() << "activating aes256 extension";
    mydb.exec("PRAGMA activate_extensions='see-aes256';");
    if(!mydb.lastError().text().isEmpty()) qDebug() <<"ERROR : " << mydb.lastError().text();

    //Lets create a table
    QSqlQuery query(mydb);
    if(!mydb.tables().contains("test",Qt::CaseInsensitive)){
        qDebug()<<"CREATING TABLE: " << "create table test (id integer primary key, number int);";
        query.exec("create table test (id integer primary key, number int);");

        qDebug() << "Inserting some random values";
        for(int i=0; i<100;++i){
            qsrand(i);//seed
            query.exec(
                        QString("insert into test (number) values (%1);").arg(qrand())
                       );
        }
    }


    if(!query.lastError().text().isEmpty()){
        qDebug() <<"ERROR : " <<query.lastError();
    }

    qDebug() << "select * from test;";
    query.exec("select * from test;");
    while (query.next()) {
        qDebug() <<"ID : " <<query.value(0).toInt() << " RANDOM NUMBER : " << query.value(1).toInt();
    }
    mydb.close();

}
int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    QSLDUnoCipher::REGISTER_DRIVER();// REGISTER THE DRIVER

    qDebug() << "TEST AES128";
    qDebug() << "=======================================\n";
    testAES128();//test aes128 encryption;

    qDebug() << "\n";
    qDebug() << "\n";
    qDebug() << "\n";

    qDebug() << "TEST AES256";
    qDebug() << "==========================================\n";
    testAES256();//test aes256 encryption;

    return a.exec();
}
