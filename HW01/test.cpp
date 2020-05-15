#include <iostream>
#include "hw01_d_linked_list.h"
using namespace std;


int main() {
    dll_deque<int> d;

    d.addFront(2);
    d.addFront(1);
    d.addRear(3);
    d.addRear(4);
    d.addRear(5);


    cout << d.deleteFront() << " ";
    cout << d.deleteFront() << " ";
    cout << d.deleteRear() << " ";
    cout << d.deleteRear() << " ";
    cout << d.deleteRear() << endl;

    return 0;
}