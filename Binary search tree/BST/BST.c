#include"BST.h"
#include <malloc.h>
#include <stdbool.h>

#define MAX_DIGITS 3
#define MAX_DEPTH 5
#define MAX_SHOW_NUMBERS 15

#define UP(num) for(uint32_t dd = 0; dd < num; dd++) printf("\033[A")
#define DOWN(num) for(uint32_t dd = 0; dd < num; dd++) printf("\033[B")
#define RIGHT(num) for(uint32_t dd = 0; dd < num; dd++) printf("\033[C")
#define LEFT(num) for(uint32_t dd = 0; dd < num; dd++) printf("\033[D")
#define HOME() printf("\033[H")
#define END() printf("\033[F")
#define PGUP() printf("\033[I")
#define PGDN() printf("\033[G")
#define SPACES(num) for(uint32_t dd = 0; dd < num; dd++) printf(" ")
#define LINES(num) for(uint32_t dd = 0; dd < num; dd++) printf("_")

#define NODE_LEFT()             if((getLeftChild(&internalNode) == NULL))\
                                break;\
                                internalNode = *getLeftChild(&internalNode)
#define NODE_RIGHT()            if((getRightChild(&internalNode) == NULL))\
                                break;\
                                internalNode = *getRightChild(&internalNode)

struct treeNode *bstFind(struct treeNode *node, KEY_TYPE key)
{

}

BinaryTreeStatus bstInsert(struct treeNode *node, KEY_TYPE key, VALUE_TYPE value, struct treeNode *parentNode)
{
    node->parentNode = parentNode;

    if((node->parentNode == (KEY_TYPE)NULL) && (node->key == NULL))
    {
        node->parentNode = NULL;
        node->leftNode = NULL;
        node->rightNode = NULL;
        node->key = key;
        node->value = value;
        return BINARY_TREE_OK;
    }

    if((node->key == NULL))
    {
        node->leftNode = NULL;
        node->rightNode = NULL;
        node->key = key;
        node->value = value;
        return BINARY_TREE_OK;
    }

    if(node->key == key)
    {
        node->value = value;
        return BINARY_TREE_OK;
    }

    if(node->key < key)
    {
        struct treeNode* rigthNode;
        rigthNode = malloc(sizeof(struct treeNode));
        if(node->rightNode == NULL)
            node->rightNode = rigthNode;
        bstInsert(node->rightNode, key, value, node);
        return BINARY_TREE_OK;
    }
    else {
        struct treeNode* leftNode;
        leftNode = malloc(sizeof(struct treeNode));
        if(node->leftNode == NULL)
            node->leftNode = leftNode;
        bstInsert(node->leftNode, key, value, node);
        return BINARY_TREE_OK;
    }

    return BINARY_TREE_ERROR;
}

BinaryTreeStatus bstRemove(struct treeNode *node, KEY_TYPE key)
{

}

static uint8_t CountNumbers(uint8_t number)
{
    if(number == 0)
        return 1;

    int count = 0;

    if(number < 0)
        count++;

    while (number != 0)
    {
        ++count;
        number /= 10;
    }

    return count;
}


static uint32_t numLines(uint32_t line);

static uint32_t numSpaces(uint32_t line)
{
    if(line == 0)
        return 0;

    uint32_t lines = numLines(line - 1);
    uint32_t res = (numSpaces(line - 1) + MAX_DIGITS + 1 + lines);
    return res;

}

static uint32_t numRightSpaces(uint32_t line)
{
    if(line == 0)
        return 5;
    uint32_t res =  (2 << (line-1)) * MAX_DIGITS - numLines(line - 1) + 2 * line + 1;
    return res;
}

static uint32_t numLines(uint32_t line)
{
    uint32_t spaces = numSpaces(line);

    int32_t res = (spaces - MAX_DIGITS - 3);
    if(res < 0)
        return 0;
    return res;
}

static struct treeNode *getLeftChild(struct treeNode *node)
{
    if(node->leftNode != NULL)
        return node->leftNode;
    else return NULL;
}

static struct treeNode *getRightChild(struct treeNode *node)
{
    if(node->rightNode != NULL)
        return node->rightNode;
    else return NULL;
}

