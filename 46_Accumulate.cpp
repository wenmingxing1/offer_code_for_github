#include<iostream>

using namespace std;

class Solution
{
public:
    int Sum_Solution(int n)
    {
        int ans = n;
        ans && (ans += Sum_Solution(n - 1));    //利用短路求值方式实现递归结束条件，级当ans为0时就不再递归
        return ans;
    }
};

int main()
{
    Solution solu;
    cout << solu.Sum_Solution(5) << endl;

    return 0;
}
