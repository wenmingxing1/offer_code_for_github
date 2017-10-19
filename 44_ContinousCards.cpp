#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

class Solution {
public:
    bool IsContinuous( vector<int> numbers ) {
        int length = numbers.size();
        if (length < 5)
            return false;
        sort(numbers.begin(), numbers.end());	//排序
        int NumberOf0 = 0;
        int NumberOfGap = 0;

        for (int i = 0; i < 5; ++i){	//统计0的个数
            if (numbers[i] == 0)
                ++NumberOf0;
        }

        int small = NumberOf0;		//因为排序之后0在最前面，所以small的值为第一个不为0的数
        int big = small + 1;	//big设为small的下一个数字，以统计Gap的数量
        while (big < length){
            if (numbers[small] == numbers[big])		//如果数组中出现两个相同的数，则直接返回false
                return false;

            NumberOfGap += numbers[big] - numbers[small] - 1;	//更新Gap的数量
            small = big;
            big++;
        }
        return (NumberOf0 < NumberOfGap) ? false : true;
    }
};

int main()
{
    vector<int> nums = {9,0,6,0,1};
    Solution solu;
    cout << solu.IsContinuous(nums) << endl;

    return 0;
}
