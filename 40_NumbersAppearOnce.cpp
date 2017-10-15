#include<iostream>
#include<vector>

using namespace std;

/*=============利用vector构建hash==================*/
class Solution
{
public:
    vector<int> FindNumsAppearOnce(vector<int> data)
    {
        vector<int> result;
        vector<int> hashtable(data.size(), 0);
        for (int i = 0; i < data.size(); ++i)
        {
            hashtable[data[i]]++;
        }
        for (int i = 0; i < hashtable.size(); ++i)
        {
            if (hashtable[data[i]] == 1)
               result.push_back(data[i]);
        }
        return result;
    }
};

/*================时间复杂度为O(n),空间复杂度为O(1)的方法=================*/
class Solution2
{
public:
    void FindNumsAppearOnce(vector<int> data, int* num1, int* num2)
    {
        if (data.size() <= 0)
            return;
        int result_temp = 0;
        for (int i = 0; i < data.size(); ++i)
        {
            result_temp = result_temp ^ data[i];
        }
        int TheFirst1 = FindFirst1(result_temp);
        *num1 = *num2 = 0;
        for (int i = 0; i < data.size(); ++i)
        {
            if (Is1(data[i], TheFirst1))
                *num1 = *num1 ^ data[i];
            else
                *num2 = *num2 ^ data[i];
        }
    }
private:
    int FindFirst1(int num)
    {
        int index = 0;
        while (((num & 1) == 0) && index < 8*sizeof(int))
        {
            num = num >> 1;
            index++;
        }
        return index;
    }

    bool Is1(int num, int index)
    {
        num = num >> index;
        return (num & 1);
    }

};

int main()
{
    Solution solu;
    vector<int> result;
    vector<int> data = {2,4,3,6,3,2,5,5};
    result = solu.FindNumsAppearOnce(data);

    for (int i = 0; i < result.size(); ++i)
    {
        cout << result[i] << " ";
    }

    return 0;
}
