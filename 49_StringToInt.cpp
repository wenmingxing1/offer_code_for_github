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

        bool isPositive = true;		//判断第一个符号
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

        if (isPositive)		//根据第一个判断的是否是符号位进行输出
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
