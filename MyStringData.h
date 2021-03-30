//
// Created by Bogdan on 16/03/2021.
//

#ifndef MYSTRING_MYSTRINGDATA_H
#define MYSTRING_MYSTRINGDATA_H

#include <iostream>

class MyStringData
{
private:
    struct LongStr
    {
        char* data;
        size_t size;
    };

    const static unsigned char _maxShortSize = sizeof(LongStr) - sizeof(unsigned char);
    struct ShortStr
    {
        char data[_maxShortSize];
        unsigned char size;
    };

    union unionData
    {
        LongStr l;
        ShortStr s;
    };

    enum class stringType {
        shortString,
        longString
    };

    stringType _stringType;
    unionData _udata;
public:
    MyStringData();
    //~MyStringData();
    MyStringData(const char* craw, size_t n);
    void update(const char* craw, size_t n);
    void clear();
    void unhook();
    unsigned char getSize() const;

    const char *getCString() const;

    const char &operator[] (size_t idx) const;
    char &operator[] (size_t idx);
};


#endif //MYSTRING_MYSTRINGDATA_H
