#include <iostream>
#include <functional>
#include <iterator>

// jeszcze zrozumiec wersje z podana funkcja zamiast obiektem funkcyjnym

template<typename IT, typename E = IT::value_type, typename C = std::equal_to<E>>
IT linear_search(IT begin, IT end, const E& value, C comp = C{})
{
    while(begin != end) {
        if(comp(*begin, value))
        {
            return begin;
        }
        begin = std::next(begin);
    }
    return end;
}

int main()
{
    std::vector<int> vec {1, 2, 5, 7, 8, 9, 11, 24, 25, 31};
    auto it = linear_search(vec.begin(), vec.end(), 32);
    auto pos = std::distance(vec.begin(), it);
    std::cout << "Position of value in container: " << pos << std::endl;
}