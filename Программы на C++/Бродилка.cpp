#include <iostream>
#include <windows.h>
#include <conio.h>
#include <ctime>

using namespace std;

int score;
int playerX, playerY;
int fruitX, fruitY;
int villainX, villainY;

const int HIGHT = 13;
const int WIDTH = 13;

bool gameOver;
bool moveVillainRightOrLeft;
bool moveVillainUpOrDown;

void Start();

void Draw();

void Logic();

void Input();

void RandomFruit();

void MoveVillain();

void SetCursor(int x, int y);

int main() {

	srand(time(NULL));

	Start();

	while (!gameOver) {

		Draw();
		Input();
		Logic();

	}

	system("cls");
	system("pause");

}

void Start() {

	playerX = HIGHT / 2 + 1;
	playerY = WIDTH / 2 + 1;

	villainX = 2;
	villainY = 2;

	RandomFruit();

}

void Draw() {

	for (int i = 1; i <= HIGHT; i++) {

		for (int j = 1; j <= WIDTH; j++) {

			if (i == 1 || i == HIGHT) cout << "#";

			else if (j == 1 || j == WIDTH) cout << "#";

			else if (j == playerY && i == playerX) cout << "P";

			else if (j == fruitY && i == fruitX) cout << "F";

			else if (j == villainY && i == villainX) cout << "V";

			else cout << " ";

		}

		cout << endl;

	}

	cout << "Score: " << score << endl;

	cout << "World record: 1120 score";

	SetCursor(0, 0);

}

void Logic() {

	if (playerX == 1 || playerX == HIGHT || playerY == 1 || playerY == WIDTH) gameOver = true;

	if (playerX == villainX && playerY == villainY)	gameOver = true;

	if (playerX == fruitX && playerY == fruitY) {

		RandomFruit();
		score += 10;

	}
}

void Input() {

	if (_kbhit()) {

		switch (_getch()) {

		case 'a':

			playerY--;
			MoveVillain();
			break;

		case 'd':

			playerY++;
			MoveVillain();
			break;

		case 'w':

			playerX--;
			MoveVillain();
			break;

		case 's':

			playerX++;
			MoveVillain();
			break;

		case 75:

			playerY--;
			MoveVillain();
			break;

		case 77:

			playerY++;
			MoveVillain();
			break;

		case 72:

			playerX--;
			MoveVillain();
			break;

		case 80:

			playerX++;
			MoveVillain();
			break;

		}
	}
}

void RandomFruit() {

	bool randomFruitActive = false;

	fruitX = rand() % HIGHT + 1;
	fruitY = rand() % WIDTH + 1;

	while (!randomFruitActive) {

		if (fruitX <= 1 || fruitX >= HIGHT || fruitY <= 1 || fruitY >= WIDTH) {

			fruitX = rand() % HIGHT;
			fruitY = rand() % WIDTH;

		}

		else randomFruitActive = true;

	}
}

void MoveVillain() {

	if (!moveVillainUpOrDown) {

		if (!moveVillainRightOrLeft) {

			villainY++;

			if (villainY >= WIDTH) {

				villainX++;
				moveVillainRightOrLeft = true;

			}
		}

		if (moveVillainRightOrLeft) {

			villainY--;

			if (villainY == 1) {

				villainY = 2;
				villainX++;
				moveVillainRightOrLeft = false;

			}
		}

		if (villainX == HIGHT) {

			moveVillainUpOrDown = true;
			moveVillainRightOrLeft = true;
			villainX = HIGHT - 1;
			villainY = WIDTH - 1;

		}
	}

	if (moveVillainUpOrDown) {

		if (moveVillainRightOrLeft) {

			villainY--;

			if (villainY == 1) {

				villainY = 1;
				villainX--;
				moveVillainRightOrLeft = false;

			}
		}

		if (!moveVillainRightOrLeft) {

			villainY++;

			if (villainY >= WIDTH) {

				villainY = WIDTH - 1;
				villainX--;
				moveVillainRightOrLeft = true;

			}
		}

		if (villainX == 1) {

			moveVillainUpOrDown = false;
			moveVillainRightOrLeft = false;
			villainX = 2;
			villainY = 3;

		}
	}
}

void SetCursor(int x, int y) {

	COORD coord;
	coord.X = x;
	coord.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);

}