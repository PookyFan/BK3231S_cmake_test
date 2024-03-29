cmake_minimum_required(VERSION 3.0.0)

set(CMAKE_TRY_COMPILE_TARGET_TYPE "STATIC_LIBRARY")
set(CMAKE_SYSTEM_NAME Generic)
set(CMAKE_SYSTEM_PROCESSOR arm)
SET(CMAKE_CROSSCOMPILING 1)

project(BK3431S_SDK VERSION 0.1.0 LANGUAGES C ASM)

set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

file(GLOB_RECURSE Src ${CMAKE_SOURCE_DIR} "src/*.c")
file(GLOB_RECURSE Include LIST_DIRECTORIES true RELATIVE ${CMAKE_SOURCE_DIR} "include")
list(FILTER Include INCLUDE REGEX "include")

add_compile_definitions(__USE_INLINES__)

add_executable(fw ${Src} "src/bootstrap.S")
target_include_directories(fw PUBLIC ${Include})
target_link_libraries(fw PRIVATE "${CMAKE_SOURCE_DIR}/lib/BK3231S_LIB.lib" "m")
set_target_properties(fw PROPERTIES LINK_DEPENDS "${CMAKE_SOURCE_DIR}/BK3431S.ld")
add_custom_command(TARGET fw PRE_BUILD COMMAND rm ARGS "-f" "${CMAKE_RUNTIME_OUTPUT_DIRECTORY}/*")
add_custom_command(
    TARGET fw POST_BUILD
    COMMAND ${CMAKE_OBJCOPY} ARGS -O binary $<TARGET_FILE:fw> $<TARGET_FILE:fw>.bin
    COMMAND python3 ARGS "${CMAKE_SOURCE_DIR}/prepare_image.py" $<TARGET_FILE:fw>.bin $<TARGET_FILE:fw>.img "${CMAKE_SOURCE_DIR}/config.bin")

SET(CMAKE_C_FLAGS "-march=ARMv5TE -fshort-wchar ${CMAKE_C_FLAGS}")
SET(CMAKE_EXE_LINKER_FLAGS "--specs=nosys.specs -fshort-wchar -T ${CMAKE_SOURCE_DIR}/BK3431S.ld ${CMAKE_EXE_LINKER_FLAGS}")
