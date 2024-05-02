#define  _CRT_SECURE_NO_WARNINGS

//typedef struct SLlist
//{
//    int* a;
//    int _top;
//    int _capacity;
//}ST;
//
//ST* stackCreate(int cpacity)
//{
//    ST* st1 = malloc(sizeof(ST));
//    st1->a = malloc(sizeof(int) * cpacity);
//    st1->_top = -1;
//    st1->_capacity = cpacity;
//    return st1;
//}
//
//void StackPush(ST* ps, int data)
//{
//    if (ps->_top + 1 == ps->_capacity)
//    {
//        int newcapacity = ps->_capacity == 0 ? 4 : ps->_capacity * 2;
//        int* tmp = (int*)realloc(ps->a, sizeof(int) * newcapacity);
//        if (tmp == NULL)
//        {
//            perror("realloc error");
//            return;
//        }
//        ps->_capacity = newcapacity;
//        ps->a = tmp;
//    }
//    ps->_top++;
//    ps->a[ps->_top] = data;
//}
//
//void StackPop(ST* ps)
//{
//    assert(ps);
//    //assert(!StackEmpty(ps));
//    //assert(!*ps);
//    ps->_top--;
//}
//
//int StackTop(ST* ps)
//{
//    assert(ps);
//    //assert(!StackEmpty(ps));
//    return ps->a[ps->_top];
//}
//
//int StackSize(ST* ps)
//{
//    assert(ps);
//    //assert(!StackEmpty(ps));
//    return ps->_top + 1;
//}
//
//// 检测栈是否为空，如果为空返回 真 ，如果不为空返回 假 
//int StackEmpty(ST* ps)
//{
//    assert(ps);
//    return ps->_top == -1;
//}
//
//void StackDestroy(ST* ps)
//{
//    assert(ps);
//    ps->_capacity = 0;
//    ps->_top = -1;
//    free(ps->a);
//    ps->a = NULL;
//}
//typedef struct {
//    ST* instack;
//    ST* outstack;
//} MyQueue;
//
//
//MyQueue* myQueueCreate() {
//    MyQueue* obj = malloc(sizeof(MyQueue));
//    obj->instack = stackCreate(100);
//    obj->outstack = stackCreate(100);
//    return obj;
//}
//
//void myQueuePush(MyQueue* obj, int x) {
//    StackPush(obj->instack, x);
//}
//
//int myQueuePop(MyQueue* obj) {
//    //先将in全跑到out
//    if (!StackEmpty(obj->outstack))
//    {
//        int tmp = StackTop(obj->outstack);
//        StackPop(obj->outstack);
//        return tmp;
//    }
//    while (!StackEmpty(obj->instack))
//    {
//        StackPush(obj->outstack, StackTop(obj->instack));
//        StackPop(obj->instack);
//    }
//    int tmp = StackTop(obj->outstack);
//    StackPop(obj->outstack);
//    return tmp;
//}
//
//int myQueuePeek(MyQueue* obj) {
//    if (!StackEmpty(obj->outstack))
//    {
//        int tmp = StackTop(obj->outstack);
//        return tmp;
//    }
//    while (!StackEmpty(obj->instack))
//    {
//        StackPush(obj->outstack, StackTop(obj->instack));
//        StackPop(obj->instack);
//    }
//    return StackTop(obj->outstack);
//}
//
//bool myQueueEmpty(MyQueue* obj) {
//    return StackEmpty(obj->instack) && StackEmpty(obj->outstack);
//}
//
//void myQueueFree(MyQueue* obj) {
//    StackDestroy(obj->instack);
//    StackDestroy(obj->outstack);
//}

/**
 * Your MyQueue struct will be instantiated and called as such:
 * MyQueue* obj = myQueueCreate();
 * myQueuePush(obj, x);

 * int param_2 = myQueuePop(obj);

 * int param_3 = myQueuePeek(obj);

 * bool param_4 = myQueueEmpty(obj);

 * myQueueFree(obj);
*/