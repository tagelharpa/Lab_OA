#include "Vector.h"
#include <iostream>

using namespace std;

void print_error(int x);

int main()
{
	//контролируемый блок
	try
	{

		Vector x(2);//вектор из двух элементов
		Vector y;//пустой вектор
		cout << x;//печать вектора х
		cout << "Number:";
		int i;
		cin >> i;
		//вывод элемента с номером i, если номер больше 2 или меньше 0, то
		//генерируется исключительная ситуация
		cout << x[i] << endl;
		//добавление элемента в вектор, если MAX_SIZE=2, то генерируется
		//исключительная ситуация
		y = x + 3;
		cout << y;
		//удалить один элемент из вектора
		x = x - 1;
		cout << x;
		//удалить один элемент из вектора
		x = x - 1;
		cout << x;//вектор пустой
		//удалить один элемент из вектора
		//генерируется исключительная ситуация
		x = x - 1;
	}
	//обработчик исключения
	catch (int x)
	{
		cout << "ERROR!!!" << endl;
		print_error(x);
	}//сообщение об ошибке

	std::cin.ignore();
	std::cin.get();
	return 0;
}

void print_error(int x)
{
	switch (x) {
	case 1: std::cout << "Given size is greater than MAX_SIZE\n"; break;
	case 2: std::cout << "Index is less than 0\n"; break;
	case 3: std::cout << "Index out of range\n"; break;
	case 4: std::cout << "Can't delete values\n"; break;
	case 5: std::cout << "Size is less than given for delete\n"; break;
	}
}
