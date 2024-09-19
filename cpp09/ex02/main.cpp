#include "PmergeMe.hpp"

int main(int ac, char **av)
{
    std::deque<int> a;
    std::vector<int> b;
    clock_t time_vec;
    clock_t time_deq;

    if (ac < 2)
    {
        std::cerr << "Error" << std::endl;
        return 1;
    }
    check_input(av);
    push_to_stack(a, b, av);
    std::cout << "Before: ";
    print(b);
    merge_insert_sort_vec(b, &time_vec);
    std::cout << "After: ";
    print(b);
    std::cout << "Time to process a range of " << b.size() << " elements in a vector: " << std::setprecision(5) << std::fixed << (float)time_vec / CLOCKS_PER_SEC << " us" << std::endl;
    merge_insert_sort_deq(a, &time_deq);
    std::cout << "Time to process a range of " << a.size() << " elements in a deque: " << std::setprecision(5) << std::fixed << (float)time_deq / CLOCKS_PER_SEC << " us" << std::endl;

    return 0;
}