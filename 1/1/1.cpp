// Лабораторная работа 1 по дисциплине МРЗвИС
// Выполнена студентами группы <821702>  <Малявко Е.С, Шишко А.С.>
// Реализация классов конвейера и структуры данных для  двоичных чисел  
// <Версия 1.0>

#include<iostream>
#include"Conveyor.h"

using namespace std;

int main()
{
	setlocale(LC_ALL, "ru");


	Conveyor example({ 2,5,7,4,5,6,7,8,9,1,2,4,5,6,7,8,4,6,7,8 }, { 2,5,7,4,5,6,7,8,9,1,2,4,5,6,7,8,4,6,7,8 });

	example.multiplicationVectors();


	system("pause");
	return 0;
}