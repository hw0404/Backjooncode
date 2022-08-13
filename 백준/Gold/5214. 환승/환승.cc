#include<iostream>
#include<queue>
#include<vector>
#define MAX_N 100000
using namespace std;

int N,K,M;
vector<int> v[MAX_N+1000+1];        //MAX_N최대 역의 개수 + 링크 개수 1000개 + 배열 1개
int destination[MAX_N+1000+1];
queue<int> q;

int bfs(){
    q.push(1);
    destination[1]=1;
    while(!q.empty()){
        int cur = q.front();
        q.pop();
        if(cur == N) return destination[N];
        for(int i=0;i<v[cur].size();i++){
            int node = v[cur][i];
            if( destination[node]==0 ){
                q.push(node);
                if(node>MAX_N) destination[node]=destination[cur];
                else destination[node]=destination[cur]+1;
            }
        }
    }
    
    return -1;
}
int main(){
    cin >>  N >> K >> M;
    int input;
    for(int i=1;i<=M;i++){
        for(int j=1;j<=K;j++){
            cin >> input;
            v[input].push_back(MAX_N+i);
            v[MAX_N+i].push_back(input);
        }
    }
    
    cout<< bfs();
    
    return 0;
}
