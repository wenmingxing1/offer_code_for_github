#include<iostream>

using namespace std;

//遍历数组，得到最小值
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
    int MidIndex = index1;  //当不满足while循环条件时，证明数组本身有序，直接返回第一个元素，即是最小元素

    if (numbers == NULL || length <= 0)
        return -1;

    while (numbers[index1] >= numbers[index2])    //一般情况下旋转数组的特性
    {
        if (index1 == index2 - 1)    //循环中止条件
        {
            MidIndex = index2;
            break;
        }

        MidIndex = (index1 + index2)/2;

        //如果三个指针位置数值大小相等，则无法确定中间位置属于递增部分还是递减部分，只能采用遍历方式
        if (numbers[index1] == numbers[MidIndex] && numbers[index1] == numbers[index2])
            return MinInOrder(numbers, index1, index2);


        if (numbers[MidIndex] >= numbers[index1])
            index1 = MidIndex;
        else if (numbers[MidIndex] <= numbers[index2])
            index2 = MidIndex;
    }

    return numbers[MidIndex];
}

void test1()    //一般测试样例
{
    int numbers[] = {3,4,5,1,2};
    cout << Min(numbers, 5) << endl;
}

void test2()    //测试样例2，测试全部相等的数
{
    int numbers[] = {1,1,1,1,1};
    cout << Min(numbers, 5) << endl;
}

void test3()    //测试样例3，测试index1， index2， MidIndex 相等
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
