#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    int GetNumberOfK(vector<int> data ,int k) {
        if (data.size() <= 0)
            return 0;
        int FirstK = GetFirstK(data, k, 0, data.size() - 1);
        int LastK = GetLastK(data, k, 0, data.size() - 1);

        if (LastK != -1 && FirstK != -1)
            return LastK - FirstK + 1;
        else
            return 0;

    }
private:
    int GetFirstK(vector<int> data, int k, int start, int end){
        if (start > end)    //递归结束条件
            return -1;
        int middle = start + (end - start) / 2;
        if (data[middle] == k){
            if ((middle > 0 && data[middle - 1] != k) || middle == 0)
                return middle;
            else
                end = middle - 1;
        }
        else if (data[middle] > k){
            end = middle - 1;
        }
        else if (data[middle] < k){
            start = middle + 1;
        }
        return GetFirstK(data, k, start, end);
    }

    int GetLastK(vector<int> data, int k, int start, int end){
        if (start > end)    //递归结束条件
            return -1;
        int middle = start + (end - start) / 2;
        if (data[middle] == k){
            if ((middle < end && data[middle + 1] != k) || middle == end)
                return middle;
            else
                start = middle + 1;
        }
        else if (data[middle] > k){
            end = middle - 1;
        }
        else if (data[middle] < k){
            start = middle + 1;
        }
        return GetLastK(data, k, start, end);
    }
};

int main()
{
    Solution solu;
    vector<int> data = {1,3,3,3,3,4,5};
    cout << solu.GetNumberOfK(data,2) << endl;

    return 0;
}
