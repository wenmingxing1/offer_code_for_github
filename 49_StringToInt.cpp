#include<iostream>
#include<string>

using namespace std;

class Solution {
public:
    int StrToInt(string str) {
        int length = str.size();
        if (length <= 0)
            return 0;
        string::iterator iter = str.begin();

        bool isPositive = true;		//�жϵ�һ������
        if (*iter == '-'){
            isPositive = false;
            iter++;
        }
        else if (*iter == '+'){
            iter++;
        }

        int number = 0;
        while (iter != str.end()){
            if (*iter >= '0' && *iter <= '9'){
                number = number * 10 + *iter - '0';
                iter++;
            }
            else
                return 0;
        }

        if (isPositive)		//���ݵ�һ���жϵ��Ƿ��Ƿ���λ�������
        	return number;
        else
            return 0 - number;
    }
};


int main()
{
    string s = "+";
    Solution solu;
    cout << solu.StrToInt(s) << endl;

    return 0;
}
