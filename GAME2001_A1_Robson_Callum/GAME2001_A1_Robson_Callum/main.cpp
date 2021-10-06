
#include "OrderedArray.h"
#include "UnorderedArray.h"
#include <iostream>
using namespace std;

int main()
{
	UnorderedArray<int> numbers(3);
	numbers.push(5);
	numbers.push(2);
	numbers.push(2);

	cout << "Unordered array: \n";

	for (int i = 0; i < numbers.getSize(); i++)
	{
		cout << numbers[i] << endl;
	}

	cout << endl << "Ordered array (duplicates not allowed): \n";

	OrderedArray<int> numbers2(3, false);
	numbers2.push(5);
	numbers2.push(2);
	numbers2.push(7);
	numbers2.push(2);
	numbers2.push(7);
	numbers2.push(9);
	numbers2.push(9);

	for (int i = 0; i < numbers2.getSize() ; i++)
	{
		cout << numbers2[i] << endl;
	}

	cout << endl << "Ordered array (duplicates allowed): \n";

	OrderedArray<int> numbers3(3, true);

	cout << "Initial max size: " << numbers3.getMaxSize() << endl;
	cout << "Initial number of elements: " << numbers3.getSize() << endl << endl;

	numbers3.push(5);
	numbers3.push(2);
	numbers3.push(7);
	numbers3.push(2);
	numbers3.push(7);
	numbers3.push(9);
	numbers3.push(9);

	for (int i = 0; i < numbers3.getSize(); i++)
	{
		cout << numbers3[i] << endl;
	}

	cout << endl << "Current max size: " << numbers3.getMaxSize() << endl;
	cout << "Current number of elements: " << numbers3.getSize() << endl;
	return 0;
}