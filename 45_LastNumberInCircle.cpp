#include<iostream>
#include<list>

using namespace std;

/*===========常规做法:循环链表==============*/
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
            for (int i = 1; i < m; ++i){	//找到要删除的元素
                current++;
                if (current == numbers.end())	//尾后迭代器不是数组中最后一个元素，而是最后一个元素后面的一个地址
                    current = numbers.begin();
            }

            list<int>::iterator next = ++current;	//list的vector不支持+
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
