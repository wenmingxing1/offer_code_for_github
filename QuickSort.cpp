#include<iostream>
#include<time.h>
#include<stdlib.h>

using namespace std;

int RandomInRange(int start ,int end)
{
    if(end>start)
    {
      //srand(time(NULL));//　srand函数是随机数发生器的初始化函数,使得随机数种子随时间的变化而变化
      return start+rand() % (end-start);//产生start~end之间的随机数
    }
    return 0;
}

void Swap(int *i, int *j)
{
    int temp;
    temp = *i;
    *i = *j;
    *j = temp;
}

//==============分组函数，将比数组中数大的数放在右边，小的数放在左边===============*/
int Partition(int data[], int length, int start, int end)
{
    if (data == NULL || length <= 0 || start < 0 || end >= length)
    {
        cout << "Invalid Parameters!" << endl;
    }

    int index = RandomInRange(start, end);  //选取其中随机的数

    //交换函数
    Swap(&data[index], &data[end]);     //将基准点放到end处

    int small = start - 1;
    for (index = start; index < end; ++index)
    {
        if (data[index] < data[end])
        {
            ++small;
            if (small != index)
                Swap(&data[index], &data[small]);
        }
    }

    ++small;
    Swap(&data[small], &data[end]);

    return small;
}

/*================================利用递归不断分组达到排序的目的=======================================*/
void QuickSort(int data[], int length, int start, int end)
{
    if (start == end)
        return;

    int index = Partition(data, length, start, end);
    if (index > start)
        QuickSort(data, length, start, index-1);
    if (index < end)
        QuickSort(data, length, index+1, end);
}

int main()
{
    int a[] = {3,2,5,5,3,2,5,7,9,10,4};
    QuickSort(a, 11, 0, 10);

    for (int i = 0; i < 11; ++i)
    {
        cout << a[i] << " ";
    }

    return 0;
}

