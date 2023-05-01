#include "Fraction.hpp"
#include <cctype>
#include <climits>
#include <cmath>
#include <cstddef>
#include <iostream>
#include <istream>
#include <iterator>
#include <ostream>
#include <stdexcept>
#include <string>
#include <utility>
#include <limits>

#define MAX_INT  std::numeric_limits<int>::max()
#define MIN_INT  std::numeric_limits<int>::min()


// ############### CONSTRUCTOR,GETTER,SETTER #############

ariel::Fraction::~Fraction(){

}

ariel::Fraction::Fraction(){
    this->numerator = 0;
    this->numerator = 1;
}

ariel::Fraction::Fraction(int numerator, int denominator){
   if (denominator == 0) {
        throw std::invalid_argument("from the constructor");
   }
    std::pair<int,int> fixedPair = fixSign(numerator, denominator);
    this->numerator = fixedPair.first;
    this->denominator = fixedPair.second;

    if (this->numerator == this->denominator) {
        this->numerator = 1;this->denominator = 1;}
}

ariel::Fraction::Fraction(double number){
    ariel::Fraction frac = doubleToFraction(number);
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
        throw std::runtime_error("from setDenominator");
    }
    std::pair<int,int> fixedPair = fixSign(this->numerator, denominator);
    this->numerator = fixedPair.first; this->denominator = fixedPair.second;
}

// ############### ADDITION #############

ariel::Fraction ariel::Fraction::operator+(const Fraction &other) const{
    int numerator = addCheckOverflow(
                        mulCheckOverflow(this->numerator,other.denominator),
                        mulCheckOverflow(this->denominator,other.numerator)
    );
    int denominator = mulCheckOverflow(this->denominator,other.denominator);
    return ariel::Fraction(numerator, denominator).reduceFraction();
}

ariel::Fraction ariel::operator+(const ariel::Fraction& other, const double number){
    ariel::Fraction fractioned = ariel::doubleToFraction(number);
    return other + fractioned;
}

ariel::Fraction ariel::operator+(const double number, const ariel::Fraction& other){
    return other + number;
}

// ############### SUBSTRACTION #############

ariel::Fraction ariel::Fraction::operator-(const Fraction &other) const{
    int numerator = subCheckOverflow(
                        mulCheckOverflow(this->numerator,other.denominator),
                        mulCheckOverflow(this->denominator,other.numerator)
    );
    int denominator = mulCheckOverflow(this->denominator,other.denominator);
    std::pair<int,int> fixedPair = fixSign(numerator, denominator);
    numerator = fixedPair.first; denominator = fixedPair.second;
    return ariel::Fraction(numerator, denominator).reduceFraction();
}

ariel::Fraction ariel::operator-(const ariel::Fraction& other, const double number){
    ariel::Fraction fractioned = ariel::doubleToFraction(number);
    return other - fractioned;
}

ariel::Fraction ariel::operator-(const double number, const ariel::Fraction& other){
    ariel::Fraction fractioned = ariel::doubleToFraction(number);
    return fractioned - other;
}

// ############### MULTIPLICATION #############

ariel::Fraction ariel::Fraction::operator*(const Fraction &other) const{
    int new_numerator = mulCheckOverflow(this->numerator,other.numerator);
    int new_denominator = mulCheckOverflow(this->denominator,other.denominator);
    return  ariel::Fraction(new_numerator, new_denominator).reduceFraction();
}

ariel::Fraction ariel::operator*(const ariel::Fraction& other, const double number){
    ariel::Fraction fractioned = ariel::doubleToFraction(number);
    return other * fractioned;
}

ariel::Fraction ariel::operator*(const double number, const ariel::Fraction& other){
    return other * number;
}

// ############### DIVISION #############

ariel::Fraction ariel::Fraction::operator/(const ariel::Fraction &other) const{
    if (other == Fraction(0,1)) { throw std::runtime_error("from operator /");}
    int new_numerator = mulCheckOverflow(this->numerator,other.denominator);
    int new_denominator = mulCheckOverflow(this->denominator,other.numerator);
    return ariel::Fraction(new_numerator, new_denominator).reduceFraction();
}

ariel::Fraction ariel::operator/(const ariel::Fraction& other, const double number){
    ariel::Fraction fractioned = ariel::doubleToFraction(number);
    return  other / fractioned;
}

ariel::Fraction ariel::operator/(const double number, const ariel::Fraction& other){
    ariel::Fraction fractioned = ariel::doubleToFraction(number);
    return  fractioned / other;
}

// ############### EQUALITY #############

bool ariel::Fraction::operator==(const ariel::Fraction &other) const{
    ariel::Fraction f1 = truncFraction(*this).reduceFraction();
    ariel::Fraction f2 = truncFraction(other).reduceFraction();

    return (f1.getNumerator() == f2.getNumerator()) 
        && (f1.getDenominator() == f2.getDenominator());
}

bool ariel::operator==(const ariel::Fraction &other, const double number) {
    ariel::Fraction frac = ariel::doubleToFraction(number);
    return other == frac;
}

bool ariel::operator==(const double number, const ariel::Fraction &other) {
    return other == number;
}

// ############### INEQUALITY #############

bool ariel::Fraction::operator!=(const ariel::Fraction &other) const{
    return !(*this == other);

}

bool ariel::operator!=(const ariel::Fraction &other, const double number) {
    return !(other == number);
}

