#include <iostream>
#include <vector>

using namespace std;

int n,m;
const int size = 100005;
vector<int> adj[size];
int c[size];
int vis[size] = {0};
int foo(int u, int rem){
  vis[u] = 1;
  if(rem < 0) return 0;
  int ans = 0;
  bool flag = true;
  for(int i = 0; i != adj[u].size(); ++i){
    int v = adj[u][i];
    if( vis[v] == 1)
      continue;
    flag = false;
    if(c[v] == 0)
      ans += foo(v,m);
    else
      ans += foo(v,rem-1);
  }

  if(flag) return 1;

  return ans;
}


int main(){
  cin >> n >> m;
  for(int i = 1; i <= n; ++i)
    cin >> c[i];
  for(int i = 0; i != n-1; ++i){
    int u,v;
    cin >> u >> v;
    adj[u].push_back(v);
    adj[v].push_back(u);
  } 
  cout << foo(1, m-c[1]) << endl;
  return 0;
}
