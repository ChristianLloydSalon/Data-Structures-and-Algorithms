#include <iostream>
#include <cstdlib>
#include <conio.h>	// getch()
#include <cctype>	// toupper()

#define MAX 100

using namespace std;

class Stack
{
	public:
		Stack();
		~Stack();
		
		void Push(int data);	// pushes an element into the stack
		void Pop(void);			// pops an element out of the stack
		void PrintAll(void);	// display all elements in the stack
		void Top();				// gets the topmost element
	
	private:
		int* stackArray;
		
		int top;				// points to the topmost element, -1 for an empty stack
		
		bool isEmpty();			// returns true is stack is empty
		bool isFull();			// returns true is stack is full
};

Stack::Stack()
{
	top = -1;
	stackArray = new int[MAX];
}

Stack::~Stack()
{
	delete[] stackArray;
}

void Stack::Push(int data)
{
	if(isFull())
		throw "Stack is full!";
		
	stackArray[++top] = data;
	
	cout << endl << data << " is inserted!" << endl;
	
	PrintAll();
}

void Stack::Pop()
{
	if(isEmpty())
		throw "Stack is empty!";
	
	cout << endl << stackArray[top--] << " is removed!" << endl;
	
	PrintAll();
}

void Stack::PrintAll()
{
	if(isEmpty())
		throw "Stack is empty!";
		
	cout << "Stack: ";
	for(int i=0; i<=top; i++)
	{
		cout << stackArray[i] << " ";
	}
	cout << endl << endl;
}

void Stack::Top()
{
	if(isEmpty())
		throw "Stack is Empty!";
		
	cout << endl << "Topmost Element: " << stackArray[top] << endl << endl;
}

bool Stack::isEmpty()
{
	return (top == -1);
}

bool Stack::isFull()
{
	return (top == MAX - 1);
}

int main()
{
	int input;
	char choice;
	Stack stack;
	
	while(1)
	{
		try
		{
			cout << "[STACK OPERATIONS]" << endl;
			cout << "[A]: Push" << endl;
			cout << "[B]: Pop" << endl;
			cout << "[C]: Print All" << endl;
			cout << "[D]: Top" << endl;
			cout << "[E]: Exit" << endl;
			
			choice = getch();
			
			switch(toupper(choice))
			{
				case 'A':
					cout << endl << "Enter data: ";
					cin >> input;
					
					stack.Push(input);
					break;
					
				case 'B':
					stack.Pop();
					break;
					
				case 'C':
					cout << endl;
					stack.PrintAll();
					break;
					
				case 'D':
					stack.Top();
					break;
					
				case 'E':
					exit(0);
					break;
					
				default:
					cout << "Invalid choice!" << endl << endl;
					break;
			}
		}
		catch(const char* errMessage)
		{
			cerr << endl << errMessage << endl << endl;
		}
	}
}
