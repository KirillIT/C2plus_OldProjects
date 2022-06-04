#include <iostream>
#include <conio.h> 
#include <windows.h>
#include <string>
#include <cmath>
#include <thread>
#include <fstream>
/*

			Идеи и планы для кликера

	1) Новые предметы
	2) Новые цены на все предметы
	3) Пристиж (10 раз. За один "престиж" покупается только 1/10 всех предметов)
	4) Полное обнуление игры
	6) Достидения, связанные с временем, проведённым в игре
	7) Больше достижений (подуровней уже имеющихся)
	8) Если денег дольше, чем в себя вмещает тип double, то обнуляем деньги на более ценную валюту.
	9) Поискать тип, вмещающий в себя больую степень, чем double
	10) Призы за достижения

*/
using namespace std;

int Variables_To_Save_Int[8];

int Number_Of_Items_Purchased;
int Number_Of_Clicks_Per_Time;
int Autoclick_Level;
int Chance_Of_Double_Coins_Level;
int Chance_Of_Double_Coins;
int Increase_Chance;
int Number_Of_Completed_Achievements;
int Click_Level = 1;
int Coefficient_Of_Price_Increase = 2;

const int Number_Of_Things = 132;
const int Number_Of_Achievements = 42;

double Variables_To_Save_Double[9];

double Amount_Of_Rubles_Per_Second;
double Currency;
double Number_Of_Rubles_For_All_Time;
double The_Amount_Of_Rubles_With_Autocliker_For_All_Time;
double Number_Of_Rubles_Using_Autoclicker_Per_Second = 1;
double Salary = 1;
double Price_To_Improve_Click = 100;
double Price_To_Improve_Autoclick = 100;
double Price_To_Improve_The_Chance_Of_Double_Coins = 100;

bool Game_Over;

string The_Name_Of_Things_In_The_Nominative_Case[Number_Of_Things]{

		"Спичечный коробок",
		"Жевательная резинка",
		"Роллтон",
		"Килограмм воды",
		"Маска",
		"Семечки",
		"Гематоген",
		"Мороженое",
		"Пачка чипсов",
		"Сок",
		"Доллар",
		"Кока-кола",
		"Макароны",
		"Батарейка",
		"Носки",
		"Бургер",
		"Пельмени",
		"Пачка сигарет",
		"Пачка презервативов",
		"Ложка",
		"Вилка",
		"Книга",
		"Фарш",
		"Водка",
		"Кружка",
		"Коньяк",
		"Килограмм железа",
		"Трусы",
		"Нож",
		"Собака",
		"Майка",
		"Шапка",
		"Футболка",
		"Стул",
		"Кот",
		"Курица",
		"Штаны",
		"Портфель",
		"Килограмм снега",
		"Футбольный мяч",
		"Кросовки",
		"Свинья",
		"Батарея",
		"Ковёр",
		"Куртка",
		"Диван",
		"Баскетбольный мяч",
		"Стол",
		"Телефон",
		"Лошадь",
		"Килограмм алюминия",
		"Телевизор",
		"Корова",
		"Игровая приставка",
		"Ответы на ОГЭ",
		"Шкаф",
		"Килограмм меди",
		"Лыжи",
		"Килограмм чистого воздуха",
		"Компьютер",
		"Ответы на ЕГЭ",
		"Килограмм урана",
		"Лев",
		"Питон",
		"Тигр",
		"Сарай",
		"Биткоин",
		"Килограмм золота",
		"Почка",
		"Автобус",
		"Гараж",
		"Машина",
		"Кофейня",
		"Лодка",
		"Качалка",
		"Килограмм алмазов",
		"Школа",
		"Магазин",
		"Дом",
		"Цирк",
		"Каток",
		"Танки Онлайн",
		"Бассейн",
		"Атомная бомба",
		"Панда",
		"Городская улица",
		"Завод",
		"Баскетбольная площадка",
		"Яхта",
		"Самолёт",
		"Особняк",
		"Подводная лодка",
		"Кинотеатр",
		"Футбольная площадка",
		"Майнкрафт",
		"Офис",
		"Кремль",
		"Компания Самсунг",
		"Единорог",
		"Компания Эппл",
		"Бункер",
		"Городской район",
		"Гидроэлектростанция",
		"Тепловая электростанция",
		"Атомная электростанция",
		"Ракета",
		"Город",
		"Банк",
		"Страна Россия",
		"Космический корабль",
		"Страна Америка",
		"Интернет",
		"Инопланетянин",
		"Луна",
		"Карликовая планета Плутон",
		"Планета Земля",
		"Планета Меркурий",
		"Планета Венера",
		"Планета Марс",
		"Планета Уран",
		"Планета Нептун",
		"Планета Сатурн",
		"Планета Юпитер",
		"Солнечная система",
		"Чёрная дыра",
		"Галактика Млечный Путь",
		"Кластер галактик",
		"Вселенная",
		"Килограмм антиматерии",
		"Машина времени",
		"Телепортатор между Вселенными в Мультивселенной",
		"Мультивселенная",

};

