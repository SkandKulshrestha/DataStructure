/*
 * @Author Skand Kulshrestha
 * @Version v0.1
 */

/*  includes
 ******************************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "binaryTree.h"


/*  function definitions
 ******************************************************************************/

//------------------------------------------------------------------------------
//                                                            Private Operations
//------------------------------------------------------------------------------

/**
 ** Visit the binary tree node.
 **
 ** @param [in]     ptNode              pointer to the binary tree node
 **/
static void vVisitNode(T_BINARY_TREE_NODE *ptNode)
{
    assert(ptNode != NULL);

    printf("%d ", ptNode->i32Data);
}


/**
 ** Preorder traversal of a node.
 **
 ** @param [in]     ptNode              pointer to the binary tree node
 **/
static void vPreorderTraversal(T_BINARY_TREE_NODE *ptNode)
{
    // VLR: Visit, Left, Right
    if (ptNode != NULL)
    {
        vVisitNode(ptNode);
        vPreorderTraversal(ptNode->ptLeftChild);
        vPreorderTraversal(ptNode->ptRightChild);
    }
}


/**
 ** Inorder traversal of a node.
 **
 ** @param [in]     ptNode              pointer to the binary tree node
 **/
static void vInorderTraversal(T_BINARY_TREE_NODE *ptNode)
{
    // LVR: Left, Visit, Right
    if (ptNode != NULL)
    {
        vInorderTraversal(ptNode->ptLeftChild);
        vVisitNode(ptNode);
        vInorderTraversal(ptNode->ptRightChild);
    }
}


/**
 ** Postorder traversal of a node.
 **
 ** @param [in]     ptNode              pointer to the binary tree node
 **/
static void vPostorderTraversal(T_BINARY_TREE_NODE *ptNode)
{
    // LRV: Left, Right, Visit
    if (ptNode != NULL)
    {
        vPostorderTraversal(ptNode->ptLeftChild);
        vPostorderTraversal(ptNode->ptRightChild);
        vVisitNode(ptNode);
    }
}



//------------------------------------------------------------------------------
//                                                      Constructor & Destructor
//------------------------------------------------------------------------------

// see header file for description
void vBTInitialize(T_BINARY_TREE *ptBinaryTree)
{
    assert(ptBinaryTree != NULL);

    // initialize root
    ptBinaryTree->ptRoot = NULL;
}


// see header file for description
void vBTTerminate(T_BINARY_TREE *ptBinaryTree)
{
    assert(ptBinaryTree != NULL);

    // delete tree
    vDeleteSubtree(ptBinaryTree->ptRoot);

    // re-initialize root
    ptBinaryTree->ptRoot = NULL;
}


// see header file for description
T_BINARY_TREE_NODE *ptBTCreateNewNode(int32_t i32Data)
{
    T_BINARY_TREE_NODE *ptNewNode;

    // allocate the node
    ptNewNode = (T_BINARY_TREE_NODE *)malloc(sizeof(T_BINARY_TREE_NODE));

    if (ptNewNode != NULL)
    {
        // set data
        ptNewNode->i32Data = i32Data;

        // set pointer to parent
        ptNewNode->ptParent = NULL;

        // set pointer to left child
        ptNewNode->ptLeftChild = NULL;

        // set pointer to right child
        ptNewNode->ptRightChild = NULL;
    }

    // return allocated node or NULL
    return ptNewNode;
}


// see header file for description
void vBTDeleteSubtree(T_BINARY_TREE_NODE *ptNode)
{
    if (ptNode != NULL)
    {
        // delete left subtree
        vBTDeleteSubtree(ptNode->ptLeftChild);
        ptNode->ptLeftChild = NULL;

        // delete right subtree
        vBTDeleteSubtree(ptNode->ptRightChild);
        ptNode->ptRightChild = NULL;

        // delete current node
        vBTDeleteNode(ptNode);
    }
}


// see header file for description
void vBTDeleteNode(T_BINARY_TREE_NODE *ptNode)
{
    assert(ptNode != NULL);

    printf("Deleting %d\n", ptNode->i32Data);
    free(ptNode);
}


