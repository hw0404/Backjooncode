#include<iostream>
#include<map>
#include<string>
#include<vector>
#include<algorithm>


using namespace std;
#define MAX_N 1001
map<string,int> m;
vector<string> v[MAX_N];
int cnt[MAX_N];
int main(){
    int N;
    cin >> N;
    int Max =0;
    for(int i=0;i<N;i++){
        string s;
        cin >> s;
        m[s]++;
    }
    for(auto iter = m.begin();iter!=m.end();iter++){
        Max = max(Max,iter->second);
    }
    for(auto iter = m.begin();iter!=m.end();iter++){
        if(Max == (*iter).second){
            cout<<(*iter).first;
            return 0;
        }
    }

    return 0;
}

