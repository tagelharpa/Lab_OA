#include <string>
#include "Student.h"

Student::Student(void) : Human()
{
	rate = 0;
}
Student::~Student(void)
{
}
Student::Student(string n, int a, float r) :Human(n, a)
{
	rate = r;

}
Student::Student(const Student& s)
{
	name = s.name;
	age = s.age;
	rate = s.rate;
}
void Student::Set_rate(float r)
{
	rate = r;
}

Student& Student::operator=(const Student& s)
{
	if (&s == this)return *this;
	name = s.name;
	age = s.age;
	rate = s.rate;

	return *this;
}

void Student::Show()
{
	cout << "\nEnter_Name : " << name;
	cout << "\nEnter_Age : " << age;
	cout << "\nEnter_Rate : " << rate;
	cout << "\n";
}

void Student::Input()
{
	cout << "\nEnter_Name : "; cin >> name;
	cout << "\nEnter_Age : "; cin >> age;
	cout << "\nEnter_Rate : "; cin >> rate;
}
