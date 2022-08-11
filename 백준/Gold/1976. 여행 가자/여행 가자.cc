#include<iostream>
#include<cstring>
#include<vector>
#define MAX_N 201
using namespace std;
int city,plan;

//int visited[MAX_N][MAX_N];
int visited[MAX_N];
vector<int> dest;
vector<int> graph[MAX_N];

void dfs( int next ){
    int cur = next;
    for(int i=0;i<graph[cur].size();i++){
        int next =graph[cur][i];
        if(visited[next]==0){
            visited[next]=1;
            dfs(next);
        }else{
            continue;
        }
    }
    
}
void input(){
    cin >> city >> plan;                    // city = 도시의 수 , plan = 여행계획에 속한 도시들의 수
    for(int i=1;i<=city;i++){               // 1번도시부터 입력받은(city)의 수만큼 for문을 돌아
        for(int j=1;j<=city;j++){           // 1번와 연결된 도시들을 입력받는다.
            int input;
            cin >> input;
            if( input ==1){
                graph[i].push_back(j);
                graph[j].push_back(i);
            }
                                    //graph[i][j]= graph[j][i] 서로 연결된 도시를 저장
        }
    }
    for(int i=0;i<plan;i++){
        int d;
        cin >> d;
        dest.push_back(d);                  //여행 계획을 넣어줌
    }
}

void solve(){
    bool stop = false;
    visited[dest[0]]=1;
    dfs(dest[0]);
    for(int i=0;i<dest.size();i++){
        if(visited[dest[i]]==0){
            stop=true;
            break;
        }
    }
    cout << (stop ? "NO" : "YES");

}

void solution(){
    input();
    solve();
}
int main(){
    solution();

    return 0;
}



