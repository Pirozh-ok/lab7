#include "Syllabus.h"
#include <Windows.h>
#include "Discipline.h"

int main()
{
    //������ ��� ������������
    //�������� ��������
    string name_bakal[70] = { "����������� ����", "������� (������� ������, �������� �������)", "�������������� ������", "�������� �������", "�����������", "������ ��������� ������������", "�������� ������� � ������� ����", "�������� � ��������", "���������� �������� � �����", "������� ��������: ��������������� ��������", 
        "����������� ����", "�������������� ������", "������", "������ ������������ � �������������� ����������", "������ ��������� ������������", "���������� ����������", "����������������", "���������� �������� � �����",
        "����������� ����", "���������", "������", "������ ��������� ������������", "��������������", "������������", "����������������", "������ �������������� ������������", "������������ �������", "���������� �������� � �����",
        "������ ��������� �����������", "�����������", "������������ �������", "������������ �����������������", "�������������� ����", "���������� � ������ ����������������", "������������ �������", "�������������� ����������", "�������������", "���������� �������� � �����",
        "���� ������", "�������������� ����", "����������� ������� �������������� �������", "��������� ������", "������������ ����������������", "�������� ����� � ����������������", "��������� � ���������� ����������������� ���������", "���������� ����������������� ���������", "������� ��������: ��������������� (�������� - ���������������) ��������", 
        "������������", "��������� �����������������", "��������� � ��������� ������", "������ ���������� ������ � ������������", "WEB-����������������", "���������� ������-��������� ����������", "������ � �������� ������������", "������ ��������������� ������", "���������� �������� � �����", "�������� � ������������ ������", "��������� ������������",
        "��������� \"������� - ����������� �������������� ������\"", "������� �������������� ����������", "����������� ���������", "������ ������� ������", "������� �������������� ���������� � �������� ��������", "���������� �������������", "����������� ����������� �������������� ������", "���������� �������� � �����",
        "���������� ���������", "��������� ���� � ��������� ����������", "���������������� ��������: ������������� (���������������(�������� - ���������������)) ��������", "���������� � ������ ��������� ���������������� ������"};
    //�������� �������
    int goal_points_bakal[70] = { 2, 3, 7, 4, 5, 2, 2, 1, 1, 3, 3, 6, 5, 4, 2, 4, 5, 1, 5, 3, 3, 2, 4, 3, 4, 3, 3, 0, 3, 4, 4, 3, 3, 4, 3, 3, 3, 0, 5, 4, 4, 3, 3, 3, 3, 1, 3, 3, 3, 3, 5, 5, 3, 3, 3, 0, 1, 2, 3, 3, 6, 6, 4, 3, 6, 0, 3, 3, 14, 9};
    //�������
    int term_bakal[70] = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 2,2,2,2,2,2,2,2,3,3,3,3,3,3,3,3,3,3,4,4,4,4,4,4,4,4,4,4,5,5,5,5,5,5,5,5,5,6,6,6,6,6,6,6,6,6,6,6,7,7,7,7,7,7,7,7,8,8,8,8};
    //������ ��� ������������
    //�������� ��������
    string name_magistr[42] = {"�������������� �������", "���������� ���������� ������������ �����������", "���������������� �������", "����������� ����", "���������", "������ ������ � ��������� ������", "������������ ���������� ������� � ��������� ������", "������ ������-����������������� ������������. ������� �������", "������� ��������: ��������������� ��������", "���������������� ��������: ������ - ����������������� ������", "������� ������������� �������������",
        "�������������� �������", "���������� ���������� ������������ �����������", "����������� ����", "������ ����������� � �������� ��������� �������", "������������� ��������� � ��������", "������ ������-����������������� ������������. ������� �������", "�������������� �������������� ������� � ���� ������", "�������������� ����������", "���������� � ������������ �������������� ������", "���������� �����������", "�������������� � ������� �������������� ���������", "������� ��������: ��������������� (�������� - ���������������) ��������", "���������������� ��������:������ - ����������������� ������", "������ �������������� ��������-�������� ������",
        "����������� ��������� ������", "������������ � ������ ���������� � �������������� ��������", "������������ ������ � ���������", "������� ������������� ������", "�������������� �������������� ������� ����� ������", "���������� ���������", "�������������� � ������� �������������� ����������", "�������������� ��������� � ������������� �������������� ������ � ����������", "���������������� ��������:������ - ����������������� ������", "������������� ��������� ������",
        "���������������� ������ ������ � ������ ��������� ��������", "������� �������������� ����������", "����������� ������� � �� ����������", "���������������� ��������: ��������������� (�������� - ���������������) ��������", "���������������� ��������: ������������� ��������(������ - ����������������� ������)", "���������� � ������ ��������� ���������������� ������", "������������"};
    //�������� �������
    int goal_points_magistr[42] = {3,2,5,3,3,3,3,2,3,3,3,3,3,2,3,3,1,3,3,3,3,2,3,3,2,3,3,5,5,2,3,4,4,5,2,3,3,3,6,9,9};
    //�������
    int term_magistr[42] = {1,8,1,1,1,1,1,1,1,1,1,2,2,2,2,2,2,2,2,2,2,2,2,2,2,3,3,3,3,3,3,3,3,3,3,4,4,4,4,4,4};

    //������ ��� �����������
    //�������� ��������
    string name_asp[19] = {"������ �������������� ������������ � ������� ������� �����������", "����������� ���� (������)", "����������� ���� � ���������������� ������������",
        "������� � ��������� �����", "����������� ���� (������)", "����������� ����", "�������������� ��������", 
        "�������������� �������������, ��������� ������ � ��������� ��������(������)", "����������� ����� �����������", "�������������� ��������", "����������� ���������������� ������������", "����������� ����",
        "�������������� �������������, ��������� ������ � ��������� ��������(������)", "�������� ���������� ����������� ���������� ��� ������� ����� �������������� ������", "����������� ���������������� ������������",
        "�������������� �������������, ��������� ������ � ��������� ��������(������)", "������ ��������� ����� ��� ������� ������� ����� �������������� ������",
        "���������� � ����� � ����� ���������������� ��������", "������������� �������� ������� �� �������� ����������� �������������� ������ - ���������������� ������(�����������)"};
    //�������� �������
    int goal_points_asp[19] = {3,6,6,2,4,4,2,3,3,3,3,2,6,6,3,6,6,3,6};
    //�������
    int term_asp[19] = {1,1,1,2,2,2,2,3,3,3,3,3,4,4,4,5,5,8,8};


    int n, i = 0;
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    setlocale(LC_ALL, "Russian");
    Syllabus a1{ 11178, "����������� � �������������� ������� ", "���������� �. �.", (Edu_step)0 };
    Syllabus a2{ 11178, "����������� � �������������� ������� ", "���������� �. �.", (Edu_step)0};
    cout << a1;
    
    //���������� ���������
    //a1.add_discipline();
    //a1.add_discipline();
    cout << "�������� ���� ��� ������� �����������(0-������������ / 1-������������ / 2-�����������) " << endl;
    cin >> n;
    //��������, �.�., ������� �����������, �������
    
    
    //���� ������������
    if (n == 0)
    {
        for (string y : name_bakal)
        {
            a1.add_discipline_auto({ y, goal_points_bakal[i], (Edu_step)0, term_bakal[i]});
            i++;
        }
    }
    //���� ������������
    else if (n == 1)
    {
        for (string y : name_magistr)
        {
            a1.add_discipline_auto({ y, goal_points_magistr[i], (Edu_step)1, term_magistr[i] });
            i++;
        }
    }
    //���� �����������
    else if (n == 2)
    {
        for (string y : name_asp)
        {
            a1.add_discipline_auto({ y, goal_points_asp[i], (Edu_step)2, term_asp[i] });
            i++;
        }
   }


    //�������� ����������
    //a1.remove_discipline();
    cout << a1;
    
    //������ ���� � ��������
    //�������� ������ ����  ��������� ������� �����������??
    a1.activate();
    cout << a1;
}