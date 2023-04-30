/**
 * Demo file for the exercise on binary tree
 *
 * @author Evgeny Hershkovitch Neiterman
 * @since 2023-03
 */

#include <iostream>
#include <fstream>
#include <sstream>
#include <stdexcept>
using namespace std;

#include "sources/Fraction.hpp"

using namespace ariel;


int main() {
    // Fraction a(5,3), b(14,21);
    // cout << "a: " << a << "b: " << b << endl;
    // cout << "a+b" << a+b << endl; 
    // cout << "a-b" << a-b << endl; 
    // cout << "a/b" << a/b << endl; 
    // cout << "a*b" << a*b << endl; 
    // cout << "2.3*b" << 2.3*b << endl; 
    // cout << "a+2.421" << a+2.421 << endl; 
    // Fraction c = a+b-1;
    // cout << c++ << endl;
    // cout << --c << endl;
    //
    // cout << "c >=b ? : " << (c >= b) << endl;
    // if (a > 1.1) cout << " a is bigger than 1.1" << endl;
    // else cout << " a is smaller than 1.1" << endl;

    Fraction a(1, 2), b(3, 4);
    ostringstream os;

    // Test operator<<
    os << a; // Not thrwoing error
    cout << os.str() << '\n';

    istringstream is("5  6"); // Could also be "5,6" for ex
    istringstream bad_is("7");

    // Test operator>>
    bad_is >> b;
    cout << b.toString() << '\n';
    cout << b.getNumerator() << '\n';
    cout << b.getDenominator() << '\n';



}
