#ifndef _BINARY_SEARCH_TREE_H_
#define _BINARY_SEARCH_TREE_H_

#include <stdint.h>         // int32_t
#include <stdio.h>          // printf
#include <stdlib.h>         // malloc, free

#include "binaryTree.h"

typedef T_BINARY_TREE_NODE T_BINARY_SEARCH_TREE_NODE;
typedef T_BINARY_TREE T_BINARY_SEARCH_TREE;


/**
 *  Initialize the binary tree.
 *
 *  @param ptList       pointer to the binary tree
 */
void vBSTInit(T_BINARY_SEARCH_TREE *ptBST);

/**
 *  Traverse the binary tree.
 *
 *  @param ptList       pointer to the binary tree
 */
void vBSTTraverse(T_BINARY_SEARCH_TREE *ptBST, T_TRAVERSAL_ORDER tOrder);

/**
 *  De-initialize the binary tree.
 *
 *  @param ptList       pointer to the binary tree
 */
void vBSTExit(T_BINARY_SEARCH_TREE *ptBST);

void vBSTInsert(T_BINARY_SEARCH_TREE *ptBST, int32_t i32Data);

T_BINARY_SEARCH_TREE_NODE *ptBSTSearch(T_BINARY_SEARCH_TREE *ptBST, int32_t i32Data);

void vBSTDelete(T_BINARY_SEARCH_TREE *ptBST, int32_t i32Data);

#endif // _BINARY_SEARCH_TREE_H_
