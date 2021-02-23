/*
 * @Author Skand Kulshrestha
 * @Version v0.1
 */

#ifndef _AVL_TREE_H_
#define _AVL_TREE_H_

/*  includes
 ******************************************************************************/
#include <stdint.h>
#include <stdbool.h>
#include "binaryTree.h"

/*  typedefs
 ******************************************************************************/

/**
 ** Balance Factor := Height(RightSubtree(X)) - Height(LeftSubtree(X))
 **/
typedef enum
{
    /// Balance factor -1
    BALANCE_FACTOR_MINUS_ONE = -1,

    /// Balance factor 0
    BALANCE_FACTOR_ZERO,

    /// Balance factor +1
    BALANCE_FACTOR_PLUS_ONE
} T_NODE_BALANCE_FACTOR;


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
typedef T_BINARY_TREE_NODE T_AVL_TREE_NODE;


/**
 ** Structure to hold the AVL tree (Same as binary tree)
 **
 ** {
 **     T_BINARY_TREE_NODE      *ptRoot;
 ** }
 **
 **/
typedef T_BINARY_TREE T_AVL_TREE;


/*  function prototypes
 ******************************************************************************/

//------------------------------------------------------------------------------
//                                                      Constructor & Destructor
//------------------------------------------------------------------------------

/**
 ** Initialize the AVL tree.
 **
 ** @param [in,out] ptAVLTree           pointer to the AVL tree
 **/
void vAVLTreeInitialize(T_AVL_TREE *ptAVLTree);


/**
 ** Terminate the AVL tree.
 **
 ** @param [in,out] ptAVLTree           pointer to the AVL tree
 **/
void vAVLTreeTerminate(T_AVL_TREE *ptAVLTree);



//------------------------------------------------------------------------------
//                                                                    Operations
//------------------------------------------------------------------------------

/**
 ** Traverse the AVL tree.
 **
 ** @param [in]     ptAVLTree           pointer to the AVL tree
 ** @param [in]     tOrder              traversal order
 **/
void vAVLTreeTraverse(T_AVL_TREE *ptAVLTree, T_TRAVERSAL_ORDER tOrder);


/**
 ** Insert the data into the AVL tree.
 **
 ** @param [in]     ptAVLTree           pointer to the AVL tree
 ** @param [in]     i32Data             data to be inserted
 **/
void vAVLTreeInsert(T_AVL_TREE *ptAVLTree, int32_t i32Data);


/**
 ** Search the data in the AVL tree.
 **
 ** @param [in]     ptAVLTree           pointer to the AVL tree
 ** @param [in]     i32Data             data to be searched
 **
 ** @return         node, if found, otherwise NULL
 **/
T_AVL_TREE_NODE *ptAVLTreeSearch(T_AVL_TREE *ptAVLTree, int32_t i32Data);


/**
 ** Delete the data (first occurrence) from the AVL tree.
 **
 ** @param [in]     ptAVLTree           pointer to the AVL tree
 ** @param [in]     i32Data             data to be deleted
 **/
void vAVLTreeDelete(T_AVL_TREE *ptAVLTree, int32_t i32Data);

#endif // _AVL_TREE_H_
