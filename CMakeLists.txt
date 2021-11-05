cmake_minimum_required(VERSION 3.19)
project(Log)

set(CMAKE_CXX_STANDARD 14)

add_executable(Log main.cpp Logger.cpp Logger.h LogStream.cpp LogStream.h MicroTimestamp.cpp MicroTimestamp.h LoggerOutput.cpp LoggerOutput.h LogFile.cpp LogFile.h)