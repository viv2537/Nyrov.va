#include "idc_date.h"

#include <vector>
#include <iterator>

int main()
{
	//Объявление вектора для хранения дат
	vector<Date> e;

	//Чтение даты из потока ввода в вектор
	copy(istream_iterator<Date>(cin),
		istream_iterator<Date>(),
		back_inserter(e)); // Добавление введённой даты в конец вектора

	//поиск значений, принадлежащих к 21 году
	auto first = find(e.begin(), e.end(), "01/01/21");
	auto last = find(e.begin(), e.end(), "12/31/21");
	*last = "12/31/21";

	//Построчный вывод дат, принадлежащих к 21 году из вектора
	copy(first, last,
		ostream_iterator<Date>(cout, "\n"));

	//Добавление текущей даты, определяемой классом Date, в конец вектора
	e.insert(--e.end(), Date::TodayDate());

	//Построчный вывод дат, принадлежащих к 21 году из вектора
	//в поток ofDates ????
	copy(first, last,
		ostream_iterator<Date>(ofDates, "\n"));
}
