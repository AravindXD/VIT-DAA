#include <iostream>
using namespace std;

void sortarr(string act[],int s[],int f[],int n){
    int i,j,temp;
    string temp1;
    for(i=0;i<n;i++){
        for(j=i+1;j<n;j++){
            if(f[i]>f[j]){
                temp=f[i];
                f[i]=f[j];
                f[j]=temp;
                temp=s[i];
                s[i]=s[j];
                s[j]=temp;
                temp1=act[i];
                act[i]=act[j];
                act[j]=temp1;
            }
        }
    }
}

int main(){
    int n,i;
    cin>>n;
    string act[n];
    int s[n];
    int f[n];
    
    for(i=0;i<n;i++){
        cin>>act[i]>>s[i]>>f[i];
    }
    
    sortarr(act,s,f,n);
    
    cout<<act[0]<<" ";
    int x=0;
    
    for(i=1;i<n;i++){
        if(s[i]>=f[x]){
            cout<<act[i]<<" ";
            x=i;
        }
    }
    
}