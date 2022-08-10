//
////빙산 골드4
////22.7.21
//
//#include<iostream>
//#include<queue>
//#include<cstring>
//#include<vector>
//using namespace std;
//#define MAX_N 300
//
//typedef struct ice{
//    int x;
//    int y;
//    int time;
//    int ice_size;
//}ice;
//typedef struct xy{
//    int x;
//    int y;
//}xy;
//queue<ice> q;
//
//int N,M;
//int map[MAX_N][MAX_N][MAX_N];
//int x_dir[4]={-1,1,0,0};
//int y_dir[4]={0,0,-1,1};
//int current_t=0;
//int visited[MAX_N][MAX_N];
//
//vector<xy> v;
//int BFS();
//int Find_ice();
//void Find_icebarg(int x, int y);
//void show();
//int main(){
//    cin >> N >> M;
//    for(int i=0;i<N;i++){
//        for(int j=0;j<M;j++){
//            cin >> map[i][j][0];
//            ice p = {i,j,0,map[i][j][0]};
//            if(map[i][j][0]>0) {
//                v.push_back({i,j});
//                q.push(p);
//            }
//        }
//    }
//    if(Find_ice()>=2){
//        cout << 0<<"\n";
//    }else{
//        v.clear();
//        cout << BFS();
//    }
//
//    return 0;
//}
//int BFS(){
//    int result=0;
//    bool stop = false;
//    while(!q.empty()){
//        int x = q.front().x;
//        int y = q.front().y;
//        int t = q.front().time;
//        int ic = q.front().ice_size;
//        if( current_t < t){ //1년이 지나고
//            current_t = t;
//            memset(visited,0,sizeof(visited));
//            int num=Find_ice();
//            if(num>=2){
//                result=t;
//                stop=true;
//            }
//
//           // show();
//
//            v.clear();
//        }
//        if(stop==true) break;
//
//        q.pop();
//        for(int i=0;i<4;i++){
//            int nx = x + x_dir[i];
//            int ny = y + y_dir[i];
//            if(nx>=0 && ny>=0 && nx<N && ny<M){
//                if(map[nx][ny][t]==0){
//                    ic -=1;
//                }
//            }
//        }
//        t+=1;
//        if(ic<0) ic=0;
//        map[x][y][t]=ic;
//        if(ic>0){
//            xy in = {x,y};
//            v.push_back(in);
//            ice input = {x,y,t,ic};
//            q.push(input);
//        }
//    }
//    return result;
//}
//int Find_ice(){
//    int icebarg=0;
//    int xy_size = v.size();
//    for(int i=0;i<xy_size;i++){
//        int xx = v[i].x;
//        int yy = v[i].y;
//        if(visited[xx][yy]==0){
//            Find_icebarg(xx,yy);
//            icebarg+=1;
//            if(icebarg==2)break;
//        }
//
//    }
//    return icebarg;
//}
//
//void Find_icebarg(int x, int y){
//    visited[x][y]=1;
//    for(int i=0;i<4;i++){
//        int nx = x + x_dir[i];
//        int ny = y + y_dir[i];
//        if(nx >=0 && ny >=0 && nx<N &&ny<M){
//            if(map[nx][ny][current_t]>0 && visited[nx][ny]==0){
//                Find_icebarg(nx,ny);
//            }
//        }
//    }
//}
//void show(){
//    for(int i=0;i<N;i++){
//        for(int j=0;j<M;j++){
//            cout << map[i][j][current_t] << " ";
//        }
//        cout << "\n";
//    }
//}


#include<iostream>
#include<queue>
#include<cstring>
#include<vector>
using namespace std;
#define MAX_N 300

typedef struct maze{
    int x;
    int y;
    int cycle;
}maze;
typedef struct maa{
    int x;
    int y;
 //   int cycle;
}maa;

int N,M;
int x_dir[4]={-1,1,0,0};
int y_dir[4]={0,0,-1,1};

int map[MAX_N][MAX_N];
int c_map[MAX_N][MAX_N];
int visited[MAX_N][MAX_N];

int result ;

queue<maa> q;
vector<maa> v;
int cur =0;

void change_map(){
    for(int i=0;i<N;i++){
        for(int j=0;j<M;j++){
            map[i][j]=c_map[i][j];      //바뀐 맵 정보르 기존 맵에 저장
        }
    }
    memset(visited,0,sizeof(visited));
}

void bfs(int i, int j){
    q.push({i,j});
    visited[i][j]=1;
    while(!q.empty()){
        int x =q.front().x;
        int y =q.front().y;
        q.pop();
        int water = 4;
        for(int i=0;i<4;i++){
            int nx = x + x_dir[i];
            int ny = y + y_dir[i];
            if( nx > 0 && ny >0 && nx < N && ny <M && map[nx][ny]>0){
                water-=1;       //주변 물 카운트
                if(!visited[nx][ny]){   //이동한 곳이 방문을 안했다면
                    visited[nx][ny]=1;
                    q.push({nx,ny});     //
                }
            }
        }
        c_map[x][y]-=water;
        if(c_map[x][y]<0) c_map[x][y]=0;
    
    }
}



void input(){
    cin >> N >> M;
    for(int i=0;i<N;i++){
        for(int j=0;j<M;j++){
            cin >> map[i][j];
            c_map[i][j]=map[i][j];
        }
    }
    int time=0;
    while(1){
        int cnt=0;
        for(int i=1;i<N;i++){
            for(int j=1;j<M;j++){
                if(visited[i][j]==0 && map[i][j]>0){        //빙하에 해당하는 위치에서 다른 빙하들 찾기
                    bfs(i,j);
                    cnt++;
                }
            }
        }
        if(cnt==0){                 //빙하가 없을때 즉 다 녹았을 때
            cout<<0;
            break;
        }else if( cnt >=2 ){        //빙하 덩어리가 2개 이상일 때
            cout<< time;
            break;
        }
        time++;
        change_map();
    }
}

void solve(){

}
void solution(){
    input();
    solve();
}
int main(){
    solution();

    return 0;
}
