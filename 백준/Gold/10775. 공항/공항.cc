#include<iostream>
using namespace std;
#define MAX_N 100001

int gate, flight;
int parent[MAX_N];
int cnt;
int arrived ;
int find( int x ){
    if(parent[x]==x)return x;
    else return parent[x]=find(parent[x]);
}
int main(){
    ios_base:: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> gate >> flight;
    
    for(int i=1;i<=gate;i++){
        parent[i]=i;
    }
    
    for(int i=1;i<=flight;i++){
        cin >>arrived;
        int fArr = find(arrived);
        if(fArr==0){
            break;
        }else{
            cnt++;
            parent[fArr]=fArr-1;
        }
    }
        cout <<cnt;

    return 0;
}
