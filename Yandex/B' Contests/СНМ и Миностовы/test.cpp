#include <cstdio>

#include <algorithm>

#include <vector>

using namespace std;

 

struct Edge

{

  int u, v, dist;

};

 

vector<Edge> e;

vector<int> parent, depth;

int i, n, m, res;

 

int Repr(int n)

{

  if (n == parent[n]) return n;

  return parent[n] = Repr(parent[n]);

}

 

int Union(int x, int y)

{

  x = Repr(x); y = Repr(y);

  if (x == y) return 0;

  if (depth[x] < depth[y]) swap(x, y);

  parent[y] = x;

  if (depth[x] == depth[y]) depth[x]++;

  return 1;

}

 

int lt(Edge a, Edge b)

{

  return a.dist < b.dist;

}

 

int main(void)

{

  scanf("%d %d", &n, &m);

 

  parent.resize(n + 1);

  depth.resize(n + 1);

  for (i = 1; i <= n; i++)

  {

    parent[i] = i;

    depth[i] = 0;

  }

 

  e.resize(m);

  for (i = 0; i < m; i++)

    scanf("%d %d %d", &e[i].u, &e[i].v, &e[i].dist);

 

  sort(e.begin(), e.end(), lt);

 

  res = 0;

  for (i = 0; i < m; i++)

    if (Union(e[i].u, e[i].v)) res += e[i].dist;

 

  printf("%d\n", res);

  return 0;

}