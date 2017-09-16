//原始快排
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
            while (i < j && s[j] >= val)    //从右向左找第一个比val小的数
                j--;
            if (i < j)
                s[i++] = s[j];  //找到之后赋值到i处；

            while (i < j && s[i] <= val)    //从左到右找第一个比val大的数
                i++;
            if (i < j)
                s[j--] = s[i];  //找到之后赋值给刚才空出来的j处；
        }

        s[i] = val;     //将空出来的i处赋值给val
        QuickSort(s, l, i - 1);     //递归调用val的左右
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
