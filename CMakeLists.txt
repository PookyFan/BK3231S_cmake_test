cmake_minimum_required(VERSION 3.0.0)

set(CMAKE_TRY_COMPILE_TARGET_TYPE "STATIC_LIBRARY")
set(CMAKE_SYSTEM_NAME Generic)
set(CMAKE_SYSTEM_PROCESSOR arm)
SET(CMAKE_CROSSCOMPILING 1)

project(BK3431_SDK VERSION 0.1.0)

set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

file(GLOB_RECURSE Src ${CMAKE_SOURCE_DIR} "src/*.c")
file(GLOB_RECURSE Include LIST_DIRECTORIES true RELATIVE ${CMAKE_SOURCE_DIR} "include")
list(FILTER Include INCLUDE REGEX "include")

#message("Include dirs:")
#message("${Include}")

add_compile_definitions(__USE_INLINES__)

add_executable(fw ${Src})
target_include_directories(fw PUBLIC ${Include})
target_link_libraries(fw PRIVATE "${CMAKE_SOURCE_DIR}/lib/BK3231S_LIB.lib" "m")

SET(CMAKE_C_FLAGS "-w -march=ARMv5TE -fshort-wchar ${CMAKE_C_FLAGS}")
SET(CMAKE_EXE_LINKER_FLAGS "--specs=nosys.specs -fshort-wchar ${CMAKE_EXE_LINKER_FLAGS}")
