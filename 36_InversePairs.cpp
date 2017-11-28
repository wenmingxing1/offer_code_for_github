#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int InversePairs(vector<int> data) {
        int length = data.size();
        if (length <= 0)
            return 0;
        vector<int> copy(length);

        int count = InversePairsCore(data, copy, 0 ,length - 1);
        return count;
    }
private:
    int InversePairsCore(vector<int> &data, vector<int> &copy, int start, int end){
        if (start == end){		//递归结束条件,当只有一个数时返回
            copy[start] = data[start];		//将最后数据存入copy中
            return 0;
        }

        int length = (end - start) / 2;

        int left = InversePairsCore(data, copy, start, start + length);
        int right = InversePairsCore(data, copy, start + length + 1, end);

        //i初始化为前半段最后一个
        int i = start + length;
        //j初始化为后半段最后一个
        int j = end;
        int indexCopy = end;
        int count = 0;
        while (i >= start && j >= start + length + 1){
            if (data[i] > data[j]){
                copy[indexCopy] = data[i];
                indexCopy--;
                i--;
                count += (j - start - length);
            }
            else{
                copy[indexCopy] = data[j];
                indexCopy--;
                j--;
            }
        }

        for (; i >= start; --i){
            copy[indexCopy] = data[i];
            indexCopy--;

        }
        for (; j >= start + length + 1; --j){
            copy[indexCopy] = data[j];
            indexCopy--;
        }

        for (int i = start; i <= end; ++i){     //保证data有序
            data[i] = copy[i];
        }
        return count + left + right;

    }
};

int main()
{
    vector<int> data = {7,5,6,4};
    Solution solu;
    cout << solu.InversePairs(data) << endl;

    return 0;
}
