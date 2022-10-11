#include "Array.h"
#include <stdlib.h>
using namespace std;

Array::Array(int size)
{
	_size = size;
	if (_size <= 0)
		throw MyExcept("Wrong Array size");
	else
	{
		ptr = new int[size] {};
		FillArray();
	}
}

Array::~Array()
{
	delete[] ptr;
}

Array::Array(const Array& other)
{
	_size = other._size;
	if (_size < 0)
		throw MyExcept("Wrong size in copy constructor");
	else
	{
		ptr = new int[other._size];
		for (int i = 0; i < _size; ++i)
			ptr[i] = other.ptr[i];
	}
}

void Array::FillArray()
{
	for (int i = 0; i < _size; ++i)
		ptr[i] = static_cast<int>(1) + rand() % 100;
}

void Array::EraseArray()
{
	delete[] ptr;
	ptr = nullptr;
	_size = 0;
}

int& Array::operator[](int index)
{
	if (index <0 || index > _size)
		throw MyExcept("Wrong index in operator[]");
	else
	    return ptr[index];
}

void Array::Insert(int element, int index)
{
	if (index < 0 || index > _size)
		throw MyExcept("Wrong index in Insert()");
	else
	{
		int* newPtr = new int[_size + 1];
		for (int before{ 0 }; before < index; ++before)
		{
			newPtr[before] = ptr[before];
		}
		for (int after{ index }; after < _size; ++after)
		{
			newPtr[after + 1] = ptr[after];
		}
		newPtr[index] = element;
		delete[] ptr;
		ptr = newPtr;
		++_size;
	}
}

void Array::Remove(int index)
{	
	if (index <= 0 || index > _size)
		throw MyExcept("Wrong index in Remove()");
	else 
	{
		int* newPtr = new int[_size - 1];
		for (int before{ 0 }; before < index; ++before)
		{
			newPtr[before] = ptr[before];
		}
		for (int after{ index + 1 }; after < _size; ++after)
		{
			newPtr[after - 1] = ptr[after];
		}
		delete[] ptr;
		ptr = newPtr;
		--_size;
	}
}

void Array::InsertEnd(int element)
{
	Insert(element, _size);
}

void Array::InsertFirst(int element)
{
	Insert(element, 0);
}

void Array::Resize(int NewSize)
{
	if (NewSize <= 0)
		throw MyExcept("Wrong size in Resize()");
	else
	{
		int* newPtr = new int[NewSize];
		for (int i = 0; i < NewSize; ++i)
			newPtr[i] = ptr[i];

		delete[] ptr;
		ptr = newPtr;
		_size = NewSize;
	}
}

int Array::getSize() const
{
	return _size;
}