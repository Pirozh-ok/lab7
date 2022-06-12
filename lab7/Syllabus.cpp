#include"Syllabus.h"
#include <cstddef>
#include <iostream>
#include <span>
#include<vector>
#include <algorithm>
//конструктор
Syllabus::Syllabus(int id, string name, string supervisor, Edu_step edu_step)
{
	if (id > 99999)
		this->id = 99999;
	else if (id <= 0)
		this->id = 1;
	else
		this->id = id;

	//добавить проверку isName
	if (isName(name) == true)
		this->name = name;
	else
		this->name = "Нет названия плана.";

	//добавить проверку isName
	if (isName(supervisor) == true)
		this->supervisor = supervisor;
	else
		this->supervisor = "Нет ответственного.";

	if (is_Edu_step(edu_step))
		this->edu_step = edu_step;
	else
		this->edu_step = (Edu_step)0;  //по умолчанию бакалавриат

	count_discipline = 0;
	count_term = 0;
	sum_points = 0;
	if (edu_step == (Edu_step)0)
		this->goal_points = 240;
	else if (edu_step == (Edu_step)1)
		this->goal_points = 139;
	else if (edu_step == (Edu_step)2)
		this->goal_points = 77;

	if (edu_step == (Edu_step)0)
		this->disciplines = 70;
	else if (edu_step == (Edu_step)1)
		this->disciplines = 42;
	else if (edu_step == (Edu_step)2)
		this->disciplines = 19;
	is_active = false;
}

int Syllabus::get_count_term()
{
	return count_term;
}

void Syllabus::set_count_term()
{
	switch (edu_step)
	{
	case Edu_step::Бакалавр:
		count_term = 8;
		break;

	case Edu_step::Магистратура:
		count_term = 4;
		break;

	case Edu_step::Аспирантура:
		count_term = 4;
		break;

	}
}

int Syllabus::get_id()
{
	return id;
}

void Syllabus::set_id(int id)
{
	if (!is_active) //можно редактировать только не введенный в действие
		this->id = id;
}

string Syllabus::get_name()
{
	return name;
}

void Syllabus::set_name(string name)
{
	if (!is_active)
		this->name = name;
}

string Syllabus::get_supervisor()
{
	return supervisor;
}

void Syllabus::set_supervisor(string supervisor)
{
	if (!is_active)
		this->supervisor = supervisor;
}

string Syllabus::get_edu_step()
{
	switch (edu_step)
	{
	case Edu_step::Бакалавр:
		return "Бакалавр";
	case  Edu_step::Магистратура:
		return "Магистратура";
	case  Edu_step::Аспирантура:
		return "Аспирантура";
	}
	return "Бакалавр";
}

void Syllabus::set_edu_step(Edu_step step)
{
	if (!is_active)
		this->edu_step = (Edu_step)step;
}

bool Syllabus::get_status()
{
	return is_active;
}

bool Syllabus::activate()
{
	if (count_discipline != 0 && sum_points != 0 && name.compare("") != 0 && supervisor.compare("") != 0) //проверка что поля заполнены
		if (sum_points == calculate_sum_credits() && (count_term == calculate_sum_term())) //целевое количество совпадает с суммарным
			is_active = true;
	return is_active;
}

bool Syllabus::isUnicDiscipline(Discipline& d)
{

	for (int i = 0; i < count_discipline; i++)
		if (list_disciplines[i].get_name() == d.get_name() && (list_disciplines[i].get_term() == d.get_term()))
		{
			cout << endl << "Дисциплина с таким именем уже существует!" << endl;
			cout << list_disciplines[i];
			return false;
		}


	return true;

}

//добавление дисциплины в файл
void Syllabus::add_discipline()
{
	cout << endl << "Добавление дисциплины..." << endl;
	Discipline d;
	cin >> d;

	if (isUnicDiscipline(d))
	{
		if (edu_step == d.get_step())
		{
			list_disciplines[count_discipline] = d;
			count_discipline++;
			sum_points += d.get_credits();
			cout << "\nДисциплина добавлена!";
			return;
		}
		else cout << "Степень дисциплины и учебного плана не совпадает.";
	} cout << " Дисциплина не добавлена!" << endl;
}

