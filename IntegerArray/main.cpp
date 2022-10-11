#include<iostream>
#include"Array.h"
using namespace std;

int main()
{
	try
	{
		Array arr(10);

		arr.Resize(7);

		arr[arr.getSize() - 1] = 0;

		arr.Insert(5, 5);

		arr.InsertFirst(15);

		arr.InsertEnd(25);

		arr.Remove(2);

		for (int i = 0; i < arr.getSize(); ++i)
		{
			cout << arr[i] << endl;
		}
		cout << " " << endl;
	}
		catch (MyExcept& exception)
		{
			cerr << "Error: " << exception.what() << endl;
		}
		catch (...)
		{
			cerr << "Unknown error" << endl;
		}
		return 0;	
}