#pragma once
#include <iostream>
#include "Student.h"
using namespace std;

#define MAX_STACK_SIZE 100

inline int error(const char* str){
    cerr << str << "\n";
    exit(1);
};

class StudentStack{
    private:
        Student data[MAX_STACK_SIZE];
        int top;
    public :
        StudentStack(){top = -1;}
        ~StudentStack(){}
        bool isEmpty(){return top == -1;}
        bool isFull(){return top == MAX_STACK_SIZE - 1;}
        void push(Student e){
            if (isFull()){
                error("스택이 가득 차 있습니다.");
            }
            data[++top] = e;
        }
        Student pop(){
            if (isEmpty()){
                error("스택이 비어 있습니다.");
            }
            return data[top--];
        }
        Student peek(){
            if (isEmpty()){
                error("스택이 비어 있습니다.");
            }
            return data[top];
        }
        void display() {
            cout << "[스택 항목의 수 = " << top+1 << "] " << endl;;
            for (int i = 0; i <= top; i++){
                cout << "<" << data[i].contents() << ">" << endl;
            }
            cout << "\n";
        }
};