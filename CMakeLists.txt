cmake_minimum_required(VERSION 3.30)
project(NTUST_OOP_113_2_Homework)

set(CMAKE_CXX_STANDARD 14)

### Find all dependencies(should be #include) in cpp file. ###
find_program(IWYU_EXE NAMES include-what-you-use iwyu_tool)
if (IWYU_EXE)
    set(CMAKE_CXX_INCLUDE_WHAT_YOU_USE ${IWYU_EXE})
    message("Load IWYU Success")
endif ()

### Add all quizzes to be executable. ###
# grab all directory start with prefix: "TS"
file(GLOB TS_DIRS RELATIVE ${CMAKE_SOURCE_DIR} "TS*")

foreach (dir ${TS_DIRS})
    # accept directory only
    if (NOT IS_DIRECTORY "${CMAKE_SOURCE_DIR}/${dir}")
        continue()
    endif ()

    # grab all .cpp file
    file(GLOB SRC_FILES "${CMAKE_SOURCE_DIR}/${dir}/*.cpp" "${CMAKE_SOURCE_DIR}/${dir}/*.h")
    if (SRC_FILES)
        add_executable(${dir} ${SRC_FILES})

        # Add #define NTUST_DEV for this executable
        target_compile_definitions(${dir} PRIVATE NTUST_DEV)
    endif ()
endforeach ()



### Add all MID to be executable. ###
file(GLOB MID_DIRS RELATIVE ${CMAKE_SOURCE_DIR} "*OOPMidQ*")

foreach (dir ${MID_DIRS})
    # accept directory only
    if (NOT IS_DIRECTORY "${CMAKE_SOURCE_DIR}/${dir}")
        continue()
    endif ()

    # grab all .cpp file
    file(GLOB SRC_FILES "${CMAKE_SOURCE_DIR}/${dir}/*.cpp" "${CMAKE_SOURCE_DIR}/${dir}/*.h")
    if (SRC_FILES)
        add_executable(${dir} ${SRC_FILES})

        # Add #define NTUST_DEV for this executable
        target_compile_definitions(${dir} PRIVATE NTUST_DEV)
    endif ()
endforeach ()
