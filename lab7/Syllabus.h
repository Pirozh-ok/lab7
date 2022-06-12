#pragma once
#include "Discipline.h"
//#include <array>
#include "array.h"
const int K = 100;

//класс описывающий ”чебный план
class Syllabus
{
private:
	int id; //шифр
	string name; //название
	string supervisor; //фио ответственного
	Edu_step edu_step;//ступень образовани€
	int goal_points; // оличество «.≈. по плану
	int disciplines; // оличество дисциплин по плану
	int sum_points; //суммарное количество зачЄтных единиц за все дисциплины
	bool is_active; //состо€ние - введен ли в действие
	int count_term; //количество семестров в учебном плане
	Array<Discipline, K> list_disciplines; //перечень дисциплин
	int count_discipline; //количество добавленных дисциплин
	void set_count_term(); //установить количество семестров
public:
	Syllabus(int id = 1, string name = " ", string supervisor = " ", Edu_step edu_step = (Edu_step)0);
	int get_count_term(); //получить количество семестров в учебном плане
	int get_id(); //получить идентификатор учебного плана
	void set_id(int id); //установка идентификатора учебного плана
	string get_name(); //получить название учебного плана
	void set_name(string name); //установить название
	string get_supervisor(); //получить фамилию ответственного
	void set_supervisor(string supervisor); //установить ответственного
	string get_edu_step(); //получить степень
	void set_edu_step(Edu_step step); //установить степень
	bool get_status(); //узнать состо€ние
	bool activate(); //ввести план в действие
	// ѕерегрузка операции ввода данных о учебном плане
	friend istream& operator >> (istream& input, Syllabus& a);
	// ѕерегрузка операции вывода данных о учебном плане
	friend ostream& operator << (ostream& output, Syllabus& m);
	void add_discipline(); // добавить дисциплину в учебный план
	void remove_discipline(); // удалить дисциплину
	int calculate_sum_credits(); //посчитать и вернуть общую сумму зачЄтных единиц в учебном плане
	int calculate_sum_term(); // посчитать и вернуть количество семестров
	int calculate_sum_step(); //посчитать и вернуть ступень образовани€

	bool isUnicDiscipline(Discipline& d); //провер€ет название дисциплины на уникальность
	void add_discipline_auto(Discipline d); // добавить дисциплину в учебный план методом
	void sort_discipline(); //сортировка дисциплин по семестрам
};