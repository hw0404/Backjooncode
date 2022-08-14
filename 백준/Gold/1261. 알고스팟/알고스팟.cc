#include<iostream>
#include<queue>
#define MAX_N 100
using namespace std;

typedef struct newInt{
    int x;
    int y;
}newInt;

int x_dir[4]={-1,1,0,0};
int y_dir[4]={0,0,-1,1};
int N,M;
int Min=100000;
queue<newInt> q;
int map[MAX_N][MAX_N];
int dp[MAX_N][MAX_N];
void input(){
    cin >>  M >> N;
    for(int i=0;i<N;i++){
        for(int j=0;j<M;j++){
            char c;
            cin >> c;
            dp[i][j]=10000;
            if(c == '0')map[i][j]=0;
            else map[i][j]=1;
        }
    }
}
void bfs(){
    while(!q.empty()){
        int x = q.front().x;
        int y = q.front().y;

      //  visited[x][y]=1;
//        if(x==N-1 && y==M-1){
//            Min = min(Min,aoj);
//        }
        q.pop();
        for(int i=0;i<4;i++){
            int nx = x + x_dir[i];
            int ny = y + y_dir[i];
            if( nx>=0 && ny>=0 && nx<N && ny<M ){
                if(map[nx][ny]==1){
                    if(dp[nx][ny]>dp[x][y]+1){
                        dp[nx][ny]=dp[x][y]+1;
                        q.push({nx,ny});
                    }
                }else{
                    if(dp[nx][ny]>dp[x][y]){
                        dp[nx][ny]=dp[x][y];
                        q.push({nx,ny});
                    }
                }
                
                
            }
        }
    }
}
void solve(){
    q.push({0,0});
    map[0][0]=-1;
    dp[0][0]=0;
    bfs();
    cout<<dp[N-1][M-1];
}
void solution(){
    input();
    solve();
}
int main(){
    solution();
    
    return 0;
    
}
