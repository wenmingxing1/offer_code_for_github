#include<iostream>
#include<vector>

using namespace std;

/*
class Solution
{
public:
    void ReorderArray(vector<int>& nums)
    {
        int start = 0;
        int end = nums.size() - 1;

        while (start < end)
        {
            while (nums[start] % 2 == 1)
                start++;
            while (nums[end] % 2 == 0)
                end--;

            if (start < end)
                Swap(&nums[start], &nums[end]);
        }
    }
private:
    void Swap(int* i, int* j)
    {
        int temp;
        temp = *i;
        *i = *j;
        *j = temp;
    }
};
*/

/*=============将函数写成模式=================*/
void Swap(int* i, int* j)
{
    int temp = *i;
    *i = *j;
    *j = temp;
}

void Recorder(vector<int>& nums, bool (*func)(int))
{
    if(nums.empty())
        return;

    int start = 0;
    int end = nums.size() - 1;
    while (start < end)
    {
        while (!func(nums[start]))
            start++;
        while (func(nums[end]))
            end--;

        if (start < end)
            Swap(&nums[start], &nums[end]);
    }
}

bool isEven(int n)
{
    return (n % 2 == 0);
}

void RecorderOddEven(vector<int> &nums)
{
    Recorder(nums, isEven);
}

int main()
{
    //Solution solu;
    vector<int> nums = {1,2,3,4,5,6,7};

    for (int i = 0; i < nums.size(); ++i)
    {
        cout << nums[i] << " ";
    }

    cout << endl;

    //solu.ReorderArray(nums);
    RecorderOddEven(nums);

    for (int i = 0; i < nums.size(); ++i)
    {
        cout << nums[i] << " ";
    }

    return 0;
}
