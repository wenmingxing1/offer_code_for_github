#include<iostream>
#include<vector>
#include<stdlib.h>
using namespace std;

/*==============常规数据===================*/
class Solution {
public:
    vector<int> GetLeastNumbers_Solution(vector<int> input, int k) {
        vector<int> result;
        if (k > input.size() || k <= 0)
            return result;

        int start = 0;
        int end = input.size() - 1;
        int index = Partation(input, start, end);
        while (index != k - 1){     //找到所在位置的数为止
            if (index > k - 1){
                end = index - 1;
                index = Partation(input, start, end);
            }
            if (index < k - 1){
                start = index + 1;
                index = Partation(input, start, end);
            }
        }

        for (int i = 0; i < k; ++i){
            result.push_back(input[i]);
        }
        return result;
    }

private:
    void Swap(int* i, int* j){
        int temp = *i;
        *i = *j;
        *j = temp;
    }

    int Random(int start, int end){
        if (end > start){
            return start + rand() % (end - start);
        }
        else
            return 0;
    }

    int Partation(vector<int>& data, int start, int end){       //因为要改变data所以采用引用
        int middle = Random(start, end);
        Swap(&data[middle], &data[end]);	//以end处作为基准

        int small = start - 1;      //哨兵作用
        for (int i = start; i < end; ++i){
            if (data[i] < data[end]){
                ++small;
                if (small != i)     //防止多余交换
                    Swap(&data[small], &data[i]);
            }
        }

        ++small;
        Swap(&data[small], &data[end]);

        return small;
    }
};

/*==================海量数据采用最大堆================*/
/*
class Solution{
public:
    vector<int> GetLeastNumbers_Solution(vector<int> input, int k){
        int len = input.size();
        if (len <= 0 || k > len || k <= 0)
            return vector<int>();       //输出空vector

        vector<int> res(input.begin(), input.begin() + k);  //结果中装填前k个数

        //建立最大堆
        make_heap(res.begin(), res.end());
        for (int i = k; i < len; ++i){
            if (input[i] < res[0]){
                //先pop，然后再容器中删除
                pop_heap(res.begin(), res.end());   //将最大元素pop并将剩余元素重新维护为一个堆
                res.pop_back();

                //先在容器中加入，再push
                res.push_back(input[i]);
                push_heap(res.begin(), res.end());     //对刚插入的元素做堆排序
            }
        }

        sort_heap(res.begin(), res.end());  //从小到大
        return res;
    }
};
*/

/*==================海量数据利用红黑树_multiset=================*/
/*
class Solution{
public:
    vector<int> GetleastNumbers_Solution(vector<int> input, int k){
        int len = input.size();
        if (len <= 0 || k > len || k <= 0)
            return vector<int>();

        //仿函数中的greater<T>模板，从大到小排序
        multiset<int, greater<int>> leastNums;
        vector<int>::iterator vec = input.begin();
        for (; vec != input.end(); ++vec){
            //将前k个元素插入集合
            if (leastNums.size() < k)
                leastNums.insert(*vec);
            else{
                //第一个元素是最大值
                //multiset<int, greater<int>>::iterator greatest = leastNums.begin();
                //如果后续元素小于最大值，删除第一个，插入当前元素
                if (*vec < *(leastNums.begin()){
                    leastNums.erase(leastNums.begin());
                    leastNums.insert(*vec);
                }
            }
        }
        return vector<int>(leastNums.begin(), leastNums.end());
    }
};
*/


int main()
{
    vector<int> input = {4,5,1,6,2,7,3,8};
    Solution solu;
    vector<int> output = solu.GetLeastNumbers_Solution(input, 4);

    for (int i = 0; i < 4; ++i){
        cout << output[i] << " ";
    }

    return 0;
}
