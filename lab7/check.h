#pragma once
#include <iostream>
#include <string>
using namespace std;
const int L = 15;

enum class Edu_step { �������� = 0, ������������ = 1, ����������� = 2 };

// ���������� �������� ������ � ����� ��� ���������� ���� month
ostream& operator << (ostream& output, const Edu_step& m);

// �������� �������� (�����������)  
bool isName(string& data);

//������� ������ ������� �����������
bool is_Edu_step(Edu_step j);
