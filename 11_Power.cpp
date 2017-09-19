#include<iostream>
#include<math.h>

using namespace std;

//�ж�����double�Ƿ����
bool Equal(double num1, double num2)
{
    if ((num1 - num2 > -0.0000001) && (num1 - num2 < 0.0000001))
    {
        return true;
    }
    else
        return false;
}

//����power
double PowerNormal(double base, unsigned int exponent)
{
    double result = 1.0;
    for (int i = 0; i < exponent; ++i)
    {
        result = result * base;
    }
    return result;
}

/*=============�Ż����������PowerNormal===================*/
double PowerNormal_opt(double base, int exponent)
{
    if (exponent == 0)
        return 0;
    if (exponent == 1)
        return base;
    double result = PowerNormal_opt(base, exponent >> 1);   //���Ƶȼ��ڳ���2
    result *= result;   //�����ż����ƽ��
    if (exponent & 0x1 == 1)    //��1�����൱����%�������Ϊ����1����������
        result *= base;     //��������������ٳ���һ��base

    return result;
}

//������������µ�power
double Power(double base, int exponent)
{

    if (exponent == 0)
        return 1.0;

    if (Equal(base, 0.0) && exponent < 0)
    {
        cout << "Invaild input!(ָ��Ϊ��������������Ϊ0)" << endl;
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
