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

//Student C (Martin) : 


// destructor
String::~String(){
    delete[] c_str_;
}

// size of allocated storage in bytes
size_t String::capacity() const{
    return capacity_;
}

// is the string empty?
bool String::empty() const {
    return this->length() == 0;
}

// request a change in capacity
void String::reserve(size_t n){
    if (n > capacity_) {
        // if n is greater than the current capacity, increase the capacity
        char* newStr = new char[n]; 
        // cout << "c_str_ = " << c_str_ << endl;
        // cout << "newStr = " << newStr << endl;
        // cout << "length = " << this->length() << endl;
  
        // copy into the new string
        for (size_t i = 0; i < this->length(); ++i) {
            //cout << "c_str_[" << i << "] = " << c_str_[i] << endl;
            newStr[i] = c_str_[i];
            // cout << "newStr[" << i << "] = " << newStr[i] << endl;
        }
        // cout << "newStr = " << newStr << endl;

        // string becomes new string
        newStr[this->length()] = '\0';
        delete[] c_str_;
        c_str_ = newStr;
        // cout << "c_str_: " << c_str_ << endl;
        capacity_ = n;
    } else if (n < capacity_){
        // if n is smaller than the current capacity, decrease the capacity
        char* newStr = new char[n]; 

        // copy into the new string
        for (size_t i = 0; i < n; ++i) {
            newStr[i] = c_str_[i];
        }

        // string becomes new string
        newStr[n-1] = '\0';
        delete[] c_str_;
        c_str_ = newStr;
        capacity_ = n;
    } else if (n > MAX_LENGTH){
        // if n is bigger than the authorized MAX_LENGTH print an error
        std::cout << "Resizing the string was not possible! n = " << n << " exceeds MAX_LENGTH = " << MAX_LENGTH << std::endl;
        return;
    }
}

// the string is set to a copy of c-string s
String& String::operator= (const char* s){

    size_t len = 0;

    // loop until the null terminator is encountered
    while (s[len] != '\0') {
        ++len;
    }

    if(len > MAX_LENGTH){
        // if the string is too long, print an error message and create an empty string
        std::cout << "Could not copy  " << s << ". " << std::endl;
        std::cout << "The length of the c-string is too long! len = " << len << " exceeds MAX_LENGTH = " << MAX_LENGTH << std::endl;
        std::cout << "An empty string was constructed instead" << std::endl; // this will be done in the clear() function
        clear();
        return *this;

    } else {
        delete[] c_str_; 
        //allocate memory
        c_str_ = new char[len + 1]; // +1 for null terminator
        // copy into the string
        for (size_t i = 0; i < len; ++i) {
            c_str_[i] = s[i];
        }
        c_str_[len] = '\0';
        capacity_ = len + 1;
    }

    return *this;
}


// concatenates the c-strings from objects lhs and rhs
String String::operator+ (const String& rhs){
    size_t lhsLen = this->length();
    size_t rhsLen = rhs.length();

    if(lhsLen + rhsLen > MAX_LENGTH){
         // if the constructed string object would be too long, print an error message and use default constructor
        std::cout << "Could not concatenate " << c_str_ << " and " << rhs.c_str() << std::endl;
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
        resultStr[lhsLen + i] = rhs.c_str()[i];
    }
    resultStr[lhsLen + rhsLen] = '\0';

    // define resultString
    String resultString(resultStr);
    // deallocate the memory used for resultStr
    delete[] resultStr;

    return resultString;
}

//Student B (thekla) : 

// constructor from a c-string
String::String(char* strcopy){
    size_t len = 0;

    // loop until the null terminator is encountered
    while (strcopy[len] != '\0') {
        ++len;
    }

    if(len > MAX_LENGTH){
        // if the string is too long, print an error message and create an empty string
        std::cout << "Could not copy  " << strcopy << ". " << std::endl;
        std::cout << "The length of the c-string is too long! len = " << len << " exceeds MAX_LENGTH = " << MAX_LENGTH << std::endl;
        
        c_str_ = new char[1];
        c_str_[0] = '\0';

        std::cout << "An empty string was constructed instead" << std::endl;

    } else {
        // allocate memory
         c_str_ = new char[len + 1];
        // copy into the string
        for (size_t i = 0; i < len; ++i) {
            c_str_[i] = strcopy[i];
        }
        c_str_[len] = '\0';
        capacity_ = len + 1;
    }

}

// length
size_t String::length() const{
    
    size_t length = 0;
    // loop until the null terminator is encountered
    while (c_str_[length] != '\0') {
        ++length;
    }
    return length;
}


// maximum length the string can reach.
size_t String::max_size() const{
    return MAX_LENGTH;
}

// resizes the string to a length of n characters
void String::resize(size_t n, char c) {

    if (n < this->length()) {
        // if n is smaller than the current size, make the string shorter
        c_str_[n] = '\0';
        capacity_ = n+1;
    } else if (n > this->length()) {
        // If n is greater than the current size, expand the string
        char* newStr = new char[n + 1];  // +1 for null terminator

        // copy into the new string
        for (size_t i = 0; i < this->length(); ++i) {
            newStr[i] = c_str_[i];
        }

        // fill the newly added space with the specified c or null character
        for (size_t i = this->length(); i < n; ++i) {
            newStr[i] = c;
        }

        // string becomes new string
        newStr[n] = '\0';
        delete[] c_str_;
        c_str_ = newStr;
        capacity_ = n + 1;
    } else if (n > MAX_LENGTH){
        // if n is bigger than the authorized MAX_LENGTH print an error
        std::cout << "Resizing the string was not possible! n = " << n << " exceeds MAX_LENGTH = " << MAX_LENGTH << std::endl;
    }
}


// the string is set to a copy of the c-string from String str
String& String::operator= (const String& str){
    if (this != &str) {  // check for self-assignment
        delete[] c_str_;

        size_t len = str.length();

        //allocate memory
        c_str_ = new char[len + 1]; // +1 for null terminator
        // copy into the string
        for (size_t i = 0; i < len; ++i) {
            c_str_[i] = str.c_str()[i];
        }
        c_str_[len] = '\0';
        capacity_ = len + 1;
    }

    return *this;
}


// concatenates a c-string from object str and a character c
String String::operator+ (char c){
    size_t len = this->length();

    if(len + 1 > MAX_LENGTH){
         // if the constructed string object would be too long, print an error message and use default constructor
        std::cout << "Could not concatenate " << c_str_ << " with " << c << std::endl;
        std::cout << "The length  is too long! Together they have length " << len + 1 << ". That exceeds MAX_LENGTH = " << MAX_LENGTH << std::endl;
        std::cout << "The default constructor was called instead!" << std::endl; // this was done in the clear() function
        return String();
    }

    char* resultStr = new char[len + 2];  // +1 for null terminator

    // copy characters from lhs
    for (size_t i = 0; i < len; ++i) {
        resultStr[i] = c_str_[i];
    }

    // add the character and the null terminator
    resultStr[len] = c;
    resultStr[len + 1] = '\0';

    // define resultString
    String resultString(resultStr);
    // deallocate the memory used for resultStr
    delete[] resultStr;

    return resultString;
}
