//최단 경로
//22.8 16
//다익스트라 알고리즘
#include<iostream>
#include<vector>
#include<queue>
#define MAX_N 300001
typedef struct loc{
    int next;
    int cost;
    
}loc;

using namespace std;
int N,M,start;
int inf= 987654321;
vector<loc> v[MAX_N];
void input(){
    cin >> N >> M >>start;
    for(int i=0;i<M;i++){
            int curNode, nextNode, cost;
            cin >> curNode >> nextNode >> cost;
            v[curNode].push_back({nextNode,cost});
    }
    
}
struct com
{
    bool operator()( loc m1, loc m2){
        return m1.cost > m2.cost;
    }
};
void solve(){
    int d[N+1];
    for(int i=0;i<=N;i++){
        d[i]=inf;
    }
    d[start]=0;
    priority_queue<loc,vector<loc>,com> pq;
    pq.push({start,0});
    while(!pq.empty()){
        int current = pq.top().next;
        int curCost = pq.top().cost;
        pq.pop();
        if(d[current]<curCost) continue;
        for(int i=0;i<v[current].size();i++){
            int nextNode = v[current][i].next;
            int nextCost = v[current][i].cost;
            if( nextCost + curCost < d[nextNode]){
                d[nextNode] = nextCost+ curCost;
                pq.push({nextNode,nextCost+curCost});
            }
        }
    }
  

        
    for(int i=1;i<=N;i++){
        if(d[i]==inf) cout<<"INF\n";
        else cout<<d[i]<<"\n";
        
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



