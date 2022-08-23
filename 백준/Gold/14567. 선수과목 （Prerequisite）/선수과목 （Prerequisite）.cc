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
            q.push({i,1});          // 만약 첫 학기에 들을 수 있을 때 {과목,학기} 를 입력으로
        }
    }
    for(int i=1;i<=N;i++){
        if(q.empty()){              // queue가 비어있다면 cycle이 있기때문에 위상정렬 조건이 안됨.
            return;
        }
        int cur = q.front().subject;    // 현재의 위치 즉 현재 과목
        int time =q.front().time;       // 현재의 학기
        result[cur]=time;                   //queue에 들어간 과목은 현재 수강중인 학이이다. 따라서 result에 저장
        q.pop();
        for(int j=0;j<v[cur].size();j++){
            int next = v[cur][j];
            degree[next]-=1;
            if(degree[next]==0){            // 다음학기에 들어야하는 과목의 선수과목을 다 들었을 경우
                q.push({next,time+1});      // 그 과목과 다음학기를 push해준다.
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


