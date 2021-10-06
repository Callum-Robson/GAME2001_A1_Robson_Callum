#pragma once
#include "Array.h"

template <class t>
class UnorderedArray : public Array<t>
{
	void push(T val) override
	{
		assert(m_array != nullptr); // Debugging purposes

		if (m_numElements >= m_maxSize) // Check if the array has to expand to accomodate the new data.
		{
			Expand();
		}

		// My array has space for a new value. Let's add it!
		m_array[m_numElements] = val;
		m_numElements++;
	};
	 
	int search(T searchKey) override
	{
		assert(m_array != nullptr);

		// Brute-force Search
		for (int i = 0; i < m_numElements; i++)
		{
			if (m_array[i] == val)
			{
				return i; // Return the index of where the item is lovated in the array
			}
		}
		return -1;
	}
};
