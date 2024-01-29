#include <iostream>
#include "string.h"
using namespace std;

int main(){
    // testing constructors and c_str()
    
    // test default constructor
    String defaultString;
    cout << "Default constructor: " << defaultString.c_str() << endl;
    cout << "Default constructor length = " << defaultString.length() << " and capacity = " << defaultString.capacity() << endl;

    // test copy constructor
    String copyString(defaultString);
    cout << "Copy constructor: " << copyString.c_str() << endl;

    // test constructor from a c-string
    char cString[] = "Hello, World!";
    String cStringObject(cString);
    cout << "Constructor from c-string: " << cStringObject.c_str() << endl;

    // test max_size()
    cout << "Test max_size(): " << endl;
    cout << defaultString.max_size() << endl;
    cout << copyString.max_size() << endl;
    cout << cStringObject.max_size() << endl;

    // test capacity()
    cout << "Test capacity(): " << endl;
    cout << defaultString.capacity() << endl;
    cout << copyString.capacity() << endl;
    cout << cStringObject.capacity() << endl;

    // test length() and size()
    cout << "Test size(), length(): " << endl;
    cout << defaultString.size() << ", " << defaultString.length() << endl;
    cout << copyString.size() << ", " << copyString.length() << endl;
    cout << cStringObject.size() << ", " << cStringObject.length() << endl;

    // test empty()
    cout << "Test empty(): " << endl;
    cout << "Default is empty: " << (defaultString.empty() ? "true" : "false") << endl;
    cout << "Copy is empty: " << (copyString.empty() ? "true" : "false") << endl;
    cout << "From c-string is empty: " << (cStringObject.empty() ? "true" : "false") << endl;
    // test the copy constructor and empty() with a copy from a different String object 
    String copyString2(cStringObject);
    cout << "Copy constructor test 2: " << copyString2.c_str() << endl;
    cout << "Copy2 is empty: " << (copyString2.empty() ? "true" : "false") << endl;

    // test clear()
    cout << "Test clear(): " << endl;
    cout << "Original String: " << copyString2.size() << " bytes - \"" << copyString2.c_str() << "\"" << endl;
    copyString2.clear();
    cout << "Cleared String: " << copyString2.size() << " bytes - \"" << copyString2.c_str() << "\"" << endl;

    // test resize(size_t, char)
    cout << "Test resize(): " << endl;
    cout << "Original String: " << cStringObject.size() << " bytes - Capacity: " << cStringObject.capacity() << " bytes - \"" << cStringObject.c_str() << "\"" << endl;
    // make it smaller
    cStringObject.resize(5);
    cout << "Resized String (smaller): " << cStringObject.size() << " bytes - Capacity: " << cStringObject.capacity() << " bytes - \"" << cStringObject.c_str() << "\"" << endl;
    // make it bigger
    cStringObject.resize(20, 'X');
    cout << "Resized String (larger): " << cStringObject.size() << " bytes - Capacity: " << cStringObject.capacity() << " bytes - \"" << cStringObject.c_str() << "\"" << endl;

    // test reserve(size_t)
    cout << "Test reserve(): " << endl;
    cout << "Original String: " << cStringObject.size() << " bytes - Capacity: " << cStringObject.capacity() << " bytes - \"" << cStringObject.c_str() << "\"" << endl;
    cStringObject.reserve(30);
    cout << "After Reserve (bigger): " << cStringObject.length() << " bytes - Capacity: " << cStringObject.capacity() << " bytes - " << cStringObject.c_str() << endl;
    cStringObject.reserve(10);
    cout << "After Reserve (smaller): " << cStringObject.size() << " bytes - Capacity: " << cStringObject.capacity() << " bytes - \"" << cStringObject.c_str() << "\"" << endl;
    cStringObject.reserve(4);
    cout << "After Reserve (even smaller): " << cStringObject.size() << " bytes - Capacity: " << cStringObject.capacity() << " bytes - \"" << cStringObject.c_str() << "\"" << endl;
    
    // test the operator= functions
    cout << endl;
    // test operator= (const String& str)
    cout << "Original String: " << copyString.size() << " bytes - Capacity: " << copyString.capacity() << " bytes - \"" << copyString.c_str() << "\"" << endl;
    copyString = cStringObject;
    cout << "After Assignment: " << copyString.size() << " bytes - Capacity: " << copyString.capacity() << " bytes - \"" << copyString.c_str() << "\"" << endl;
    // test operator= (char c)
    cout << "Original String: " << cStringObject.size() << " bytes - Capacity: " << cStringObject.capacity() << " bytes - \"" << cStringObject.c_str() << "\"" << endl;
    cStringObject = 'X';
    cout << "After Assignment: " << cStringObject.size() << " bytes - Capacity: " << cStringObject.capacity() << " bytes - \"" << cStringObject.c_str() << "\"" << endl;
    // test operator= (const char* s)
    cout << "Original String: " << cStringObject.size() << " bytes - Capacity: " << cStringObject.capacity() << " bytes - \"" << cStringObject.c_str() << "\"" << endl;
    char s[] = "Bonjour!";
    cStringObject = s;
    cout << "After Assignment: " << cStringObject.size() << " bytes - Capacity: " << cStringObject.capacity() << " bytes - \"" << cStringObject.c_str() << "\"" << endl;

    // test the operator+ functions
    cout << endl;
    // test operator+ (const String& rhs)
    char initialStr1[] = "Hello, ";
    char initialStr2[] = "World!";
    String string1(initialStr1);
    String string2(initialStr2);

    cout << "String 1: " << string1.size() << " bytes - Capacity: " << string1.capacity() << " bytes - \"" << string1.c_str() << "\"" << endl;
    cout << "String 2: " << string2.size() << " bytes - Capacity: " << string2.capacity() << " bytes - \"" << string2.c_str() << "\"" << endl;
    String result1 = string1 + string2;
    cout << "Concatenated String: " << result1.size() << " bytes - Capacity: " << result1.capacity() << " bytes - \"" << result1.c_str() << "\"" << endl;

    // test operator+ (char c)
    cout << "String 1: " << string1.size() << " bytes - Capacity: " << string1.capacity() << " bytes - \"" << string1.c_str() << "\"" << endl;
    String result2 = string1 + 'W';
    cout << "Concatenated String: " << result2.size() << " bytes - Capacity: " << result2.capacity() << " bytes - \"" << result2.c_str() << "\"" << endl;

    // test operator+ (const char* rhs)
    cout << "String 1: " << string1.size() << " bytes - Capacity: " << string1.capacity() << " bytes - \"" << string1.c_str() << "\"" << endl;
    String result3 = string1 + initialStr2;
    cout << "Concatenated String: " << result3.size() << " bytes - Capacity: " << result3.capacity() << " bytes - \"" << result3.c_str() << "\"" << endl;

    return 0;

}