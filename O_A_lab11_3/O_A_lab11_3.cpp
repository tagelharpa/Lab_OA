#include <iostream>

#include "my_vector_11_3.h"
#include "time_class.h"

int main()
{
	setlocale(LC_ALL, "Russian");
	std::cout << "Номер элемента: ";
	int n;
	std::cin >> n;

	MyVector<Time> vec(n);
	vec.print("Начальный вектор: ");

	vec.add_max_to_begin();
	vec.print("Максимальный объект добавлен в начало: ");

	vec.erase_min();
	vec.print("Удаляется минимальный объект: ");

	vec.inc_average();
	vec.print("Среднее арифмитеческое для объектов: ");

	std::cin.ignore();
	std::cin.get();
	return 0;
}
