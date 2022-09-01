#include <string>
#include <vector>
#include <iostream>
#include <cstring>
#include <queue>
typedef struct loc{
    int x;
    int y;
    int time;
    int seq;
}loc;
using namespace std;
char map[5][5];
queue<loc> q;
int x_dir[4]={-1,1,0,0};
int y_dir[4]={0,0,-1,1};
int visited[25][5][5];
int bfs(){
    bool stop = false;
    memset(visited,0,sizeof(visited));
    while(!q.empty()){
        int x = q.front().x;
        int y = q.front().y;
        int time = q.front().time;
        int seq = q.front().seq;
        visited[seq][x][y]=1;
        q.pop();
        for(int i=0;i<4;i++){
            int nx = x + x_dir[i];
            int ny = y + y_dir[i];
            if(nx>=0 && ny >=0 && nx<5 && ny<5 && time<=1){
                if(map[nx][ny] !='X'&& visited[seq][nx][ny]==0){
                    if(time<=1 && map[nx][ny]=='P'){
                        stop = true;
                        break;
                    }
                    q.push({nx,ny,time+1,seq});
                    visited[seq][nx][ny]=1;
                }
            }
        }//end for i
        if(stop == true){   //맨해튼 못지킴
            while(!q.empty())q.pop();
            return 0;
        }
    }
    return 1;
}
vector<int> solution(vector<vector<string>> places) {
    vector<int> answer;
   // cout<<places[0][1];    
    for(int i=0;i<5;i++){
        int se=0;
        for(int j=0;j<5;j++){
            string s = places[i][j];
            for(int k=0;k<5;k++){
                map[j][k]=s[k];
                cout<<s[k]<<" ";
                if(s[k]=='P'){
                    q.push({j,k,0,se});
                    se+=1;
                }
            }//end for k    
        }//end for j   
        answer.push_back(bfs());      
    }//end for i
    
    return answer;
}