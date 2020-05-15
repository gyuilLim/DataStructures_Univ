#include <iostream>
using namespace std;

inline void error(const char* str){
    cerr << str << "\n";
    exit(1);
};



class node{
    private:
        int data;
        node *next;
    public:
        node (int val = 0){
            data = val;
            next = nullptr;
        }

        node* getLink(){return next;}

        int getData(){ return data; }

        void setLink(node * target){ next = target;}

        void insertNext(node* newnode){
            if(newnode != nullptr){
                newnode->next = next; 
                next = newnode;
            }
        }

        node* removeNext(){
            node *removed = next;
            if(removed != nullptr){
                next = removed -> next;
            }
            return removed;
        }
};

class hn_s_linked_list{
    protected:
        node origin;
    public:
        hn_s_linked_list(): origin(0){}
        ~hn_s_linked_list(){clear();}

        void clear();
        node* getHead();
        bool isEmpty();

        node* getEntry(int pos);
        void insert(int pos, node *n);
        node* remove(int pos);
        node* find(int Value);
        void replace(int pos, node *n);
        size_t size();
        void display();
};

void hn_s_linked_list::clear(){
    while(!isEmpty()){
        delete remove(0);
    }
}
node* hn_s_linked_list::getHead(){
    return origin.getLink();
}
bool hn_s_linked_list::isEmpty(){
    return getHead() == nullptr;
}

node* hn_s_linked_list::getEntry(int pos){
    node* n = &origin;
    for (int i = -1; i < pos; i++, n = n -> getLink()){
        if (n == nullptr){ break; }
    }
    return n;
}
void hn_s_linked_list::insert(int pos, node *n){
    node* prev = getEntry(pos-1);
    if(prev != nullptr){
        prev->insertNext(n);
    }
} 
node* hn_s_linked_list::remove(int pos){
    node* prev = getEntry(pos - 1);
    if (prev != nullptr){
        prev -> removeNext();
    }
}
node* hn_s_linked_list::find(int value){
    for (node* p = getHead(); p != nullptr; p = p -> getLink()){
        if(p->getData() == value){return p;}
    }
    return nullptr;
}
void hn_s_linked_list::replace(int pos, node *n){
    node* prev = getEntry(pos-1);
    if(prev != nullptr){
        delete prev->removeNext();
        prev->insertNext(n);
    }
}
size_t hn_s_linked_list::size(){
    int count = 0;
    for (node* p = getHead(); p != nullptr; p = p -> getLink()){
        count ++;
    }
    return count;
}
void hn_s_linked_list::display(){
    int count = 0;
    cout << "전체 항목의 수 : " << size() << ", ";
    for (node* p = getHead(); p != nullptr; p = p -> getLink()){
        cout << p->getData() << " ";
    }
    cout << endl;
}

int main() {
    hn_s_linked_list list;

    list.insert(0, new node(10));
    list.insert(0, new node(20));
    list.insert(1, new node(30));
    list.insert(list.size(), new node(40));
    list.insert(2,new node(50));
    list.display();


    list.remove(2);
    list.remove(list.size() - 1);
    list.remove(0);
    list.replace(1, new node(90));
    list.display();

    list.clear();
    list.display();

    return 0;
}