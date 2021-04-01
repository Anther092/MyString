//
// Created by Bogdan on 01/04/2021.
//

#ifndef MYSTRING_EXCEPTIONMYSTRINGAT_H
#define MYSTRING_EXCEPTIONMYSTRINGAT_H

#include "MyString.h"
#include <exception>

class ExcepitonMyStringAt : public std::exception {
private:
    size_t _size;
    int _idx;
public:
    ExcepitonMyStringAt(size_t size, int idx);

    const char * what() const noexcept override;
};
#endif //MYSTRING_EXCEPTIONMYSTRINGAT_H
