#include <iostream>
using namespace std;

//*************************************************************************************************************************

bool isFull(int size, int n);
bool isEmpty(int size, int n);
void Enqueue(int *queue, int &head, int &tail, int &size, int &n);
void Dequeue(int *queue, int &head, int &tail, int &size, int &n);

//*************************************************************************************************************************

int main()
{
	int size;
	int n = 0;
	int head = 0;
	int tail = 0;
	do
	{
		cout << "Enter queue size: ";
		cin >> size;
	} while (size <= 0);
	int *queue = new int[size];                                                              

	int wybor;
	do
	{
		cout << "\n[CORMEN QUEUE]" << endl
			<< "1. Add new value" << endl
			<< "2. Delete value" << endl
			<< "0. Exit" << endl;
		cin >> wybor;

		switch (wybor)
		{
		case 1:
			Enqueue(queue, head, tail, size, n);                            
			break;
		case 2:
			Dequeue(queue, head, tail, size, n);                                
			break;

		}

	} while (wybor != 0);
}

//*************************************************************************************************************************

bool isFull(int size, int n)
{
	if (n == size)
		return true;
	else
		return false;
}

//*************************************************************************************************************************

bool isEmpty(int size, int n)
{
	if (n == 0)
		return true;
	else
		return false;
}
//*************************************************************************************************************************

void Enqueue(int *queue, int &head, int &tail, int &size, int &n)
{
	bool Full;
	Full = isFull(size, n);                           

	if (Full == false)
	{
		cout << "Enter value for " << tail << " element of queue: ";
		cin >> queue[tail];
		n++;
		if (tail == (size - 1))
		{
			tail = 0;
		}
		else                                                          
		{
			tail++;
		}
	}

	else
	{
		cout << "Queue is full. You can't add new element!" << endl;
	}

}

//*************************************************************************************************************************

void Dequeue(int *queue, int &head, int &tail, int &size, int &n)
{
	bool Empty;
	Empty = isEmpty(size, n);                          
	if (Empty == true)
	{
		cout << "Queue is empty. You can't read any values!" << endl;
	}

	else
	{
		cout << "Element " << head << " is equal to: " << queue[head] << endl;
		n--;

		if (head == (size - 1))
		{
			head = 0;
		}                                                        
		else
		{
			head++;
		}
	}
}

//*************************************************************************************************************************


