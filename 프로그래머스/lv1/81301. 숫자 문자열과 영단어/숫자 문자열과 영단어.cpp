#include <string>
#include <vector>

using namespace std;

int solution(string s) {
    int answer = 0;
    int start=0;
    string copy;
    for(int i=0;i<s.length();i++){
        if(s[i]=='z'){
            copy+='0';
            i+=3;
        }
        else if(s[i]=='o') {
            copy+='1';
            i+=2;
        }else if( s[i]=='t'){
            if(s[i+1]=='w'){
                copy+='2';
                i+=2;
            }else{
                copy+='3';
                i+=4;
            }
        }else if(s[i]=='f'){
            if(s[i+1]=='o'){
                copy+='4';
            }else{
                copy+='5';
            }
            i+=3;
        }else if(s[i]=='s'){
            if(s[i+1]=='i'){
                copy+='6';
                i+=2;
            }else{
                copy+='7';
                i+=4;
            }
        }else if(s[i]=='e'){
            copy+='8';
            i+=4;
        }else if(s[i]=='n'){
            copy+='9';
            i+=3;
        }else{
            copy+=s[i];
        }
    }
    answer=stoi(copy);
    return answer;
    
}