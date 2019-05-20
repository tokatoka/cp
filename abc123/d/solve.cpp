#include<iostream>
#include<typeinfo>
#include<vector>
#include<algorithm>
#include<queue>
#include<set>

using namespace std;
using Data = pair<long long,vector<int>>;

int main(){
  vector<long long> N(3);
  int K;
  cin >> N[0] >> N[1] >> N[2];
  cin >> K;
  vector<vector<long long>> v(3);
  for(int i=0;i<3;i++){
    v[i].resize(N[i]);
    for(int j=0;j<N[i];j++){
      cin >> v[i][j];
      sort(v[i].begin(),v[i].end(),greater<long long>());
    }
  }

  priority_queue<Data> que;
  set<Data> set;
  que.push(Data(v[0][0] + v[1][0] + v[2][0],vector<int>({0,0,0})));
  for(int k=0;k < K;k++){
    auto c = que.top();que.pop();
    cout << c.first << endl;
    for(int iter=0;iter<3;iter++){
      if(c.second[iter] + 1 < N[iter]){
        long long sum = c.first - v[iter][c.second[iter]] + v[iter][c.second[iter] + 1];
        auto num = c.second;
        num[iter]++;
        auto d = Data(sum,num);
        if(!set.count(d)) set.insert(d),que.push(d);
      }
    }
  }

}
