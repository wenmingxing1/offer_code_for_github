//Fibonacci����
#include<iostream>
using namespace std;

//�ݹ鷽ʽ�����������ظ�����
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

//ѭ����ʽ
int Fibonacci_Iterative(int n)
{
    int result[2] = {0, 1};
    if (n < 2)
        return result[n];

    int i = 0;
    int j = 1;
    int FibN = 0;
    for (int index = 2; index <= n; ++index)    //�൱������ָ�벻������ƶ�
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
