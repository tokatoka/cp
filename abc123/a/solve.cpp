#include<iostream>
#include<cmath>
using namespace std;
int main(){
  int a,b,c,d,e,k;
  cin >> a >> b >> c >> d >> e >> k;
  int data[10];
  data[0] = abs(a-b);
  data[1] = abs(a-c);
  data[2] = abs(a-d);
  data[3] = abs(a-e);
  data[4] = abs(b-c);
  data[5] = abs(b-d);
  data[6] = abs(b-e);
  data[7] = abs(c-d);
  data[8] = abs(c-e);
  data[9] = abs(d-e);
  for(int i = 0; i < 10; i++ ){
    if(data[i] > k){
      cout << ":(" << endl;
      return 0;
    }
  }
  cout << "Yay!" << endl;
  

  return 0;
}
