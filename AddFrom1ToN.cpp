//求1+2+...+n

#include<iostream>
using namespace std;

//递归形式
int AddFrom1ToN_Recursive(int n)
{
    return n < 0 ? 0 : AddFrom1ToN_Recursive(n-1) + n;
}

//循环形式
int AddFrom1ToN_Iterative(int n)
{
    int sum = 0;
    for (int i = 1; i <= n; ++i)
    {
        sum = sum + i;
    }
    return sum;
}

int main()
{
    cout << AddFrom1ToN_Iterative(5) << endl;
    cout << AddFrom1ToN_Recursive(5) << endl;
    return 0;
}
