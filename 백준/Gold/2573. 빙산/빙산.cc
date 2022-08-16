#include<iostream>
#include<vector>
#include<queue>
#include<cstring>
#define MAX_N 301
typedef struct loc{
    int x;
    int y;
 //   int melt;
}loc;

using namespace std;
int N,M;
int visited[MAX_N][MAX_N];
int map[MAX_N][MAX_N];
int cMap[MAX_N][MAX_N];
int x_dir[4]={-1,1,0,0};
int y_dir[4]={0,0,-1,1};
queue<loc> q;
void input(){
    cin >> N >> M;
    for(int i=1;i<=N;i++){
        for(int j=1;j<=M;j++){
            cin >> map[i][j];
            cMap[i][j]=map[i][j];
        }
    }
}
void findIce(){
    
}
void changeMap(int map[][MAX_N],int cMap[][MAX_N]){
    for(int i=1;i<=N;i++){
        for(int j=1;j<=M;j++){
            map[i][j]=cMap[i][j];
        }
    }
}
void bfs(){
    visited[q.front().x][q.front().y]=1;
    while(!q.empty()){
        int x = q.front().x;
        int y = q.front().y;
      //  int melt = q.front().melt;
        q.pop();
        for(int i=0;i<4;i++){
            int nx = x + x_dir[i];
            int ny = y + y_dir[i];
//     요기  (틀린코드)   ---------------------------=-
            
            if(nx>=1 && ny>=1 && nx<=N && ny<=M && !visited[nx][ny] ){
                if(map[nx][ny]==0){
                    cMap[x][y]-=1;
                    if(cMap[x][y]<0) cMap[x][y]=0;
                }else{
                    visited[nx][ny]=1;
                    q.push({nx,ny});
                }
            }
//-----------=----=----=----=----=----=----=----=----=----=----=----=--
        }
    }
}
void solve(){
    int year=0;
    while(1){
        memset(visited,0,sizeof(visited));
        int cnt=0;
        for(int i=1;i<=N;i++){
            for(int j=1;j<M;j++){
                if(map[i][j]>0 && !visited[i][j]){
                    q.push({i,j});
                    bfs();
                    cnt++;
                }else{
                    continue;
                }
            }
        }
        if(cnt >= 2){
            cout<<year<<"\n";
            break;
        }else if( cnt ==0){
            cout<< "0\n";
            break;
        }
        year++;
        changeMap(map,cMap);
        
        
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