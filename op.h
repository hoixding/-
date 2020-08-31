#ifndef OP_H
#define OP_H
#include <iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<iostream>
#include<cmath>
#include<ctime>
#include<algorithm>
#include <vector>
#include<set>
#include<queue>
#include <sstream>
#include<string>
#include<sstream>
using namespace std;
struct my_struct {
    bool type;
    double num;
    char ch;

};

template <class T>
class template_Stack
{
public:
    virtual bool empty() const = 0;

    virtual int size() const = 0;

    virtual void push(const T& x) = 0;

    virtual T  pop() = 0;

    virtual T getTop() const = 0;

    virtual void clear() = 0;

    ~template_Stack() {};

    template_Stack() {};
};

template <class T>
class my_Stack :public template_Stack<T>
{
private:
    T* data;
    int top;
    int size_stack;
public:

    my_Stack() {
        size_stack = 150;
        data = new T[150];
        if (data == NULL)
            exit(0);
        top = -1;
    };
    ~my_Stack() {

        delete[] data;

    };
    bool empty() const { return top == -1; }
    int size() const { return top + 1; }
    void clear() { top = -1; }
    void push(const T& x);
    T  pop();
    T  getTop() const;

};

template <class T>
void my_Stack<T>::push(const T& x) {
    if (top == size_stack - 1)
    {
        T* tem_data = data;
        data = new T[2 * size_stack];
        if (data == NULL)
            exit(0);
        for (int i = 0; i < size_stack; ++i)
            data[i] = tem_data[i];
        size_stack *= 2;
        delete[] tem_data;
    }
    else
        data[++top] = x;
}
template <class T>
T my_Stack<T>::pop() {

    return data[top--];
}
template <class T>
T my_Stack<T>::getTop() const {

    return data[top];
}



#endif // OP_H
