#include<iostream>
#include<time.h>
#include<stdlib.h>

using namespace std;

int RandomInRange(int start ,int end)
{
    if(end>start)
    {
      //srand(time(NULL));//��srand������������������ĳ�ʼ������,ʹ�������������ʱ��ı仯���仯
      return start+rand() % (end-start);//����start~end֮��������
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

//==============���麯��������������������������ұߣ�С�����������===============*/
int Partition(int data[], int length, int start, int end)
{
    if (data == NULL || length <= 0 || start < 0 || end >= length)
    {
        cout << "Invalid Parameters!" << endl;
    }

    int index = RandomInRange(start, end);  //ѡȡ�����������

    //��������
    Swap(&data[index], &data[end]);     //����׼��ŵ�end��

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

/*================================���õݹ鲻�Ϸ���ﵽ�����Ŀ��=======================================*/
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

