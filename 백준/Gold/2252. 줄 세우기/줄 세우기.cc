#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
#define MAX_N 32001
using namespace std;
int N,M;
queue<int> q;
vector<int> v[MAX_N];
int degree[MAX_N];
int result[MAX_N];
void input(){
    cin >> N >> M;
    for(int j=1;j<=M;j++){
        int a, b;
        cin >> a >> b;
        v[a].push_back(b);
        degree[b]+=1;
    }
}
void solve(){
    for(int i=1;i<=N;i++){
        if(degree[i]==0){
            q.push(i);
        }
    }
    for(int i=1;i<=N;i++){
        if(q.empty()){
            return;
        }
        int cur = q.front();
        q.pop();
        result[i]=cur;
        for(int j=0;j<v[cur].size();j++){
            int next = v[cur][j];
            degree[next]-=1;
            if(degree[next]==0){
                q.push(next);
            }
        }
    }
    for(int i=1;i<=N;i++){
        cout<< result[i]<< " ";
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