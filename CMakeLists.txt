cmake_minimum_required(VERSION 3.24)
project(dataStructure C)

set(CMAKE_C_STANDARD 11)

# 소스 파일 목록
set(SOURCES
        02/ArrayStack/ArrayStack.c
        02/ArrayStack/Test_ArrayStack.c
        )

# 실행 파일 생성
add_executable(dataStructure ${SOURCES})

add_executable(testLinkedList 02/ArrayStack/Test_ArrayStack.c 02/ArrayStack/ArrayStack.c)