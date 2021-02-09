#include "binarySearchTree.h"

// see header file for description
void vBSTInit(T_BINARY_SEARCH_TREE *ptBST)
{
    vBinaryTreeInit(ptBST);
}

void vBSTExit(T_BINARY_SEARCH_TREE *ptBST)
{
    vBinaryTreeExit(ptBST);
}

void vBSTTraverse(T_BINARY_SEARCH_TREE *ptBST, T_TRAVERSAL_ORDER tOrder)
{
    vBinaryTreeTraverse(ptBST, tOrder);
}

void vBSTInsert(T_BINARY_SEARCH_TREE *ptBST, int32_t i32Data)
{
    T_BINARY_SEARCH_TREE_NODE *ptNode;
    T_BINARY_SEARCH_TREE_NODE *ptTemp;
    T_BINARY_SEARCH_TREE_NODE *ptParent;
    int32_t i32NodeData;
    ptNode = ptBinaryTreeCreateNewNode(i32Data);

    //
    printf("Inserting %d", i32Data);

    if ( !bIsRootExist(ptBST) )
    {
        printf(": Inserted\n");
        vSetRoot(ptBST, ptNode);
    }
    else
    {
        ptParent = NULL;
        ptTemp = ptGetRoot(ptBST);
        while (ptTemp)
        {
            printf(".");
            ptParent = ptTemp;
            i32NodeData = i32GetData(ptTemp);
            if (i32Data < i32NodeData)
            {
                ptTemp = ptGetLeftChild(ptTemp);
            }
            else
            {
                ptTemp = ptGetRightChild(ptTemp);
            }
        }
        printf(": Inserted\n");
        if (i32Data < i32NodeData)
        {
            vSetLeftChild(ptParent, ptNode);
        }
        else
        {
            vSetRightChild(ptParent, ptNode);
        }
    }
}

T_BINARY_SEARCH_TREE_NODE *ptBSTSearch(T_BINARY_SEARCH_TREE *ptBST, int32_t i32Data)
{
    T_BINARY_SEARCH_TREE_NODE *ptNode = NULL;
    int32_t i32NodeData;

    printf("Searching %d", i32Data);

    if ( bIsRootExist(ptBST) )
    {
        ptNode = ptGetRoot(ptBST);
        while (ptNode)
        {
            printf(".");
            i32NodeData = i32GetData(ptNode);
            if (i32Data == i32NodeData)
            {
                printf(": Found\n");
                return ptNode;
            }
            else if (i32Data < i32NodeData)
            {
                ptNode = ptGetLeftChild(ptNode);
            }
            else
            {
                ptNode = ptGetRightChild(ptNode);
            }
        }
    }
    printf(": Not found\n");
    return ptNode;
}

void vBSTDelete(T_BINARY_SEARCH_TREE *ptBST, int32_t i32Data)
{
    T_BINARY_SEARCH_TREE_NODE *ptNode = NULL;
    int32_t i32NodeData;

    printf("Deleting %d", i32Data);

    // if ( bIsRootExist(ptBST) )
    // {
        // ptNode = ptGetRoot(ptBST);
        // i32NodeData = i32GetData(ptNode);
        // if (i32NodeData == i32Data)
        // {
            // ;
        // }
        // if (bIsLeafNode(ptNode))
        // {
            // ;
        // }
    // }
    printf(": Not found\n");
}
