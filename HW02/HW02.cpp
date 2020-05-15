#include "hw02_palindrome.h"

int main() {
    int a = 1001;
    string s = "hello";

    if (isPalindromeInt(a)){
        cout << "true" << endl;
    }
    else{
        cout << "false" << endl;
    }
    if (isPalindromeString(s)){
        cout << "true" << endl;
    }
    else {
        cout << "false" << endl;
    }

    return 0;
}