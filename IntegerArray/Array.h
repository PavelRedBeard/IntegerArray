#pragma once
#include<iostream>
#include<string>
#include<exception>
using namespace std;

class MyExcept : public exception
{
private:
	string _message;
public:
	MyExcept(string message) : _message(message) {};
	const char* what() const noexcept { return _message.c_str(); }
};

class Array
{
private:
	int _size;
	int* ptr;
	
public:
	Array() = default;
	Array(int size);
	~Array();
	Array(const Array& other);

	void FillArray();

	void EraseArray();

	int& operator [](int index);

	void Insert(int element, int index);
	void Remove(int index);
	void InsertEnd(int element);
	void InsertFirst(int element);	
	
	void Resize(int NewSize);

	int getSize() const;
};