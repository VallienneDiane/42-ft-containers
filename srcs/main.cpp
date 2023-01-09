/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvallien <dvallien@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 14:15:18 by dvallien          #+#    #+#             */
/*   Updated: 2023/01/09 16:22:06 by dvallien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <vector>
#include <iterator>
#include "../incs/vector.hpp"

int main(void)
{
	std::cout << " -------------- FT::VECTOR --------------- " << std::endl;
	ft::vector<int> test;
	ft::vector<int>::iterator it;
	ft::vector<int>::iterator itbis;
	
	int i = 0;
	for (int j = 5; j < 10; j++)
	{
		test.push_back(j);
		i++;
		// std::cout << "ft::vector  value : " << ' ' << test[i] << std::endl;
	}
	it = test.begin();
	itbis = test.begin()+2;
	it+=2;
	std::cout << "it       : " << *(it) << std::endl;
	std::cout << "it bis   : " << *(itbis) << std::endl;
	std::cout << "operator : " << (it == itbis) << std::endl;
	
	// std::cout << "size : " << test.size() << std::endl;
	// std::cout << "capacity : " << test.capacity() << std::endl;
	// std::cout << "at 0: "<< test.at(0) << std::endl;
	// std::cout << "at 1: "<< test.at(1) << std::endl;
	// std::cout << "at 2: "<< test.at(2) << std::endl;
	// std::cout << "at 3: "<< test.at(3) << std::endl;
	// std::cout << "at 4: "<< test.at(4) << std::endl;
	// test.assign(it, test.end()-1);
	// std::cout << "size : " << test.size() << std::endl;
	// std::cout << "capacity : " << test.capacity() << std::endl;
	
////////////////////////////////////////////////////////////////////////////////////
	std::cout << " -------------- STD::VECTOR --------------- " << std::endl;
	std::vector<int> test2;
	std::vector<int>::iterator it2;
	std::vector<int>::iterator it2bis;
	
	i = 0;
	for (int j = 5; j < 10; j++)
	{
		test2.push_back(j);
		i++;
		// std::cout << "std::vector value : " << ' ' << test2[i] << std::endl;
	}
		
	it2 = test2.begin();
	it2bis = test2.begin()+2;
	it2+=2;
	std::cout << "it2       : " << *(it2) << std::endl;
	std::cout << "it2 bis   : " << *(it2bis) << std::endl;
	std::cout << "operator : " << (it2 == it2bis) << std::endl;
	// std::cout << "size : " << test2.size() << std::endl;
	// std::cout << "capacity : " << test2.capacity() << std::endl;
	// std::cout << "at 0: "<< test2.at(0) << std::endl;
	// std::cout << "at 1: "<< test2.at(1) << std::endl;
	// std::cout << "at 2: "<< test2.at(2) << std::endl;
	// std::cout << "at 3: "<< test2.at(3) << std::endl;
	// std::cout << "at 4: "<< test2.at(4) << std::endl;
	// test2.assign(it2, test2.end()-1);
	// std::cout << "size : " << test2.size() << std::endl;
	// std::cout << "capacity : " << test2.capacity() << std::endl;
}

// test.swap(test2);
// test.resize(16);
// test.pop_back();


// #include <string>
// #include <deque>
// #if 1 //CREATE A REAL STL EXAMPLE
// 	#include <map>
// 	#include <stack>
// 	#include <vector>
// 	namespace ft = std;
// #else
// 	#include <map.hpp>
// 	#include <stack.hpp>
// 	#include <vector.hpp>
// #endif

// #include <stdlib.h>

// #define MAX_RAM 4294967296
// #define BUFFER_SIZE 4096
// struct Buffer
// {
// 	int idx;
// 	char buff[BUFFER_SIZE];
// };

// #define COUNT (MAX_RAM / (int)sizeof(Buffer))

// template<typename T>
// class MutantStack : public ft::stack<T>
// {
// public:
// 	MutantStack() {}
// 	MutantStack(const MutantStack<T>& src) { *this = src; }
// 	MutantStack<T>& operator=(const MutantStack<T>& rhs) 
// 	{
// 		this->c = rhs.c;
// 		return *this;
// 	}
// 	~MutantStack() {}

// 	typedef typename ft::stack<T>::container_type::iterator iterator;

// 	iterator begin() { return this->c.begin(); }
// 	iterator end() { return this->c.end(); }
// };

// int main(int argc, char** argv) {
// 	if (argc != 2)
// 	{
// 		std::cerr << "Usage: ./container seed" << std::endl;
// 		std::cerr << "Provide a seed please" << std::endl;
// 		std::cerr << "Count value:" << COUNT << std::endl;
// 		return 1;
// 	}
// 	const int seed = atoi(argv[1]);
// 	srand(seed);

// 	ft::vector<std::string> vector_str;
// 	ft::vector<int> vector_int;
// 	ft::stack<int> stack_int;
// 	ft::vector<Buffer> vector_buffer;
// 	ft::stack<Buffer, std::deque<Buffer> > stack_deq_buffer;
// 	ft::map<int, int> map_int;

// 	for (int i = 0; i < COUNT; i++)
// 	{
// 		vector_buffer.push_back(Buffer());
// 	}

// 	for (int i = 0; i < COUNT; i++)
// 	{
// 		const int idx = rand() % COUNT;
// 		vector_buffer[idx].idx = 5;
// 	}
// 	ft::vector<Buffer>().swap(vector_buffer);

// 	try
// 	{
// 		for (int i = 0; i < COUNT; i++)
// 		{
// 			const int idx = rand() % COUNT;
// 			vector_buffer.at(idx);
// 			std::cerr << "Error: THIS VECTOR SHOULD BE EMPTY!!" <<std::endl;
// 		}
// 	}
// 	catch(const std::exception& e)
// 	{
// 		//NORMAL ! :P
// 	}
	
// 	for (int i = 0; i < COUNT; ++i)
// 	{
// 		map_int.insert(ft::make_pair(rand(), rand()));
// 	}

// 	int sum = 0;
// 	for (int i = 0; i < 10000; i++)
// 	{
// 		int access = rand();
// 		sum += map_int[access];
// 	}
// 	std::cout << "should be constant with the same seed: " << sum << std::endl;

// 	{
// 		ft::map<int, int> copy = map_int;
// 	}
// 	MutantStack<char> iterable_stack;
// 	for (char letter = 'a'; letter <= 'z'; letter++)
// 		iterable_stack.push(letter);
// 	for (MutantStack<char>::iterator it = iterable_stack.begin(); it != iterable_stack.end(); it++)
// 	{
// 		std::cout << *it;
// 	}
// 	std::cout << std::endl;
// 	return (0);
// }