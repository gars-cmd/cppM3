#include "sources/Fraction.hpp"
#include "doctest.h"
#include <sstream>


TEST_CASE("Constructor , Getter , Setter") {
    ariel::Fraction f1(2, 5);
    ariel::Fraction f2(-3, 7);
    ariel::Fraction f3(-5, -11);
    ariel::Fraction f4(4, -9);

    CHECK(f1.getNumerator() == 2);
    CHECK(f1.getDenominator() == 5);
    CHECK(f2.getNumerator() == -3);
    CHECK(f2.getDenominator() == 7);
    CHECK(f3.getNumerator() == 5);
    CHECK(f3.getDenominator() == 11);
    CHECK(f4.getNumerator() == -4);
    CHECK(f4.getDenominator() == 9);
    CHECK_THROWS_AS(ariel::Fraction(3, 0), std::invalid_argument);

    f1.setNumerator(5);
    f2.setDenominator(-7);

    CHECK(f1.getNumerator() == 5);
    CHECK(f1.getDenominator() == 5);
    CHECK(f2.getNumerator() == 3);
    CHECK(f2.getDenominator() == 7);
    CHECK_THROWS_AS(f1.setDenominator(0), std::invalid_argument);

}

TEST_CASE("Addition test ") {
        ariel::Fraction f1(2, 5);
        ariel::Fraction f2(3, 7);
        ariel::Fraction f3 = f1 + f2;
        ariel::Fraction f4(-2, 5);
        ariel::Fraction f5 = f1 + f4;
        CHECK(f3.getNumerator() == 29);
        CHECK(f3.getDenominator() == 35);
        CHECK(f5.getNumerator() == 0);
        CHECK(f5.getDenominator() == 1);

        ariel::Fraction f7(2, 5);
        float num = 1.25;
        ariel::Fraction f8 = num + f7;
        CHECK(f8.getNumerator() == 33);
        CHECK(f8.getDenominator() == 20);
        ariel::Fraction f9(-2, 5);
        float num2 = -1.25;
        ariel::Fraction f10 = num + f9;
        CHECK(f10.getNumerator() == 17);
        CHECK(f10.getDenominator() == 20);
        ariel::Fraction f11(4, 5);
        float num3 = 1.25;
        ariel::Fraction f12 = f11 + num3;
        CHECK(f12.getNumerator() == 41);
        CHECK(f12.getDenominator() == 20);
}


