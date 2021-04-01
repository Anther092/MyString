//
// Created by Bogdan on 16/03/2021.
//

#include "MyString.h"
#include "MyStringData.h"

#include <cassert>
#include <cstdlib>
#include <cstring>

MyString::MyString(const char* craw) {
    if (craw) {
        _data.update(craw, strlen(craw));
    }
}

MyString::MyString(const MyString &other) {
    if (other._data.getSize() > 0) {
        _data.update(other._data.getCString(), other._data.getSize());
    }
}

MyString::MyString(MyString &&other) noexcept {
    std::swap(_data, other._data);
    other._data.unhook();
}

MyString& MyString::operator=(const MyString& other) {

    if (this != &other) {
        _data.clear();
        _data.update(other._data.getCString(), other._data.getSize());
    }

    return *this;
}

MyString& MyString::operator=(MyString&& other) noexcept {

    if (this != &other) {
        _data.clear();
        std::swap(_data, other._data);
        other._data.unhook();
    }

    return *this;
}

void MyString::append(const MyString& appendedString) {
    insert(size(), appendedString);
}

void MyString::insert(unsigned int pos, const MyString& insertedString) {
    assert(pos <= size());

    MyStringData buf(_data.getCString(), size() + insertedString.size());

    memcpy((void *) (buf.getCString() + pos), insertedString._data.getCString(), insertedString.size());
    memcpy((void *) (buf.getCString() + pos + insertedString.size()), _data.getCString(), buf.getSize() - (pos + insertedString.size()));

    _data = buf;
}

unsigned int MyString::size() const {
    return _data.getSize();
}

const char& MyString::at(unsigned int idx) const {
     assert(idx < size());
     return _data[idx];
}

char &MyString::at(unsigned int idx) {
    assert(idx < size());
    return _data[idx];
}

const char& MyString::operator[](unsigned int idx) const {
    return at(idx);
}

char& MyString::operator[](unsigned int idx) {
    return at(idx);
}

const char* MyString::rawString() const {
    return _data.getCString();
}

MyString::~MyString() {
    _data.clear();
}

void MyString::clear() {
    _data.clear();
}

void MyString::erase(unsigned int pos, unsigned int count) {
    assert(pos >= 0);
    assert(pos < size());

    if (count > size() - pos)
        count = size() - pos;

    MyStringData buf(_data.getCString(), size() - count);
    memcpy((void *) (buf.getCString() + pos), buf.getCString() + pos + count, size() - (count + pos));
    _data = buf;
}

bool MyString::isEmpty() const {
    return _data.getSize() == 0;
}

MyString &MyString::operator+(const MyString &appendedString) {
    this->append(appendedString);
    return *this;
}

unsigned int MyString::find(const MyString &substring, unsigned int pos) {

    for (int i = 0; i <= size() - substring.size(); ++i) {
        for (int j = 0; j < substring.size(); ++j) {
            if (_data.getCString()[i + j] != substring._data.getCString()[j]) {
                break;
            }

            if (j == substring.size()-1) return i;
        }
    }

    return -1;
}

int MyString::compare(const MyString &comparableString) const {
    return 0;
}







