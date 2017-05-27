/*用栈实现队列*/

#include<iostream>
#include<stack>

using namespace std;

// 定义一个模板类
template<typename T>class MyQueue{

public:

    MyQueue(void);
    virtual ~MyQueue(void);

    void enterQueue(const T& node);
    T outQueue();

private:

    stack<T> stack1;
    stack<T> stack2;
};

// 入队列，相当于对第一个栈做入栈操作。
template<typename T> void MyQueue<T>::enterQueue(const T& element){

    stack1.push(element);
}

// 出队列
template<typename T> T MyQueue<T>::outQueue(){

    if(stack2.size() <= 0){

        while(stack1.size()>0){

            T& data = stack1.top();
            stack1.pop();
            stack2.push(data);
        }
    }

    if(stack2.size()==0)
        throw new exception(" is empty");
    
    T head = stack2.top();
    stack2.pop();

    return head;
}