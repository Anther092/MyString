//
// Created by Bogdan on 01/04/2021.
//

#include "ExceptionMyStringAt.h"


ExcepitonMyStringAt::ExcepitonMyStringAt(size_t size, int idx) {
    _size = size;
    _idx = idx;
}

const char *ExcepitonMyStringAt::what() const noexcept {
    char *s = new char[256];
    sprintf(s, "Called at('%d') on string of size '%zu'", _idx, _size);
    return s;
}
