#include <iostream>
#include"locale.h"
using namespace std;

const int LNAME = 25;

class STUDENT {

private:
	char name[LNAME];      // имя
	int age;                         // возраст
	float grade;                  // рейтинг

public:

	char* GetName() {       // получение имени
		return name;
	}

	int GetAge() const {
		return age;
	}

	float GetGrade() const {
		return grade;
	}

	void SetName(char* valueName) { // установка имени
		char *p = name; // Указатель 
		while (*valueName) { // Пока слово не закончилось
			*p = *valueName; // Присвоить элемент одного элементу другого
			valueName++; // Перейти к следующему элементу
			p++; // Перейти к следующему элементу
		}
		*p = '\0'; // После всего добавить символ конца строки
	}

	void SetAge(int valueAge) {
		age = valueAge;
	}

	void SetGrade(float valueGrade) {
		grade = valueGrade;
	}

	void Set(char *valueName, int valueAge, float valueGrade) {
		char* p = name;
		while (*valueName) {
			*p = *valueName;
			valueName++;
			p++;
		}
		*p = '\0';

		age = valueAge;

		grade = valueGrade;
	}

	void Show() {
		cout << "Имя - " << name << endl << "Возраст - " << age << endl << "Рейтинг - " << grade << endl;
	}

};

int main() {
	setlocale(LC_ALL, "Russian");

	STUDENT a;
	a.SetAge(15);
	a.SetGrade(99.1);
	
	char inputname[LNAME] = "Полина";
	char *invalue = inputname;
	a.SetName(invalue);

	a.Show();

	return 0;
}
