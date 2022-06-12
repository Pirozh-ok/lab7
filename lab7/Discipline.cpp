#include"Discipline.h"

istream& operator>>(istream& input, Discipline& d)
{
	string _name;
	int edu_step, term, credits;
	do
	{
		cout << "Введите название дисциплины: ";
		cin.ignore(cin.rdbuf()->in_avail()); //очистка входного потока
		getline(cin, _name);
		if (isName(_name) == true)
		{
			d.set_name(_name);
			break;
		}
		cout << "Ошибка! Введите название дисциплины.";
	} while (1);

	do
	{
		cout << "Введите ступень образования (0-бакалавариат / 1-магистратура / 2-аспирантура): ";
		cin >> edu_step;

		if (is_Edu_step((Edu_step)edu_step))
		{
			d.set_step((Edu_step)edu_step);
			break;
		}
		cout << "Ошибка при вводе ступени образования!" << endl;
	} while (1);

	do
	{
		cout << "Введите семестр дисциплины: ";
		cin >> term;
		if (term > 0)
		{
			if (d.get_step() == Edu_step::Бакалавр && term < 15)
			{
				d.set_term(term);
				break;
			}
			else if (d.get_step() == Edu_step::Магистратура && term < 5)
			{
				d.set_term(term);
				break;
			}
			else if (d.get_step() == Edu_step::Аспирантура && term < 5)
			{
				d.set_term(term);
				break;
			}
		}
		cout << "Ошибка при вводе семестра дисциплины!" << endl;
	} while (1);

	do
	{
		cout << "Введите количество зачётных единиц по дисциплине: ";
		cin >> credits;

		if (credits > 0 && credits < 10)
		{
			d.set_credits(credits);
			break;
		}
		cout << "Ошибка при вводе количества зачётных единиц по дисциплине!";
	} while (1);
	return input;
}

ostream& operator<<(ostream& output, const Discipline& d)
{
	cout << d.name << ": " << d.term << " семестр, " << d.credits << " зачётных единиц, ступень образования - " << d.edu_step;
	return output;
}



Edu_step Discipline::get_step()
{
	return edu_step;
}

void Discipline::set_name(string _name)
{
	this->name = _name;
}

void Discipline::set_step(Edu_step step)
{
	this->edu_step = step;
}

void Discipline::set_term(int _term)
{
	this->term = _term;
}

string Discipline::get_name()
{
	return name;
}

int Discipline::get_credits()
{
	return credits;
}

int Discipline::get_term()
{
	return term;
}

void Discipline::set_credits(int _credits)
{
	credits = _credits;
}

Discipline::Discipline()
{
	name = "";
	credits = 0;
	edu_step = Edu_step::Бакалавр;
	term = 1;
}

Discipline::Discipline(string _name, int _credits, Edu_step _step, int _term)
{
	name = isName(_name) ? _name : "Название дисциплины";
	credits = _credits > 0 ? _credits : 0;
	edu_step = _step;
	term = _term > 0 ? _term : 1;
}