//добавление дисциплины в файл методом
void Syllabus::add_discipline_auto(Discipline d)
{
	cin.ignore(cin.rdbuf()->in_avail()); //очистка входного потока
	if (isUnicDiscipline(d))
	{
		if (edu_step == d.get_step())
		{

			list_disciplines[count_discipline] = d;
			count_discipline++;

			sum_points += d.get_credits();
			cout << "\nДисциплина добавлена!";
			return;
		}
		else cout << "Степень дисциплины и учебного плана не совпадает.";
	} cout << " Дисциплина не добавлена!" << endl;

}

bool myfunction(Discipline i, Discipline j) { return (i.get_term() > j.get_term()); }

struct myclass {
	bool operator() (Discipline i, Discipline j) { return (i.get_term() > j.get_term()); }
} myobject;



void Syllabus::sort_discipline()
{
	//std::sort(list_disciplines.begin(), list_disciplines.end(), myobject);
}

//удаление дисциплины из учебного плана
void Syllabus::remove_discipline()
{
	cout << endl << "Удаление дисциплины..." << endl;
	if (count_discipline > 0)
	{
		string remove_name;
		cout << "Введите название дисциплины для удаления: ";

		getline(cin, remove_name);

		for (int i = 0; i < count_discipline; i++)
		{
			if (list_disciplines[i].get_name() == remove_name)
			{
				for (int j = i; j < count_discipline - 1; j++)
					list_disciplines[j] = list_disciplines[j + 1];

				list_disciplines[count_discipline] = Discipline();
				count_discipline--;
				sum_points = calculate_sum_credits();

				cout << "\nДисциплна удалена!";
				return;
			}
		}
		cout << "\nОшибка удаления дисциплины. Не найдено дисциплины с введёным названием!" << endl;
	}
	else cout << "Ошибка удаления дисциплины. Список дисциплин пуст!" << endl;
}

int Syllabus::calculate_sum_credits()
{
	int sum = 0;
	for (int i = 0; i < count_discipline; i++)
		sum += list_disciplines[i].get_credits();

	return goal_points;
}

int Syllabus::calculate_sum_term()
{
	return count_term;
}

// Перегрузка операции ввода данных об одном учебном плане
istream& operator >> (istream& input, Syllabus& a)
{
	int edu_step, id;
	string name, supervisor;
	do
	{
		cout << "Введите шифр учебного плана: ";
		cin >> id;
		a.set_id(id);
		if (id <= 99999) break;
		cout << "Ошибка при вводе учебного шифра! Учебный шифр может быть не больше шестизначного числа. " << endl;
	} while (1);
	do
	{
		cout << "Введите название учебного плана: ";
		cin.ignore();
		getline(cin, name);
		a.set_name(name);
		if (isName(name) == true)
			break;
		cout << "Ошибка! Введите название учебного плана.";
	} while (1);
	do
	{
		cout << "Введите фамилию ответственного лица: ";
		cin.ignore();
		getline(cin, supervisor);
		a.set_supervisor(supervisor);
		if (isName(supervisor) == true)
			break;
		cout << "Ошибка при вводе фамилии ответственного!" << endl;
	} while (1);
	do
	{
		cout << "Введите ступень образования (0-бакалавариат / 1-магистратура / 2-аспирантура): ";
		cin >> edu_step;

		if (is_Edu_step((Edu_step)edu_step))
		{
			a.set_edu_step((Edu_step)edu_step);
			break;
		}
		cout << "Ошибка при вводе ступени образования!" << endl;
	} while (1);

	a.set_count_term();
	a.activate();
	return input;
}

// Перегрузка операции вывода данных о учебном плане
ostream& operator << (ostream& output, Syllabus& m)
{
	cout << endl << "План #" << m.id << " - " << m.name << endl;
	cout << "Ответственный: " << m.supervisor << endl;
	cout << "Ступень образования: " << m.edu_step << endl;
	cout << "Количество дисциплин: " << m.count_discipline << endl;
	cout << "Количество зачётных единиц: " << m.sum_points << endl;
	cout << "Состояние: ";
	if (m.is_active)
		cout << "ВВЕДЕН В ДЕЙСТВИЕ\n";
	else
		cout << "НЕ АКТИВЕН\n";

	if (m.count_discipline > 0)
	{
		m.sort_discipline();

		cout << "Список дисциплин:" << endl;
		for (int i = m.count_discipline; 0 < i; i--)
			cout << m.count_discipline - i + 1 << ") " << m.list_disciplines[i-1] << endl;
	}
	else cout << "Список дисциплин пуст!" << endl;

	return output;
}
