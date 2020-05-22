#include <iostream>
#include <cstdlib>
#include <ctime>
#include <Windows.h>
#include <queue>
#include <stack>

#define MAZE_SIZE 10

using namespace std;

int map[MAZE_SIZE][MAZE_SIZE] = {{1,1,0,0,0,0,0,0,0,0},
                                 {0,0,0,0,0,0,0,0,0,0},
                                 {0,0,0,0,0,0,0,0,0,0},
                                 {0,0,0,0,0,0,0,0,0,0},
                                 {0,0,0,0,0,0,0,0,0,0},
                                 {0,0,0,0,0,0,0,0,0,0},
                                 {0,0,0,0,0,0,0,0,0,0},
                                 {0,0,0,0,0,0,0,0,0,0},
                                 {0,0,0,0,0,0,0,0,0,0},
                                 {0,0,0,0,0,0,0,0,0,0}};

bool isValidLoc(int r, int c){
    if(r < 0 || c < 0 || r>=MAZE_SIZE || c>=MAZE_SIZE){return false;}
    else{return map[r][c] == 1 || map[r][c] == 2;}
}

struct Location2D {
    int  row;
    int  col;
    Location2D (int r=0, int c=0) { row = r; col = c; }
    bool isNeighbor(Location2D &p) {
        return((row==p.row && (col==p.col-1 || col==p.col+1))
            || (col==p.col && (row==p.row-1 || row==p.row+1)));
    }
    // == 오퍼레이터를 연산자 오버로딩을 통해 2d 비교로 사용합니다
    bool operator==(Location2D &p) {return row==p.row && col==p.col;}
};

void printMap();
bool pathableNext(int x, int y, int _x, int _y);
bool pathableNow(int x, int y);
bool isEnd(int x, int y);
void making_path();
void setExit();
void dfs();
void bfs();
int mazeLength();

int main() {
    making_path();
   printMap();

   return 0;
}

void printMap(){
   for (int i = 0; i < MAZE_SIZE; i++){
      for (int j = 0; j < MAZE_SIZE; j++){
         if (map[i][j] == 0){
            cout << "■ ";
         }
         else if (map[i][j] == 1){
            cout << "□ ";
         }
         else if (map[i][j] == 2){
            cout << "# ";
         }
      }
      cout << "\n";
   }
}

bool pathableNext(int x, int y, int _x, int _y){
   if (x < 0 || y < 0){
      return false;
   }
   else if (x > MAZE_SIZE-1 || y > MAZE_SIZE-1){
      return false;
   }
   else if (x == _x && y == _y){
      return false;
   }
   else if (map[x][y] == 2){
      return false;
   }
   else if (map[x][y] == 1){
      return false;
   }

   int path = 0;

   if (map[x-1][y-1] == 1){path++;}
   if (map[x-1][y] == 1){path++;}
   if (map[x-1][y+1] == 1){path++;}
   if (map[x][y-1] == 1){path++;}
   if (map[x][y+1] == 1){path++;}
   if (map[x+1][y-1] == 1){path++;}
   if (map[x+1][y] == 1){path++;}
   if (map[x+1][y+1] == 1){path++;}

   if ((x == 0 && y == 0) || (x == 0 && y == MAZE_SIZE-1) || (x == MAZE_SIZE-1 && y == 0) || (x == MAZE_SIZE-1 && y == MAZE_SIZE-1)){
      if (path == 1){
         return true;
      }
   }

   if (path < 3){return true;}
   else {return false;}
}

bool pathableNow(int x, int y){
   if (map[x][y] == 2){
      return false;
   }
   int path = 0;
   if (map[x-1][y-1] == 1){path++;}
   if (map[x-1][y] == 1){path++;}
   if (map[x-1][y+1] == 1){path++;}
   if (map[x][y-1] == 1){path++;}
   if (map[x][y+1] == 1){path++;}
   if (map[x+1][y-1] == 1){path++;}
   if (map[x+1][y] == 1){path++;}
   if (map[x+1][y+1] == 1){path++;}

   if ((x == 0 && y == 0) || (x == 0 && y == MAZE_SIZE-1) || (x == MAZE_SIZE-1 && y == 0) || (x == MAZE_SIZE-1 && y == MAZE_SIZE-1)){
      if (path == 1){
         return true;
      }
   }
   else {
      if (path < 4){
         return true;
      }
   }
   return false;
}

