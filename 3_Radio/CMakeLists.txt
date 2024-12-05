cmake_minimum_required(VERSION 3.16)

project(Radio LANGUAGES CXX)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(QT NAMES Qt6 Qt5 REQUIRED COMPONENTS Core)
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Core)

add_executable(Radio
  main.cpp

  station.h station.cpp
  radio.h radio.cpp
)
target_link_libraries(Radio Qt${QT_VERSION_MAJOR}::Core)

if(APPLE)
    set_target_properties(Radio PROPERTIES MACOSX_BUNDLE OFF)
endif()

include(GNUInstallDirs)
install(TARGETS Radio
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)
