#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int InversePairs(vector<int> data) {
        int length = data.size();
        if (length <= 0)
            return 0;
        vector<int> copy;
        for (int i = 0; i < length; ++i){
            copy.push_back(data[i]);
        }
        int count = InversePairsCore(data, copy, 0 ,length - 1);
        return count % 1000000007;
    }
private:
    int InversePairsCore(vector<int> &data, vector<int> &copy, int start, int end){
        if (start == end){		//递归结束条件
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
    vector<int> data = {364,637,341,406,747,995,234,971,571,219,993,407,416,366,315,301,601,650,418,355,460,505,360,965,516,648,727,667,465,849,455,181,486,149,588,233,144,174,557,67,746,550,474,162,268,142,463,221,882,576,604,739,288,569,256,936,275,401,497,82,935,983,583,523,697,478,147,795,380,973,958,115,773,870,259,655,446,863,735,784,3,671,433,630,425,930,64,266,235,187,284,665,874,80,45,848,38,811,267,575};
    Solution solu;
    cout << solu.InversePairs(data) << endl;

    return 0;
}
