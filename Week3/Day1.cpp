#include<iostream>
#include<vector>
#include<unordered_map>
#include<queue>
using namespace std;

vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
       priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>>pq;
        unordered_map<int, int>mymap;
        for(int i=0;i<mat.size(); i++){
            int count=0;
            for(int j=0;j<mat[0].size();j++){
                if(mat[i][j]==1){
                    count+=1;
                }
            }
            pq.push(make_pair(count, i));
            mymap[i]=count;
        }
        
        vector<int>result;
        while(k && pq.size()!=0){
            auto rn= pq.top();
            pq.pop();
            if(result.size()==0){
                result.push_back(rn.second);
                k--;
            }
            else if(rn.first >= mymap[result[result.size()-1]]){
                result.push_back(rn.second);
                k--;
            }
        }
        return result;
    }