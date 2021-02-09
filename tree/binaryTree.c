/*
 * @Author Skand Kulshrestha
 * @Version v0.1
 */

/*  includes
 ******************************************************************************/
#include "binaryTree.h"


/*  typedefs
 ******************************************************************************/

// see header file for description
typedef struct binaryTreeNode
{
    // data of the node
    int32_t                     i32Data;

    // pointer to parent node
    struct binaryTreeNode       *ptParent;

    // pointer to left child node
    struct binaryTreeNode       *ptLeftChild;

    // pointer to right child node
    struct binaryTreeNode       *ptRightChild;
} T_BINARY_TREE_NODE;


// see header file for description
typedef struct binaryTree
{
    // root of the tree
    T_BINARY_TREE_NODE      *ptRoot;
} T_BINARY_TREE;


/*  function definitions
 ******************************************************************************/


static void vVisitNode(T_BINARY_TREE_NODE *ptNode)
{
    printf("%d ", ptNode->i32Data);
}

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

static void vBinaryTreeDeleteNode(T_BINARY_TREE_NODE *ptNode)
{
    printf("Deleting %d\n", ptNode->i32Data);
    free(ptNode);
}

// see header file for description
void vBinaryTreeInitialize(T_BINARY_TREE *ptBinaryTree)
{
    // initialize root
    ptBinaryTree->ptRoot = NULL;
}

// see header file for description
void vBinaryTreeTerminate(T_BINARY_TREE *ptBinaryTree)
{
    // delete tree
    vDeleteSubtree(ptBinaryTree->ptRoot);

    // re-initialize root
    ptBinaryTree->ptRoot = NULL;
}

// see header file for description
T_BINARY_TREE_NODE *ptBinaryTreeCreateNewNode(int32_t i32Data)
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
void vDeleteSubtree(T_BINARY_TREE_NODE *ptNode)
{
    if (ptNode != NULL)
    {
        // delete left subtree
        vDeleteSubtree(ptNode->ptLeftChild);
        ptNode->ptLeftChild = NULL;

        // delete right subtree
        vDeleteSubtree(ptNode->ptRightChild);
        ptNode->ptRightChild = NULL;

        // delete current node
        vBinaryTreeDeleteNode(ptNode);
    }
}


// see header file for description
void vSetRoot(T_BINARY_TREE *ptBinaryTree, T_BINARY_TREE_NODE *ptNewNode)
{
    ptBinaryTree->ptRoot = ptNewNode;
}

// see header file for description
void vSetLeftChild(T_BINARY_TREE_NODE *ptParentNode, T_BINARY_TREE_NODE *ptChildNode)
{
    ptChildNode->ptParent = ptParentNode;
    ptParentNode->ptLeftChild = ptChildNode;
}

// see header file for description
void vSetRightChild(T_BINARY_TREE_NODE *ptParentNode, T_BINARY_TREE_NODE *ptChildNode)
{
    ptChildNode->ptParent = ptParentNode;
    ptParentNode->ptRightChild = ptChildNode;
}

// see header file for description
T_BINARY_TREE_NODE *ptGetRoot(T_BINARY_TREE *ptBinaryTree)
{
    return ptBinaryTree->ptRoot;
}

// see header file for description
T_BINARY_TREE_NODE *ptGetLeftChild(T_BINARY_TREE_NODE *ptParentNode)
{
    return ptParentNode->ptLeftChild;
}

// see header file for description
T_BINARY_TREE_NODE *ptGetRightChild(T_BINARY_TREE_NODE *ptParentNode)
{
    return ptParentNode->ptRightChild;
}

// see header file for description
int32_t i32GetData(T_BINARY_TREE_NODE *ptNode)
{
    return ptNode->i32Data;
}

// see header file for description
bool bIsRootExist(T_BINARY_TREE *ptBinaryTree)
{
    return (ptBinaryTree->ptRoot != NULL);
}

// see header file for description
bool bIsLeftChildExist(T_BINARY_TREE_NODE *ptParentNode)
{
    return (ptParentNode->ptLeftChild != NULL);
}

// see header file for description
bool bIsRightChildExist(T_BINARY_TREE_NODE *ptParentNode)
{
    return (ptParentNode->ptRightChild != NULL);
}

// see header file for description
bool bIsLeafNode(T_BINARY_TREE_NODE *ptNode)
{
    return (ptNode->ptLeftChild == NULL && ptNode->ptRightChild == NULL);
}

// see header file for description
void vRemoveLeafNode(T_BINARY_TREE_NODE *ptNode)
{
    vBinaryTreeDeleteNode(ptNode);
}

void vRemoveLeftChild(T_BINARY_TREE_NODE *ptParentNode, T_BINARY_TREE_NODE *ptChildNode)
{
}

void vRemoveRightChild(T_BINARY_TREE_NODE *ptParentNode, T_BINARY_TREE_NODE *ptChildNode)
{
}

// see header file for description
void vBinaryTreeTraverse(T_BINARY_TREE *ptBinaryTree, T_TREE_TRAVERSAL_ORDER tOrder)
{
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
