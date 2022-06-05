#include <iostream>

#include <string> 

#include <Windows.h>

using namespace std;

struct Item {

    Item() {}

    ~Item() {}

    Item& operator=(const Item&other) {
    
        this->determinant = other.determinant;

        this->name = other.name;

        this->price = other.price;

        if (this->determinant){
        
            this->fridge.v = other.fridge.v;

        }

        else {

            this->processor.frequency = other.processor.frequency;

        }

        return *this;

    }

    bool determinant;

        union {

            struct {

                double frequency;

            } processor;

            struct {

                double v;

            } fridge;

        };

    string name;

    double price;

};

Item* addProcessor(Item* item, const int Counter, int& ProcessorCount) {

    Item* newItemList = new Item[Counter + 1];

    for (int i = 0; i < Counter; i++) {

        newItemList[i] = item[i];

    }

    newItemList[Counter].determinant = false;

    cout << "Введите название процессора нового вида: ";

    cin >> newItemList[Counter].name;

    cout << endl;

    cout << "Введите частоту (в МГц) процессора нового вида: ";

    cin >> newItemList[Counter].processor.frequency;

    cout << endl;

    cout << "Введите цену (в рублях) процессора нового вида: ";

    cin >> newItemList[Counter].price;

    cout << endl;

    ProcessorCount++;

    delete[] item;

    item = newItemList;

    return item;

}

Item* addFridge(Item* item, const int Counter, int& FridgeCount) {

    Item* newItemList = new Item[Counter + 1];

    for (int i = 0; i < Counter; i++) {

        newItemList[i] = item[i];

    }

    newItemList[Counter].determinant = true;

    cout << "Введите название холодильника нового вида: ";

    cin >> newItemList[Counter].name;

    cout << endl;

    cout << "Введите объём (в литрах) холодильника нового вида: ";

    cin >> newItemList[Counter].fridge.v;

    cout << endl;

    cout << "Введите цену (в рублях) холодильника нового вида: ";

    cin >> newItemList[Counter].price;

    cout << endl;

    FridgeCount++;

    delete[] item;

    item = newItemList;

    return item;

}

Item* deleteProcessor(Item* item, int Counter, int& ProcessorCount, int n) {

    Item* newItemList = new Item[Counter - 1];

    int k = 0;

    int count = 0;

    for (int i = 0; i < Counter; i++) {

        if (!item[i].determinant) {

            count++;

        }

        if (count == n) {

            count++;

            continue;

        }

        newItemList[k++] = item[i];

    }

    ProcessorCount--;

    delete[] item;

    item = newItemList;

    return item;

}

Item* deleteFridge(Item* item, int Counter, int& FridgeCount, int n) {

    Item* newItemList = new Item[Counter - 1];

    int k = 0;

    int count = 0;

    for (int i = 0; i < Counter; i++) {

        if (item[i].determinant) {

            count++;

        }

        if (count == n) {

            count++;

            continue;

        }

        newItemList[k++] = item[i];

    }

    FridgeCount--;

    delete[] item;

    item = newItemList;

    return item;

}

