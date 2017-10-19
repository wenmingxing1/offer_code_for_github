#include<iostream>
using namespace std;

class Solution
{
public:
    int AddTwoNumbers(int num1, int num2)
    {
        while (num2 != 0)
        {
            int sum = num1 ^ num2;
            num2 = (num1 & num2) << 1;
            num1 = sum;
        }
        return num1;
    }
};

int main()
{
    Solution solu;
    cout << solu.AddTwoNumbers(5,6) << endl;

    return 0;
}
