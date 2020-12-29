cmake_minimum_required(VERSION 3.14)

project(Controll_App LANGUAGES CXX)

set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# QtCreator supports the following variables for Android, which are identical to qmake Android variables.
# Check https://doc.qt.io/qt/deployment-android.html for more information.
# They need to be set before the find_package(...) calls below.

#if(ANDROID)
#    set(ANDROID_PACKAGE_SOURCE_DIR "${CMAKE_CURRENT_SOURCE_DIR}/android")
#    if (ANDROID_ABI STREQUAL "armeabi-v7a")
#        set(ANDROID_EXTRA_LIBS
#            ${CMAKE_CURRENT_SOURCE_DIR}/path/to/libcrypto.so
#            ${CMAKE_CURRENT_SOURCE_DIR}/path/to/libssl.so)
#    endif()
#endif()

set(PROJECT_SOURCES
    appcontroller.h
    appcontroller.cpp
    protocol.h
    main.cpp
    qml.qrc
    )


file(GLOB QmlFiles
    "*.qml"
    "qml/*.qml")
file(GLOB SrcFiles "*.qrc")

add_custom_target(${PROJECT_NAME}-qml-main SOURCES ${QmlFiles})
add_custom_target(${PROJECT_NAME}-resources SOURCES ${SrcFiles})

find_package(QT NAMES Qt6 Qt5 COMPONENTS Core Quick SerialPort REQUIRED)
find_package(Qt${QT_VERSION_MAJOR} COMPONENTS Core Quick SerialPort REQUIRED)

if(${QT_VERSION_MAJOR} GREATER_EQUAL 6)
    qt_add_executable(Controll_App
        ${PROJECT_SOURCES}
    )
else()
    if(ANDROID)
        add_library(Controll_App SHARED
            ${PROJECT_SOURCES}
        )
    else()
        add_executable(Controll_App
          ${PROJECT_SOURCES}
        )
    endif()
endif()

target_compile_definitions(Controll_App
  PRIVATE $<$<OR:$<CONFIG:Debug>,$<CONFIG:RelWithDebInfo>>:QT_QML_DEBUG>)
target_link_libraries(Controll_App
  PRIVATE Qt${QT_VERSION_MAJOR}::Core Qt${QT_VERSION_MAJOR}::Quick Qt${QT_VERSION_MAJOR}::SerialPort)
