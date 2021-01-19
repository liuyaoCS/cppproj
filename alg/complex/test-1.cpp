#include <iostream>
using namespace std;
#define MAXSIZE 10

//栈的数组实现

template<class T>
class Stack
{
public:
	Stack();
	Stack(size_t maxElements);
	Stack(T data[], size_t maxElements);
	~Stack();

	void Push(T data);
	T Pop();
	T Top();
	bool isEmpty();
	bool isFull();
	void Clear();
	size_t GetSize();
private:
	size_t top;
	T *arrays;
	size_t maxSize;
};

template<class T>
Stack<T>::Stack() : maxSize(MAXSIZE), top(-1)
{
	arrays = new T[maxSize];
	if (arrays == NULL)
	{
		cout << "动态分配内存失败";
		exit(1);
	}
}

template<class T>
Stack<T>::Stack(size_t maxElements) : maxSize(maxElements), top(-1)
{
	arrays = new T[maxSize];
	if (arrays == NULL)
	{
		cout << "动态分配内存失败";
		exit(1);
	}
}

template<class T>
Stack<T>::Stack(T data[], size_t maxElements) : maxSize(maxElements), top(-1)
{
	arrays = new T[maxSize];
	if (arrays == NULL)
	{
		cout << "动态分配内存失败";
		exit(1);
	}
	for (size_t i = 0; i < maxSize; i++)
	{
		arrays[i] = data[i];
	}
	top += maxSize;
}

template<class T>
Stack<T>::~Stack()
{
	delete[] arrays;
}

template<class T>
void Stack<T>::Push(T data)
{
	if (isFull())
	{
		throw runtime_error("Full stack");
	}
	else
	{
		top++;
		arrays[top] = data;
	}
}

template<class T>
T Stack<T>::Pop()
{
	if (isEmpty())
	{
		throw runtime_error("No elements in the stack");
	}
	else
	{
		T data = arrays[top];
		top--;
		return data;
	}
}

template<class T>
T Stack<T>::Top()
{
	if (isEmpty())
	{
		throw runtime_error("No elements in the stack");
	}
	else
	{
		return arrays[top];
	}
}

template<class T>
bool Stack<T>::isEmpty()
{
	return top == -1;
}

template<class T>
bool Stack<T>::isFull()
{
	return top == maxSize - 1;
}

template<class T>
void Stack<T>::Clear()
{
	while (top != -1)
	{
		top--;
	}
}

template<class T>
size_t Stack<T>::GetSize()
{
	return top + 1;
}

int main()
{
	try
	{
		int a[6] = { 1, 2, 3, 4, 5, 6 };
		Stack<int> s(a, 6);
		s.Pop();
		s.Push(7);
		while (!s.isEmpty())
		{
			cout << s.Pop() << " ";
		}
		cout << endl;
	}
	catch (exception &e)//引用体现了多态性，基类exception指向runtime_error
	{
		cout << e.what() << endl;
	}

	return 0;
}