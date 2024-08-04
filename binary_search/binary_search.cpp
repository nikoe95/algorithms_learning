#include <iostream>
#include <optional>
#include <vector>


// Wersja 1 
std::optional<int> binarySearch(const std::vector<int> & numbers, int value, int left, int right)
{
    if(left > right) {
        return std::nullopt;
    }

    auto mid = (left + right) / 2;
    if(numbers[mid] == value) {
        return mid;
    }

    if(value > numbers[mid]) {
        return binarySearch(numbers, value, mid + 1, right);
    }
    return binarySearch(numbers, value, left, mid - 1);
}

int binarySearch(const std::vector<int> & numbers, int value)
{
    return binarySearch(numbers, value, 0, numbers.size() - 1).value_or(-1);
}

// Wersja 2
template <typename T, typename E, typename C>
std::optional<int> binarySearchT1(const T& numbers, const E& value, int left, int right, C comp)
{
    if(left > right) {
        return std::nullopt;
    }

    auto mid = (left + right) / 2;
    if(!comp(numbers[mid], value) && (value, numbers[mid])) {
        return mid;
    }

    if(comp(value, numbers[mid])) {
        return binarySearchT1(numbers, value, mid + 1, right, comp);
    }

    return binarySearchT1(numbers, value, left, right - 1, comp);
}

template<typename T, typename E = T::value_type, typename C = std::greater<E>>
int binarySearchT1(const T& numbers, const E& value, C comp = C{})
{
    return binarySearchT1(numbers, value, 0, numbers.size() -1, comp).value_or(-1);
}

int main()
{
    std::vector<int> value_vec {1, 3, 5, 7, 11, 14, 21, 94, 101};
    auto output = binarySearchT1(value_vec, 101);
    std::cout << "look for value at index: " << output << std::endl;

    return true;
}

