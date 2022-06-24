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
	cout << "Очистка очереди печати" << endl;
	delete[]queue;
	delete[]pri;
}

void Printer::AddPrinting(int c, int p) 
{
	if (!IsFull())//если в очереди есть своб.меcто
	{
		queue[queueLength] = c;//новое кол-во значений
		pri[queueLength] = p;
		queueLength++;
	}
}

int Printer::Extract()
{
	//Если в очереди есть элементы, то возвращаем тот, у которого наивысший приоритет и сдвигаем очередь
	if (!IsEmpty()) { //пусть приоритетный элемент - нулевой
		int max_pri = pri[0]; //а приоритетный индекс = 0
		int pos_max_pri = 0;
		
		for (int i = 1; i < queueLength; i++) //ищем приоритет
			if (max_pri < pri[i]) { //если встречен более приоритетный элемент
				max_pri = pri[i];
				pos_max_pri = i;
			}		
		int temp1 = queue[pos_max_pri]; //вытаскиваем приоритетный элемент
		int temp2 = pri[pos_max_pri]; 
		for (int i = pos_max_pri; i < queueLength - 1; i++) {//сдвинуть все элементы
			queue[i] = queue[i + 1];
			pri[i] = pri[i + 1];
		}
		queueLength--; //уменьшаем количество
		return temp1; //возврат извлеченного элемента
	}
	else return -1;
}

void Printer::ClearPrinting()
{
	queueLength = 0;
}

bool Printer::IsEmpty()
{
	return queueLength==0;//вернуть 0 если пусто
}

bool Printer::IsFull()
{
	return queueLength == maxQueueLength;
}

int Printer::GetCount()
{
	return queueLength;//вернуть текущую длину очереди
}

void Printer::Show()
{
	cout << "\n-----------------------------------\n";
	for (int i = 0; i < queueLength; i++)  //вывод элементов очереди
	{
		cout << queue[i] << " - " << pri[i] << "\n\n";
	}
	cout << "\n-----------------------------------\n";
}
