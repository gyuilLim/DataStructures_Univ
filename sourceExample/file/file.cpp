#include <iostream>
#include <fstream>
using namespace std;

int main() {
    string dataStructure = "자료구조는 다양한 자료구조의 형태와 알고리즘을 배우는 과목입니다.";
    ofstream f_out("ds.txt");

    if (!f_out){
        cout << "파일이 열려있지 않습니다." << endl;
    }
    else {
        f_out << dataStructure << endl;
        f_out.close();
    }

    ofstream f_out2("ds.txt", ios::app);
    string dataStructure2 = "이번 학기 자료구조는 윤진혁 교수가 가르칩니다.";
    if (!f_out){
        cout << "파일이 열려있지 않습니다." << endl;
    }
    else {
        f_out2 << dataStructure2 << endl;
        f_out2.close();
    }

    char letter;
     
    ifstream f_in("ds.txt");
    if(!f_in){
        cout << "파일이 열려있지 않습니다." << endl;
    }
    else {
        for (int i = 0; !f_in.eof(); i++){
            f_in.get(letter);
            cout << letter;
        }
    }
    

    return 0;
}

/*
ios::binary : 파일을 binary로 다룹니다.
ios::in : 파일을 읽기만 가능한 형태로 엽니다.
ios::out : 파일을 쓰기 가능한 형태로 엽니다.
ios::ate : 파일을 오픈하면서 파일포인터를 끝으로 옮깁니다.
ios::trunc : 오픈하고자 하는 파일이 이미 있는 경우, 기존의 파일을 삭제하고 다시 만듭니다(기본)
ios::nocreate : 파일을 열지 않고 파일이 있는지만 확인합니다. 파일이 업으면 에러
ios::noreplace : 파일이 존재하면 에러를 발생합니다.
*/