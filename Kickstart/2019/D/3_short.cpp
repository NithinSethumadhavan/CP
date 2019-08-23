#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

typedef long long ll;

ll foo(int n, int k, const vector<ll> &x,
    const vector<ll> &c){
  ll mincost = LLONG_MAX;
  for(int i = 0; i != n; ++i){
    vector<ll> tc;
    for(int j = 0; j != n; ++j){
      if( j == i) continue;
      ll temp = c[j] + abs(x[i] - x[j]);
      tc.push_back(temp);
    }
    sort(tc.begin(),tc.end());
    ll ccost = c[i];
    for(int j = 0; j != k; ++j)
      ccost += tc[j];
    mincost = min(mincost,ccost);
  }
  return mincost;
}
    
 

int main(){
  int t;
  cin >> t;
  for(int tc = 0; tc != t; ++tc){
    int n,k;
    cin >> k >> n;
    vector<ll> c(n), x(n);
    for(int i = 0; i != n ; ++i)
     cin >> x[i];
    for(int i = 0; i != n ; ++i)
     cin >> c[i];
    cout << "Case #" << tc + 1 << ": " 
      << foo(n,k,x,c) << endl; 
  }
  return 0;
}

