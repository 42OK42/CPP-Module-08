/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okrahl <okrahl@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 11:23:23 by okrahl            #+#    #+#             */
/*   Updated: 2025/02/05 13:23:38 by okrahl           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"
#include <iostream>
#include <cstdlib>
#include <ctime>

int main() {
	try {
		// Test empty span
		std::cout << "Testing empty span:" << std::endl;
		Span emptySpan(5);
		try {
			std::cout << "Trying to get shortest span from empty span..." << std::endl;
			emptySpan.shortestSpan();
		} catch (const std::exception& e) {
			std::cout << "Exception caught: " << e.what() << std::endl;
		}

		// Test span with one number
		std::cout << "\nTesting span with one number:" << std::endl;
		Span oneNumSpan(5);
		oneNumSpan.addNumber(5);
		try {
			std::cout << "Trying to get longest span from span with one number..." << std::endl;
			oneNumSpan.longestSpan();
		} catch (const std::exception& e) {
			std::cout << "Exception caught: " << e.what() << std::endl;
		}

		// Original tests
		std::cout << "\nOriginal tests:" << std::endl;
		Span sp = Span(5);
		sp.addNumber(6);
		sp.addNumber(3);
		sp.addNumber(17);
		sp.addNumber(9);
		sp.addNumber(11);
		
		std::cout << "Shortest span: " << sp.shortestSpan() << std::endl;
		std::cout << "Longest span: " << sp.longestSpan() << std::endl;

		// Test with 10000 numbers
		Span bigSpan(10000);

		// Initialize random seed with current time
		std::srand(static_cast<unsigned int>(std::time(NULL)));

		std::cout << "\nAdding 10000 random numbers..." << std::endl;

		// Create a vector with 10000 random numbers
		std::vector<int> randomNumbers;
		for (int i = 0; i < 10000; i++) {
			randomNumbers.push_back(rand());
		}

		bigSpan.addRange(randomNumbers.begin(), randomNumbers.end());

		std::cout << "\nBig Span Test (10000 numbers):" << std::endl;
		std::cout << "Shortest span: " << bigSpan.shortestSpan() << std::endl;
		std::cout << "Longest span: " << bigSpan.longestSpan() << std::endl;

		// Test full span exception
		std::cout << "\nTesting full span:" << std::endl;
		Span smallSpan(1);
		smallSpan.addNumber(5);
		try {
			smallSpan.addNumber(3); // Should throw exception
		} catch (const std::exception& e) {
			std::cout << "Exception caught: " << e.what() << std::endl;
		}

	} catch (const std::exception& e) {
		std::cout << "Exception caught: " << e.what() << std::endl;
	}

	return 0;
} 