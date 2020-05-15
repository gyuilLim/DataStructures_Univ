#include <iostream>
#include <vector>
#include <string>
#include <fstream>
using namespace std;

class Animal{
    private:
        int height;
        int weight;
        string name;

        static int numberOfAnimals;
    
    public:
        int getHeight(){ return height; }
        int getWeight(){ return weight; }
        string getName(){ return name; }

        void setHeight(int newval){ height = newval; }
        void setWeight(int newval){ weight = newval; }
        void setName(string newval){ name = newval; }

        void setAll(int, int, string);

        Animal(int, int, string);
        ~Animal();

        Animal();
        
        static int getNumberOfAnimals() { return numberOfAnimals; }
        void toString();
};

int Animal::numberOfAnimals = 0;

Animal::Animal(int height, int weight, string name){
    this -> height = height;
    this -> weight = weight;
    this -> name = name;
    Animal::numberOfAnimals++;
}

Animal::~Animal() {
    cout << this->name << " goodbye" << endl;
}

Animal::Animal(){
    Animal::numberOfAnimals++;
}

void Animal::toString(){
    cout << "name : " << this->name << "height : " << this->height << "weight : " << this->weight << endl;

}

class Dog: public Animal{
    private:
        string sound = "멍멍";
    public:
        void doBark() { cout << sound << endl;};
        Dog(int, int, string, string);
        Dog() : Animal(){};

        void toString();
};

Dog::Dog(int height, int weight, string name, string bark) : Animal(height, weight, name){
    this -> sound = bark;
}

void Dog::toString() {
    cout << "name : " << this->getName() << "height : " << this->getHeight << "weight : " 
    << this->getWeight << "sound : " << this->sound << endl;
}

int main() {
    Animal spider;
    spider.setHeight(60);
    spider.setWeight(20);
    spider.setName("Peter Parker");
    cout << "현재 동물의 수는? : " << Animal::getNumberOfAnimals() << endl;
    
    cout << "name : " << spider.getName() << "height : " << spider.getHeight() << "weight : " << spider.getWeight() << endl;

    Animal ant(5, 1, "Scott Lang");
    cout << "현재 동물의 수는? : " << Animal::getNumberOfAnimals() << endl;
    cout << "name : " << ant.getName() << "height : " << ant.getHeight() << "weight : " << ant.getWeight() << endl;

    Dog dog(40, 12, "mike", "walwal");
    cout << "현재 동물의 수는? : " << Animal::getNumberOfAnimals() << endl;
    dog.doBark();
    spider.toString();
    dog.toString();
    dog.Animal::toString();

    return 0;
}