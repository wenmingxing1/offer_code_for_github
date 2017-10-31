/*
struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
    TreeNode(int x) :
            val(x), left(NULL), right(NULL) {
    }
};
*/
class Solution {
public:
    TreeNode* KthNode(TreeNode* pRoot, int k)
    {
        if (pRoot == NULL || k == 0)
            return NULL;
        else
            return KthNodeCore(pRoot, k);
    }
private:
    //��������ĵ�k�����Ϊ����,���������ʱ�������ڵݹ���������֮���ӡ����㣬
    //���ⲻ�Ǵ�ӡ��������ӽ�㲻��Ҫ�ҵĽ�㣬�Ż���ʸ���㣬���Է��ʵ�������ʱ��Ҫ��k-1
    //��Ϊ���ӽ���Ѿ�֤������Ҫ�ҵĽ���ˣ��ų����ӽ�㡣������̿��Կ���Ŀ����λ�Ĺ��̣�
    //ÿ����һ����㣬k-1��֪��k==1����ǰ�ڵ����Ҫ��Ľ�㡣
    TreeNode* KthNodeCore(TreeNode* pRoot, int& k){
        TreeNode* target = NULL;
        if (pRoot->left) target = KthNodeCore(pRoot->left, k);
        if (target == NULL){
            if (k == 1)
                target = pRoot;
            k--;
        }
        if (target == NULL && pRoot->right)
            target = KthNodeCore(pRoot->right, k);

        return target;
    }

};
