// ������������ ������ 1 �� ���������� ������
// ��������� ���������� ������ <821702>  <������� �.�, ����� �.�.>
// ���������� ������� ��������� � ��������� ������ ���  �������� �����  
// <������ 1.0>

#include"Conveyor.h"

BinaryNumber::BinaryNumber(int decimalNumber) //����������� ��� �������� �����
{
	for (int i = 0; i < this->BitDepthOfNumbers; i++)
	{
		this->valueInputVector[i] = 0;
	}

	int counter = this->BitDepthOfNumbers - 1;

	while (decimalNumber)
	{
		if (decimalNumber % 2 == 1)
		{
			this->valueInputVector[counter] = 1;
		}
		else
		{
			this->valueInputVector[counter] = 0;
		}

		counter--;

		decimalNumber /= 2;

	}

	for (int i = 0; i < this->BitDepthOfNumbers * 2; i++)
	{
		this->valueOutputVector[i] = 0;
	}

}

int BinaryNumber::binaryToDecimalBy8digit() //������� 8 �������� �������� ����� � ����������
{
	int temp = 0;

	for (int i = this->BitDepthOfNumbers * 2 - 1, k = 0; i >= 0; i--, k++)
	{
		if (this->valueOutputVector[i])
		{
			temp += pow(2, k);
		}
	}


	return temp;
}

int BinaryNumber::binaryToDecimalBy4digit() //������� 4 �������� �������� ����� � ����������
{
	int temp = 0;

	for (int i = this->BitDepthOfNumbers - 1, k = 0; i >= 0; i--, k++)
	{
		if (this->valueInputVector[i])
		{
			temp += pow(2, k);
		}
	}


	return temp;
}

void Conveyor::sum(int shift, BinaryNumber stepBinaryNumber, int elementCounter) //����� ���������� ������������ 
{
	/// ������� ����� ����� �����

	BinaryNumber tempwww(0);

	for (int i = BinaryNumber::BitDepthOfNumbers * 2 - 1; i >= 4; i--)
	{
		tempwww.valueOutputVector[i - shift] = stepBinaryNumber.valueOutputVector[i];
	}

	bool transfer = false;

	for (int i = BinaryNumber::BitDepthOfNumbers * 2 - 1; i >= 0; i--)
	{
		if (this->resultantVector[elementCounter].valueOutputVector[i] == 1 && tempwww.valueOutputVector[i] == 1 && transfer == false)
		{
			transfer = true;

			this->resultantVector[elementCounter].valueOutputVector[i] = 0;

		}

		if (this->resultantVector[elementCounter].valueOutputVector[i] == 1 && tempwww.valueOutputVector[i] == 1 && transfer == true)
		{
			transfer = true;

			this->resultantVector[elementCounter].valueOutputVector[i] = 1;

		}

		if (this->resultantVector[elementCounter].valueOutputVector[i] == 0 && tempwww.valueOutputVector[i] == 0 && transfer == true)
		{
			transfer = false;

			this->resultantVector[elementCounter].valueOutputVector[i] = 1;

		}

		if (this->resultantVector[elementCounter].valueOutputVector[i] == 0 && tempwww.valueOutputVector[i] == 0 && transfer == false)
		{
			transfer = false;

			this->resultantVector[elementCounter].valueOutputVector[i] = 0;

		}

		if (this->resultantVector[elementCounter].valueOutputVector[i] == 1 && tempwww.valueOutputVector[i] == 0 && transfer == false)
		{
			transfer = false;

			this->resultantVector[elementCounter].valueOutputVector[i] = 1;

		}

		if (this->resultantVector[elementCounter].valueOutputVector[i] == 0 && tempwww.valueOutputVector[i] == 1 && transfer == false)
		{
			transfer = false;

			this->resultantVector[elementCounter].valueOutputVector[i] = 1;

		}

		if (this->resultantVector[elementCounter].valueOutputVector[i] == 1 && tempwww.valueOutputVector[i] == 0 && transfer == true)
		{
			transfer = true;

			this->resultantVector[elementCounter].valueOutputVector[i] = 0;

		}

		if (this->resultantVector[elementCounter].valueOutputVector[i] == 0 && tempwww.valueOutputVector[i] == 1 && transfer == true)
		{
			transfer = true;

			this->resultantVector[elementCounter].valueOutputVector[i] = 0;
		}
	}

	this->A[elementCounter].status = false;
}

void Conveyor::multiplication(int elementCounter, int curentBelement) // ����������� ��� ���� ����� �� ������� � �� 1 ��� �������������� ����� �� ������� �
{
	for (int bitCounter = BinaryNumber::BitDepthOfNumbers - 1, stepNumber = 0; bitCounter >= 0; bitCounter--, stepNumber++)
	{
		this->stepMultiplication[elementCounter].valueOutputVector[BinaryNumber::BitDepthOfNumbers * 2 - 1 - stepNumber] = this->A[elementCounter].valueInputVector[bitCounter] * this->B[elementCounter].valueInputVector[curentBelement];
	}

	this->A[elementCounter].status = true;
}

