#include <vector>
#include <iostream>
#include <iomanip>
#include <random>
#include <string>

typedef std::vector<double> my_vector;

void print_vector(my_vector& vec, const std::string& message);
void fill_vector(my_vector& vec);
void add_max_to_begin(my_vector& vec);
void erase_min(my_vector& vec);
void inc_average(my_vector& vec);

int main()
{
	setlocale(LC_ALL, "Russian");
	my_vector vec;

	fill_vector(vec);
	print_vector(vec, "\nНачальный вектор: ");

	add_max_to_begin(vec);
	print_vector(vec, "\nМаксимальный объект добавлен в начало: ");

	erase_min(vec);
	print_vector(vec, "\nУдаляется минимальный объект: ");

	inc_average(vec);
	print_vector(vec, "\nСреднее арифметическое для объектов: ");

	std::cin.ignore();
	std::cin.get();
	return 0;
}

void print_vector(my_vector& vec, const std::string& message)
{
	std::cout << message << "\n" << std::setprecision(3) << std::fixed;
	for (size_t i = 0; i < vec.size(); ++i)
		std::cout << vec[i] << " ";
	std::cout << "\n";
}

void fill_vector(my_vector& vec)
{
	std::cout << "Введите количество элементов: ";
	int n;
	std::cin >> n;

	std::random_device rd;
	std::uniform_real_distribution<double> distr(0, 1);
	for (int i = 0; i < n; ++i)
		vec.push_back(distr(rd));
}

void add_max_to_begin(my_vector& vec)
{
	double max = vec[0];
	for (size_t i = 0; i < vec.size(); ++i)
	{
		if (vec[i] > max)
			max = vec[i];
	}
	vec.insert(vec.begin(), max);
}

void erase_min(my_vector& vec)
{
	my_vector::iterator min = vec.begin();
	for (my_vector::iterator it = vec.begin(); it != vec.end(); ++it)
	{
		if (*it < *min)
			min = it;
	}
	vec.erase(min);
}

void inc_average(my_vector& vec)
{
	double avg = 0;
	for (size_t i = 0; i < vec.size(); ++i)
		avg += vec[i];
	avg /= vec.size();

	std::cout << "Среднее значение: " << avg << "\n";
	for (size_t i = 0; i < vec.size(); ++i)
		vec[i] += avg;
}
