#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main(){
  int A,B,K;
  cin >> A >> B >> K;
  int larger,smaller;
  larger = max(A,B);
  smaller = min(A,B);
  vector<int> d;
  for(int i=1;i<=smaller;i++){
    if((larger % i == 0) && (smaller % i == 0)){
      d.push_back(i);
    }
  }
  sort(d.begin(),d.end(),greater<int>());
  cout << d[K-1] << endl;
}
