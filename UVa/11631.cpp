#include <iostream>
#include <queue>

using namespace std;

int m, n;

struct edge {
	int a, b;
	int cost;

	bool operator< (const edge &lhs ) const {
		return (cost > lhs.cost);
	}
} edges[200010];

int findSet(int* rep, int a) {
	if (rep[a] != a)
		rep[a] = findSet(rep, rep[a]);
	else
		return a;
	return rep[a];
}

void unionSet(int* rep, int a, int b) {
	rep[findSet(rep, a)] = b;
}

bool read() {
	cin >> m >> n;
	if (m == 0 && n == 0) return false;
	return true;
}

void process() {
	priority_queue<edge> edgesQueue;
	int totalCost = 0;
	for (int i = 0; i < n; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		edges[i].a = a;
		edges[i].b = b;
		edges[i].cost = c;
		edgesQueue.push(edges[i]);
		totalCost += c;
	}

	int rep[m];
	for (int i = 0; i < m; i++) {
		rep[i] = i;
	}

	int connectedComp = 1;
	int cost = 0;
	while (connectedComp < m) {
		edge newEdge = edgesQueue.top();
		edgesQueue.pop();
		if (findSet((int*)rep, newEdge.a) != findSet((int*)rep, newEdge.b)) {
			unionSet((int*)rep, newEdge.a, newEdge.b);
			connectedComp++;
			cost += newEdge.cost;
		}
	}

	cout << (totalCost-cost) << endl;
}

int main() {
	while (read()) {
		process();
	}

	return 0;
}
