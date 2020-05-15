#include <iostream>
using namespace std;

class ThreadedBinNode{
    protected:
        int data;
        ThreadedBinNode *left;
        ThreadedBinNode *right;

    public:
        bool bThread;
        ThreadedBinNode(int val = 0, ThreadedBinNode* l = nullptr, 
                ThreadedBinNode* r = nullptr, bool bTh=false)
                :data(val), left(l), right(r), bThread(bTh){}
        ~ThreadedBinNode(){}
        
        void setData(int val){
            data = val;
        }
        void setLeft(ThreadedBinNode *l){
            left = l;
        }
        void setRight(ThreadedBinNode *r){
            right = r;
        }
        int getData(){
            return data;
        }
        ThreadedBinNode* getLeft(){
            return left;
        }
        ThreadedBinNode* getRight(){
            return right;
        }
        bool isLeaf(){
            return (left == nullptr && right == nullptr);
        }
};

class ThreadedBinTree{
    private:
        ThreadedBinNode* root;
        // 트리의 순회연산 (2주차)

    public:
        ThreadedBinTree(): root(nullptr){}
        ~ThreadedBinTree(){}

        void setRoot(ThreadedBinNode* node){
            root = node;
        }
        ThreadedBinNode* getRoot(){
            return root;
        }
        bool isEmpty() {
            return root==nullptr;
        }
        void threadedInorder(){
            if(!isEmpty()){
                cout << "Threaded Binary Tree Inorder : ";
                ThreadedBinNode *q = root;

                while(q->getLeft()){
                    q = q->getLeft();
                }
                do{
                    cout << " [" << q->getData() << "]";
                    q = findSuccessor(q);
                }while(q);
                cout << "\n";   
            }
        }
        ThreadedBinNode *findSuccessor(ThreadedBinNode* p){
            ThreadedBinNode *q = p->getRight();
            if(q == nullptr || p->bThread){
                return q;
            }
        }
};

int main() {

    return 0;
}