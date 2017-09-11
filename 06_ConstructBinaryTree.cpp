#include<iostream>
#include<vector>

using namespace std;


struct BinaryTreeNode
{
    int val;
    BinaryTreeNode* left;
    BinaryTreeNode* right;

    BinaryTreeNode(int x) : val(x), left(NULL), right(NULL) {}

    //输出前序遍历结果
    static void PreOrder(BinaryTreeNode* root)
    {
        if (root == NULL)
        {
            return;
        }
        cout << root->val << " ";
        PreOrder(root->left);
        PreOrder(root->right);
    }

    //输出中序遍历结果，采用static
    static void InOrder(BinaryTreeNode* root)
    {
        if (root == NULL)
        {
            return;
        }
        InOrder(root->left);
        cout << root->val << " ";
        InOrder(root->right);
    }

    //输出后序遍历结果
    static void LatOrder(BinaryTreeNode* root)
    {
        if (root == NULL)
        {
            return;
        }
        LatOrder(root->left);
        LatOrder(root->right);
        cout << root->val << " ";
    }
};

class Solution
{
public:
    BinaryTreeNode* reConstructBinaryTree(vector<int> pre, vector<int> in)
    {
        //前序遍历的长度和中序遍历相同
        if (pre.size() != in.size())
        {
            return NULL;
        }

        //长度不能为0
        int length = pre.size();
        if (length == 0)
        {
            return NULL;
        }

        //int length = pre.size();

        int value = pre[0];     //前序遍历的第一个结点是根结点

        BinaryTreeNode *root = new BinaryTreeNode(value);

        //找到中序遍历中的根结点
        int rootIndex = 0;
        for (int i = 0; i < length; ++i)
        {
            if (in[i] == value)
            {
                rootIndex = i;
                break;
            }
        }

        //区分左子树和右子树
        //中序遍历中，根左边的就是左子树，右边的就是右子树
        //前序遍历中，根后面的是先遍历左子树，然后遍历右子树

        //首先确定左右子数的长度，从中序遍历in中确定

        vector<int> preLeft, inLeft, preRight, inRight;

        for (int i = 0; i < rootIndex; ++i)
        {
            //前序遍历的第一个结点是根结点，所以是i+1
            preLeft.push_back(pre[i+1]);
            //中序遍历的前i个结点即使中序遍历的左子树
            inLeft.push_back(in[i]);
        }
        for (int i = rootIndex + 1; i < length; ++i)
        {
            //前序遍历的右子树
            preRight.push_back(pre[i]);
            //中序遍历的右子树
            inRight.push_back(in[i]);
        }


        root->left = reConstructBinaryTree(preLeft, inLeft);
        root->right = reConstructBinaryTree(preRight, inRight);

        return root;
    }
};

int main()
{
    int pre[] = {1,2,4,7,3,5,6,8};
    int in[] = {4,7,2,1,5,3,8,6};

    vector<int> preOrder(pre, pre+8);
    vector<int> inOrder(in, in+8);

    Solution solu;
    BinaryTreeNode *root = solu.reConstructBinaryTree(preOrder, inOrder);

    cout << root->val << endl;

    BinaryTreeNode::PreOrder(root);
    cout << endl;
    BinaryTreeNode::InOrder(root);
    cout << endl;
    BinaryTreeNode::LatOrder(root);

    return 0;
}












