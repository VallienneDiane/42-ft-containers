/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvallien <dvallien@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 14:15:18 by dvallien          #+#    #+#             */
/*   Updated: 2023/01/19 11:48:15 by dvallien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <vector>
#include <iterator>
#include "../incs/Vector.hpp"

int main(void)
{
	std::cout << " -------------- FT::VECTOR --------------- " << std::endl;

	ft::vector<int> test01;
	ft::vector<int> test01bis;
	for (int j = 0; j < 15; j++)
	{
		test01.push_back(j);
	}
	std::cout << "size : " << test01.size() << std::endl;
	std::cout << "capacity : " << test01.capacity() << std::endl;

	test01.resize(7, 42);

	std::cout << std::endl;
	for(size_t i = 0; i < test01.size(); i++)
		std::cout << "at " << i << ": " << test01.at(i) << std::endl;
	std::cout << std::endl;

	std::cout << "size : " << test01.size() << std::endl;
	std::cout << "capacity : " << test01.capacity() << std::endl;

////////////////////////////////////////////////////////////////////////////////////
	std::cout << " -------------- STD::VECTOR --------------- " << std::endl;
	
	std::vector<int> test02;
	std::vector<int> test02bis;
	for (int j = 0; j < 15; j++)
	{
		test02.push_back(j);
	}
	std::cout << "size : " << test02.size() << std::endl;
	std::cout << "capacity : " << test02.capacity() << std::endl;

	test02.resize(7, 42);
	
	std::cout << std::endl;
	for(size_t i = 0; i < test02.size(); i++)
		std::cout << "at " << i << ": " << test02.at(i) << std::endl;
	std::cout << std::endl;
	std::cout << "size : " << test02.size() << std::endl;
	std::cout << "capacity : " << test02.capacity() << std::endl;
}

// INSERT WITH ITERATORS
// std::cout << " -------------- FT::VECTOR --------------- " << std::endl;

// 	ft::vector<int> test01;
// 	for (int j = 0; j < 15; j++)
// 	{
// 		test01.push_back(j);
// 	}
// 	std::cout << "size : " << test01.size() << std::endl;
// 	std::cout << "capacity : " << test01.capacity() << std::endl;

// 	ft::vector<int>::iterator it;

// 	it = test01.begin();
// 	test01.insert(it+2, it+10, it+18);

// 	std::cout << std::endl;
// 	for(int i = 0; i < test01.size(); i++)
// 		std::cout << "at " << i << ": " << test01.at(i) << std::endl;
// 	std::cout << std::endl;

// 	std::cout << "size : " << test01.size() << std::endl;
// 	std::cout << "capacity : " << test01.capacity() << std::endl;

// ////////////////////////////////////////////////////////////////////////////////////
// 	std::cout << " -------------- STD::VECTOR --------------- " << std::endl;
	
// 	std::vector<int> test02;
// 	for (int j = 0; j < 15; j++)
// 	{
// 		test02.push_back(j);
// 	}
// 	std::cout << "size : " << test02.size() << std::endl;
// 	std::cout << "capacity : " << test02.capacity() << std::endl;

// 	std::vector<int>::iterator it2;

// 	it2 = test02.begin();
// 	test02.insert(it2+2, it2+10, it2+18);

// 	std::cout << std::endl;
// 	for(int i = 0; i < test02.size(); i++)
// 		std::cout << "at " << i << ": " << test02.at(i) << std::endl;
// 	std::cout << std::endl;
// 	std::cout << "size : " << test02.size() << std::endl;
// 	std::cout << "capacity : " << test02.capacity() << std::endl;
//SWAP
// 	ft::vector<int> test;
// 	ft::vector<int> test2;
	
// 	for (int j = 0; j < 12; j++)
// 	{
// 		test.push_back(j);
// 	}
// 	for (int j = 80; j < 85; j++)
// 	{
// 		test2.push_back(j);
// 	}
	
// 	for(int i = 0; i < test.size(); i++)
// 		std::cout << "TEST at " << i << ": " << test.at(i) << std::endl;
// 	std::cout << "size : " << test.size() << std::endl;
// 	std::cout << "capacity : " << test.capacity() << std::endl;
		
// 	for(int i = 0; i < test2.size(); i++)
// 		std::cout << "TEST2 at " << i << ": " << test2.at(i) << std::endl;
// 	std::cout << "size : " << test2.size() << std::endl;
// 	std::cout << "capacity : " << test2.capacity() << std::endl;
	
// 	std::cout << "--------------------------- SWAP !!!" << std::endl;
// 	test.swap(test2);
	
// 	for(int i = 0; i < test.size(); i++)
// 		std::cout << "TEST at " << i << ": " << test.at(i) << std::endl;
// 	std::cout << "size : " << test.size() << std::endl;
// 	std::cout << "capacity : " << test.capacity() << std::endl;
		
// 	for(int i = 0; i < test2.size(); i++)
// 		std::cout << "TEST2 at " << i << ": " << test2.at(i) << std::endl;
// 	std::cout << "size : " << test2.size() << std::endl;
// 	std::cout << "capacity : " << test2.capacity() << std::endl;

	
// ////////////////////////////////////////////////////////////////////////////////////
// 	std::cout << " -------------- STD::VECTOR --------------- " << std::endl;
	
// 	std::vector<int> test3;
// 	std::vector<int> test4;
	
// 	for (int j = 0; j < 12; j++)
// 	{
// 		test3.push_back(j);
// 	}
// 	for (int j = 80; j < 85; j++)
// 	{
// 		test4.push_back(j);
// 	}
	
// 	for(int i = 0; i < test3.size(); i++)
// 		std::cout << "TEST3 at " << i << ": " << test3.at(i) << std::endl;
// 	std::cout << "size : " << test3.size() << std::endl;
// 	std::cout << "capacity : " << test3.capacity() << std::endl;
		
// 	for(int i = 0; i < test4.size(); i++)
// 		std::cout << "TEST4 at " << i << ": " << test4.at(i) << std::endl;
// 	std::cout << "size : " << test4.size() << std::endl;
// 	std::cout << "capacity : " << test4.capacity() << std::endl;
	
// 	std::cout << "------------------------------- SWAP !!!" << std::endl;
// 	test3.swap(test4);
	
// 	for(int i = 0; i < test3.size(); i++)
// 		std::cout << "TEST3 at " << i << ": " << test3.at(i) << std::endl;
// 	std::cout << "size : " << test3.size() << std::endl;
// 	std::cout << "capacity : " << test3.capacity() << std::endl;
		
// 	for(int i = 0; i < test4.size(); i++)
// 		std::cout << "TEST4 at " << i << ": " << test4.at(i) << std::endl;
// 	std::cout << "size : " << test4.size() << std::endl;
// 	std::cout << "capacity : " << test4.capacity() << std::endl;
// END OF SWAP

	// test.assign(it, test.end()-1);
	// test4.assign(test2.begin(), test2.end());
	// std::vector<int> test4(test2.begin(), test2.end());
	// for(int i = 0; i < test4.size(); i++)
	// 	std::cout << "at " << i << ": " << test4.at(i) << std::endl;
	
	// std::cout << "size : " << test.size() << std::endl;
	// std::cout << "capacity : " << test.capacity() << std::endl;
	// it2 = test2.begin();
	// it2bis = test2.begin()+5;
	// it2 = test2.rbegin();
	// it2bis = test2.rbegin()+5;
	// 8 + it2; //operator+ non membre
	// it2 + 8; //operator+ membre
	// std::cout << "it2       : " << *(it2) << std::endl;
	// std::cout << "it2 bis   : " << *(it2bis) << std::endl;
	// std::cout << "operator : " << (it2 >= it2bis) << std::endl;
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