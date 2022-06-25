# CMakeList.txt: проект CMake для 38_5_3_VS; включите исходный код и определения,
# укажите здесь логику для конкретного проекта.
#
cmake_minimum_required (VERSION 3.8)

project ("38_5_3_VS")

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)

find_package(Qt5 COMPONENTS
        Core
        Gui
        Widgets
        REQUIRED
        )

# Добавьте источник в исполняемый файл этого проекта.
add_executable (38_5_3_VS "38_5_3_VS.cpp" )
target_link_libraries(38_5_3_VS
        Qt5::Core
        Qt5::Gui
        Qt5::Widgets
        )

if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET 38_5_3_VS PROPERTY CXX_STANDARD 20)
endif()

