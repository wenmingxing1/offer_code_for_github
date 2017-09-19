#include<iostream>
#include<cstring>

using namespace std;

//�ж��Ƿ񵽴���n��9999
bool Increment(char* number)
{
    bool isOverflow = false;    //û�е���
    int nTakeOver = 0;      //��λ
    int nLength = strlen(number);   //n

    for (int i = nLength - 1; i >= 0; --i)
    {
        int nSum = number[i] - '0' + nTakeOver;
        if (i == nLength - 1)
            nSum++;

        if (nSum >= 10)     //�������10������Ҫ������λ
        {
            if (i == 0)     //��i==0ʱ��֤�������nλ
                isOverflow = true;      //��i==0���������λ��ʱ�򣬲���nSum=10����֤��������n��999�ﵽ��1000���ı��־λ����ӡ
            else
            {
                nSum -= 10;
                nTakeOver = 1;  //��λΪ1��Ȼ��ֵ����һ���ж��е�nSum�У���15�У�
                number[i] = '0' + nSum;     //���ַ���ʽ��ֵ��number[i]
            }
        }
        else    //���������10�����ò�����λ����ֱ�Ӵ�ӡ
        {
            number[i] = '0' + nSum;     //��nSum���ַ���ʽ��ֵ��number[i]
            break;
        }
    }
    return isOverflow;
}

void PrintNumber(char* number)
{
    bool isBeginning0 = true;
    int nLength = strlen(number);

    for (int i = 0; i < nLength; ++i)
    {
        if (isBeginning0 && number[i] != '0')
            isBeginning0 = false;
        if (!isBeginning0)
        {
            cout << number[i];
        }
    }
    cout << " ";
}

/*================һ�㷽ʽ====================*/
void Print1ToMaxOfNDigits_Normal(int n)
{
    if (n <= 0)
        return;
    char *number = new char[n+1];
    memset(number, '0', n);     //ǰn��λ�ó�ʼ��Ϊ'0'
    number[n] = '\0';

    while (!Increment(number))
    {
        PrintNumber(number);
    }

    delete []number;
}

/*=================�ݹ鷽ʽ=======================*/
void Print1ToMaxOfNDigitsRecursively(char* number, int length, int index)
{
    if (index == length - 1)    //��index����length-1��ʱ��֤���������ˣ��ſ�ʼ��ӡ
    {
        PrintNumber(number);
        return;
    }
    for (int i = 0; i < 10; ++i)
    {
        number[index + 1] = i + '0';
        Print1ToMaxOfNDigitsRecursively(number, length, index + 1);     //ÿ�εݹ��������index����һλ��
    }
}

void Print1ToMaxOfNDigits(int n)
{
    if (n <= 0)
        return;

    char *number = new char[n + 1];
    number[n] = '\0';

    for (int i = 0; i < 10; ++i)
    {
        number[0] = i + '0';
        Print1ToMaxOfNDigitsRecursively(number, n, 0);
    }
    delete []number;
}

int main()
{
    Print1ToMaxOfNDigits_Normal(2);

    cout << endl;

    Print1ToMaxOfNDigits(2);

    cout << endl;

    return 0;
}
