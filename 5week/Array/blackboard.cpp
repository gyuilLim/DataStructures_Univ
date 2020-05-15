#include <iostream>
#include "ArrayStackTemplate.h"
#include "Student.h"
using namespace std;

int main() {
    ArrayStack<double> stack;
    for (int i = 0; i < 10; i++){
        stack.push(i);
    }

    stack.display();
    cout << stack.pop() << endl;
    cout << stack.pop() << endl;
    cout << stack.pop() << endl;
    stack.display();

    ArrayStack<Student> stack2;
    stack2.push((Student(20200001, "gagaga" , "sss")));
    stack2.push((Student(20200001, "gagaga" , "sss")));
    stack2.push((Student(20200001, "gagaga" , "sss")));
    stack2.display();
    stack2.pop();
    stack2.display();

    return 0;
}