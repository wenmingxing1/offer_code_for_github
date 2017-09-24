#include<iostream>
using namespace std;

struct BinaryTreeNode
{
    int val;
    BinaryTreeNode* left;
    BinaryTreeNode* right;
};

class Solution
{
public:
    //Ѱ�ҵ���tree2�������ͬ�Ľ�㡣��ִ��֮��Ĳ����������Ҳ��������±�����֪���ҵ����ж�����������
    bool HasSubtree(BinaryTreeNode* pRoot1, BinaryTreeNode* pRoot2)
    {
        bool result = false;
        if (pRoots != NULL && pRoot2 != NULL)   //����������Ϊ��
        {
            if (pRoot1->val == pRoot2->val)     //��������֮��תΪ�Ƚ������ӽ��
                result = DoesTreeHaveTree2(pRoot1, pRoot2);
            if (!result)        //�����ӽڵ㲻������������tree1������Ѱ����tree2�������ȵĽ��
                result = HasSubtree(pRoot1->left, pRoot2);  //������������
            if (!result)
                result = HasSubtree(pRoot1->right, pRoot2); //������������
        }
        return result;
    }
private:
    bool DoesTreeHaveTree2(BinaryTreeNode* pRoot1, BinaryTreeNode* pRoot2)
    {
        if (pRoot2 == NULL)     //�������ҶԱȣ���õ���tree2��Ҷ�ӽڵ㣬���������������true�����������������һ������֮ǰ
            return true;
        if (pRoot1 = NULL)      //�����ҶԱ������tree1��Ҷ�ӽڵ���֤��û���ҵ���Ӧ������
            return false;

        if (pRoot1->val != pRoot2->val)
            return false;

        //����������ȣ���ֱ��ж���������
        return DoesTreeHaveTree2(pRoot1->left, pRoot2->left) && DoesTreeHaveTree2(pRoot1->right, pRoot2->right);
    }
};

int main()
{

}
