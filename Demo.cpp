/**
 * Demo file for the exercise on binary tree
 *
 * @author Evgeny Hershkovitch Neiterman
 * @since 2023-03
 */

#include <iostream>
#include <fstream>
#include <iterator>
#include <sstream>
#include <stdexcept>
using namespace std;

#include "sources/Fraction.hpp"

using namespace ariel;


int main() {
    ariel::Fraction f1(2, 5);
    ariel::Fraction f2(3, 7);
    ariel::Fraction f3(-4, 7);
    ariel::Fraction f4(-1, 5);
    ariel::Fraction f5(0, 2);
    ariel::Fraction f6(3, 8);

    ariel::Fraction result = f1 * f2;
    result.getNumerator() == 6;
    result.getDenominator() == 35;

    result = f3 * f4;
    result.getNumerator() == 4;
    result.getDenominator() == 35;

    result = f5 * f6;
    result.getNumerator() == 0;
    result.getDenominator() == 16;

    ariel::Fraction f7(1, 4);
    ariel::Fraction f8(-3, 2);

    float num = 0.5;
    result = f7 * num;
    result.getNumerator() == 1;
    result.getDenominator() == 8;
    
    float num2 = -0.75;
    result = num2 * f8;
    result.getNumerator() == 9;
    result.getDenominator() == 8;

}
