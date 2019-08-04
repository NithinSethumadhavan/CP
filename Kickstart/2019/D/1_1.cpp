#include <iostream>
using namespace std;

long bin_count(int n){
  if( __builtin_parity(n)) return 1;
  return 0;
}

long foo(long n, long f, long l, long val){
  if(val == 0) return n;
  if( f == -1 || f == n) return 0;
  return max(l,n - f - 1);
}


int main(){
  long T;
  cin >> T;
  for(int t = 0; t!= T; ++t){
    long n,q;
    cin >> n >> q;
    long a[100005];
    long temp;
    long f = n, l = -1;
    long val = 0;
    for(int i = 0; i != n; ++i){
      cin >> temp;
      a[i] = bin_count(temp);
      val += a[i];
      if(a[i] == 1){
        if(f == n)
          f = i;
        l = i;
      }
    }
    val = val % 2;
    long ans = foo(n,f,l,val);
    long p,v;
    cout << "Case #"<< t+1 <<":";
    for(int i = 0; i != q; ++i){
      cin >> p >> v;
      temp = bin_count(v);
      if(temp != a[p]){
        a[p] = temp;
        val = (val + 1) % 2;
        if(val == 0) ans = n;
        else{
          for(int li = 0; li != n; ++li){
            for(int ri = li + 1; 

      }
      cout <<" " << ans; 
    }
    cout << "\n";
  }
  return 0;
}