//------------------------------------------------------------------------------
//                                                               Setter & Getter
//------------------------------------------------------------------------------

// see header file for description
void vBTSetRoot(T_BINARY_TREE *ptBinaryTree, T_BINARY_TREE_NODE *ptNewNode)
{
    assert(ptBinaryTree != NULL);

    ptBinaryTree->ptRoot = ptNewNode;
}


// see header file for description
void vBTSetLeftChild(T_BINARY_TREE_NODE *ptParentNode, T_BINARY_TREE_NODE *ptChildNode)
{
    assert(ptParentNode != NULL && ptChildNode != NULL);

    ptChildNode->ptParent = ptParentNode;
    ptParentNode->ptLeftChild = ptChildNode;
}


// see header file for description
void vBTSetRightChild(T_BINARY_TREE_NODE *ptParentNode, T_BINARY_TREE_NODE *ptChildNode)
{
    assert(ptParentNode != NULL && ptChildNode != NULL);

    ptChildNode->ptParent = ptParentNode;
    ptParentNode->ptRightChild = ptChildNode;
}


// see header file for description
void vBTSetData(T_BINARY_TREE_NODE *ptNode, int32_t i32Data)
{
    assert(ptNode != NULL);

    ptNode->i32Data = i32Data;
}


// see header file for description
T_BINARY_TREE_NODE *ptBTGetRoot(T_BINARY_TREE *ptBinaryTree)
{
    assert(ptBinaryTree != NULL);

    return ptBinaryTree->ptRoot;
}


// see header file for description
T_BINARY_TREE_NODE *ptBTGetLeftChild(T_BINARY_TREE_NODE *ptParentNode)
{
    assert(ptParentNode != NULL);

    return ptParentNode->ptLeftChild;
}


// see header file for description
T_BINARY_TREE_NODE *ptBTGetRightChild(T_BINARY_TREE_NODE *ptParentNode)
{
    assert(ptParentNode != NULL);

    return ptParentNode->ptRightChild;
}


// see header file for description
int32_t i32BTGetData(T_BINARY_TREE_NODE *ptNode)
{
    assert(ptNode != NULL);

    return ptNode->i32Data;
}


// see header file for description
bool bBTIsRootExist(T_BINARY_TREE *ptBinaryTree)
{
    assert(ptBinaryTree != NULL);

    return (ptBinaryTree->ptRoot != NULL);
}


// see header file for description
bool bBTHasLeftChild(T_BINARY_TREE_NODE *ptParentNode)
{
    assert(ptParentNode != NULL);

    return (ptParentNode->ptLeftChild != NULL);
}


// see header file for description
bool bBTHasRightChild(T_BINARY_TREE_NODE *ptParentNode)
{
    assert(ptParentNode != NULL);

    return (ptParentNode->ptRightChild != NULL);
}


// see header file for description
bool bBTIsLeafNode(T_BINARY_TREE_NODE *ptNode)
{
    assert(ptNode != NULL);

    return (ptNode->ptLeftChild == NULL && ptNode->ptRightChild == NULL);
}


//------------------------------------------------------------------------------
//                                                                    Operations
//------------------------------------------------------------------------------

// see header file for description
void vBTTraverse(T_BINARY_TREE *ptBinaryTree, T_TREE_TRAVERSAL_ORDER tOrder)
{
    assert(ptBinaryTree != NULL);

    switch (tOrder)
    {
        case PREORDER_TRAVERSAL:
        {
            printf("Pre  : ");
            vPreorderTraversal(ptBinaryTree->ptRoot);
            break;
        }
        case INORDER_TRAVERSAL:
        {
            printf("In   : ");
            vInorderTraversal(ptBinaryTree->ptRoot);
            break;
        }
        case POSTORDER_TRAVERSAL:
        {
            printf("Post : ");
            vPostorderTraversal(ptBinaryTree->ptRoot);
            break;
        }
    }
    printf("\n");
}
