#include<iostream>
#include<vector>
#include<algorithm>
#include<climits>
using namespace std;

#define INF 10000000

int main(){
    int n;
    cin>>n;
    vector<vector<int>>input(n, vector<int>(n));
    vector<vector<int>>dp(n, vector<int>(n, INF));
    int minlen= INF;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin>>input[i][j];
        }
    }

    if(input[0][0] == 1 || input[n-1][n-1] == 1){
        cout<<-1;
    }
    else{
        vector<vector<int>>dir={{0,1},
                                {1,0},
                                {1,1},
                                {0, -1},
                                {-1, 0},
                                {-1, -1},
                                {1, -1},
                                {-1, 1}};
        dp[0][0]=1;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                for(int k=0;k<dir.size();k++){
                    int x=dir[k][0] + i;
                    int y=dir[k][1] + j;
                    if(x>=0 && y>=0 && x<n && y<n && input[x][y]!=1){
                        dp[x][y]= min(dp[x][y], dp[i][j]+1);
                    }
                }
            }
        }
        if(dp[n-1][n-1]<INF)
            cout<<dp[n-1][n-1]<<endl;
        else{
            cout<<-1<<endl;
        }
    }

}