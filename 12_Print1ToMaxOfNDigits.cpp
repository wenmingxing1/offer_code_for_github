#include<iostream>
#include<cstring>

using namespace std;

//判断是否到达了n个9999
bool Increment(char* number)
{
    bool isOverflow = false;    //没有到达
    int nTakeOver = 0;      //进位
    int nLength = strlen(number);   //n

    for (int i = nLength - 1; i >= 0; --i)
    {
        int nSum = number[i] - '0' + nTakeOver;
        if (i == nLength - 1)
            nSum++;

        if (nSum >= 10)     //如果超过10，则需要产生进位
        {
            if (i == 0)     //当i==0时，证明溢出了n位
                isOverflow = true;      //当i==0即到达最高位的时候，并且nSum=10，则证明超过了n个999达到了1000，改变标志位不打印
            else
            {
                nSum -= 10;
                nTakeOver = 1;  //进位为1，然后赋值到下一个判断中的nSum中（第15行）
                number[i] = '0' + nSum;     //以字符形式赋值到number[i]
            }
        }
        else    //如果不超过10，不用产生进位，则直接打印
        {
            number[i] = '0' + nSum;     //将nSum以字符形式赋值给number[i]
            break;
        }
    }
    return isOverflow;
}

void PrintNumber(char* number)
{
    bool isBeginning0 = true;
    int nLength = strlen(number);

    for (int i = 0; i < nLength; ++i)
    {
        if (isBeginning0 && number[i] != '0')
            isBeginning0 = false;
        if (!isBeginning0)
        {
            cout << number[i];
        }
    }
    cout << " ";
}

/*================一般方式====================*/
void Print1ToMaxOfNDigits_Normal(int n)
{
    if (n <= 0)
        return;
    char *number = new char[n+1];
    memset(number, '0', n);     //前n个位置初始化为'0'
    number[n] = '\0';

    while (!Increment(number))
    {
        PrintNumber(number);
    }

    delete []number;
}

/*=================递归方式=======================*/
void Print1ToMaxOfNDigitsRecursively(char* number, int length, int index)
{
    if (index == length - 1)    //当index到达length-1的时候证明分配满了，才开始打印
    {
        PrintNumber(number);
        return;
    }
    for (int i = 0; i < 10; ++i)
    {
        number[index + 1] = i + '0';
        Print1ToMaxOfNDigitsRecursively(number, length, index + 1);     //每次递归调用填满index的下一位置
    }
}

void Print1ToMaxOfNDigits(int n)
{
    if (n <= 0)
        return;

    char *number = new char[n + 1];
    number[n] = '\0';

    for (int i = 0; i < 10; ++i)
    {
        number[0] = i + '0';
        Print1ToMaxOfNDigitsRecursively(number, n, 0);
    }
    delete []number;
}

int main()
{
    Print1ToMaxOfNDigits_Normal(2);

    cout << endl;

    Print1ToMaxOfNDigits(2);

    cout << endl;

    return 0;
}
