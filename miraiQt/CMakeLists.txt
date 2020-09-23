cmake_minimum_required(VERSION 3.5)

project(miraiQt LANGUAGES CXX)

#通过环境变量设置qt库
#QtDefault32 32位
#QtDefault64 64位
#set(CMAKE_PREFIX_PATH $ENV{QtDefault64})

#打开相关自动选项
set(CMAKE_INCLUDE_CURRENT_DIR ON)
set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# QtCreator supports the following variables for Android, which are identical to qmake Android variables.
# Check http://doc.qt.io/qt-5/deployment-android.html for more information.
# They need to be set before the find_package(Qt5 ...) call.

#if(ANDROID)
#    set(ANDROID_PACKAGE_SOURCE_DIR "${CMAKE_CURRENT_SOURCE_DIR}/android")
#    if (ANDROID_ABI STREQUAL "armeabi-v7a")
#        set(ANDROID_EXTRA_LIBS
#            ${CMAKE_CURRENT_SOURCE_DIR}/path/to/libcrypto.so
#            ${CMAKE_CURRENT_SOURCE_DIR}/path/to/libssl.so)
#    endif()
#endif()

#查找Qt模块
find_package(Qt5 COMPONENTS Widgets Network WebSockets LinguistTools REQUIRED)

#qt翻译家
set(TS_FILES
    miraiQt_zh_CN.ts
)

set(HEADERS
    mainwindow.h
    logindlg.h
    httpclient.h
    onebot.h
    websocketclient.h
    httpexception.h
    event.h
    QBlockingQueue.h
    bytearrayconverter.h
    noticeevent.h
    messageevent.h
    requestevent.h
    metaevent.h
)

set(SOURCES
    main.cpp
    mainwindow.cpp
    logindlg.cpp
    httpclient.cpp
    onebot.cpp
    websocketclient.cpp
    httpexception.cpp
    event.cpp
    QBlockingQueue.cpp
    bytearrayconverter.cpp
    noticeevent.cpp
    messageevent.cpp
    requestevent.cpp
    metaevent.cpp
    )

set(FORMS
    mainwindow.ui
    logindlg.ui

)
INCLUDE_DIRECTORIES(
${CMAKE_CURRENT_BINARY_DIR}/)

add_executable(${PROJECT_NAME} ${HEADERS} ${SOURCES} ${FORMS})

target_link_libraries(${PROJECT_NAME} Qt5::Widgets Qt5::Network Qt5::WebSockets)

qt5_use_modules(${PROJECT_NAME} Core Widgets Network WebSockets)

qt5_create_translation(QM_FILES ${CMAKE_SOURCE_DIR} ${TS_FILES})
