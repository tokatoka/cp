#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main(){
  int a,b,c,d,e;
  cin >> a >> b >> c >> d >> e;
  vector<int> original(5,0);
  vector<int> digit(5,0);
  original[0] = a;
  original[1] = b;
  original[2] = c;
  original[3] = d;
  original[4] = e;
  digit[0] = a%10;
  digit[1] = b%10;
  digit[2] = c%10;
  digit[3] = d%10;
  digit[4] = e%10;
  for(int i=0;i<5;i++){
    if(digit[i] == 0){
      digit[i] = 9;
    }
  }
  int minElementIndex = min_element(digit.begin(),digit.end()) - digit.begin();
  int ret = 0;
  for(int i = 0; i < 5; i++){
    if(i != minElementIndex){
      ret = ret + (original[i] + ((10 - original[i] % 10 == 10) ? 0 : 10 - original[i] % 10));
    }
  }
  ret = ret + original[minElementIndex];
  cout << ret << endl;
}

