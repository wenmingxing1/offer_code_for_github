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
        if (start == end){		//�ݹ��������,��ֻ��һ����ʱ����
            copy[start] = data[start];		//��������ݴ���copy��
            return 0;
        }

        int length = (end - start) / 2;

        int left = InversePairsCore(data, copy, start, start + length);
        int right = InversePairsCore(data, copy, start + length + 1, end);

        //i��ʼ��Ϊǰ������һ��
        int i = start + length;
        //j��ʼ��Ϊ�������һ��
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

        for (int i = start; i <= end; ++i){     //��֤data����
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
