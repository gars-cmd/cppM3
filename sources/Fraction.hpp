#ifndef FRACTION_HPP
#define FRACTION_HPP

#include <iostream>
#include <ostream>
#include <string>

namespace ariel {


class Fraction
{
private:
    int numerator , denominator;
public:
    Fraction();
    Fraction(int numerator , int denominator );
    Fraction(double number);
    ~Fraction();
    int getNumerator();
    int getDenominator();
    void setNumerator(int numerator);
    void setDenominator(int denominator);
    Fraction(const Fraction& other) noexcept;
    Fraction& operator=(const Fraction& other) noexcept;
    Fraction (ariel::Fraction&& other) noexcept;
    Fraction& operator=(Fraction&& other) noexcept;

    Fraction operator+(const Fraction& other) const;
    friend Fraction operator+(const Fraction& other, double number) ;
    friend Fraction operator+(double number, const Fraction&) ;

    Fraction operator-(const Fraction& other) const;
    friend Fraction operator-(const Fraction& other, double number) ;
    friend Fraction operator-(double number, const Fraction& other) ;

    Fraction operator*(const Fraction& other) const;
    friend Fraction operator*(const Fraction& other, double number) ;
    friend Fraction operator*(double number, const Fraction& other) ;

    Fraction operator/(const Fraction& other) const;
    friend Fraction operator/(const Fraction& other, double number) ;
    friend Fraction operator/(double number, const Fraction& other) ;

    bool operator==(const Fraction& other) const;
    friend bool operator==(const Fraction& other, double number) ;
    friend bool operator==(double number, const Fraction& other) ;

    bool operator!=(const Fraction& other) const;
    friend bool operator!=(const Fraction& other, double number) ;
    friend bool operator!=(double number, const Fraction& other) ;

    bool operator>(const Fraction& other) const;
    friend bool operator>(const Fraction& other, double number) ;
    friend bool operator>(double number, const Fraction& other) ;

    bool  operator<(const Fraction& other) const;
    friend bool operator<(const Fraction& other, double number) ;
    friend bool operator<(double number, const Fraction& other) ;

    bool operator>=(const Fraction& other) const;
    friend bool operator>=(const Fraction& other, double number) ;
    friend bool operator>=(double number, const Fraction& other) ;

    bool  operator<=(const Fraction& other) const;
    friend bool operator<=(const Fraction& other, double number) ;
    friend bool operator<=(double number, const Fraction& other) ;

    Fraction operator++();
    Fraction operator++(int);

    Fraction operator--();
    Fraction operator--(int);

    friend std::ostream& operator<<(std::ostream& stream, const Fraction& other);
    friend std::istream& operator>>(std::istream& stream, Fraction& other);

    int getGCD(int num1, int num2)const;
    Fraction reduceFraction()const;
    std::string toString() const;

};

ariel::Fraction doubleToFraction(double num);
std::pair<int, int> fixSign(int numerator, int denominator);
bool isValidStream(int numerator, int denominator);
bool checkInteger(std::string input);
int addCheckOverflow(int a, int b);
int subCheckOverflow(int a, int b);
int mulCheckOverflow(int a, int b);
ariel::Fraction truncFraction(ariel::Fraction frac);
unsigned int absu(int value);

}
#endif //FRACTION_HPP


//Ressources
//https://www.geeksforgeeks.org/increment-and-decrement-operator-overloading-in-c/
//https://www.youtube.com/watch?v=mS9755gF66w
