//ԭʼ����
#include<iostream>

using namespace std;

void QuickSort(int s[], int l, int r)
{
    if (l < r)
    {
        int i = l, j = r;
        int val = s[l];
        while (i < j)
        {
            while (i < j && s[j] >= val)    //���������ҵ�һ����valС����
                j--;
            if (i < j)
                s[i++] = s[j];  //�ҵ�֮��ֵ��i����

            while (i < j && s[i] <= val)    //�������ҵ�һ����val�����
                i++;
            if (i < j)
                s[j--] = s[i];  //�ҵ�֮��ֵ���ղſճ�����j����
        }

        s[i] = val;     //���ճ�����i����ֵ��val
        QuickSort(s, l, i - 1);     //�ݹ����val������
        QuickSort(s, i + 1, r);
    }
}

int main()
{
    int a[] = {3,5,2,4,9};
    for (int i = 0; i < 5; ++i)
    {
        cout << a[i];
    }

    cout << endl << sizeof(a)/sizeof(int) << endl;
    QuickSort(a, 0, 5);

    for (int i = 0; i < 5; ++i)
    {
        cout << a[i];
    }

    return 0;
}
