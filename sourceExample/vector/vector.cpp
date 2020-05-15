#include <iostream>
#include <vector>
using namespace std;

int main() {
    vector <int> lottoNumVec(6);
    int lottoNumArray[6] = {10, 23, 25, 31, 38, 40};

    lottoNumVec.insert(lottoNumVec.begin(), lottoNumArray, lottoNumArray+3);
    cout << lottoNumVec[2] << endl;
    cout << lottoNumVec.at(2) << endl;

    lottoNumVec.insert(lottoNumVec.begin() + 4, 44);
    cout << lottoNumVec.at(4) << endl;

    cout << lottoNumVec.size() << endl;
    cout << lottoNumVec.back() << endl;
    cout << lottoNumVec.front() << endl;
    cout << lottoNumVec.empty() << endl;


    return 0;
}