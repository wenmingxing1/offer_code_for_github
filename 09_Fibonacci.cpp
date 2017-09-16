//Fibonacci数列
#include<iostream>
using namespace std;

//递归方式，包含大量重复计算
int Fibonacci_Recursive(int n)
{
    if (n < 0)
        return -1;
    if (n == 0)
        return 0;
    else if (n == 1)
        return 1;
    else
        return Fibonacci_Recursive(n - 1) + Fibonacci_Recursive(n - 2);
}

//循环方式
int Fibonacci_Iterative(int n)
{
    int result[2] = {0, 1};
    if (n < 2)
        return result[n];

    int i = 0;
    int j = 1;
    int FibN = 0;
    for (int index = 2; index <= n; ++index)    //相当于两个指针不断向后移动
    {
        FibN = i + j;
        i = j;
        j = FibN;
    }

    return FibN;
}

int main()
{
    cout << Fibonacci_Recursive(6) << endl;
    cout << Fibonacci_Iterative(6) << endl;

    return 0;
}
