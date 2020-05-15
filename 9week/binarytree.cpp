#include <iostream>
using namespace std;

#define MAX_QUEUE_SIZE 100

inline void error(const char * str){
    cerr << str << "\n";
    exit(1);
}

class BinaryNode{
    protected:
        int data;
        BinaryNode *left;
        BinaryNode *right;

    public:
        BinaryNode(int val = 0, BinaryNode* l = nullptr, BinaryNode* r = nullptr)
        :data(val), left(l), right(r){}
        ~BinaryNode(){}
        
        void setData(int val){
            data = val;
        }
        void setLeft(BinaryNode *l){
            left = l;
        }
        void setRight(BinaryNode *r){
            right = r;
        }
        int getData(){
            return data;
        }
        BinaryNode* getLeft(){
            return left;
        }
        BinaryNode* getRight(){
            return right;
        }
        bool isLeaf(){
            return (left == nullptr && right == nullptr);
        }
};
      
class CircularQueue{
    protected:
        int front;
        int rear;
        BinaryNode* data[MAX_QUEUE_SIZE];
    public:
    CircularQueue(){front = rear = 0;}
    ~CircularQueue(){}
    bool isEmpty(){return front == rear;}
    bool isFull(){return (rear+1) % MAX_QUEUE_SIZE == front;}
    void enqueue(BinaryNode* val){
        if(isFull()){
            error("ERROR: 큐가 포화상태입니다.\n");
        }
        else {
            rear = (rear+1) % MAX_QUEUE_SIZE;
            data[rear] = val;
        }
    }
    BinaryNode* dequeue(){
        if(isEmpty()){
            error("ERROR: 큐가 공백상태입니다.\n");
        }
        else {
            front = (front+1) % MAX_QUEUE_SIZE;
            return data[front];
        }
    }
};


class BinaryTree{
    private:
        BinaryNode* root;
        // 트리의 순회연산 (2주차)

    public:
        BinaryTree(): root(nullptr){}
        ~BinaryTree(){}

        void setRoot(BinaryNode* node){
            root = node;
        }
        BinaryNode* getRoot(){
            return root;
        }
        bool isEmpty() {
            return root==nullptr;
        }

        void inorder(BinaryNode *node){
            if(node != nullptr){
                if(node->getLeft() != nullptr){
                    inorder(node->getLeft());
                }
                std::cout << " [" << node->getData() << "] ";
                if(node->getRight()!= nullptr){
                    inorder(node->getRight());
                }
            }
        }       
        void inorder(){
            std::cout << "inorder: ";
            inorder(root);
        }        
        void preorder(BinaryNode *node){
            if(node != nullptr){
                std::cout << " [" << node->getData() << "] ";
                if(node->getLeft() != nullptr){
                    preorder(node->getLeft());
                }
                if(node->getRight()!= nullptr){
                    preorder(node->getRight());
                }                
            }
        }
        void postorder(BinaryNode *node) {
            if(node != nullptr){
                if(node->getLeft() != nullptr){
                    postorder(node->getLeft());
                }
                if(node->getRight()!= nullptr){
                    postorder(node->getRight());
                }
                std::cout << " [" << node->getData() << "] ";
            }            
        }

        void preorder(){
            std::cout << "preorder: ";
            preorder(root);
        }
        void postorder(){
            std::cout << "postorder: ";
            postorder(root);
        }
        void levelorder(){
            std::cout << "levelorder: ";
            if(!isEmpty()){
                CircularQueue q;
                q.enqueue(root);
                while (!q.isEmpty()){
                    BinaryNode* n = q.dequeue();
                    if(n != nullptr){
                        std::cout << " [" << n->getData() << "] ";
                        q.enqueue(n->getLeft ());
                        q.enqueue(n->getRight());
                    }
                }
            }
            printf("\n");
        }

        int getCount(){
            return isEmpty() ? 0 : getCount(root);
        }
        int getCount(BinaryNode *node){
            if(node == nullptr){
                return 0;
            }
            return 1 + getCount(node->getLeft()) + getCount(node->getRight());
        }
        int	getLeafCount(){
            return isEmpty() ? 0 : getLeafCount(root);
        }
        int getLeafCount(BinaryNode *node) {
            if(node == nullptr){
                return 0;
            }
            if(node->isLeaf()){
                return 1;
            }
            else return getLeafCount(node->getLeft()) + getLeafCount(node->getRight());
        }
        int	getHeight(){
            return isEmpty() ? 0 : getHeight(root);
        }
        int getHeight(BinaryNode *node) {
            if(node == nullptr){
                return 0;
            }
            int hLeft  = getHeight(node->getLeft());
            int hRight = getHeight(node->getRight());
            return (hLeft>hRight) ? hLeft+1 : hRight+1;
        }
        
        int calcSize(){
            return calcSize(root);
        }
        int calcSize(BinaryNode *node){
            if(node == nullptr){
                return 0;
            }
            return node->getData() + calcSize(node->getLeft()) + calcSize(node->getRight());
        }

        int evaluate(){ // 수식 계산 함수
            return evaluate(root);
        }
        int evaluate(BinaryNode *node){
            if(node == nullptr){
                return 0;
            }
            if(node->isLeaf()) return node->getData();
            else {
                int op1 = evaluate(node->getLeft());
                int op2 = evaluate(node->getRight());
                switch(node->getData()){
                    case '+': return op1+op2;
                    case '-': return op1-op2;
                    case '*': return op1*op2;
                    case '/': return op1/op2;
                }
                return 0;
            }
        }



};

int main() {
    BinaryTree tree;

    BinaryNode *d = new BinaryNode(4, nullptr, nullptr);
    BinaryNode *e = new BinaryNode(5, nullptr, nullptr);
    BinaryNode *b = new BinaryNode(2, d, e);
    BinaryNode *f = new BinaryNode(6, nullptr, nullptr);
    BinaryNode *c = new BinaryNode(3, f, nullptr);
    BinaryNode *a = new BinaryNode(1, b, c);
    tree.setRoot(a);
    tree.preorder();
    cout << endl;
    tree.inorder();
    cout << endl;
    tree.postorder();
    cout << endl;
    tree.levelorder();
    cout << endl;

    cout << "노드의 수 : " << tree.getCount() << endl;
    cout << "잎 노드의 수 : " << tree.getLeafCount() << endl;
    cout << "트리의 높이 : " << tree.getHeight() << endl;
    
    BinaryTree tree2;
    BinaryNode *n1 = new BinaryNode(3, nullptr, nullptr);
    BinaryNode *n2 = new BinaryNode(2, nullptr, nullptr);
    BinaryNode *n3 = new BinaryNode('*', n1, n2);
    BinaryNode *n4 = new BinaryNode(5, nullptr, nullptr);
    BinaryNode *n5 = new BinaryNode(6, nullptr, nullptr);
    BinaryNode *n6 = new BinaryNode('-', n4, n5);
    BinaryNode *n7 = new BinaryNode('+', n3, n6);
    tree2.setRoot(n7);
    cout << "계산 결과 : " << tree2.evaluate() << endl;

    return 0;
}