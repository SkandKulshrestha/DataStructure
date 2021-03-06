/*
 * @Author Skand Kulshrestha
 * @Version v0.1
 */

#ifndef _BINARY_TREE_H_
#define _BINARY_TREE_H_

/*  includes
 ******************************************************************************/
#include <stdint.h>
#include <stdbool.h>


/*  typedefs
 ******************************************************************************/

/**
 ** Tree traversal order
 **/
typedef enum
{
    /// Inorder traversal (Depth-first search)
    INORDER_TRAVERSAL,

    /// Preorder traversal (Depth-first search)
    PREORDER_TRAVERSAL,

    /// Postorder traversal (Depth-first search)
    POSTORDER_TRAVERSAL
} T_TREE_TRAVERSAL_ORDER;


/**
 ** Structure of the node
 **/
typedef struct binaryTreeNode
{
    /// data of the node
    int32_t                             i32Data;

    /// pointer to parent node
    struct binaryTreeNode               *ptParent;

    /// pointer to left child node
    struct binaryTreeNode               *ptLeftChild;

    /// pointer to right child node
    struct binaryTreeNode               *ptRightChild;
} T_BINARY_TREE_NODE;


/**
 ** Structure to hold the tree
 **/
typedef struct binaryTree
{
    /// root of the tree
    T_BINARY_TREE_NODE                  *ptRoot;
} T_BINARY_TREE;


/*  function prototypes
 ******************************************************************************/

//------------------------------------------------------------------------------
//                                                      Constructor & Destructor
//------------------------------------------------------------------------------

/**
 ** Initialize the binary tree.
 **
 ** @param [in,out] ptBinaryTree        pointer to the binary tree
 **/
void vBTInitialize(T_BINARY_TREE *ptBinaryTree);


/**
 ** Terminate the binary tree.
 **
 ** @param [in,out] ptBinaryTree        pointer to the binary tree
 **/
void vBTTerminate(T_BINARY_TREE *ptBinaryTree);


/**
 ** Create the node for binary tree.
 **
 ** @param [in]     i32Data             data to insert
 **
 ** @return pointer to newly created node or NULL if not created
 **/
T_BINARY_TREE_NODE *ptBTCreateNewNode(int32_t i32Data);


/**
 ** Delete the subtree of given node including node itself.
 **
 ** @param [in]     ptNode              pointer to the node
 **/
void vBTDeleteSubtree(T_BINARY_TREE_NODE *ptNode);


/**
 ** Delete given binary tree node.
 **
 ** @pre            given node must be leaf node
 **
 ** @param [in]     ptNode              pointer to the binary tree node
 **/
void vBTDeleteNode(T_BINARY_TREE_NODE *ptNode);


//------------------------------------------------------------------------------
//                                                               Setter & Getter
//------------------------------------------------------------------------------

/**
 ** Set root node of the binary tree.
 **
 ** @param [in,out] ptBinaryTree        pointer to the binary tree
 ** @param [in]     ptNewNode           pointer to the node
 **/
void vBTSetRoot(T_BINARY_TREE *ptBinaryTree, T_BINARY_TREE_NODE *ptNewNode);


/**
 ** Set left child of the given node.
 **
 ** @param [in,out] ptParentNode        pointer to the parent node
 ** @param [in]     ptChildNode         pointer to the child node
 **/
void vBTSetLeftChild(T_BINARY_TREE_NODE *ptParentNode, T_BINARY_TREE_NODE *ptChildNode);


/**
 ** Set right child of the given node.
 **
 ** @param [in,out] ptParentNode        pointer to the parent node
 ** @param [in]     ptChildNode         pointer to the child node
 **/
void vBTSetRightChild(T_BINARY_TREE_NODE *ptParentNode, T_BINARY_TREE_NODE *ptChildNode);

void vBTSetData(T_BINARY_TREE_NODE *ptNode, int32_t i32Data);


/**
 ** Get root node of the binary tree.
 **
 ** @param [in]     ptBinaryTree        pointer to the binary tree
 **
 ** @return root node, if exist, otherwise NULL
 **/
T_BINARY_TREE_NODE *ptBTGetRoot(T_BINARY_TREE *ptBinaryTree);


/**
 ** Get left child node of the given node.
 **
 ** @param [in]     ptParentNode        pointer to the parent node
 **
 ** @return left child node, if exist, otherwise NULL
 **/
T_BINARY_TREE_NODE *ptBTGetLeftChild(T_BINARY_TREE_NODE *ptParentNode);


/**
 ** Get right child node of the given node.
 **
 ** @param [in]     ptParentNode        pointer to the parent node
 **
 ** @return right child node, if exist, otherwise NULL
 **/
T_BINARY_TREE_NODE *ptBTGetRightChild(T_BINARY_TREE_NODE *ptParentNode);


/**
 ** Get node data of the given node.
 **
 ** @pre            `ptNode` must not be NULL
 **
 ** @param [in]     ptNode              pointer to the node
 **
 ** @return node data
 **/
int32_t i32BTGetData(T_BINARY_TREE_NODE *ptNode);


/**
 ** Check whether the root exist or not.
 **
 ** @param [in]     ptBinaryTree        pointer to the binary tree
 **
 ** @return true, if root exist, otherwise, false
 **/
bool bBTIsRootExist(T_BINARY_TREE *ptBinaryTree);


/**
 ** Check whether the left child exist or not.
 **
 ** @param [in]     ptParentNode        pointer to the parent node
 **
 ** @return true, if root exist, otherwise, false
 **/
bool bBTHasLeftChild(T_BINARY_TREE_NODE *ptParentNode);


/**
 ** Check whether the right child exist or not.
 **
 ** @param [in]     ptParentNode        pointer to the parent node
 **
 ** @return true, if root exist, otherwise, false
 **/
bool bBTHasRightChild(T_BINARY_TREE_NODE *ptParentNode);


//------------------------------------------------------------------------------
//                                                                    Operations
//------------------------------------------------------------------------------

/**
 ** Traverse the binary tree.
 **
 ** @param [in]     ptBinaryTree        pointer to the binary tree
 ** @param [in]     tOrder              traversal order
 **/
void vBTTraverse(T_BINARY_TREE *ptBinaryTree, T_TREE_TRAVERSAL_ORDER tOrder);

#endif // _BINARY_TREE_H_
