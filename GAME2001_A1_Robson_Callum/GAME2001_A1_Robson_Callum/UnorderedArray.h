#pragma once
#include "Array.h"

template <class t>
class UnorderedArray : public Array<t>
{
public:
	UnorderedArray(int size, int growBy = 1) : Array<t>(size, growBy) {};

	~UnorderedArray() {};

	void push(t val) override
	{
		assert(Array<t>::m_array != nullptr); // Debugging purposes

		if (Array<t>::m_numElements >= Array<t>::m_maxSize) // Check if the array has to expand to accomodate the new data.
		{
			Array<t>::Expand();
		}

		// My array has space for a new value. Let's add it!
		Array<t>::m_array[Array<t>::m_numElements] = val;
		Array<t>::m_numElements++;
	};
	 
	int search(t searchKey) override
	{
		assert(Array<t>::m_array != nullptr);

		// Brute-force Search
		for (int i = 0; i < Array<t>::m_numElements; i++)
		{
			if (Array<t>::m_array[i] == searchKey)
			{
				return i; // Return the index of where the item is lovated in the array
			}
		}
		return -1;
	}

};
