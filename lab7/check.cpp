#include"check.h"


// перегрузка операции вывода в поток для переменных типа month
ostream& operator << (ostream& output, const Edu_step& m)
{
	switch (m)
	{
	case Edu_step::Бакалавр: cout << " Бакалавр "; break;
	case Edu_step::Магистратура: cout << " Магистратура "; break;
	case Edu_step::Аспирантура: cout << " Аспирантура "; break;
	default: cout << "Неверный ввод ступени образования!" << endl;
	}
	return output;
}

// проверка названия (предприятия)  
bool isName(string& data)
{
	//перечень допустимых символов
	string str_name(" \":()-абвгдеёжзийклмнопрстуфхцчшщьыэюяАБВГДЕЁЖЗИЙКЛМНОПРСТУФХЦЧШЩЬЫЭЮЯ.WEB,");

	// индекс первого символа, которого не должно быть в строке         
	basic_string <char>::size_type indexCh = -1;

	// Поиск первого символа в строке  my_str, который не является ни одним из элементов строки str_name 
	// Возвращаемое значение - индекс первого символа, который не является элементом строки str_name 
	indexCh = data.find_last_not_of(str_name); // поиск недопустимых символов 
	if ((indexCh != -1) || (data[0] == ' ') || (data[0] == '-'))
		// Строка содержит недопустимые символы или начинается с пробела/дефиса                 
		return false;
	return true;
}

//Условие выбора ступени образования
bool is_Edu_step(Edu_step j)
{
	if (j >= (Edu_step)0 && j <= (Edu_step)2)
		return true;
	return false;
}
