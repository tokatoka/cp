#include<iostream>
#define ll long long


using namespace std;
ll N;

void f(ll,ll,ll&);
int main(){
  cin >> N;
  ll result = 0;
  f(0,0,result);
  cout << result << endl;
}

void f(ll cur,ll use,ll &result){
  if(cur > N){
    return;
  }
  if(use == 0b111){
    result++;
  }

  f(cur * 10 + 7,use | 0b001,result);
  f(cur * 10 + 5,use | 0b010,result);
  f(cur * 10 + 3,use | 0b100,result);

}
