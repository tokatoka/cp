#include<iostream>
#include<vector>
#include<algorithm>
#include<numeric>
using namespace std;
int N;
vector<int> L;
int main(){
  cin >> N;
  L.resize(N);

  for(int i=0;i<N;i++){
    cin >> L[i];
  }

  sort(L.begin(),L.end());
  int largest = L[N-1];
  L.pop_back();
  int sum = accumulate(L.begin(),L.end(),0);
  if(largest < sum){
    cout << "Yes" << endl;
  }
  else{
    cout << "No" << endl;
  }
}


