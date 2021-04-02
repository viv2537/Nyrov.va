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

	//поиск значений, лежащих между позициями дат 01.01.21 и 31.12.21
	auto first = find(e.begin(), e.end(), "01/01/21");
	auto last = find(e.begin(), e.end(), "12/31/21");
	*last = "12/31/21";

	//Построчный вывод дат, начиная с позиции 01.01.21 и до 31.12.21
	copy(first, last,
		ostream_iterator<Date>(cout, "\n"));

	//Добавление текущей даты, определяемой классом Date, в конец вектора
	e.insert(--e.end(), Date::TodayDate());


	//Построчный вывод дат в поток ofDates - не сделано
	//copy(first, last,
	//	ostream_iterator<Date>(ofDates, "\n"));
}
