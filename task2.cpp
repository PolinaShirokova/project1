#include <iostream>
#include <string>
#include <Windows.h>
#include <vector>
using namespace std;

class Employee {

private:

    static int count;    //Количество сотрудников
    string organization; // место работы
    string position;     // должность 
    double experience;   //стаж 
    string name;
    char gender;        // м или ж
    int age;
    double salary;           //зарплата
    double allSalary = 0;    // счёт 

public:

    void AddSalary() { allSalary += salary; } // начисление зарплаты 
    void operator()(string valuePosition) {  // изменение должности
        position = valuePosition;
    }
    void operator[](double valueSalary) { // изменение зарплаты
        salary = valueSalary;
    }

    void SetPersonalDate(string valueName, char valueGender, int valueAge) {
        name = valueName;
        gender = valueGender;
        age = valueAge;
    }
    void ShowPersonalData() {
        cout << "Имя: " << name << endl << "Пол: " << gender << endl << "Возраст: " << age << endl;
    }

    void ShowAllDate() {
        cout << "Имя: " << name << endl << "Пол: " << gender << endl << "Возраст: " << age << endl;
        cout << "Место работы: " << organization << endl << "Должность: " << position << endl << "Стаж работы: " << experience << " years" << endl;
        cout << "Заработная плата: " << salary << endl << "Начисленная зарплата(счёт): " << allSalary << endl;
    }

    Employee(string valueName, char valueGender, int valueAge, string valueOrganization, string valuePosition, double valueExperience, double valueSalary) {
        name = valueName;
        gender = valueGender;
        age = valueAge;
        organization = valueOrganization;
        position = valuePosition;
        experience = valueExperience;
        salary = valueSalary;
        count++;
    }
  
    static int GetCount(){ return count; }
};

int Employee::count = 0;

int main() {

    setlocale(LC_ALL, "Russian");
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    vector <Employee> allPeople = {
        Employee("Виктор", 'м', 23, "Сбербанк", "менеджер", 2, 40000),
        Employee("Алина", 'ж', 19, "Шоколадница", "официант", 1, 25000),
        Employee("Денис", 'м', 28, "Яндекс", "программист", 5, 95000)
    };

    int a, Nomer, sum, NewSalary;
    string newjob;
    cout << "Выберите один из пунктов меню" << endl;
    cout << "1 - вывести количество сотрудников\n";
    cout << "2 - все данные о сотруднике\n";
    cout << "3 - изменить должность\n";
    cout << "4 - начислить заработную плату\n";
    cout << "5 - изменить заработную плату\n";
    cout << "6 - вывод личных данных\n";
    cout << "7 - данные о всех сотрудников\n";

    bool ran = true;
    while (ran) {
        cout << endl << "Введите пункт: "; cin >> a;
        switch (a) {
        case 1: 
            cout << allPeople[0].GetCount() << " - количество сотрудников\n";
            break;
        case 2:
            cout << "Выберите сотрудника: "; 
            cin >> Nomer;
            cout << "Номер сотрудника: " << Nomer << endl << endl;
            allPeople[Nomer - 1].ShowAllDate();
            break; 
        case 3: 
            cout << "Выберите сотрудника:\n"; cin >> Nomer;
            cout << "Введите должность: "; cin >> newjob;
            allPeople[Nomer - 1](newjob);  
            break; 
        case 4: 
            cout << "Введите номер сотрудника: "; cin >> Nomer;
            allPeople[Nomer - 1].AddSalary();
            cout << "Зарплата начислилась на счёт!\n";
            break;
        case 5: 
            cout << "Введите номер сотрудника: "; cin >> Nomer;
            cout << "Введите новую заработную плату: "; cin >> NewSalary;
            allPeople[Nomer - 1][NewSalary];
            break;
        case  6:
            cout << "Введите номер сотрудника: "; cin >> Nomer;
            allPeople[Nomer - 1].ShowPersonalData();
            break;
        case 7:
            for (int i = 1; i <= allPeople.size(); i++) {
                cout << endl << "Номер сотрудника: " << i << endl;
                allPeople[i - 1].ShowAllDate();
            }
            break;

        default: { ran = false; };
        }
    }
    return 0;
}
