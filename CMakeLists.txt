cmake_minimum_required(VERSION 3.30)
project(vk_test)

set(CMAKE_CXX_STANDARD 20)

include_directories(${CMAKE_CURRENT_SOURCE_DIR}/include)


set(SOURCES
        ${CMAKE_CURRENT_SOURCE_DIR}/main.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/src/metric_manager.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/src/writer.cpp
)

set(HEADERS
        ${CMAKE_CURRENT_SOURCE_DIR}/include/metric.h
        ${CMAKE_CURRENT_SOURCE_DIR}/include/metric_manager.h
        ${CMAKE_CURRENT_SOURCE_DIR}/include/custom_metric.h
        ${CMAKE_CURRENT_SOURCE_DIR}/include/writer.h
)


add_executable(vk_test main.cpp
        ${SOURCES}
)

target_include_directories(
        vk_test
        PRIVATE
        ${CMAKE_CURRENT_SOURCE_DIR}/include
)

message(STATUS "HEADERS: ${HEADERS}")
message(STATUS "SOURCES: ${SOURCES}")
