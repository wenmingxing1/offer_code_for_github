//������4
//��Ŀ����ʵ��һ�����������ַ����е�ÿ���ո��滻�ɡ�%20����
//���磬��We are happy.�����������We%20are%20happy.��

#include<iostream>

//================ʹ��string======================
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

//=========================��ʹ��string=======================

using namespace std;

void ReplaceBlank(char *str, int length)
{
    int i, j;
    int count = 0;  //�ո�����
    int len = length;   //�ַ�������
    for (int i = 0; i < length; ++i)    //�ȵ����жϿո�����
    {
        if (str[i] == ' ')
        {
            ++count;
        }
    }

    len = length + count * 2;   //�����ַ�������

    for (i = length - 1, j = len - 1; i >= 0 && j >= 0;)    //iָ��ԭʼ�ַ���ĩβ�ַ���jָ�����֮���ַ���ĩβ�ַ�λ��
    {
        if (str[i] == ' ')
        {
            str[j--] = '0';
            str[j--] = '2';
            str[j--] = '%';
            i--;        //��������ո�i��ǰ�ƶ�һλ��j�ƶ���λ������%20
        }
        else
        {
            str[j--] = str[i--];    //������ǿո�ֱ�ӽ�i���ƶ���j����������ǰ�ƶ�һλ
        }
    }
    str[len] = '\0';    //�ַ���ĩβ��־

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















