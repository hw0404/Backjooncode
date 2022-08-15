//단어 수학
// 22 8 15


#include<iostream>
#include<cstring>
#include<algorithm>
#include<cmath>
#include<vector>
#define MAX_N 8
using namespace std;
//방법 1 그리디 알고리즘
// 그리디 알고리즘은 탐욕알고리즘으로 555원 잔돈에대해서 거슬러줄 때 500원 100원 10원 1원이 있을 때 어떻게 사용되는지 와 같은 방법의 예시가 있다.
// 이 문제 또한 동일하다.
// 각 자리수에 해당하는 알파벳의 자리값을 알파벳에 넣어주고 그 값이 제일 큰 부분에 순차적으로 큰 수를 곱해준다면 문제가 해결된다.
// 예를들어서 첫번째에 AB가나오고 CA가 나오게 된다면 알파벳 A=11,B=1,C=10이 된다. 이를 내림차순 or 오름차순으로 정렬하여 큰수를 먼저 작은수를 먼저 곱해주게 된담녀 두 수의 최대값을 구하게 되는것이다.

vector<char> v[MAX_N];
int N;
int alpha[26];
void input(){
    cin >> N;
    for(int i=0;i<N;i++){
        string s;
        cin >> s;
        int loc=1;
        for(int j=(int)s.length()-1;j>=0;j--){
            int idx =(int)s[j]-'A';
            alpha[idx] += loc;
            loc*=10;
        }
    }
    
}
int solve(){
    sort(alpha,alpha+26);       //오름차순 정렬
    int result=0;
    int num =9;
    for(int i=25;i>=0;i--){
        if(alpha[i]==0) break;
        result += (alpha[i]*num);
        num--;
    }
    return result;
}
void solution(){
    input();
    cout<< solve();
}
int main(){
    solution();
return 0;
}

