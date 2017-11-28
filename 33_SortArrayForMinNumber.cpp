#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
using namespace std;
class Solution {
public:
    static bool compare(int a, int b){	//����sort�еĲ�������Ϊstatic
        string A = "";
        string B = "";
        A += to_string(a);
        A += to_string(b);
        B += to_string(b);
        B += to_string(a);

        return A < B;	//�����С�ں����ַ����ıȽ�
    }
    string PrintMinNumber(vector<int> numbers) {
        string res = "";
        sort(numbers.begin(), numbers.end(), compare);
        for (int i = 0; i < numbers.size(); ++i){
            res += to_string(numbers[i]);
        }

        return res;
    }
};

int main()
{
    vector<int> nums = {3,32,321};
    Solution solu;
    cout << solu.PrintMinNumber(nums) << endl;

    return 0;
}
