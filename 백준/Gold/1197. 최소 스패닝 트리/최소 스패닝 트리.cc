//최소 스패닝 트리
//22 8 16




#include<iostream>
#include<vector>
#include<algorithm>
#define MAX_N 10001
using namespace std;
typedef struct newInt{
    int cost;
    int curNode;
    int nextNode;
}newInt;

int N,M;
vector<newInt> v;
int parent[MAX_N];
int bigger(newInt a, newInt b){
    return a.cost<b.cost;
}
int getParent(int x ){
    if(parent[x]==x) return x;
    else return parent[x]=getParent(parent[x]);
}
void Union(int a ,int b){
    a = getParent(a);
    b = getParent(b);
    if(a!=b) parent[a]=b;
}
bool isSame(int a, int b){
    a = getParent(a);
    b = getParent(b);
    return a == b ? true : false;
}
void input(){
    cin >> N >> M;
    int cur,next,cost;
    for(int i=0;i<M;i++){
        cin >> cur >> next >> cost;
        v.push_back({cost,cur,next});
    }
}
void solve(){
    for(int i=1;i<=N;i++){
        parent[i]=i;
    }
    int result=0;
    sort(v.begin(),v.end(),bigger);
    for(int i=0;i<v.size();i++){
        int cur = v[i].curNode;
        int next = v[i].nextNode;
        int cost = v[i].cost;
        if(!isSame(cur,next)){
            Union(cur, next);
            result+=cost;
        }
    }
    cout<< result;
}
void solution(){
    input();
    solve();
}
int main(){
    solution();
return 0;
}



