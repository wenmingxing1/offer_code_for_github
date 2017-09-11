#include<iostream>
#include<vector>

using namespace std;


struct BinaryTreeNode
{
    int val;
    BinaryTreeNode* left;
    BinaryTreeNode* right;

    BinaryTreeNode(int x) : val(x), left(NULL), right(NULL) {}

    //���ǰ��������
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

    //�������������������static
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

    //�������������
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
        //ǰ������ĳ��Ⱥ����������ͬ
        if (pre.size() != in.size())
        {
            return NULL;
        }

        //���Ȳ���Ϊ0
        int length = pre.size();
        if (length == 0)
        {
            return NULL;
        }

        //int length = pre.size();

        int value = pre[0];     //ǰ������ĵ�һ������Ǹ����

        BinaryTreeNode *root = new BinaryTreeNode(value);

        //�ҵ���������еĸ����
        int rootIndex = 0;
        for (int i = 0; i < length; ++i)
        {
            if (in[i] == value)
            {
                rootIndex = i;
                break;
            }
        }

        //������������������
        //��������У�����ߵľ������������ұߵľ���������
        //ǰ������У�����������ȱ�����������Ȼ�����������

        //����ȷ�����������ĳ��ȣ����������in��ȷ��

        vector<int> preLeft, inLeft, preRight, inRight;

        for (int i = 0; i < rootIndex; ++i)
        {
            //ǰ������ĵ�һ������Ǹ���㣬������i+1
            preLeft.push_back(pre[i+1]);
            //���������ǰi����㼴ʹ���������������
            inLeft.push_back(in[i]);
        }
        for (int i = rootIndex + 1; i < length; ++i)
        {
            //ǰ�������������
            preRight.push_back(pre[i]);
            //���������������
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












