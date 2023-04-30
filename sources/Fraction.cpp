#include "Fraction.hpp"
#include <cctype>
#include <cmath>
#include <cstddef>
#include <iostream>
#include <istream>
#include <iterator>
#include <ostream>
#include <stdexcept>
#include <string>
#include <utility>

// ############### CONSTRUCTOR,GETTER,SETTER #############

ariel::Fraction::~Fraction(){

}

ariel::Fraction::Fraction(){
    this->numerator = 0;
    this->numerator = 1;
}

ariel::Fraction::Fraction(int numerator, int denominator){
   if (denominator == 0) {
        throw std::runtime_error("0 cannot be at denominator");
   }
    std::pair<int,int> fixedPair = fixSign(numerator, denominator);
    this->numerator = fixedPair.first;
    this->denominator = fixedPair.second;
}

ariel::Fraction::Fraction(float number){
    ariel::Fraction frac = floatToFraction(number);
    this->numerator = frac.numerator;
    this->denominator = frac.denominator;
}

// copy constructor
ariel::Fraction::Fraction(const Fraction& other) noexcept{
    this->numerator = other.numerator;
    this->denominator = other.denominator;
}

//copy assignement operator
ariel::Fraction& ariel::Fraction::operator=(const Fraction& other) noexcept{
    if (this != &other) {
        this->numerator = 0 ;
        this->numerator = 1 ;

        this->numerator = other.numerator;
        this->denominator = other.denominator;
    }
    return *this;
}

// move constructor 
ariel::Fraction::Fraction(ariel::Fraction&& other) noexcept{
    numerator = other.numerator;
    denominator = other.denominator;
    other.numerator = 0;
    other.denominator = 1;
}

//move assignement operator
ariel::Fraction& ariel::Fraction::operator=(ariel::Fraction&& other) noexcept{
    if (this != &other) {
        numerator = 0;
        denominator = 1;

        numerator = other.numerator;
        denominator = other.denominator;

        other.numerator = 0;
        other.denominator = 1;
    }
    return *this;
}

int ariel::Fraction::getNumerator(){

    return  this->numerator;
}

int ariel::Fraction::getDenominator(){
    return  this->denominator;
}

void ariel::Fraction::setNumerator(int numerator){

    std::pair<int,int> fixedPair = fixSign(numerator, this->denominator);
    this->numerator = fixedPair.first;
    this->denominator = fixedPair.second;
}

void ariel::Fraction::setDenominator(int denominator){
    if (denominator == 0) {
        throw std::runtime_error("cannot set denominator to 0");
    }
    std::pair<int,int> fixedPair = fixSign(this->numerator, denominator);
    this->numerator = fixedPair.first; this->denominator = fixedPair.second;
}

// ############### ADDITION #############

ariel::Fraction ariel::Fraction::operator+(const Fraction &other) const{
    int numerator = (this->numerator * other.denominator)
                  + (this->denominator * other.numerator);
    int denominator = this->denominator * other.denominator;
    return ariel::Fraction(numerator, denominator).reduceFraction();
}

ariel::Fraction ariel::operator+(const ariel::Fraction& other, const float number){
    ariel::Fraction fractioned = ariel::floatToFraction(number);
    return other + fractioned;
}

ariel::Fraction ariel::operator+(const float number, const ariel::Fraction& other){
    return other + number;
}

// ############### SOUSTRACTION #############

ariel::Fraction ariel::Fraction::operator-(const Fraction &other) const{
    int numerator = (this->numerator * other.denominator)
                  - (this->denominator * other.numerator);
    int denominator = this->denominator * other.denominator;
    std::pair<int,int> fixedPair = fixSign(numerator, denominator);
    numerator = fixedPair.first; denominator = fixedPair.second;
    return ariel::Fraction(numerator, denominator).reduceFraction();
}

ariel::Fraction ariel::operator-(const ariel::Fraction& other, const float number){
    ariel::Fraction fractioned = ariel::floatToFraction(number);
    return other - fractioned;
}

ariel::Fraction ariel::operator-(const float number, const ariel::Fraction& other){
    ariel::Fraction fractioned = ariel::floatToFraction(number);
    return fractioned - other;
}

// ############### MULTIPLICATION #############

