#include<iostream>
#include<queue>
#include<vector>
#include<algorithm>
using namespace std;

#define MAX_N 1000001
int N,M,K,X;
int visi[300001];
int d[300001];
int cnt;
queue<pair<int,int>> q;
vector<int> v[MAX_N];

void find(vector<int> &result ){
    
    while(!q.empty()){
        int cur = q.front().first;
        int depth = q.front().second;
        q.pop();
        if( depth == K){
            result.push_back(cur);
        }
        for(int i=0;i<v[cur].size();i++){
            int next = v[cur][i];
            if(visi[next]==0){
                visi[next]=1;
                q.push({next,depth+1});
            }
        }
      
    }
}
int main(){
    cin >> N >> M >> K >> X;
    for(int i=0;i<M;i++){
        int a,b;
        cin >> a >> b;
        v[a].push_back(b);
    }
    visi[X]=1;
    q.push({X,0});
    vector<int> result;
    find(result);
    
    if(result.size()==0){
        cout<< -1<<"\n";
        return 0;
    }
    sort(result.begin(),result.end());
    for(int i=0;i<result.size();i++){
        cout<< result[i]<<"\n";
    }
    return 0;
}
