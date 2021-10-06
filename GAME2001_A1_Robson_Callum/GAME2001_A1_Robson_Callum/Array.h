#pragma once
#include <cassert>

template <class t>
class Array
{
public:
	// Constructor
	Array(int size, int growBy = 1) :
		m_array(NULL), m_maxSize(0), m_growSize(0), m_numElements(0)
	{
		if (size) // Is this a legal size for an array?	
		{
			m_maxSize = size;
			m_array = new T[m_maxSize]; // Dynamically allocating an array to m_maxSize
			memset(m_array, 0, sizeof(T) * m_maxSize); // Explicity set 0 to all elements in the array

			m_growSize = ((growBy > 0 ? growBy : 0)); // ternary statement (fancy version of: if growBy > 0, set m_growSize to growBy, else set to 0
		}
	};
	// Destructor
	~Array()
	{
		if (m_array != nullptr)
		{
			delete[] m_array;
			m_array = nullptr;
		}
	}

	virtual void push(T val) = 0;
	
	void pop()
	{
		if (m_numElements > 0)
		{
			m_numElements--; // Reduce the total number of elements by 1. Ignoring the last element;
		}
	}

	// Remove an iten given an index
	// (Almost) Brute-force execution -- BigO = O(N)
	void remove(int index)
	{
		assert(m_array != nullptr);

		if (index >= m_numElements)
		{
			// I am trtying to remove something outside of the bound of the array
			return; //<-- Maybe could do some form of exception handling
		}

		for (int i = index; i < m_numElements; i++)
		{
			// Start at the index we want to remove.
			// Shift everything after the index back by one.
			if (i + 1 < m_numElements) // Confines the loop into the array
			{
				m_array[i] = m_array[i + 1];
			}
		}
		m_numElements--;
	}

	virtual int search(T searchKey) = 0;

	// Overloaded [] operator
	T& operator[](int index)
	{
		assert(m_array != nullptr && index < m_numElements);
		return m_array[index];
	}
	// Clear
	void clear()
	{
		m_numElements = 0; // Ignore (or forgets) all current items in the array
	}
	// Gets and Sets
	int getSize()
	{
		return m_numElements;
	}
	int getMaxSize()
	{
		return m_maxSize;
	}
	int getGrowSize()
	{
		return m_growSize;
	}
	int setGrowSize(int val)
	{
		assert(val >= 0);
		m_growSize = val;
	}

	// Expansion
	bool Expand()
	{
		if (m_growSize <= 0)
		{
			// Leave!
			return false;
		}
		// Create the new array
		T* temp = new T[m_maxSize + m_growSize];
		assert(temp != nullptr);

		// Copy the contents of the original array into the new array
		memcpy(temp, m_array, sizeof(T) * m_maxSize);

		// Delete the old array
		delete[] m_array;

		// Clean up variable assignments
		m_array = temp;
		temp = nullptr;

		m_maxSize += m_growSize;

		return true;
	}
private:

};