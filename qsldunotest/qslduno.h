#ifndef QSLDUNO_H
#define QSLDUNO_H


extern "C" {
#include "sqlite3.h"
}

#include <QtSql/qsqldriver.h>
#include <QtSql/qsqlresult.h>

///////////////////////////////////////////////////////////////////////////////
// CHANGE : According to your qt path
///////////////////////////////////////////////////////////////////////////////
#include "qsqlcachedresult.h"

struct sqlite3;

#ifdef QT_PLUGIN
#define Q_EXPORT_SQLDRIVER_SQLITE
#else
#define Q_EXPORT_SQLDRIVER_SQLITE Q_SQL_EXPORT
#endif

QT_BEGIN_HEADER
QT_BEGIN_NAMESPACE

class QSLDUnoCipher;
class QSLDUnoCipherPrivate;
class QSLDUnoCipherResultPrivate;



class QSLDUnoCipherResult : public QSqlCachedResult
{
    friend class QSLDUnoCipher;
    friend class QSLDUnoCipherResultPrivate;
public:
    explicit QSLDUnoCipherResult(const QSLDUnoCipher* db);
    ~QSLDUnoCipherResult();
    QVariant handle() const;

protected:
    bool gotoNext(QSqlCachedResult::ValueCache& row, int idx);
    bool reset(const QString &query);
    bool prepare(const QString &query);
    bool exec();
    int size();
    int numRowsAffected();
    QVariant lastInsertId() const;
    QSqlRecord record() const;
    void detachFromResultSet();
    void virtual_hook(int id, void *data);

private:
    QSLDUnoCipherResultPrivate* d;
};



class Q_EXPORT_SQLDRIVER_SQLITE QSLDUnoCipher : public QSqlDriver
{
    Q_OBJECT
    friend class QSLDUnoCipherResult;

private:
    QSLDUnoCipherPrivate* d;
    static bool zDriverRegistered;

public:
    explicit QSLDUnoCipher(QObject *parent = 0);
    explicit QSLDUnoCipher(sqlite3 *connection, QObject *parent = 0);
    ~QSLDUnoCipher();
    bool hasFeature(DriverFeature f) const;
    bool open(const QString & db,
                   const QString & user,
                   const QString & password,
                   const QString & host,
                   int port,
                   const QString & connOpts);
    void close();
    QSqlResult *createResult() const;
    bool beginTransaction();
    bool commitTransaction();
    bool rollbackTransaction();
    QStringList tables(QSql::TableType) const;

    QSqlRecord record(const QString& tablename) const;
    QSqlIndex primaryIndex(const QString &table) const;
    QVariant handle() const;
    QString escapeIdentifier(const QString &identifier, IdentifierType) const;

    static bool REGISTER_DRIVER();
};

QT_END_NAMESPACE
QT_END_HEADER

#endif // QSLDUNO_H
