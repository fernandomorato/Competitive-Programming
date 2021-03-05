#include <bits/stdc++.h>
#include "robots.h"

using namespace std;

const int N = 1e6 + 5;
const int M = 5e5 + 5;
const int INF = 1e9;

int a, b, t, x[M], y[M], ans;
pair<int, int> toys[N];

bool check(int qtd) {
	priority_queue<pair<int, int>> pq;
	int ptr = 0;
	for (int i = 0; i < a; i++) {
		for (; ptr < t && toys[ptr].first < x[i]; ptr++)
			pq.emplace(toys[ptr].second, toys[ptr].first);
		for (int j = 0; j < qtd && !pq.empty(); j++)
			pq.pop();
	}
	for (; ptr < t; ptr++) 
		pq.emplace(toys[ptr].second, toys[ptr].first);
	for (int i = 0; i < b; i++) {
		for (int j = 0; j < qtd && !pq.empty(); j++) {
			if (pq.top().first >= y[i]) return false;
			pq.pop();
		}
	}
	return pq.empty();
}

int putaway(int A, int B, int T, int X[], int Y[], int W[], int S[]) {
	a = A, b = B, t = T;
	for (int i = 0; i < a; i++) {
		x[i] = X[i];
	}
	for (int i = 0; i < b; i++) {
		y[i] = Y[i];
	}
	for (int i = 0; i < t; i++) {
		toys[i] = {W[i], S[i]};
	}
	sort(x, x + a);
	sort(y, y + b, greater<int>());
	sort(toys, toys + t);
	int l = 1, r = 1e6, best = -1;
	while (l <= r) {
		int m = (l + r) >> 1;
		if (check(m)) {
			best = m;
			r = m - 1;
		} else {
			l = m + 1;
		}
	}
	return best;
}