#pragma once
class Printer
{
	int *queue; //очередь принтера
	int *pri; //приоритет 
	int maxQueueLength;//макс. размер очереди
	int queueLength;//текущ. размер очереди

public:
	Printer(int m);//конструктор 
	~Printer(); //деструктор 
	void AddPrinting(int c, int p);//добавление очереди печати
	int Extract();//извлечение элемента очереди
	void ClearPrinting(); //очистка очереди печати
	bool IsEmpty(); //проверка наличия элементов в очереди
	bool IsFull();//проверка переполнения очереди
	int GetCount();//кол-во элементов в очереди
	void Show();//показать очередь 

};

