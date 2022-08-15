// 탈출
// 22 8 15


#include<iostream>
#include<queue>
#define MAX_N 51
using namespace std;
typedef struct loc{
    int x;
    int y;
    int cnt;
}loc;
char map[MAX_N][MAX_N];
int N,M;
int x_dir[4]={-1,1,0,0};
int y_dir[4]={0,0,-1,1};
queue<loc> water;
queue<loc> hege;
int limit = 0;
int wLimit = 0;
int result =0;
bool stop = false;
bool kaktus = false;
void show(){
    for(int i=0;i<N;i++){
        for(int j=0;j<M;j++){
            cout <<map[i][j];
        }
        cout<<"\n";
    }
}
void input(){
    cin >> N >> M;
    for(int i=1;i<=N;i++){
        for(int j=1;j<=M;j++){
            cin >> map[i][j];
            if(map[i][j]=='S'){
                hege.push({i,j,0});
                map[i][j]='O';
            }else if( map[i][j]=='*'){
                water.push({i,j,0});
            }
        }
    }
    
}
void findHege(){
    while(!water.empty()){
        int wx = water.front().x;
        int wy = water.front().y;
        int wCnt = water.front().cnt;
        
        if(wCnt > wLimit ){
            wLimit = wCnt;
            break;
        }else{
            water.pop();
            for(int i=0;i<4;i++){
                int waterX = wx + x_dir[i];
                int waterY = wy + y_dir[i];
                if(waterX)
                if(waterX >0 && waterY > 0 && waterX<=N && waterY<=M && (map[waterX][waterY]=='.'||map[waterX][waterY]=='O') ){
                    water.push({waterX,waterY,wCnt+1});
                    map[waterX][waterY]='*';
                }
            }
        }
        
    }
   // show();
}
 void bfs(){
    while(!hege.empty()){
        int x = hege.front().x;
        int y = hege.front().y;
        int cnt = hege.front().cnt;
        if(cnt > limit){
           // show();
            limit = cnt;
            findHege();
        }
        hege.pop();
        if(map[x][y]=='*') continue;
        else{
            for(int i=0;i<4;i++){
                int nx = x + x_dir[i];
                int ny = y + y_dir[i];
                if(map[nx][ny]=='D'){
                    result=cnt+1;
                    stop=true;
                    break;
                }
                if( nx >0 && ny > 0 && nx<=N && ny<=M && map[nx][ny]=='.'){
                    map[nx][ny]='O';                                        //방문처리
                    hege.push({nx,ny,cnt+1});                               //이동 처리 + 횟수
                }
            }
        }
        if(stop==true){
            cout<<result;
            kaktus=true;
            break;
        }
    }
    if(kaktus==false)
        cout<<"KAKTUS";
     
}
void solve(){
    bfs();
}
void solution(){
    input();
    solve();
}
int main(){
    solution();
return 0;
}


