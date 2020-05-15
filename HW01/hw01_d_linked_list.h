//20192927 임규일
#pragma once

#include <iostream>
using namespace std;

template <typename T>
struct node{
    public:
        T data; 
        node<T> *next, *prev;
};

template <typename T>
class d_linked_list{
    protected:
        node<T> *head, *tail;
        int length = 0;
    public:
        d_linked_list(){
            head = nullptr;
            tail = nullptr;
        }
        ~d_linked_list(){}

        //삽입
        void push_front(T n){
            node<T> *ptr = new node<T>;
            ptr->data = n;
            if (head==nullptr){
                head = tail = ptr;
                tail->next = nullptr;
                head->prev = nullptr;
            }
            else if (length == 1){
                ptr->next = head;
                head = ptr;
                tail->prev = ptr;
            }
            else {
                head->prev = ptr;
                ptr->next = head;
                head = ptr;
                head->prev = nullptr;
            }
            length++;
        }
        void push_back(T n){
            node<T> *ptr = new node<T>;
            ptr->data = n;
            if (head == nullptr){
                head = tail = ptr;
                head->prev = nullptr;
                tail->next = nullptr;
            }
            else if (length == 1){
                ptr->prev = tail;
                tail = ptr;
                head->next = ptr;
            }
            else {
                ptr->prev = tail;
                tail->next = ptr;
                tail = ptr;
                tail->next = nullptr;
            }
            length++;
        }
        void insert_node_at(int idx, T n){
            if(length < idx || 0 > idx){
                std::cout << "해당 인덱스는 존재하지 않습니다\n";
            }
            else if(idx == 0){  // idx == 0은 push_front(n)과 같다.
                push_front(n);
            }
            else if(idx == length){  // idx == size은 push_back(n)과 같다.
                push_back(n);
            }
            else {
                node<T> *ptr = head;
                node<T> *tmp = ptr;
                node<T> *new_node = new node<T>;
                new_node->data = n;
                for (int i = 0; i < idx; i++){
                    tmp = ptr;
                    ptr = ptr->next;
                }
                tmp->next = new_node;
                new_node->next = ptr;
                ptr->prev = new_node;
                new_node->prev = tmp;
                length++;
            }
        }

        //삭제
        T pop_front(){
            if(head == nullptr){
                std::cout << "linked list가 비어있습니다\n";
                exit(1);
            }
            node<T> *ptr = head;
            int value = head->data;
            head = ptr->next;
            if(head == nullptr){tail = nullptr;}
            else{head->prev = nullptr;}
            delete ptr;
            length--;
            return value;
        }
        T pop_back(){
            if(length == 0){  // 리스트가 비었을때 pop_back()을 시도한 경우
                std::cout << "linked list가 비어있습니다\n";
                exit(1);
            }
            node<T> *ptr = tail;
            int value = tail->data;
            tail = ptr->prev;
            if (tail == nullptr){
                tail = nullptr;
                head = nullptr;
            }
            else {tail->next = nullptr;}
            delete ptr;
            length--;
            return value;
        }
        T pop_node_at(int idx){
            int value = -1;
            if(length <= idx || 0 > idx){  // length < idx 에서 length <= idx 로 수정
                std::cout << "해당 인덱스는 존재하지 않습니다\n";
            }
            else if(length == 0){  // 리스트가 비었을때 pop_node_at()을 시도한 경우
                std::cout << "linked list가 비어있습니다\n";
                exit(1);
            }
            else if(idx == 0){ // ixd == 0 은 pop_front()와 같다.
                value = pop_front();
            }
            else if(idx == length - 1){  // ixd == size-1 은 pop_back()와 같다.
                value = pop_back();
            }
            else {
                node<T> *ptr = head;
                node<T> *tmp = head;
                for (int i = 0; i < idx; i++){
                    tmp = ptr;
                    ptr = ptr->next;
                }
                value = ptr->data;
                tmp->next = ptr->next;
                ptr->next->prev = tmp;
                if(ptr == tail){
                    tail = tmp;
                }
                length--;
                delete ptr;
            }
            return value;
        }
        void delete_list(){
            node<T> *ptr = head;
            while(ptr != nullptr){
                head = ptr->next;
                delete ptr;
                ptr= head;
            }
            length = 0;
            std::cout << "리스트가 삭제되었습니다 \n";
        }

        //조회
        T front(){
            if (head == nullptr){
                cout << "리스트가 비어있습니다." << endl;
                return -1;
            }
            return head->data;
        }
        T back(){
            if (tail == nullptr){
                cout << "리스트가 비어있습니다." << endl;
                return -1;
            }
            return tail->data;
        }
        int size(){
            return length;
        }
};


template <typename T>
class dll_deque : d_linked_list<T>{
    public:
        dll_deque(){}
        ~dll_deque(){}

        void addFront(T data){
            d_linked_list<T>::push_front(data);
        }
        void addRear(T data){
            d_linked_list<T>::push_back(data);
        }
        T getFront(){
            return d_linked_list<T>::front();
        }
        T getRear(){
            return d_linked_list<T>::back();
        }
        T deleteFront(){
            return d_linked_list<T>::pop_front();
        }
        T deleteRear(){
            return d_linked_list<T>::pop_back();
        }
};