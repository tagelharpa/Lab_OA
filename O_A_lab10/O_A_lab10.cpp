#include <iostream>
#include <string>
#include "time_class.h"
#include "time_funcs.h"

int main()
{
	setlocale(LC_ALL, "Russian");
	std::cout << "\nВведите файл для работы: ";
	std::string filename;
	std::cin >> filename;

	int x = 0;
	do {
		std::cout << "\n\nМеню:\n"
			<< "1. Добавить в файл\n"
			<< "2. Распечатать\n"
			<< "3. Удалить значения\n"
			<< "4. Увеличить +1:30\n"
			<< "5. Вставить значения\n"
			<< "0. Выход\n"
			<< ">> ";

		std::cin >> x;
		switch (x) {
		case 0: break;
		case 1: add_to_end(filename); break;
		case 2: print(filename); break;
		case 3: delete_values(filename); break;
		case 4: increment_values(filename); break;
		case 5: insert_after(filename); break;
		default: std::cout << "Неверно ввел дурень!\n";
		}

	} while (x != 0);

	return 0;
}
