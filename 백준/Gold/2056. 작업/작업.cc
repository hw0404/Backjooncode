//작업 -> 위상정렬
//22.7.22
#include<algorithm>
#include<iostream>
#include<vector>
#include<queue>
#define MAX_N 100001
using namespace std;

int N;
int degree[MAX_N];
int build_Time[MAX_N];
int result[MAX_N];
vector<int> v[MAX_N];

void input(){
    cin >> N;
    for(int k=1;k<=N;k++){
        int sec, build_num;
        cin >> sec >> build_num;
        build_Time[k]=sec;
        for(int i=0;i<build_num;i++){
            int prior_building;
            cin >> prior_building;
            v[prior_building].push_back(k);
            degree[k]+=1;
        }

    }
    
}

void solution(){
    queue<int> q;
    
    for(int i=1;i<=N;i++){
        if(degree[i]==0) q.push(i);
        result[i]=build_Time[i];
    }
    
    for(int i=1;i<=N;i++){
        if(q.empty()) return;
        int cur = q.front();
        q.pop();
        for(int i=0;i<v[cur].size();i++){
            int next = v[cur][i];
            if(result[next]<result[cur]+build_Time[next])
                result[next]=result[cur]+build_Time[next];
            degree[next]-=1;
            if(degree[next]==0) q.push(next);
        }
    }
    sort(result,result+N+1);
    cout<<result[N];
    
}

void solve(){
    input();
    solution();
}

int main(){
    solve();
    return 0;
}
