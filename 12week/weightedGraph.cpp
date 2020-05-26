#include "AdjMatGraph.h"

#define INF 9999

class node{
    private:
        int weight;
        int v1;
        int v2;
        node* next;
    public:
        node(int val = INF, int vx1 = -1, int vx2 = -1){
            weight = val;
            v1 = vx1;
            v2 = vx2;
            next = nullptr;
        }
        ~node(){}
        node* getLink() {return next;}
        int getWeight() {return weight;}
        int getSource() {return v1;}
        int getTarget() {return v2;}

        void setLink(node* target) {next = target;}
        void insertNext(node *newnode){
            if (newnode != nullptr){
                newnode->next = next;
                next = newnode;
            }
        }
        node* removeNext() {
            node* removed = next;
            if (removed != nullptr){
                next = removed->next;
            }
            return removed;
        }
};

class o_linked_list{
    protected:
        node origin;

    public:
        o_linked_list(){}
        ~o_linked_list(){clear();}
        void clear(){
            while (!isEmpty()){
                origin.removeNext();
            }
        }

        bool isEmpty(){
            return getHead() == nullptr;
        }

        node* getHead(){
            return origin.getLink();
        }

        node* removeHead(){
            origin.removeNext();
        }

        void orderedInsert(node *n){
            int w = n->getWeight();
            node *prev = &origin;
            node *now = getHead();
            while(now != nullptr){
                int now_w = now->getWeight();
                if (now_w >= w){
                    prev->insertNext(n);
                    return;
                }
                prev = now;
                now = now->getLink();
            }
            prev->insertNext(n);
            return;
        }
        size_t size(){
            int count = 0;
            for (node *p = getHead(); p != nullptr; p = p->getLink()){
                count++;
            }
            return count; 
        }

        void display(){
            cout << "항목 수 : " << size() << "\n";
            for (node *p = getHead(); p != nullptr; p = p->getLink()){
                cout << p->getWeight() << " " << p->getSource() << " ";
                cout << p->getTarget() << "\n";
            }
        }
};

class VertexSets{
    protected:
        int parent[MAX_VTXS]; 
        int size;
    public:
        VertexSets(int nSets){
            size = nSets;
            for (int i = 0; i < nSets; i++){
                parent[i] = -1;
            }
        }

        bool isRoot(int i){
            return parent[i] < 0;
        }

        int findSet(int vertex){
            int id = vertex;
            while (!isRoot(id)){
                id = parent[id];
            }
            return id; 
        }

        void unionSets(int s1, int s2){
            parent[s1] = s2;
            size--;
        }
};

class WGraph : public AdjMatGraph{
    public:
        WGraph(){}
        ~WGraph(){}

        bool hasEdge(int i, int j){ return (getEdge(i,j) > INF);}

        void insertEdge(int u, int v, int weight){
            if (weight >= INF){ weight = INF;}
            setEdge(u, v, weight);
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
                    insertEdge(i, j, val);
                }
            }
            ifs.close();
        }
};

class WGraphMST : public WGraph{
    public:
    //kruskal MST
    void Kruskal(){
        o_linked_list o_edgelist;
        for (int i = 0; i < size-1; i++){
            for (int j = i+1; j < size; j++){
                if(hasEdge(i, j)){
                    o_edgelist.orderedInsert(new node(getEdge(i,j), i, j));
                
                }
            }
        }
        VertexSets set(size);
        int edgeAccepted = 0;
        while(edgeAccepted < size-1){
            node* e = o_edgelist.getHead();
            int uset = set.findSet(e->getSource());
            int vset = set.findSet(e->getTarget());
            if (uset != vset){
                cout << "An edge added to MST : " << getVertex(e->getSource());
                cout << " " << getVertex(e->getTarget()) << " " << e->getWeight() << "\n";
                set.unionSets(uset, vset);
                edgeAccepted++;
            }
            o_edgelist.removeHead();
        }
    }

    void Prim(){
        bool selected[MAX_VTXS];
        int dist[MAX_VTXS];
        int source_vertex[MAX_VTXS];

        for (int i = 0; i < size; i++){
            dist[i] = INF;
            selected[i] = false;
            source_vertex[i] = 0;
        }
        dist[0] = 0;
        for (int i = 0; i < size; i++){
            int u = getMinVertex(selected, dist);
            selected[u] = true;
            if (dist[u] >= INF){
                return ;
            }
            if (u != source_vertex[u]){
                cout << "An edge added to MST : " << getVertex(u) << " ";
                cout << getVertex(source_vertex[u]) << " ";
                cout << getEdge(u, source_vertex[u]) << "\n";
            }
            for (int v = 0; v < size; v++){
                if (getEdge(u,v) != INF){
                    if(!selected[v], getEdge(u,v) < dist[v]){
                        dist[v] = getEdge(u,v);
                        source_vertex[v] = u;
                    }
                }
            }
        }

    }

    int getMinVertex(bool* selected, int *dist){
        int minv = 0;
        int mindist = INF;
        for (int v = 0; v < size; v++){
            if (!selected[v] && dist[v] < mindist){
                mindist = dist[v];
                minv = v;
            }
        }
        return minv;
    }
};


int main() {
    WGraphMST g;
    g.load("graph.txt");
    g.display();

    g.Prim();

    return 0;
}