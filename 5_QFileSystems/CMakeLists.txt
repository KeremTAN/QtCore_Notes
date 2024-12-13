cmake_minimum_required(VERSION 3.16)

project(5_QFileSystems LANGUAGES CXX)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(QT NAMES Qt6 Qt5 REQUIRED COMPONENTS Core)
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Core)

add_executable(5_QFileSystems
  main.cpp
  IODevice.h
  TextStream.h
  DataStream.h
)
target_link_libraries(5_QFileSystems Qt${QT_VERSION_MAJOR}::Core)

include(GNUInstallDirs)
install(TARGETS 5_QFileSystems
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)
