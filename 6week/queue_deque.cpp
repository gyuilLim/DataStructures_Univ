#include <iostream>
using namespace std;

#define MAX_QUEUE_SIZE 100

inline void error(const char* str){
    cerr << str << endl;
    exit(1);
};

class CircularQueue{
    protected:
        int front;
        int rear;
        int data[MAX_QUEUE_SIZE];
    public:
    CircularQueue(){front = rear = 0;}
    ~CircularQueue(){}
    bool isEmpty(){return front == rear;}
    bool isFull(){return (rear+1) % MAX_QUEUE_SIZE == front;}
    void enqueue(int val){
        if(isFull()){
            error("ERROR: 큐가 포화상태입니다.\n");
        }
        else {
            rear = (rear+1) % MAX_QUEUE_SIZE;
            data[rear] = val;
        }
    }
    int dequeue(){
        if(isEmpty()){
            error("ERROR: 큐가 공백상태입니다.\n");
        }
        else {
            front = (front+1) % MAX_QUEUE_SIZE;
            return data[front];
        }
    }
    int peek(){
        if(isEmpty()){
            error("ERROR: 큐가 공백상태입니다.\n");
        }
        else {
            return data[(front+1) % MAX_QUEUE_SIZE];
        }
    }
    void display(){
        cout << "Queue 안에는 : ";
        int maxi = (front < rear) ? rear : rear + MAX_QUEUE_SIZE;
        for (int i = front + 1; i <= maxi; i++){
            cout << data[i%MAX_QUEUE_SIZE] << " ";
        }
        cout << "\n";
    }
};

class CircularDeque: public CircularQueue{
    public:
        CircularDeque(){}
        ~CircularDeque(){}
        void addFront(int val){
            if(isFull()){
            error("ERROR: 덱이 포화상태입니다.\n");
            }
            else {
                data[front] = val;
                front = (front-1+MAX_QUEUE_SIZE) % MAX_QUEUE_SIZE;
            }
        }
        void addRear(int val){enqueue(val);}
        int deleteFront(){return dequeue();}
        int deleteRear(){
            if(isEmpty()){
                error("ERROR: 덱이 공백상태입니다.\n");
            }
            else {
                int result = data[rear];
                rear = (rear-1+MAX_QUEUE_SIZE) % MAX_QUEUE_SIZE;
                return result;
            }
        }
        int getFront(){return peek();}
        int getRear(){
            if(isEmpty()){
                error("ERROR: 덱이 공백상태입니다.\n");
            }
            else {
                return data[rear];
            }
        }
        void display(){
            cout << "Deque 안에는 : ";
            int maxi = (front < rear) ? rear : rear + MAX_QUEUE_SIZE;
            for (int i = front + 1; i <= maxi; i++){
                cout << data[i%MAX_QUEUE_SIZE] << " ";
            }
            cout << "\n";
        }
};

int main() {
    CircularDeque que;
    for (int i = 1; i < 10; i++){
        if (i % 2 == 0){que.addFront(i);}
        else{que.addRear(i);}
    }
    que.display();
    que.deleteFront();
    que.deleteFront();
    que.deleteRear();
    que.display();

    return 0;
}