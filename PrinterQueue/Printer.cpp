#include "Printer.h"
#include <iostream>
using namespace std;

Printer::Printer(int m)
{
	maxQueueLength = m;
	queue = new int[maxQueueLength];
	pri = new int[maxQueueLength];
	queueLength = 0;
}

Printer::~Printer()
{
	cout << "������� ������� ������" << endl;
	delete[]queue;
	delete[]pri;
}

void Printer::AddPrinting(int c, int p) 
{
	if (!IsFull())//���� � ������� ���� ����.��c��
	{
		queue[queueLength] = c;//����� ���-�� ��������
		pri[queueLength] = p;
		queueLength++;
	}
}

int Printer::Extract()
{
	//���� � ������� ���� ��������, �� ���������� ���, � �������� ��������� ��������� � �������� �������
	if (!IsEmpty()) { //����� ������������ ������� - �������
		int max_pri = pri[0]; //� ������������ ������ = 0
		int pos_max_pri = 0;
		
		for (int i = 1; i < queueLength; i++) //���� ���������
			if (max_pri < pri[i]) { //���� �������� ����� ������������ �������
				max_pri = pri[i];
				pos_max_pri = i;
			}		
		int temp1 = queue[pos_max_pri]; //����������� ������������ �������
		int temp2 = pri[pos_max_pri]; 
		for (int i = pos_max_pri; i < queueLength - 1; i++) {//�������� ��� ��������
			queue[i] = queue[i + 1];
			pri[i] = pri[i + 1];
		}
		queueLength--; //��������� ����������
		return temp1; //������� ������������ ��������
	}
	else return -1;
}

void Printer::ClearPrinting()
{
	queueLength = 0;
}

bool Printer::IsEmpty()
{
	return queueLength==0;//������� 0 ���� �����
}

bool Printer::IsFull()
{
	return queueLength == maxQueueLength;
}

int Printer::GetCount()
{
	return queueLength;//������� ������� ����� �������
}

void Printer::Show()
{
	cout << "\n-----------------------------------\n";
	for (int i = 0; i < queueLength; i++)  //����� ��������� �������
	{
		cout << queue[i] << " - " << pri[i] << "\n\n";
	}
	cout << "\n-----------------------------------\n";
}
