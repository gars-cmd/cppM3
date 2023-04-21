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
    Fraction f1 = Fraction(2,5);
    Fraction f2 = Fraction(3,7);
    Fraction f3 = f1 + f2;

    Fraction f4 = 0.75 + Fraction(1,4); 
    cout << f3.getNumerator()<< '\n';
    cout << f3.getDenominator() << '\n';
    cout << f4 << '\n';
}
