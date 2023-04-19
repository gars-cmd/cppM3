#include "Fraction.hpp"
#include <iostream>
#include <iterator>
#include <ostream>
#include <stdexcept>

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
    return  ariel::Fraction();
}

ariel::Fraction ariel::operator+(float number, const ariel::Fraction& other){
    return  ariel::Fraction();
}

ariel::Fraction ariel::Fraction::operator-(const Fraction &other) const{
    int numerator = (this->numerator * other.denominator)
                  - (this->denominator * other.numerator);
    int denominator = this->denominator * other.denominator;
    return ariel::Fraction(numerator, denominator).reduceFraction();
}

ariel::Fraction ariel::operator-(const ariel::Fraction& other, float number){
    return  ariel::Fraction();
}

ariel::Fraction ariel::operator-(float number, const ariel::Fraction& other){
    return  ariel::Fraction();
}

ariel::Fraction ariel::Fraction::operator*(const Fraction &other) const{
    int new_numerator = this->numerator * other.numerator;
    int new_denominator = this->denominator * other.denominator;
    return  ariel::Fraction(new_numerator, new_denominator).reduceFraction();
}


ariel::Fraction ariel::operator*(const ariel::Fraction& other, float number){
    return  ariel::Fraction();
}

ariel::Fraction ariel::operator*(float number, const ariel::Fraction& other){
    return  ariel::Fraction();
}

ariel::Fraction ariel::Fraction::operator/(const ariel::Fraction &other) const{
    return ariel::Fraction();
}


ariel::Fraction ariel::operator/(const ariel::Fraction& other, float number){
    return  ariel::Fraction();
}

ariel::Fraction ariel::operator/(float number, const ariel::Fraction& other){
    return  ariel::Fraction();
}

bool ariel::Fraction::operator==(const ariel::Fraction &other) const{
    return false;
}

bool ariel::operator==(const ariel::Fraction &other, float number) {
    return false;
}

bool ariel::operator==(float number, const ariel::Fraction &other) {
    return false;
}

bool ariel::Fraction::operator!=(const ariel::Fraction &other) const{
    return false;
}

bool ariel::operator!=(const ariel::Fraction &other, float number) {
    return false;
}

bool ariel::operator!=(float number, const ariel::Fraction &other) {
    return false;
}

bool ariel::Fraction::operator>(const ariel::Fraction &other) const{
    return false;
}

bool ariel::operator>(const ariel::Fraction &other, float number) {
    return false;
}

bool ariel::operator>(float number, const ariel::Fraction &other) {
    return false;
}


bool ariel::Fraction::operator<(const ariel::Fraction &other) const{
    return false;
}

bool ariel::operator<(const ariel::Fraction &other, float number) {
    return false;
}

bool ariel::operator<(float number, const ariel::Fraction &other) {
    return false;
}

bool ariel::Fraction::operator>=(const ariel::Fraction &other) const{
    return false;
}

bool ariel::operator>=(const ariel::Fraction &other, float number) {
    return false;
}

bool ariel::operator>=(float number, const ariel::Fraction &other) {
    return false;
}



bool ariel::Fraction::operator<=(const ariel::Fraction &other) const{
    return false;
}

bool ariel::operator<=(const ariel::Fraction &other, float number) {
    return false;
}

bool ariel::operator<=(float number, const ariel::Fraction &other) {
    return false;
}

ariel::Fraction ariel::Fraction::operator++(){
    this->numerator += this->denominator;
    return *this;
}

ariel::Fraction ariel::Fraction::operator++(int){
    ariel::Fraction tmp = *this;
    this->numerator += denominator;
    return tmp;
}

ariel::Fraction ariel::Fraction::operator--(){
    this->numerator -= this->denominator;
    return *this;
}

ariel::Fraction ariel::Fraction::operator--(int){
    ariel::Fraction tmp = *this;
    this->numerator -= denominator;
    return tmp;
}

std::ostream& ariel::operator<<(std::ostream& stream, const ariel::Fraction& other){
    stream << other.numerator << '/' << other.denominator ;
    return stream;
}


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
    return ariel::Fraction( (this->numerator / gcd) , (this->denominator / gcd) );
}



//Ressources : 
//https://www.geeksforgeeks.org/reduce-the-fraction-to-its-lowest-form/
//https://www.geeksforgeeks.org/program-to-find-gcd-or-hcf-of-two-numbers/
