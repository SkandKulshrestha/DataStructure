/*
 * @Author Skand Kulshrestha
 * @Version v0.1
 */

/*  includes
 ******************************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "AVLTree.h"


/*  function definitions
 ******************************************************************************/

//------------------------------------------------------------------------------
//                                                            Private Operations
//------------------------------------------------------------------------------



//------------------------------------------------------------------------------
//                                                      Constructor & Destructor
//------------------------------------------------------------------------------

// see header file for description
void vAVLTreeInitialize(T_AVL_TREE *ptAVLTree)
{
    vBTInitialize(ptAVLTree);
}


// see header file for description
void vAVLTreeTerminate(T_AVL_TREE *ptAVLTree)
{
    vBTTerminate(ptAVLTree);
}


//------------------------------------------------------------------------------
//                                                                    Operations
//------------------------------------------------------------------------------

// see header file for description
void vAVLTreeTraverse(T_AVL_TREE *ptAVLTree, T_TRAVERSAL_ORDER tOrder)
{
    vBTTraverse(ptAVLTree, tOrder);
}


// see header file for description
void vAVLTreeInsert(T_AVL_TREE *ptAVLTree, int32_t i32Data)
{
}


// see header file for description
T_AVL_TREE_NODE *ptAVLTreeSearch(T_AVL_TREE *ptAVLTree, int32_t i32Data)
{
    T_AVL_TREE_NODE *ptNode;

    return ptNode;
}


// see header file for description
void vAVLTreeDelete(T_AVL_TREE *ptAVLTree, int32_t i32Data)
{
}
