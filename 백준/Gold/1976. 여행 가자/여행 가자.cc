//분리집합
#include<iostream>
#include<vector>
#define MAX_N 201
using namespace std;

int parent[MAX_N];
vector<int> v;
int city,plan;

int getParent(int x){
    if(parent[x]==x) return x;
    else return parent[x]=getParent(parent[x]);
}

void Union(int a, int b){
    a = getParent(a);
    b = getParent(b);
//    if(a>b)parent[a]=b;
//    else parent[b]=a;
     a>b ? parent[a]=b : parent[b]=a ;
    
}
void input(){
    cin >> city >> plan ;
    for(int i=1;i<=city;i++){        //자기 자신이 부모노드 연결전.
        parent[i]=i;
    }
    for(int i=1;i<=city;i++){
        for(int j=1;j<=city;j++){
            int input;
            cin >> input;
            if(input ==1){
                Union(i,j);
            }
        }
    }
    for(int i=0;i<plan;i++){
        int listCity;
        cin >> listCity;
        v.push_back(listCity);
    }
}
void solve(){
    bool stop =false;
    for(int i=0;i<plan-1;i++){
        if(parent[v[i]]!=parent[v[i+1]]){
            stop = true;
            break;
        }
    }
    cout<< (stop ? "NO\n" : "YES\n") ;
}
void solution(){
    input();
    solve();
}
int main(){
    solution();
    return 0;
}

