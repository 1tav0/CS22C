#include <iostream>
#include <cstddef>
#include <assert.h>
#include <string>
#include "Queue.h"
#include "Stack.h"
using namespace std;

void Stack::pop()
{
	assert (!isEmpty());
	if (q2.isEmpty())
	{
		while(q1.getSize() != 1)
		{
			q2.enqueue(q1.getFront());
			q1.dequeue();
		}
		q1.dequeue();
	}
	else
	{
		while(q2.getSize() != 1)
		{
			q1.enqueue(q2.getFront());
			q2.dequeue();
		}
			q2.dequeue();

	}
}

void Stack::push(string data)
{
	if (q2.isEmpty())
		q1.enqueue(data);
	else
		q2.enqueue(data);

}

string Stack::getTop()
{
	assert (!isEmpty());
	string buffer;
	if (q2.isEmpty())
	{
		while(q1.getSize() != 1)
		{
			q2.enqueue(q1.getFront());
			q1.dequeue();
		}
		buffer = q1.getFront();
		q2.enqueue(q1.getFront());
		q1.dequeue();
		return buffer;
	}
	else
	{
		while(q2.getSize() != 1)
		{
			q1.enqueue(q2.getFront());
			q2.dequeue();
		}

			buffer = q2.getFront();
			q1.enqueue(q2.getFront());
			q2.dequeue();
			return buffer;
	}
}


int Stack::getSize()
{
	if (q1.isEmpty())
	{
		return	q2.getSize();
	}
	else
	{
		return q1.getSize();
	}
}

bool Stack::isEmpty()
{
	if (q1.isEmpty())
	{
		return	q2.isEmpty();
	}
	else
	{
		return q1.isEmpty();
	}
}

void Stack::print()
{
	Stack s;
	if(q1.isEmpty())
	{
		while (q2.getSize() != 0)
		{
			s.push(q2.getFront());
			q1.enqueue(q2.getFront());
			q2.dequeue();
		}
		while(!(s.isEmpty()))
		{
			cout << s.getTop() << " ";
			s.pop();
		}
		cout << endl;
	}
	else
	{
		while (q1.getSize() != 0)
		{
			s.push(q1.getFront());
			q2.enqueue(q1.getFront());
			q1.dequeue();
		}
		while(!(s.isEmpty()))
		{
			cout << s.getTop() << " ";
			s.pop();
		}
	}
}


















