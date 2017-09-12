#include<iostream>
#include<stack>

using namespace std;

class Solution
{
public:
    void push(int node)
    {
        stackIn.push(node);
    }

    int pop()
    {
        if (stackOut.empty())
        {
            while (!stackIn.empty())
            {
                stackOut.push(stackIn.top());
                stackIn.pop();
            }
        }

        int head = stackOut.top();
        stackOut.pop();

        return head;
    }

    bool empty()
    {
        return stackIn.empty() && stackOut.empty();
    }

private:
    stack<int> stackIn;
    stack<int> stackOut;
};

int main()
{
    Solution solu;
    solu.push(1);
    solu.push(2);
    solu.push(3);
    solu.push(4);
    solu.push(5);

    while (!solu.empty())
    {
        cout << solu.pop() << " ";
    }
}
