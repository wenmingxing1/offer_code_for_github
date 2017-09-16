#include<iostream>

using namespace std;

//�������飬�õ���Сֵ
int MinInOrder(int *numbers, int index1, int index2)
{
    int result = numbers[index1];
    for (int i = index1 + 1; i <= index2; ++i)
    {
        if (numbers[i] < result)
            result = numbers[i];
    }

    return result;
}

int Min(int *numbers, int length)
{
    int index1 = 0;
    int index2 = length - 1;
    int MidIndex = index1;  //��������whileѭ������ʱ��֤�����鱾������ֱ�ӷ��ص�һ��Ԫ�أ�������СԪ��

    if (numbers == NULL || length <= 0)
        return -1;

    while (numbers[index1] >= numbers[index2])    //һ���������ת���������
    {
        if (index1 == index2 - 1)    //ѭ����ֹ����
        {
            MidIndex = index2;
            break;
        }

        MidIndex = (index1 + index2)/2;

        //�������ָ��λ����ֵ��С��ȣ����޷�ȷ���м�λ�����ڵ������ֻ��ǵݼ����֣�ֻ�ܲ��ñ�����ʽ
        if (numbers[index1] == numbers[MidIndex] && numbers[index1] == numbers[index2])
            return MinInOrder(numbers, index1, index2);


        if (numbers[MidIndex] >= numbers[index1])
            index1 = MidIndex;
        else if (numbers[MidIndex] <= numbers[index2])
            index2 = MidIndex;
    }

    return numbers[MidIndex];
}

void test1()    //һ���������
{
    int numbers[] = {3,4,5,1,2};
    cout << Min(numbers, 5) << endl;
}

void test2()    //��������2������ȫ����ȵ���
{
    int numbers[] = {1,1,1,1,1};
    cout << Min(numbers, 5) << endl;
}

void test3()    //��������3������index1�� index2�� MidIndex ���
{
    int numbers[] = {1,0,1,1,1};
    cout << Min(numbers, 5) << endl;
}

void test4()
{
    int numbers[] = {1,2,3,4,5};
    cout << Min(numbers, 5);
}

int main()
{
    test1();
    test2();
    test3();
    test4();

    return 0;
}
