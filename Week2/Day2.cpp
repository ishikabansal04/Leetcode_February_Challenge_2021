#include<iostream>
#include<queue>
#include<vector>
#include<unordered_map>
using namespace std;

 struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode() : val(0), left(nullptr), right(nullptr) {}
     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 };

TreeNode* convertBST(TreeNode* root) {
        if(root==NULL){
            return root;
        }
        priority_queue<int>pq;
        unordered_map<int, int>newval;
        queue<TreeNode*>que;
        int sum=0;
        que.push(root);
        while(que.size()!=0){
            TreeNode* front= que.front();
            que.pop();
            pq.push(front->val);
            if(front->left!=NULL){
                que.push(front->left);
            }
            if(front->right!=NULL){
                que.push(front->right);
            }
        }
        while(pq.size()!=0){
            int fr= pq.top();
            pq.pop();
            sum+=fr;
            newval[fr]=sum;
        }
        que.push(root);
        while(que.size()!=0){
            TreeNode* front= que.front();
            que.pop();
            if(front->left!=NULL){
                que.push(front->left);
            }
            if(front->right!=NULL){
                que.push(front->right);
            }
            front->val=newval[front->val];
        }
        return root;
    }