#include <iostream>
#include "LinkedlistStack.h"
using namespace std;

int main() {
    LinkedlistStack stack;
    for (int i = 0; i < 10; i++){
        stack.push(i);
    }
    stack.display();
    cout << stack.pop() << endl;
    cout << stack.pop() << endl;
    cout << stack.pop() << endl;
    stack.display();
}