cmake_minimum_required(VERSION 3.16)
project(Music2 LANGUAGES CXX)

include(qt.cmake)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)


set(CMAKE_AUTOMOC ON)    # 处理 Q_OBJECT 宏
set(CMAKE_AUTOUIC ON)    # 处理 .ui 文件 → 生成 ui_*.h
set(CMAKE_AUTORCC ON)    # 处理 .qrc 资源文件



find_package(QT NAMES Qt6 Qt5 REQUIRED COMPONENTS Core)

find_package(Qt${QT_VERSION_MAJOR}
    COMPONENTS
        Core
        Gui
        Widgets
        multimedia
)
qt_standard_project_setup()

set(PROJECT_SOURCES
    ./Main/main.cpp
    ./Main/Music2.ui
    ./Main/Music2.h
    ./Main/Music2.cpp
    ./Main/Resource.qrc
    ./addmusic/addMusic.cpp
    ./addmusic/addMusic.h
    ./addmusic/addMusic.ui
    ./Test/text.cpp
    ./Test/text.h
    ./Test/text.ui
)

qt_add_executable(${PROJECT_NAME} ${PROJECT_SOURCES})

set_target_properties(${PROJECT_NAME}
    PROPERTIES
        WIN32_EXECUTABLE TRUE
)

target_link_libraries(${PROJECT_NAME}
    PUBLIC
        Qt::Core
        Qt::Gui
        Qt::Widgets
        Qt::Multimedia
)
