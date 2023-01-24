#include "BST_Show.h"
#include "BST_File.h"
#include "BST.h"

#define SOURCE_FILE_PATH "/home/user/Challenges/Binary search tree/A.bst"
#define NUM_SHOWING_NODES 4

int main(int argc, char** argv)
{
    struct treeNode node;

    addToNode(&node, SOURCE_FILE_PATH);

    showTree(&node, NUM_SHOWING_NODES);
}

