#include<iostream>
#include<stdlib.h>  //atoi头文件
#include<sstream>
#include<string>

using namespace std;

//采用标准库函数atoi（接收一个C风格的字符串）
int StrToInt1(const string &s)
{
    int a = atoi(s.c_str());
    return a;
}

//利用sstream头文件中定义的字符串流对象来实现转换
int StrToInt2(string &s)
{
    istringstream is(s);    //构造输入字符串流
    int a;
    is >> a;
    return a;
}

/*
//利用标准库函数to_string实现,编译器问题可能不可用
string IntToStr1(int &i)
{
    string s = std::to_string(i);
}
*/

//利用字符串流对象实现
string IntToStr2(int &i)
{
    ostringstream os;   //构造一个输出字符串流
    os << i;    //向流中写入
    return os.str();    //str函数获取流内容
}

int main()
{
    string s = "123";
    cout << StrToInt1(s) + 5 << endl;
    cout << StrToInt2(s) + 5 << endl;

    int j = 12345;
    //cout << IntToStr1(j) + "haha" << endl;
    cout << IntToStr2(j) + "haha" << endl;

    return 0;
}
