#include<iostream>
#include<vector>
#include<unordered_map>
#include<queue>
#include<string>
using namespace std;

void helper(string ques, string ans, int idx, vector<string>&result){
        if(idx==ques.length()){
            result.push_back(ans);
            return;
        }
        string temp=ans;
        if(ques[idx]>=97 && ques[idx]<=122){
            char ch = ques[idx];
            ans+= ch-32;
            helper(ques, ans, idx+1, result);
        }
        else if(ques[idx]>=65 && ques[idx]<=92){
            char ch = ques[idx];     
            ans+= ch+32;
            helper(ques, ans, idx+1, result);
        }
        
        temp+=ques[idx];
        helper(ques, temp, idx+1, result);
          
    }
    
    vector<string> letterCasePermutation(string S) {
        vector<string>result;
        helper(S, "", 0, result);
        return result;
    }