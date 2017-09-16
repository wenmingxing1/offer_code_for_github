#include<iostream>

using namespace std;

//ͨ����n����������1�����жϣ��������������з������еĸ�����������ѭ��
int NumberOf1_Solution1(int n)
{
    int count = 0;
    while (n)
    {
        if (n & 1)
            count ++;
        n = n >> 1;
    }
    return count;
}

//ͨ����1��������1->10->100... ��n��������������Ǹ�ѭ���Ĵ�������whileѭ�����������ڶ����Ƶ�λ������32.
int NumberOf1_Solution2(int n)
{
    int count = 0;
    unsigned int i = 1;
    while (i)
    {
        if (n & i)
            count ++;
        i = i << 1;
    }
    return count;
}

//�������м���1��ֻ��Ҫѭ������
int NumberOf1_Solution3(int n)
{
    int count = 0;
    while (n)
    {
        count++;
        n = n & (n - 1);
    }
    return count;
}

int main()
{
    cout << NumberOf1_Solution1(9) << endl;
    //cout << NumberOf1_Solution1(-9) << endl;    //��ѭ��

    cout << NumberOf1_Solution2(9) << endl;
    cout << NumberOf1_Solution2(-9) << endl;

    cout << NumberOf1_Solution3(9) << endl;
    cout << NumberOf1_Solution3(-9) << endl;

    return 0;
}
