#include <iostream>
using namespace std;


int main () {

	/**
	*	When we declare an integer the "normal" way, it is sored
	*	in "static" memory.  That is, it can be calculated 
	*	when the program is launched.
	*	See how the memory addresses of these ints are relatively close.
	*/
	int NumberInStaticMemory;
	int AnotherNumberInStaticMemory;
	int YetAnotherNumberInStaticMemory;
		
	cout << "The addresses of the 3 ints are:" << endl;
	cout << &NumberInStaticMemory << endl;
	cout << &AnotherNumberInStaticMemory << endl;
	cout << &YetAnotherNumberInStaticMemory << endl;
	
	
	
	int* PointerToInt = &NumberInStaticMemory;
	int* AnotherPointerToInt = &AnotherNumberInStaticMemory;
	int* YetAnotherPointerToInt = &YetAnotherNumberInStaticMemory;

	cout << "The pointers point to" << endl;
	cout << PointerToInt << endl;
	cout << AnotherPointerToInt << endl;
	cout << YetAnotherPointerToInt << endl;
	
	
	/**
	*	Re-assign the pointers using the "new" operator.
	*/
	PointerToInt = new int;
	AnotherPointerToInt = new int;
	YetAnotherPointerToInt = new int;
	
	cout << "The addresses of the 3 ints after using dynamic memory are:" << endl;
	cout << PointerToInt << endl;
	cout << AnotherPointerToInt << endl;
	cout << YetAnotherPointerToInt << endl;
	
	/**
	*	Dynamic memory must be freed.  It is not deallocated when it falls
	*	out of scope.
	*/
	delete PointerToInt;
	delete AnotherPointerToInt;
	delete YetAnotherPointerToInt;
		
		
		
	
	cout << endl << endl;
	cout << "The addresses of elements of an array in static memory:" << endl;
	int ArrayInStaticMemory[10];
	cout << ArrayInStaticMemory << endl;
	cout << &ArrayInStaticMemory << endl;
	cout << &ArrayInStaticMemory[0] << endl;
	cout << &ArrayInStaticMemory[1] << endl;
	cout << &ArrayInStaticMemory[2] << endl;
	cout << &ArrayInStaticMemory[3] << endl;
	cout << &ArrayInStaticMemory[4] << endl;
	
	
	cout << endl << endl;
	
	cout << "The addresses of array elements in a dynamicly allocated array: " << endl;
	int* ArrayInDynamicMemory = new int[10];
	cout << ArrayInDynamicMemory << endl;
	cout << &ArrayInDynamicMemory[0] << endl;
	cout << &ArrayInDynamicMemory[1] << endl;
	cout << &ArrayInDynamicMemory[2] << endl;
	cout << &ArrayInDynamicMemory[3] << endl;
	cout << &ArrayInDynamicMemory[4] << endl;
}
