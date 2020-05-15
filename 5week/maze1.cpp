#include <stack>
#include <iostream>
using namespace std;

const int MAZE_SIZE = 6;
char map[MAZE_SIZE][MAZE_SIZE] = {
    {'1','1','1','1','1','1'},
    {'e','0','1','0','1','1'},
    {'1','0','0','0','1','1'},
    {'1','0','1','0','0','0'},
    {'1','0','1','0','1','x'},
    {'1','1','1','1','1','1'},
};


struct Location2D{
    int row;
    int col;
    Location2D(int r = 0, int c = 0){
        row = r;
        col = c;
    }
    bool isNeighbor(Location2D &p){
        return ((row == p.row && col == p.col-1) ||
                (row == p.row && col == p.col+1) ||
                (row == p.row-1 && col == p.col) ||
                (row == p.row+1 && col == p.col)
        );
    }
    bool operator==(Location2D &p){return row=p.row && col == p.col;}
};

bool isValidLoc(int r, int c){
    if (r < 0 || c < 0 || r >= MAZE_SIZE || c >= MAZE_SIZE) {return false;}
    else return map[r][c] == '0' || map[r][c] == 'x';
}

int main() {
    stack<Location2D> locStack;
    Location2D entry(1,0);
    locStack.push(entry);
    while(locStack.empty() == false){
        Location2D here = locStack.top();
        locStack.pop();
        int r = here.row;
        int c = here.col;
        cout << "(" << r << "," << c << ")" ;
        if (map[r][c] == 'x'){
            cout << "탈출 성공\n";
            return 0;
        }
        else {
            map[r][c] = '.';
            if (isValidLoc(r-1, c)) locStack.push(Location2D(r-1,c));
            if (isValidLoc(r+1, c)) locStack.push(Location2D(r+1,c));
            if (isValidLoc(r, c-1)) locStack.push(Location2D(r,c-1));
            if (isValidLoc(r, c+1)) locStack.push(Location2D(r,c+1));
        }
    }
    cout << "탈출에 실패했습니다." << endl;
}