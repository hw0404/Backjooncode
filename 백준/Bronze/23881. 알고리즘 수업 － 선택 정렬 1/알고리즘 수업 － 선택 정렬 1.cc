#include<iostream>
using namespace std;

int main(){
    
    int N,K;
    int result[2];
    cin >> N >> K;
    int arr[N];
    for(int i=0;i<N;i++){
        cin >> arr[i];
    }
    
    //선택 정렬하기
    int idx = 0;
    int cnt = 0;
    for(int i=N-1;i>0;i--){
        int max = 0;
        for(int j=0;j<=i;j++){
            if(arr[j]>max){                     // 최솟값 찾기 & 인덱스 저장
                idx = j;
                max = arr[j];
            }
        }
        if( idx == i ) continue;                // 최솟값이 자신의 오름차순의 위치에 있을 때 변경 없음으로 그래로
        else{
            cnt++;
            int temp;
            temp = arr[idx];
            arr[idx] = arr[i];
            arr[i] = temp;
        }
        if(cnt == K){
            result[0] = arr[idx];
            result[1] = arr[i];
            cout<< result[0] << " "<< result[1]<<"\n";
        }
    }
    if(cnt<K)
        cout<<-1<<"\n";
    
    
    return 0;
}
