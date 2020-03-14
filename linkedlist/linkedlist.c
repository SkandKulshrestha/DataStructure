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
    // set the head with empty list
    ptList->ptHead = NULL;
}

// see header file for description
void vLinkedListInsertAtBeginning(list *ptList, node *ptNewNode)
{
    // attach head node after the new node
    ptNewNode->ptNext = ptList->ptHead;
    // update the head with new node
    ptList->ptHead = ptNewNode;
}

// see header file for description
void vLinkedListInsertAfterNode(node *ptNode, node *ptNewNode)
{
    // attach given node after new node
    ptNewNode->ptNext = ptNode->ptNext;
    // attach new node after given node
    ptNode->ptNext = ptNewNode;
}

// see header file for description
void vLinkedListRemoveFromBeginning(list *ptList)
{
    // get the head node
    node *ptObseleteNode = ptList->ptHead;
    if (ptObseleteNode != NULL)
    {
        // attach the head to its next
        ptList->ptHead = ptObseleteNode->ptNext;
        // deallocate the memory
        free(ptObseleteNode);
    }
}

// see header file for description
void vLinkedListRemoveAfterNode(node *ptNode)
{
    node *ptObseleteNode = ptNode->ptNext;
    if (ptObseleteNode != NULL)
    {
        // attach the remaining list to given node 
        ptNode->ptNext = ptObseleteNode->ptNext;
        // deallocate the memory
        free(ptObseleteNode);
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
    // set the head with empty list
    while (ptList->ptHead != NULL)
    {
        vLinkedListRemoveFromBeginning(ptList);
    }
}
