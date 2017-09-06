//��ά�������
//��Ŀ����һ����ά�����У�ÿһ�ж����մ����ҵ�����˳������ÿһ�ж����մ��ϵ��µ�˳������
//���һ������������������һ����ά�����һ���������ж��������Ƿ��и�������

#include<iostream>
#include<vector>

using namespace std;

//=======================��Ŀ�𰸺���=====================
bool Find(int *matrix, int m, int n, int key)
{
    bool result = false;
    if (matrix != NULL && m > 0 && n > 0)
    {
        int row = 0;    //��ʼ��������Ϊ��һ��
        int column = n - 1;     //��ʼ��������Ϊ���һ�У��Ӷ��������Ͻ�

        while (row < m && column > 0)
        {
            if (matrix[row * n + column] == key)    //matrixΪ���Ͻ�λ��
            {
                result = true;
                break;
            }
            else if (matrix[row * n + column] > key)
                --column;       //�����еݼ����������ƶ�
            else
                ++row;  //�����е����������������ƶ�
        }
    }
    return result;
}


//=====================��������=====================

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





















