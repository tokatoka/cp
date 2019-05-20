#include<iostream>
#include<string>
using namespace std;

int main(){
  int N;
  cin >> N;
  int data[N];
  for(int i = 0;i<N;i++){
    cin >> data[i];
  }
  int ret = 0;
  for(int i = 0;i < N ;i++){
    if(i == 0){
      ret++;
      continue;
    }
    else{
      bool flag = true;
      for(int j=0;j < i;j++){
        if(data[j] > data[i]){
          flag = false;
        }
      }
      if(flag == true){
        ret++;
      }
    }
  }
  cout << ret << endl;
  return 0;
}
