#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

#define MAX_N 100001

int N,M;
vector<int>v;
int result[MAX_N];
int arr[MAX_N];
void input(){
    cin >> N >> M;
    for(int i=0;i<N;i++){
        int a;
        cin >> a;
        if(arr[a]==0){
            v.push_back(a);
            arr[a]=1;
        }

    }
    sort(v.begin(),v.end());
}
void solve(int cnt){
    if(cnt == M){
        for(int i=0;i<M;i++){
            cout<< result[i]<< " " ;
        }
        cout<<"\n";
        return ;
    }
    for(int i=0;i<v.size();i++){
        result[cnt]=v[i];
        solve(cnt+1);
    }
}
int main(){
    input();
    solve(0);
    return 0;
}
