#include<iostream>
using namespace std;

    int hammingWeight(uint32_t n) {
        int count=0;
        while(n){
            int rem=n%2;
            if(rem==1){
                count=count+1;
            }
            n= n/2;
        }
        return count;
    }

    int main(){
        uint32_t n;
        cin>>n;
        cout<<hammingWeight(n);
    }
