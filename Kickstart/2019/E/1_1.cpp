#include <iostream>
#include <queue>
#include <vector>

using namespace std;

typedef long long ll;

int main(){
  int t;
  cin >> t;
  for(int tc = 1; tc <= t; ++tc){
  ll n1,m;
  cin >> n1 >> m;
  const ll n = n1;
  vector<ll> l[n+1];
  ll u,v;
  for(ll i = 0; i < m; ++i){
    cin >> u >> v;
    l[u].push_back(v);
    l[v].push_back(u);
  }
  vector<bool> vis(n+1,0);
  ll count = 0;
  for(ll x = 1; x <= n; ++x){
    queue <ll> q;
    if(vis[x] == 0){
      q.push(x);
      vis[x] = 1;
    }
    
    while(!q.empty())
    {
      u = q.front();
      q.pop();
      for(ll i = 0; i < l[u].size(); ++i){
        if( vis[ l[u][i] ] == 0){
          ++count;
          q.push(l[u][i]);
          vis[ l[u][i]] = 1;
        }
      }
    }
  }
  ll ans =  2 * (n-1) - count;
  cout << "Case #" << tc << ": " << ans << endl;
  }
  return 0;
}




