#include<iostream>

using namespace std;

class Solution
{
public:
    int Sum_Solution(int n)
    {
        int ans = n;
        ans && (ans += Sum_Solution(n - 1));    //���ö�·��ֵ��ʽʵ�ֵݹ��������������ansΪ0ʱ�Ͳ��ٵݹ�
        return ans;
    }
};

int main()
{
    Solution solu;
    cout << solu.Sum_Solution(5) << endl;

    return 0;
}