bool isEnd(int x, int y){
   if (x == MAZE_SIZE-1 || y == MAZE_SIZE-1){
      return true;
   }
   if (x > 3 && y == 0){
      return true;
   }
   return false;
}

void making_path(){
   clock_t begin, end;
   begin = clock();
   srand(static_cast<unsigned int>(time(0)));
   queue<Location2D> locQueue; //현재 위치 넣을 큐
   Location2D entry(0,0);
   int x = 0, y = 1;
   int _x = 0, _y = 0; // 전 위치
   int random; // 상하좌우 랜덤 수
   bool p_next; // 길을 만들 수 있는지 확인하는 불 변수
   bool p_now;
   bool e = false; // 도착점에 도착했는지 확인하는 불 변수
   int Try = 0;

   locQueue.push(Location2D(x,y));

   while (!e){
      random = rand() % 10;
      switch(random){
         case 0:
         case 1: // up
            p_next = pathableNext(x-1, y, _x, _y);
            if (p_next == true){
               map[x-1][y] = 1;
               _x = x; _y = y;
               x = x - 1;
               locQueue.push(Location2D(x,y));
            }
            break;
         case 2:
         case 3:
         case 4: // down
            p_next = pathableNext(x+1, y, _x, _y);
            if (p_next == true){
               map[x+1][y] = 1;
               _x = x; _y = y;
               x = x + 1;
               locQueue.push(Location2D(x,y));
            }
            break;
         case 5: // left
            p_next = pathableNext(x, y-1, _x, _y);
            if (p_next == true){
               map[x][y-1] = 1;
               _x = x; _y = y;
               y = y - 1;
               locQueue.push(Location2D(x,y));
            }
            break;
         case 6:
         case 7:
         case 8:
         case 9: // right
            p_next = pathableNext(x, y+1, _x, _y);
            if (p_next == true){
               map[x][y+1] = 1;
               _x = x; _y = y;
               y = y + 1;
               locQueue.push(Location2D(x,y));
            }
            break;
      }
      e = isEnd(x, y);
      Try++;
      if (Try > 100){
         break;
      }
      Sleep(1);
   }


   while (locQueue.empty() == false){
      e = false;
      Try = 0;
      Location2D node = locQueue.front();
      x = node.row; y = node.col;
      while (!e){
         random = rand() % 10;
         switch(random){
            case 0:
            case 1: // up
               p_next = pathableNext(x-1, y, _x, _y);
               if (p_next == true){
                  map[x-1][y] = 1;
                  _x = x; _y = y;
                  x = x - 1;
                  locQueue.push(Location2D(x,y));
               }
               break;
            case 2:
            case 3:
            case 4: // down
               p_next = pathableNext(x+1, y, _x, _y);
               if (p_next == true){
                  map[x+1][y] = 1;
                  _x = x; _y = y;
                  x = x + 1;
                  locQueue.push(Location2D(x,y));
               }
               break;
            case 5: // left
               p_next = pathableNext(x, y-1, _x, _y);
               if (p_next == true){
                  map[x][y-1] = 1;
                  _x = x; _y = y;
                  y = y - 1;
                  locQueue.push(Location2D(x,y));
               }
               break;
            case 6:
            case 7:
            case 8:
            case 9: // right
               p_next = pathableNext(x, y+1, _x, _y);
               if (p_next == true){
                  map[x][y+1] = 1;
                  _x = x; _y = y;
                  y = y + 1;
                  locQueue.push(Location2D(x,y));
               }
               break;
         }
         e = isEnd(x, y);
         Try++;
         if (Try > 100){
            break;
         }
         Sleep(1);
      }
      locQueue.pop();
   }
   while (locQueue.empty() == false){
      e = false;
      Try = 0;
      Location2D node = locQueue.front();
      x = node.row; y = node.col;
      while (!e){
         random = rand() % 10;
         switch(random){
            case 0:
            case 1: // up
               p_next = pathableNext(x-1, y, _x, _y);
               if (p_next == true){
                  map[x-1][y] = 1;
                  _x = x; _y = y;
                  x = x - 1;
                  locQueue.push(Location2D(x,y));
               }
               break;
            case 2:
            case 3:
            case 4: // down
               p_next = pathableNext(x+1, y, _x, _y);
               if (p_next == true){
                  map[x+1][y] = 1;
                  _x = x; _y = y;
                  x = x + 1;
                  locQueue.push(Location2D(x,y));
               }
               break;
            case 5: // left
               p_next = pathableNext(x, y-1, _x, _y);
               if (p_next == true){
                  map[x][y-1] = 1;
                  _x = x; _y = y;
                  y = y - 1;
                  locQueue.push(Location2D(x,y));
               }
               break;
            case 6:
            case 7:
            case 8:
            case 9: // right
               p_next = pathableNext(x, y+1, _x, _y);
               if (p_next == true){
                  map[x][y+1] = 1;
                  _x = x; _y = y;
                  y = y + 1;
                  locQueue.push(Location2D(x,y));
               }
               break;
         }
         e = isEnd(x, y);
         Try++;
         if (Try > 100){
            break;
         }
         Sleep(1);
      }
      locQueue.pop();
   }
   setExit();
   end = clock();
   cout << "미로 생성 시간 : " << (double)(end - begin) << "ms" << endl;
}

