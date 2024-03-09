#include <iostream>
#include <algorithm>
#include <vector>

int main() {
    // Sample data
    std::vector<int> numbers = {1, -2, 3, -4, 5, -6, 7, -8, 9};

    // 1. for_each
    std::cout << "1. for_each: ";
    std::for_each(numbers.begin(), numbers.end(), [](int n) {
        std::cout << n << " ";
    });
    std::cout << std::endl;

    // 2. find_if
    auto it = std::find_if(numbers.begin(), numbers.end(), [](int n) {
        return n < 0;
    });
    std::cout << "2. find_if: " << (*it) << std::endl;

    // 3. count_if
    int count = std::count_if(numbers.begin(), numbers.end(), [](int n) {
        return n > 0;
    });
    std::cout << "3. count_if: " << count << std::endl;

    // 4. transform
    std::vector<int> squared_numbers;
    std::transform(numbers.begin(), numbers.end(), std::back_inserter(squared_numbers), [](int n) {
        return n * n;
    });
    std::cout << "4. transform: ";
    for (int num : squared_numbers) {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    // 5. sort
    std::sort(numbers.begin(), numbers.end());
    std::cout << "5. sort: ";
    for (int num : numbers) {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    // 6. copy_if
    std::vector<int> positive_numbers;
    std::copy_if(numbers.begin(), numbers.end(), std::back_inserter(positive_numbers), [](int n) {
        return n > 0;
    });
    std::cout << "6. copy_if: ";
    for (int num : positive_numbers) {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    // 7. any_of
    bool any_positive = std::any_of(numbers.begin(), numbers.end(), [](int n) {
        return n > 0;
    });
    std::cout << "7. any_of: " << std::boolalpha << any_positive << std::endl;

    // 8. all_of
    bool all_positive = std::all_of(numbers.begin(), numbers.end(), [](int n) {
        return n > 0;
    });
    std::cout << "8. all_of: " << std::boolalpha << all_positive << std::endl;

    // 9. none_of
    bool none_negative = std::none_of(numbers.begin(), numbers.end(), [](int n) {
        return n >= 0;
    });
    std::cout << "9. none_of: " << std::boolalpha << none_negative << std::endl;

    return 0;
}
