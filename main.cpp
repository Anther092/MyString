#include <iostream>
#include "MyString.h"

void printMyString(const MyString &str) {
    for (int i = 0; i < str.size(); ++i) {
        std::cout << str.at(i);
    }
    std::cout << std::endl;
}

int main() {


    MyString str1("afor store apple");
    MyString str2("apple");


//    std::cout << "append:" << std::endl;
//    str1.append(str2);
//    printMyString(str1);
//    std::cout << std::endl;
//
//    std::cout << "insert:" << std::endl;
//    str1.insert(0, str2);
//    printMyString(str1);
//    std::cout << std::endl;
//
//    std::cout << "clear:" << std::endl;
//    str1.clear();
//    printMyString(str1);
//    std::cout << std::endl;
//
//    std::cout << "isEmpty:" << std::endl;
//    std::cout << str1.isEmpty() << std::endl;
//    std::cout << std::endl;
//
//    std::cout << "operator=:" << std::endl;
//    str1 = str2;
//    printMyString(str1);
//    std::cout << std::endl;
//
//    std::cout << "erase:" << std::endl;
//    str1.erase(2, 20);
//    printMyString(str1);
//    std::cout << std::endl;
//
//    std::cout << "size:" << std::endl;
//    std::cout << str1.size() << std::endl;
//    std::cout << std::endl;
//
//    std::cout << "operator+:" << std::endl;
//    str1 = str1 + str2;
//    printMyString(str1);
//    std::cout << std::endl;

    std::cout << "find:" << std::endl;
    std::cout << str1.find(str2) << std::endl;
    std::cout << std::endl;


    return 0;
}
