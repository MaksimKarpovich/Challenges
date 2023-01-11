
cmake_minimum_required (VERSION 3.14)
project (Bst VERSION 0.1.0)


set(SOURCE_EXE main.c)

set(SOURCE_LIB
    ${CMAKE_CURRENT_SOURCE_DIR}/BST/BST.c)
set(HEADER_LIB
    ${CMAKE_CURRENT_SOURCE_DIR}/BST/BST.h)

set(HEADER_DIRS
    ${CMAKE_CURRENT_SOURCE_DIR}
    ${CMAKE_CURRENT_SOURCE_DIR}/BSP/Drawing)

include_directories(${HEADER_DIRS})

add_library(bst STATIC ${SOURCE_LIB} ${HEADER_LIB})

add_executable(main ${SOURCE_EXE})


target_link_libraries(main bst)
