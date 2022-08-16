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
        return m1.cost <m2.cost;
    }
};
void solve(){
    int arr[N+1];
    for(int i=0;i<=N;i++){
        arr[i]=inf;
    }
    arr[start]=0;
    priority_queue<loc,vector<loc>,com> pq;
    pq.push({start,0});
    while(!pq.empty()){
        int cur = pq.top().next;
        int distance = -pq.top().cost;
        pq.pop();
        if(arr[cur]<distance) continue;
        for(int i=0;i<v[cur].size();i++){
            int next = v[cur][i].next;
            int cost = v[cur][i].cost + distance;
            if(cost<arr[next]){
                arr[next]=cost;
                pq.push({next,-cost});
            }
        }
    }
    for(int i=1;i<=N;i++){
        if(arr[i]==inf) cout<<"INF\n";
        else cout<<arr[i]<<"\n";
        
    }
        
//    int arr[N+1];
//    for(int i=0;i<N+1;i++){
//        arr[i]=inf;
//    }
//    arr[start]=0;
//
//    for(int i=0;i<v[start].size();i++){
//        int next = v[start][i].next;
//        int cost = v[start][i].cost;
//        arr[next]=cost;
//    }
//    for(int i=1;i<=N;i++){
//        if(i==start){
//            continue;
//        }else{
//            for(int j=0;j<v[i].size();j++){
//                int next = v[i][j].next;
//                int cost = v[i][j].cost;
//                if(next == start) continue;
//                if( arr[i]+cost<arr[next]) arr[next]=arr[i]+cost;
//            }
//        }
//    }
//
//    for(int i=1;i<=N;i++){
//        if(arr[i]==10000) cout<<"INF\n";
//        else  cout<<arr[i]<<"\n";
//    }
}
void solution(){
    input();
    solve();
}
int main(){
    solution();
return 0;
}



