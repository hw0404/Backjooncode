#include<iostream>
#include<cstring>
#include<vector>
#include<algorithm>

using namespace std;

int N,K;
int alpha[26];
vector<string> v;

int MAX =0;
int findWord(){
   
    int output=0;
    for(int i=0;i<N;i++){
        bool stop = false;
        string st = v[i];
        for(int j=0;j<st.length();j++){
            int compa = st[j]-'a';
            if(alpha[compa]==0){
                stop = true;
                break;
            }
        }
        if(!stop){
            output+=1;
        }
    }
    return output;
}
void back( int cnt ,int start){
    if(cnt == K){
        if(MAX<findWord()) MAX =findWord();
 
        return ;
    }
    for(int i=start;i<26;i++){          //알파벳의 사이즈만큼
        if(alpha[i]==1)continue;
        alpha[i]=1;
        back(cnt+1,i);
        alpha[i]=0;
    }
}
int main(){
    cin >> N >> K;
    alpha['t'-'a']=1;
    alpha['a'-'a']=1;
    alpha['n'-'a']=1;
    alpha['i'-'a']=1;
    alpha['c'-'a']=1;
    
    for(int i=0;i<N;i++){
        string s;
        cin >> s;
        v.push_back(s);             //입력받은 단어들을 벡터 v에 저장
    }
    if(K<5) cout<< "0\n";
    else{
        K=K-5;
        back(0,0);
        cout<<MAX;
    }
    return 0;
}
