cmake_minimum_required(VERSION 3.30)
project(NTUST_OOP_113_2_Homework)

set(CMAKE_CXX_STANDARD 14)

# 搜尋專案根目錄下所有名稱以 TS 開頭的資料夾
file(GLOB TS_DIRS RELATIVE ${CMAKE_SOURCE_DIR} "TS*")

foreach (dir ${TS_DIRS})
    # 只接受資料夾
    if (NOT IS_DIRECTORY "${CMAKE_SOURCE_DIR}/${dir}")
        continue()
    endif ()

    # 搜尋該資料夾下所有 .cpp 檔案
    file(GLOB SRC_FILES "${CMAKE_SOURCE_DIR}/${dir}/*.cpp")
    if (SRC_FILES)
        # 以資料夾名稱作為執行檔名稱，並加入對應的 .cpp 檔案
        add_executable(${dir} ${SRC_FILES})
    endif ()
endforeach ()
