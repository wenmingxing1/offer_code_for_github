#include<iostream>
#include<stdlib.h>  //atoiͷ�ļ�
#include<sstream>
#include<string>

using namespace std;

//���ñ�׼�⺯��atoi������һ��C�����ַ�����
int StrToInt1(const string &s)
{
    int a = atoi(s.c_str());
    return a;
}

//����sstreamͷ�ļ��ж�����ַ�����������ʵ��ת��
int StrToInt2(string &s)
{
    istringstream is(s);    //���������ַ�����
    int a;
    is >> a;
    return a;
}

/*
//���ñ�׼�⺯��to_stringʵ��,������������ܲ�����
string IntToStr1(int &i)
{
    string s = std::to_string(i);
}
*/

//�����ַ���������ʵ��
string IntToStr2(int &i)
{
    ostringstream os;   //����һ������ַ�����
    os << i;    //������д��
    return os.str();    //str������ȡ������
}

int main()
{
    string s = "123";
    cout << StrToInt1(s) + 5 << endl;
    cout << StrToInt2(s) + 5 << endl;

    int j = 12345;
    //cout << IntToStr1(j) + "haha" << endl;
    cout << IntToStr2(j) + "haha" << endl;

    return 0;
}
