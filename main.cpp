#include <iostream>
#include <string>
#include "MyString.h"

void printMyString(const MyString &str) {
    for (int i = 0; i < str.size(); ++i) {
        std::cout << str.at(i);
    }
    std::cout << std::endl;
}

int main() {


    MyString myStr1("bread_");
    MyString myStr2("butter");

    std::cout << "append:" << std::endl;
    myStr1.append(myStr2);
    printMyString(myStr1);
    std::cout << std::endl;

    std::cout << "insert:" << std::endl;
    myStr1.insert(0, myStr2);
    printMyString(myStr1);
    std::cout << std::endl;

    std::cout << "clear:" << std::endl;
    myStr1.clear();
    printMyString(myStr1);
    std::cout << std::endl;

    std::cout << "isEmpty:" << std::endl;
    std::cout << myStr1.isEmpty() << std::endl;
    std::cout << std::endl;

    std::cout << "operator=:" << std::endl;
    myStr1 = myStr2;
    printMyString(myStr1);
    std::cout << std::endl;

    std::cout << "erase:" << std::endl;
    myStr1.erase(2, 20);
    printMyString(myStr1);
    std::cout << std::endl;

    std::cout << "size:" << std::endl;
    std::cout << myStr1.size() << std::endl;
    std::cout << std::endl;

    std::cout << "operator+:" << std::endl;
    myStr1 = myStr1 + myStr2;
    printMyString(myStr1);
    std::cout << std::endl;

    std::cout << "find:" << std::endl;
    std::cout << myStr1.find(myStr2) << std::endl;
    std::cout << std::endl;

    std::cout << "compare:" << std::endl;
    std::cout << myStr1.compare(myStr2) << std::endl;
    std::cout << std::endl;

    return 0;
}
