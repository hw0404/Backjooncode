

#include<iostream>
#include<queue>
#define MAX_N 51
using namespace std;

typedef struct loc{
    int x;
    int y;
}loc;
int N;
int map[MAX_N][MAX_N];
int visited[MAX_N][MAX_N];
int x_dir[4]={-1,1,0,0};
int y_dir[4]={0,0,-1,1};
int dp[MAX_N][MAX_N];
queue<loc> q;
void input(){
    cin >> N;
    for(int i=1;i<=N;i++){
        for(int j=1;j<=N;j++){
            char input;
            cin >> input;
            if(input =='1') map[i][j]=1;
            else map[i][j]=0;
            dp[i][j]=2500;
        }
    }
}
void bfs(){
    while(!q.empty()){
        int x = q.front().x;
        int y = q.front().y;
        q.pop();
        
            for(int i=0;i<4;i++){
                int nx = x + x_dir[i];
                int ny = y + y_dir[i];
                if(nx >0 && ny >0 && nx<=N && ny<=N){
                    if(map[nx][ny]==1){
                        if(dp[nx][ny]>dp[x][y]){
                            dp[nx][ny]=dp[x][y];
                            q.push({nx,ny});
                        }
                    }else{//벽일때
                        if(dp[nx][ny]>dp[x][y]+1){
                            dp[nx][ny]=dp[x][y]+1;
                            q.push({nx,ny});
                        }
                    }
                }
            }
        
        
      
    }
}
void solve(){
    q.push({1,1});
    dp[1][1]=0;
    bfs();
    cout<<dp[N][N];
}
void solution(){
    input();
    solve();
}
int main(){
    solution();
return 0;
}


