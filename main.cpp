#include "string.h"

#include <iostream>
#include <utility>

int main() {
    String s1 = "Hello";
    String s2 = "Helo";
    s1 = s2;
    s1.PrintString();
    std::cout << (s1 == s2) << std::endl;
    String str = "Hello";  
    str.PrintString();  

    String str2 = " World!";
    String str3 = (str + str2);
    str3.PrintString();

    String str4 = "Hi";
    String str5 = std::move(str4);
    str5.PrintString();

    return 0;
}
