#include <iostream>
using namespace std;

void printMap(int map[][7], int n) {
    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            if (map[i][j] == 0){
                cout << "■";
            }
            else{
                cout << "□";
            }
        }
        cout << "\n";
    }
}

int main() {
    int map[7][7] = {{0,0,0,0,0,0,0},
                 {0,0,0,0,0,0,0},
                 {0,0,0,0,0,0,0},
                 {0,0,0,0,0,0,0},
                 {0,0,0,0,0,0,0},
                 {0,0,0,0,0,0,0},
                 {0,0,0,0,0,0,0}};

    printMap(map, 7);

    return 0;
}