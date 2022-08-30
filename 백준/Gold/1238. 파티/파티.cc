// 파티


#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>


using namespace std;
#define iint pair<int,int>
#define MAX_N 10001
#define INF 987654321
int N,M,X;
vector<iint> v[MAX_N];
vector<int> result;
int dist[1001];
void input(){
    cin >> N >> M >> X;
    for(int i=0;i<M;i++){
        int a,b,c;
        cin >> a >> b >> c;
        v[a].push_back({b,c});
    }
}
int dijkstra(int start, int end){
    for(int i=1;i<=N;i++){
        dist[i]=INF;
    }
    
    priority_queue<iint> pq;
    pq.push({start,0});
    dist[start]=0;
    while(!pq.empty()){
        int cur = pq.top().first;
        int cost = pq.top().second;
        pq.pop();
        if( cost > dist[cur])continue;
        for(int i=0;i<v[cur].size();i++){
            int next = v[cur][i].first;
            int nextCost = v[cur][i].second + cost;
            if( nextCost < dist[next]){
                dist[next]=nextCost;
                pq.push({next,nextCost});
            }
        }
    }
    return dist[end];
}
void solve(){
    for(int i=1;i<=N;i++){
        if( i == X) continue;
        int res1 = dijkstra(i, X);
        int res2 = dijkstra(X, i);
        result.push_back(res1+res2);
    }
    sort(result.begin(),result.end());
    cout<< result[N-2];
}
void solution(){
    input();
    solve();
}
int main(){
    solution();
return 0;
}
