#include<iostream>
#include<queue>
#include<vector>
using namespace std;

struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode() : val(0), left(nullptr), right(nullptr) {}
     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 };
 
 vector<int> rightSideView(TreeNode* root) {
        vector<int>result;
        if(root==NULL){
            return result;
        }
        queue<TreeNode*>que;
        que.push(root);
        int size= que.size();
        while(que.size()!=0){
            while(size!=1){
                TreeNode* rn=que.front();
                que.pop();
                if(rn->left!= NULL){
                    que.push(rn->left);
                }
                if(rn->right!=NULL){
                    que.push(rn->right);
                }
                size--;
            }
            if(size==1){
                result.push_back(que.front()->val);
                TreeNode* rn=que.front();
                que.pop();
                if(rn->left!= NULL){
                    que.push(rn->left);
                }
                if(rn->right!=NULL){
                    que.push(rn->right);
                }
                size=que.size();
            }
        }
        return result;
    }
