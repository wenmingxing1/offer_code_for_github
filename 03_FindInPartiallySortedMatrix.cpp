//二维数组查找
//题目：在一个二维数组中，每一行都按照从左到右递增的顺序排序，每一列都按照从上到下的顺序排序。
//完成一个函数，输入这样的一个二维数组和一个整数，判断数组中是否含有该整数。

#include<iostream>
#include<vector>

using namespace std;

//=======================题目答案函数=====================
bool Find(int *matrix, int m, int n, int key)
{
    bool result = false;
    if (matrix != NULL && m > 0 && n > 0)
    {
        int row = 0;    //初始化所在行为第一行
        int column = n - 1;     //初始化所在列为最后一列，从而锁定右上角

        while (row < m && column > 0)
        {
            if (matrix[row * n + column] == key)    //matrix为右上角位置
            {
                result = true;
                break;
            }
            else if (matrix[row * n + column] > key)
                --column;       //所在列递减表明向左移动
            else
                ++row;  //所在行递增，表明逐渐向下移动
        }
    }
    return result;
}


//=====================测试样例=====================

void Test1()
{
    int m, n, key;
    int *matrix;

    cin >> m >> n >> key;
    //cout << endl;
    for (int i = 0; i < m * n; ++i)
    {
        cin >> matrix[i];
    }

    if (Find(matrix, m, n, key))
        cout << "true" << endl;
    else
        cout << "false" << endl;
}

int main()
{
    Test1();

    return 0;
}





















