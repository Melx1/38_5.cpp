# CMakeList.txt: проект CMake для 38_5_2; включите исходный код и определения,
# укажите здесь логику для конкретного проекта.
#
cmake_minimum_required (VERSION 3.8)

project ("38_5_2")
set(CMAKE_CXX_STANDARD 20)

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)

find_package(Qt5 COMPONENTS
        Core
        Gui
        Widgets
        WebEngineWidgets
        REQUIRED
        )

# Добавьте источник в исполняемый файл этого проекта.
add_executable (38_5_2 "38_5_2.cpp")
target_link_libraries(38_5_2
        Qt5::Core
        Qt5::Gui
        Qt5::Widgets
        Qt5::WebEngineWidgets
        )

if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET 38_5_2 PROPERTY CXX_STANDARD 20)
endif()

# TODO: Добавьте тесты и целевые объекты, если это необходимо.
