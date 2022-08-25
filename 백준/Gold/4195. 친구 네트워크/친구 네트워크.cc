//친구 네트워크
//8월 25일

#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
#include<cstring>
#include<map>
#define MAX_N 200001
using namespace std;

int T,F;
map<string,int > m;
int parent[MAX_N];
int result[MAX_N];
vector<pair<int,int>> v;
int getParent(int x){
    if(parent[x]==x) return x;
    else return parent[x]=getParent(parent[x]);
}
int Union( int a, int b){
    a = getParent(a);
    b = getParent(b);
    a>b ? parent[a]=b : parent[b]=a;
    if(a>b){
        result[b]+=result[a];
        return b;
    }else if(a<b){
        result[a]+=result[b];
        return a;
    }else{
        return a;
    }
}

void input(){
    cin >> T;
    int cnt;
    for(int i=0;i<T;i++){
        v.clear();
        m.clear();
        cnt=0;
        cin >> F;
        for(int j=1;j<=F;j++){
            int a=0,b=0;
            string s1,s2;
            cin >> s1 >> s2;
            if(m.find(s1)==m.end()){//존재하지 않을 때
                m.insert({s1,cnt});
                a=cnt;
                cnt++;
            }else{//존재하면
                a=m.find(s1)->second;
            }
            if(m.find(s2)==m.end()){
                m.insert({s2,cnt});
                b=cnt;
                cnt++;
            }else{
                b=m.find(s2)->second;
            }
            v.push_back({a,b});
        }
        for(int i=0;i<cnt;i++){
            result[i]=1;
            parent[i]=i;
        }
        for(int i=0;i<v.size();i++){
            int c1 = v[i].first;
            int c2 = v[i].second;
            int out = Union(c1,c2);
            cout<<result[out]<<"\n" ;
        }
    }
}
void solution(){
    input();
}
int main(){
    solution();
return 0;
}