static struct treeNode *getParent(struct treeNode *node)
{
    if(node->parentNode != NULL)
        return node->parentNode;
    else return NULL;
}

static KEY_TYPE *initShowArray(struct treeNode *node)
{
    KEY_TYPE *array;
    struct treeNode internalNode = *node;
    array = malloc(sizeof(KEY_TYPE) * MAX_SHOW_NUMBERS);
    *array = internalNode.key;

    for(int i = 1; i < MAX_SHOW_NUMBERS; i++)
    {

        switch (i) {
        case 1:
            NODE_LEFT();
            *(array + i) = internalNode.key;
            break;
        case 2:
            NODE_RIGHT();
            *(array + i) = internalNode.key;
            break;
        case 3:
            NODE_LEFT();
            NODE_LEFT();
            *(array + i) = internalNode.key;
            break;
        case 4:
            NODE_LEFT();
            NODE_RIGHT();
            *(array + i) = internalNode.key;
            break;
        case 5:
            NODE_RIGHT();
            NODE_LEFT();
            *(array + i) = internalNode.key;
            break;
        case 6:
            NODE_RIGHT();
            NODE_RIGHT();
            *(array + i) = internalNode.key;
            break;
        case 7:
            NODE_LEFT();
            NODE_LEFT();
            NODE_LEFT();
            *(array + i) = internalNode.key;
            break;
        case 8:
            NODE_LEFT();
            NODE_LEFT();
            NODE_RIGHT();
            *(array + i) = internalNode.key;
            break;
        case 9:
            NODE_LEFT();
            NODE_RIGHT();
            NODE_LEFT();
            *(array + i) = internalNode.key;
            break;
        case 10:
            NODE_LEFT();
            NODE_RIGHT();
            NODE_RIGHT();
            *(array + i) = internalNode.key;
            break;
        case 11:
            NODE_RIGHT();
            NODE_LEFT();
            NODE_LEFT();
            *(array + i) = internalNode.key;
            break;
        case 12:
            NODE_RIGHT();
            NODE_LEFT();
            NODE_RIGHT();
            *(array + i) = internalNode.key;
            break;
        case 13:
            NODE_RIGHT();
            NODE_RIGHT();
            NODE_LEFT();
            *(array + i) = internalNode.key;
            break;
        case 14:
            NODE_RIGHT();
            NODE_RIGHT();
            NODE_RIGHT();
            *(array + i) = internalNode.key;
            break;
        default:
            break;
        }
        internalNode = *node;
    }
    return array;
}

static void printKey(struct treeNode *node)
{
    static uint16_t num = 0;
    KEY_TYPE *array = initShowArray(node);


    for(int i = 0; i < MAX_DIGITS; i++)
        printf("0");

    LEFT(CountNumbers(*(array+num)));
    printf("%d", *(array+num));
    num++;

}


BinaryTreeStatus showTree(struct treeNode *node, uint8_t num) // Now good work only with num = [0; 4]
{
    if(node->key == (KEY_TYPE)NULL)
    {
        printf("Error: Can not show empty tree\r\n");
        return BINARY_TREE_EMPTY;
    }

    if(num == 0)
    {
        printf("Error: Can not show 0 three nodes\r\n");
        return BINARY_TREE_ERROR;
    }

    uint16_t numRightSpace = 0;

    for(int k = num; k > 0; k--)
    {

        SPACES(numSpaces(k));

        LINES(numLines(k));

        printKey(node);

        LINES(numLines(k));

        for(uint32_t u = 0; u < numRightSpace; u++)
        {
            SPACES(numRightSpaces(k));

            LINES(numLines(k));

            printKey(node);

            LINES(numLines(k));

        }

        printf("\r\n");

        if(numRightSpace == 0)
            numRightSpace = 1;
        else
            numRightSpace = (numRightSpace << 1) + 1;


        SPACES(numSpaces(k) - 1);

        if(k > 1)
        {
            for(uint16_t i = 0; i < (numRightSpace >> 1) + 1; i++) {
                printf("/");

                SPACES((numLines(k) * 2) + MAX_DIGITS);

                printf("\\");
                SPACES(numRightSpaces(k) - 2);
            }
            printf("\r\n");
        }
    }
}


