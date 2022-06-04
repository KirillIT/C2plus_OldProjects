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

	cout << "�� ������ ����� �� ������ ��������� �����, ������� ���: ";

	cin >> startRange;

	cout << endl << "�� ������ ����� �� ������ ��������� �����, ������� ���: ";

	cin >> endRange;

	cout << endl << "����������� �������: ";

	if (startRange > endRange) {

		startRange = startRange + endRange;

		endRange = startRange - endRange;

		startRange = startRange - endRange;

	}

	cin >> numberAttempts; 
	
	if (numberAttempts < 1) {

		cout << endl << "������������� ���-�� ������ (��� ���-�� ������� ����� 0)!" << endl << endl;

		system("pause");

		return 0;

	}

	if (numberAttempts > ceil(float(endRange - startRange + 1) / 2)) { 

		numberAttempts = ceil(float(endRange - startRange + 1) / 2);

		cout << endl << "� ��� ������� ����� �������! ������������ ����� � " << numberAttempts << " ������� ��������!" << endl;

	}

	int random = rand() % (endRange - startRange + 1) + startRange;

	cout << endl << "����� ���������!" << endl << endl;

	system("pause");

	do {
		
		system("cls");
		 
		cout << "� ��� �������� " << numberAttempts << " �������(��)(�)" << endl << endl;

		cout << "��������� ����� " << "�� " << startRange << " �� " << endRange << ": ";

		cin >> numberPlayer;

		if (numberPlayer == random) {

			system("cls");

			cout << "�� ������� �����! ���������!" << endl;

			break;

		}

		numberAttempts--;

	}
	
	while (numberAttempts != 0);

	if (numberAttempts == 0) {

		system("cls");
	
		cout << "�� �� ������� �����! �� ���������!" << endl << endl << "��� ����� ���� ����� " << random << endl;

	}

	cout << endl;

	system("pause");

}