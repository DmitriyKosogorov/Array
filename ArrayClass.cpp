#include<iostream>
#include "Array.cpp"
using namespace std;
int main(void)
{
	//setlocale(LC_ALL, "Russian");
	Array arr(4);
	Array arr2(3);
	for (int i = 0; i < 3; i++)
		arr2.insert(i);
	for (int i = 0; i < 4; i++)
		arr.insert(i + 1);
	cout <<"creating"<<endl<< arr << endl;
	for (int i = 0; i < 8; i += 2)
		arr.insert(10 + i, i);
	cout << arr << endl;
	for (int i = 1; i < 8; i += 2)
		arr[i] = 20 + i;
	cout << arr << endl;
	for (int i = 6; i >= 0; i -= 3)
		arr.remove(i);
	cout << arr << endl;
	arr.insert(arr2, 3);
	cout <<"adding massive in massive"<<endl<< arr << endl;
	arr.clear();
	cout << "clearing" << endl << arr << endl;
}
