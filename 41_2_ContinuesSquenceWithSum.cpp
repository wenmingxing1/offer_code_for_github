#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> result;
    vector<vector<int> > FindContinuousSequence(int sum) {
        int small = 1;
        int big = 2;
        int Cursum = 3;
        while (small < big){
            Cursum = (small + big)*(big - small +1)/2;
            if (Cursum < sum)
                ++big;
            if (Cursum == sum){
                vector<int> temp;
                for (int i = small; i <= big; ++i){
                    temp.push_back(i);
                }
                result.push_back(temp);
                ++small;	//此句很重要,不可缺少，要不然无法完成while循环
            }
            if (Cursum > sum)
                ++small;
        }
        return result;
    }
};

int main()
{
    Solution solu;
    vector<vector<int>> result;
    result = solu.FindContinuousSequence(15);
    for (int i = 0; i < result.size(); ++i)
    {
        for (int j = 0; j < result[i].size(); ++j)
        {
            cout << result[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}
