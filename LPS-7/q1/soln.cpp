#include <iostream>
using namespace std;

void check(string text,string pat){
    
    int t=text.length();
    int p=pat.length();
    int i;
    int s=0;
    while(s<=(t-p+1)){
        int x=s;
        bool y=true;
        for(i=0;i<p;i++){
            if(text[x]==pat[i]){
                x++;
            }
            else{
                y=false;
            }
        }
        if(y){
            cout<<s<<"\n";
            s+=p;
        }
        else{
            s+=1;
        }
    }
    
}

int main(){
    string text,pattern;
    cin>>text;
    cin>>pattern;
    check(text,pattern);
    
}