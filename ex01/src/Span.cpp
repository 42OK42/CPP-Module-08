/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okrahl <okrahl@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 11:22:58 by okrahl            #+#    #+#             */
/*   Updated: 2025/01/06 11:23:00 by okrahl           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

Span::Span(unsigned int N) : _N(N) {}

Span::Span(const Span& other) : _N(other._N), _numbers(other._numbers) {}

Span& Span::operator=(const Span& other) {
	if (this != &other) {
		_N = other._N;
		_numbers = other._numbers;
	}
	return *this;
}

Span::~Span() {}

void Span::addNumber(int number) {
	if (_numbers.size() >= _N)
		throw std::runtime_error("Span is full");
	_numbers.push_back(number);
}

unsigned int Span::shortestSpan() const {
	if (_numbers.size() <= 1)
		throw std::runtime_error("Not enough numbers to find span");

	std::vector<int> sorted = _numbers;
	std::sort(sorted.begin(), sorted.end());
	
	unsigned int minSpan = static_cast<unsigned int>(sorted[1] - sorted[0]);
	for (size_t i = 2; i < sorted.size(); ++i) {
		unsigned int span = static_cast<unsigned int>(sorted[i] - sorted[i-1]);
		minSpan = std::min(minSpan, span);
	}
	return minSpan;
}

unsigned int Span::longestSpan() const {
	if (_numbers.size() <= 1)
		throw std::runtime_error("Not enough numbers to find span");

	std::vector<int>::const_iterator min = std::min_element(_numbers.begin(), _numbers.end());
	std::vector<int>::const_iterator max = std::max_element(_numbers.begin(), _numbers.end());
	
	return static_cast<unsigned int>(*max - *min);
} 