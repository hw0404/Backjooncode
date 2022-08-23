//선수과목
//22.8.23



#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
#define MAX_N 1001
typedef struct loc{
    int subject;
    int time;
}loc;
using namespace std;
int N,M;
vector<int> v[MAX_N];
queue<loc> q;
int result[MAX_N];
int degree[MAX_N];
void input(){
    cin >> N >> M;
    for(int i=0;i<M;i++){       // 선수 조건 입력 받기
        int a,b;
        cin >> a >> b;
        v[a].push_back(b);
        degree[b]+=1;
    }
    
}
void solve(){
    for(int i=1;i<=N;i++){          // 총 과목 수 만큼
        if(degree[i]==0){
            q.push({i,1});
        }
    }
    for(int i=1;i<=N;i++){
        if(q.empty()){
            return;
        }
        int cur = q.front().subject;
        int time =q.front().time;
        result[cur]=time;
        q.pop();
        for(int j=0;j<v[cur].size();j++){
            int next = v[cur][j];
            degree[next]-=1;
            if(degree[next]==0){
                q.push({next,time+1});
            }
        }
    }
    for(int i=1;i<=N;i++){
        cout<<result[i]<<" " ;
    }
    
}
void solution(){
    input();
    solve();
}
int main(){
    solution();
return 0;
}