bool ariel::operator!=(const double number, const ariel::Fraction &other) {
    return (other != number);
}


// ############### GREATER THAN #############

bool ariel::Fraction::operator>(const ariel::Fraction &other) const{
    int firstNumerator = mulCheckOverflow(this->numerator,other.denominator);
    int secondNumerator = mulCheckOverflow(other.numerator , this->denominator);
    return firstNumerator > secondNumerator;
}

bool ariel::operator>(const ariel::Fraction &other, const double number) {
    ariel::Fraction frac = ariel::doubleToFraction(number);
    return (other > frac);
}

bool ariel::operator>(const double number, const ariel::Fraction &other) {
    ariel::Fraction frac = ariel::doubleToFraction(number);
    return (frac > other);
}

// ############### LESS THAN #############

bool ariel::Fraction::operator<(const ariel::Fraction &other) const{
    int firstNumerator = mulCheckOverflow(this->numerator,other.denominator);
    int secondNumerator = mulCheckOverflow(other.numerator , this->denominator);
    return firstNumerator < secondNumerator;
}

bool ariel::operator<(const ariel::Fraction &other, const double number) {
    ariel::Fraction frac = ariel::doubleToFraction(number);
    return (other < frac);
}

bool ariel::operator<(const double number, const ariel::Fraction &other) {
    ariel::Fraction frac = ariel::doubleToFraction(number);
    return (frac < other);
}

// ############### GREATER THAN EQUAL #############

bool ariel::Fraction::operator>=(const ariel::Fraction &other) const{
    return ( (*this > other) || (*this == other) );
}

bool ariel::operator>=(const ariel::Fraction &other, const double number) {
    return ( (other > number) || (other == number) );
}

bool ariel::operator>=(const double number, const ariel::Fraction &other) {
    return  ( (number > other) || (number == other) );
}

// ############### LESS THAN EQUAL #############

bool ariel::Fraction::operator<=(const ariel::Fraction &other) const{
    return ( (*this < other) || (*this == other) );
}

bool ariel::operator<=(const ariel::Fraction &other, const double number) {
    return  ( (other < number) || (other == number) );
}

bool ariel::operator<=(const double number, const ariel::Fraction &other) {
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
        throw std::runtime_error("from >> operator");
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
    // if it's a negative number
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
    if (num1 == MIN_INT) { num1 = MAX_INT;
    }else if (num2 == MIN_INT) { num2 = MAX_INT; }
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

ariel::Fraction ariel::doubleToFraction(double num){
    int signOfNum  = (num > 0) ? 1 : -1;
    num = std::abs(num);
    if (num - (int)num == 0) {
        return ariel::Fraction((int)num, 1);
    }else {
        num *= 1000;
        return ariel::Fraction( (std::trunc(num) * signOfNum), 1000 ).reduceFraction();
    }
}

std::pair<int, int> ariel::fixSign(int numerator, int denominator){
    int sign = (numerator < 0) ^ (denominator < 0) ? -1 : 1;
    numerator = std::abs(numerator);
    denominator = std::abs(denominator);
    return { (sign * numerator) , denominator};
}

int ariel::addCheckOverflow(int a, int b){
    if ( (b > 0 && a > MAX_INT - b) 
    || (b < 0 && a < MIN_INT - b)){
        throw std::overflow_error("from addCheckOverflow");
    }
    else {
        return a+b;
    }
}

int ariel::subCheckOverflow(int a, int b){
    if ( (b < 0  && a > MAX_INT + b)
    ||  (b > 0 && a < MIN_INT + b) ){
        throw std::overflow_error("from subCheckOverflow");
    }
    else {
        return a-b;
    }
}

int ariel::mulCheckOverflow(int a, int b){
    long long tmp = static_cast<long long>(a) * b;
    if ( (tmp > MAX_INT) || (tmp < MIN_INT) ) {
        throw std::overflow_error("from mulCheckOverflow");
    }else {
        return a * b;
    }
}

ariel::Fraction ariel::truncFraction(ariel::Fraction frac){
    double fracTodouble = (frac.getNumerator() * 1.0) / (frac.getDenominator() * 1.0 );
    return doubleToFraction(fracTodouble);
}

// unsigned int ariel::absu(int value) {
//     return (value < 0) ? -((unsigned int)value) : (unsigned int) value;
// }



//Ressources : 
//https://www.geeksforgeeks.org/reduce-the-fraction-to-its-lowest-form/
//https://www.geeksforgeeks.org/program-to-find-gcd-or-hcf-of-two-numbers/
//https://www.simplilearn.com/tutorials/cpp-tutorial/int-to-string-cpp
//https://www.geeksforgeeks.org/pair-in-cpp-stl/
//https://www.youtube.com/watch?v=2972LRdyquk&pp=ygUfPj4gb3BlcmF0b3Igb3ZlcmxvYWRpbmcgaW4gYysrIA%3D%3D
//https://www.geeksforgeeks.org/overloading-stream-insertion-operators-c/
//https://java2blog.com/check-if-input-is-integer-in-cpp/
//https://stackoverflow.com/questions/7959688/how-to-ignore-white-spaces-input-stream-in-operator-overload
//https://wiki.sei.cmu.edu/confluence/display/c/INT32-C.+Ensure+that+operations+on+signed+integers+do+not+result+in+overflow
