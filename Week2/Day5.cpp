#include<iostream>
#include<vector>
using namespace std;

int main(){
    int num;
    cin>>num;
    int count=0;
    while(num){
        if(num%2==0){
            num=num/2;
            count+=1;
        }
        else{
            num= num-1;
            count+=1;
        }
    }
    cout<< count;
}