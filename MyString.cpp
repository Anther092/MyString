//
// Created by Bogdan on 16/03/2021.
//

#include "MyString.h"
#include "MyStringData.h"
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

    MyStringData buf(_data.getCString(), size() + insertedString.size());

    if (size() == 0) {
        _data = insertedString._data;
        return;
    }

    memcpy(&buf[0] + pos, &insertedString._data[0], insertedString.size());
    memcpy( &buf[0] + pos + insertedString.size(), &_data[0], buf.getSize() - (pos + insertedString.size()));

    _data = buf;
}

unsigned int MyString::size() const {
    return _data.getSize();
}

const char& MyString::at(unsigned int idx) const {
     return _data[idx];
}

char &MyString::at(unsigned int idx) {
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

    if (count > size() - pos)
        count = size() - pos;

    MyStringData buf(_data.getCString(), size() - count);
    memcpy(&buf[0] + pos, &buf[0] + pos + count, size() - (count + pos));
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

    for (int i = pos; i <= (int)size() - (int)substring.size(); ++i) {
        for (int j = 0; j < substring.size(); ++j) {
            if (_data[i + j] != substring._data[j]) {
                break;
            }

            if (j == substring.size()-1) return i;
        }
    }

    return -1;
}

int MyString::compare(const MyString &comparableString) const {
    size_t n = size() < comparableString.size() ? size() : comparableString.size();

    for (int i = 0; i < n; ++i) {
        if (_data[i] != comparableString[i])
            return _data[i] - comparableString[i];
    }

    return size() > comparableString.size() ? 1 : -1;
}

bool MyString::operator==(const MyString& comparableString) const {
    return this->compare(comparableString) == 0;
}
bool MyString::operator!=(const MyString& comparableString) const {
    return !(*this == comparableString);
}
bool MyString::operator>(const MyString& comparableString) const {
    return this->compare(comparableString) > 0;
}
bool MyString::operator<(const MyString& comparableString) const {
    return this->compare(comparableString) < 0;
}
bool MyString::operator>=(const MyString& comparableString) const {
    return (*this == comparableString) || (*this > comparableString);
}
bool MyString::operator<=(const MyString& comparableString) const {
    return (*this == comparableString) || (*this < comparableString);
}






