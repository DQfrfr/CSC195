#include <iostream>
using namespace std;
struct Person
{
	char name[32];
	int id;
};

void square(int &i)
{
	i = i * i;
}

void Double(int *i)
{
	*i = *i * 2;
}

int main()
{
	// ** REFERENCE **
	// declare an int variable and set the value to some number (less than 10)
	// declare a int reference and set it to the int variable above
	// output the int variable
	// set the int reference to some number
	// output the int variable
	// what happened to the int variable when the reference was changed? (The int was changed to 15 once I changed the reference variable) 
	// output the address of the int variable
	// output the address of the int reference
	// are the addresses the same or different? (They are the same)
	int i1 = 5;
	int& i1Ref = i1;

	cout << i1 << endl;

	i1Ref = 15;

	cout << i1 << endl;

	cout << &i1 << endl;
	cout << &i1Ref << endl;
		


	// ** REFERENCE PARAMETER **
	// create a function above main() called Square that takes in an int parameter
	// in the function, multiply the int parameter by itself and assign it back to the parameter(i = i * i)
	// call the Square function with the int variable created in the REFERENCE section
	// output the int variable to the console
	// !! notice how the variable has not changed, this is because we only passed the value to the function !!
	// change the Square function to take a int reference
	// !! notice how the calling variable has now changed, this is because we 'passed by reference' !!
	// !! when a function takes a reference parameter, any changes to the parameter changes the calling variable ""
	square(i1);
	cout << i1 << endl;
	
	// ** POINTER VARIABLE **
	// declare an int pointer, set it to nullptr (it points to nothing)
	// set the int pointer to the address of the int variable created in the REFERENCE section
	// output the value of the pointer
	// what is this address that the pointer is pointing to? (Whatever the memory address in I1 is. My case: 0000004F386FFCE4)
	// output the value of the object the pointer is pointing to (dereference the pointer)
	int* ptr = nullptr;
	ptr = &i1;

	cout << ptr << endl;
	cout << *ptr << endl;

	// ** POINTER PARAMETER **
	// create a function above main() called Double that takes in an int pointer parameter
	// in the function, multiply the int pointer parameter by 2 and assign it back to the parameter(i = i * 2)
	// !! make sure to dereference the pointer to set the value and not set the address !!
	// call the Double function with the pointer created in the POINTER VARIABLE section
	// output the dereference pointer
	// output the int variable created in the REFERENCE section
	// did the int variable's value change when using the pointer? - Yes it did

	Double(ptr);
	cout << *ptr << endl;
	cout << i1 << endl;
}