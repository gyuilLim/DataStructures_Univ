#include <iostream>
#include <random>
#include <ctime>
using namespace std;

#define MAX_QUEUE_SIZE 100

static mt19937 gen = mt19937((unsigned int)time(NULL));
static uniform_real_distribution<> dist(0, 1);



inline void error(const char* str){
    cerr << str << "\n";
    exit(1);
};

struct Customer{
    int id;
    int tArrival;
    int tService;
    Customer(int i = 0, int tArr = 0, int tServ = 0)
        : id(i), tArrival(tArr), tService(tServ){}
    ~Customer(){}
};

class CustomerQueue{
    private:
        int front;
        int rear;
        Customer data[MAX_QUEUE_SIZE];
    public:
        CustomerQueue(){front = rear = 0;}
        bool isEmpty(){return front == rear;}
        bool isFull(){return (rear+1) % MAX_QUEUE_SIZE == front;}
        void enqueue(Customer& val){
            if(isFull()){
                error("ERROR: 큐가 포화상태입니다.\n");
            }
            else {
                rear = (rear+1) % MAX_QUEUE_SIZE;
                data[rear] = val;
            }
        }
        Customer& dequeue(){
            if(isEmpty()){
                error("ERROR: 큐가 공백상태입니다.\n");
            }
            else {
                front = (front+1) % MAX_QUEUE_SIZE;
                return data[front];
            }
        }
};

class BankSimulator{
    private:
        int nSimulation;
        double probArrival;
        int tMaxService;
        int totalWaitTime;
        int nCustomers;
        int nServedCustomers;
        CustomerQueue que;
        bool isNewCustomer(){return dist(gen) < probArrival;}
        int randServiceTime(){return (int)tMaxService*dist(gen)+1;}
        void insertCustomer(int arrivalTime){
            Customer a(++nCustomers, arrivalTime, randServiceTime());
            cout << "고객 " << a.id << "방문 (서비스 시간 : " << a.tService << "분)\n";
            que.enqueue(a);
        }
    public:
        BankSimulator(): nCustomers(0), totalWaitTime(0), nServedCustomers(0){}
        void readSimilationParameters(){
            cout << "시뮬레이션 할 최대 시간 (예:10) : ";
            cin >> nSimulation;
            cout << "단위시간에 도착하는 고객 수 (예: 0.5) : ";
            cin >> probArrival;
            cout << "한 고객에 대한 최대 서비스 시간 (예: 5) : ";
            cin >> tMaxService;
        }
        void run(){
            int clock = 0;
            int serviceTime = -1;
            while (clock < nSimulation){
                clock++;
                cout << "현재시각 : " << clock << endl;
                if (isNewCustomer()){insertCustomer(clock);}
                if (serviceTime > 0){serviceTime--;}
                else{
                    if (que.isEmpty()){continue;}
                    Customer a = que.dequeue();
                    nServedCustomers++;
                    totalWaitTime += clock - a.tArrival;
                    cout << "고객 " << a.id << "서비스 시작";
                    cout << "(대기시간 : " << clock - a.tArrival << "분)";
                    serviceTime = a.tService-1;
                }

            }
        }
        void printStat(){
            cout << "-----------------------------------------\n";
            cout << "서비스 받은 고객 수 : " << nServedCustomers << "명\n";
            cout << "전체 대기 시간 : " << totalWaitTime << "분\n";
            cout << "서비스 받은 고객 평균 대기 시간 : " << (double)totalWaitTime/nServedCustomers << "분/명\n";
            cout << "현재 대기 고객 수 : " << nCustomers - nServedCustomers << "명\n";
        }
};

int main() {
    BankSimulator sim;
    sim.readSimilationParameters();
    sim.run();
    sim.printStat();

    return 0;
}