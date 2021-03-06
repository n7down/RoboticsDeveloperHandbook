#ifndef QUEUE_H
#define QUEUE_H

#include <stack>

class Queue
{
	private:
		std::stack<int> a;
		std::stack<int> b;
		void update();

	public:
		int top();
		void enqueue(int i);
		int dequeue();
		int size();
};

#endif
