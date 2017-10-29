#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    //�������Ϊ������
    vector<int> multiply(const vector<int>& A) {
    	int length = A.size();
    	vector<int> result(length);
        if (length <= 0)
            return result;

        //��ֵǰ�벿��
        result[0] = 1;
        for (int i = 1; i < length; ++i){
            result[i] = result[i - 1] * A[i - 1];
        }

        //��ֵ��벿��
        int temp = 1;
        for (int i = length - 1; i >= 0; --i){
            result[i] = result[i] * temp;
            temp = temp * A[i];
        }
        return result;
    }
};

int main()
{
    vector<int> A = {1,2,3,4,5};
    vector<int> result;
    Solution solu;
    result = solu.multiply(A);

    for (int i = 0; i < result.size(); ++i)
    {
        cout << result[i] << " " << endl;
    }

    return 0;
}
