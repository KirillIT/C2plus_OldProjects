#include <iostream>

#include <windows.h>

#include <ctime>

#include <cmath>

using namespace std;

int main() {

	SetConsoleCP(1251);

	SetConsoleOutputCP(1251);

	srand(time(NULL));

	int startRange, endRange;

	int numberAttempts;

	int numberPlayer;

	cout << "От какого числа вы будете угадывать число, включая его: ";

	cin >> startRange;

	cout << endl << "До какого числа вы будете угадывать число, включая его: ";

	cin >> endRange;

	cout << endl << "Колличество попыток: ";

	if (startRange > endRange) {

		startRange = startRange + endRange;

		endRange = startRange - endRange;

		startRange = startRange - endRange;

	}

	cin >> numberAttempts; 
	
	if (numberAttempts < 1) {

		cout << endl << "Отрицательное кол-во ошибок (или кол-во попыток равно 0)!" << endl << endl;

		system("pause");

		return 0;

	}

	if (numberAttempts > ceil(float(endRange - startRange + 1) / 2)) { 

		numberAttempts = ceil(float(endRange - startRange + 1) / 2);

		cout << endl << "У вас слишком много попыток! Максимальный порог в " << numberAttempts << " попыток превышен!" << endl;

	}

	int random = rand() % (endRange - startRange + 1) + startRange;

	cout << endl << "Число загаданно!" << endl << endl;

	system("pause");

	do {
		
		system("cls");
		 
		cout << "У вас осталось " << numberAttempts << " попыток(ки)(а)" << endl << endl;

		cout << "Отгадайте число " << "от " << startRange << " до " << endRange << ": ";

		cin >> numberPlayer;

		if (numberPlayer == random) {

			system("cls");

			cout << "Вы угадали число! Поздравлю!" << endl;

			break;

		}

		numberAttempts--;

	}
	
	while (numberAttempts != 0);

	if (numberAttempts == 0) {

		system("cls");
	
		cout << "Вы не угадали число! Вы проиграли!" << endl << endl << "Это число было равно " << random << endl;

	}

	cout << endl;

	system("pause");

}