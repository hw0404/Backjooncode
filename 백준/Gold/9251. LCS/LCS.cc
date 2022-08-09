//LCS
//22.8.9
#include<iostream>
#include<cstring>

int dp[1001][1001];

using namespace std;

int main(){
    string s1,s2;
    cin >> s1 >>s2;
    for(int i=1;i<=s1.size();i++){
        for(int j=1;j<=s2.size();j++){
            if(s1[i-1]==s2[j-1]){
                dp[i][j] = dp[i-1][j-1]+1;
            }else{
                dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
            }
        }
    }

    cout<<dp[s1.size()][s2.size()];
    return 0;
}

//DP를 이용한 방법
//그냥 for문 돌려서 찾으면 시간초과 발생.
//가로 세로로 문자열 나열하고
// 같으면 현재 위치의 대각선에 있는 값 +1
// 다르면 현재 위치의 왼쪽과 위쪽의 값중 큰값을 그 행렬의 값으로 취한다.
// 단 시작시 처음 0,0에서의 값이 존재해야함으로 1,1부터 문자열을 시작한다.

