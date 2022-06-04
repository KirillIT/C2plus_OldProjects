#include <iostream>
#include <windows.h>
#include <conio.h>
#include <ctime>

using namespace std;

int score;
int hight, width;
int firstPortalX, firstPortalY;
int secondPortalX, secondPortalY;
int firstPlayerScore, secondPlayerScore;
int firstPlayerX, firstPlayerY;
int secondPlayerX, secondPlayerY;

int firstPlayerStep = 1, secondPlayerStep = 1;

char firstPlayerSkin, secondPlayerSkin;

bool chaser;
bool gameOver;

void Start();

void Draw();

void Logic();

void Input();

void SetCursor(int x, int y);

int main() {

	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	srand(time(NULL));

	Start();

	while (!gameOver) {

		Draw();
		Input();
		Logic();

	}	

	system("cls");

	if (firstPlayerScore == score) cout << "������ ����� �������!\n";

	else if (secondPlayerScore == score) cout << "������ ����� �������!\n";

	system("pause");

}

void Start() {

	cout << "�������� ���� ��� ������� ������: ";

	cin >> firstPlayerSkin;

	cout << "�������� ���� ��� ������� ������: ";

	cin >> secondPlayerSkin;

	system("cls");

	while (true) {

		cout << "�������� ����� ����� �� ��������� (�� 7 �� 21): ";

		cin >> width;

		if (width < 7 || width > 21) {

			cout << "����� ������ ������� ������� ����������! ��������� �������!\n";

			continue;

		}

		system("cls");

		break;

	}

	while (true) {

		cout << "�������� ����� ����� �� ����������� (�� 7 �� 21): ";

		cin >> hight;

		if (hight < 7 || hight > 21) {

			cout << "����� ������ ������� ������� ����������! ��������� �������!\n";

			continue;

		}

		system("cls");

		break;

	}

	secondPortalX = rand() % (hight - 4) + 3;
	secondPortalY = rand() % (width - 4) + 3;

	cout << "�� �������� ����� �� ������ ������ (�� 1 �� 100): ";

	while (true) {

		cin >> score;

		if (score > 100 || score < 1) {

			cout << "������! ����� �������� ������� ����������! ��������� �������!\n";

			continue;

		}

		break;

	}

	system("cls");

	int * a = new int[1];

	a[0] = rand() % 2 + 1;

	if (a[0] == 1) chaser = true;

	else chaser = false;

	delete[]a;

	firstPlayerX = 2;

	firstPlayerY = 2;

	secondPlayerX = hight - 1;

	secondPlayerY = width - 1;

	while (true) {

		firstPortalX = rand() % (hight - 4) + 3;

		firstPortalY = rand() % (width - 4) + 3;

		if (secondPortalX == firstPortalX && secondPlayerY == firstPortalY) continue;

		break;

	}

	system("cls");

}

void Draw() {

	for (int i = 1; i <= hight; i++) {

		for (int j = 1; j <= width; j++) {

			if (i == 1 || i == hight) cout << "#";

			else if (j == 1 || j == width) cout << "#";

			else if (j == firstPlayerY && i == firstPlayerX) cout << firstPlayerSkin;

			else if (j == secondPlayerY && i == secondPlayerX) cout << secondPlayerSkin;

			else if (j == firstPortalY && i == firstPortalX) cout << "O";

			else if (j == secondPortalY && i == secondPortalX) cout << "O";

			else cout << " ";

		}

		cout << endl;

	}

	cout << "���� ������� ������: " << firstPlayerScore << " �� " << score << " ���������"<< endl;

	cout << "���� ������� ������: " << secondPlayerScore << " �� " << score << " ���������" << endl;

	cout << "����� ";
	
	if (chaser) cout << "������ �����\n";

	else cout << "������ �����\n";

	SetCursor(0, 0);

}

void Logic() {

	if (firstPlayerScore == score) gameOver = true;

	if (secondPlayerScore == score) gameOver = true;

	if (firstPlayerX == 1) firstPlayerX++;

	if (firstPlayerX == hight) firstPlayerX--;

	if (firstPlayerY == 1) firstPlayerY++;

	if (firstPlayerY == width) firstPlayerY--;

	if (secondPlayerX == 1) secondPlayerX++;

	if (secondPlayerX == hight) secondPlayerX--;

	if (secondPlayerY == 1) secondPlayerY++;

	if (secondPlayerY == width) secondPlayerY--;

	if (firstPlayerX == secondPlayerX && secondPlayerY == firstPlayerY) {

		
		firstPlayerX = 2;

		firstPlayerY = 2;

		secondPlayerX = hight - 1;

		secondPlayerY = width - 1;

		if (chaser) firstPlayerScore++;

		else secondPlayerScore++;

		if (chaser) chaser = false;

		else chaser = true;

	}

	if (firstPlayerX == firstPortalX && firstPlayerY == firstPortalY && firstPlayerStep > 0) {

		firstPlayerX = secondPortalX;

		firstPlayerY = secondPortalY;

		firstPlayerStep = 0;
			
	}

	if (firstPlayerX == secondPortalX && firstPlayerY == secondPortalY && firstPlayerStep > 0) {

		firstPlayerX = firstPortalX;

		firstPlayerY = firstPortalY;

		firstPlayerStep = 0;

	}

	if (secondPlayerX == firstPortalX && secondPlayerY == firstPortalY && secondPlayerStep > 0) {

		secondPlayerX = secondPortalX;

		secondPlayerY = secondPortalY;

		secondPlayerStep = 0;

	}

	if (secondPlayerX == secondPortalX && secondPlayerY == secondPortalY && secondPlayerStep > 0) {

		secondPlayerX = firstPortalX;

		secondPlayerY = firstPortalY;

		secondPlayerStep = 0;

	}
}

void Input() {

	if (_kbhit()) {

		switch (_getch()) {

		case 'a':

			firstPlayerY--;
			firstPlayerStep++;
			break;

		case 'd':

			firstPlayerY++;
			firstPlayerStep++;;
			break;

		case 'w':

			firstPlayerX--;
			firstPlayerStep++;
			break;

		case 's':

			firstPlayerX++;
			firstPlayerStep++;
			break;

		case 75:

			secondPlayerY--;
			secondPlayerStep++;
			break;

		case 77:

			secondPlayerY++;
			secondPlayerStep++;
			break;

		case 72:

			secondPlayerX--;
			secondPlayerStep++;
			break;

		case 80:

			secondPlayerX++;
			secondPlayerStep++;
			break;

		}
	}
}

void SetCursor(int x, int y) {

	COORD coord;
	coord.X = x;
	coord.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);

}