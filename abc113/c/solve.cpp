#include<iostream>
#include<vector>
#include<tuple>
#include<algorithm>
#include<>
using namespace std;
int N,M;

int main(){
  cin >> N >> M;
  tuple<int,int,int> data[M];
  for(int i = 0; i < M ; i++ ){
    int p,y;
    cin >> p >> y;
    data[i] = make_tuple(y,p,i);
  }

  sort(data,data+M);

  int cnt[N+1];
  fill(cnt,cnt+N+1,0);
  pair<int,int> id[M];
  for(int i = 0; i < M; i++){
    int y,p,idx;
    tie(y,p,idx) = data[i];
    cnt[p]++;
    id[idx] = make_pair(p,cnt[p]);
  }
  for(int i = 0; i < M;i++){
    cout << setw(6) << setfill('0') << id[i].first;
    cout << setw(6) << setfill('0') << id[i].second << endl;
  }
  return 0;
}
