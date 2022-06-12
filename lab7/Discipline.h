#pragma once
#include "check.h"
#include <span>

//����� ���������
class Discipline
{
private:
	string name; //�������� ����������
	int credits; //���������� �������� ������ 1�.�. = 36 ������������� �����
	Edu_step edu_step;//������� ����������� (0-����������� 1- ������������ 2- �����������)
	int term; //������� ����������
	
	void set_name(string _name); //���������� �������� ����������
	void set_step(Edu_step step); //���������� ������� ����������
	void set_term(int _term); //���������� �������
	void set_credits(int _credits); //���������� ���-�� �������� ������
public:
	Discipline();
	Discipline(string _name, int _credits, Edu_step _step, int _term); // �����������
	string get_name(); //�������� �������� �������� �����
	// ���������� �������� ����� ������ � ����������
	friend istream& operator >> (istream& input, Discipline& d);
	// ���������� �������� ������ ������ � ����������
	friend ostream& operator << (ostream& output, const Discipline& d);
	
	//string get_name_(); // ������� ��������
	int get_credits(); // ������� ���-�� ���. ��. 
	int get_term();    //������� �������
	Edu_step get_step(); // ������� �������
};
