
cmake_minimum_required (VERSION 3.14)
project (Bst VERSION 0.1.0)


set(SOURCE_EXE main.c)

set(SOURCE_LIB
    ${CMAKE_CURRENT_SOURCE_DIR}/BST/BST.c
    ${CMAKE_CURRENT_SOURCE_DIR}/BST/BST_Show.c
    ${CMAKE_CURRENT_SOURCE_DIR}/BST/BST_File.c)
set(HEADER_LIB
    ${CMAKE_CURRENT_SOURCE_DIR}/BST/BST.h
    ${CMAKE_CURRENT_SOURCE_DIR}/BST/BST_Show.h
    ${CMAKE_CURRENT_SOURCE_DIR}/BST/BST_Show_config.h
    ${CMAKE_CURRENT_SOURCE_DIR}/BST/BST_config.h
    ${CMAKE_CURRENT_SOURCE_DIR}/BST/BST_File.h)

set(HEADER_DIRS
    ${CMAKE_CURRENT_SOURCE_DIR}
    ${CMAKE_CURRENT_SOURCE_DIR}/BST)

include_directories(${HEADER_DIRS})

add_executable(main ${SOURCE_EXE})

add_library(bst STATIC ${SOURCE_LIB} ${HEADER_LIB})

target_link_libraries(main bst)
