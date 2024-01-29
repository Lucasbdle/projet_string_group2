//Student A (Lucas): 

#include "string.h"
using namespace std;

//default constructor
String::String(){
    c_str_ = new char[1];
    c_str_[0] = '\0';
    capacity_ = 1;
}


// copy constructor
String::String(const String& other){
    if(other.c_str() == nullptr) {
        // if the string is a nullpointer, copy that
        c_str_ = nullptr;
        capacity_ = 0;
    } else {
        // else copy the string 
        size_t length = other.length();
        // allocate memory
        c_str_ = new char[length + 1];
        // copy into the string
        for (size_t i = 0; i < length; ++i) {
            c_str_[i] = other.c_str()[i];
        }
        c_str_[length] = '\0';
        capacity_ = length + 1;
    }    
}

// c-string 
const char* String::c_str() const{
    return c_str_;
}


// length of the string, in terms of bytes
size_t String::size() const{
    return this->length() * sizeof(char); // size of char is one byte (* 1)
}

// erases the contents of the string, which becomes an empty string 
void String::clear(){
    delete[] c_str_;
    c_str_ = new char[1];
    c_str_[0] = '\0';
    capacity_ = 1;
}


// the string is set to a single copy of character c
String& String::operator= (char c){
    delete[] c_str_;

    // allocate new storage for the character
    c_str_ = new char[2];
    c_str_[0] = c;
    c_str_[1] = '\0';
    capacity_ = 2;
    return *this;

}


// concatenates a c-string from object lhs and a c-string rhs
String String::operator+ (const char* rhs){
    size_t lhsLen = this->length();

    size_t rhsLen = 0;

    // loop until the null terminator is encountered
    while (rhs[rhsLen] != '\0') {
        ++rhsLen;
    }

    if(lhsLen + rhsLen > MAX_LENGTH){
         // if the constructed string object would be too long, print an error message and use default constructor
        std::cout << "Could not concatenate " << c_str_ << " and " << rhs << std::endl;
        std::cout << "The length  is too long! Together they have length " << lhsLen + rhsLen << ". That exceeds MAX_LENGTH = " << MAX_LENGTH << std::endl;
        std::cout << "The default constructor was called instead!" << std::endl; // this was done in the clear() function
        return String();
    }

    char* resultStr = new char[lhsLen + rhsLen + 1];  // +1 for null terminator

    // copy characters from lhs
    for (size_t i = 0; i < lhsLen; ++i) {
        resultStr[i] = c_str_[i];
    }

    // copy characters from rhs
    for (size_t i = 0; i < rhsLen; ++i) {
        resultStr[lhsLen + i] = rhs[i];
    }
    resultStr[lhsLen + rhsLen] = '\0';

    // define resultString
    String resultString(resultStr);
    // deallocate the memory used for resultStr
    delete[] resultStr;

    return resultString;
}

