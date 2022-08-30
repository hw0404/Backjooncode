//특정한 최단 경로


#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
#define MAX_N 200000
#define INF 987654321
using namespace std;
vector<pair<int,int>> v[MAX_N];
int dist[801];
int N,M,visitA,visitB;

void input(){
    cin >> N >> M;
    for(int i=0;i<M;i++){
        int a,b,c;
        cin >> a >>  b>> c;
        v[a].push_back({b,c});
        v[b].push_back({a,c});
    }
    cin >> visitA >> visitB;
}
int dijkasta( int start, int end ){
    for(int i=1;i<=N;i++){
        dist[i]=INF;
    }
    priority_queue<pair<int,int>> pq;
    pq.push({start,0});
    dist[start]=0;
    while(!pq.empty()){
        int cur = pq.top().first;
        int cost = pq.top().second;
        pq.pop();
        if(cost > dist[cur]) continue;
        for(int i=0;i<v[cur].size();i++){
            int next =v[cur][i].first;
            int nextCost = v[cur][i].second;
            if( nextCost + cost < dist[next]){
                dist[next] = nextCost + dist[cur];
                pq.push({next,dist[next]});
            }
        }
    }
    return dist[end];
}
void solve(){
    int result1, result2;
    int f1,f2,f3;
    int s1,s2,s3;
    f1 = dijkasta(1, visitA);
    f2 = dijkasta(visitA, visitB);
    f3 = dijkasta(visitB, N);
    if(f1 == INF || f2 == INF || f3 == INF){
        result1 = INF;
    }else result1 = f1+f2+f3;
    
    s1 = dijkasta(1, visitB);
    s2 = dijkasta(visitB, visitA);
    s3 = dijkasta(visitA, N);
    if(s1 == INF || s2 == INF || s3 == INF){
        result2 = INF;
    }else result2 = s1+s2+s3;
    if( result1 < result2 )
        cout<< result1;
    else if( result1 == INF && result2 == INF) cout<<-1;
    else cout<< result2;
    
}
void solution(){
    input();
    solve();
}
int main(){
    solution();
return 0;
}


