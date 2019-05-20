#include<iostream>
#include<vector>
#include<utility>
#include<algorithm>
using namespace std;

int main(){
  unsigned long N,M;
  cin >> N >> M;
  vector<pair<unsigned long,unsigned long>> data(N,std::make_pair(0,0));
  for(int i=0;i<N;i++){
    cin >> data[i].first >> data[i].second;
  }
  sort(data.begin(),data.end());


  unsigned long sum = 0;
  unsigned long total = 0;
  for(int i=0;i<N;i++){
    if(total + data[i].second >= M){
      unsigned long diff = (M-total);
      sum = sum + data[i].first*diff;
      break;
    }
    else{
      sum = sum + data[i].first*data[i].second;
      total = total + data[i].second;
    }
  }

  cout << sum << endl;
  return 0;
}
