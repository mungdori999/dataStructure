cmake_minimum_required(VERSION 3.24)
project(dataStructure C)

set(CMAKE_C_STANDARD 11)

# 소스 파일 목록
set(SOURCES
        01/DoublyLinkedList/DoublyLinkedList.c
        01/DoublyLinkedList/Test_DoublyLinkedList.c
        )

# 실행 파일 생성
add_executable(dataStructure ${SOURCES})

add_executable(testLinkedList 01/DoublyLinkedList/Test_DoublyLinkedList.c 01/DoublyLinkedList/DoublyLinkedList.c)