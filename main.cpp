#include <iostream>
#include"vector.h"
using namespace std;

int main()
{
	try {
		Vector<int> obj;
		int* a = new int[5];
		for (int i = 0; i < 5; i++)
		{
			a[i] = i+1;
		}
		Vector<int> obj1(5,a);
		Vector<int> obj2(obj1);
		obj = obj1;
		IteratorV<int> iter;
		iter = obj2.begin();
		obj2.insert(iter, 7);
		for (iter; iter != obj2.end(); iter++)
		{
			cout << *iter;
		}
	}
	catch(const char* a){
		cout << a;
	}
}