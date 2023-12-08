class Solution {
public:
    string ans;
    void preOrder(TreeNode* node){
        if (!node) return ;
        ans+=to_string(node->val);
        if (node->left){
          ans.push_back('(');
          preOrder(node->left);
          ans.push_back(')');
        }
        if (node->right){
          if (!node->left) ans+="()";
          ans.push_back('(');
          preOrder(node->right);
          ans.push_back(')');
        }
    }
    string tree2str(TreeNode* root) {
        preOrder(root);
        return ans;
    }
};
// class Solution {
// public:
//     string tree2str(TreeNode* root) {
//         if(root == NULL)
//             return "";
        
//         if(root->left != NULL or root->right != NULL)
//         {
//             cout<<")";
//             cout << root->val;
//             cout<<"(";
            
//         }
//         if(root->left == NULL and root->right == NULL)
//         {
//             cout<<"(";
//             cout << root->val;
//             cout<<")";
//         }
//         tree2str(root->left);
//         tree2str(root->right);
//         return "";
//     }
// };