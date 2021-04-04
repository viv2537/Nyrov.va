Date::Date(const char * date)
{

	//////////////////////////////////////////////
	//         Проверка корректности даты
	//////////////////////////////////////////////


	// Число дней по месяцам
	short NumberDays[12] = { 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };//отсутствует проверка високосности года



	// Проверка формата строки ввода
	if (strlen(date) == 8)
	{
		if (date[2] != '/' && date[5] != '/')
		{
			std::cerr << "invalid date format, need MM/DD/YY\nThis value will not be read " << '\n';
		}

		// Проверка на нечисловые символы
		else 
		if (date[0] >= '0' && date[0] <= '9' &&
			date[1] >= '0' && date[0] <= '9' &&
			date[3] >= '0' && date[0] <= '9' &&
			date[4] >= '0' && date[0] <= '9' &&
			date[6] >= '0' && date[0] <= '9' &&
			date[7] >= '0' && date[0] <= '9')
		{
			// Получение числовых значений месяца и дня
			int month = ((int)date[0] - '0') * 10 + (int)date[1] - '0';
			int day = ((int)date[3] - '0') * 10 + (int)date[4] - '0';

			// Проверка значения месяца
			if (month > 12 || month == 0)
			{
				std::cerr << "Invalid month value. Must be 1 to 12.\nDate format is MM/DD/YY\nThis value will not be read " << '\n';
			}

			// Проверка значения дня
			else if (day > NumberDays[month - 1] || day == 0)
			{
				std::cerr << "Invalid day value. Must be 1 to 28-31\nThis value will not be read " << '\n';
			}

			else
			{
				//////////////////////////////////////////////
				//         Перевод входной строки в ISO
				//////////////////////////////////////////////

				// Дата формата YYYY-MM-DD
				this->date = "2000-00-00";

				// Получение года
				for (int i = 2; i < 4; i++)
					this->date[i] = date[i + 4];


				// Получение месяца
				for (int i = 5; i < 7; i++)
					this->date[i] = date[i - 5];


				// Получение дня
				for (int i = 8; i < 10; i++)
					this->date[i] = date[i - 5];
			}
		}
		else std::cerr << "Value has non-numeric symbols\nThis value will not be read " << '\n';
	}
	else std::cerr << "Invalid date length, need 8\nThis value will not be read " << '\n';

};
