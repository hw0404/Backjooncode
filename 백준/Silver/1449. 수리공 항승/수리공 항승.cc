//수리공 항승
// 22 8 12


#include<iostream>
#include<algorithm>
#include<vector>
#define MAX_N 1001
using namespace std;
vector<int> v;
int visited[MAX_N];
int main(){
    int N , L, input;
    cin >> N >> L;
    int cnt =0;
    
    for(int i=0;i<N;i++){
        cin >> input;
        v.push_back(input);
    }
    
    sort(v.begin(),v.end());
    for(int i=0;i<N;i++){
        int start = v[i];
        if(visited[start]==0){
            cnt++;
            for(int i=0;i<L;i++){
                if(start+i<1001){
                visited[start+i]=1;
                }
            }
        }
    }
    cout<< cnt;
    return 0;
}
