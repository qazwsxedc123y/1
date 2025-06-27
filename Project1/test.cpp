#define  _CRT_SECURE_NO_WARNINGS

class Foo {
protected:
    sem_t firstmutex;
    sem_t secondmutex;
public:
    Foo() {
        sem_init(&firstmutex, 0, 0);
        sem_init(&secondmutex, 0, 0);
    }

    void first(function<void()> printFirst) {

        // printFirst() outputs "first". Do not change or remove this line.
        printFirst();
        sem_post(&firstmutex);
    }

    void second(function<void()> printSecond) {
        sem_wait(&firstmutex);
        // printSecond() outputs "second". Do not change or remove this line.
        printSecond();
        sem_post(&secondmutex);
    }

    void third(function<void()> printThird) {
        sem_wait(&secondmutex);
        // printThird() outputs "third". Do not change or remove this line.
        printThird();
    }
};