string The_Name_Of_Things_In_The_Аccusative_Case[Number_Of_Things]{

		"спичечный коробок",
		"жевательную резинку",
		"Роллтон",
		"килограмм воды",
		"маску",
		"семечки",
		"гематоген",
		"мороженое",
		"пачку чипсов",
		"сок",
		"доллар",
		"Кока-колу",
		"макароны",
		"батарейку",
		"носки",
		"бургер",
		"пельмени",
		"пачку сигарет",
		"пачку презервативов",
		"ложку",
		"вилку",
		"книгу",
		"фарш",
		"водку",
		"кружку",
		"коньяк",
		"килограмм железа",
		"трусы",
		"нож",
		"собаку",
		"майку",
		"шапку",
		"футболку",
		"стул",
		"кота",
		"курицу",
		"штаны",
		"портфель",
		"килограмм снега",
		"футбольный мяч",
		"кросовки",
		"свинью",
		"батарею",
		"ковёр",
		"куртку",
		"диван",
		"баскетбольный мяч",
		"стол",
		"телефон",
		"лошадь",
		"килограмм алюминия",
		"телевизор",
		"корову",
		"игровую приставку",
		"ответы на ОГЭ",
		"шкаф",
		"килограмм меди",
		"лыжи",
		"килограмм чистого воздуха",
		"компьютер",
		"ответы на ЕГЭ",
		"килограмм урана",
		"льва",
		"питона",
		"тигра",
		"сарай",
		"биткоин",
		"килограмм золота",
		"почку",
		"автобус",
		"гараж",
		"машину",
		"кофейню",
		"лодку",
		"качалку",
		"килограмм алмазов",
		"школу",
		"магазин",
		"дом",
		"цирк",
		"каток",
		"Танки Онлайн",
		"бассейн",
		"атомную бомбу",
		"панду",
		"городскую улицу",
		"завод",
		"баскетбольную площадку",
		"яхту",
		"самолёт",
		"особняк",
		"подводную лодку",
		"кинотеатр",
		"футбольную площадку",
		"Майнкрафт",
		"офис",
		"кремль",
		"компанию Самсунг",
		"единорога",
		"компанию Эппл",
		"бункер",
		"городской район",
		"гидроэлектростанцию",
		"тепловую электростанцию",
		"атомную электростанцию",
		"ракету",
		"город",
		"банк",
		"страну Россию",
		"космический корабль",
		"страну Америку",
		"интернет",
		"инопланетянина",
		"Луну",
		"карликовую планету Плутон",
		"планету Земля",
		"планету Меркурий",
		"планету Венера",
		"планету Марс",
		"планету Уран",
		"планету Нептун",
		"планету Сатурн",
		"планету Юпитер",
		"солнечную систему",
		"чёрную дыру",
		"галактику Млечный Путь",
		"кластер галактик",
		"Вселенную",
		"килограмм антиматерии",
		"машину времени",
		"телепортатор между Вселенными в Мультивселенной",
		"Мультивселенную",

};

double The_Price_Of_Things[Number_Of_Things]{

		1,
		10,
		500,
		7000,
		10,
		25,
		30,
		40,
		50,
		60,
		70,
		75,
		82,
		90,
		100,
		105,
		120,
		135,
		150,
		175,
		180,
		200,
		250,
		300,
		400,
		500,
		600,
		750,
		800,
		900,
		1'000,
		1'500,
		2'000,
		3'500,
		4'000,
		4'700,
		5'000,
		5'300,
		6'000,
		7'500,
		8'000,
		10'000,
		11'000,
		15'000,
		18'000,
		20'000,
		23'000,
		25'000,
		30'000,
		33'000,
		35'000,
		42'000,
		45'000,
		50'000,
		55'000,
		60'000,
		75'000,
		84'000,
		92'000,
		100'000,
		175'000,
		250'000,
		400'000,
		520'000,
		950'000,
		1'500'000,
		2'000'000,
		2'500'000,
		3'500'000,
		5'000'000,
		7'000'000,
		10'000'000,
		13'000'000,
		18'000'000,
		22'000'000,
		25'000'000,
		35'000'000,
		42'000'000,
		50'000'000,
		64'000'000,
		75'000'000,
		80'000'000,
		130'000'000,
		200'000'000,
		250'000'000,
		400'000'000,
		550'000'000,
		760'000'000,
		880'000'000,
		1'000'000'000,
		2'500'000'000,
		4'300'000'000,
		5'700'000'000,
		6'500'000'000,
		7'900'000'000,
		50'000'000'000,
		130'500'000'000,
		15'000'000'000'000,
		45'000'000'000'000,
		75'000'000'000'000,
		120'000'000'000'000,
		250'000'000'000'000,
		300'000'000'000'000,
		550'000'000'000'000,
		750'000'000'000'000,
		800'000'000'000'000,
		1'000'000'000'000'000,
		2'300'000'000'000'000,
		5'000'000'000'000'000,
		24'000'000'000'000'000,
		55'000'000'000'000'000,
		750'000'000'000'000'000,
		4'600'000'000'000'000'000,
		2.3e+19,
		6.5e+20,
		1.12e+24,
		1.624e+25,
		2.304e+25,
		5e+25,
		7.6e+26,
		1.8e+27,
		8.4e+29,
		3.2e+30,
		1e+36,
		1e+38,
		1e+63,
		1e+72,
		1e+87,
		1e+123,
		1e+135,
		1e+153,
		9.999e+297

};

void Exit();

void Shop();

void Input();

void Progress();

void Rounding();

void Main_Info();

void Statistics();

void Load_To_File();

void Training_Menu();

void Load_From_File();

void Room_With_Things();

