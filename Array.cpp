#include<iostream>
#include "Array.h"

using namespace std;

Array::Array(int startCapacity)
	{
		if (startCapacity <= 0)
			capacity = DEFAULT_CAPACITY;
		else capacity = startCapacity;
		ptr = new int[capacity];
		size = 0;
	}
Array::~Array() { delete[] ptr; cout << "deleted" << endl; }
	Array::Array(const Array& arr)
	{
		ptr = new int[arr.capacity];
		size = arr.size;
		capacity = arr.capacity;
		for (int i = 0; i < size; i++)
			ptr[i] = arr.ptr[i];
	}
	Array& Array::operator=(const Array& arr)
	{
		if (this == &arr)
			return*this;
		if (capacity != arr.capacity)
		{
			delete[] ptr;
			ptr = new int[arr.capacity];
			capacity = arr.capacity;
		}
		size = arr.size;
		for (int i = 0; i < size; i++)
			ptr[i] = arr.ptr[i];
		return*this;
	}
	int& Array::operator[](int index)
	{
		if (index >= size || index < 0)
			throw ArrayException();
		else
			return ptr[index];
	}
	void Array::insert(int elem, int index)
	{
		if (index < 0 || index > size)
			throw ArrayException();
		if (size == capacity)
			increaseCapacity(size+1);
		for(int j=size-1; j>=index; j--)
			ptr[j+1]=ptr[j];
		size++;
		ptr[index]=elem;
	}
	void Array::insert(int elem)
	{
		insert(elem, size);
	}
	void Array::insert(Array& vect, int index)
	{
		int vs = vect.size, i, old_size = size;
		size = size + vs;
		if (index < 0 || index > size)
			throw ArrayException();
		if (size <= capacity)
		{
			increaseCapacity(capacity);
		}
        for (i = size-1; i >= index+vs; i--)
            ptr[i]=ptr[i-vs];
       for (i = 0; i < vs; i++)
            ptr[i + index] = vect[i];
	}
	void Array::increaseCapacity(int newCapacity)
	{
		capacity = newCapacity < capacity * 2 ? capacity * 2 : newCapacity;
		int* newPtr = new int[capacity];
		for (int i = 0; i < size; i++)
			newPtr[i] = ptr[i];
		delete[] ptr;
		ptr = newPtr;
	}
	void Array::remove(int index)
	{
		if (index < 0 || index >= size)
			throw ArrayException();
		for (int j = index; j < size - 1; j++)
			ptr[j] = ptr[j + 1];
		ptr[size - 1] = 0;
		size--;
	}
	void Array::checkmax()
	{
		if (size > Max_Size)
			throw ArrayException();
	}
	int Array::getSize() const
	{
		return size;
	}
	ostream& operator<<(ostream& out, const Array& arr)
	{
		out << "Total size: " << arr.size << endl;
		for (int i = 0; i < arr.size; i++)
			out << arr.ptr[i] << endl;
		return out;
	}
	void Array::resize(int new_size)
	{
		int old_size = size;
		size = new_size;
		checkmax();
		if (size <= capacity)
		{
			increaseCapacity(capacity);
		}
		for (int i = old_size; i < size; i++)
			ptr[i] = 0;
	}
	void Array::clear()
	{
		for (int i = 0; i < size; i++)
			ptr[i] = 0;
		size = 0;
	}
