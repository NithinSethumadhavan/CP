#include <iostream>
#include <set>

using namespace std;

int foo(int n, const set<int> &s){
  if( s.size()%2 == 0 )
    return n;
  int f = *(s.begin());
  int l = *(s.rbegin());
  return max(n - f - 1, l);
}

int main(){
  int T;
  cin >> T;
  for(int t = 0; t!= T; ++t){
    int n,q;
    cin >> n >> q;
    set<int> s;
    int temp;
    for(int i = 0; i != n; ++i){
      cin >> temp;
      if( __builtin_parity(temp))
        s.insert(i);
    }
    int p,v,ans;
    cout << "Case #"<< t+1 <<":";
    for(int i = 0; i != q; ++i){
      cin >> p >> v;
      if( __builtin_parity(v) )
        s.insert(p);
      else
        s.erase(p);
      ans = foo(n,s);
      cout <<" " << ans; 
    }
    cout << "\n";
  }
  return 0;
}




