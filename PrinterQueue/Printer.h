#pragma once
class Printer
{
	int *queue; //������� ��������
	int *pri; //��������� 
	int maxQueueLength;//����. ������ �������
	int queueLength;//�����. ������ �������

public:
	Printer(int m);//����������� 
	~Printer(); //���������� 
	void AddPrinting(int c, int p);//���������� ������� ������
	int Extract();//���������� �������� �������
	void ClearPrinting(); //������� ������� ������
	bool IsEmpty(); //�������� ������� ��������� � �������
	bool IsFull();//�������� ������������ �������
	int GetCount();//���-�� ��������� � �������
	void Show();//�������� ������� 

};

