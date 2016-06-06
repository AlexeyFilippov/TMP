#pragma once

#define EXPORT __declspec(dllexport)

__interface EXPORT IQueue
{
	void create(int size);
	bool add(int value);
	int get();
	bool del();
};

class Queue : public IQueue
{
private:
	int* _array;
	int _head;
	int _tail;
	int _size;
	int _counter;
public:
	void create(int size);
	bool add(int value);
	int get();
	bool del();
};

extern "C"
{
	__declspec(dllexport) IQueue* GetIQueue();
}

void Queue::create(int size)
{
	_size = size;
	_array = new int[size];
	for (int i = 0; i < _size; i++)
		_array[i] = 0;
}

bool Queue::add(int data)
{
	if (_counter == _size)
		return false;
	if (_tail >= _size)
		_tail = 0;
	_array[_tail] = data;
	_counter++;
	_tail++;
	return true;
}

int Queue::get()
{
	return _array[_head];
}

bool Queue::del()
{
	if (_counter == 0)
		return false;
	_array[_head] = 0;
	_head++;
	if (_head >= _size)
		_head = 0;
	_counter--;
	return true;
}

IQueue * GetIQueue()
{
	return new Queue();
}
