//Solution: DataContainers
//Project: ForwardList
#include<iostream>
using std::cin;
using std::cout;
using std::endl;

#define tab "\t"

class Element {
	int Data; //�������� ��������
	Element* pNext;//����� ���������� ��������
public:
	Element(int Data, Element* pNext = nullptr) : Data(Data), pNext(pNext)
	{
		cout << "EConstructor:\t" << this << endl;
	}
	~Element()
	{
		cout << "EDestructor:\t" << this << endl;
	}
	friend class ForwardList;
};

class ForwardList
{
	Element* Head;	//��������� �� ��������� ������� ������
	//�������� ������ ����� � ������
public:
	ForwardList()
	{
		this->Head = nullptr;	//���� ������ ��������� �� ����, ������ ������ ����
		cout << "LConstructor:\t" << this << endl;
	}
	~ForwardList()
	{
		cout << "LDestructor:\t" << this << endl;
	}
		
					//Adding Element
	void push_front(int Data)
	{
		//1)������� �������
		Element* New = new Element(Data);
		//2)������������ ����� ������� � ������:
		New->pNext = Head;
		//3)��������� ������ �� ����� �������
		Head = New;
	}

	void pop_front()
	{
		Element* Temp = Head->pNext;  
		delete Head;                  
		Head = Temp;                  
	}

	void pop_back()
	{
		Element* Temp = Head;
		while (Temp->pNext->pNext != nullptr)Temp = Temp->pNext;
		delete Temp->pNext;
		Temp->pNext = nullptr;
	}

				//Methods
	void print()const
	{
		Element* Temp = Head;	//Temp - ��������
		//�������� - ��� ���������, ��� ������ �������� ����� �������� ������ � ���������
		//��������� ������
		while (Temp != nullptr)
		{
			cout << Temp << tab << Temp->Data << tab << Temp->pNext << endl;
			Temp = Temp->pNext;	//������� �� ��������� �������
		}
	}
};
void main()
{
	setlocale(LC_ALL, "ru");
	int n;		//������ ������
	cout << "������� ������ ������: "; cin >> n;
	ForwardList list;
	for (int i = 0; i < n; i++)
	{
		list.push_front(rand() % 100);
	}
	list.print();

	list.pop_front();
	list.print();


	list.pop_back();
	list.print();

}