TEST_CASE("Soustraction test ") {
    ariel::Fraction f1(3, 5);
    ariel::Fraction f2(2, 3);
    ariel::Fraction result = f1 - f2;
    ariel::Fraction f3(-4, 7);
    ariel::Fraction f4(-1, 5);
    ariel::Fraction f5(0, 2);
    ariel::Fraction f6(3, 8);

    CHECK(result.getNumerator() == 1);
    CHECK(result.getDenominator() == 15);

    result = f3 - f4;
    CHECK(result.getNumerator() == -11);
    CHECK(result.getDenominator() == 35);

    result = f5 - f6;
    CHECK(result.getNumerator() == -3);
    CHECK(result.getDenominator() == 8);

    ariel::Fraction f7(1, 4);
    ariel::Fraction f8(-3, 2);

    float num = 0.5;
    result = f7 - num;
    CHECK(result.getNumerator() == -1);
    CHECK(result.getDenominator() == 4);

    float num2 = -0.75;
    result = num2 - f8;
    CHECK(result.getNumerator() == 1);
    CHECK(result.getDenominator() == 8);

}
//
//
// TEST_CASE("Multiplication test ") {
//     ariel::Fraction f1(2, 5);
//     ariel::Fraction f2(3, 7);
//     ariel::Fraction f3(-4, 7);
//     ariel::Fraction f4(-1, 5);
//     ariel::Fraction f5(0, 2);
//     ariel::Fraction f6(3, 8);
//
//     ariel::Fraction result = f1 * f2;
//     CHECK(result.getNumerator() == 6);
//     CHECK(result.getDenominator() == 35);
//     //
//     result = f3 * f4;
//     CHECK(result.getNumerator() == 4);
//     CHECK(result.getDenominator() == 35);
//     //
//     result = f5 * f6;
//     CHECK(result.getNumerator() == 0);
//     CHECK(result.getDenominator() == 16);
//     //
//     ariel::Fraction f7(1, 4);
//     ariel::Fraction f8(-3, 2);
//
//     float num = 0.5;
//     result = f7 * num;
//     CHECK(result.getNumerator() == 1);
//     CHECK(result.getDenominator() == 8);
//
//     float num2 = -0.75;
//     result = num2 * f8;
//     CHECK(result.getNumerator() == 9);
//     CHECK(result.getDenominator() == 8);
// }
//
// TEST_CASE("Division test ") {
//     ariel::Fraction f1(2, 5);
//     ariel::Fraction f2(3, 7);
//     ariel::Fraction f3(-4, 7);
//     ariel::Fraction f4(-1, 5);
//     ariel::Fraction f5(0, 2);
//     ariel::Fraction f6(3, 8);
//
//     ariel::Fraction result = f1 / f2;
//     CHECK(result.getNumerator() == 14);
//     CHECK(result.getDenominator() == 15);
//
//     result = f3 / f4;
//     CHECK(result.getNumerator() == 20);
//     CHECK(result.getDenominator() == 7);
//
//     result = f5 / f6;
//     CHECK(result.getNumerator() == 0);
//     CHECK(result.getDenominator() == 1);
//
//     ariel::Fraction f7(1, 4);
//     ariel::Fraction f8(-3, 2);
//
//     float num = 0.5;
//     result = f7 / num;
//     CHECK(result.getNumerator() == 1);
//     CHECK(result.getDenominator() == 2);
//
//     float num2 = -0.75;
//     result = num2 / f8;
//     CHECK(result.getNumerator() == -1);
//     CHECK(result.getDenominator() == 6);
// }
//
//
// TEST_CASE("Equality test") {
//     ariel::Fraction f1(3, 4);
//     ariel::Fraction f2(3, 4);
//     ariel::Fraction f3(2, 3);
//     ariel::Fraction f4(5, 3);
//     ariel::Fraction f5(1, 6);
//     ariel::Fraction f6(1, 2);
//     ariel::Fraction f7(-1, 2);
//     ariel::Fraction f8(1, -2);
//     float num = 0.75;
//
//     CHECK(f1 == f2);
//     CHECK_FALSE(f3 == f4);
//     CHECK_FALSE(f5 == f6);
//     CHECK(f7 == f8);
//     CHECK(f1 == num);
// }
//
//
// TEST_CASE("Inequality test") {
//     ariel::Fraction f1(3, 4);
//     ariel::Fraction f2(2, 3);
//     ariel::Fraction f3(5, 3);
//     ariel::Fraction f4(1, 6);
//     ariel::Fraction f5(1, 2);
//     ariel::Fraction f6(-1, 2);
//     ariel::Fraction f87(1, -2);
//     float f10 = 0.75;
//
//     CHECK_FALSE(f1 != f1);
//     CHECK(f2 != f3);
//     CHECK(f4 != f5);
//     CHECK_FALSE(f6 != f87);
//     CHECK_FALSE(f1 != f10);
// }
//
//
// TEST_CASE("Greater than test") {
//     ariel::Fraction f1(2, 3);
//     ariel::Fraction f2(1, 3);
//     ariel::Fraction f3(-2, 3);
//     ariel::Fraction f4(1, -3);
//     ariel::Fraction f6(1, 2);
//     ariel::Fraction f7(2, 3);
//
//     CHECK(f1 > f2);
//     CHECK_FALSE(f2 > f1);
//     CHECK(f3 > f4);
//     CHECK_FALSE(f4 > f3);
//     CHECK(f1 > f6);
//     CHECK_FALSE(f6 > f1);
//     CHECK_FALSE(f7 > f1);
//     CHECK_FALSE(f1 > f7);
// }
//
//
// TEST_CASE("Less than test") {
//     ariel::Fraction f1(1, 2);
//     ariel::Fraction f2(3, 4);
//     ariel::Fraction f3(5, 6);
//     ariel::Fraction f4(-2, 5);
//     ariel::Fraction f5(1, -3);
//
//     CHECK(f1 < f2);
//     CHECK(f2 < f3);
//     CHECK(f4 < f1);
//     CHECK(f5 < f4);
//     CHECK_FALSE(f3 < f1);
// }
//
//
// TEST_CASE("Greater than Equal test") {
//     ariel::Fraction f1(1, 2);
//     ariel::Fraction f2(1, 3);
//     ariel::Fraction f3(1, 2);
//     float num2 = 0.3;
//     float num = 0.4;
//
//     CHECK((f1 >= f2) == true);
//     CHECK((f1 >= f3) == true);
//     CHECK((f1 >= num) == true);
//     CHECK((f1 >= num2) == false);
// }
//
//
// TEST_CASE("Less than Equal test") {
//     ariel::Fraction f1(3, 4);
//     ariel::Fraction f2(2, 5);
//     ariel::Fraction f3(6, 8);
//     ariel::Fraction f4(2, 2);
//
//     CHECK((f1 <= f2) == false);
//     CHECK((f2 <= f3) == true);
//     CHECK((f1 <= f4) == false);
//     CHECK((0.5 <= f1) == true);
//     CHECK((f1 <= 1.0) == true);
//     CHECK_FALSE((f1 <= 0.7) == true);
//
// }
//
//
// TEST_CASE("Increment test") {
//     ariel::Fraction f1(1, 2);
//     ariel::Fraction f2(3, 4);
//     ariel::Fraction f3(5, 6);
//     ariel::Fraction f4(7, 8);
//
//     CHECK((f1++) == ariel::Fraction(1, 2));
//     CHECK(f1 == ariel::Fraction(3, 2));
//     CHECK((f2++) == ariel::Fraction(3, 4));
//     CHECK(f2 == ariel::Fraction(7, 4));
//     CHECK((f3++) == ariel::Fraction(5, 6));
//     CHECK(f3 == ariel::Fraction(11, 6));
//     CHECK((f4++) == ariel::Fraction(7, 8));
//     CHECK(f4 == ariel::Fraction(15, 8));
// }
//
//
// TEST_CASE("Decrement test") {
//     ariel::Fraction f1(5, 2);
//     ariel::Fraction f2(7, 4);
//     ariel::Fraction f3(5, 4);
//     ariel::Fraction f4(7, 8);
//
//     CHECK((--f1) == ariel::Fraction(3, 2));
//     CHECK((--f2) == ariel::Fraction(-1, 4));
//     CHECK((f3--) == ariel::Fraction(5, 2));
//     CHECK(f3 == ariel::Fraction(1, 4));
//     CHECK((f4--) == ariel::Fraction(7, 8));
//     CHECK(f4 == ariel::Fraction(-1, 8));
// }
//
//
// TEST_CASE("cout test") {
//     ariel::Fraction f1(1, 2);
//     ariel::Fraction f2(-3, 4);
//     std::stringstream out;
//
//     out << f1;
//     CHECK(out.str() == "1/2");
//
//     out.str("");
//     out << f2;
//     CHECK(out.str() == "-3/4");
// }
//
// TEST_CASE("cin test") {
//     ariel::Fraction f1;
//     ariel::Fraction f2;
//     std::istringstream input("1/2 -3/4");
//
//     input >> f1;
//     CHECK(f1.toString() == "1/2");
//     input >> f2;
//     CHECK(f2.toString() == "-3/4");
// }

//Ressources : 
//https://stackoverflow.com/questions/31815230/how-to-test-input-and-output-overloaded-operator-in-c-gtest
//https://cplusplus.com/forum/general/30351/
