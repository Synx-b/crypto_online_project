cmake_minimum_required(VERSION 3.9)
project(crypto_online_project)

set(CMAKE_CXX_STANDARD 11)
set(WT_CONNECTOR "whttp" CACHE STRING "Connector used (whttp or wtfcgi)")

add_subdirectory(src)