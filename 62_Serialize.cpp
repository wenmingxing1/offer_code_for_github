#include<iostream>
#include<vector>

using namespace std;

struct treeNode {
    int val = 0;
    treeNode* left = nullptr;
    treeNode* right = nullptr;

    treeNode() = default;
    treeNode(int x):val(x), left(nullptr), right(nullptr) {}
};

void Serialize(treeNode* root, ostream& stream) {
    if (root == nullptr) {
        stream << '#,';
        return;
    }
    stream << root->val << ',';
    Serialize(root->left, stream);
    Serialize(root->right, stream);
}

void Deserialize(treeNode** root, istream& stream) {
    int number;
    if (ReadStream(stream, &number)) {
        (*root)->val = number;
        (*root)->left = nullptr;
        (*root)->right = nullptr;

        Deserialize(&((*root)->left)), stream);
        Deserialize(&((*root)->right)), stream);
    }

}


int main()
{
    treeNode node[4];
    node[0].val = 0;
    node[1].val = 1;
    node[2].val = 2;
    node[3].val = 3;
    node[0].left = &node[1];
    node[0].right = &node[2];
    node[1].right = &node[3];

    Serialize(node, cout);

    return 0;
}
