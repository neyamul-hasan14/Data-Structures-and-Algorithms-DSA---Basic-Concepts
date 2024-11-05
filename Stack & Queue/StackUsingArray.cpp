#include <iostream>
using namespace std;

struct Stack
{
	int top;
	int arr[100];
};

int isEmpty(Stack *s)
{
	return s->top;
}

void push(Stack *s, int value)
{
	s->top++;
	s->arr[s->top] = value;
}

int pop(Stack *s)
{
	if (isEmpty(s) != -1)
	{
		int y = s->arr[s->top];
		s->top--;
		return y;
	}
	return -1;
}

int peek(Stack *s)
{
	if (isEmpty(s))
	{
		return s->arr[s->top];
	}
	return -1;
}

void display(Stack *s)
{
	for (int i = 0; i < s->top + 1; i++)
	{
		cout << s->arr[i] << endl;
	}
}

int main()
{
	Stack *s1;
	s1 = new Stack();

	s1->top = -1;
	while (1)
	{
		cout << "1. Push\n2. Pop\n3. Peek\n4. isEmpty\n5. Display\n0. Exit" << endl;
		int x;
		cin >> x;
		if (x == 0)
			break;
		else if (x == 1)
		{
			cout << "Enter a value: ";
			int y;
			cin >> y;
			push(s1, y);
		}
		else if (x == 2)
		{
			int y = pop(s1);
			cout << y << endl;
		}
		else if (x == 3)
		{
			int y = peek(s1);
			cout << y << endl;
		}
		else if (x == 4)
		{
			cout << isEmpty(s1) << endl;
		}
		else if (x == 5)
		{
			display(s1);
		}
	}
}
