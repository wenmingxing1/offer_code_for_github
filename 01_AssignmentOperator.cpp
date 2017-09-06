#include<iostream>
#include<string>
#include<cstring>
//#include<>

using namespace std;

//No.1_赋值运算符函数
//如下为类型CMySting的声明，请为该类型添加赋值运算符函数。
class CMyString
{
public:
    CMyString(char* pData = NULL);  //构造函数
    CMyString(const CMyString& str);    //构造函数
    ~CMyString(void);   //析构函数

    CMyString& operator=(const CMyString& str);

    void Print();   //为测试代码准备

private:
    char* m_pData;
};

//=================================================

//构造函数
CMyString::CMyString(char *pData)
{
    if (pData == NULL)
    {
        m_pData = new char[1];
        m_pData[0] = '\0';
    }
    else
    {
        int length = strlen(pData);
        m_pData = new char[length + 1];
        strcpy(m_pData, pData);
    }
}

//构造函数2
CMyString::CMyString(const CMyString &str)
{
    int length = strlen(str.m_pData);
    m_pData = new char[length + 1];
    strcpy(m_pData, str.m_pData);
}

//析构函数
CMyString::~CMyString()
{
    delete []m_pData;
}

//==========================题目答案============================

/*
//初级程序员
//判断自赋值-->如果不是自赋值则释放*this的内存-->开辟空间进行赋值-->返回*this
CMyString& CMyString::operator=(const CMyString &str)   //赋值运算符应具有构造函数和析构函数两种功能
{
    if (this == &str)   //自赋值
        return *this;
    //先用delete释放内存，然后再用new为新的数据开辟空间，若new char内存不足，则无法正常开辟空间
    //这时，原始的m_pData没有了，也无法更新新的数据，发生异常的情况下CMyString无法保持有效状态，违背了异常安全性原则
    delete []m_pData;
    m_pData = NULL;
    m_pData = new char[strlen(str.m_pData) + 1];
    strcpy(m_pData, str.m_pData);

    return *this;
}
*/

//高级程序员
//先创建一个临时实参，再交换临时实参和原来的实参
CMyString& CMyString::operator=(const CMyString &str)
{
    if (this != &str)   //如果不是自赋值
    {
        CMyString strTemp(str);     //创建临时实参strTemp

        //将局部变量的m_pData指向的地址与需要实例m_pData指向的地址互换
        //这种方法好在：
        //先创建一个临时实例，若不成功，抛出异常，不影响原来的自己
        //若成功，str_Temp是局部变量，在作用域if中，出了if就会自动调用析构函数
        //而我们把str_Temp.m_pData和原来自己的m_pData互换了，这时候析构的就是原来自己的空间
        char* pTemp = strTemp.m_pData;
        strTemp.m_pData = m_pData;
        m_pData = pTemp;

    }
    return *this;
}


//====================测试代码=========================
void CMyString::Print()
{
    cout << m_pData << endl;
}

//测试代码1
void Test1()
{
    cout << "Test1 begin: " << endl;
    char *text = "Hello World";
    CMyString str1(text);
    CMyString str2;
    str2 = str1;

    cout << "The expected result is : " << text << endl;
    cout << "The actual result is : ";
    str2.Print();
    cout << endl;
}

//测试代码2--自赋值
void Test2()
{
    cout << "Text2 begin: " << endl;
    char *text = "Hello World";
    CMyString str1(text);
    CMyString str2;
    str1 = str1;

    cout << "The expected result is : " << text << endl;
    cout << "The actual result is : ";
    str1.Print();
    cout << endl;
}

//测试代码3--连续赋值
void Text3()
{
    cout << "Text3 begin: " << endl;
    char *text = "Hello World";
    CMyString str1(text);
    CMyString str2, str3;
    str2 = str3 = str1;

    cout << "The expected result is : " << text << endl;
    cout << "The actual result is : ";
    str2.Print();
    cout << endl;
}


int main()
{
    Test1();
    Test1();
    Test1();

    return 0;
}


















