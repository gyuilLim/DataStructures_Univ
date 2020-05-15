#include <iostream>
#include <vector>
#include <string>
#include <fstream>
using namespace std;

class SuperHero{
    public:
        void getFamily() { cout << "우리는 영웅입니다." <<endl;}
        virtual void getClass() { cout << "나는 영웅입니다." << endl;}
};

class Avangers : public SuperHero{
    public:
        void getClass() { cout << "나는 어벤져스 입니다." << endl;}
};

class Ironman : public Avangers{
    public:
        void getClass() { cout << "나는 아이언맨입니다." << endl;}
        void getDerived() { cout << "나는 영웅이고 어벤져스입니다." << endl;}
};

void whatIsMyClass(SuperHero *SuperHero){
    SuperHero -> getClass();
}

int main() {
    SuperHero *superhero = new SuperHero;
    Avangers *avangers = new Avangers;

    superhero -> getClass();
    avangers -> getClass();

    whatIsMyClass(superhero);
    whatIsMyClass(avangers);

    Avangers spiderman;
    Ironman suit_mark1;
    Avangers *pSpiderman = &spiderman;
    Avangers *pIronman = &suit_mark1;

    pSpiderman -> getFamily();
    pSpiderman -> getClass();

    pIronman -> getFamily();
    pIronman -> getClass();

    return 0;
}