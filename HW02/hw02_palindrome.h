// 20192927 임규일
#pragma once
#include <iostream>
#include <string>
using namespace std;

int findDigits(int number);
int reverseDigits(int number, int number2 = 0);
bool isPalindromeInt(int number);
string reverseString(string str);
bool isPalindromeString(string str);

int findDigits(int number){
    int n = 1;
    while (number >= 10){
        number = number / 10;
        n = n * 10;
    }
    return n;
}

int reverseDigits(int number, int number2){
    int d = findDigits(number);
    if (number < 10){
        return number;
    }
    else {
        int t = (number%10) * d; number2+=t;
        return t + reverseDigits(number/10, number2);
    }
}

bool isPalindromeInt(int number){
    int rNum = reverseDigits(number);
    if (number == rNum){
        return true;
    }
    else {
        return false;
    }
}

string reverseString(string str){
    static int length = str.size() - 1;
    static int i = 0;

    char temp;
    if (i >= length){
        return str;
    }
    else {
        temp = str[i];
        str[i] = str[length];
        str[length] = temp;
        i++; length--;
        return reverseString(str);
    }
}

bool isPalindromeString(string str){
    string rStr = reverseString(str);
    if (rStr == str){
        return true;
    }
    else {
        return false;
    }
}