#include "postfix.h"
#include <iostream>
#include <string>

int main() {
    /*
    cout << "수식 입력(postfix) : ";
    double res = calcPostfixExpr();
    cout << "계산 결과 = " << res << endl;
    string input = "30 20 100 + *";
    cout << "미리 입력된 수식 (postfix) : " << input << endl;
    res = calcPostfixExpr(input);
    cout << "계산 결과 = " << res << endl; 

    cout << "수식 입력(infix) : ";
    string res2 = infix2Postfix();
    cout << "변환 결과 = " << res2 << endl;
    string input2 = "30 + 20 * 100";
    res2 = infix2Postfix(input2);
    cout << "미리 입력된 수식 (infix) : " << input2 << endl;
    res2 = infix2Postfix(input2);
    cout << "계산 결과 = " << res2 << endl;
    */
    string input3 = "30 + 20 * 100";
    cout << "미리 입력된 수식 (infix) : " << input3 << endl;
    string res3 = infix2Postfix(input3);
    cout << "변환 결과 = " << res3 << endl;
    double res4 = calcPostfixExpr(res3);
    cout << "수식 계산 결과 = " << res4 << endl;

    return 0;
}