void Is_The_Autoclicker_Active();

void Set_Cursor(int x, int y);

int main() {

	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	try {

		Load_From_File();

	}

	catch (...) {}

	thread Flow_For_The_Autoclicker(Is_The_Autoclicker_Active);

	while (!Game_Over) {

		Set_Cursor(0, 0);

		Rounding();

		Main_Info();

		Input();

	}

	Flow_For_The_Autoclicker.detach();

}

void  Load_From_File() {

	ifstream temporary;

	string path = "C:\\Users\\kirill\\source\\repos\\FirstProject\\save.txt";

	temporary.open(path);

	if (temporary.is_open()) {

		string str;

		int count = 1;

		while (!temporary.eof()) {

			str = "";

			temporary >> str;

			if (count <= 8) Variables_To_Save_Int[count - 1] = stoi(str);

			else if (count > 8 && count <= 17) Variables_To_Save_Double[count - 9] = stod(str);

			count++;

		}

		Number_Of_Items_Purchased = Variables_To_Save_Int[0];
		Number_Of_Clicks_Per_Time = Variables_To_Save_Int[1];
		Autoclick_Level = Variables_To_Save_Int[2];
		Chance_Of_Double_Coins_Level = Variables_To_Save_Int[3];
		Chance_Of_Double_Coins = Variables_To_Save_Int[4];
		Increase_Chance = Variables_To_Save_Int[5];
		Number_Of_Completed_Achievements = Variables_To_Save_Int[6];
		Click_Level = Variables_To_Save_Int[7];

		Amount_Of_Rubles_Per_Second = Variables_To_Save_Double[0];
		Currency = Variables_To_Save_Double[1];
		Number_Of_Rubles_For_All_Time = Variables_To_Save_Double[2];
		The_Amount_Of_Rubles_With_Autocliker_For_All_Time = Variables_To_Save_Double[3];
		Number_Of_Rubles_Using_Autoclicker_Per_Second = Variables_To_Save_Double[4];
		Salary = Variables_To_Save_Double[5];
		Price_To_Improve_Click = Variables_To_Save_Double[6];
		Price_To_Improve_Autoclick = Variables_To_Save_Double[7];
		Price_To_Improve_The_Chance_Of_Double_Coins = Variables_To_Save_Double[8];

		temporary.close();

		system("cls");

	}

	else {

		cout << "Ошибка открытия файла!" << endl << endl;

		system("pause");

		system("cls");

	}
}

void Load_To_File() {

	ofstream temporary;

	string path = "C:\\Users\\kirill\\source\\repos\\FirstProject\\save.txt";

	temporary.open(path);

	if (temporary.is_open()) {

		temporary << Number_Of_Items_Purchased << endl;
		temporary << Number_Of_Clicks_Per_Time << endl;
		temporary << Autoclick_Level << endl;
		temporary << Chance_Of_Double_Coins_Level << endl;
		temporary << Chance_Of_Double_Coins << endl;
		temporary << Increase_Chance << endl;
		temporary << Number_Of_Completed_Achievements << endl;
		temporary << Click_Level << endl;
		temporary << Amount_Of_Rubles_Per_Second << endl;
		temporary << Currency << endl;
		temporary << Number_Of_Rubles_For_All_Time << endl;
		temporary << The_Amount_Of_Rubles_With_Autocliker_For_All_Time << endl;
		temporary << Number_Of_Rubles_Using_Autoclicker_Per_Second << endl;
		temporary << Salary << endl;
		temporary << Price_To_Improve_Click << endl;
		temporary << Price_To_Improve_Autoclick << endl;
		temporary << Price_To_Improve_The_Chance_Of_Double_Coins << endl;

		temporary.close();

		cout << "Сохранение прогресса прошло успешно!" << endl << endl;

		system("pause");

		system("cls");

	}

	else {

		cout << "Ошибка открытия файла!" << endl << endl;

		system("pause");

		system("cls");

	}
}

void Statistics() {

	cout << "Уровень клика: " << Click_Level << endl;
	cout << "Рублей за один клик: " << Salary << endl << endl;
	cout << "Уровень автоклика: " << Autoclick_Level << endl;
	cout << "Рублей автоматически за 1 сек.: ";

	if (Autoclick_Level >= 1) {

		if (Amount_Of_Rubles_Per_Second > 100) Amount_Of_Rubles_Per_Second = ceil(Amount_Of_Rubles_Per_Second);

		cout << Amount_Of_Rubles_Per_Second << endl;

	}

	else cout << "0" << endl;

	cout << endl;

	cout << "Шанс \"двойной монеты\": " << Chance_Of_Double_Coins << "%" << endl;
	cout << "Уровень шанса \"двойной монеты\": " << Chance_Of_Double_Coins_Level << endl << endl;

	cout << "Всего кликов: " << Number_Of_Clicks_Per_Time << endl;
	cout << "Рублей за всё время: " << Number_Of_Rubles_For_All_Time << endl;
	cout << "Рублей с помощью автоклика за всё время: " << The_Amount_Of_Rubles_With_Autocliker_For_All_Time << endl;

	cout << endl;

	system("pause");

	system("cls");

}

