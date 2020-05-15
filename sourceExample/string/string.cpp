#include <iostream>
#include <string>
using namespace std;

int main() {
    char textArr[6] = "Happy";
    string textStr = "Day!";
    cout << textArr + textStr << endl;

    string userName;
    cout << "what's your name?" << endl;
    getline(cin, userName);
    cout << "Hello " << userName << endl;
//-----------------------------------------------

    string sPi = "3.14";
    double pi = 3.14;
    if (stod(sPi) == pi){
        cout << "Match!" << endl;
    }

    cout << "size of string : " << sPi.size() << endl;
    cout << "empty? : " << sPi.empty() << endl;
    cout << "append string " << sPi.append("285") << endl;
//----------------------------------------------------------

    string dogSound = "멍멍";
    string catSound = "야옹";

    cout << dogSound.compare(catSound) << endl;
//-----------------------------------------------------

    string userName1 = "lim gyuil";
    string fullName = userName1.assign(userName1);
    cout << fullName << endl;

    string lastName = fullName.assign(fullName, 0, 3);
    cout << lastName << endl;

    int firstNameIdx = userName1.find("Jin");
    cout << "name idx : " << firstNameIdx << endl;

    userName1.insert(firstNameIdx, "student");
    cout << "new name : " << userName1 << endl;

    userName1.erase(firstNameIdx, 10);
    cout << "new name : "<< userName1 << endl;

    userName1.replace(firstNameIdx, 8, "Man");
    cout << "new name : " << userName1 << endl;

    return 0;
}