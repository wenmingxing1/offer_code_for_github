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
                while (stackData.empty() || stackData.top() != popV[pPop]){ //��pushV��Ѱ��popV�е���,��Ҫ�ж�ջ����ʼ״̬Ϊ�յ����
                    if (pPush == pushV_size)    //��û���ҵ�
                        break;
                    stackData.push(pushV[pPush]);   //���ҵ�֮ǰ����ѹ����ʱջ
                    pPush++;
                }

                if (stackData.top() != popV[pPop])
                    break;

                stackData.pop();    //�ҵ�֮�󵯳�
                pPop++;
            }

            if (stackData.empty() && pPop == popV_size)     //�����ж������������ʱջ��Ϊ�գ�����popV������Ԫ�ض������˱Ƚ�
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
