#ifndef _LINKED_LIST_H_
#define _LINKED_LIST_H_

#include <stdint.h>         // int32_t
#include <stdio.h>          // printf
#include <stdlib.h>         // malloc, free

/**
 *  Structure of the node
 */
typedef struct node_s
{
    /// data of the node
    int32_t         i32Data;
    /// pointer to next node
    struct node_s   *ptNext;
} node;

/**
 *  Structure to hold the list
 */
typedef struct list_s
{
    /// head of the list
    node            *ptHead;
} list;

/**
 *  Create the node.
 *
 *  @param i32Data      data to insert
 *
 *  @return pointer to newly created node or NULL if not created
 */
node *ptLinkedListCreateNewNode(int32_t i32Data);

/**
 *  Initialize the list.
 *
 *  @param ptList       pointer to the list
 */
void vLinkedListInit(list *ptList);

/**
 *  Insert the node at the beginning of the list.
 *
 *  @param ptList       pointer to the list
 *  @param ptNewNode    pointer to the node to be inserted
 */
void vLinkedListInsertAtBeginning(list *ptList, node *ptNewNode);

/**
 *  Insert the node after the given node.
 *
 *  @pre    given node must exist
 *
 *  @param ptNode       pointer to the node
 *  @param ptNewNode    pointer to the node to be inserted
 */
void vLinkedListInsertAfterNode(node *ptNode, node *ptNewNode);

/**
 *  Remove the node from the beginning.
 *
 *  @param ptList       pointer to the list
 */
void vLinkedListRemoveFromBeginning(list *ptList);

/**
 *  Remove the node after the node.
 *
 *  @pre    given node must exist
 *
 *  @param ptNode       pointer to the node
 */
void vLinkedListRemoveAfterNode(node *ptNode);

/**
 *  Traverse the list.
 *
 *  @param ptList       pointer to the list
 */
void vLinkedListTraverse(list *ptList);

/**
 *  De-initialize the list.
 *
 *  @param ptList       pointer to the list
 */
void vLinkedListExit(list *ptList);

#endif // _LINKED_LIST_H_