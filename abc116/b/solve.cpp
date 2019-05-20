#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;
long long s;
vector<long long> vec;

long long f(long long);
int main(){
  cin >> s;
  while(true){
    vec.push_back(s);
    s = f(s);
    if(find(vec.begin(),vec.end(),s)!=vec.end()){
      cout << vec.size() + 1 << endl;
      break;
    }
  }
  return 0;
}

long long f(long long n){
  if(n % 2 == 0){
    return n/2;
  }
  else{
    return 3 * n + 1;
  }
}
