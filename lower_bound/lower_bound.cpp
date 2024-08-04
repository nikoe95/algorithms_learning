// lower_bound - wyszukuje pierwszą liczbę równą/większa od zadanej
// rekurencyjnie warunkiem brzegowym jest left>right
#include <iostream>
#include <vector>

template<typename T, typename C = std::greater<T>>
bool isEqual(const T& lhs, const T& rhs, C comp = C{})
{
    if(!comp(lhs, rhs) && !comp(rhs, lhs)) {
        return true;
    }
    return false;
}

template<typename IT, typename E, typename C>
IT lower_bound(IT left, IT right, const E& value, C comp)
{
     // warunek brzegowy - iterator lewy przechodzi za prawy
     if(left > right) {
         return left;
     }

     const size_t distance = std::distance(left, right) / 2;
     const IT mid = std::next(left, distance);
     if(isEqual(*mid, value) || comp(*mid, value))
     {
        return lower_bound(left, std::prev(mid), value, comp);
     }
     return lower_bound(std::next(mid), right, value, comp);
}

template<typename IT, typename E = IT::value_type, typename C = std::greater<E>>
IT lower_bound_top(IT left, IT right, const E& value, C comp = C{})
{
    const auto it = lower_bound(left, right, value, comp);
    return it > right ? right : it;
}


int main()
{
    std::vector<int> vect {1, 2, 4, 7, 7, 8, 9, 10, 11, 12, 17, 24, 51, 52, 53};
    auto it = lower_bound_top(vect.begin(), vect.end(), 52);
    std::cout << "It: " << std::distance(vect.begin(), it) << std::endl;
    return true;
}

