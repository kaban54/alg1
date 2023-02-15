#include "stack.h"


struct LStack *LStackCtor (size_t elem_size)
{
    struct LStack *stk = (struct LStack *) calloc (1, sizeof (struct LStack));
    if (stk == nullptr) return nullptr;

    stk -> elem_size = elem_size;

    return stk;
}

struct LStack *LStackDtor (struct LStack *stk)
{
    if (stk == nullptr) return nullptr;

    struct ListElem *elem = stk -> head;
    struct ListElem *next = nullptr;
    while (elem)
    {
        next = elem -> next;
        free (elem);
        elem = next;
    }

    free (stk);
    return nullptr;
}

int LPush (struct LStack *stk, void *buf)
{
    if (stk == nullptr || buf == nullptr) return 0;

    struct ListElem *elem = (struct ListElem *) calloc (1, sizeof (struct ListElem));

    memcpy (elem -> data, buf, stk -> elem_size);

    elem -> next = stk -> head;
    stk  -> head = elem;

    return 1;
}

int LTop (struct LStack *stk, void *buf)
{
    if (stk == nullptr || buf == nullptr) return 0;
    if (stk -> head == nullptr) return 0;

    memcpy (buf, stk -> head -> data, stk -> elem_size);

    return 1;
}

int LPop (struct LStack *stk)
{
    if (stk == nullptr) return 0;
    if (stk -> head == nullptr) return 0;
    
    struct ListElem *newhead = stk -> head -> next;

    free (stk -> head);
    stk -> head = newhead;

    return 1;
}