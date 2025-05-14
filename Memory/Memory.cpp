#include <iostream>
using namespace std;

void set(int& i)
{
	i = 123;
}

void swapper(int* a, int* b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}

//Always try to use references, but if whatever your using can be null user a pointer
// This is because pointers can be null but references cannot
// pointers are always 4 bytes not matter the data type.
// dereferencing is just getting the value from a pointer. this is done by putting the * operator in front of the variable name. line 29 for example

int main()
{
    int i1 = 10;
	int i2 = 20;

	int* r = &i1;
	int* p = nullptr; // or int* r2;

	//set(*r);

	p = &i2;

	swapper(&i1, &i2);
    
	cout << r << endl;
    cout << "i1: " << i1 << endl;
	cout << "i2: " << i2 << endl;

	cout << "i1 Adress: " << &i1 << endl;
	cout << "i2 Adress: " << &i2 << endl;
	cout << "dereference p: " << *p << endl;
	cout << "P address = " << p << endl;
}