ariel::Fraction ariel::Fraction::operator*(const Fraction &other) const{
    int new_numerator = this->numerator * other.numerator;
    int new_denominator = this->denominator * other.denominator;
    return  ariel::Fraction(new_numerator, new_denominator).reduceFraction();
}

ariel::Fraction ariel::operator*(const ariel::Fraction& other, const float number){
    ariel::Fraction fractioned = ariel::floatToFraction(number);
    return other * fractioned;
}

ariel::Fraction ariel::operator*(const float number, const ariel::Fraction& other){
    return other * number;
}

// ############### DIVISION #############

ariel::Fraction ariel::Fraction::operator/(const ariel::Fraction &other) const{
    int new_numerator = this->numerator * other.denominator;
    int new_denominator = this->denominator * other.numerator;
    return ariel::Fraction(new_numerator, new_denominator).reduceFraction();
}

ariel::Fraction ariel::operator/(const ariel::Fraction& other, const float number){
    ariel::Fraction fractioned = ariel::floatToFraction(number);
    return  other / fractioned;
}

ariel::Fraction ariel::operator/(const float number, const ariel::Fraction& other){
    ariel::Fraction fractioned = ariel::floatToFraction(number);
    return  fractioned / other;
}

// ############### EQUALITY #############

bool ariel::Fraction::operator==(const ariel::Fraction &other) const{
    ariel::Fraction f1 = reduceFraction();
    ariel::Fraction f2 = other.reduceFraction();
    return (f1.getNumerator() == f2.getNumerator()) 
        && (f1.getDenominator() == f2.getDenominator());
}

bool ariel::operator==(const ariel::Fraction &other, const float number) {
    ariel::Fraction frac = ariel::floatToFraction(number);
    return other == frac;
}

bool ariel::operator==(const float number, const ariel::Fraction &other) {
    return other == number;
}

// ############### INEQUALITY #############

bool ariel::Fraction::operator!=(const ariel::Fraction &other) const{
    return !(*this == other);

}

bool ariel::operator!=(const ariel::Fraction &other, const float number) {
    return !(other == number);
}

bool ariel::operator!=(const float number, const ariel::Fraction &other) {
    return (other != number);
}


// ############### GREATER THAN #############

bool ariel::Fraction::operator>(const ariel::Fraction &other) const{
    int firstNumerator = this->numerator * other.denominator;
    int secondNumerator = other.numerator * this->denominator;
    return firstNumerator > secondNumerator;
}

bool ariel::operator>(const ariel::Fraction &other, const float number) {
    ariel::Fraction frac = ariel::floatToFraction(number);
    return (other > frac);
}

bool ariel::operator>(const float number, const ariel::Fraction &other) {
    ariel::Fraction frac = ariel::floatToFraction(number);
    return (frac > other);
}

// ############### LESS THAN #############

bool ariel::Fraction::operator<(const ariel::Fraction &other) const{
    int firstNumerator = this->numerator * other.denominator;
    int secondNumerator = other.numerator * this->denominator;
    return firstNumerator < secondNumerator;
}

bool ariel::operator<(const ariel::Fraction &other, const float number) {
    ariel::Fraction frac = ariel::floatToFraction(number);
    return (other < frac);
}

bool ariel::operator<(const float number, const ariel::Fraction &other) {
    ariel::Fraction frac = ariel::floatToFraction(number);
    return (frac < other);
}

// ############### GREATER THAN EQUAL #############

bool ariel::Fraction::operator>=(const ariel::Fraction &other) const{
    return ( (*this > other) || (*this == other) );
}

bool ariel::operator>=(const ariel::Fraction &other, const float number) {
    return ( (other > number) || (other == number) );
}

bool ariel::operator>=(const float number, const ariel::Fraction &other) {
    return  ( (number > other) || (number == other) );
}

// ############### LESS THAN EQUAL #############

bool ariel::Fraction::operator<=(const ariel::Fraction &other) const{
    return ( (*this < other) || (*this == other) );
}

bool ariel::operator<=(const ariel::Fraction &other, const float number) {
    return  ( (other < number) || (other == number) );
}

bool ariel::operator<=(const float number, const ariel::Fraction &other) {
    return  ( (number < other) || (number == other) );
}

