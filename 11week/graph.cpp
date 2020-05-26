#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include "CircularQueue.h"

#define MAX_VTXS 256
using namespace std;

class Node{
    protected:
        int id;
        Node* link;
    public:
        Node(int i, Node* l = nullptr) : id(i), link(l){}
        ~Node(){
            if(link != nullptr){
                delete link;
            }
        }
        int getId() {return id;}
        Node* getLink() {return link;}
        void setLink(Node *l) { link = l;}
};

class AdjListGraph{
    protected:
        int size;
        string vertices[MAX_VTXS];
        Node* adj[MAX_VTXS];

    public:
        AdjListGraph() : size(0){}
        ~AdjListGraph() {reset();}

        string getVertex(int i){return vertices[i];}
        bool isEmpty(){return size == 0;}
        bool isFull(){return size>=MAX_VTXS;}

        void reset(){
            for (int i = 0; i < size; i++){
                if (adj != nullptr){delete adj[i];}
            }
            size = 0;
        }

        void insertVertex(string name){
            if (!isFull()){
                vertices[size] = name;
                adj[size++] = nullptr;
            }
            else {
                cout << "최대 정점 수 이상을 입력 시도했습니다.";
            }
        }

        void insertEdge(int u, int v){
            //adj[u] = new Node(v, adj[u]);
            if (adj[u] == nullptr){
                adj[u] = new Node(v, adj[u]);
            }
            else {
                Node *p = adj[u];
                while (p->getLink() != nullptr){
                    p = p->getLink();
                }
                p->setLink(new Node(v, nullptr));
            }
        }

        void display(){
            cout << size << "\n";
            for (int i = 0; i < size; i++){
                cout << getVertex(i) << " ";
                for (Node *v = adj[i]; v != nullptr; v = v->getLink()){
                    cout << getVertex(v->getId()) << " ";
                }
                cout << "\n";
            }
        }

        void load(string filename){
            ifstream ifs(filename);
            string line;
            getline(ifs, line);
            stringstream ls(line);
            int n;
            ls >> n;
            for (int i = 0; i < n; i++){
                getline(ifs, line);
                string str;
                int val;
                stringstream ls(line);
                ls >> str;
                insertVertex(str);
                for (int j = 0; j < n; j++){
                    ls >> val;
                    if(val != 0){
                        insertEdge(i, j);
                    }
                }
            }
            ifs.close();
        }

        
};

class AdjMatGraph{
    protected:
        int size;
        string vertices[MAX_VTXS];
        int adj[MAX_VTXS][MAX_VTXS];

    public:
        AdjMatGraph() {reset();}
        ~AdjMatGraph() {}

        string getVertex(int i){return vertices[i];}
        int getEdge(int i, int j){return adj[i][j];}
        void setEdge(int i, int j, int val){adj[i][j] = val;}
        bool isEmpty(){return size == 0;}
        bool isFull(){return size>=MAX_VTXS;}

        void reset(){
            size = 0;
            for (int i = 0; i < MAX_VTXS; i++){
                for (int j = 0; j < MAX_VTXS; j++){
                    setEdge(i, j, 0);
                }
            }
        }

        void insertVertex(string name){
            if (!isFull()){
                vertices[size++] = name;
            }
            else {
                cout << "최대 정점 수 이상을 입력 시도했습니다.";
            }
        }

        void insertEdge(int u, int v){
            setEdge(u, v, 1);
            setEdge(v, u, 1);
        }

        void display(){
            cout << size << "\n";
            for (int i = 0; i < size; i++){
                cout << getVertex(i) << " ";
                for (int j = 0; j < size; j++){
                    cout << getEdge(i,j) << " ";
                }
                cout << "\n";
            }
        }

        void load(string filename){
            ifstream ifs(filename);
            string line;
            getline(ifs, line);
            stringstream ls(line);
            int n;
            ls >> n;
            for (int i = 0; i < n; i++){
                getline(ifs, line);
                string str;
                int val;
                stringstream ls(line);
                ls >> str;
                insertVertex(str);
                for (int j = 0; j < n; j++){
                    ls >> val;
                    if(val != 0){
                        insertEdge(i, j);
                    }
                }
            }
            ifs.close();
        }

        void store(string filename){
            ofstream ofs(filename);
            ofs << size << "\n";
            for (int i = 0; i < size; i++){
                ofs << getVertex(i) << " ";
                for (int j = 0; j < size; j++){
                    ofs << getEdge(i,j) << " ";
                }
                ofs << "\n";
            }
            ofs.close();
        }
};

class SrchAMGraph : public AdjMatGraph{
    protected:
        bool visited[MAX_VTXS];
    public:
        void resetVisited(){
            for (int i = 0; i < size; i++){
                visited[i] = false;
            }
        }
        bool isLinked(int u, int v){return getEdge(u, v) != 0;}

        void DFS(int v){
            visited[v] = true;
            cout << getVertex(v) << " ";
            for (int w = 0; w < size; w++){
                if (isLinked(v, w) && visited[w] == false){
                    DFS(w);
                }
            }
        }

        void BFS(int v){
            visited[v] = true;
            cout << getVertex(v) << " ";
            CircularQueue que;
            que.enqueue(v);
            while(!que.isEmpty()){
                int v = que.dequeue();
                for (int w = 0; w < size; w++){
                    if (isLinked(v,w) && visited[w] == false){
                        visited[w] = true;
                        cout << getVertex(w) << " ";
                        que.enqueue(w);
                    }
                }
            }
        }
};

