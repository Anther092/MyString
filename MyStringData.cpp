//
// Created by Bogdan on 16/03/2021.
//

#include "MyStringData.h"
#include <cstring>

void MyStringData::update(const char* craw, size_t n) {
    if (_udata.l.data)
        clear();

    if (n <= _maxShortSize) {
        _stringType = stringType::shortString;

        _udata.s.size = n;
        for (int i = 0; i < n; ++i) {
            _udata.s.data[i] = craw[i];
        }
    }
    else if (n > _maxShortSize) {
        _stringType = stringType::longString;

        _udata.l.size = n;
        _udata.l.data = new char[n];
        for (int i = 0; i < n; ++i) {
            _udata.l.data[i] = craw[i];
        }
    }
}

MyStringData::MyStringData() {
    _stringType = stringType::shortString;
    this->clear();
}

MyStringData::MyStringData(const char *craw, size_t n) {
    update(craw, n);
}

void MyStringData::clear() {
    if (_stringType == stringType::longString) {
        _udata.l.size = 0;
        delete[] _udata.l.data;
        _udata.l.data = nullptr;
        _stringType = stringType::shortString;
    }
    else if (_stringType == stringType::shortString) {
        _udata.s.size = 0;
        memset(_udata.s.data, '\0', _maxShortSize);
    }
}

unsigned char MyStringData::getSize() const {
    return (_stringType == stringType::longString) ? _udata.l.size : _udata.s.size;
}

const char& MyStringData::operator[](size_t idx) const {
    assert(idx < getSize());
    return (_stringType == stringType::longString) ? _udata.l.data[idx] : _udata.s.data[idx];
}

char& MyStringData::operator[](size_t idx) {
    assert(idx < getSize());
    return (_stringType == stringType::longString) ? _udata.l.data[idx] : _udata.s.data[idx];
}

const char *MyStringData::getCString() const {
    //add null terminant
    return (_stringType == stringType::longString) ? _udata.l.data : _udata.s.data;
}

void MyStringData::unhook() {
    _udata.l.data = nullptr;
}









