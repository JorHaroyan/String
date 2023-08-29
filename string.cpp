#include "string.h"

#include <iostream>
#include <cstring>
#include <utility>

String::String() 
    : m_str { nullptr }, m_size { 0 }
{}

String::String(const char* other) {
    int all_size = strlen(other) + 1;
    m_str = new char[all_size];
    for (int i = 0; i < all_size; ++i) {
        m_str[i] = other[i];
    }
    m_size = all_size;
}

String::String(String& other) {    
    m_size = other.m_size;
    m_str = new char[m_size];
    for (int i = 0; i < m_size; ++i) {
        m_str[i] = other.m_str[i];
    }
}

String::String(String&& other) {
    m_size = other.m_size;
    m_str = other.m_str;
    other.m_str = nullptr;
    std::cout << "move ctor" << std::endl;
}

String& String::operator=(const String& other) {
    if (*this == other) {
        return *this;
    }
    if (other.m_size != m_size) {
        delete[] m_str;
        m_str = new char[other.m_size];
        m_size = other.m_size;
    }
    for (int i = 0; i < m_size; ++i) {
        m_str[i] = other.m_str[i];
    }
    return *this;
}


bool String::operator==(const String& other) {
    if (m_size != other.m_size) {
        return false;
    }
    for (int i = 0; i < m_size; ++i) {
        if (other.m_str[i] != m_str[i]) {
            return false;
        }
    }
    return true;
}

String String::operator+(String& other) {
    int size1 = strlen(m_str);
    int size2 = strlen(other.m_str);
    int size3 = size1 + size2 + 1;
    char* newStr = new char[size3];
    
    for (int i = 0; i < size1; ++i) {
        newStr[i] = m_str[i];
    }
    int j = 0;
    for (int i = size1; i < size3; ++i) {
        newStr[i] = other.m_str[j++];
    }

    String sum(newStr);
    return sum;
    
}


void String::PrintString() {
    for (int i = 0; m_str[i] != '\0'; ++i) {
        std::cout << m_str[i];
    }
    std::cout << std::endl;
}


String::~String() {
    delete[] m_str;
}
















































































