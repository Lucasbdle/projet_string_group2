#ifndef STRING_H_
#define STRING_H_
#define MAX_LENGTH  100

#include <iostream>

class String{
    public:
        // default constructor
        String();
        // copy constructor
        String(const String& other);
        // constructor from a c-string
        String(char* strcopy);
        // destructor
        ~String();

        // Student A
        const char* c_str() const;
        size_t size() const;
        void clear();
        String& operator= (char c);
        String operator+ (const char* rhs);

        // Student B
        size_t length() const;
        size_t max_size() const;
        void resize (size_t n, char c = '\0');
        String& operator= (const String& str);
        String operator+ (char c);

        // Student C
        size_t capacity() const;
        bool empty() const;
        void reserve (size_t n = 0);
        String& operator= (const char* s);
        String operator+ (const String& rhs);

    private:
        char* c_str_ = nullptr;
        size_t capacity_ = 0;

};
#endif  //STRING_H_