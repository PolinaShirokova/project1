#include <iostream>
#include <vector>
#include <Windows.h>
#include <string>

using namespace std;

class book {
public:
    string Title;
    unsigned int Year;           //год издания
    vector <string> Authors;
    string Publisher;           //издательство
    unsigned int Pages;         //количество страниц
    book() { };
    book(string Title, unsigned int Year, vector <string> Authors, string Publisher, unsigned int Pages) {
        this->Title = Title;
        this->Year = Year;
        this->Authors = Authors;
        this->Publisher = Publisher;
        this->Pages = Pages;
    }
    book(book& basis) {
        Title = basis.Title; Authors = basis.Authors; Year = basis.Year; Publisher = basis.Publisher; Pages = basis.Pages;
    };

    void ShowAllBook() {
        cout << "Название книги: " << Title << endl << "Год издания: " << Year << endl << "Автор: ";
        for (int i = 0; i < Authors.size(); i++) cout << Authors[i] << endl;
        cout << "Издательство: " << Publisher << endl << "Kоличество страниц: " << Pages << endl;
    };
};
struct reader {
    string name;
    string date;
    reader(string name, string date) {
        this->name = name;
        this->date = date;
    }
};
class cathalog_book : public book {
public:
    unsigned int ID;
    unsigned int Quantity;      //Общее количество экземпляров
    unsigned int Instances;     //Количество экземпляров в наличии
    vector<reader>Picked;       //Список читателей, взявших книгу, с датой выдачи
    cathalog_book(unsigned int ID, unsigned int Quantity, unsigned int Instances, vector<reader>Picked) {
        this->ID = ID;
        this->Instances = Instances;
        this->Picked = Picked;
        this->Quantity = Quantity;
    }
    void ShowCathalog() {
        cout << "ID: " << ID << endl << "Количество экземпляров: " << Quantity << endl;
        cout << "Экземпляров в наличии: " << Instances << endl << "Список читателей, взявших книгу: " << endl;
        for (int a = 0; a < Picked.size(); a++) cout <<  "Имя: " << Picked[a].name << endl << "Дата: " << Picked[a].date << endl;
    }
};
book* cbook(string Title, unsigned int Year, vector <string> Authors, string Publisher, unsigned int Pages) {
    return new book(Title, Year, Authors, Publisher, Pages); // Создание книги и возвращение указателя
}
cathalog_book* bbook(unsigned int ID, unsigned int Quantity, unsigned int Instances, vector<reader>Picked) {
    return new cathalog_book(ID, Quantity, Instances, Picked); // Создание книги в каталоге и возвращение указателя
}


int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    vector <book*> allbook = {
         new book("Сказка обо мне", 2022, {"Полина"}, "Москва моя", 120),
         new book("Сказка обо мне", 2022, {"Пол"}, "Москва моя", 120)
    };
    vector <cathalog_book*> cathalog = {
         new cathalog_book(0, 50, 49, { reader("Полинка", "2022") })
    };



    bool ran = true;
    int a, nomer;
    string title, publisher, author;
    vector <string> authors;
    unsigned int ID;
    unsigned int Quantity;      //Общее количество экземпляров
    unsigned int Instances;     //Количество экземпляров в наличии
    vector<reader>Picked;
    unsigned int year, pages, anume;
    string name, date;
    bool proverka = false;
    while (ran) {
        system("cls");
        cout << "Выберите один из пунктов меню" << endl;
        cout << "1 - вывести все книги из списка\n";
        cout << "2 - удалить книгу из списка\n";
        cout << "3 - создать книгу в списке \n";
        cout << "4 - информация по книге и читателях, взявших книгу\n";
        cout << "5 - вывести все книги из каталога\n";
        cout << "6 - добавить книгу в каталог\n";
        cout << "7 - удалить книгу из каталога\n";
        cout << "8 - поиск книги в каталоге\n";
        cout << "9 - выдача книги\n";
        cout << "10 - возврат книги\n";
        //cout << "11 - список читателей, не вернувших книгу в течение года\n";

        cout << endl << "Введите пункт: "; cin >> a;
        switch (a) {
        case 1:
            for (int i = 0; i < allbook.size(); i++) {
                cout << "ID книги :" << i << endl;
                (*allbook[i]).ShowAllBook();
                cout << endl;
            }; break;
        case 2:
            cout << "ID книги :";
            cin >> nomer;
            allbook.erase(allbook.begin() + nomer);
            break;
        case 3:
            cout << "Название: "; cin >> title;
            cout << "Автор: ";
            cin >> author;
            authors.push_back(author);
            cout << "Год: "; cin >> year;
            cout << "Издательство: "; cin >> publisher;
            cout << "Страницы: "; cin >> pages;
            allbook.push_back(cbook(title, year, authors, publisher, pages));
            break;
        case 4:
            unsigned int ID;
            cout << "Номер книги: ";
            cin >> ID;
            if (cathalog.size() > ID)
                (*cathalog[ID]).ShowCathalog();
            else
                cout << "такого ID нет в списке , введите другой";
            break;
        case 5:
            for (int i = 0; i < cathalog.size(); i++) {
                //cout << "Номер книги :" << i << endl;
                (*cathalog[i]).ShowCathalog();
                cout << endl;
            };
            break;
        case 6:
            cout << "Номер книги: "; cin >> ID;
            cout << "Количество экземпляров: "; cin >> Quantity;
            cout << "Экземпляров в наличии: "; cin >> Instances;
            cathalog.push_back(bbook(ID, Quantity, Instances, Picked));
            break;
        case 7:
            cout << "ID книги :";
            cin >> nomer;
            for (int i = 0; i < cathalog.size(); i++) {
                if ((*cathalog[i]).ID == nomer)
                    cathalog.erase(cathalog.begin() + i);
            }
            cout << "Ваша книга удалена!";
            //cathalog.erase(cathalog.begin() + nomer);
            // Циклом for пройтись по всеи элементам списка cathalog
            // if cathalog[i].ID == nomer, то erase текущий элемент
            break;
        case 8:
            cout << "ID книги :";
            cin >> nomer;
            for (int i = 0; i < cathalog.size(); i++) {
                if ((*cathalog[i]).ID == nomer)
                    (*cathalog[i]).ShowCathalog();
            }
            break;
        case 9:
            cout << "ID книги: "; cin >> nomer;
            for (int i = 0; i < cathalog.size(); i++) {
                if ((*cathalog[i]).ID == nomer) proverka = true;
                if (!proverka) cout << "такого ID нет в каталоге";
                else {
                    cout << "Имя: "; cin >> name;
                    cout << "Дата: "; cin >> date;
                    (*cathalog[i]).Picked.push_back(reader(name, date));
                    (*cathalog[i]).Instances -= 1;
                }
            }
            break;
        case 10:
            cout << "ID книги: "; cin >> nomer;
            cout << "Имя взявшего: "; cin >> name;
            for (int i = 0; i < cathalog.size(); i++) {
                if ((*cathalog[i]).ID == nomer) {
                    for (int i = 0; i < (*cathalog[nomer]).Picked.size(); i++) {
                        if ((*cathalog[nomer]).Picked[i].name == name) {
                            (*cathalog[nomer]).Picked.erase((*cathalog[nomer]).Picked.begin() + i);
                            (*cathalog[nomer]).Instances += 1;
                        }
                    }
                }
            }
            break;
        }
        system("pause");
    }
    return 0;
}
