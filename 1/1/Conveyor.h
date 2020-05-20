#pragma once

// Лабораторная работа 1 по дисциплине МРЗвИС
// Выполнена студентами группы <821702>  <Малявко Е.С, Шишко А.С.>
// Реализация классов конвейера и структуры данных для  двоичных чисел  
// <Версия 1.0>

#include<vector>
#include<iostream>
#include<algorithm>

using namespace std;


class BinaryNumber
{
public:

	bool status = false;

	int valueInputVector[4];

	int valueOutputVector[8];

	static const int BitDepthOfNumbers = 4; // разрядность чисел 

	BinaryNumber(int decimalNumber);

	int binaryToDecimalBy8digit();

	int binaryToDecimalBy4digit();
};


class Conveyor {

	vector <BinaryNumber> A;

	vector <BinaryNumber> B;

	vector<BinaryNumber> stepMultiplication;

	vector <BinaryNumber> resultantVector;

	bool isFinish = false;

	void sum(int shift, BinaryNumber stepBinaryNumber, int elementCounter);

	void multiplication(int elementCounter, int curentBelement);

	void showStepMultiplication(int tact, int currentPairOfNumbers, int currentBelement, bool isFirstStepInTact);

	void showStepSum(int tact, int currentPairOfNumbers, int currentBelement, bool isFirstStepInTact);

	void showResult(int tacts);

	void showElementsAtBegin();

public:

	void multiplicationVectors();

	Conveyor(vector<int> A, vector<int> B);
};