cmake_minimum_required(VERSION 3.24)
project(dataStructure C)

set(CMAKE_C_STANDARD 11)

# 소스 파일 목록
set(SOURCES
        08/OpenAddressing/OpenAddressing.c
        08/OpenAddressing/Test_OpenAddressing.c
        )

# 실행 파일 생성
add_executable(dataStructure ${SOURCES})

add_executable(testLinkedList
        08/OpenAddressing/OpenAddressing.c
        08/OpenAddressing/Test_OpenAddressing.c)