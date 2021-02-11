#include<iostream>
#include<unordered_map>
#include<vector>
#include<string>
using namespace std;
bool isAnagram(string s, string t) {
        unordered_map<char, int>mymap1;
        unordered_map<char, int>mymap2;
        if(s.length()!=t.length()){
            return false;
        }
        for(int i=0;i<s.length();i++){
            mymap1[s[i]]+=1;
            mymap2[t[i]]+=1;
        }
        for(auto i:mymap1){
            if(i.second!=mymap2[i.first]){
                return false;
            }
        }
        for(auto i:mymap2){
            if(i.second!=mymap1[i.first]){
                return false;
            }
        }
        return true;
    }

int main(){
    string s,t;
    cin>>s>>t;
    cout<< isAnagram(s,t);
}