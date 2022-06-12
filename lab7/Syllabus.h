#pragma once
#include "Discipline.h"
//#include <array>
#include "array.h"
const int K = 100;

//����� ����������� ������� ����
class Syllabus
{
private:
	int id; //����
	string name; //��������
	string supervisor; //��� ��������������
	Edu_step edu_step;//������� �����������
	int goal_points; //���������� �.�. �� �����
	int disciplines; //���������� ��������� �� �����
	int sum_points; //��������� ���������� �������� ������ �� ��� ����������
	bool is_active; //��������� - ������ �� � ��������
	int count_term; //���������� ��������� � ������� �����
	Array<Discipline, K> list_disciplines; //�������� ���������
	int count_discipline; //���������� ����������� ���������
	void set_count_term(); //���������� ���������� ���������
public:
	Syllabus(int id = 1, string name = " ", string supervisor = " ", Edu_step edu_step = (Edu_step)0);
	int get_count_term(); //�������� ���������� ��������� � ������� �����
	int get_id(); //�������� ������������� �������� �����
	void set_id(int id); //��������� �������������� �������� �����
	string get_name(); //�������� �������� �������� �����
	void set_name(string name); //���������� ��������
	string get_supervisor(); //�������� ������� ��������������
	void set_supervisor(string supervisor); //���������� ��������������
	string get_edu_step(); //�������� �������
	void set_edu_step(Edu_step step); //���������� �������
	bool get_status(); //������ ���������
	bool activate(); //������ ���� � ��������
	// ���������� �������� ����� ������ � ������� �����
	friend istream& operator >> (istream& input, Syllabus& a);
	// ���������� �������� ������ ������ � ������� �����
	friend ostream& operator << (ostream& output, Syllabus& m);
	void add_discipline(); // �������� ���������� � ������� ����
	void remove_discipline(); // ������� ����������
	int calculate_sum_credits(); //��������� � ������� ����� ����� �������� ������ � ������� �����
	int calculate_sum_term(); // ��������� � ������� ���������� ���������
	int calculate_sum_step(); //��������� � ������� ������� �����������

	bool isUnicDiscipline(Discipline& d); //��������� �������� ���������� �� ������������
	void add_discipline_auto(Discipline d); // �������� ���������� � ������� ���� �������
	void sort_discipline(); //���������� ��������� �� ���������
};