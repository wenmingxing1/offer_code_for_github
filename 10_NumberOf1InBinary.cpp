#include<iostream>

using namespace std;

//通过将n不断右移与1相与判断，但是这样对于有符号数中的负数会陷入死循环
int NumberOf1_Solution1(int n)
{
    int count = 0;
    while (n)
    {
        if (n & 1)
            count ++;
        n = n >> 1;
    }
    return count;
}

//通过将1不断左移1->10->100... 与n相与计算结果，但是干循环的次数由于while循环条件，等于二进制的位数，即32.
int NumberOf1_Solution2(int n)
{
    int count = 0;
    unsigned int i = 1;
    while (i)
    {
        if (n & i)
            count ++;
        i = i << 1;
    }
    return count;
}

//整数中有几个1就只需要循环几次
int NumberOf1_Solution3(int n)
{
    int count = 0;
    while (n)
    {
        count++;
        n = n & (n - 1);
    }
    return count;
}

int main()
{
    cout << NumberOf1_Solution1(9) << endl;
    //cout << NumberOf1_Solution1(-9) << endl;    //死循环

    cout << NumberOf1_Solution2(9) << endl;
    cout << NumberOf1_Solution2(-9) << endl;

    cout << NumberOf1_Solution3(9) << endl;
    cout << NumberOf1_Solution3(-9) << endl;

    return 0;
}