void Is_The_Autoclicker_Active() {

	while (true) {

		if (Autoclick_Level >= 1) {

			this_thread::sleep_for(chrono::milliseconds(1000));

			Currency += Number_Of_Rubles_Using_Autoclicker_Per_Second;

			The_Amount_Of_Rubles_With_Autocliker_For_All_Time += Number_Of_Rubles_Using_Autoclicker_Per_Second;

			Number_Of_Rubles_For_All_Time += Number_Of_Rubles_Using_Autoclicker_Per_Second;

		}
	}
}

void Room_With_Things() {

	for (int i = 0; i < Number_Of_Items_Purchased; i++) cout << The_Name_Of_Things_In_The_Nominative_Case[i] << " - куплено за " << The_Price_Of_Things[i] << " р." << endl;

	if (Number_Of_Items_Purchased > 0) cout << endl;

	if (Number_Of_Items_Purchased < Number_Of_Things) {

		cout << "Хотите купить " << The_Name_Of_Things_In_The_Аccusative_Case[Number_Of_Items_Purchased] << " за " << The_Price_Of_Things[Number_Of_Items_Purchased] << " р.?" << endl;

		cout << endl;

		cout << "1) Да" << endl;

		cout << "2) Нет" << endl << endl;

		string trophy_answer;

		getline(cin, trophy_answer);

		cout << endl;

		if (trophy_answer == string("да") || trophy_answer == string("ДА") || trophy_answer == string("Да") || trophy_answer == string("дА") || trophy_answer == string("lf") || trophy_answer == string("1") || trophy_answer == string("LF") || trophy_answer == string("lF") || trophy_answer == string("Lf")) {

			if (Currency >= The_Price_Of_Things[Number_Of_Items_Purchased]) {

				Currency -= The_Price_Of_Things[Number_Of_Items_Purchased];

				Number_Of_Items_Purchased++;

			}

			else {

				cout << "Ваших рублей слишком мало!" << endl << endl;

				system("pause");

			}
		}
	}

	else system("pause");

	system("cls");

}

void Rounding() {

	if (Salary > 3)	Salary = ceil(Salary);

}

void Training_Menu() {

	cout << "Чтобы заработать деньги, нажмите на пробел!" << endl;

	cout << endl;

	cout << "Чтобы войти в магазин, нажмите: m" << endl;

	cout << "Чтобы войти в комнату с предметами, нажмите: t" << endl;

	cout << "Чтобы войти в зал достижений, нажмите: h" << endl;

	cout << "Чтобы посмотреть статистику, нажмите: s" << endl;

	cout << "Чтобы сохранить прогресс, нажмите: g" << endl;

	cout << "Чтобы выйти из игры, нажмите: e" << endl;

	cout << endl;

	system("pause");

	system("cls");

}

void Main_Info() {

	cout << "Кол-во рублей: " << Currency << endl << endl;

	cout << "Чтобы получить больше информации, нажмите: i" << endl << endl;

}

void Exit() {

	cout << "Вы точно хотите выйти из игры?" << endl;

	string trophy_answer;

	cout << endl;

	cout << "1) Да" << endl;

	cout << "2) Нет" << endl;

	cout << endl;

	getline(cin, trophy_answer);

	if (!(trophy_answer == string("да") || trophy_answer == string("ДА") || trophy_answer == string("Да") || trophy_answer == string("дА") || trophy_answer == string("lf") || trophy_answer == string("1") || trophy_answer == string("LF") || trophy_answer == string("lF") || trophy_answer == string("Lf"))) {

		cout << endl;

		system("pause");

		system("cls");

	}

	else {

		cout << endl;

		Load_To_File();

		Game_Over = true;

		cout << endl;

	}
}

void Input() {

	if (_kbhit()) {

		int get = _getwch();

		if (get == ' ') {

			Currency += Salary;

			Number_Of_Clicks_Per_Time++;

			Number_Of_Rubles_For_All_Time += Salary;

			if (Chance_Of_Double_Coins_Level >= 1) {

				Increase_Chance++;

				if (Increase_Chance == 101 - Chance_Of_Double_Coins) {

					Increase_Chance = 0;

					Currency += Salary;

				}
			}
		}

		else if (get == 'm' || get == 'M') Shop();

		else if (get == 's' || get == 'S') Statistics();

		else if (get == 'h' || get == 'H') Progress();

		else if (get == 't' || get == 'T') Room_With_Things();

		else if (get == 'i' || get == 'I') Training_Menu();

		else if (get == 'g' || get == 'G') Load_To_File();

		else if (get == 'e' || get == 'E') Exit();

	}
}

