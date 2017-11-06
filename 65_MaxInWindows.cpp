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
        deque<int> index;   //双向队列保存索引

        if (num.size() == 0 || size == 0)
            return res;

        for (int i = 0; i < num.size(); ++i)
        {
            while (index.size() && num[i] > num[index.back()])  //如果新来的值大于deque末尾值，则弹出末尾值
                index.pop_back();
            if (index.size() && (i-index.front()) >= size)  //如果front已经不在窗口中，则弹出front
                index.pop_front();
            index.push_back(i);

            if (i+1 >= size)    //当到达滑动窗口长度时，开始记录最大值
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
