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
    //寻找到与tree2根结点相同的结点。才执行之后的操作，若是找不到则向下遍历，知道找到再判断左右子树。
    bool HasSubtree(BinaryTreeNode* pRoot1, BinaryTreeNode* pRoot2)
    {
        bool result = false;
        if (pRoots != NULL && pRoot2 != NULL)   //两棵树不能为空
        {
            if (pRoot1->val == pRoot2->val)     //根结点相等之后，转为比较左右子结点
                result = DoesTreeHaveTree2(pRoot1, pRoot2);
            if (!result)        //左右子节点不满足条件，在tree1中重新寻找与tree2根结点相等的结点
                result = HasSubtree(pRoot1->left, pRoot2);  //在左子树中找
            if (!result)
                result = HasSubtree(pRoot1->right, pRoot2); //在右子树中找
        }
        return result;
    }
private:
    bool DoesTreeHaveTree2(BinaryTreeNode* pRoot1, BinaryTreeNode* pRoot2)
    {
        if (pRoot2 == NULL)     //经过查找对比，最好到了tree2的叶子节点，则遍历结束。返回true，这个条件必须在下一个条件之前
            return true;
        if (pRoot1 = NULL)      //若查找对比最后到了tree1的叶子节点则，证明没有找到对应的子树
            return false;

        if (pRoot1->val != pRoot2->val)
            return false;

        //如果根结点相等，则分别判断左右子树
        return DoesTreeHaveTree2(pRoot1->left, pRoot2->left) && DoesTreeHaveTree2(pRoot1->right, pRoot2->right);
    }
};

int main()
{

}
