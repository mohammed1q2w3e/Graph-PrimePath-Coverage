#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Graph {
    int n;
    vector<vector<int>> adj;

public:
    Graph(int n) : n(n), adj(n) {}
    void addEdge(int u, int v) { adj[u].push_back(v); }

    void dfsAll(int u, vector<int>& path, vector<vector<int>>& res) {
        path.push_back(u);

        for (int v : adj[u]) {
            if (!path.empty() && v == path.front() && v != path.back()) {
                vector<int> cycle = path;
                cycle.push_back(v);
                res.push_back(cycle);
            }
            if (find(path.begin(), path.end(), v) == path.end()) {
                dfsAll(v, path, res);
            }
        }

        res.push_back(path);
        path.pop_back();
    }

    vector<vector<int>> getAllPaths() {
        vector<vector<int>> res;
        vector<int> path;
        for (int i = 0; i < n; i++)
            dfsAll(i, path, res);

        sort(res.begin(), res.end());
        res.erase(unique(res.begin(), res.end()), res.end());
        return res;
    }

    static bool isSub(const vector<int>& p, const vector<int>& q) {
        if (p.size() > q.size()) return false;
        for (size_t i = 0; i + p.size() <= q.size(); ++i)
            if (equal(p.begin(), p.end(), q.begin() + i))
                return true;
        return false;
    }

    vector<vector<int>> getPrime(const vector<vector<int>>& all) {
        vector <vector<int>> primes;
        for (const auto& p : all) {
            bool sub = false;
            for (const auto& q : all) {
                if (p == q) continue;
                if (q.size() > p.size() && isSub(p, q)) {
                    sub = true;
                    break;
                }
            }
            if (!sub)
                primes.push_back(p);
        }
        sort(primes.begin(), primes.end());
        primes.erase(unique(primes.begin(), primes.end()), primes.end());
        return primes;
    }

    bool simpleDFSUtil(int u, int dst, vector<int>& path, vector<int>& used) {
        path.push_back(u);
        used[u] = 1;
        if (u == dst) return true;

        for (int v : adj[u]) {
            if (!used[v]) {
                if (simpleDFSUtil(v, dst, path, used)) return true;
            }
        }

        path.pop_back();
        used[u] = 0;
        return false;
    }

    bool simpleDFS(int src, int dst, vector<int>& path) {
        vector<int> used(n, 0);
        path.clear();
        return simpleDFSUtil(src, dst, path, used);
    }

    vector<vector<int>> buildTests(const vector<vector<int>>& primes) {
        vector<vector<int>> tests;
        if (n == 0) return tests;
        int start = 0, end = n - 1;
        for (const auto& prime : primes) {
            vector<int> test, prefix, suffix;
            if (!simpleDFS(start, prime.front(), prefix)) {
                prefix.clear();
                prefix.push_back(prime.front());
            }

            test = prefix;
            for (int x : prime)
                if (test.empty() || test.back() != x)
                    test.push_back(x);

            if (simpleDFS(prime.back(), end, suffix)) {
                for (size_t i = 0; i < suffix.size(); i++) {
                    if (i == 0 && test.back() == suffix[0]) continue;
                    test.push_back(suffix[i]);
                }
            }

            tests.push_back(test);
        }

        sort(tests.begin(), tests.end());
        tests.erase(unique(tests.begin(), tests.end()), tests.end());
        return tests;
    }
};

static void printPaths(const vector<vector<int>>& paths, const string& title) {
    cout << "\n" << title << ":\n";
    for (auto& p : paths) {
        for (int x : p) cout << x << " ";
        cout << "\n";
    }
}

int main() {
    int n;
    cout << "Enter number of nodes: ";
    cin >> n;

    Graph g(n);

    cout << "Enter edges (u v), end with -1:\n";
    while (true) {
        int u;
        cin >> u;
        if (u == -1) break;
        int v;
        cin >> v;
        g.addEdge(u, v);
    }

    auto all = g.getAllPaths();
    auto primes = g.getPrime(all);
    auto tests = g.buildTests(primes);

    printPaths(primes, "Prime Paths");
    printPaths(tests, "Test Paths");

    return 0;
}
