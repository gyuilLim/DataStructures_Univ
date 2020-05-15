#pragma once
#include <iostream>
#include <vector>
#include <chrono>
using namespace std;

struct node{
    int data;
    node *next;
};

class s_linked_list{
    protected:
        node *head, *tail;
        int size = 0;
    public:
        s_linked_list(){
            head = nullptr;
            tail = nullptr;
        }
        ~s_linked_list(){
            delete_list();
        }
        
        //삽입
        void push_front(int n);
        void push_back(int n);
        void insert_node_at(int idx, int n);

        //삭제
        int pop_front();
        int pop_back();
        int pop_node_at(int idx);
        void remove_node(int n);
        void delete_list();

        //대입
        void replace_value_at(int idx, int n);

        //기타
        int Size();
        void display_contents();
        int search_value(int n);


};

//삽입
void s_linked_list::push_front(int n){
    node *ptr = new node;
    ptr -> next = head;
    ptr -> data = n;
    head = ptr;
    size++;
}
void s_linked_list::push_back(int n){
    node *tmp = new node;
    size ++;
    tmp -> data = n;
    tmp -> next = nullptr;
    if (head == nullptr){
        head = tmp;
        tail = tmp;
    }
    else {
        tail -> next = tmp;
        tail = tail -> next;
    }
}
void s_linked_list::insert_node_at(int idx, int n){
    if (size < idx || 0 > idx){
        cout << "해당 인덱스가 없습니다." << endl;
    }
    else{
        node *ptr = head;
        node *tmp = ptr;
        node *new_node = new node;
        new_node -> data = n;
        new_node -> next = nullptr;
        for (int i = 0; i < idx; i++){
            tmp = ptr;
            ptr =
             ptr->next;
        }
        tmp -> next = new_node;
        new_node -> next = ptr;
        size++;
    }
}

//삭제
int s_linked_list::pop_front(){
    node *ptr = head;
    int value = head -> data;
    head = ptr -> next;
    delete ptr;
    size--;
    return value;
}
int s_linked_list::pop_back(){
    node *ptr = head;
    node *tmp = ptr;
    while (ptr -> next != nullptr){
        tmp = ptr;
        ptr = ptr -> next;
    }
    int value = ptr -> data;
    tail = tmp;
    tail -> next = nullptr;
    delete ptr;
    size --;
    return value;
}
int s_linked_list::pop_node_at(int idx){
    int value = -1;
    if (size < idx || 0 > idx){
        cout << "해당 인덱스는 존재하지 않습니다." << endl;
    }
    else {
        node *ptr = head;
        node *tmp = ptr;
        for (int i = 0; i < idx; i++){
            tmp = ptr;
            ptr = ptr -> next;
        }
        int value = ptr -> data;
        tmp -> next = ptr -> next;
        if (ptr == tail){
            tail = tmp;
        }
        size --;
        delete ptr;
    }
    return value;
}
void s_linked_list::remove_node(int n){
    node *ptr = head;
    node *tmp = ptr;
    while (ptr != nullptr){
        if (ptr -> data == n){
            break;
        }
        else {
            tmp = ptr;
            ptr = ptr->next;
        }
    }
    if (ptr == nullptr){
        cout << n << "값의 노드는 존재하지 않습니다." << endl;
    }
    else {
        size --;
        tmp -> next = ptr->next;
        if (ptr == tail){
            tail = tmp;
        }
        delete ptr;
    }
}
void s_linked_list::delete_list(){
    node *ptr = head;
    while (ptr != nullptr){
        head = ptr -> next;
        delete ptr;
        ptr = head;
    }
    size = 0;
    cout << "리스트가 삭제되었습니다." << endl;
}

//대입
void s_linked_list::replace_value_at(int idx, int n){
    node *ptr = head;
    if (size < idx || 0 > idx){
        cout << "해당 인덱스는 존재하지 않습니다." << endl;
    }
    else {
        for (int i = 0; i < idx; i++){
            ptr = ptr -> next;
        }
        ptr -> data = n;
    }
}

//기타
int s_linked_list::Size(){
    return size;
}
void s_linked_list::display_contents(){
    node *ptr = head;
    while (ptr != nullptr){
        cout << ptr -> data << "->";
        ptr = ptr -> next;
    }
    cout << "nullptr" << endl;
}
int s_linked_list::search_value(int n){
    node *ptr = head;
    int idx = 0;
    bool isFind = false;
    while (ptr != nullptr){
        if (ptr -> data == n){
            cout << n << " 은 " << idx << " 에 있습니다." << endl;
            isFind = true;
            break;
        }
        ptr = ptr -> next;
        idx++;
    }
    if (isFind == false){
        cout << n << " 은 리스트 안에 없습니다." << endl;
        return -1;
    }
    else{
        return idx;
    }
}