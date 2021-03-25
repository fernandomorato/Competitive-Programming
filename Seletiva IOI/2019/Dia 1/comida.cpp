#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

struct Point
{
	ll x, y;

	Point(ll _x = 0, ll _y = 0): x(_x), y(_y) {}

	Point operator -(const Point &other) { return Point(x - other.x, y - other.y); }
	
	ll operator %(const Point &other) { return x * other.y - y * other.x; }

	bool operator <(Point &other) {
		if (x == other.x) return y < other.y;
		return x < other.x;
	}
};

bool cmp(Point &a, Point &b) {
	return a.y * b.x > b.y * a.x;
}

vector<Point> upper_hull(vector<Point> p) {
	vector<Point> uh;
	int m = 0;
	for (int i = 0; i < (int) p.size(); i++) {
		while ((int) uh.size() >= 2 && (uh[m - 1] - uh[m - 2]) % (p[i] - uh[m - 2]) >= 0) {
			m--;
			uh.pop_back();
		}
		uh.push_back(p[i]);
		m++;
	}
	return uh;
}

void fix(vector<Point> &p) {
	vector<Point> pp;
	for (int i = 0; i < (int) p.size(); i++) {
		if (i == 0) pp.push_back(p[i]);
		else {
			if (pp.back().x != p[i].x) pp.push_back(p[i]);
			else {
				pp.back() = p[i];
			}
		}
	}
	p = pp;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n;
	ll r, ans = 0;
	cin >> n >> r;
	ll precoAtual = 0;
	vector<Point> pontos;
	for (int j = 0; j < n; j++) {
		int k;
		cin >> k;
		vector<Point> p;
		for (int i = 0; i < k; i++) {
			ll x, y;
			cin >> x >> y;
			p.emplace_back(x, y);
		}
		sort(p.begin(), p.end());
		fix(p);
		p = upper_hull(p);
		ll mx = 0;
		int idx = 0;
		for (int i = 0; i < (int) p.size(); i++) {
			if (p[i].y > mx) {
				mx = p[i].y;
				idx = i;
			}
		}
		while ((int) p.size() > idx + 1) {
			p.pop_back();
		}
		reverse(p.begin(), p.end());
		precoAtual += p.back().x;
		ans += p.back().y;
		Point anterior = p.back();
		p.pop_back();
		while (!p.empty()) {
			pontos.push_back(p.back() - anterior);
			anterior = p.back();
			p.pop_back();
		}
	}
	if (precoAtual > r) {
		cout << -1 << '\n';
		return 0;
	}
	sort(pontos.begin(), pontos.end(), cmp);
	for (int i = 0; i < (int) pontos.size(); i++) {
		if (r - precoAtual >= pontos[i].x) {
			precoAtual += pontos[i].x;
			ans += pontos[i].y;
		} else {
			ans += pontos[i].y * (r - precoAtual) / pontos[i].x;
			precoAtual = r;
		}
		if (precoAtual == r) break;
	}
	assert(precoAtual <= r);
	cout << ans << '\n';
	return 0;
}