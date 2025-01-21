cmake_minimum_required(VERSION 3.24)
project(dataStructure C)

set(CMAKE_C_STANDARD 11)

# 소스 파일 목록
set(SOURCES
        04/BinaryTree/BinaryTree.c
        04/BinaryTree/Test_BinaryTree.c
        )

# 실행 파일 생성
add_executable(dataStructure ${SOURCES})

add_executable(testLinkedList 04/BinaryTree/BinaryTree.c
        04/BinaryTree/Test_BinaryTree.c)