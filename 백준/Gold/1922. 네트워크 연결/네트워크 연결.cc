//네트워크 연결
// 22 8 15



#include<iostream>
#include<vector>
#include<algorithm>
#define MAX_N 1001
using namespace std;

typedef struct newInt{
    int cost;
    int startNode;
    int nextNode;
}newInt;

int N,M;
int result;
vector<newInt> v;
int parent[MAX_N];
bool bigger( newInt a , newInt b){      //오름차순
    if( a.cost < b.cost){
        return true;
    }else return false;
}
int getParent(int x){
    if(parent[x]==x) return x;
    else  return parent[x]=getParent(parent[x]);
}
bool findParent(int a, int b){
    if( getParent(parent[a])==getParent(parent[b])){
        return true;
    }else return false;
}
void Union(int a, int b){
    a = getParent(a);
    b = getParent(b);
    a<b ? parent[a]=b : parent[b]=a;
}
void input(){
    cin >> N >> M;
    for(int i=0;i<M;i++){
        int start,end,cost;
        cin >> start >> end >> cost;
        v.push_back({cost,start,end});
    }
    for(int i=1;i<=N;i++){
        parent[i]=i;
    }
}

void solve(){
    sort(v.begin(),v.end(),bigger);
    for(int i=0;i<v.size();i++){
        int cost = v[i].cost;
        int start =v[i].startNode;
        int end = v[i].nextNode;
        if(findParent(start,end)==false){
            result+=cost;
            Union(start, end);
        }
    }
    cout<<result<<"\n";
   
    
}
void solution(){
    input();
    solve();
}
int main(){
    solution();
return 0;
}


