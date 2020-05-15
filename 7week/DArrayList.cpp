#include <iostream>
#include <chrono>
#define MAX_LIST_SIZE 100000
using namespace std;

inline void error(const char* str){
    cerr << str << endl;
    exit(1);
};

class DArrayList{
    private:
        int *data;
        size_t length;
        size_t current_size;
        size_t resize_unit;
    public:
        DArrayList(size_t init_size = 10){
            cout << "\n<Initialize to : " << init_size << "> ";
            data = new int[init_size];
            current_size = init_size;
            resize_unit = init_size;
            length = 0;
        }
        ~DArrayList(){delete [] data;}

        void resize(size_t newsize){
            cout << "\n<Resize to : " << newsize << "> ";
            int *temparray = new int[newsize];
            for (int i = 0; i < length; i++){
                temparray[i] = data[i];
            }
            delete [] data;
            current_size = newsize;
            data = temparray;
        }

        void insert(int pos, int e){
            if(pos >= 0 && pos <= length){
                if(isFull()){
                    resize(current_size + resize_unit);
                }                
                for (int i = length; i > pos; i--){
                    data[i] = data[i-1];
                }
                data[pos] = e;
                length++;
            }
            else {cout << "삽입 위치가 잘못되었습니다." << endl;}
        }

        void remove(int pos){
            if(!isEmpty() && pos >= 0 && pos < length){
                if(current_size > resize_unit + length){
                    resize(current_size - resize_unit);
                }
                for(int i = pos + 1; i < length; i++){
                    data[i-1] = data[i];
                }
                length--;
            }
            else {cout << "포화상태 또는 삽입 위치가 잘못되었습니다." << endl;}

        }

        int getEntry(int pos){return data[pos];}

        bool isEmpty(){return length == 0;}

        bool isFull(){return length == current_size;}

        bool find(int item){
            for (int i = 0; i < length; i++){
                if (data[i] == item){return true;}
            }
            return false;
        }

        void replace(int pos, int e){
            if(!isEmpty() && pos >= 0 && pos < length){
                data[pos] = e;
            }
            else {cout << "포화상태 또는 삽입 위치가 잘못되었습니다." << endl;}
        }

        int size(){return length;}

        void display(){
            cout << "Arrat list의 총 항목 수 : " << length;
            for (int i = 0;i < length; i++){
                cout << " [" << data[i] << "]";
            }
            cout << "\n";
        }

        void clear(){
            length = 0;
            resize(resize_unit);
        }

};

int main() {
    DArrayList list(10);
    /*for (int i = 0; i < 20; i++){
        list.insert(list.size(), i);
        if (i % 10 == 9){
            list.display();
        }
    }

    for (int i = 0; i < 20; i++){
        list.remove(list.size() - 1);
        if (i % 10 == 9){
            list.display();
        }
    }*/

    for (int i = 0; i < 100; i++){
        auto start = chrono::steady_clock::now();
        list.insert(list.size(), i);
        auto end = chrono::steady_clock::now();
        cout << chrono::duration_cast<chrono::nanoseconds>(end - start).count() << endl;
    }
    
    for (int i = 0; i < 100; i++){
        auto start = chrono::steady_clock::now();
        list.remove(list.size() - 1);
        auto end = chrono::steady_clock::now();
        cout << chrono::duration_cast<chrono::nanoseconds>(end - start).count() << endl;
    }

    list.clear();

    return 0;
}