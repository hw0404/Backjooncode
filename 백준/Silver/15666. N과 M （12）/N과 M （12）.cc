#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

#define MAX_N 9
int N,M;
int num[10001];
vector<int> v;
int result[MAX_N];
void back(int cnt){
    if( cnt == M){
        for(int i=0;i<M;i++){
            cout<<result[i]<<" " ;
        }
        cout<<"\n";
        
        return ;
    }
    
    for(int i=0;i<v.size();i++){
        if(cnt>0){
            if(v[i]>=result[cnt-1]){
                    result[cnt]=v[i];
                    back(cnt+1);
            }
        }else{
        result[cnt]=v[i];
        back(cnt+1);
        }
      
    }
    
}
int main(){
    cin >> N >> M;
    int a=0;
    for(int i=0;i<N;i++){
        cin >>  a;
        if(num[a]==0){
            num[a]=1;
            v.push_back(a);
        }
    }
    sort(v.begin(),v.end());
    back(0);
    
    
    return 0;
}


