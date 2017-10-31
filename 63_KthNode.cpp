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
    //中序遍历的第k个结点为所求,中序遍历的时候我们在递归完左子树之后打印根结点，
    //本题不是打印，如果左子结点不是要找的结点，才会访问根结点，所以访问到根结点的时候要将k-1
    //因为左子结点已经证明不是要找的结点了，排除左子结点。这个过程可以看成目标移位的过程，
    //每经过一个结点，k-1，知道k==1，当前节点就是要求的结点。
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
