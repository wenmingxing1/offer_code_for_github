#include<iostream>
using namespace std;

class Solution {
public:
    //暴力法，会超时
    int NumberOf1Between1AndN_Solution(int n)
    {
    	int result = 0;
        for (int i = 1; i <= n; ++i){
            result = result + number(i);
        }
        return result;
    }

private:
    int number(int n){
        int count = 0;
        while (n){
            if (n % 10 == 1){
                count++;
                //n = n / 10;
            }
            n = n / 10;
        }
        return count;
    }
};

int main()
{
    int n = 51;
    Solution solu;
    cout << solu.NumberOf1Between1AndN_Solution(n) << endl;

    return 0;
}
