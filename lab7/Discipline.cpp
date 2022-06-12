#include"Discipline.h"

istream& operator>>(istream& input, Discipline& d)
{
	string _name;
	int edu_step, term, credits;
	do
	{
		cout << "������� �������� ����������: ";
		cin.ignore(cin.rdbuf()->in_avail()); //������� �������� ������
		getline(cin, _name);
		if (isName(_name) == true)
		{
			d.set_name(_name);
			break;
		}
		cout << "������! ������� �������� ����������.";
	} while (1);

	do
	{
		cout << "������� ������� ����������� (0-������������ / 1-������������ / 2-�����������): ";
		cin >> edu_step;

		if (is_Edu_step((Edu_step)edu_step))
		{
			d.set_step((Edu_step)edu_step);
			break;
		}
		cout << "������ ��� ����� ������� �����������!" << endl;
	} while (1);

	do
	{
		cout << "������� ������� ����������: ";
		cin >> term;
		if (term > 0)
		{
			if (d.get_step() == Edu_step::�������� && term < 15)
			{
				d.set_term(term);
				break;
			}
			else if (d.get_step() == Edu_step::������������ && term < 5)
			{
				d.set_term(term);
				break;
			}
			else if (d.get_step() == Edu_step::����������� && term < 5)
			{
				d.set_term(term);
				break;
			}
		}
		cout << "������ ��� ����� �������� ����������!" << endl;
	} while (1);

	do
	{
		cout << "������� ���������� �������� ������ �� ����������: ";
		cin >> credits;

		if (credits > 0 && credits < 10)
		{
			d.set_credits(credits);
			break;
		}
		cout << "������ ��� ����� ���������� �������� ������ �� ����������!";
	} while (1);
	return input;
}

ostream& operator<<(ostream& output, const Discipline& d)
{
	cout << d.name << ": " << d.term << " �������, " << d.credits << " �������� ������, ������� ����������� - " << d.edu_step;
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
	edu_step = Edu_step::��������;
	term = 1;
}

Discipline::Discipline(string _name, int _credits, Edu_step _step, int _term)
{
	name = isName(_name) ? _name : "�������� ����������";
	credits = _credits > 0 ? _credits : 0;
	edu_step = _step;
	term = _term > 0 ? _term : 1;
}



