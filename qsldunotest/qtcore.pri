win32{
win32-msvc* {

    LIBS += -lkernel32 \
            -luser32 \
            -lgdi32 \
            -lwinspool \
            -lcomdlg32 \
            -ladvapi32 \
            -lshell32 \
            -lole32 \
            -loleaut32 \
            -luuid \
            -lodbc32 \
            -lodbccp32 \
            -lws2_32 \
            -limm32 \
            -lwinmm \
            -lshlwapi \
            #-lfreetype246 \

    LIBS += \
            #-lqwindows \
            #-lqoffscreen\
            #-lqminimal \
            #-lQt5PlatformSupport \
            #-lqtharfbuzzng \
}

}
