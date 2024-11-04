#include <iostream>
using namespace std;

bool inc(string s1,string s2){
    int k;
    int p=s1.length();
    if(s1[0]==s2[0]){
        for(k=2;k<p;k++){
            if((s1[k-1]-s2[k-1])<=(s1[k-2]-s2[k-2])){
                return false;
            }
        }
    }
    else{
        return false;
    }
    return true;
}


bool dec(string s1,string s2){
    int k;
    int p=s1.length();
    if(s1[0]==s2[0]){
        for(k=2;k<p;k++){
            if((s1[k-1]-s2[k-1])>=(s1[k-2]-s2[k-2])){
                return false;
            }
        }
    }
    else{
        return false;
    }
    return true;
}
void check(string text,string pat){
    int i,j;
    int t=text.length();
    int p=pat.length();
    string temp="";
    for(i=0;i<(t-p+1);i++){
        int x=0;
        while(x<p){
            temp+=text[i+x];
            x++;
        }
        bool y=true;
        for(j=0;j<p;j++){
            if(temp[j]!=pat[j]){
                y=false;
                break;
            }
        }
        if(y){
            cout<<"Matching"<<"\n";
        }
        else if(inc(temp,pat)){
            cout<<"First match increasing"<<"\n";
        }
        else if(dec(temp,pat)){
            cout<<"First match decreasing"<<"\n";
        }
        else{
            cout<<"Not matching"<<"\n";
        }
        temp="";
    }
}

int main(){
    string text,pattern;
    cin>>text;
    cin>>pattern;
    check(text,pattern);
}