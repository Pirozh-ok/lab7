#pragma once
#include "check.h"
#include <span>

//класс дисциплин
class Discipline
{
private:
	string name; //название дисциплины
	int credits; //количество зачётных единиц 1з.е. = 36 академических часов
	Edu_step edu_step;//ступень образования (0-бакалавриат 1- магистратура 2- аспирантура)
	int term; //семестр дисциплины
	
	void set_name(string _name); //установить название дисциплины
	void set_step(Edu_step step); //установить степень дисциплины
	void set_term(int _term); //установить семестр
	void set_credits(int _credits); //установить кол-во зачётных единиц
public:
	Discipline();
	Discipline(string _name, int _credits, Edu_step _step, int _term); // конструктор
	string get_name(); //получить название учебного плана
	// Перегрузка операции ввода данных о дисциплине
	friend istream& operator >> (istream& input, Discipline& d);
	// Перегрузка операции вывода данных о дисциплине
	friend ostream& operator << (ostream& output, const Discipline& d);
	
	//string get_name_(); // вернуть название
	int get_credits(); // вернуть кол-во зач. ед. 
	int get_term();    //вернуть семестр
	Edu_step get_step(); // вернуть степень
};
