#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int N, M;

struct amigo {
	vector<int> adj;
	bool visited;

	void add(int j) {
		adj.push_back(j);
	}
} friends[30010];

void readProcess() {
	cin >> N >> M;
	for (int i = 1; i <= N; i++) {
		friends[i].visited = false;
		friends[i].adj.clear();
	}
	for (int i = 0; i < M; i++) {
		int a, b;
		cin >> a >> b;
		friends[a].add(b);
		friends[b].add(a);
	}

	int maxHeight = 1;
	for (int i = 1; i <= N; i++) {
		if (!friends[i].visited) {
			int tempHeight = 0;
			queue<int> friendsQueue;
			friendsQueue.push(i);

			while (!friendsQueue.empty()) {
				int friendInd = friendsQueue.front();
				friendsQueue.pop();
				if (friends[friendInd].visited) continue;
				friends[friendInd].visited = true;
				tempHeight++;
				if (tempHeight > maxHeight)
					maxHeight = tempHeight;
				for (int i = 0; i < friends[friendInd].adj.size(); i++) {
					if (!friends[friends[friendInd].adj[i]].visited)
						friendsQueue.push(friends[friendInd].adj[i]);
				}
			}
		}
	}
	cout << maxHeight << endl;
}

int main() {
	int T;
	cin >> T;
	while (T--) {
		readProcess();
	}
}
