#include "PmergeMe.hpp"

void    check_input(char **args)
{
	for (int i = 1; args[i]; i++)
	{
		for (int j = 0; args[i][j]; j++)
		{
			if (!isdigit(args[i][j]))
			{
				if (j == 0 && args[i][j] == '+' && isdigit(args[i][j + 1]))
					continue;
				std::cerr << "Error" << std::endl;
				exit(1);
			}
		}
	}
}

void    push_to_stack(std::deque<int> &a, std::vector<int> &b, char **args)
{
	for (int i = 1; args[i]; i++)
	{
		int num = atoi(args[i]);
		a.push_back(num);
		b.push_back(num);
	}
}

void    print(std::vector<int> &a)
{
	for (std::vector<int>::iterator it = a.begin(); it != a.end(); it++)
		std::cout << *it << " ";
	std::cout << std::endl;
}

//-----------------------------------------------------------------------------------------------

void    insert_in_order_vec(std::vector<int> &a, int b)
{
	std::vector<int>::iterator it;
	it = std::lower_bound(a.begin(), a.end(), b);
	a.insert(it, b);
}

void	merge_insert_sort_vec(std::vector<int> &arr, clock_t *time)
{
    int size = arr.size();
	*time = clock();
    
    if (size <= 1)
    	return;

    std::vector<int> min_v, max_v;
    for(int i = 0; i + 1 < size; i += 2) {
        if (arr[i] < arr[i + 1]) {
            min_v.push_back(arr[i]);
            max_v.push_back(arr[i + 1]);
        } else {
            min_v.push_back(arr[i + 1]);
            max_v.push_back(arr[i]);
        }
    }

    if (size % 2 != 0) {
        min_v.push_back(arr[size - 1]);
    }

    merge_insert_sort_vec(min_v, time);
    merge_insert_sort_vec(max_v, time);

    std::vector<int> result = min_v;
    for (std::vector<int>::iterator it = max_v.begin(); it != max_v.end(); it++)
	{
        insert_in_order_vec(result, *it);
	}
    
	*time = clock() - *time;
    arr = result;
}

//----------------------------------------------------------------------------------------------- copy for deque

void    insert_in_order_deq(std::deque<int> &a, int b)
{
	std::deque<int>::iterator it;
	it = std::lower_bound(a.begin(), a.end(), b);
	a.insert(it, b);
}

void	merge_insert_sort_deq(std::deque<int> &arr, clock_t *time)
{
	int size = arr.size();
	*time = clock();
	
	if (size <= 1)
		return;

	std::deque<int> min_v, max_v;
	for(int i = 0; i + 1 < size; i += 2) {
		if (arr[i] < arr[i + 1]) {
			min_v.push_back(arr[i]);
			max_v.push_back(arr[i + 1]);
		} else {
			min_v.push_back(arr[i + 1]);
			max_v.push_back(arr[i]);
		}
	}

	if (size % 2 != 0) {
		min_v.push_back(arr[size - 1]);
	}

	merge_insert_sort_deq(min_v, time);
	merge_insert_sort_deq(max_v, time);

	std::deque<int> result = min_v;
	for (std::deque<int>::iterator it = max_v.begin(); it != max_v.end(); it++)
	{
		insert_in_order_deq(result, *it);
	}
	
	*time = clock() - *time;
	arr = result;
}
