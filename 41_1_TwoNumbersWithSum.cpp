#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    vector<int> result;
    vector<int> FindNumbersWithSum(vector<int> array,int sum) {
        if (array.size() <= 0)
            return result;
        int small = 0;
        int big = array.size() - 1;
        while (small < big){
            if (array[small] + array[big] == sum){
                result.push_back(array[small]);
                result.push_back(array[big]);
                break;
            }
            else if (array[small] + array[big] > sum){
                big--;
            }
            else
                small++;
        }
        return result;
    }
};

int main()
{
    vector<int> data = {1,2,3,4,5,6,7,8};
    Solution solu;
    vector<int> result = solu.FindNumbersWithSum(data, 11);
    for (int i = 0; i < result.size(); ++i)
    {
        cout << result[i] << " ";
    }

    return 0;
}
