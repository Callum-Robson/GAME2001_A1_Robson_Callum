#pragma once
#include "Array.h"

template <class t>
class OrderedArray : public Array<t>
{
public:
	OrderedArray(int size, bool duplicatesFlag = true, int growBy = 1) : Array<t>(size, growBy)
	{
		duplicatesAllowed = duplicatesFlag;
	};

	~OrderedArray() {};

	void push(t val) override
	{
		assert(Array<t>::m_array != nullptr);
		if (Array<t>::m_numElements >= Array<t>::m_maxSize)
		{
			Array<t>::Expand();
		}

		int i, k; // i - index to be inserted. k - Used for shifting purposes
		// Step 1: Find the index to insert val
		for (i = 0; i < Array<t>::m_numElements; i++)
		{
			if (Array<t>::m_array[i] > val)
			{
				break;
			}
		}
		if (duplicatesAllowed == false)
		{
			if (search(val) < 0)
				duplicatesFound = false;
			else
				duplicatesFound = true;
		}
		if (duplicatesAllowed == true || duplicatesFound == false)
		{
			// Step 2: Shift everything to the right of the index(i) forward by one. Work backwards
			for (k = Array<t>::m_numElements; k > i; k--)
			{
				Array<t>::m_array[k] = Array<t>::m_array[k - 1];
			}

			// Step 3: Insert val into the array at index
			Array<t>::m_array[i] = val;

			Array<t>::m_numElements++;
		}

		//return i;
	};

	int search(t searchKey) override
	{
		// Call to binary search recursive function
		// Binary search: searchKey, initial lowerBound, initial upperBound
		return binarySearch(searchKey, 0, Array<t>::m_numElements - 1);
	};

private:
	// Private functions
		// Recursive Binary Search
	int binarySearch(t searchKey, int lowerBound, int upperBound)
	{
		assert(Array<t>::m_array != nullptr);
		assert(lowerBound >= 0);
		assert(upperBound < Array<t>::m_numElements);

		// Bitwise divide by 2
		int current = (lowerBound + upperBound) >> 1;

		// Check 1 "Base Case": Did we find the searchKey at the current index?
		if (Array<t>::m_array[current] == searchKey)
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
			if (Array<t>::m_array[current] < searchKey)
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

private:
	bool duplicatesAllowed;
	bool duplicatesFound = false;

};