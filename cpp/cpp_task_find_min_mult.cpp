#include <iostream>
#include <vector>
#include <algorithm>
#include <limits>
#include <stdexcept>
#include <cmath>

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
    if (nums.size() < 2)
    {
        throw std::out_of_range("The input vector must contain at least two elements.");
    }

    // Initialize variables to store the two smallest and two largest numbers
    int min1 = std::numeric_limits<int>::max(), min2 = std::numeric_limits<int>::max();
    int max1 = std::numeric_limits<int>::min(), max2 = std::numeric_limits<int>::min();

    for (const int num : nums)
    {
        // Find the two smallest numbers
        if (num <= min1)
        {
            min2 = min1;
            min1 = num;
        }
        else if (num < min2)
        {
            min2 = num;
        }

        // Find the two largest numbers
        if (num >= max1)
        {
            max2 = max1;
            max1 = num;
        }
        else if (num > max2)
        {
            max2 = num;
        }
    }

    // Calculate possible products
    long long prod1 = static_cast<long long>(min1) * min2;
    long long prod2 = static_cast<long long>(max1) * max2;
    long long prod3 = static_cast<long long>(min1) * max1;

    // Find the minimum product
    long long min_product = std::min({prod1, prod2, prod3});

    return min_product;
}

int main()
{
    int N;
    std::cin >> N;

    std::vector<int> nums(N);
    for (int i = 0; i < N; ++i)
    {
        std::cin >> nums[i];
    }

    try
    {
        long long result = find_min_mult(nums);
        std::cout << result << std::endl;
    }
    catch (const std::out_of_range& e)
    {
        std::cerr << e.what() << std::endl;
        return 1;
    }

    return 0;
}
