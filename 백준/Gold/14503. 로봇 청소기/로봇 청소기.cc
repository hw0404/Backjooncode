#include<iostream>
#include<queue>
using namespace std;

#define RoomMax 51
int N , M ;     //방의 크기
int Vx,Vy, Vd;  //청소기의 초기위치 및 청소기의 초기 방향
int x_dir[4]={-1,0,1,0};
int y_dir[4]={0,1,0,-1};
int result =1;
int map[RoomMax][RoomMax];
int finish;
queue<pair<int,int>> q;

///void check_locaton(int x, int y, int direction);
void move();

int main(){
    cin >> N >> M;
    cin >> Vx >> Vy >> Vd;
    
    //방 구조 입력받기
    for(int i=0; i< N; i++){
        for(int j=0;j<M ;j++){
            cin >> map[i][j];
            if(map[i][j]==0) finish+=1;
        }
       
    }



//    if(finish ==1) {cout <<"1";
//        return 0;
//    }
  //  else{
        q.push(make_pair(Vx,Vy));
        map[Vx][Vy]=2;
        move();
   
        cout<<result;
         
    
    return 0 ;
}

void move(){
    int check_all=0;
    while(!q.empty()){
        int x = q.front().first;
        int y = q.front().second;
     
        q.pop();
        int cnt=0;
        
        while(1){
   
            //왼쪽으로 움직이기 위해서
            if(Vd==0){
                Vd = 3;
            }
            else Vd = Vd - 1;
            //왼쪽으로 돌렸을 때의 좌표
            int n_x = x + x_dir[Vd];
            int n_y = y + y_dir[Vd];
            //좌표가 유효한지 검사
            if(n_x>=0 && n_y>=0 && n_x<N && n_y<M){
                //청소 되지 않은 공간이 존재하면
                if(map[n_x][n_y]==0){
                    map[n_x][n_y]=2;           //2 청소완료
                    q.push(make_pair(n_x,n_y));
                   
                    result+=1;
                    if(check_all==1)
                        check_all=0;
                    break;
                
                }
                //벽이거나 청소가 되어있으면
                else{
                    cnt+=1;
                    //4방향 청소가 완료되어있다면 뒤로 원래 방향에서 한칸 뒤로 물러야한다.
                    if(cnt==4){
                        //원래 방향의 반대방향으로 움직이게 하기
                        int back = Vd-2;
                        if(back == -1) back =3;
                        else if(back ==-2) back =2;
                        n_x  = x + x_dir[back];
                        n_y  = y + y_dir[back];
                        //만약에 원래방향으로 돌아간다음에 4방향으로 체크를 했을 때 다시 돌아가는 방향이 벽이면 stop
                        if(map[n_x][n_y]==1){
                            break;
                        }
                        q.push(make_pair(n_x,n_y)); //이전 위치를 push 해주고 그 위치에서 다시 돌리기.
                        break;
                    }
                    
                    
                    
                    
                    
//
//                    cnt+=1; //모든 공간이 막혔있을 때 3번쨰 조건 하려면 필요
//                    if(cnt == 4 && check_all!=1){
//                        //자기가 현재 바라보는 방향이 초기의 움직였던 방향임으로 돌아가기함
//                        int back = Vd-2;
//                        if(back == -1) back =3;
//                        else if(back ==-2) back =2;
//                        n_x  = x + x_dir[back];
//                        n_y  = y + y_dir[back];
//                        check_all=1;
//                        q.push(make_pair(n_x,n_y)); //이전 위치를 push 해주고 그 위치에서 다시 돌리기.
//                        break;
//                    }
//                    //갈곳없음
//                    else if(check_all == 1 && cnt==4 && map[n_x][n_y]){
//                        while(!q.empty()) q.pop();
//                        break;
//                    }
                }
            }
            //이전으로 돌아가야함으로
            //
           
        }
        
       // check_locaton(x,y,direction);
        //왼쪽에 청소하지 않은 공간이 존재하면
    
    }
}
    
//
//void check_locaton(int x, int y, int direction){
//    int cnt=0;
//    while(1){
//        if(direction==0){
//            D = 3;
//        }
//        else D = direction - 1;
//        n_x = x + x_dir[D];
//        n_y = y + y_dir[D];
//
//        //청소 되지 않은 공간이 존재하면
//        if(map[n_x][n_y]==0){
//            map[n_x][n_y]=2;           //2 청소완료
//            q.push(make_pair(n_x,n_y));
//            direction=D;
//            break;
//        }
//        //벽이거나 청소가 되어있으면
//        else{
//            D-=1;   //회전해서 공간 찾기
//            cnt+=1; //모든 공간이 막혔있을 때 3번쨰 조건 하려면 필요
//            if(cnt == 4){
//                //자기가 현재 바라보는 방향이 초기의 움직였던 방향임으로 돌아가기함
//                n_x = x - x_dir[D];
//                n_y = y - y_dir[D];
//                q.push(make_pair(n_x,n_y)); //이전 위치를 push 해주고 그 위치에서 다시 돌리기.
//                break;
//            }
//        }
//        //이전으로 돌아가야함으로
//        //
//
//    }
//}

