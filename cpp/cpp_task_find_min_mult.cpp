

#include <iostream>
#include <vector>
#include <string>
#include <math.h>
#include <algorithm>



/**
 * @brief Finds the minimum product of two numbers in the given vector.
 *
 * This function takes a vector of integers and returns the minimum product
 * of any two numbers in the vector. It handles both positive and negative
 * numbers to ensure the smallest possible product is found.
 *
 * @param nums A vector of integers from which the minimum product is to be found.
 * @return The minimum product of any two numbers in the vector.
 * @throws std::out_of_range if the vector contains fewer than two elements.
 */


long long find_min_mult(const std::vector<int>& nums)
{
	if (nums.size() <= 1)
	{
		throw std::out_of_range("dddd");
	}

	long long min_1 = std::min(nums[0], nums[1]);
	long long min_2 = std::max(nums[0], nums[1]);
	long long max_1 = std::max(nums[0], nums[1]);
	long long max_2 = std::min(nums[0], nums[1]);

	//std::cout << "min1 " << min_1 << std::endl;
	//std::cout << "min2 " << min_2 << std::endl;
	//std::cout << "max1 " << max_1 << std::endl;
	//std::cout << "max2 " << max_2 << std::endl;

	for (int i = 2; i < nums.size(); ++i)
	{
		// min search
		if (nums[i] < min_1)
		{
			min_2 = min_1;
			min_1 = nums[i];
		}
		else if (nums[i] < min_2)
		{
			min_2 = nums[i];
		}

		// max search
		if (nums[i] > max_1)
		{
			max_2 = max_1;
			max_1 = nums[i];
		}
		else if (nums[i] > max_2) // 2
		{
			max_2 = nums[i];
		}
	}

	if (min_1 > 0)
	{
		return min_1 * min_2;
	}
	else if (max_1 < 0)
	{
		return max_1 * max_2;
	}
	else {
		return min_1 * max_1;
	}
}

void print_example(const std::vector<int>& ns)
{
	std::cout << "\nInput array: ";
	for (int i = 0; i < ns.size(); ++i)
	{
		printf("%d  ", ns.at(i));
	}
	std::cout << "\nResult is " << find_min_mult(ns) << std::endl;
}

int main()
{
	std::vector<int> case_1 = { 9, 4, 2, 5, 3, 2 };
	print_example({ 9,4,2,5,3 });
	print_example({ 9, 4, 2, 5, 3, 2 });

	//
	print_example({ 9, 4, 2, 5, 3, 2, -19, 7 });
	print_example({ 9, 4, 2, 5, 3, 2, -19, -10 });

	// 
	print_example({ -2, -3, -4, -5 });

	getchar();
}

