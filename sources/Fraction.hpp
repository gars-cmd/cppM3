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
    Fraction(int numerator = 0, int denominator = 1);
    ~Fraction();
    int getNumerator();
    int getDenominator();
    void setNumerator(int numerator);
    void setDenominator(int denominator);

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

    int getGCD(int a, int b)const;
    Fraction reduceFraction()const;
    std::string toString() const;

};

ariel::Fraction floatToFraction(float num);
std::pair<int, int> fixSign(int numerator, int denominator);

}
#endif //FRACTION_HPP


//Ressources
//https://www.geeksforgeeks.org/increment-and-decrement-operator-overloading-in-c/
//https://www.youtube.com/watch?v=mS9755gF66w
