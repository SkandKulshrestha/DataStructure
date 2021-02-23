/*
 * @Author Skand Kulshrestha
 * @Version v0.1
 */

#ifndef _BINARY_SEARCH_TREE_H_
#define _BINARY_SEARCH_TREE_H_

/*  includes
 ******************************************************************************/
#include <stdint.h>
#include <stdbool.h>
#include "binaryTree.h"

/*  typedefs
 ******************************************************************************/

/**
 ** Structure of the node (Same as binary tree)
 **
 ** {
 **     int32_t                 i32Data
 **     T_BINARY_TREE_NODE*     ptParent
 **     T_BINARY_TREE_NODE*     ptLeftChild
 **     T_BINARY_TREE_NODE*     ptRightChild
 ** }
 **/
typedef T_BINARY_TREE_NODE T_BINARY_SEARCH_TREE_NODE;


/**
 ** Structure to hold the binary search tree (Same as binary tree)
 **
 ** {
 **     T_BINARY_TREE_NODE      *ptRoot;
 ** }
 **
 **/
typedef T_BINARY_TREE T_BINARY_SEARCH_TREE;


/*  function prototypes
 ******************************************************************************/

//------------------------------------------------------------------------------
//                                                      Constructor & Destructor
//------------------------------------------------------------------------------

/**
 ** Initialize the binary tree.
 **
 ** @param [in,out] ptBST               pointer to the binary search tree
 **/
void vBSTInitialize(T_BINARY_SEARCH_TREE *ptBST);


/**
 ** Terminate the binary tree.
 **
 ** @param [in,out] ptBST               pointer to the binary search tree
 **/
void vBSTTerminate(T_BINARY_SEARCH_TREE *ptBST);



//------------------------------------------------------------------------------
//                                                                    Operations
//------------------------------------------------------------------------------

/**
 ** Traverse the binary search tree.
 **
 ** @param [in]     ptBST               pointer to the binary search tree
 ** @param [in]     tOrder              traversal order
 **/
void vBSTTraverse(T_BINARY_SEARCH_TREE *ptBST, T_TRAVERSAL_ORDER tOrder);


/**
 ** Insert the data into the binary search tree.
 **
 ** @param [in]     ptBST               pointer to the binary search tree
 ** @param [in]     i32Data             data to be inserted
 **/
void vBSTInsert(T_BINARY_SEARCH_TREE *ptBST, int32_t i32Data);


/**
 ** Search the data in the binary search tree.
 **
 ** @param [in]     ptBST               pointer to the binary search tree
 ** @param [in]     i32Data             data to be searched
 **
 ** @return         node, if found, otherwise NULL
 **/
T_BINARY_SEARCH_TREE_NODE *ptBSTSearch(T_BINARY_SEARCH_TREE *ptBST, int32_t i32Data);


/**
 ** Delete the data (first occurrence) from the binary search tree.
 **
 ** @param [in]     ptBST               pointer to the binary search tree
 ** @param [in]     i32Data             data to be deleted
 **/
void vBSTDelete(T_BINARY_SEARCH_TREE *ptBST, int32_t i32Data);

#endif // _BINARY_SEARCH_TREE_H_
