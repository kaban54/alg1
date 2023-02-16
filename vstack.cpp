#include "stack.h"


struct VStack *VStackCtor (size_t cap, size_t elem_size)
{
    struct VStack *stk = (struct VStack *) calloc (1, sizeof (struct VStack));
    if (stk == nullptr) return nullptr;

    stk -> data = calloc (cap, elem_size);
    if (stk -> data == nullptr)
    {
        free (stk);
        return nullptr;
    }

    stk -> elem_size = elem_size;
    stk -> capacity  = cap;
    stk -> size      = 0;

    return stk;
}

struct VStack *VStackDtor (struct VStack *stk)
{
    if (stk) free (stk -> data);
    free (stk);
    return nullptr;
}

int VPush (struct VStack *stk, void *buf)
{
    if (stk == nullptr || buf == nullptr) return 0;

    if (stk -> size >= stk -> capacity)
    {
        size_t size = stk -> size;
        stk -> data = Recalloc (stk -> data, size * 2, stk -> elem_size, size);
        if (stk -> data == nullptr) return 0;

        stk -> capacity = size * 2;
    }

    memcpy ((char *) (stk -> data) + (stk -> size) * stk -> elem_size, buf, stk -> elem_size);
    stk -> size ++;

    return 1;
}

int VTop (struct VStack *stk, void *buf)
{
    if (stk == nullptr || buf == nullptr) return 0;
    if (stk -> size <= 0) return 0;

    memcpy (buf, (char *) (stk -> data) + (stk -> size - 1) * stk -> elem_size, stk -> elem_size);

    return 1;
}

int VPop (struct VStack *stk)
{
    if (stk == nullptr) return 0;
    if (stk -> size <= 0) return 0;

    stk -> size --;

    memset ((char *) (stk -> data) + stk -> size * stk -> elem_size, 0, stk -> elem_size);

    return 1;
}



void *Recalloc (void *memptr, size_t num, size_t size, size_t old_num)
{
    memptr = realloc (memptr, num * size);
    if (memptr == nullptr) return nullptr;

    if (num > old_num) memset ((void *) ((char *) memptr + old_num * size), 0, (num - old_num) * size);

    return memptr;
}