void setExit(){
   srand(static_cast<unsigned int>(time(0)));
   while (1){
      int row = rand()%MAZE_SIZE;
      int col = rand()%MAZE_SIZE;
      if ((row == MAZE_SIZE-1 || col == MAZE_SIZE-1)){
         map[row][col] = 2;
         break;
      }
   }
}

void bfs(){
   clock_t begin, end;
   begin = clock();
   queue<Location2D> locQueue;                
   Location2D entry(0,0);                    
   locQueue.push( entry );

   while ( locQueue.empty() == false ) {    
      Location2D  here = locQueue.front();
      locQueue.pop();                        

      int r = here.row;
      int c = here.col;
      if( map[r][c] == 2 ) {            
         std::cout << "탈출에 성공했습니다.\n";
         end = clock();
         cout << "bfs time : " << (double)(end - begin) << "ms" << endl;
         return ;
      }
      else {                                 
         map[r][c] = '.';                
         if(isValidLoc(r-1, c)) locQueue.push(Location2D(r-1,c));
         if(isValidLoc(r+1, c)) locQueue.push(Location2D(r+1,c));
         if(isValidLoc(r, c-1)) locQueue.push(Location2D(r,c-1));
         if(isValidLoc(r, c+1)) locQueue.push(Location2D(r,c+1));
      }
   }
   std::cout << "탈출에 실패했습니다\n";
   end = clock();
   cout << "bfs begin time : " << begin << '\n' << "bfs end time : " << end << "ms" << endl;
   return ;
}

void dfs(){
   clock_t begin, end;
   begin = clock();
   stack<Location2D> locStack;                
   Location2D entry(0,0);                    
   locStack.push( entry );                    

   while(locStack.empty() == false){    
      Location2D  here = locStack.top();    
      locStack.pop();                        

      int r = here.row;
      int c = here.col;
      if(map[r][c] == 2){
         std::cout << "탈출에 성공했습니다.\n";
         return;
      }
      else{
         map[r][c] = '.';                
         if(isValidLoc(r-1, c)) locStack.push(Location2D(r-1,c));
         if(isValidLoc(r+1, c)) locStack.push(Location2D(r+1,c));
         if(isValidLoc(r, c-1)) locStack.push(Location2D(r,c-1));
         if(isValidLoc(r, c+1)) locStack.push(Location2D(r,c+1));
      }
   }
   cout << "탈출에 실패했습니다\n";
   end = clock();
   cout << "dfs begin time : " << begin << '\n' << "dfs end time : " << end << "ms" << endl;
   return;
}

int mazeLength(){
   int length = 0;
   for (int i = 0; i < MAZE_SIZE; i++){
      for (int j = 0; j < MAZE_SIZE; j++){
         if (map[i][j] == 1 || map[i][j] == 2){
            length++;
         }
      }
   }
   return length;
}