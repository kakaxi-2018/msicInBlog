#ifndef __MYSTRING_H__
#define __MYSTRING_H__

#include <iostream>

class MyString
{
    friend std::ostream &operator<<(std::ostream &co, const MyString &another);
    friend std::istream &operator>>(std::istream &ci, MyString &another);
public: 
    MyString(const char *str = nullptr);
    ~MyString();
    MyString(const MyString & another);
    MyString & operator=(const MyString & another);
    MyString operator+(const MyString & another);
    MyString & operator+=(const MyString & another);
    bool operator>(const MyString & another);
    bool operator<(const MyString & another);
    bool operator==(const MyString & another);
    char & at(int n);
    char & operator[](int n);
    char * c_str();
private:
    char * m_str;
};

#endif