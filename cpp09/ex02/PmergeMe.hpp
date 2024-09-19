#ifndef PmergeMe_HPP
#define PmergeMe_HPP

#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <deque>
#include <cstdlib>
#include <algorithm>
#include <iomanip>

void	check_input(char** args);
void	print(std::vector<int> &a);
void	push_to_stack(std::deque<int> &a, std::vector<int> &b, char **args);

void	insert_in_order_vec(std::vector<int> &a, int b);
void	merge_insert_sort_vec(std::vector<int> &arr, clock_t *rime);

void	insert_in_order_deq(std::deque<int> &a, int b);
void	merge_insert_sort_deq(std::deque<int> &arr, clock_t *time);

#endif

