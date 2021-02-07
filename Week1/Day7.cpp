#include<iostream>
#include<stack>
#include<string>
#include<algorithm>
#include<vector>
#include<climits>
using namespace std;

vector<int> shortestToChar(string s, char c) {
    vector<int> arr(s.length(), INT_MAX);
    stack<int>stk;
  
    int i=0;
    for(;i<s.length();i++){
       
        if(stk.size()==0){
            stk.push(i);
            if(s[i]==c){
                arr[i]=0;
            }
            continue;
        }
        if(s[i]==c){
            arr[i]=0;
            while( stk.size()!=0 && s[stk.top()]!=c){
                int idx= stk.top();
                stk.pop();
                
                arr[idx]= min(arr[idx], i-idx);
            }
        }
        else{
            
            if(s[stk.top()]==c){
                arr[i]=1;
            }
            else if(arr[stk.top()]!=INT_MAX){
                arr[i]= arr[stk.top()]+1;
            }
        }
        stk.push(i);
    }
    return arr;
}

int main(){
    string s;
    char c;
    cin>>s>>c;
    vector<int> arr = shortestToChar(s, c);
    for(int i:arr){
        cout<<i<<"  ";
    }
}