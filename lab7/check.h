#pragma once
#include <iostream>
#include <string>
using namespace std;
const int L = 15;

enum class Edu_step { Бакалавр = 0, Магистратура = 1, Аспирантура = 2 };

// перегрузка операции вывода в поток для переменных типа month
ostream& operator << (ostream& output, const Edu_step& m);

// проверка названия (предприятия)  
bool isName(string& data);

//Условие выбора ступени образования
bool is_Edu_step(Edu_step j);
