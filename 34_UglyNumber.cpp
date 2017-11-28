#include<iostream>
using namespace std;

//暴力法，需要计算非丑数的元素
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

//以空间换时间，只需计算丑数部分，将有序的丑数存放在数组中
class Solution2 {
public:
    int GetUglyNumber_Solution(int index) {
    	if (index <= 0)
            return 0;
        vector<int> Ugly(index);
        Ugly[0] = 1;
        int next = 1;

        int multi2 = 0, multi3 = 0, multi5 = 0;
        while (next < index){
            Ugly[next] = min(Ugly[multi2]*2, Ugly[multi3]*3, Ugly[multi5]*5);

            //记录三种位置
            if (Ugly[next] == Ugly[multi2]*2)
                ++multi2;
            if (Ugly[next] == Ugly[multi3]*3)
                ++multi3;
            if (Ugly[next] == Ugly[multi5]*5)
                ++multi5;

            ++next;
        }
        return Ugly[index-1];
    }
private:
    int min(int i, int j, int k){
        int res = i < j ? i : j;
        res = res < k ? res : k;
        return res;
    }
};

int main()
{
    Solution solu;
    cout << solu.GetUglyNumber_Solution(7) << endl;

    return 0;
}
