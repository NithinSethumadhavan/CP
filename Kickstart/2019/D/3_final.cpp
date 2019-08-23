#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
#include <queue>
#include <cmath>

using namespace std;

typedef long long ll;

vector<ll> rightVal(int n, int k,const vector<pair<ll,ll> > &x){
  int p = n - k;
  int l = floor(k/2);
  int r = k - l;
  priority_queue<ll, vector<ll> > s;
  vector<ll> ret;
  ll csum = 0;
  for(int i = n-1; i != n - r - 1; --i){
    ll vi = x[i].second + x[i].first - x[0].first;
    s.push(vi);
    csum += vi;
  }
  for(int i = n - r - 1; i > l - 1 ; --i){
    ll ccost = csum - r * (x[i].first - x[0].first) ;
    ret.push_back(ccost);
    ll vi = x[i].second + x[i].first - x[0].first;
    if(s.top() > vi){
      csum -= s.top();
      s.pop();
      s.push(vi);
      csum += vi;
    }
  }
  reverse(ret.begin(),ret.end());
  return ret;
}

vector<ll> leftVal(int n, int k,const vector<pair<ll,ll> > &x){
  int p = n - k;
  int l = floor(k/2);
  if(l == 0){
    return vector<ll>(p,0);
  }
  int r = k - l;
  priority_queue<ll, vector<ll> > s;
  vector<ll> ret;
  ll csum = 0;
  for(int i = 0; i != l; ++i){
    ll vi = x[n-1].first + x[i].second - x[i].first;
    s.push(vi);
    csum += vi;
  }
  for(int i = l; i < n - r; ++i){
    ll ccost = csum - l * (x[n-1].first - x[i].first) ;
    ret.push_back(ccost);
    ll vi = x[n-1].first + x[i].second - x[i].first;
    if(s.top() > vi){
      csum -= s.top();
      s.pop();
      s.push(vi);
      csum += vi;
    }
  }
  return ret;
}



ll foo(int n, int k, const vector<pair<ll,ll> > &x){
  ll mincost = LLONG_MAX;
  int l = floor(k/2);
  int p = n - k;
  vector<ll> lv = leftVal(n,k,x);
  vector<ll> rv = rightVal(n,k,x);
  for(int i = 0; i != p; ++i){
    //cout << rv[i] << endl;
    mincost = min(mincost, lv[i] + rv[i] + x[i+l].second);
  }
  return mincost;
}
    
 

int main(){
  int t;
  cin >> t;
  for(int tc = 0; tc != t; ++tc){
    int n,k;
    cin >> k >> n;
    vector<pair<ll,ll> > x(n);
    for(int i = 0; i != n ; ++i)
     cin >> x[i].first;
    for(int i = 0; i != n ; ++i)
     cin >> x[i].second;
    sort(x.begin(),x.end());
    cout << "Case #" << tc + 1 << ": " 
      << foo(n,k,x) << endl; 
  }
  return 0;
}

