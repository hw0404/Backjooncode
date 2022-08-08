////베스트셀러
////2022 7 8
//
//#include<iostream>
//#include<map>
//#include<string>
//#include<vector>
//#include<algorithm>
//
//
//using namespace std;
//#define MAX_N 1001
//map<string,int> m;
//vector<string> v[MAX_N];
//int cnt[MAX_N];
//int main(){
//    int N;
//    cin >> N;
//
//     int max = 0;
//    for(int i=0;i<N;i++){
//        string s;
//        cin >> s;
//        if(N==1){
//            cout<< s;
//            break;
//        }
//        if(i>0){
//            if(m.find(s)==m.end()){
//                m.insert({s,i});
//                cnt[i]+=1;
//                if(cnt[i]>max){
//                    max = cnt[i];
//                }
//            }else{
//                int n= m.find(s)->second;
//                cnt[n]+=1;
//                if(cnt[n]>max){
//                    max = cnt[n];
//                }
//            }
//        }
//        if(i==0){
//            m.insert({s,i});
//            cnt[i]+=1;
//        }
//
//    }
//    if(N!=1){
//        vector<string> v;
//        for(auto iter = m.begin();iter!=m.end();iter++){
//            if(cnt[iter->second] ==max){
//                v.push_back(iter->first);
//            }
//        }
//        if(v.size()==1){
//            cout<<v[0];
//        }else{
//            sort(v.begin(),v.end());
//            cout<<v[0];
//        }
//    }
//    return 0;
//}
//
//
//
#include<iostream>
#include<map>
#include<string>
#include<vector>
#include<algorithm>


using namespace std;
#define MAX_N 1001
map<string,int> m;
vector<string> v[MAX_N];
int cnt[MAX_N];
int main(){
    int N;
    cin >> N;
    int Max =0;
    for(int i=0;i<N;i++){
        string s;
        cin >> s;
        m[s]++;
    }
    for(auto iter = m.begin();iter!=m.end();iter++){
        Max = max(Max,iter->second);
    }
    for(auto iter = m.begin();iter!=m.end();iter++){
        if(Max == (*iter).second){
            cout<<(*iter).first;
            return 0;
        }
    }

    return 0;
}

