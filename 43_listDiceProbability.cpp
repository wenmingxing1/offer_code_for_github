#include<iostream>
#include<math.h>

using namespace std;

//计算n个骰子，和为s的次数
int CountNumber(int n, int s)
{
    if (s < n || s > 6*n)
        return 0;

    //一个骰子，出现每个点数的次数都是1
    if (n == 1)
        return 1;

    //递归公式
    return CountNumber(n-1, s-1) + CountNumber(n-1, s-2) + CountNumber(n-1, s-3)
            + CountNumber(n-1, s-4) + CountNumber(n-1, s-5) + CountNumber(n-1, s-6);
}

void listDictProbability(int n)
{
    int Total = pow(6, n);
    for (int i = n; i <= 6*n; ++i){
        cout << "The Sum " << i << "'s probability is " << CountNumber(n, i) << "/" << Total << endl;
    }
}

int main()
{
    listDictProbability(3);

    return 0;
}