int main() {
    
    SetConsoleCP(1251);

    SetConsoleOutputCP(1251);

    cout << "Сколько у вас будет видов холодильников: ";

    int FridgeCount;

    cin >> FridgeCount;

    cout << endl;

    cout << "Сколько у вас будет видов процессоров: ";

    int ProcessorCount;

    cin >> ProcessorCount;

    cout << endl;

    Item* item = new Item[FridgeCount + ProcessorCount];

    int FridgeCounterTemp = 1;

    for (int i = 0; i < FridgeCount; i++) {

        system("cls");

        item[i].determinant = true;

        cout << "Введите название " << i + 1 << "-ого холодильника: ";

        cin >> item[i].name;

        cout << endl;

        cout << "Введите объём (в литрах) " << i + 1 << "-ого холодильника: ";

        cin >> item[i].fridge.v;

        cout << endl;

        cout << "Введите цену (в рублях) " << i + 1 << "-ого холодильника: ";

        cin >> item[i].price;

        cout << endl;

    }

    for (int i = FridgeCount; i < ProcessorCount + FridgeCount; i++) {

        system("cls");

        item[i].determinant = false;

        cout << "Введите название " << FridgeCounterTemp << "-ого процессора: ";

        cin >> item[i].name;

        cout << endl;

        cout << "Введите частоту (в МГц) " << FridgeCounterTemp << "-ого процессора: ";

        cin >> item[i].processor.frequency;

        cout << endl;

        cout << "Введите цену (в рублях) " << FridgeCounterTemp++ << "-ого процессора: ";

        cin >> item[i].price;

        cout << endl;

    }

    bool exit = false;

    int choice;

    int n, fCounter, pCounter;

    while (!exit) {

        system("cls");

        fCounter = pCounter = 1;

        cout << "1) Вывести информацию обо всех предметах" << endl;

        cout << "2) Вывести информацию n-ого предмета (холодильник или процессор)" << endl;

        cout << "3) Удалить n-ый вид холодильника" << endl;

        cout << "4) Удалить n-ый вид процессора" << endl;

        cout << "5) Добавить новый вид холодильника" << endl;

        cout << "6) Добавить новый вид процессора" << endl;

        cout << "7) Выйти из программы" << endl << endl;

        cout << "Выберете (от 1 до 7): ";

        cin >> choice;

        system("cls");

        switch (choice) {

        case 1:

            for (int i = 0; i < FridgeCount + ProcessorCount; i++) {

                if (item[i].determinant) {

                    cout << "Название " << fCounter << "-ого холодильника: " << item[i].name;

                    cout << endl;

                    cout << "Объём (в литрах) " << fCounter << "-ого холодильника: " << item[i].fridge.v;

                    cout << endl;

                    cout << "Цена (в рублях) " << fCounter++ << "-ого холодильника: " << item[i].price;

                    cout << endl << endl;

                }
                else {

                    cout << "Название " << pCounter << "-ого процессора: " << item[i].name;

                    cout << endl;

                    cout << "Частота (в МГц) " << pCounter << "-ого процессора: " << item[i].processor.frequency;

                    cout << endl;

                    cout << "Цена (в рублях) " << pCounter++ << "-ого процессора: " << item[i].price;

                    cout << endl << endl;

                }
            }

            system("pause");

            break;

        case 2:

            cout << "Информацию о каком по счёту предмете вы хотите получить: ";

            cin >> n;

            if (n > 0 && n <= FridgeCount + ProcessorCount) {
            
                for (int i = 0; i < n - 1; i++) {
                
                    if (item[i].determinant) { 
                        
                        fCounter++;
                    
                    }

                    else { 
                        
                        pCounter++; 
                    
                    }
                }

                if (item[n - 1].determinant) {

                    cout << "Название " << fCounter << "-ого холодильника: " << item[n - 1].name;

                    cout << endl;

                    cout << "Объём (в литрах) " << fCounter << "-ого холодильника: " << item[n - 1].fridge.v;

                    cout << endl;

                    cout << "Цена (в рублях) " << fCounter << "-ого холодильника: " << item[n - 1].price;

                    cout << endl << endl;

                }

                else {

                    cout << "Название " << pCounter << "-ого процессора: " << item[n - 1].name;

                    cout << endl;

                    cout << "Частота (в МГц) " << pCounter << "-ого процессора: " << item[n - 1].processor.frequency;

                    cout << endl;

                    cout << "Цена (в рублях) " << pCounter << "-ого процессора: " << item[n - 1].price;

                    cout << endl << endl;

                }      
            }

            else {

                cout << "Предмета под таким номером не существует, повторите попытку!" << endl;
            
            }

            system("pause");

            break;

        case 3:

            cout << "Какой по счёту вид холодильника вы хотите удалить: ";

            cin >> n;

            item = deleteFridge(item, FridgeCount + ProcessorCount, FridgeCount, n);

            break;

        case 4:

            cout << "Какой по счёту вид процессора вы хотите удалить: ";

            cin >> n;

            item = deleteProcessor(item, FridgeCount + ProcessorCount, ProcessorCount, n);

            break;

        case 5:

            item = addFridge(item, FridgeCount + ProcessorCount, FridgeCount);

            break;

        case 6:

            item = addProcessor(item, FridgeCount + ProcessorCount, ProcessorCount);

            break;

        case 7:

            exit = true;

            break;

        default:

            cout << "Такого пункта в меню не существует. Повторите попытку!" << endl << endl;

            system("pause");

            break;

        }
    }
}