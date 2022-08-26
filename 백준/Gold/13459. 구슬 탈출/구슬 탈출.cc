//구슬탈출
//22.8.26



#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
#define MAX_N 11
typedef struct loc{
    int rx;
    int ry;
    int bx;
    int by;
    int count;
}loc;

using namespace std;

int N,M;
int redX,redY,blueX,blueY;  // 각 공의 위치
int x_dir[4]={-1,1,0,0};
int y_dir[4]={0,0,-1,1};
int cnt=0;
char map[MAX_N][MAX_N];
int visited[MAX_N][MAX_N][MAX_N][MAX_N];
queue<loc> q;
//입력 받기
void input(){
    cin >> N >> M;
    for(int i=0;i<N;i++){
        for(int j=0;j<M;j++){
            cin >> map[i][j];
            if(map[i][j]=='R'){     //빨간구슬일 때
                map[i][j]='.';
                redX = i;
                redY = j;
            }else if( map[i][j]=='B'){//파란구슬
                map[i][j]='.';
                blueX = i;
                blueY = j;
            }
        }
    }
}
void move( int &rx, int &ry, int dx, int dy, int &cnt ){
    while(1){
        if(map[rx][ry]=='#'){
            rx -=dx;
            ry -=dy;
            cnt-=1;
            break;
        }
        if(map[rx][ry]=='O'){
            break;
        }
        rx +=dx;
        ry +=dy;
        cnt+=1;

    }
}
void bfs(){
    bool stop =false;
    while(!q.empty()){
        int rx = q.front().rx;
        int ry = q.front().ry;
        int bx = q.front().bx;
        int by = q.front().by;
        int count = q.front().count;
        q.pop();
        if(stop){
            break;
        }
        if( count >=10){
            break;
        }
        for(int i=0;i<4;i++){           //움직이게 하는것
            int rcnt =0;
            int bcnt =0;
            int nrx = rx;
            int nry = ry;
            int nbx = bx;
            int nby = by;
            move(nrx,nry,x_dir[i],y_dir[i],rcnt);
            move(nbx,nby,x_dir[i],y_dir[i],bcnt);

            //이동의 조건에 대한 조건문들을 작성해준다.
            if(map[nbx][nby]=='O'){
                continue;
            }else if( map[nrx][nry]=='O'){
                cout<<1<<"\n";
                stop=true;
            }else{
                if(nrx==nbx && nry == nby ){        //서로 겹칠 때
                    if( rcnt > bcnt ){          //빨간공이 더 움직였다 즉 빨강공에서 현재의 방향을 빼준다.
                        nrx-=x_dir[i];
                        nry-=y_dir[i];
                    }else{
                        nbx-=x_dir[i];
                        nby-=y_dir[i];
                    }
                }
                if(visited[nrx][nry][nbx][nby]==0){
                    visited[nrx][nry][nbx][nby]=1;
                    q.push({nrx,nry,nbx,nby,count+1});
                }
            }
        }
    }
    if(!stop) cout<<0<<"\n";
}

void solve(){
    loc ordi = { redX,redY,blueX,blueY,0};
    visited[redX][redY][blueX][blueY]=1;
    q.push(ordi);
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


