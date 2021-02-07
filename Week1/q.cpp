#include<iostream>
#include<stack>
#include<string>
#include<algorithm>
#include<vector>
#include<climits>
#include<cmath>
#include<math.h>
using namespace std;

int main(){
    int tc;
    cin>>tc;
    for(int t=0;t<tc;t++){
       long A,B,n;
       cin>>A>>B>>n;
       vector<long>attackpow(n);
       vector<long>healthval(n);
       for(int i=0;i<n;i++){
           cin>>attackpow[i];
       }
       for(int i=0;i<n;i++){
           cin>>healthval[i];
       }
       int i=0;
       for(;i<n && B>0;i++){
           float y =(float)healthval[i]/(float)A;
        //    long y = ceil(num);
           cout<<y<<"   ";
           B = B- y*attackpow[i];
           healthval[i] = healthval[i] - y*A;
       }
       bool flag=true;
        for(int i=0;i<n;i++){
            if(healthval[i]>0){
                flag=false;
                break;
            }
        }
        if(!flag){
            cout<<"NO"<<endl;
            continue;
        }
        if(B<=0 && i==n){
            cout<<"YES"<<endl;
        }

        else if(B<0 && i<n){
            cout<<"NO"<<endl;
        }
        else{
            cout<<"YES"<<endl;
        }
    }
}