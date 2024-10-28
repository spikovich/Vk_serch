
#include <iostream>
#include <vector>
#include <algorithm>
#include <memory>
#include <stdio.h>

// In already sorted non-empty array you need find N closest numbers to some X.
// An example of that array: 1 3 45 56 78 81 82 83 89 90 111 126

// if: X = 5, N = 4.
// result: 1 3 45 56
// 
// if: X = 1000000, N = 4.
// result: 126 111 90 89
// 
// if: X = 80, N = 4.
// result: 81 82 78 83


std::vector<int> solution_1(const std::vector<int>& numbers, int x, int n)
{
    std::vector<int> res;
    int left = 0, right = 0;
    auto it = std::lower_bound(numbers.begin(), numbers.end(), x);

    {
        std::cout << "\n------------------------------------------------\n";
        std::cout << "source numbers: ";
        for (auto k : numbers) {
            std::cout << " " << k;
        }
    }

    if (it == numbers.end()) {
        left = (x < numbers[0]) ? -1 : numbers.size() - 1;
        right = (x < numbers[0]) ? 0 : numbers.size() + 1;
    } else {
        left = it - numbers.begin() - 1;
        right = it - numbers.begin() + 1;
        res.push_back(*it);
    }

    while ((res.size() < n) && ((left >= 0) || (right < numbers.size()))) {
        if (left >= 0 && right < numbers.size()) { // normal case
            if (abs(x - numbers[left]) < abs(x - numbers[right])) {
                res.push_back(numbers[left--]);
            } else {
                res.push_back(numbers[right++]);
            }
        } else if (left >= 0) { // corner cases
            res.push_back(numbers[left--]);
        } else if (right < numbers.size()) {
            res.push_back(numbers[right++]);
        }
    }

    {
        std::cout << "\nfound numbers for " << x << " : ";
        for (auto k : res) {
            std::cout << " " << k;
        }
        std::cout << "\n------------------------------------------------\n";
    }

    return res;
}

int main()
{
    std::vector<int> numbers = {1, 3, 45, 56, 78, 81, 82, 83, 89, 90, 111, 126};

    solution_1(numbers, 3, 4);
    solution_1(numbers, 80, 4);
    solution_1(numbers, 1000009, 4);

    std::vector<int> bad_numbers = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
    solution_1(bad_numbers, 5, 20);
    solution_1(bad_numbers, 20, 20);
    solution_1(bad_numbers, -1, 20);

    getchar();
}