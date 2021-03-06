#include "Span.hpp"
#include <limits>
#include <numeric>
#include <stdexcept>

// Constructors & Destructor
Span::Span(uint n) : _n(n) {
  if (_n < 2)
    throw std::out_of_range("max size of at least 2 required");
}
Span::Span(const Span& other) : _n(other._n), _vec(other._vec) {}
Span::~Span() {}

// Methods
void Span::addNumber(int n) {
  if (_vec.size() >= _n)
    throw std::out_of_range("internal storage full");
  _vec.push_back(n);
}

size_t Span::shortestSpan() const {
  if (_vec.size() < 2)
    throw std::out_of_range("not enough numbers");

  std::vector<int> sorted = _vec;
  std::vector<int> result(_vec.size());

  std::sort(sorted.begin(), sorted.end());
  std::adjacent_difference(sorted.begin(), sorted.end(), result.begin());
  return *std::min_element(result.begin() + 1, result.end());
}

size_t Span::longestSpan() const {
  if (_vec.size() < 2)
    throw std::out_of_range("not enough numbers");

  const int min = *std::min_element(_vec.begin(), _vec.end());
  const int max = *std::max_element(_vec.begin(), _vec.end());
  return max - min;
}
