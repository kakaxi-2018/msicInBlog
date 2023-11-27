#include <iostream>
#include <string>
#include "MyString.h"

using std::cout;
using std::endl;
using std::cin;

void testBase()
{
    MyString ms;
    MyString ms2("hello, world!");
    MyString ms3("Gread Wall");
    //ms3 = ms2;
    MyString ms4;
    ms4 = ms3 = ms2;

    cout << "ms : " << ms << endl;
    cout << "ms2: " << ms2 << endl;
    cout << "ms3: " << ms3 << endl;
    cout << "ms4: " << ms4 << endl;
}

void testAssignment()
{
    MyString ms("apple");
    MyString ms2("banana");
    MyString ms3("orgince");
    ms3 = ms = ms2;
    cout << "ms: " << ms <<endl;
    cout << "ms2: " << ms2 <<endl;
    cout << "ms3: " << ms3 <<endl;
}

void testIO()
{
    // 单个输入
    MyString ms;
    cin >> ms;
    cout << ms << endl;

    cout << "==========" << endl;
    // 连续输入
    MyString ms2;
    MyString ms3;
    cin >> ms2 >> ms3;
    cout << "ms2: " << ms2 << endl;
    cout << "ms3: " << ms3 << endl;

    cout << "==========" << endl;
    // 连续输出 
    cout << ms2 << ' ' << ms3 << endl;
}

void testPlus()
{
    MyString ms("hello");
    MyString ms2(" world");

    cout << ms + ms2 << endl;
    cout << "ms : "<< ms << endl;
    cout << "ms2: " << ms2 << endl;
}

void testPlusAssign()
{
    MyString ms("hello");
    MyString ms2(" world!");
    MyString ms3(" I love C++");
    ms+=ms2+=ms3;
    cout << ms << endl;

    cout << "==========" << endl;
    cout << "ms : " << ms << endl;
    cout << "ms2: " << ms2 << endl;
    cout << "ms3: " << ms3 << endl;
}

void testCompare()
{
    MyString ms("helloc");
    MyString ms2("helloc");

    if (ms == ms2)
    {
        cout << "ms == ms2" << endl;
    }
    else if (ms > ms2)
    {
        cout << "ms > ms2" << endl;
    }
    else
    {
        cout << "ms < ms2" << endl;
    }
}

void testIndex()
{
    MyString ms("hello");
    cout << ms[3] << endl;

    ms[3] = 'z';
    cout << ms[3] << endl;
    cout << ms << endl;

    cout << "==========" << endl;
    cout << ms.at(3) << endl;
    ms.at(3) = 'l';
    cout << ms << endl;
}

void testC_str()
{
    MyString ms;
    cout << ms.c_str() << endl;
    MyString ms2("hello");
    cout << ms2.c_str() << endl;
}

int main()
{
    //testBase();
    //testAssignment();
    //testIO();
    //testPlus();
    //testPlusAssign();
    //testCompare();
    //testIndex();
    testC_str();

    return 0;
}