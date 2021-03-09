#include <iostream>
#include <clocale>
#include <string>

using namespace std;

class Student {
private:
    int age{};
    string name{};
    string surname{};
    string phone{};
    char group{};
    int grades[10];
public:
	Student() {
		cout << "Объект был создан" << endl;
	} // Конструктор по умолчанию

	Student(int age, char group) {
		this->age = age > 5 ? age : 5; // age равно age если оно больше 5, если нет, то приравниваем к 5
		this->group = group;
	}

	Student(int age, string name, string surname, string phone, char group) {
		this->age = age > 5 ? age : 5; // age равно age если оно больше 5, если нет, то приравниваем к 5
		this->name = name;
        this->surname = surname;
        this->phone = phone;
        this->group = group;
	}

	void setGrade(int value, int index) {
		if(index < 0 || index >=10)
			return;

		this->grades[index] = value;
	}

	int getGrade(int index) {
		if(index < 0 || index >=10)
			return 0;

		return this->grades[index];
	}

    void setAll (string name, string surname, string phone) {
        this->name = name;
        this->surname = surname;
        this->phone = phone;
        cout << this->name << " " << this->surname << ". Телефон: " << this->phone << endl;
    }

    void setAll (int age, string surname, string phone) {
        this->age = age;
        this->surname = surname;
        this->phone = phone;
    }

    void printAll() {
        cout << this->name << " " << this->surname << ". Возраст: " << this->age << endl;
    }

    ~Student() {
    	cout << "Объект был удалён" << endl;
    }

};

int main()
{
    setlocale(LC_ALL, "Russian");

    Student alex(24, 'C');
    alex.setAll(24, "Alex", "Martini");
    alex.setGrade(5, 2);
    cout << alex.getGrade(2) << endl;
    alex.printAll();

    Student jhon(21, "Jhon", "Marley", "+79995554433", 'C');
    jhon.setAll("Jhon", "Marley", "+79995554433");
    jhon.printAll();

    return 0;
}

