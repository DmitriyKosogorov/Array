#pragma once
#ifndef Array_H
#define Array_H
using namespace std;

const int DEFAULT_CAPACITY = 10;
const long long Max_Size = 10000000000;
class ArrayException{};
class Array
{
private:
	int* ptr;
	int size;
	int capacity;
public:
	explicit Array(int startCapacity = DEFAULT_CAPACITY);
	~Array();
	Array(const Array& arr);
	Array& operator=(const Array& arr);
	int& operator[](int index);
	void insert(int index, int elem);
	void insert(int elem);
	void insert(Array vect, int index);
	void increaseCapacity(int newCapacity);
	void remove(int index);
	void checkmax();
	int getSize() const;
	friend ostream& operator<<(ostream& out, const Array& arr);
	void resize(int new_size);
	void clear();
};
#endif