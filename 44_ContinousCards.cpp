#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

class Solution {
public:
    bool IsContinuous( vector<int> numbers ) {
        int length = numbers.size();
        if (length < 5)
            return false;
        sort(numbers.begin(), numbers.end());	//����
        int NumberOf0 = 0;
        int NumberOfGap = 0;

        for (int i = 0; i < 5; ++i){	//ͳ��0�ĸ���
            if (numbers[i] == 0)
                ++NumberOf0;
        }

        int small = NumberOf0;		//��Ϊ����֮��0����ǰ�棬����small��ֵΪ��һ����Ϊ0����
        int big = small + 1;	//big��Ϊsmall����һ�����֣���ͳ��Gap������
        while (big < length){
            if (numbers[small] == numbers[big])		//��������г���������ͬ��������ֱ�ӷ���false
                return false;

            NumberOfGap += numbers[big] - numbers[small] - 1;	//����Gap������
            small = big;
            big++;
        }
        return (NumberOf0 < NumberOfGap) ? false : true;
    }
};

int main()
{
    vector<int> nums = {9,0,6,0,1};
    Solution solu;
    cout << solu.IsContinuous(nums) << endl;

    return 0;
}
