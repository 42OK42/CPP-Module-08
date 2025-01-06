/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okrahl <okrahl@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 11:22:35 by okrahl            #+#    #+#             */
/*   Updated: 2025/01/06 11:24:27 by okrahl           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
# define SPAN_HPP

# include <vector>
# include <algorithm>
# include <stdexcept>

class Span {
private:
	unsigned int _N;              // Max ammount of numbers
	std::vector<int> _numbers;    // Vector to save numbers in

public:
	// Orthodox Canonical Form
	Span(unsigned int N);
	Span(const Span& other);
	Span& operator=(const Span& other);
	~Span();

	// Member functions
	void addNumber(int number);
	unsigned int shortestSpan() const;
	unsigned int longestSpan() const;

	// Bonus: Add multiple numbers at once
	template<typename Iterator>
	void addRange(Iterator begin, Iterator end) {
		if (_numbers.size() + std::distance(begin, end) > _N)
			throw std::runtime_error("Not enough space for range");
		_numbers.insert(_numbers.end(), begin, end);
	}
};

#endif 