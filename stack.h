#ifndef STACK_H
#define STACK_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <math.h>


struct ListElem
{
    void *data;
    struct ListElem *next;
};

struct LStack
{
    size_t elem_size;
    struct ListElem *head;
};

struct VStack
{
    size_t size;
    size_t capacity;
    size_t elem_size;
    void *data;
};


struct LStack *LStackCtor (size_t elem_size);

struct LStack *LStackDtor (struct LStack *stk);

int LPush (struct LStack *stk, void *buf);

int LPop (struct LStack *stk);

int LTop (struct LStack *stk, void *buf);


struct VStack *VStackCtor (size_t cap, size_t elem_size);

struct VStack *VStackDtor (struct VStack *stk);

int VPush (struct VStack *stk, void *buf);

int VPop (struct VStack *stk);

int VTop (struct VStack *stk, void *buf);

void *Recalloc (void *memptr, size_t num, size_t size, size_t old_num);


int Test1 (FILE *file);
int Test2 (FILE *file);
int Test3 (FILE *file);


#endif