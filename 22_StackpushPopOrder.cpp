#include<iostream>
#include<vector>
#include<stack>
using namespace std;

class Solution {
public:
    bool IsPopOrder(vector<int> pushV,vector<int> popV) {
        bool result = false;
        int pushV_size = pushV.size();
        int popV_size = popV.size();
        if (!pushV.empty() && pushV_size == popV_size){
            int pPush = 0, pPop = 0;
            std::stack<int> stackData;
            while (pPop < popV_size){
                while (stackData.empty() || stackData.top() != popV[pPop]){ //在pushV中寻找popV中的数,需要判断栈的起始状态为空的情况
                    if (pPush == pushV_size)    //都没有找到
                        break;
                    stackData.push(pushV[pPush]);   //将找到之前的数压入临时栈
                    pPush++;
                }

                if (stackData.top() != popV[pPop])
                    break;

                stackData.pop();    //找到之后弹出
                pPop++;
            }

            if (stackData.empty() && pPop == popV_size)     //最终判断条件，如果临时栈中为空，并且popV中所有元素都经过了比较
                result = true;
        }
        return result;
    }
};

int main()
{
    vector<int> push = {1,2,3,4,5};
    vector<int> pop = {4,3,5,2,1};

    Solution solu;
    bool result = solu.IsPopOrder(push, pop);

    cout << result << endl;

    return 0;
}
