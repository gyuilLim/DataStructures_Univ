#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int hanoiTower(int n, char from, char tmp, char to){
    if (n == 1){
        return 1;
        //cout << "원판 1을 " << from << " 에서 " << to << "로 옮깁니다. \n";
    }
    else {
        int val1 = hanoiTower(n-1, from, to, tmp);
        cout << "원판 " << n << "을 "<<from << " 에서 " << to << "로 옮깁니다. \n";
        int val2 = hanoiTower(n-1, tmp, from, to);
        return val1 + val2;
    }
}

int main() {
    cout << hanoiTower(10, 'a', 'b', 'c');

    return 0;
}