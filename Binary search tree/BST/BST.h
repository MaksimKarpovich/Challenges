#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <stdint.h>
#include "BST_config.h"

#define bstInsert(node, key, value) bstInternalInsert(node, key, value, NULL)
#define bstRemove(node, key) bstInternalRemove(node, key, NULL, DIRECTION_LEFT)

/**
  * @brief  Describes the module working status
  */
typedef enum {
    BINARY_TREE_OK,
    BINARY_TREE_EMPTY,
    BINARY_TREE_ERROR,

} BinaryTreeStatus;

/**
  * @brief  Describes the module working status
  */
typedef enum {
    DIRECTION_LEFT,
    DIRECTION_RIGHT
} Direction;

/**
  * @brief Structure describing one node
  */
struct treeNode
{
    struct treeNode* leftNode;
    struct treeNode* rightNode;
    struct treeNode* parentNode;
    KEY_TYPE key;
    VALUE_TYPE value;
};

/**
  * @brief  Find node with necessary key.
  *
  * @param  node Pointer to starting node (root)
  * @param  key The key we are looking for
  * @return Pointer to node with key equal input key
  */
struct treeNode *bstFind(struct treeNode *node, KEY_TYPE key);

/**
  * @brief  Insert node to tree.
  *
  * @param  node Pointer to starting node (root)
  * @param  key Adding key
  * @param  value Adding value
  * @param  parentNode Pointer to parent node
  * @return Result status
  */
BinaryTreeStatus bstInternalInsert(struct treeNode *node, KEY_TYPE key, VALUE_TYPE value, struct treeNode *parentNode);

/**
  * @brief  Remove node from tree.
  *
  * @param  node Pointer to starting node (root)
  * @param  key Removing key
  * @return Result status
  */
BinaryTreeStatus bstInternalRemove(struct treeNode *node, KEY_TYPE key, struct treeNode *parentNode, Direction direction);

#ifdef BST_SHOW
/**
  * @brief  Shows the tree to the depth from the node.
  *
  * @note   Displays a tree visually on the screen.
  * @param  node Poiner to starting node (root)
  * @param  depth display depth
  * @return Result status
  */
BinaryTreeStatus showTree(struct treeNode *node, uint8_t depth);
#endif
