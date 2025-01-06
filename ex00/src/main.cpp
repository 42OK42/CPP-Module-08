/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okrahl <okrahl@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 11:02:20 by okrahl            #+#    #+#             */
/*   Updated: 2025/01/06 11:10:05 by okrahl           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "easyfind.hpp"
#include <iostream>
#include <vector>
#include <list>
#include <deque>

int main() {
	// Test with Vector
	std::vector<int> vec;
	vec.push_back(10);
	vec.push_back(20);
	vec.push_back(30);

	// Test with List
	std::list<int> lst;
	lst.push_back(100);
	lst.push_back(200);
	lst.push_back(300);

	// Test with Deque
	std::deque<int> deq;
	deq.push_back(1000);
	deq.push_back(2000);
	deq.push_back(3000);

	try {
		// Vector Tests
		std::cout << "Searching in Vector:" << std::endl;
		std::cout << "Search for 20: " << *easyfind(vec, 20) << std::endl;
		std::cout << "Search for 99: ";
		easyfind(vec, 99);  // This will throw an exception
	}
	catch (const std::exception& e) {
		std::cout << "Exception: " << e.what() << std::endl;
	}

	try {
		// List Tests
		std::cout << "\nSearching in List:" << std::endl;
		std::cout << "Search for 200: " << *easyfind(lst, 200) << std::endl;
		std::cout << "Search for 999: ";
		easyfind(lst, 999);  // This will throw an exception
	}
	catch (const std::exception& e) {
		std::cout << "Exception: " << e.what() << std::endl;
	}

	try {
		// Deque Tests
		std::cout << "\nSearching in Deque:" << std::endl;
		std::cout << "Search for 2000: " << *easyfind(deq, 2000) << std::endl;
		std::cout << "Search for 9999: ";
		easyfind(deq, 9999);  // This will throw an exception
	}
	catch (const std::exception& e) {
		std::cout << "Exception: " << e.what() << std::endl;
	}

	return 0;
} 