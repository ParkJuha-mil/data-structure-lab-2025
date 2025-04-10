// sparsepoly.hpp
#ifndef SPARSE_POLY_HPP
#define SPARSE_POLY_HPP

#include <iostream>
#include <map>
#include <string>

// 내림차순 정렬된 희소 다항식 표현: 차수 → 계수
using Polynomial = std::map<int, double, std::greater<int>>;

// 다항식 입력 받기
Polynomial inputPolynomial();

// 다항식 출력
void printPolynomial(const std::string& name, const Polynomial& poly);

// 두 다항식 더하기
Polynomial addPolynomials(const Polynomial& A, const Polynomial& B);

#endif // SPARSE_POLY_HPP
