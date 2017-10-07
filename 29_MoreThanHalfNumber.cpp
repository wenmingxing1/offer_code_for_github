#include<iostream>
#include<vector>
#include<stdlib.h>
using namespace std;

class Solution {
public:
    //�ҵ������е�middle�������,��Ϊ����
    int MoreThanHalfNum_Solution(vector<int> numbers) {
        if (!CheckInvalidArray(numbers))
            return 0;
        int middle = numbers.size() >> 1;
        int start = 0;
        int end = numbers.size() - 1;
        int index = Partation(numbers, start, end);

        while (index != middle){
            if (index > middle){
                end = index - 1;
                index = Partation(numbers, start, end);
            }
            if (index < middle){
                start = index + 1;
                index = Partation(numbers, start, end);
            }
        }

        int result = numbers[middle];
        if (!CheckMoreThanHalf(numbers, result))
            return 0;

        return result;

    }
private:

    //��������Ƿ�Ϸ�
    bool CheckInvalidArray(vector<int> numbers){
        bool check = false;
        if (numbers.size() > 0)
            check = true;
        return check;
    }

    //��������Ƿ񳬹�һ��
    bool CheckMoreThanHalf(vector<int> numbers, int number){
        int count = 0;
        for (int i = 0; i < numbers.size(); ++i){
            if (number == numbers[i])
                count++;
        }
        if (count > numbers.size()/2)
            return true;
        else
            return false;
    }

    void Swap(int* i, int* j){
        int temp = *i;
        *i = *j;
        *j = temp;
    }

    //�������λ��
    int Random(int start, int end){
        if (end > start)
            return start + rand() % (end - start);
        else
            return 0;
    }

    int Partation(vector<int> numbers, int start, int end){
        int middle = Random(start, end);
        Swap(&numbers[middle], &numbers[end]);

        int small = start - 1;
        for (int index = start; index < end; ++index){
            if (numbers[index] < numbers[end]){
                small++;
                if (small != index)
                    Swap(&numbers[small], &numbers[index]);		//smallǰ����С�ģ�small��index�Ǵ�ģ�index��end��ûɨ�赽��
            }
        }
        small++;
        Swap(&numbers[end], &numbers[small]);

        return small;
    }
};

/*=============���ı�����ⷨ=====================*/
class Solution2{
public:
    int MoreThanHalfNum(vector<int> numbers){
        if (numbers.size() == 0)
            return 0;
        int result = numbers[0];
        int times = 1;
        for (int i = 1; i < numbers.size(); ++i){
            if (times == 0){
                result = numbers[i];
                times = 1;
            }
            else if (numbers[i] == result)
                times++;
            else
                times--;
        }

        if (CheckMoreThanHalf(numbers, result)){
            return result;
        }
        else
            return 0;
    }

private:
    bool CheckMoreThanHalf(vector<int> numbers, int k){
        int count = 0;
        for (int i = 0; i < numbers.size(); ++i){
            if (k == numbers[i])
                count++;
        }
        if (count > numbers.size() / 2)
            return true;
        else
            return false;
    }
};

int main()
{
    vector<int> numbers = {2,2,4,3,2,2};
    Solution2 solu;
    cout << solu.MoreThanHalfNum(numbers) << endl;

    return 0;
}
