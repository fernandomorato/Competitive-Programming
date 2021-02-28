/**
 *    author:  morato
 *    created: 12.11.2020 20:23:33
**/
#include <bits/stdc++.h>
 
using namespace std;
 
const int N = 5e5;
 
struct Node {
  long long valor;
  Node *l, *r;
 
  Node() {
    valor = 0;
    l = r = NULL;
  }
};
 
long long v[N];
 
void build(Node *cur, int l, int r) {
  if (l == r) {
    cur->valor = v[l];
  } else {
    int m = (l + r) >> 1;
    cur->l = new Node(), cur->r = new Node();
    build(cur->l, l, m);
    build(cur->r, m + 1, r);
    cur->valor = cur->l->valor + cur->r->valor;
  }
}
 
void update(Node *prev, Node *cur, int l, int r, int pos, long long valor) {
  if (l == r) {
    cur->valor = valor;
  } else {
    int m = (l + r) >> 1;
    if (pos <= m) {
      cur->l = new Node();
      cur->r = prev->r;
      update(prev->l, cur->l, l, m, pos, valor);
    } else {
      cur->l = prev->l;
      cur->r = new Node();
      update(prev->r, cur->r, m + 1, r, pos, valor);
    }
    cur->valor = cur->l->valor + cur->r->valor;
  }
}
 
long long query(Node *cur, int l, int r, int ql, int qr) {
  if (qr < l || r < ql) return 0;
  if (ql <= l && r <= qr) return cur->valor;
  int m = (l + r) >> 1;
  return query(cur->l, l, m, ql, qr) + query(cur->r, m + 1, r, ql, qr);
}
 
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n, q; cin >> n >> q;
  for (int i = 1; i <= n; i++) {
    cin >> v[i];
  }
  Node *root = new Node();
  build(root, 1, n);
  vector<Node> versoes;
  versoes.push_back(*root);
  for (int i = 0; i < q; i++) {
    int op; cin >> op;
    if (op == 1) {
      int k, a;
      long long x;
      cin >> k >> a >> x;
      k--;
      Node *novo = new Node();
      update(&versoes[k], novo, 1, n, a, x);
      versoes[k] = *novo;
    } else if (op == 2) {
      int k, a, b;
      cin >> k >> a >> b;
      k--;
      cout << query(&versoes[k], 1, n, a, b) << '\n';
    } else {
      int k; cin >> k;
      k--;
      versoes.push_back(versoes[k]);
    }
  }
  return 0;
}