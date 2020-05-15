#include <iostream>
#include <fstream>
#include <string>
using namespace std;

inline void error(const char* str){
    cerr << str << "\n";
    exit(1);
};

class line{
    protected:
        string data;

    public:
        line(string line = ""){ data = line; }

        void read(istream *is = &cin){
            getline(*is, data);

        }

        void display(ostream *os = &cout){
            *os << data  << endl;
        }

        bool hasData(string str){ return str == data; }
};

class node:public line{
    private:
        node *next;
    public:
        node (string str = ""): line(str){
            next = nullptr;
        }

        node* getLink(){return next;}

        string getData(){ return data; }

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
class l_hn_s_linked_list{
    protected:
        node origin;
    public:
        l_hn_s_linked_list(): origin(0){}
        ~l_hn_s_linked_list(){clear();}

        void clear();
        node* getHead();
        bool isEmpty();

        node* getEntry(int pos);
        void insert(int pos, node *n);
        node* remove(int pos);
        node* find(string value);
        void replace(int pos, node *n);
        size_t size();
        void display();
};

void l_hn_s_linked_list::clear(){
    while(!isEmpty()){
        delete remove(0);
    }
}
node* l_hn_s_linked_list::getHead(){
    return origin.getLink();
}
bool l_hn_s_linked_list::isEmpty(){
    return getHead() == nullptr;
}

node* l_hn_s_linked_list::getEntry(int pos){
    node* n = &origin;
    for (int i = -1; i < pos; i++, n = n -> getLink()){
        if (n == nullptr){ break; }
    }
    return n;
}
void l_hn_s_linked_list::insert(int pos, node *n){
    node* prev = getEntry(pos-1);
    if(prev != nullptr){
        prev->insertNext(n);
    }
} 
node* l_hn_s_linked_list::remove(int pos){
    node* prev = getEntry(pos - 1);
    if (prev != nullptr){
        prev -> removeNext();
    }
}
node* l_hn_s_linked_list::find(string value){
    for (node* p = getHead(); p != nullptr; p = p -> getLink()){
        if(p->getData() == value){return p;}
    }
    return nullptr;
}
void l_hn_s_linked_list::replace(int pos, node *n){
    node* prev = getEntry(pos-1);
    if(prev != nullptr){
        delete prev->removeNext();
        prev->insertNext(n);
    }
}
size_t l_hn_s_linked_list::size(){
    int count = 0;
    for (node* p = getHead(); p != nullptr; p = p -> getLink()){
        count ++;
    }
    return count;
}
void l_hn_s_linked_list::display(){
    int count = 0;
    cout << "전체 항목의 수 : " << size() << ", ";
    for (node* p = getHead(); p != nullptr; p = p -> getLink()){
        cout << p->getData() << " ";
    }
    cout << endl;
}

class LineEditor : public l_hn_s_linked_list{
    public:
        void Display(ostream * os);
        void InsertLine();
        void DeleteLine();
        void ReplaceLine();
        void LaodFile(string fname);
        void SaveFile(string fname);
};


void LineEditor::Display(ostream * os = &cout){
    int i = 0;
    cout << "전체 항목의 수 : " << size() << ", ";
    for (node* p = getHead(); p != nullptr; p = p -> getLink(), i++){
        cerr << i << " ";
        p->display(os);
    }
    cout << endl;
}
void LineEditor::InsertLine(){
    int position;
    string line;
    cout << "  입력행 번호: " ;
    cin >> position;
    cin.sync();
    cin.clear();
    cout << "  입력할 내용 : ";
    getline(cin, line);
    insert(position, new node(line));
}
void LineEditor::DeleteLine(){
    int position;
    cout << "  삭제행 번호 : ";
    cin >> position;
    remove(position);
}
void LineEditor::ReplaceLine(){
    int position;
    string line;
    cout << "  변경행 번호: " ;
    cin >> position;
    cin.sync();
    cin.clear();
    cout << "  변경할 내용 : ";
    getline(cin, line);
    replace(position, new node(line));
}
void LineEditor::LaodFile(string fname){
    ifstream ifs(fname);
    string line;
    while(getline(ifs, line)){
        insert(size(), new node(line));
    }
    ifs.close();
}
void LineEditor::SaveFile(string fname){
    ofstream ofs(fname);
    if(ofs.good()){
        Display(&ofs);
        ofs.close();
    }
}

int main() {
    LineEditor editor;
    char command;
    do {
        cout << "[메뉴선택] i-입력, d-삭제, r-변경, p-출력, l-파일읽기, s-저장, q-종료 : ";
        command = getchar();
        cin.sync();
        switch(command){
            case 'd':
                editor.DeleteLine();
            case 'i':
                editor.InsertLine();
            case 'r':
                editor.ReplaceLine();
            case 'l':
                editor.LaodFile("test.txt");
            case 's':
                editor.SaveFile("test.txt");
            case 'p':
                editor.Display();
        }

    }while (command != 'q');

    return 0;
}