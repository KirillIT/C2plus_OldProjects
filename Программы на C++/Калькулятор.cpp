#include <iostream>

#include <Windows.h>

using namespace std;

int main() {

    SetConsoleCP(1251);

    SetConsoleOutputCP(1251);

    char sign;

    double firstN, secondN;

    cout << "Введите первое число: ";

    cin >> firstN;

    cout << "Введите второе число: ";

    cin >> secondN;

    cout << "Введите знак ('+', '-', '*', '/', '%'): ";

    cin >> sign;

    cout << "Результат: ";

    switch (sign) {

    case '+':

        cout << firstN + secondN << endl;

        break;

    case '-':

        cout << firstN - secondN << endl;

        break;

    case '*':

        cout << firstN * secondN << endl;

        break;

    case '/':

        secondN == 0 ? cout << "делить на ноль нельзя!" << endl : cout << firstN / secondN << endl;

        break;

    case '%':

        if (firstN - int(firstN) < 0.0000001 && secondN - int(secondN) < 0.0000001) {

            cout << (int)firstN % (int)secondN << endl;

        }

        else {
        
            cout << "для проведения данной операции числа должны быть целыми!" << endl;

        }

        break;

    default:

        cout << "неправильный знак!" << endl;

        break;

    }
}
