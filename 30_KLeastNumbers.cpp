#include<iostream>
#include<vector>
#include<stdlib.h>
using namespace std;

/*==============��������===================*/
class Solution {
public:
    vector<int> GetLeastNumbers_Solution(vector<int> input, int k) {
        vector<int> result;
        if (k > input.size() || k <= 0)
            return result;

        int start = 0;
        int end = input.size() - 1;
        int index = Partation(input, start, end);
        while (index != k - 1){     //�ҵ�����λ�õ���Ϊֹ
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

    int Partation(vector<int>& data, int start, int end){       //��ΪҪ�ı�data���Բ�������
        int middle = Random(start, end);
        Swap(&data[middle], &data[end]);	//��end����Ϊ��׼

        int small = start - 1;      //�ڱ�����
        for (int i = start; i < end; ++i){
            if (data[i] < data[end]){
                ++small;
                if (small != i)     //��ֹ���ཻ��
                    Swap(&data[small], &data[i]);
            }
        }

        ++small;
        Swap(&data[small], &data[end]);

        return small;
    }
};

/*==================�������ݲ�������================*/
/*
class Solution{
public:
    vector<int> GetLeastNumbers_Solution(vector<int> input, int k){
        int len = input.size();
        if (len <= 0 || k > len || k <= 0)
            return vector<int>();       //�����vector

        vector<int> res(input.begin(), input.begin() + k);  //�����װ��ǰk����

        //��������
        make_heap(res.begin(), res.end());
        for (int i = k; i < len; ++i){
            if (input[i] < res[0]){
                //��pop��Ȼ����������ɾ��
                pop_heap(res.begin(), res.end());   //�����Ԫ��pop����ʣ��Ԫ������ά��Ϊһ����
                res.pop_back();

                //���������м��룬��push
                res.push_back(input[i]);
                push_heap(res.begin(), res.end());     //�Ըղ����Ԫ����������
            }
        }

        sort_heap(res.begin(), res.end());  //��С����
        return res;
    }
};
*/

/*==================�����������ú����_multiset=================*/
/*
class Solution{
public:
    vector<int> GetleastNumbers_Solution(vector<int> input, int k){
        int len = input.size();
        if (len <= 0 || k > len || k <= 0)
            return vector<int>();

        //�º����е�greater<T>ģ�壬�Ӵ�С����
        multiset<int, greater<int>> leastNums;
        vector<int>::iterator vec = input.begin();
        for (; vec != input.end(); ++vec){
            //��ǰk��Ԫ�ز��뼯��
            if (leastNums.size() < k)
                leastNums.insert(*vec);
            else{
                //��һ��Ԫ�������ֵ
                //multiset<int, greater<int>>::iterator greatest = leastNums.begin();
                //�������Ԫ��С�����ֵ��ɾ����һ�������뵱ǰԪ��
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
