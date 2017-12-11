#include <gtest/gtest.h>
#include <stdexcept>
#include <string>

#include "insertionsort.h"

namespace
{
	bool isEqual(int a[], int b[])
	{
		int aSize = *(&a + 1) - a; 
		int bSize = *(&b + 1) - b;
		if(aSize != bSize)
		{
			return false;
		}
		for(int i = 0; i < aSize; i++)
		{
			if(a[i] != b[i])
			{
				return false;
			}
		}
		return true;
	}

	std::string printArray(int d[])
	{
		int size = *(&d + 1) - d;	
	}

	TEST(InsertionSort, EmptyArray)
	{
		try {
			int d[] = {};
			InsertionSort::sort(d, 0);
			FAIL() << "expected std::invalid_argument";
		}
		catch(std::invalid_argument const & err) {
			EXPECT_EQ(err.what(), std::string("empty array"));
		}
		catch(...) {
			FAIL() << "expected std::invalid_argument";
		}
	}

	TEST(InsertionSort, ArrayWithOneElement)
	{
		int d[] = { 1 };
		int e[] = { 1 };
		InsertionSort::sort(d, 1);
		ASSERT_TRUE(isEqual(d, e)) << "error";
	}

	TEST(InsertionSort, ArrayWithTwoElements)
	{
		int d[] = { 2, 1 };
		int e[] = { 1, 2 };
		InsertionSort::sort(d, 2);
		ASSERT_TRUE(isEqual(d, e)) << "error";
	}
}
