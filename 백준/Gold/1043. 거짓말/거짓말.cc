//거짓말
//22.8.11


#include<iostream>
#include<vector>
#include<algorithm>
#define MAX_N 51
using namespace std;

int parent[MAX_N];
int people,party,realPeople;
vector<int> partyList[MAX_N];
vector<int> checkList;
int arr[MAX_N];
int result;
int getParent(int x){
    if(parent[x]==x) return x;
    else return getParent(parent[x]);
}
void Union(int a, int b){
    a = getParent(a);
    b = getParent(b);
    
    a > b ? parent[a] = b : parent[b] = a;
}
void solve(){
    if(realPeople == 0){            // (1)조건 : 아는 사람 0 명이면 모든 파티 거짓말 가능
        cout<< party<<"\n";
    }else{
        for(int i=0;i<party;i++){
            for(int j=0;j<partyList[i].size();j++){
                int p = partyList[i][j];
                if(getParent(p)==getParent(checkList[0])){
                    result+=1;
                    break;
                }
            }
        }
        cout<<party-result<<"\n";
    }

}

void input(){
    cin >> people >> party >> realPeople;
                        // 각 파티별 참석하는 사람들을 partyList[N] N번 파티에 들어가는 사람 넣어주기.
    for(int i=1;i<=people;i++){
        parent[i]=i;
    }
    for(int i=0;i<realPeople;i++){
        int p;
        cin >> p;
        checkList.push_back(p);
        if(i>0){
            Union(checkList[i-1], checkList[i]);
        }
        
    }
    sort(checkList.begin(),checkList.end());
    
    for(int i=0;i<party;i++){
        int numPeople;
        cin >> numPeople;
        for(int j=0;j<numPeople;j++){
            int getnum;
            cin >> getnum;
            partyList[i].push_back(getnum);
        }
        for(int j=0;j<partyList[i].size()-1;j++){
                Union(partyList[i][j],partyList[i][j+1]);
        }
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
