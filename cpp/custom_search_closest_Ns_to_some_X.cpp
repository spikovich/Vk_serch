#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

 

std::vector<int> find_closest_numbers(const std::vector<int>& numbers, int x, int n)
{
    std::vector<int> res;
    int size = numbers.size();

    auto it = std::lower_bound(numbers.begin(), numbers.end(), x);
    int left = it - numbers.begin() - 1;
    int right = it - numbers.begin();

    while (res.size() < n && (left >= 0 || right < size)) {
        if (left >= 0 && right < size) {
            int diff_left = std::abs(x - numbers[left]);
            int diff_right = std::abs(x - numbers[right]);

            if (diff_left <= diff_right) {
                res.push_back(numbers[left--]);
            } else {
                res.push_back(numbers[right++]);
            }
        } else if (left >= 0) {
            res.push_back(numbers[left--]);
        } else if (right < size) {
            res.push_back(numbers[right++]);
        } else {
            break;
        }
    }

    
    std::cout << "\n------------------------------------------------\n";
    std::cout << "first:";
    for (auto k : numbers) {
        std::cout << " " << k;
    }
    std::cout << "\nfind num " << x << " :";
    for (auto k : res) {
        std::cout << " " << k;
    }
    std::cout << "\n------------------------------------------------\n";

    return res;
}

int main()
{
    std::vector<int> numbers = {1, 3, 45, 56, 78, 81, 82, 83, 89, 90, 111, 126};

    find_closest_numbers(numbers, 3, 4);
    find_closest_numbers(numbers, 80, 4);
    find_closest_numbers(numbers, 1000009, 4);

    std::vector<int> bad_numbers = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
    find_closest_numbers(bad_numbers, 5, 20);
    find_closest_numbers(bad_numbers, 20, 20);
    find_closest_numbers(bad_numbers, -1, 20);

    return 0;
}
