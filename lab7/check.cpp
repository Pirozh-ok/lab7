#include"check.h"


// ���������� �������� ������ � ����� ��� ���������� ���� month
ostream& operator << (ostream& output, const Edu_step& m)
{
	switch (m)
	{
	case Edu_step::��������: cout << " �������� "; break;
	case Edu_step::������������: cout << " ������������ "; break;
	case Edu_step::�����������: cout << " ����������� "; break;
	default: cout << "�������� ���� ������� �����������!" << endl;
	}
	return output;
}

// �������� �������� (�����������)  
bool isName(string& data)
{
	//�������� ���������� ��������
	string str_name(" \":()-������������������������������������Ũ�������������������������.WEB,");

	// ������ ������� �������, �������� �� ������ ���� � ������         
	basic_string <char>::size_type indexCh = -1;

	// ����� ������� ������� � ������  my_str, ������� �� �������� �� ����� �� ��������� ������ str_name 
	// ������������ �������� - ������ ������� �������, ������� �� �������� ��������� ������ str_name 
	indexCh = data.find_last_not_of(str_name); // ����� ������������ �������� 
	if ((indexCh != -1) || (data[0] == ' ') || (data[0] == '-'))
		// ������ �������� ������������ ������� ��� ���������� � �������/������                 
		return false;
	return true;
}

//������� ������ ������� �����������
bool is_Edu_step(Edu_step j)
{
	if (j >= (Edu_step)0 && j <= (Edu_step)2)
		return true;
	return false;
}
