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
    Fraction(float number);
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
    friend Fraction operator+(const Fraction& other, float number) ;
    friend Fraction operator+(float number, const Fraction&) ;

    Fraction operator-(const Fraction& other) const;
    friend Fraction operator-(const Fraction& other, float number) ;
    friend Fraction operator-(float number, const Fraction& other) ;

    Fraction operator*(const Fraction& other) const;
    friend Fraction operator*(const Fraction& other, float number) ;
    friend Fraction operator*(float number, const Fraction& other) ;

    Fraction operator/(const Fraction& other) const;
    friend Fraction operator/(const Fraction& other, float number) ;
    friend Fraction operator/(float number, const Fraction& other) ;

    bool operator==(const Fraction& other) const;
    friend bool operator==(const Fraction& other, float number) ;
    friend bool operator==(float number, const Fraction& other) ;

    bool operator!=(const Fraction& other) const;
    friend bool operator!=(const Fraction& other, float number) ;
    friend bool operator!=(float number, const Fraction& other) ;

    bool operator>(const Fraction& other) const;
    friend bool operator>(const Fraction& other, float number) ;
    friend bool operator>(float number, const Fraction& other) ;

    bool  operator<(const Fraction& other) const;
    friend bool operator<(const Fraction& other, float number) ;
    friend bool operator<(float number, const Fraction& other) ;

    bool operator>=(const Fraction& other) const;
    friend bool operator>=(const Fraction& other, float number) ;
    friend bool operator>=(float number, const Fraction& other) ;

    bool  operator<=(const Fraction& other) const;
    friend bool operator<=(const Fraction& other, float number) ;
    friend bool operator<=(float number, const Fraction& other) ;

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

ariel::Fraction floatToFraction(float num);
std::pair<int, int> fixSign(int numerator, int denominator);
bool isValidStream(int numerator, int denominator);
bool checkInteger(std::string input);

}
#endif //FRACTION_HPP


//Ressources
//https://www.geeksforgeeks.org/increment-and-decrement-operator-overloading-in-c/
//https://www.youtube.com/watch?v=mS9755gF66w
