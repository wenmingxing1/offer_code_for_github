#include<iostream>
#include<math.h>

using namespace std;

//判断两个double是否相等
bool Equal(double num1, double num2)
{
    if ((num1 - num2 > -0.0000001) && (num1 - num2 < 0.0000001))
    {
        return true;
    }
    else
        return false;
}

//常规power
double PowerNormal(double base, unsigned int exponent)
{
    double result = 1.0;
    for (int i = 0; i < exponent; ++i)
    {
        result = result * base;
    }
    return result;
}

/*=============优化计算次数的PowerNormal===================*/
double PowerNormal_opt(double base, int exponent)
{
    if (exponent == 0)
        return 0;
    if (exponent == 1)
        return base;
    double result = PowerNormal_opt(base, exponent >> 1);   //右移等价于除以2
    result *= result;   //如果是偶数则平方
    if (exponent & 0x1 == 1)    //与1相与相当于求%（最后以为不是1则是奇数）
        result *= base;     //如果是奇数，则再乘以一个base

    return result;
}

//考虑特殊情况下的power
double Power(double base, int exponent)
{

    if (exponent == 0)
        return 1.0;

    if (Equal(base, 0.0) && exponent < 0)
    {
        cout << "Invaild input!(指数为负数，底数不能为0)" << endl;
        return 0.0;
    }

    if (exponent > 0.0)
        return PowerNormal_opt(base, exponent);
    else if (exponent < 0.0)
        return (1 / PowerNormal_opt(base, -exponent));

}

int main()
{
    cout << Power(1.5, -1) << endl;

    cout << pow(1.5, -1) << endl;
    return 0;
}