void Shop() {

	string The_Main_Answer;
	string Answer_About_Click;
	string Answer_About_Autoclick;
	string The_Answer_About_The_Chance_Of_A_Double_Coin;

	cout << "Выберите из списка:\n\n";

	cout << "1) Улучшить клик" << endl;
	cout << "2) Улучшить автоклик" << endl;
	cout << "3) Улучшить шанс \"двойной монеты\"" << endl;

	cout << endl;

	getline(cin, The_Main_Answer);

	cout << endl;

	if (The_Main_Answer == string("1") || The_Main_Answer == string("Улучшить клик") || The_Main_Answer == string("улучшить клик") || The_Main_Answer == string("УЛУЧШИТЬ КЛИК")) {

		cout << "Уровень вашего клика " << Click_Level << ". Улучшить до " << Click_Level + 1 << " уровня за " << Price_To_Improve_Click << " рублей?" << endl << endl;

		cout << "1) Да" << endl;

		cout << "2) Нет" << endl;

		cout << endl;

		cin >> Answer_About_Click;

		cout << endl;

		if (Answer_About_Click == string("да") || Answer_About_Click == string("ДА") || Answer_About_Click == string("Да") || Answer_About_Click == string("дА") || Answer_About_Click == string("lf") || Answer_About_Click == string("1") || Answer_About_Click == string("LF") || Answer_About_Click == string("lF") || Answer_About_Click == string("Lf")) {

			if (Currency >= Price_To_Improve_Click) {

				Currency -= Price_To_Improve_Click;

				Click_Level++;

				Salary += Salary * 0.75;

				Price_To_Improve_Click += Price_To_Improve_Click * Coefficient_Of_Price_Increase;

				Price_To_Improve_Click = ceil(Price_To_Improve_Click);

			}

			else {

				cout << "Ваших рублей слишком мало!" << endl;

				cout << endl;

				system("pause");

			}
		}
	}

	else if (The_Main_Answer == string("2") || The_Main_Answer == string("Улучшить автоклик") || The_Main_Answer == string("улучшить автоклик") || The_Main_Answer == string("УЛУЧШИТЬ АВТОКЛИК")) {

		cout << "Уровень вашего автоклика " << Autoclick_Level << ". Улучшить до " << Autoclick_Level + 1 << " уровня за " << Price_To_Improve_Autoclick << " рублей?" << endl << endl;

		cout << "1) Да" << endl;

		cout << "2) Нет" << endl;

		cout << endl;

		cin >> Answer_About_Autoclick;

		cout << endl;

		if (Answer_About_Autoclick == string("да") || Answer_About_Autoclick == string("ДА") || Answer_About_Autoclick == string("Да") || Answer_About_Autoclick == string("дА") || Answer_About_Autoclick == string("lf") || Answer_About_Autoclick == string("1") || Answer_About_Autoclick == string("LF") || Answer_About_Autoclick == string("lF") || Answer_About_Autoclick == string("Lf")) {

			if (Currency >= Price_To_Improve_Autoclick) {

				Currency -= Price_To_Improve_Autoclick;

				Autoclick_Level++;

				Price_To_Improve_Autoclick += Price_To_Improve_Autoclick * Coefficient_Of_Price_Increase;

				Price_To_Improve_Autoclick = ceil(Price_To_Improve_Autoclick);

				Number_Of_Rubles_Using_Autoclicker_Per_Second = Number_Of_Rubles_Using_Autoclicker_Per_Second * 1.75;

				if (Autoclick_Level == 1) {

					Amount_Of_Rubles_Per_Second = 1;

					Number_Of_Rubles_Using_Autoclicker_Per_Second = 1;

				}

				else Amount_Of_Rubles_Per_Second *= 1.75;

			}

			else {

				cout << "Ваших рублей слишком мало!" << endl;

				cout << endl;

				system("pause");

			}
		}
	}

	else if (The_Main_Answer == string("3") || The_Main_Answer == string("Улучшить шанс двойной монеты") || The_Main_Answer == string("улучшить шанс двойной монеты") || The_Main_Answer == string("УЛУЧШИТЬ ШАНС ДВОЙНОЙ МОНЕТЫ")) {

		if (Chance_Of_Double_Coins_Level != 100) {

			cout << "Уровень вашего шанса \"двойной монеты\" " << Chance_Of_Double_Coins_Level << ". Улучшить до " << Chance_Of_Double_Coins_Level + 1 << " уровня за " << Price_To_Improve_The_Chance_Of_Double_Coins << " рублей?" << endl << endl;

			cout << "1) Да" << endl;

			cout << "2) Нет" << endl;

			cout << endl;

			cin >> The_Answer_About_The_Chance_Of_A_Double_Coin;

			cout << endl;

			if (Chance_Of_Double_Coins_Level != 100) {

				if (The_Answer_About_The_Chance_Of_A_Double_Coin == string("да") || The_Answer_About_The_Chance_Of_A_Double_Coin == string("ДА") || The_Answer_About_The_Chance_Of_A_Double_Coin == string("Да") || The_Answer_About_The_Chance_Of_A_Double_Coin == string("дА") || The_Answer_About_The_Chance_Of_A_Double_Coin == string("lf") || The_Answer_About_The_Chance_Of_A_Double_Coin == string("1") || The_Answer_About_The_Chance_Of_A_Double_Coin == string("LF") || The_Answer_About_The_Chance_Of_A_Double_Coin == string("lF") || The_Answer_About_The_Chance_Of_A_Double_Coin == string("Lf")) {

					if (Currency >= Price_To_Improve_The_Chance_Of_Double_Coins) {

						Currency -= Price_To_Improve_The_Chance_Of_Double_Coins;

						Chance_Of_Double_Coins_Level++;

						Price_To_Improve_The_Chance_Of_Double_Coins += Price_To_Improve_The_Chance_Of_Double_Coins * Coefficient_Of_Price_Increase;

						Price_To_Improve_The_Chance_Of_Double_Coins = ceil(Price_To_Improve_The_Chance_Of_Double_Coins);

						Chance_Of_Double_Coins++;

					}

					else {

						cout << "Ваших рублей слишком мало!" << endl;

						cout << endl;

						system("pause");

					}
				}
			}
		}

		else {

			cout << "Уровень вашего шанса \"двойной монеты\" 100" << endl << endl;

			system("pause");

		}
	}

	system("cls");

}