void Conveyor::showStepMultiplication(int tact, int currentPairOfNumbers, int currentBelement, bool isFirstStepInTact)// ���������� ��������� ��������� ����� �� ������� � �� 1 ��� �������������� ����� �� ������� �
{
	if (isFirstStepInTact)
	{
		cout << "Tacts:" << tact << ";";
	}

	cout << " Pair[" << currentPairOfNumbers << "] " << "Step result mul: ";;

	for (int i = 0; i < BinaryNumber::BitDepthOfNumbers * 2; i++)
	{
		cout << this->stepMultiplication[currentPairOfNumbers].valueOutputVector[i];

		if (i == 3)
		{
			cout << "-";
		}
	}
	cout << ";" << "\t";

}

void Conveyor::showStepSum(int tact, int currentPairOfNumbers, int currentBelement, bool isFirstStepInTact) //���������� �������� ����� ���������� ������������ 
{
	if (isFirstStepInTact)
	{
		cout << "Tacts:" << tact << ";";
	}

	cout << " Pair[" << currentPairOfNumbers << "] " << "Step result sum: ";

	for (int i = 0; i < BinaryNumber::BitDepthOfNumbers * 2; i++)
	{
		cout << this->resultantVector[currentPairOfNumbers].valueOutputVector[i];
		if (i == 3)
		{
			cout << "-";
		}
	}

	cout << ";" << "\t";
}

void Conveyor::showResult(int tacts) // ������� �������� ��������� 
{
	for (int i = 0; i < this->resultantVector.size(); i++)
	{
		cout << "Tacts for number [" << tacts - this->resultantVector.size() + 1 << "]  " << "Result: " << this->resultantVector[i].binaryToDecimalBy8digit() << "\n";

		tacts++;
	}

}

void Conveyor::showElementsAtBegin()// ������� �������� �������� ��������
{
	for (int i = 0; i < this->A.size(); i++)
	{
		cout << "Pair of numbers decimial [" << i << "]" << "\t" << this->A[i].binaryToDecimalBy4digit() << "\t" << this->B[i].binaryToDecimalBy4digit() << "\n";
	}

	cout << "\n";

	for (int i = 0; i < this->A.size(); i++)
	{
		cout << "Pair of numbers binary [" << i << "]" << "\t";
		for (int j = 0; j < BinaryNumber::BitDepthOfNumbers; j++)
		{
			cout << this->A[i].valueInputVector[j];
		}
		cout << "\t";

		for (int j = 0; j < BinaryNumber::BitDepthOfNumbers; j++)
		{
			cout << this->B[i].valueInputVector[j];
		}

		cout << "\n";
	}
	cout << "\n";
}

void Conveyor::multiplicationVectors()// ����� ������������ �������� 
{
	int tacts = 0;

	int processingElements = 0;// �������������� �������� 

	int currentBelement = BinaryNumber::BitDepthOfNumbers - 1;

	this->showElementsAtBegin();

	while (!this->isFinish)
	{

		bool isFirstStepInTact = true;

		tacts++;

		bool isTactFinish = false;

		if (processingElements < this->A.size()) // "���������" �� �������� �� ��� �������
		{
			processingElements++;
		}

		int elementCounter = processingElements - 1;

		int copyCurrentBelemet = currentBelement;

		while (!isTactFinish)
		{
			if (this->A[elementCounter].status)// ������ ���� ������ ��������� �� ���� � ��� ���� ������� ������ ��� ������ ��������� ���� � �� ������ ���������� 
			{
				this->sum(BinaryNumber::BitDepthOfNumbers - 1 - copyCurrentBelemet, this->stepMultiplication[elementCounter], elementCounter);

				this->showStepSum(tacts, elementCounter, currentBelement, isFirstStepInTact);

				if (elementCounter == this->A.size() - 1 && copyCurrentBelemet == 0)
				{
					this->isFinish = true;

					cout << "\n" << "\n";

					this->showResult(tacts);
				}

				if (elementCounter == this->A.size() - 1)// ����� ���������� ��������� ������� ������� �� ���������� ��� �������� �
				{
					currentBelement--;
				}

				copyCurrentBelemet--;

				elementCounter--;
			}
			else
			{
				if (copyCurrentBelemet >= 0)
				{
					this->multiplication(elementCounter, copyCurrentBelemet);

					this->showStepMultiplication(tacts, elementCounter, copyCurrentBelemet, isFirstStepInTact);
				}

				elementCounter--;
			}

			if (elementCounter == -1)// ���� ���������� ��� ������� ������� �� ����� ������ ���� ��������;
			{
				isTactFinish = true;

				cout << "\n" << "\n";
			}

			isFirstStepInTact = false;

		}
	}
}


Conveyor::Conveyor(vector<int> A, vector<int> B) //����������� ��������� 
{
	for (int i = 0; i < A.size(); i++)
	{
		this->A.push_back(BinaryNumber(A[i]));
		this->B.push_back(BinaryNumber(B[i]));
	}

	for (int i = 0; i < A.size(); i++)
	{
		this->resultantVector.push_back(BinaryNumber(0));
		this->stepMultiplication.push_back(BinaryNumber(0));
	}
}