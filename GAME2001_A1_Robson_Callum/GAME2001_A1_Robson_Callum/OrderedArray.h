#pragma once
#include "Array.h"

template <class t>
class OrderedArray : public Array<t>
{
	void push(T val) override
	{
		assert(m_array != nullptr);
		if (m_numElements >= m_maxSize)
		{
			Expand();
		}

		int i, k; // i - index to be inserted. k - Used for shifting purposes
		// Step 1: Find the index to insert val
		for (i = 0; i < m_numElements; i++)
		{
			if (m_array[i] > val)
			{
				break;
			}
		}
		//54:00
		// Step 2: Shift everything to the right of the index(i) forward by one. Work backwards
		for (k = m_numElements; k > i; k--)
		{
			m_array[k] = m_array[k - 1];
		}

		// Step 3: Insert val into the array at index
		m_array[i] = val;

		m_numElements++;

		//return i;
	};

	int search(T searchKey) override
	{
		// Call to binary search recursive function
		// Binary search: searchKey, initial lowerBound, initial upperBound
		return binarySearch(searchKey, 0, m_numElements - 1);
	};

private:
	// Private functions
		// Recursive Binary Search
	int binarySearch(T searchKey, int lowerBound, int upperBound)
	{
		assert(m_array != nullptr);
		assert(lowerBound >= 0);
		assert(upperBound < m_numElements);

		// Bitwise divide by 2
		int current = (lowerBound + upperBound) >> 1;

		// Check 1 "Base Case": Did we find the searchKey at the current index?
		if (m_array[current] == searchKey)
		{
			// We found it! Return the index
			return current;
		}
		// Check 2 "Base Case": Are we done searching?
		else if (lowerBound > upperBound)
		{
			// Did not find searchKey within m_array
			return -1;
		}
		// Checkk 3: Which half of the array is searchKey  in?
		else
		{
			if (m_array[current] < searchKey)
			{
				// Search the upper half of the array
				return binarySearch(searchKey, current + 1, upperBound);
			}
			else
			{
				// Search the lower half of the array
				return binarySearch(searchKey, lowerBound, current - 1);
			}
		}
		return -1;
	}
};