void Progress() {

	Number_Of_Completed_Achievements = 0;

	cout << "Нажмите на пробел 1 раз - ";

	if (Number_Of_Clicks_Per_Time >= 1) {

		cout << "выполнено" << " - 100%" << endl;

		Number_Of_Completed_Achievements++;

	}

	else cout << "не выполнено - " << Number_Of_Clicks_Per_Time / 100 << "%" << endl;

	cout << "Нажмите на пробел 10 раз - ";

	if (Number_Of_Clicks_Per_Time >= 10) {

		cout << "выполнено" << " - 100%" << endl;

		Number_Of_Completed_Achievements++;

	}

	else cout << "не выполнено - " << Number_Of_Clicks_Per_Time * 10 << "%" << endl;

	cout << "Нажмите на пробел 100 раз - ";

	if (Number_Of_Clicks_Per_Time >= 100) {

		cout << "выполнено" << " - 100%" << endl;

		Number_Of_Completed_Achievements++;

	}

	else cout << "не выполнено - " << Number_Of_Clicks_Per_Time << "%" << endl;

	cout << "Нажмите на пробел 1000 раз - ";

	if (Number_Of_Clicks_Per_Time >= 1000) {

		cout << "выполнено" << " - 100%" << endl;

		Number_Of_Completed_Achievements++;

	}

	else cout << "не выполнено - " << (double)Number_Of_Clicks_Per_Time / 10 << "%" << endl;

	cout << "Нажмите на пробел 10000 раз - ";

	if (Number_Of_Clicks_Per_Time >= 10000) {

		cout << "выполнено" << " - 100%" << endl;

		Number_Of_Completed_Achievements++;

	}

	else cout << "не выполнено - " << (double)Number_Of_Clicks_Per_Time / 100 << "%" << endl;

	cout << "Нажмите на пробел 100000 раз - ";

	if (Number_Of_Clicks_Per_Time >= 100000) {

		cout << "выполнено" << " - 100%" << endl;

		Number_Of_Completed_Achievements++;

	}

	else cout << "не выполнено - " << (double)Number_Of_Clicks_Per_Time / 1000 << "%" << endl;

	cout << "Нажмите на пробел 1000000 раз - ";

	if (Number_Of_Clicks_Per_Time >= 1000000) {

		cout << "выполнено" << " - 100%" << endl;

		Number_Of_Completed_Achievements++;

	}

	else cout << "не выполнено - " << (double)Number_Of_Clicks_Per_Time / 10000 << "%" << endl;

	cout << endl;

	cout << "Накопите 1 рубль за всё время - ";

	if (Number_Of_Rubles_For_All_Time >= 1) {

		cout << "выполнено - 100%" << endl;

		Number_Of_Completed_Achievements++;

	}

	else cout << "не выполнено - 0%" << endl;

	cout << "Накопите 10 рублей за всё время - ";

	if (Number_Of_Rubles_For_All_Time >= 10) {

		cout << "выполнено - 100%" << endl;

		Number_Of_Completed_Achievements++;

	}

	else cout << "не выполнено - " << Number_Of_Rubles_For_All_Time * 10 << "%" << endl;

	cout << "Накопите 100 рублей за всё время - ";

	if (Number_Of_Rubles_For_All_Time >= 100) {

		cout << "выполнено - 100%" << endl;

		Number_Of_Completed_Achievements++;

	}

	else cout << "не выполнено - " << Number_Of_Rubles_For_All_Time << "%" << endl;

	cout << "Накопите 1000 рублей за всё время - ";

	if (Number_Of_Rubles_For_All_Time >= 1000) {

		cout << "выполнено - 100%" << endl;

		Number_Of_Completed_Achievements++;

	}

	else cout << "не выполнено - " << Number_Of_Rubles_For_All_Time / 10 << "%" << endl;

	cout << "Накопите 10000 рублей за всё время - ";

	if (Number_Of_Rubles_For_All_Time >= 10000) {

		cout << "выполнено - 100%" << endl;

		Number_Of_Completed_Achievements++;

	}

	else cout << "не выполнено - " << Number_Of_Rubles_For_All_Time / 100 << "%" << endl;

	cout << "Накопите 100000 рублей за всё время - ";

	if (Number_Of_Rubles_For_All_Time >= 100000) {

		cout << "выполнено - 100%" << endl;

		Number_Of_Completed_Achievements++;

	}

	else cout << "не выполнено - " << Number_Of_Rubles_For_All_Time / 1000 << "%" << endl;

	cout << "Накопите 1000000 рублей за всё время - ";

	if (Number_Of_Rubles_For_All_Time >= 1000000) {

		cout << "выполнено - 100%" << endl;

		Number_Of_Completed_Achievements++;

	}

	else cout << "не выполнено - " << Number_Of_Rubles_For_All_Time / 10000 << "%" << endl;

	cout << "Накопите 10000000 рублей за всё время - ";

	if (Number_Of_Rubles_For_All_Time >= 10000000) {

		cout << "выполнено - 100%" << endl;

		Number_Of_Completed_Achievements++;

	}

	else cout << "не выполнено - " << Number_Of_Rubles_For_All_Time / 100000 << "%" << endl;

	cout << "Накопите 100000000 рублей за всё время - ";

	if (Number_Of_Rubles_For_All_Time >= 100000000) {

		cout << "выполнено - 100%" << endl;

		Number_Of_Completed_Achievements++;

	}

	else cout << "не выполнено - " << Number_Of_Rubles_For_All_Time / 1000000 << "%" << endl;

	cout << "Накопите 1000000000 рублей за всё время - ";

	if (Number_Of_Rubles_For_All_Time >= 1000000000) {

		cout << "выполнено - 100%" << endl;

		Number_Of_Completed_Achievements++;

	}

	else cout << "не выполнено - " << Number_Of_Rubles_For_All_Time / 10000000 << "%" << endl;

	cout << "Накопите 10000000000 рублей за всё время - ";

	if (Number_Of_Rubles_For_All_Time >= 10000000000) {

		cout << "выполнено - 100%" << endl;

		Number_Of_Completed_Achievements++;

	}

	else cout << "не выполнено - " << Number_Of_Rubles_For_All_Time / 100000000 << "%" << endl;

	cout << "Накопите 100000000000 рублей за всё время - ";

	if (Number_Of_Rubles_For_All_Time >= 100000000000) {

		cout << "выполнено - 100%" << endl;

		Number_Of_Completed_Achievements++;

	}

	else cout << "не выполнено - " << Number_Of_Rubles_For_All_Time / 1000000000 << "%" << endl;

	cout << "Накопите 1000000000000 рублей за всё время - ";

	if (Number_Of_Rubles_For_All_Time >= 1000000000000) {

		cout << "выполнено - 100%" << endl;

		Number_Of_Completed_Achievements++;

	}

	else cout << "не выполнено - " << Number_Of_Rubles_For_All_Time / 10000000000 << "%" << endl;

	cout << "Накопите 10000000000000 рублей за всё время - ";

	if (Number_Of_Rubles_For_All_Time >= 10000000000000) {

		cout << "выполнено - 100%" << endl;

		Number_Of_Completed_Achievements++;

	}

	else cout << "не выполнено - " << Number_Of_Rubles_For_All_Time / 100000000000 << "%" << endl;

	cout << "Накопите 100000000000000 рублей за всё время - ";

	if (Number_Of_Rubles_For_All_Time >= 100000000000000) {

		cout << "выполнено - 100%" << endl;

		Number_Of_Completed_Achievements++;

	}

	else cout << "не выполнено - " << Number_Of_Rubles_For_All_Time / 1000000000000 << "%" << endl;

	cout << "Накопите 1000000000000000 рублей за всё время - ";

	if (Number_Of_Rubles_For_All_Time >= 1000000000000000) {

		cout << "выполнено - 100%" << endl;

		Number_Of_Completed_Achievements++;

	}

	else cout << "не выполнено - " << Number_Of_Rubles_For_All_Time / 10000000000000 << "%" << endl;

	cout << endl;

	cout << "Накопите 1 рубль с помощью автоклика - ";

	if (The_Amount_Of_Rubles_With_Autocliker_For_All_Time >= 1) {

		cout << "выполнено - 100%" << endl;

		Number_Of_Completed_Achievements++;

	}

	else cout << "не выполнено - " << The_Amount_Of_Rubles_With_Autocliker_For_All_Time * 100 << "%" << endl;

	cout << "Накопите 10 рублей с помощью автоклика - ";

	if (The_Amount_Of_Rubles_With_Autocliker_For_All_Time >= 10) {

		cout << "выполнено - 100%" << endl;

		Number_Of_Completed_Achievements++;

	}

	else cout << "не выполнено - " << The_Amount_Of_Rubles_With_Autocliker_For_All_Time * 10 << "%" << endl;

	cout << "Накопите 100 рублей с помощью автоклика - ";

	if (The_Amount_Of_Rubles_With_Autocliker_For_All_Time >= 100) {

		cout << "выполнено - 100%" << endl;

		Number_Of_Completed_Achievements++;

	}

	else cout << "не выполнено - " << The_Amount_Of_Rubles_With_Autocliker_For_All_Time << "%" << endl;

	cout << "Накопите 1000 рублей с помощью автоклика - ";

	if (The_Amount_Of_Rubles_With_Autocliker_For_All_Time >= 1000) {

		cout << "выполнено - 100%" << endl;

		Number_Of_Completed_Achievements++;

	}

	else cout << "не выполнено - " << The_Amount_Of_Rubles_With_Autocliker_For_All_Time / 10 << "%" << endl;

	cout << "Накопите 10000 рублей с помощью автоклика - ";

	if (The_Amount_Of_Rubles_With_Autocliker_For_All_Time >= 10000) {

		cout << "выполнено - 100%" << endl;

		Number_Of_Completed_Achievements++;

	}

	else cout << "не выполнено - " << The_Amount_Of_Rubles_With_Autocliker_For_All_Time / 100 << "%" << endl;

	cout << "Накопите 100000 рублей с помощью автоклика - ";

	if (The_Amount_Of_Rubles_With_Autocliker_For_All_Time >= 100000) {

		cout << "выполнено - 100%" << endl;

		Number_Of_Completed_Achievements++;

	}

	else cout << "не выполнено - " << The_Amount_Of_Rubles_With_Autocliker_For_All_Time / 1000 << "%" << endl;

	cout << "Накопите 1000000 рублей с помощью автоклика - ";

	if (The_Amount_Of_Rubles_With_Autocliker_For_All_Time >= 1000000) {

		cout << "выполнено - 100%" << endl;

		Number_Of_Completed_Achievements++;

	}

	else cout << "не выполнено - " << The_Amount_Of_Rubles_With_Autocliker_For_All_Time / 10000 << "%" << endl;

	cout << "Накопите 10000000 рублей с помощью автоклика - ";

	if (The_Amount_Of_Rubles_With_Autocliker_For_All_Time >= 10000000) {

		cout << "выполнено - 100%" << endl;

		Number_Of_Completed_Achievements++;

	}

	else cout << "не выполнено - " << The_Amount_Of_Rubles_With_Autocliker_For_All_Time / 100000 << "%" << endl;

	cout << "Накопите 100000000 рублей с помощью автоклика - ";

	if (The_Amount_Of_Rubles_With_Autocliker_For_All_Time >= 100000000) {

		cout << "выполнено - 100%" << endl;

		Number_Of_Completed_Achievements++;

	}

	else cout << "не выполнено - " << The_Amount_Of_Rubles_With_Autocliker_For_All_Time / 1000000 << "%" << endl;

	cout << "Накопите 1000000000 рублей с помощью автоклика - ";

	if (The_Amount_Of_Rubles_With_Autocliker_For_All_Time >= 1000000000) {

		cout << "выполнено - 100%" << endl;

		Number_Of_Completed_Achievements++;

	}

	else cout << "не выполнено - " << The_Amount_Of_Rubles_With_Autocliker_For_All_Time / 10000000 << "%" << endl;

	cout << "Накопите 10000000000 рублей с помощью автоклика - ";

	if (The_Amount_Of_Rubles_With_Autocliker_For_All_Time >= 10000000000) {

		cout << "выполнено - 100%" << endl;

		Number_Of_Completed_Achievements++;

	}

	else cout << "не выполнено - " << The_Amount_Of_Rubles_With_Autocliker_For_All_Time / 100000000 << "%" << endl;

	cout << "Накопите 100000000000 рублей с помощью автоклика - ";

	if (The_Amount_Of_Rubles_With_Autocliker_For_All_Time >= 10000000000) {

		cout << "выполнено - 100%" << endl;

		Number_Of_Completed_Achievements++;

	}

	else cout << "не выполнено - " << The_Amount_Of_Rubles_With_Autocliker_For_All_Time / 1000000000 << "%" << endl;

	cout << "Накопите 1000000000000 рублей с помощью автоклика - ";

	if (The_Amount_Of_Rubles_With_Autocliker_For_All_Time >= 1000000000000) {

		cout << "выполнено - 100%" << endl;

		Number_Of_Completed_Achievements++;

	}

	else cout << "не выполнено - " << The_Amount_Of_Rubles_With_Autocliker_For_All_Time / 10000000000 << "%" << endl;

	cout << endl;

	cout << "Получите шанс \"двойной монеты\" в 1% - ";

	if (Chance_Of_Double_Coins >= 1) {

		cout << "выполнено - 100%" << endl;

		Number_Of_Completed_Achievements++;

	}

	else cout << "не выполнено - 0%" << endl;

	cout << "Получите шанс \"двойной монеты\" в 10% - ";

	if (Chance_Of_Double_Coins >= 10) {

		cout << "выполнено - 100%" << endl;

		Number_Of_Completed_Achievements++;

	}

	else cout << "не выполнено - " << Chance_Of_Double_Coins * 10 << "%" << endl;

	cout << "Получите шанс \"двойной монеты\" в 25% - ";

	if (Chance_Of_Double_Coins >= 25) {

		cout << "выполнено - 100%" << endl;

		Number_Of_Completed_Achievements++;

	}

	else cout << "не выполнено - " << Chance_Of_Double_Coins * 4 << "%" << endl;

	cout << "Получите шанс \"двойной монеты\" в 50% - ";

	if (Chance_Of_Double_Coins >= 50) {

		cout << "выполнено - 100%" << endl;

		Number_Of_Completed_Achievements++;

	}

	else cout << "не выполнено - " << Chance_Of_Double_Coins * 2 << "%" << endl;

	cout << "Получите шанс \"двойной монеты\" в 100% - ";

	if (Chance_Of_Double_Coins >= 100) {

		cout << "выполнено - 100%" << endl;

		Number_Of_Completed_Achievements++;

	}

	else cout << "не выполнено - " << Chance_Of_Double_Coins << "%" << endl;

	cout << endl;

	cout << "Купите все предметы - ";

	if (Number_Of_Items_Purchased == Number_Of_Things) {

		cout << "выполнено - 100%";

		Number_Of_Completed_Achievements++;

	}

	else cout << "не выполнено - " << round((Number_Of_Items_Purchased * (double(100) / double(Number_Of_Things))) * 100) / 100 << "%" << endl;

	cout << endl;

	cout << "Выполните все достижения - ";

	if (Number_Of_Completed_Achievements == 42) cout << "выполнено - 100%" << endl;

	else cout << "не выполнено - " << round((Number_Of_Completed_Achievements * (double(100) / double(Number_Of_Achievements))) * 100) / 100 << "%" << endl;

	cout << endl;

	system("pause");

	system("cls");

}

void Set_Cursor(int x, int y) {

	COORD coord;

	coord.X = x;

	coord.Y = y;

	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);

}