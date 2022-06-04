#include <iostream>

#include <Windows.h>

#include <cmath>

using namespace std;

int main() {

    const double ACCURACY = 0.00000001;

    double result = 0;

    double trueResult = 1.0 / 8;

    cout << "True result: " << trueResult << endl;

    for (int i = 1; i / pow((4 * pow(i, 2) - 1), 2) >= ACCURACY; i++) {
    
        result += i / pow((4 * pow(i, 2) - 1), 2);
        
    }

    cout << "Result obtained by calculations with the accuracy of " << ACCURACY << ": " << result << endl;

    system("pause");

}