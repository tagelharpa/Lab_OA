#include <iostream>
#include <fstream>
#include <string>
#include <stdio.h>
#include "time_class.h"
#include "time_funcs.h"

void add_to_end(const std::string& filename)
{
	std::ofstream out(filename, std::ios::out | std::ios::app);
	if (!out.is_open()) {
		std::cout << "Не получается открыть " << filename << "!\n";
		return;
	}

	std::cout << "Введите кол-во объектов Time: ";
	int n;
	std::cin >> n;

	for (int i = 0; i < n; ++i) {
		std::cout << "Time #" << i + 1 << ":\n";
		Time t;
		std::cin >> t;

		out << t;
	}
}

void print(const std::string& filename)
{
	std::ifstream in(filename);
	if (!in.is_open()) {
		std::cout << "Не получается открыть " << filename << "!\n";
		return;
	}

	Time t;
	std::cout << "Файлы " << filename << " Time которые есть:\n";
	while (in >> t) {
		std::cout << t << "\n";
	}
}

void delete_values(const std::string& filename)
{
	std::ifstream in(filename);
	if (!in.is_open()) {
		std::cout << "Не получается открыть " << filename << "!\n";
		return;
	}

	std::string tempfile = "temp.txt";
	std::ofstream temp(tempfile);

	std::cout << "Введите значение Time для удаления:\n";
	Time del_t;
	std::cin >> del_t;

	Time t;
	while (in >> t) {
		if (t != del_t)
			temp << t;
	}

	in.close();
	temp.close();
	std::remove(filename.c_str());
	std::rename(tempfile.c_str(), filename.c_str());
}

void increment_values(const std::string& filename)
{
	std::ifstream in(filename);
	if (!in.is_open()) {
		std::cout << "Не получается открыть " << filename << "!\n";
		return;
	}

	std::string tempfile = "temp.txt";
	std::ofstream temp(tempfile);

	std::cout << "Суммированное время:\n";
	Time t;
	while (in >> t) {
		std::cout << t << " + " << Time(1, 30) << " = " << t + Time(1, 30) << "\n";
		temp << t + Time(1, 30);
	}

	in.close();
	temp.close();
	std::remove(filename.c_str());
	std::rename(tempfile.c_str(), filename.c_str());
}

void insert_after(const std::string& filename)
{
	std::ifstream in(filename);
	if (!in.is_open()) {
		std::cout << "Не получается открыть " << filename << "!\n";
		return;
	}

	std::string tempfile = "temp.txt";
	std::ofstream temp(tempfile);

	std::cout << "Введите количество новых объектов времени: ";
	int k;
	std::cin >> k;

	std::cout << "Введите индекс для вставки: ";
	int n;
	std::cin >> n;

	Time t;
	while ((n > 0) && (in >> t)) {
		temp << t;
		--n;
	}

	for (int i = 0; i < k; ++i) {
		std::cin >> t;
		temp << t;
	}

	while (in >> t)
		temp << t;

	in.close();
	temp.close();
	std::remove(filename.c_str());
	std::rename(tempfile.c_str(), filename.c_str());
}
