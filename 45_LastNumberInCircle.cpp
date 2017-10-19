#include<iostream>
#include<list>

using namespace std;

/*===========��������:ѭ������==============*/
class Solution {
public:
    int LastRemaining_Solution(int n, int m)
    {
        if (n < 1 || m < 1)
            return -1;
        list<int> numbers;
        for (int i = 0; i < n; ++i){
            numbers.push_back(i);
        }

        list<int>::iterator current = numbers.begin();
        while (numbers.size() > 1){
            for (int i = 1; i < m; ++i){	//�ҵ�Ҫɾ����Ԫ��
                current++;
                if (current == numbers.end())	//β��������������������һ��Ԫ�أ��������һ��Ԫ�غ����һ����ַ
                    current = numbers.begin();
            }

            list<int>::iterator next = ++current;	//list��vector��֧��+
            if (next == numbers.end())
                next = numbers.begin();
            --current;
            numbers.erase(current);
            current = next;
        }
        return *current;
    }
};

int main()
{
    Solution solu;
    cout << solu.LastRemaining_Solution(5,3) << endl;

    return 0;
}