class SrchALGraph : public AdjListGraph{
    protected:
        bool visited[MAX_VTXS];
    public:
        void resetVisited(){
            for (int i = 0; i < size; i++){
                visited[i] = false;
            }
        }
        bool isLinked(int u, int v){
            for (Node *p = adj[u]; p != nullptr; p = p->getLink()){
                if (p->getId() == v){return true;}
            }
            return false;
        }

        void DFS(int v){
            visited[v] = true;
            cout << getVertex(v) << " ";
            for (Node *p = adj[v]; p != nullptr; p = p->getLink()){
                if (visited[p->getId()] == false){
                    DFS(p->getId());
                }
            }
        }

        void BFS(int v){
            visited[v] = true;
            cout << getVertex(v) << " ";
            CircularQueue que;
            que.enqueue(v);
            while(!que.isEmpty()){
                int v = que.dequeue();
                for (Node *w = adj[v]; w != nullptr; w = w->getLink()){
                    int id = w->getId();
                    if (visited[id] == false){
                        visited[id] = true;
                        cout << getVertex(id) << " ";
                        que.enqueue(id);
                    }
                }
            }
        }
};

class ConnectedComponentGrpah : public SrchAMGraph{
    protected:
        int label[MAX_VTXS];

    public:
        void labelDFS(int v, int color){
            visited[v] = true;
            label[v] = color;
            cout << getVertex(v) << " ";
            for (int w = 0; w < size; w++){
                if(isLinked(v, w) && visited[w] == false){
                    labelDFS(w, color);
                }
            }
        }
        void findConnectedComponent(){
            int count = 0;
            for (int i = 0; i < size; i++){
                if (visited[i] == false){
                    labelDFS(i, ++count);
                }
            }
            cout << "\n연결 성분의 수는 : " << count << "\n";
            for (int i = 0; i < size; i++){
                cout << getVertex(i) << ":" << label[i] << " ";
            }
            cout << "\n";
        }

};

class TopoSortGraph : public AdjListGraph{
    public:
        TopoSortGraph(){}
        ~TopoSortGraph(){}

        void insertDirEdge(int u, int v){
            adj[u] = new Node(v, adj[u]);
        }

        void TopoSort(){
            CircularQueue q;
            int *inDeg = new int [size]; // 모든 정점의 in-degree를 담는 변수

            for (int i = 0; i < size; i++){
                inDeg[i] = 0;
            }

            for (int i = 0; i < size; i++){
                Node *node = adj[i];
                while (node != nullptr){
                    inDeg[node->getId()]++;
                    node = node->getLink();
                }
            }

            for (int i = 0; i < size; i++){
                if (inDeg[i] == 0){ q.enqueue(i);}
            }

            while (q.isEmpty() == false){
                int w = q.dequeue();
                cout << getVertex(w) << " ";
                Node *node = adj[w];
                while(node != nullptr){
                    int u = node->getId();
                    inDeg[u]--;
                    if(inDeg[u] == 0){
                        q.enqueue(u);
                    }
                    node = node->getLink();
                }
            }
            cout << "\n";
            delete[] inDeg;
        }

};

int main() {
    /*AdjMatGraph g;
    for (int i = 0; i < 4; i++){
        g. insertVertex(string(1, 'A'+ i));
    }
    g.insertEdge(0,1);
    g.insertEdge(0,3);
    g.insertEdge(1,2);
    g.insertEdge(1,3);
    g.insertEdge(2,3);
    g.display();
    g.store("graph.txt");
    g.reset();
    g.load("graph.txt");
    g.display();*/

    /*
    AdjListGraph g;

    g.load("./grpah.txt");
    g.display();
    */

   /*
    SrchAMGraph g;
    g.load("./graph2.txt");
    g.display();

    cout << "DFS ==> ";
    g.resetVisited();
    g.DFS(0);
    cout << "\n";

    cout << "BFS ==> ";
    g.resetVisited();
    g.BFS(0);
    cout << "\n";
    */

    /*
    SrchALGraph g;
    g.load("./graph2.txt");
    g.display();

    cout << "DFS ==> ";
    g.resetVisited();
    g.DFS(0);
    cout << "\n";

    cout << "BFS ==> ";
    g.resetVisited();
    g.BFS(0);
    cout << "\n";
    */
    
    /*
    ConnectedComponentGrpah g;
    for (int i = 0; i < 5; i++){
        g.insertVertex(string(1, 'A'+i));
    }
    g.insertEdge(0, 1);
    g.insertEdge(0, 2);
    g.insertEdge(3, 4);
    g.store("graph3.txt");
    cout << "연결성분 테스트";
    g.display();
    g.resetVisited();
    g.findConnectedComponent();
    */

   TopoSortGraph g;

   for (int i = 0; i < 6; i++){
       g.insertVertex(string(1, 'A'+ i));
   }

    g.insertDirEdge(0,2);
    g.insertDirEdge(0,3);

    g.insertDirEdge(1,3);
    g.insertDirEdge(1,4);
    
    g.insertDirEdge(2,3);
    g.insertDirEdge(2,5);
    
    g.insertDirEdge(3,5);

    g.insertDirEdge(4,5);

    cout << "위상정렬 수행 : ";
    g.TopoSort();

    return 0;
}