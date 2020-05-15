#include <iostream>
#include <string>
#define MAX_DEGREE 80
using namespace std;

class Polynomial{
    private:
        int degree;
        float coef[MAX_DEGREE];
    public:
        Polynomial(){
            degree = 0;
        }
        void read(){
            cout << "다항식의 최고 차수를 입력하세요: ";
            cin >> degree;
            cout << "각 항의 계수를 입력하세요 : " << degree+1 << "개";
            for (int i = 0; i <= degree; i++){
                cin >> coef[i];
            }
        }
        void display(string str = "Poly = "){
            cout << str;
            for (int i = 0; i <= degree; i++){
                cout <<coef[i] << "x^" << degree - i <<"+";
            }
            cout << coef[degree] << endl;
        }

        void add(Polynomial a, Polynomial b){
            if(a.degree > b.degree){
                *this = a;
                for (int i = 0; i<=b.degree; i++){
                    coef[i+(degree-b.degree)] += b.coef[i];
                }
            }
            else{
                *this = b;
                for (int i = 0; i <= a.degree; i++){
                    coef[i+(degree-a.degree)] += a.coef[i];
                }
            }
        }

        bool isZero(){
            return degree == 0;
        }

        void negate(){
            for (int i = 0; i < degree; i++){
                coef[i] = -coef[i];
            }
        }
};

int main() {
    Polynomial a, b, c;
    a.read();
    b.read();
    c.add(a,b);
    a.display("A = ");
    b.display("B = ");
    c.display("A + B = ");

    return 0;
}