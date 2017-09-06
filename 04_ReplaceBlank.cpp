//面试题4
//题目：请实现一个函数，把字符串中的每个空格替换成“%20”。
//例如，“We are happy.”，则输出“We%20are%20happy.”

#include<iostream>

//================使用string======================
/*
#include<string>

using namespace std;

string replace_blank(string str)
{
    for (int i = 0; i < str.size(); ++i)
    {
        if (str[i] == ' ')
            str = str.substr(0,i) + "%20" + str.substr(i+1);
    }
    return str;
}

int main()
{
    string str = "We are happy";
    cout << replace_blank(str) << endl;

    return 0;
}
*/

//=========================不使用string=======================

using namespace std;

void ReplaceBlank(char *str, int length)
{
    int i, j;
    int count = 0;  //空格数量
    int len = length;   //字符串长度
    for (int i = 0; i < length; ++i)    //先迭代判断空格数量
    {
        if (str[i] == ' ')
        {
            ++count;
        }
    }

    len = length + count * 2;   //更新字符串长度

    for (i = length - 1, j = len - 1; i >= 0 && j >= 0;)    //i指向原始字符串末尾字符，j指向更新之后字符串末尾字符位置
    {
        if (str[i] == ' ')
        {
            str[j--] = '0';
            str[j--] = '2';
            str[j--] = '%';
            i--;        //如果遇到空格，i向前移动一位，j移动三位并加上%20
        }
        else
        {
            str[j--] = str[i--];    //如果不是空格，直接将i处移动到j处，并都向前移动一位
        }
    }
    str[len] = '\0';    //字符串末尾标志

}

int main()
{
    //cout << "input a string: " << endl;


    char str[12 + 1] = "We are happy";
    int str_len = sizeof(str);
    ReplaceBlank(str, str_len);

    cout << str << endl;

    return 0;
}















