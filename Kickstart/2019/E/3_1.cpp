#include <iostream>
#include <map>
#include <cmath>
#include <vector>

using namespace std;

typedef long long ll;

int main(){
  int t;
  const ll ul = 1e7+1;
  vector<ll> primes;
  vector<bool> f(ul,1);
  for( ll i = 2; i*i <= ul; ++i){
   if( f[i] == 1){
    primes.push_back(i);
    for(ll j = i*i; j <= ul; j += i)
     f[j] = 0;
   }
  } 

  cin >> t;
  for(int tc = 1; tc <= t; ++tc){
    ll l,r;
    ll ans = 0;
    cin >> l >> r;
    for(ll i = l; i <= r; ++i){
      map< ll,ll > m;
      ll temp = i;
      for(ll j = 0; j < primes.size() && primes[j] <= temp ; ++j){
        ll d = primes[j];
        while( temp % d == 0){
          ++m[ d ];
          temp = temp / d ;
        }
      }
      if( temp != 1) ++m[temp];
      ll o = 1,e = 0;
      for( map<ll,ll>::const_iterator it = m.begin();
          it != m.end(); it++){
        ll num = it->first;
        ll c = it->second;
        if(num == 2){
          e = c;
        }
        else{
          o = o * (c+1);
        }
      }
//      cout << o << e << endl;
      e = e * o;
      if( llabs(e - o) <= 2) ++ans;
    }
    cout << "Case #" << tc << ": " << ans << endl;
  }
  return 0;
}
