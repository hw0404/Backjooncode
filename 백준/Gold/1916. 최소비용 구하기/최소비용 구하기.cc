#include<iostream>
#include<queue>
#include<vector>
#define MAX_N 1001
#define INF 987654321
using namespace std;

vector<pair<int,int>> v[MAX_N];

int d[1001];
int N,M;
int start,desti;
void dijkstra(int s){
    priority_queue<pair<int,int>> pq;
    pq.push({s,0});
    while(!pq.empty()){
        int cur =  pq.top().first;
        int cost = pq.top().second;
        pq.pop();
        if(d[cur]<cost)continue;
        for(int i=0;i<v[cur].size();i++){
            int next = v[cur][i].first;
            int nextCost = v[cur][i].second;
            if(d[next]> d[cur]+nextCost){
                d[next]=d[cur]+nextCost;
                pq.push({next,d[next]});
            }
        }
    }
}
void input(){
    cin  >> N >> M;
    for(int i=1;i<=N;i++){
        d[i]=INF;
    }
    for(int i=0;i<M;i++){
        int a, b, c;
        cin >> a >> b >> c;
        v[a].push_back({b,c});
    }
    cin >> start >> desti;
}
void solve(){

    d[start]=0;
    dijkstra(start);
   
    cout<<d[desti];
}
void solution(){
    input();
    solve();
}
int main(){
    solution();
    
    return 0;
}
