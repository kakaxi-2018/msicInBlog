#include "MyString.h"
#include <iostream>
#include <cstring>
#include <stdlib.h>

MyString::MyString(const char *str)
{
    if (nullptr == str)
    {
        m_str = new char[1];
        *m_str = '\0';
    }
    else
    {
        m_str = new char[strlen(str)+1];
        strcpy(m_str, str);
    }
}

MyString::~MyString()
{
    delete []m_str;
}

MyString::MyString(const MyString &another)
{
    int len = strlen(another.m_str);
    m_str = new char[len+1];
    strcpy(m_str, another.m_str);
}

// version1
MyString & MyString::operator=(const MyString &another)
{
    if (this == &another)
    {
        return *this;
    }

    delete []m_str;
    int len = strlen(another.m_str);
    m_str = new char[len+1];
    strcpy(m_str, another.m_str);

    return *this;
}

// version2，采用 copy and swap 技术
/*
MyString & MyString::operator=(const MyString &another)
{
    if (this == &another)
    {
        return *this;
    }

    MyString ms(another);
    std::swap(this->m_str, ms.m_str);

    return *this;
}
*/

MyString MyString::operator+(const MyString &another)
{
    MyString ms;

    int len = strlen(this->m_str) + strlen(another.m_str);
    delete []ms.m_str;
    ms.m_str = new char[len +1]{0};  // 注意初始化
    strcat(strcat(ms.m_str, this->m_str), another.m_str);

    return ms;
}

MyString & MyString::operator+=(const MyString &another)
{
    int lenOfSource = strlen(this->m_str);
    int lenOfAnother = strlen(another.m_str);
    this->m_str = (char *)realloc(this->m_str, lenOfSource+lenOfAnother+1);
    memset(this->m_str+lenOfSource, 0, lenOfAnother+1);
    strcat(this->m_str, another.m_str);

    return *this;
}

/*
MyString & MyString::operator+=(const MyString &another)
{
    *this = *this + another;
    return *this;
}
*/

bool MyString::operator>(const MyString &another)
{
    return strcmp(this->m_str, another.m_str) > 0;
}

bool MyString::operator<(const MyString &another)
{
    return strcmp(this->m_str, another.m_str) < 0;
}

bool MyString::operator==(const MyString &another)
{
    return strcmp(this->m_str, another.m_str) == 0;
}

char & MyString::at(int n)
{
    return m_str[n];
}

char & MyString::operator[](int n)
{
    return m_str[n];
}

char * MyString::c_str()
{
    return m_str;
}

//========== 
// 全局函数重载
std::ostream &operator<<(std::ostream &co, const MyString &another)
{
    co << another.m_str;
    return co;
}

std::istream &operator>>(std::istream &ci, MyString &another)
{
    char ch[1024];
    ci >> ch;

    delete []another.m_str;
    another.m_str = new char[strlen(ch)+1];
    strcpy(another.m_str, ch);
    return ci;
}