#include <windows.h>
#include <stdio.h>

extern "C"
{

// A self referential structure
typedef struct tagNODE
{
    struct tagNODE *pNext;
    INT value;
} NODE, *PNODE;

PNODE g_pHead = NULL;

void __stdcall printAllNodes(PNODE pHead)
{
    PNODE pNode;
    INT index = 0;
    printf("---\n");
    for (pNode = pHead; pNode; pNode = pNode->pNext)
    {
        printf("%p(%d): pNode %p, value %d, pNext %p\n", pHead, index, pNode, pNode->value, pNode->pNext);
        ++index;
    }
}

BOOL __cdecl addNode(PNODE& pHead, INT value)
{
    PNODE pNode = new NODE; //PNODE pNode = malloc(sizeof(NODE))
    pNode->value = value;
    pNode->pNext = pHead;
    pHead = pNode;
    return TRUE;
}

PNODE __stdcall findNode(PNODE pHead, INT value)
{
    PNODE pNode;
    for (pNode = pHead; pNode; pNode = pNode->pNext)
    {
        if (pNode->value == value)
            return pNode;
    }
    return NULL;
}

void __stdcall deleteNode(PNODE& pHead, PNODE pTarget) // This function has a bug.
{
    PNODE pNode;

    if (!pTarget)
        return;

    for (pNode = pHead; pNode; pNode = pNode->pNext)
    {
        if (pNode->pNext == pTarget)
        {
            pNode->pNext = pTarget->pNext;
            break;
        }
    }

    delete pTarget; //free(pTarget);
}

void __stdcall deleteAllNodes(PNODE& pHead)
{
    PNODE pNode, pNext;
    for (pNode = pHead; pNode; pNode = pNext)
    {
        pNext = pNode->pNext;
        delete pNode; //free(pNode);
    }
    pHead = NULL;
}

} // extern "C"

int main(void)
{
    printAllNodes(g_pHead);

    addNode(g_pHead, 123);
    printAllNodes(g_pHead);

    addNode(g_pHead, 456);
    printAllNodes(g_pHead);

    //deleteNode(g_pHead, findNode(g_pHead, 456)); // buggy
    printAllNodes(g_pHead);

    addNode(g_pHead, 789);
    printAllNodes(g_pHead);

    addNode(g_pHead, 555);
    printAllNodes(g_pHead);

    deleteAllNodes(g_pHead);
    printAllNodes(g_pHead);
    return 0;
}
