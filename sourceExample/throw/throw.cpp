#include <iostream>
using namespace std;

void swap(int &a, int &b){
    int temp;
    if (a == b) throw a;
    temp = a;
    a = b;
    b = temp;
}

int main() {

    try{
        int a = 3;
        int b = 3;
        swap(a,b);
    }
    catch(int val){
        cout << "두 값이 모두 " << val << "(으)로 같습니다."<<endl;
    }

    int num = 0;
    try{
        if (num == 0){
            throw num;
        }
        cout << 2/num << endl;
    }
    catch(int num){
        cout << num << "은 올바르지 않은 분모입니다." << endl;
    }


    return 0;
}