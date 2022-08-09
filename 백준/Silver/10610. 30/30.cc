//30

#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
//30의 배수 -> 1. 0을 포함하고있어야함.
//           2. 각자리수에 합들이 3의 배수.
bool compare(char a, char b){
    if( a>b){
        return true;
    }else return false;
}
int main(){
    string s;
    cin >> s;
    int total=0;
    bool zero= false;
    for(int i=0;i<s.length();i++){
        // string -> 숫자로 바꾸기.
        total += s[i]-'0';  //2번조건을 위함
        if((s[i]-'0')==0){
            zero=true;
        }
    }
    if( zero == true && total%3==0){
        sort(s.begin(),s.end(),compare);
        cout<<s<<"\n";
    }else{
        cout<<-1<<"\n";
    }
    return 0;
}
