cmake_minimum_required(VERSION 3.0.0)
project(Chess-Terminal-Client)
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_FLAGS "-Wall -g")

include_directories(${CMAKE_SOURCE_DIR})
include_directories(${CMAKE_SOURCE_DIR}/externals)
include_directories(${CMAKE_SOURCE_DIR}/externals/asio)

set(SOURCE
    ${SOURCE}
    ${PROTO_SRCS}
    ${CMAKE_CURRENT_SOURCE_DIR}/main.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/networkinterface.cpp
  )

set(HEADERS
    ${HEADERS}
    ${PROTO_HDRS}
    ${CMAKE_CURRENT_SOURCE_DIR}/networkinterface.hpp
)

add_executable(chess-terminal-client.bin ${SOURCE} ${HEADERS})
