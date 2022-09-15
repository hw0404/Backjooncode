

#include<iostream>
#include<queue>

#define MAX_N 101

typedef struct loc{
    int x;
    int y;
    int d;
    int t;
}loc;
using namespace std;

int N,M;
int startX, startY, startD, endX,endY,endD;
int map[MAX_N][MAX_N];
int visited[MAX_N][MAX_N][5];
int x_dir[5]={0,0,0,1,-1};
int y_dir[5]={0,1,-1,0,0};
queue<loc> q;
void input(){
    cin >> N >> M;
    for(int i=1;i<=N;i++){
        for(int j=1;j<=M;j++){
            cin >> map[i][j];
        }
    }
    cin >> startX >> startY >> startD;
    q.push({startX,startY,startD,0});
    visited[startX][startY][startD]=1;
    cin >> endX >> endY >> endD;
    
}
int bfs(){
    
    int result=0;
    while(!q.empty()){
        int size = q.size();
        while(size--){
            int x = q.front().x;
            int y = q.front().y;
            int d = q.front().d;
            int time = q.front().t;
            q.pop();
            if( x == endX && y == endY && d==endD ){
                return result;
            }
            int nx = x;
            int ny = y;
            int nd = d;
            /*앞으로 이동*/
            for(int i=0;i<3;i++){
                nx = nx + x_dir[d];
                ny = ny + y_dir[d];
                if(map[nx][ny]==1) break;
                if(nx>=1 && ny>=1 && nx<=N && ny<=M &&map[nx][ny]==0){
                    if(visited[nx][ny][nd]==0){
                        q.push({nx,ny,nd,time+1});
                        visited[nx][ny][nd]=1;
                    }
                }
            }
     
            if( d<=2) nd = 3;
            else nd=1;
            
            /*회전 구현*/
            for(int i=0;i<2;i++){
                nd+=i;
        
                if(visited[x][y][nd]==0){
                    visited[x][y][nd]=1;
                    q.push({x,y,nd,time+1});
                }
            }
            
        }
        result+=1;
    }
    return result;
}
void solve(){
    cout<<bfs();
    
}
void solution(){
    input();
    solve();
}
int main(){
    solution();
return 0;
}
