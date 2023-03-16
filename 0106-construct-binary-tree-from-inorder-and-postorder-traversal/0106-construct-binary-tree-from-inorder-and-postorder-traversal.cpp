/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
// class Solution {
// public:
//     TreeNode* helper(vector<int>& inorder,int inS,int inE ,vector<int>& postorder,int pS,int pE,unordered_map<int,int> mapp){
//         if(inS>inE) return NULL;
//         int rootData=postorder[pE];
//         int rootIndex=mapp[rootData];
//         int linS=inS;
//         int linE=rootIndex-1;
//         int rinS=rootIndex+1;
//         int rinE=inE;
//         int lpS=pS;
//         int lpE=pS+(linE-linS);
//         int rpS=lpE+1;
//         int rpE=pE-1;
//         TreeNode* root=new TreeNode(rootData);
//         root->left=helper(inorder,linS,linE,postorder,lpS,lpE,mapp);
//         root->right=helper(inorder,rinS,rinE,postorder,rpS,rpE,mapp);
//         return root;
        
//     }
//     TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
//         TreeNode* root= new TreeNode(postorder[postorder.size()-1]);
//         unordered_map<int,int> mapp;
//         for(int i =0;i<inorder.size();i++){
//             mapp[inorder[i]]=i;
//         }
//         int inS=0 ;
//         int inE=inorder.size()-1;
//         int pS=0;
//         int pE=postorder.size()-1;
//         return helper(inorder,inS,inE,postorder,pS,pE,mapp);
//     }
// };

class Solution {
public:
     TreeNode* helper(vector<int>& postorder,int pos,int poe,vector<int>& inorder,int ins,int ine)
    {
        if(ins>ine )
            return NULL;
        int rootdata=postorder[poe];
        int rootindex=-1;
        for(int i=ins;i<=ine;i++)
        {
            if(inorder[i]==rootdata)
            {
                rootindex=i;
                break;
            }
        }
        int lins=ins;
        int line=rootindex-1;
        int lpos=pos;
        int lpoe=pos+line-lins;        
        int rpos=lpoe+1;
        int rpoe=poe-1;
        int rins=rootindex+1;
        int rine=ine;
        TreeNode*root=new TreeNode(rootdata);
        root->left=helper(postorder,lpos,lpoe,inorder,lins,line);
        root->right=helper(postorder,rpos,rpoe,inorder,rins,rine);
        return root;
    }
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
         return helper(postorder,0,postorder.size()-1,inorder,0,inorder.size()-1);
        
    }
};