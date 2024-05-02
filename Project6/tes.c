#define  _CRT_SECURE_NO_WARNINGS
#include<stdbool.h>
#include<assert.h>
#include<stdio.h>
#include<stdlib.h>
typedef struct Queue {
    struct Queue* next;
    int val;
}Queue;

typedef struct {
    Queue* top;
} MyStack;


MyStack* myStackCreate() {
    MyStack* st = malloc(sizeof(MyStack));
    return st;
}

void myStackPush(MyStack* obj, int x) {
    Queue* newcode = malloc(sizeof(Queue));
    newcode->val = x;
    newcode->next = obj->top;
    obj->top = newcode;
}

int myStackPop(MyStack* obj) {
    Queue* newcode = obj->top;
    int val = newcode->val;
    obj->top = newcode->next;
    free(newcode);
    return val;
}

int myStackTop(MyStack* obj) {
    return obj->top->val;
}

bool myStackEmpty(MyStack* obj) {
    return (obj->top == NULL);
}

void myStackFree(MyStack* obj) {
    while (obj->top != NULL)
    {
        Queue* newcode = obj->top;
        obj->top = obj->top->next;
        free(newcode);
    }
    free(obj);
}