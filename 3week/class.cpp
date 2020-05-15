#include <iostream>
#include <string>
using namespace std;

class Car{
    protected:
        int speed;
        string name;
    public:
        int gear;
        Car(){ }
        ~Car() { }
        Car(int s, string n, int g): speed(s), gear(g){
            name  =n;
        }
        void changeGear(int g = 4){ 
            gear = g;
        }
        void speedUp(){
            speed+=5;
        }
        void display(){
            cout << name << ", gear : " << gear;
            cout << "단, 속도 : " << speed << endl;
        }
        void whereAmI(){
            cout << this << endl;
        }
};

class SportsCar : public Car{
    public:
        bool bTurbo;
        SportsCar() {}
        SportsCar(int s, string n, int g): Car(s, n, g){}
        void setTurbo(bool bTur = false){
            bTurbo = bTur; 
        }
        void speedUp(){
            if (bTurbo){
                speed += 20;
            }
            else {
                Car::speedUp();
            }
        }
};

int main(){
    Car yourCar(80, "your car", 4);
    SportsCar myCar(100, "my car", 4);

    yourCar.display();
    myCar.display();
    yourCar.speedUp();
    myCar.setTurbo();
    myCar.speedUp();
    yourCar.display();
    myCar.display();
    yourCar.changeGear(3);
    myCar.changeGear(3);
    yourCar.display();
    myCar.display();
    
    return 0;
}