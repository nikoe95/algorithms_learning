#include <iostream>
#include <vector>

template<typename IT, typename E=IT::value_type, typename C = std::greater<E>>
void bubble_sortT(IT first, IT last, C comp = C {})
{
    bool changes {true};
    int round{0};
    while(changes) {
        changes = false;
        ++round;
        for(IT begin = first; begin != last - round; begin++)
        {
            auto next_it = std::next(begin);
            if(comp(*begin, *next_it))
            {
                std::swap(*begin, *next_it);
                changes = true;
            }
        }
    }
}

void bubble_sort(std::vector<int> & numbers)
{
    bool changes {true};
    int round {0};
    while(changes) 
    {
        changes = false;
        ++round;
        for(int i = 0; i < numbers.size() - round; i++)
        {
            if(numbers[i] > numbers[i + 1])
            {
                std::swap(numbers[i], numbers[i+1]);
                changes = true;
            }
        }
    }
}

int main()
{
    std::vector<int> vec{1, 7, 5, 4, 2, 1};
    bubble_sort(vec);
    std::cout << "sorted vector: " << std::endl;
    for(const auto& nb : vec) {
        std::cout << " " << nb <<", ";
    }
    std::cout << std::endl;

    std::vector<int> vec2{1, 7, 5, 4, 2, 1};
    bubble_sortT(vec2.begin(), vec2.end());
    std::cout << "Template bubble_sort: " << std::endl;
    for(const auto& nb : vec2) {
        std::cout << " " << nb <<", ";
    }
    
}