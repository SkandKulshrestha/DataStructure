#include "linkedlist.h"

// see header file for description
node *ptLinkedListCreateNewNode(int32_t i32Data)
{
    // allocate the memory
    node *ptNode = (node *)malloc(sizeof(node));
    if (ptNode != NULL)
    {
        // set the data
        ptNode->i32Data = i32Data;

        // set the next node
        ptNode->ptNext = NULL;
    }
    // return newly created node
    return ptNode;
}

// see header file for description
void vLinkedListInit(list *ptList)
{
    // set the head and tail for empty list
    ptList->ptHead = ptList->ptTail = NULL;
}

int32_t i32LinkedListGetData(node *ptNode)
{
    return ptNode->i32Data;
}

node *ptLinkedListGetNext(node *ptNode)
{
    return ptNode->ptNext;
}

// see header file for description
node *ptLinkedListGetNodeAtIndex(list *ptList, int32_t i32Index)
{
    int32_t i32Counter = 0;
    node *ptNode = ptList->ptHead;

    // find the node
    while (i32Counter < i32Index && ptNode != NULL)
    {
        i32Counter++;
        ptNode = ptNode->ptNext;
    }

    return ptNode;
}

// see header file for description
void vLinkedListInsertAtBeginning(list *ptList, node *ptNewNode)
{
    // attach head node after the new node
    ptNewNode->ptNext = ptList->ptHead;

    // update the head with new node
    ptList->ptHead = ptNewNode;

    // set tail also, if list is empty
    if (ptList->ptTail == NULL)
    {
        ptList->ptTail = ptNewNode;
    }
}

// see header file for description
void vLinkedListInsertAfterNode(node *ptNode, node *ptNewNode)
{
    // attach given node after new node
    ptNewNode->ptNext = ptNode->ptNext;

    // attach new node after given node
    ptNode->ptNext = ptNewNode;

    // update the tail if node is inserted at the end
    if (ptList->ptTail == ptNode)
    {
        ptList->ptTail = ptNewNode;
    }
}

// see header file for description
void vLinkedListInsertAtIndex(list *ptList, node *ptNewNode, int32_t i32Index)
{
    int32_t i32Counter = 0;
    node *ptPreviousNode = NULL;
    node *ptNode = ptList->ptHead;

    if (i32Index == 0 || ptNode == NULL)
    {
        // insert node at the beginning
        vLinkedListInsertAtBeginning(ptList, ptNewNode);
    }
    else
    {
        // find the node
        while (i32Counter < i32Index && ptNode != NULL)
        {
            i32Counter++;
            ptPreviousNode = ptNode;
            ptNode = ptNode->ptNext;
        }

        // insert after the node
        vLinkedListInsertAfterNode(ptPreviousNode, ptNewNode);
    }
}

// see header file for description
void vLinkedListInsertAtEnd(list *ptList, node *ptNewNode)
{
    if (ptList->ptTail == NULL)
    {
        // empty list
        ptList->ptTail = ptList->ptHead = ptNewNode;
    }
    else
    {
        // append the node to the tail
        ptList->ptTail->ptNext = ptNewNode;

        // update the tail
        ptList->ptTail = ptNewNode;
    }
}

// see header file for description
void vLinkedListRemoveFromBeginning(list *ptList)
{
    // get the head node
    node *ptDeletableNode = ptList->ptHead;

    if (ptDeletableNode != NULL)
    {
        // attach the head to its next
        ptList->ptHead = ptDeletableNode->ptNext;

        // deallocate the memory
        free(ptDeletableNode);

        // check for empty list
        if (ptList->ptHead == NULL)
        {
            ptList->ptTail = NULL;
        }
    }
}

// see header file for description
void vLinkedListRemoveAfterNode(node *ptNode)
{
    node *ptDeletableNode = ptNode->ptNext;

    if (ptDeletableNode != NULL)
    {
        // attach the remaining list to given node 
        ptNode->ptNext = ptDeletableNode->ptNext;

        // deallocate the memory
        free(ptDeletableNode);

        // update the tail if deleted node was tail
        if (ptNode->ptNext == NULL)
        {
            ptList->ptTail = ptNode;
        }
    }
}

// see header file for description
void vLinkedListRemoveAtIndex(list *ptList, int32_t i32Index)
{
    int32_t i32Counter = 0;
    node *ptPreviousNode = NULL;
    node *ptNode = ptList->ptHead;

    // check the empty list
    if (ptNode == NULL)
    {
        return;
    }

    if (i32Index == 0)
    {
        // remove node from the beginning
        vLinkedListRemoveFromBeginning(ptList);
    }
    else
    {
        // find the node
        while (i32Counter < i32Index && ptNode != NULL)
        {
            i32Counter++;
            ptPreviousNode = ptNode;
            ptNode = ptNode->ptNext;
        }

        // remove after the node
        vLinkedListRemoveAfterNode(ptPreviousNode);
    }
}

// see header file for description
void vLinkedListRemoveFromEnd(list *ptList)
{
    node *ptPreviousNode = NULL;
    node *ptNode = ptList->ptHead;

    // check the empty list
    if (ptList->ptTail == NULL)
    {
        return;
    }
    if (ptList->ptHead == ptList->ptTail)
    {
        // remove node from the beginning
        vLinkedListRemoveFromBeginning(ptList);
    }
    else
    {
        // reach the end
        while (ptNode->ptNext != NULL)
        {
            ptPreviousNode = ptNode;
            ptNode = ptNode->ptNext;
        }

        // remove tail node
        vLinkedListRemoveAfterNode(ptPreviousNode);
    }
}

// see header file for description
void vLinkedListTraverse(list *ptList)
{
    // get the head node
    node *ptNode = ptList->ptHead;

    printf("List : ");
    while (ptNode != NULL)
    {
        // do something with data
        printf("[%u]%d -> ", ptNode, ptNode->i32Data);
        ptNode = ptNode->ptNext;
    }
    printf("NULL\n");
}

// see header file for description
void vLinkedListExit(list *ptList)
{
    // check the head for empty list
    while (ptList->ptHead != NULL)
    {
        vLinkedListRemoveFromBeginning(ptList);
    }
}
