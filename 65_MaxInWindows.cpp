#include<iostream>
#include<vector>
#include<deque>

using namespace std;

class Solution
{
public:
    vector<int> maxInWindows(const vector<int>& num, unsigned int size)
    {
        vector<int> res;
        deque<int> index;   //˫����б�������

        if (num.size() == 0 || size == 0)
            return res;

        for (int i = 0; i < num.size(); ++i)
        {
            while (index.size() && num[i] > num[index.back()])  //���������ֵ����dequeĩβֵ���򵯳�ĩβֵ
                index.pop_back();
            if (index.size() && (i-index.front()) >= size)  //���front�Ѿ����ڴ����У��򵯳�front
                index.pop_front();
            index.push_back(i);

            if (i+1 >= size)    //�����ﻬ�����ڳ���ʱ����ʼ��¼���ֵ
                res.push_back(num[index.front()]);
        }
        return res;
    }
};

int main()
{
    vector<int> num = {2,3,4,2,6,2,5,1};
    Solution solu;
    vector<int> res = solu.maxInWindows(num, 3);

    for (int i = 0; i < res.size(); ++i)
    {
        cout << res[i] << ",";
    }

    return 0;
}