// ############### INCREMENT ###############

ariel::Fraction ariel::Fraction::operator++(){
    this->numerator += this->denominator;
    return *this;
}

ariel::Fraction ariel::Fraction::operator++(int){
    ariel::Fraction tmp = *this;
    this->numerator += denominator;
    return tmp;
}

// ############### DECREMENT ###############

ariel::Fraction ariel::Fraction::operator--(){
    this->numerator -= this->denominator;
    return *this;
}

ariel::Fraction ariel::Fraction::operator--(int){
    ariel::Fraction tmp = *this;
    this->numerator -= denominator;
    return tmp;
}

// ############### COUT ###############

std::ostream& ariel::operator<<(std::ostream& stream, const ariel::Fraction& other){
    Fraction frac = other.reduceFraction();
    return stream << frac.numerator << '/' << frac.denominator ;
}

// ############### CIN ###############

std::istream& ariel::operator>>(std::istream& stream, ariel::Fraction& other){
    int numerator = 0, denominator = 0;
    stream >> numerator >> denominator ;
    bool check = isValidStream(numerator, denominator);
    if (check == true) {
        other = ariel::Fraction(numerator, denominator).reduceFraction();
    }else {
        throw std::runtime_error("Invalid input format");
    }
    return stream;
}

// ############### UTILS ###############

bool ariel::isValidStream(int numerator, int denominator){
    bool isNumerator = ariel::checkInteger(std::to_string(numerator));
    bool isDenominator = ariel::checkInteger(std::to_string(denominator));
    return isNumerator && isDenominator && (denominator != 0);
}

bool ariel::checkInteger(std::string input)
{
    bool isNeg=false;
    size_t itr=0;
    if(input[0] == '-')
    {
        isNeg=true;
        itr=1;
    }
 
    for(size_t i = itr ; i < input.length() ; i++)
    {
        if(!std::isdigit(input[i])){
            return false;
        }
    }
    return true;
}

int ariel::Fraction::getGCD(int num1, int num2) const {

    //  need to do abs because the old function didn't work for negative numbers
    num1 = std::abs(num1); num2 = std::abs(num2);

    int result = std::min(num1, num2);
    while (result > 0) {
        if (num1 % result == 0 & num2 % result == 0) {
            break;
        }
    result--;
    }
    return result;
}

// reduce the fraction to is lowest form (with help of gcd)
ariel::Fraction ariel::Fraction::reduceFraction()const {
    int gcd = ariel::Fraction::getGCD(this->numerator,this->denominator);
    if (gcd == 0){return ariel::Fraction(0, 1);}
    return ariel::Fraction( (this->numerator / gcd) , (this->denominator / gcd) );
}

std::string ariel::Fraction::toString() const{
    return std::to_string(this->numerator) 
        + "/" 
        + std::to_string(this->denominator);
}

ariel::Fraction ariel::floatToFraction(float num){
    int signOfNum  = (num > 0) ? 1 : -1;
    num = std::abs(num);
    num *= 1000;
    return ariel::Fraction( (std::trunc(num) * signOfNum), 1000 ).reduceFraction();
}

std::pair<int, int> ariel::fixSign(int numerator, int denominator){
    int sign = (numerator < 0) ^ (denominator < 0) ? -1 : 1;
    numerator = std::abs(numerator);
    denominator = std::abs(denominator);
    return { (sign * numerator) , denominator};
}



//Ressources : 
//https://www.geeksforgeeks.org/reduce-the-fraction-to-its-lowest-form/
//https://www.geeksforgeeks.org/program-to-find-gcd-or-hcf-of-two-numbers/
//https://www.simplilearn.com/tutorials/cpp-tutorial/int-to-string-cpp
//https://www.geeksforgeeks.org/pair-in-cpp-stl/
//https://www.youtube.com/watch?v=2972LRdyquk&pp=ygUfPj4gb3BlcmF0b3Igb3ZlcmxvYWRpbmcgaW4gYysrIA%3D%3D
//https://www.geeksforgeeks.org/overloading-stream-insertion-operators-c/
//https://java2blog.com/check-if-input-is-integer-in-cpp/
//https://stackoverflow.com/questions/7959688/how-to-ignore-white-spaces-input-stream-in-operator-overload
