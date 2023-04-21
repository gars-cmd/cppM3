#include "Fraction.hpp"
#include <cmath>
#include <iostream>
#include <iterator>
#include <ostream>
#include <stdexcept>
#include <string>

// ############### CONSTRUCTOR,GETTER,SETTER #############

ariel::Fraction::~Fraction(){

}

ariel::Fraction::Fraction(int numerator, int denominator){
   if (denominator == 0) {
        throw std::invalid_argument("0 cannot be denominator");
   }
    this->numerator = numerator;
    this->denominator = denominator;
}

int ariel::Fraction::getNumerator(){
    return  this->numerator;
}

int ariel::Fraction::getDenominator(){
    return  this->denominator;
}

void ariel::Fraction::setNumerator(int numerator){
    this->numerator = numerator;
}

void ariel::Fraction::setDenominator(int denominator){
    if (denominator == 0) {
        throw std::invalid_argument("cannot set denominator to 0");
    }
    this->denominator = denominator;
}

// ############### ADDITION #############

ariel::Fraction ariel::Fraction::operator+(const Fraction &other) const{
    int numerator = (this->numerator * other.denominator)
                  + (this->denominator * other.numerator);
    int denominator = this->denominator * other.denominator;
    return ariel::Fraction(numerator, denominator).reduceFraction();
}

ariel::Fraction ariel::operator+(const ariel::Fraction& other, float number){
    ariel::Fraction fractioned = ariel::floatToFraction(number);
    return other + fractioned;
}

ariel::Fraction ariel::operator+(float number, const ariel::Fraction& other){
    return other + number;
}

// ############### SOUSTRACTION #############

ariel::Fraction ariel::Fraction::operator-(const Fraction &other) const{
    int numerator = (this->numerator * other.denominator)
                  - (this->denominator * other.numerator);
    int denominator = this->denominator * other.denominator;
    return ariel::Fraction(numerator, denominator).reduceFraction();
}

ariel::Fraction ariel::operator-(const ariel::Fraction& other, float number){
    ariel::Fraction fractioned = ariel::floatToFraction(number);
    return other - fractioned;
}

ariel::Fraction ariel::operator-(float number, const ariel::Fraction& other){
    return other - number;
}

// ############### MULTIPLICATION #############

ariel::Fraction ariel::Fraction::operator*(const Fraction &other) const{
    int new_numerator = this->numerator * other.numerator;
    int new_denominator = this->denominator * other.denominator;
    return  ariel::Fraction(new_numerator, new_denominator).reduceFraction();
}

ariel::Fraction ariel::operator*(const ariel::Fraction& other, float number){
    ariel::Fraction fractioned = ariel::floatToFraction(number);
    return other * fractioned;
}

ariel::Fraction ariel::operator*(float number, const ariel::Fraction& other){
    ariel::Fraction fractioned = ariel::floatToFraction(number);
    return other * fractioned;
}

// ############### DIVISION #############

ariel::Fraction ariel::Fraction::operator/(const ariel::Fraction &other) const{
    return ariel::Fraction();
}

ariel::Fraction ariel::operator/(const ariel::Fraction& other, float number){
    return  ariel::Fraction();
}

ariel::Fraction ariel::operator/(float number, const ariel::Fraction& other){
    return  ariel::Fraction();
}

// ############### EQUALITY #############

bool ariel::Fraction::operator==(const ariel::Fraction &other) const{
    return this->numerator == other.numerator
        && this->denominator == other.denominator ;
}

bool ariel::operator==(const ariel::Fraction &other, float number) {
    ariel::Fraction frac = ariel::floatToFraction(number);
    return other == frac;
}

bool ariel::operator==(float number, const ariel::Fraction &other) {
    return other == number;
}

// ############### INEQUALITY #############

bool ariel::Fraction::operator!=(const ariel::Fraction &other) const{
    return false;
}

bool ariel::operator!=(const ariel::Fraction &other, float number) {
    return false;
}

bool ariel::operator!=(float number, const ariel::Fraction &other) {
    return false;
}


// ############### GREATER THAN #############

bool ariel::Fraction::operator>(const ariel::Fraction &other) const{
    return false;
}

bool ariel::operator>(const ariel::Fraction &other, float number) {
    return false;
}

bool ariel::operator>(float number, const ariel::Fraction &other) {
    return false;
}

// ############### LESS THAN #############

bool ariel::Fraction::operator<(const ariel::Fraction &other) const{
    return false;
}

bool ariel::operator<(const ariel::Fraction &other, float number) {
    return false;
}

bool ariel::operator<(float number, const ariel::Fraction &other) {
    return false;
}

// ############### GREATER THAN EQUAL #############

bool ariel::Fraction::operator>=(const ariel::Fraction &other) const{
    return false;
}

bool ariel::operator>=(const ariel::Fraction &other, float number) {
    return false;
}

bool ariel::operator>=(float number, const ariel::Fraction &other) {
    return false;
}


// ############### LESS THAN EQUAL #############

bool ariel::Fraction::operator<=(const ariel::Fraction &other) const{
    return false;
}

bool ariel::operator<=(const ariel::Fraction &other, float number) {
    return false;
}

bool ariel::operator<=(float number, const ariel::Fraction &other) {
    return false;
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
    stream << other.numerator << '/' << other.denominator ;
    return stream;
}

// ############### CIN ###############

std::istream& ariel::operator>>(std::istream& stream, ariel::Fraction& other){
    int numerator, denominator;
    stream >> numerator >> denominator;
    other = ariel::Fraction(numerator, denominator);
    return stream;
}

// return the gcd of two number
int ariel::Fraction::getGCD(int a, int b){
    int result = std::min(a, b);
    while (result > 0) {
        if (a % result == 0 & b % result == 0) {
            break;
        }
    result--;
    }
    return result;
}

// reduce the fraction to is lowest form (with help of gcd)
ariel::Fraction ariel::Fraction::reduceFraction(){
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


//Ressources : 
//https://www.geeksforgeeks.org/reduce-the-fraction-to-its-lowest-form/
//https://www.geeksforgeeks.org/program-to-find-gcd-or-hcf-of-two-numbers/
//https://www.simplilearn.com/tutorials/cpp-tutorial/int-to-string-cpp
