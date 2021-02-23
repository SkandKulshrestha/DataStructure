/*
 * @Author Skand Kulshrestha
 * @Version v0.1
 */

/*  includes
 ******************************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "binarySearchTree.h"


/*  function definitions
 ******************************************************************************/

//------------------------------------------------------------------------------
//                                                            Private Operations
//------------------------------------------------------------------------------


/**
 ** Get the inorder successor.
 **
 ** @param [in]     ptNode              pointer to the binary search tree node
 **
 ** @return         pointer to inorder successor if exists, otherwise NULL
 **/
T_BINARY_SEARCH_TREE_NODE ptGetInorderSuccessor(T_BINARY_SEARCH_TREE_NODE *ptNode)
{
    T_BINARY_SEARCH_TREE_NODE ptSuccessorNode = NULL;
    T_BINARY_SEARCH_TREE_NODE ptCurrentNode = ptBTGetRightChild(ptNode);

    // walk the right subtree
    while ( ptCurrentNode != NULL )
    {
        ptSuccessorNode = ptCurrentNode;
        ptCurrentNode = ptBTGetLeftChild(ptCurrentNode);
    }

    return ptSuccessorNode;
}


/**
 ** Get the inorder predecessor.
 **
 ** @param [in]     ptNode              pointer to the binary search tree node
 **
 ** @return         pointer to inorder predecessor if exists, otherwise NULL
 **/
T_BINARY_SEARCH_TREE_NODE ptGetInorderPredecessor(T_BINARY_SEARCH_TREE_NODE *ptNode)
{
    T_BINARY_SEARCH_TREE_NODE ptPredecessorNode = NULL;
    T_BINARY_SEARCH_TREE_NODE ptCurrentNode = ptBTGetLeftChild(ptNode);

    // walk the left subtree
    while ( ptCurrentNode != NULL )
    {
        ptPredecessorNode = ptCurrentNode;
        ptCurrentNode = ptBTGetRightChild(ptCurrentNode);
    }

    return ptPredecessorNode;
}

//------------------------------------------------------------------------------
//                                                      Constructor & Destructor
//------------------------------------------------------------------------------

// see header file for description
void vBSTInitialize(T_BINARY_SEARCH_TREE *ptBST)
{
    vBTInitialize(ptBST);
}


// see header file for description
void vBSTTerminate(T_BINARY_SEARCH_TREE *ptBST)
{
    vBTTerminate(ptBST);
}


//------------------------------------------------------------------------------
//                                                                    Operations
//------------------------------------------------------------------------------

// see header file for description
void vBSTTraverse(T_BINARY_SEARCH_TREE *ptBST, T_TRAVERSAL_ORDER tOrder)
{
    vBTTraverse(ptBST, tOrder);
}


// see header file for description
void vBSTInsert(T_BINARY_SEARCH_TREE *ptBST, int32_t i32Data)
{
    T_BINARY_SEARCH_TREE_NODE *ptNode;
    T_BINARY_SEARCH_TREE_NODE *ptCurrent;
    T_BINARY_SEARCH_TREE_NODE *ptParent = NULL;
    int32_t i32NodeData;

    // create new node
    ptNode = ptBTCreateNewNode(i32Data);

    // print message
    printf("Inserting %d", i32Data);

    // get root node as current node
    ptCurrent = ptBTGetRoot(ptBST);

    // search node position
    while ( ptCurrent != NULL )
    {
        printf(".");

        // set parent to current node
        ptParent = ptCurrent;

        // set current node data
        i32NodeData = i32BTGetData(ptCurrent);

        // get child node
        if (i32Data < i32NodeData)
        {
            ptCurrent = ptBTGetLeftChild(ptCurrent);
        }
        else
        {
            ptCurrent = ptBTGetRightChild(ptCurrent);
        }
    }

    if ( ptParent != NULL )
    {
        // insert child node
        if (i32Data < i32NodeData)
        {
            vBTSetLeftChild(ptParent, ptNode);
        }
        else
        {
            vBTSetRightChild(ptParent, ptNode);
        }
    }
    else
    {
        // insert root node
        vBTSetRoot(ptBST, ptNode);
    }

    printf(": Inserted\n");
}


// see header file for description
T_BINARY_SEARCH_TREE_NODE *ptBSTSearch(T_BINARY_SEARCH_TREE *ptBST, int32_t i32Data)
{
    T_BINARY_SEARCH_TREE_NODE *ptNode;
    int32_t i32NodeData;

    // print message
    printf("Searching %d", i32Data);

    // get root node
    ptNode = ptBTGetRoot(ptBST);

    // search node
    while ( ptNode != NULL )
    {
        printf(".");

        // get node data
        i32NodeData = i32BTGetData(ptNode);

        // check node data
        if (i32Data == i32NodeData)
        {
            printf(": Found\n");

            // node found
            return ptNode;
        }
        else if (i32Data < i32NodeData)
        {
            // check in left subtree
            ptNode = ptBTGetLeftChild(ptNode);
        }
        else
        {
            // check in right subtree
            ptNode = ptBTGetRightChild(ptNode);
        }
    }

    printf(": Not found\n");

    return ptNode;
}


// see header file for description
void vBSTDelete(T_BINARY_SEARCH_TREE *ptBST, int32_t i32Data)
{
    T_BINARY_SEARCH_TREE_NODE *ptNode;
    T_BINARY_SEARCH_TREE_NODE *ptChildNode;

    // print message
    printf("Deleting %d: ", i32Data);

    // search the tree
    ptNode = ptBSTSearch(ptBST, i32Data);

    // check node exist
    if ( ptNode != NULL )
    {
        if ( bBTHasLeftChild(ptNode) && bBTHasRightChild(ptNode) )
        {
#ifdef 1
            ptChildNode = ptGetInorderSuccessor(ptNode);
#else
            ptChildNode = ptGetInorderPredecessor(ptNode);
#endif
            vBTSetData(ptNode, i32BTGetData(ptChildNode));
            ptNode = ptChildNode;
        }

        ptParentNode = ptBTGetParent(ptNode);

        ptChildNode = ptBTGetLeftChild(ptNode);
        if ( ptChildNode == NULL )
        {
            ptChildNode = ptBTGetRightChild(ptNode);
        }

        if ( ptParentNode == NULL )
        {
            vBTSetRoot(ptBST, ptChildNode);
        }
        else
        {
            if ( ptNode == ptBTGetLeftChild(ptParentNode) )
            {
                vBTSetLeftChild(ptParentNode, ptChildNode);
            }
            else
            {
                vBTSetRightChild(ptParentNode, ptChildNode);
            }
        }
        vBTDeleteNode(ptNode);
    }
}
