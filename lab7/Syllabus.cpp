#include"Syllabus.h"
#include <cstddef>
#include <iostream>
#include <span>
#include<vector>
#include <algorithm>
//�����������
Syllabus::Syllabus(int id, string name, string supervisor, Edu_step edu_step)
{
	if (id > 99999)
		this->id = 99999;
	else if (id <= 0)
		this->id = 1;
	else
		this->id = id;

	//�������� �������� isName
	if (isName(name) == true)
		this->name = name;
	else
		this->name = "��� �������� �����.";

	//�������� �������� isName
	if (isName(supervisor) == true)
		this->supervisor = supervisor;
	else
		this->supervisor = "��� ��������������.";

	if (is_Edu_step(edu_step))
		this->edu_step = edu_step;
	else
		this->edu_step = (Edu_step)0;  //�� ��������� �����������

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
	case Edu_step::��������:
		count_term = 8;
		break;

	case Edu_step::������������:
		count_term = 4;
		break;

	case Edu_step::�����������:
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
	if (!is_active) //����� ������������� ������ �� ��������� � ��������
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
	case Edu_step::��������:
		return "��������";
	case  Edu_step::������������:
		return "������������";
	case  Edu_step::�����������:
		return "�����������";
	}
	return "��������";
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
	if (count_discipline != 0 && sum_points != 0 && name.compare("") != 0 && supervisor.compare("") != 0) //�������� ��� ���� ���������
		if (sum_points == calculate_sum_credits() && (count_term == calculate_sum_term())) //������� ���������� ��������� � ���������
			is_active = true;
	return is_active;
}

bool Syllabus::isUnicDiscipline(Discipline& d)
{

	for (int i = 0; i < count_discipline; i++)
		if (list_disciplines[i].get_name() == d.get_name() && (list_disciplines[i].get_term() == d.get_term()))
		{
			cout << endl << "���������� � ����� ������ ��� ����������!" << endl;
			cout << list_disciplines[i];
			return false;
		}


	return true;

}

//���������� ���������� � ����
void Syllabus::add_discipline()
{
	cout << endl << "���������� ����������..." << endl;
	Discipline d;
	cin >> d;

	if (isUnicDiscipline(d))
	{
		if (edu_step == d.get_step())
		{
			list_disciplines[count_discipline] = d;
			count_discipline++;
			sum_points += d.get_credits();
			cout << "\n���������� ���������!";
			return;
		}
		else cout << "������� ���������� � �������� ����� �� ���������.";
	} cout << " ���������� �� ���������!" << endl;
}

//���������� ���������� � ���� �������
void Syllabus::add_discipline_auto(Discipline d)
{
	cin.ignore(cin.rdbuf()->in_avail()); //������� �������� ������
	if (isUnicDiscipline(d))
	{
		if (edu_step == d.get_step())
		{

			list_disciplines[count_discipline] = d;
			count_discipline++;

			sum_points += d.get_credits();
			cout << "\n���������� ���������!";
			return;
		}
		else cout << "������� ���������� � �������� ����� �� ���������.";
	} cout << " ���������� �� ���������!" << endl;

}

bool myfunction(Discipline i, Discipline j) { return (i.get_term() > j.get_term()); }

struct myclass {
	bool operator() (Discipline i, Discipline j) { return (i.get_term() > j.get_term()); }
} myobject;



void Syllabus::sort_discipline()
{
	//std::sort(list_disciplines.begin(), list_disciplines.end(), myobject);
}

//�������� ���������� �� �������� �����
void Syllabus::remove_discipline()
{
	cout << endl << "�������� ����������..." << endl;
	if (count_discipline > 0)
	{
		string remove_name;
		cout << "������� �������� ���������� ��� ��������: ";

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

				cout << "\n��������� �������!";
				return;
			}
		}
		cout << "\n������ �������� ����������. �� ������� ���������� � ������� ���������!" << endl;
	}
	else cout << "������ �������� ����������. ������ ��������� ����!" << endl;
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

// ���������� �������� ����� ������ �� ����� ������� �����
istream& operator >> (istream& input, Syllabus& a)
{
	int edu_step, id;
	string name, supervisor;
	do
	{
		cout << "������� ���� �������� �����: ";
		cin >> id;
		a.set_id(id);
		if (id <= 99999) break;
		cout << "������ ��� ����� �������� �����! ������� ���� ����� ���� �� ������ ������������� �����. " << endl;
	} while (1);
	do
	{
		cout << "������� �������� �������� �����: ";
		cin.ignore();
		getline(cin, name);
		a.set_name(name);
		if (isName(name) == true)
			break;
		cout << "������! ������� �������� �������� �����.";
	} while (1);
	do
	{
		cout << "������� ������� �������������� ����: ";
		cin.ignore();
		getline(cin, supervisor);
		a.set_supervisor(supervisor);
		if (isName(supervisor) == true)
			break;
		cout << "������ ��� ����� ������� ��������������!" << endl;
	} while (1);
	do
	{
		cout << "������� ������� ����������� (0-������������ / 1-������������ / 2-�����������): ";
		cin >> edu_step;

		if (is_Edu_step((Edu_step)edu_step))
		{
			a.set_edu_step((Edu_step)edu_step);
			break;
		}
		cout << "������ ��� ����� ������� �����������!" << endl;
	} while (1);

	a.set_count_term();
	a.activate();
	return input;
}

// ���������� �������� ������ ������ � ������� �����
ostream& operator << (ostream& output, Syllabus& m)
{
	cout << endl << "���� #" << m.id << " - " << m.name << endl;
	cout << "�������������: " << m.supervisor << endl;
	cout << "������� �����������: " << m.edu_step << endl;
	cout << "���������� ���������: " << m.count_discipline << endl;
	cout << "���������� �������� ������: " << m.sum_points << endl;
	cout << "���������: ";
	if (m.is_active)
		cout << "������ � ��������\n";
	else
		cout << "�� �������\n";

	if (m.count_discipline > 0)
	{
		m.sort_discipline();

		cout << "������ ���������:" << endl;
		for (int i = m.count_discipline; 0 < i; i--)
			cout << m.count_discipline - i + 1 << ") " << m.list_disciplines[i-1] << endl;
	}
	else cout << "������ ��������� ����!" << endl;

	return output;
}
