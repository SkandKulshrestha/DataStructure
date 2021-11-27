#ifndef _LINKED_LIST_H_
#define _LINKED_LIST_H_

#include <stdint.h>         // int32_t
#include <stdio.h>          // printf
#include <stdlib.h>         // malloc, free

/**
 ** Structure of the node
 **/
typedef struct node_s
{
    /// data of the node
    int32_t         i32Data;

    /// pointer to next node
    struct node_s   *ptNext;
} node;

/**
 ** Structure to hold the list
 **/
typedef struct list_s
{
    /// head of the list
    node            *ptHead;

    /// tail of the list
    node            *ptTail;
} list;

/**
 ** Create the node.
 **
 ** @param i32Data      data to insert
 **
 ** @return pointer to newly created node or NULL if not created
 **/
node *ptLinkedListCreateNewNode(int32_t i32Data);

/**
 ** Initialize the list.
 **
 ** @param ptList       pointer to the list
 **/
void vLinkedListInit(list *ptList);

/**
 ** Get the node at the given index.
 **
 ** @param ptList       pointer to the list
 ** @param i32Index     index of the node
 **/
node *ptLinkedListGetNodeAtIndex(list *ptList, int32_t i32Index);

/**
 ** Insert the node at the beginning of the list.
 **
 ** @param ptList       pointer to the list
 ** @param ptNewNode    pointer to the node to be inserted
 **/
void vLinkedListInsertAtBeginning(list *ptList, node *ptNewNode);

/**
 ** Insert the node at the given index.
 ** If list finishes before given index, append at the end.
 **
 ** @param ptList       pointer to the list
 ** @param ptNewNode    pointer to the node to be inserted
 ** @param i32Index     index to be inserted at
 **/
void vLinkedListInsertAtIndex(list *ptList, node *ptNewNode, int32_t i32Index);

/**
 ** Insert the node after the given node.
 **
 ** @pre    given node must exist
 **
 ** @param ptNode       pointer to the node
 ** @param ptNewNode    pointer to the node to be inserted
 **/
void vLinkedListInsertAfterNode(node *ptNode, node *ptNewNode);

/**
 ** Remove the node from the beginning.
 **
 ** @param ptList       pointer to the list
 **/
void vLinkedListRemoveFromBeginning(list *ptList);

/**
 ** Remove the node after the node.
 **
 ** @pre    given node must exist
 **
 ** @param ptNode       pointer to the node
 **/
void vLinkedListRemoveAfterNode(node *ptNode);

/**
 ** Remove the node at given index.
 **
 ** @param ptList       pointer to the list
 ** @param i32Index     index to be removed at
 **/
void vLinkedListRemoveAtIndex(list *ptList, int32_t i32Index);

/**
 ** Remove the node from the end.
 **
 ** @param ptList       pointer to the list
 **/
void vLinkedListRemoveFromEnd(list *ptList);

/**
 ** Traverse the list.
 **
 ** @param ptList       pointer to the list
 **/
void vLinkedListTraverse(list *ptList);

/**
 ** De-initialize the list.
 **
 ** @param ptList       pointer to the list
 **/
void vLinkedListExit(list *ptList);

#endif // _LINKED_LIST_H_