#include <iostream>
#include <windows.h>
#include <string>
#include <ctime>

using namespace std;

string action;
string personName, firstEnemyName, secondEnemyName;
float damage_person;
bool logic = true;

class Person;

class Enemy {

	friend class Person;

private:

	float health_enemy = 10000;
};

class Person {

	friend class Enemy;

public:

	void ultra(Enemy &enemy) {

		enemy.health_enemy -= damage_person * 10;
		cout << endl;
		cout << "Критический урон!\n";

	}

	void epic(Enemy &enemy) {

		enemy.health_enemy = 1;
		cout << endl;
		cout << "Смертельный урон!\n";

	}

	void Damage(Enemy &enemy) {

		enemy.health_enemy -= damage_person;

	}

	void special(Enemy &enemy) {

		enemy.health_enemy -= damage_person * 10;

	}

	void Health(Enemy &enemy) {

		enemy.health_enemy += damage_person * 1.5;

	}

	void OutPut(Enemy &enemy) {

		if (enemy.health_enemy <= 0) {

			cout << endl;
			cout << firstEnemyName << " умер(ла)!\n";
			logic = false;
			cout << endl;

		}

		else if (enemy.health_enemy > 10000) {

			enemy.health_enemy = 10000;
			cout << endl;
			cout << "Здоровье " << secondEnemyName << " состовляет " << enemy.health_enemy << " из 10000!" << endl;
			cout << endl;

		}

		else {

			cout << endl;
			cout << "Здоровье " << secondEnemyName << " состовляет " << enemy.health_enemy << " из 10000!" << endl;
			cout << endl;

		}
	}
};

int main() {

	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	srand(time(NULL));

	Person person;

	Enemy enemy;

	cout << "Как вас зовут: ";

	cin >> personName;

	cout << endl;

	cout << "Как зовут вашего врага: ";

	cin >> firstEnemyName;

	cout << endl;

	cout << "Введите имя вашего врага в родительном падеже: ";

	cin >> secondEnemyName;

	cout << endl;

	cout << "Привет, " << personName << "!\n";

	cout << "Какой урон ты хочешь заполучить(не больше 100): ";

	cin >> damage_person;

	cout << endl;

	if (damage_person > 100) damage_person = 100;

	cout << "У " << secondEnemyName << " 10.000 xp!\n";

	cout << "Что ты с ним хочешь сделать (нанести урон или выличить): ";

	while (logic == true) {

		int random = 1 + rand() % 10;
		int legend = 1 + rand() % 100;

		getline(cin, action);

		if (action == "") continue;

		else if (action == string("нанести урон") || action == string("Нанести урон") || action == string("Нанести Урон") || action == string("НАНЕСТИ УРОН") || action == string("урон") || action == string("Урон") || action == string("УРОН") || action == string("нанести") || action == string("Нанести") || action == string("НАНЕСТИ") || action == string("-")) {

			if (random == 5) {

				person.ultra(enemy);
				person.OutPut(enemy);

			}

			else if (legend == damage_person) {

				person.epic(enemy);
				person.OutPut(enemy);

			}

			else {

				person.Damage(enemy);
				person.OutPut(enemy);

			}
		}

		else if (action == string("вылечить") || action == string("Вылечить") || action == string("ВЫЛЕЧИТЬ") || action == string("+")) {

			person.Health(enemy);
			person.OutPut(enemy);

		}

		else {

			cout << endl;
			cout << "Такого действия не существует, повторите попытку!\n";
			cout << endl;
			continue;

		}
	}

	system("pause");

}