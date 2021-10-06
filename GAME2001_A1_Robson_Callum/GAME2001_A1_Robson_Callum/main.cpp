
#include "OrderedArray.h"
#include "UnorderedArray.h"
#include <iostream>
using namespace std;

int main()
{
	UnorderedArray<int> numbers(3);
	numbers.push(5);
	numbers.push(2);
	numbers.push(3);

	cout << "Unorderer array: \n";

	for (int i = 0; i < 3; i++)
	{
		cout << numbers[i] << endl;
	}

	cout << "Ordered array: \n";

	OrderedArray<int> numbers2(3);
	numbers2.push(5);
	numbers2.push(2);
	numbers2.push(3);

	for (int i = 0; i < 3; i++)
	{
		cout << numbers2[i] << endl;
	}
	return 0;
}