#include <fstream>
#include <iostream>
#include <string>
#include "5week/Array/ArrayStackTemplate.h"
using namespace std;

bool CheckMatching(string filename){
    ifstream is(filename);
    if(!is.is_open()){
        error("Error : 파일이 제대로 열리지 않았습니다.\n");
    }
    int nLine = 1;
    int nChar = 0;
    ArrayStack<char> stack;
    char ch;
    while(is.get(ch)){
        if(ch == '\n'){nLine++;}
        nChar++;
        if (ch == '[' || ch == '{' || ch == '('){
            stack.push(ch);
        }
        else if (ch == ']' || ch == '}' || ch == ')'){
            char prev = stack.pop();
            if ((ch == ']' && prev == '[') || (ch == '}' && prev == '{') || (ch == ')' && prev == '(')){
                break;
            }
            stack.push(ch);
        }
    }
    is.close();
    cout << filename << "파일 검사 결과 : " << endl;
    if (!stack.isEmpty()){
        cout << "Error: 문제발견 (총 라인수 : " << nLine << ", 총 문자수 : " << nChar << ")" << endl;
    }
    else {
        cout << "OK: 괄호닫기 정상 (총 라인수 : " << nLine << ", 총 문자수 : " << nChar << ")" << endl;
    }
    return stack.isEmpty();
}

int main() {
    CheckMatching("./5week/Array/ArrayStackTemplate.h");
    CheckMatching("./5week/blackboard.cpp");
    return 0;
}