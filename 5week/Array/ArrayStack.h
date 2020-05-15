#pragma once
#include <iostream>
using namespace std;

#define MAX_STACK_SIZE 100

inline int error(const char* str){
    cerr << str << "\n";
    exit(1);
};

class ArrayStack{
    private:
        int data[MAX_STACK_SIZE];
        int top;
    public :
        ArrayStack(){top = -1;}
        ~ArrayStack(){}
        bool isEmpty(){return top == -1;}
        bool isFull(){return top == MAX_STACK_SIZE - 1;}
        void push(int e){
            if (isFull()){
                error("스택이 가득 차 있습니다.");
            }
            data[++top] = e;
        }
        int pop(){
            if (isEmpty()){
                error("스택이 비어 있습니다.");
            }
            return data[top--];
        }
        int peek(){
            if (isEmpty()){
                error("스택이 비어 있습니다.");
            }
            return data[top];
        }
        void display() {
            cout << "[스택 항목의 수 = " << top+1 << "] ";
            for (int i = 0; i <= top; i++){
                cout << "<" << data[i] << ">";
            }
            cout << "\n";
        }
};