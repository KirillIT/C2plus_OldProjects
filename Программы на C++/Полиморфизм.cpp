#include <iostream>

#include <Windows.h>

using namespace std;

class Aircraft { //базовый класс

private:  

    int maxSpeed = 0;

public:

    virtual void fly() = 0; //чисто виртуальный метод

    void setMaxSpeed(int maxSpeed) { //обычные методы

        this->maxSpeed = maxSpeed;

    };

    int getMaxSpeed() {

        return this->maxSpeed;

    };
};

class Airplane : public Aircraft {

    void fly() override { //переопределённый метод для класса 'Самолёт'

        getMaxSpeed(); //можно использовать и эти данные для реализации

        cout << "тут одна реализация" << endl;

    }

};

class Helicopter : public Aircraft { //переопределённый метод для класса 'Вертолёт'

    void fly() override {

        getMaxSpeed(); //можно использовать и эти данные для реализации

        cout << "тут другая" << endl;

    }
};

//Если возникает вопрос, зачем нам нужен общий базовый класс, то вот пример:
//нам нужна функция, которая заранее не знает, что принимать её в качестве параметра (самолёт или вертолёт)
//но две функции писать не выгодно. И тогда делаем так:

void launchAFlyingObject(Aircraft *obj) {

    obj->fly();

}//мы вызываем у нашего базового класса чисто виртуальную функцию, а реализация этой функции будет зависить от того, какой именно объект туда попал (вертолёт или самолёт)

int main() {

    SetConsoleCP(1251); //для русского языка

    SetConsoleOutputCP(1251);

    Airplane a;

    Helicopter b;

    launchAFlyingObject(&a); //вызываем нашу функцию

    launchAFlyingObject(&b); //вызываем нашу функцию

    system("pause");

}