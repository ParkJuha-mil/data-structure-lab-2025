// sparsepoly.hpp
#ifndef SPARSE_POLY_HPP
#define SPARSE_POLY_HPP

#include <iostream>
#include <map>
#include <string>

// �������� ���ĵ� ��� ���׽� ǥ��: ���� �� ���
using Polynomial = std::map<int, double, std::greater<int>>;

// ���׽� �Է� �ޱ�
Polynomial inputPolynomial();

// ���׽� ���
void printPolynomial(const std::string& name, const Polynomial& poly);

// �� ���׽� ���ϱ�
Polynomial addPolynomials(const Polynomial& A, const Polynomial& B);

#endif // SPARSE_POLY_HPP
