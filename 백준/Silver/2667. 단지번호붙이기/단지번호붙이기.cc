#include<iostream>
#include<vector>
#include<cstring>
#include<algorithm>
#define max 25
using namespace std;
int visited[max][max];
int maze[max][max];
int cnt;

int x_dir[4]={-1,1,0,0};
int y_dir[4]={0,0,-1,1};
vector<int> v;
void dfs(int start_x, int start_y);
int n;
int main(){

    cin >> n ;
    for(int i=0;i<n;i++){
        string s;
        cin >> s;
        for(int j=0;j<n;j++){
            maze[i][j]=s[j]-'0';}
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(maze[i][j] ==1 && visited[i][j]==0){
                cnt=0;
                dfs(i,j);
                v.push_back(cnt);
            }
        }
    }
    sort(v.begin(),v.end());
    cout<<v.size()<<"\n";
    for(int i =0;i<v.size();i++){
        cout<<v[i]<<"\n";
    }
    return  0;
}
void dfs(int start_x, int start_y){
    cnt++;
    visited[start_x][start_y]=1;
        for(int i=0;i<4;i++){
            int x=start_x+x_dir[i];
            int y=start_y+y_dir[i];
            if(x<0||x>=n || y<0 || y>=n)continue;
        if(maze[x][y]==1 && visited[x][y]==0){
            dfs(x,y);
        }
    }
}