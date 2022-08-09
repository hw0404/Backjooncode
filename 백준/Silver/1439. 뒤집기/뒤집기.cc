#include<iostream>

using namespace std;

int main(){
    string s;
    cin >> s;
    int zero=0;
    int one=0;
    for(int i=0;i<s.size();i++){
        if(i==s.size()-1){
            if(s[i]=='1'){
                one+=1;
            }else zero+=1;
        }
        if(s[i]!=s[i+1]){
            if(s[i]=='1'){
                one+=1;
            }else{
                zero+=1;
            }
        }
        
    }
    cout<<min(one,zero);
    return 0;
}
