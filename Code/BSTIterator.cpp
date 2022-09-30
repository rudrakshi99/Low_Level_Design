
#include <bits/stdc++.h>
using namespace std;

class TreeNode {
public:
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class BSTIterator {
public:
    stack<TreeNode*> st;
    BSTIterator(TreeNode *root) {
        Lefttree(root);
    }

    bool hasNext() {
        return st.empty() ? false : true;
    }

    int next() {
        TreeNode* top = st.top();
        st.pop();
        if (top->right != NULL)
            Lefttree(top->right);
        return top->val;
    }

    void Lefttree(TreeNode* root)
    {
        TreeNode* p = root;
        while (p)
        {
            st.push(p);
            p = p->left;
        }
    }
};

int main() {

    TreeNode* root = NULL;
    BSTIterator* obj = new BSTIterator(root);
    int param_1 = obj->next();
    bool param_2 = obj->hasNext();

    return 0;
}

/*

BSTIterator bSTIterator = new BSTIterator([7, 3, 15, null, null, 9, 20]);
bSTIterator.next();    // return 3
bSTIterator.next();    // return 7
bSTIterator.hasNext(); // return True
bSTIterator.next();    // return 9
bSTIterator.hasNext(); // return True
bSTIterator.next();    // return 15
bSTIterator.hasNext(); // return True
bSTIterator.next();    // return 20
bSTIterator.hasNext(); // return False

*/