#include<iostream>
using namespace std;

class Solution {
public:
    int GetUglyNumber_Solution(int index) {
        if (index <= 0)
            return 0;
        int number = 0;
        int uglyFound = 0;
        while (uglyFound < index){
            ++number;
            if (IsUglyNumber(number))
                ++uglyFound;
        }

        return number;
    }
private:
    bool IsUglyNumber(int number){
        while (number % 2 == 0)
            number /= 2;
        while (number % 3 == 0)
            number /= 3;
        while (number % 5 == 0)
            number /= 5;

        if (number == 1)
            return true;
        else
            return false;
    }
};

int main()
{
    Solution solu;
    cout << solu.GetUglyNumber_Solution(7) << endl;

    return 0;
}
