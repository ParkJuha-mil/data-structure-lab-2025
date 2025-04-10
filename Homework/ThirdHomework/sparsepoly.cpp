// sparsepoly.cpp
#include "sparsepoly.hpp"

Polynomial inputPolynomial() {
    Polynomial poly;
    int n;
    std::cout << "항의 개수를 입력하세요: ";
    std::cin >> n;
    for (int i = 0; i < n; ++i) {
        double coeff;
        int exp;
        std::cout << i + 1 << "번째 항의 계수와 차수를 입력하세요 (예:계수 차수): ";
        std::cin >> coeff >> exp;
        if (coeff != 0) {
            poly[exp] += coeff;
        }
    }
    return poly;
}

void printPolynomial(const std::string& name, const Polynomial& poly) {
    std::cout << name << ": ";
    bool first = true;
    for (const auto& term : poly) {
        if (!first) std::cout << " + ";
        std::cout << term.second << "x^" << term.first;
        first = false;
    }
    if (poly.empty()) {
        std::cout << "0";
    }
    std::cout << std::endl;
}

Polynomial addPolynomials(const Polynomial& A, const Polynomial& B) {
    Polynomial result = A;
    for (const auto& term : B) {
        result[term.first] += term.second;
    }

    // 계수가 0인 항 제거
    for (auto it = result.begin(); it != result.end(); ) {
        if (it->second == 0.0) {
            it = result.erase(it);
        }
        else {
            ++it;
        }
    }
    return result;
}

// 메인 함수 포함
int main() {
    std::cout << "다항식 A 입력" << std::endl;
    Polynomial A = inputPolynomial();

    std::cout << "다항식 B 입력" << std::endl;
    Polynomial B = inputPolynomial();

    Polynomial C = addPolynomials(A, B);

    printPolynomial("Poly A", A);
    printPolynomial("Poly B", B);
    printPolynomial("Poly C", C);

    return 0;
}
