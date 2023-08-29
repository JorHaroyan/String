#pragma once

#include <iostream>
#include <cstring>

class String 
{
public:
    String();
    ~String();
    String(const char*);
    String(String&);
    String(String&&);
    String operator+ (String&);
    String& operator=(const String&);
    String& operator=(String&&);
    bool operator==(const String&);
    void PrintString();

private:
    char* m_str;
    int m_size;
};
