#include<string>
#include<iostream>
#include<vector>

using namespace std;
int N,K;
string S;
int main(){
  cin >> N >> K;
  cin >> S;
  vector<int> data;
  if(S[0] == '0'){
    data.push_back(0);
  }
  for(int i=0;i<S.size();){
    int j = i;
    while(j < S.size() && S[j] == S[i]){
      j++;
    }
    data.push_back(j-i);
    i = j;
  }

  if(S.back() == '0'){
    data.push_back(0);
  }

  vector<int> sums((int)data.size() + 1,0);
  for(int i=0;i<data.size();i++){
    sums[i+1] = sums[i] + data[i];
  }

  int ret = 0;
  for(int left = 0; left < sums.size(); left += 2){
    int right = left + K * 2 + 1;
    if(right >= data.size()){
      right = (int) sums.size() - 1;
    }
    ret = max(ret,sums[right] - sums[left]);
  }

  cout << ret << endl;
}
