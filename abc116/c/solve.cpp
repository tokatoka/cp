#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int N;
vector<int> h;
int main(){
  cin >> N;
  h.resize(N);
  int result = 0;
  for(int i=0;i<N;i++){
    cin >> h[i];
  }


  while(true){
    int i = 0;
    if(*max_element(h.begin(),h.end()) == 0){
      break;
    }
    while(i < N){
      if(h[i] == 0){
        i++;
      }
      else{
        result++;
        while(i < N && h[i] > 0){
          h[i]--;
          i++;
        }
      }
    }
  }
  cout << result << endl;
  return 0;
}
