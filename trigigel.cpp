#include <bits/stdc++.h>
using namespace std;

#define MOD 1000000007

class Task {
 public:
	void solve() {
        	read_input();
        	print_output(get_result());
    	}

 private:
	long long int n;
	// citirea
    	void read_input() {
        	ifstream fin("trigigel.in");
        	fin >> n;
        	fin.close();
    	}

	long long int get_result() {
		// liniile matricii inseamna cazurile pentru cand se primeste
		// 0, 1, .. n ca parametru.
		// coloana 0 stocheaza numarul de siruri ce se termina in 0;
		// coloana 1 stocheaza numarul de siruri ce se termina in 1;
		// coloana 2 stocheaza numarul de siruri ce se termina in 2;
        	vector<vector<long long int>> dp(n + 1, vector<long long int>(3, 0));
        	// cazul initial:
        	// pentru o secventa de lungime 3 (012), avem:
        	// - un sir ce se termina in 0;
        	// - 2 siruri ce se termina in 1;
        	// - 3 siruri ce se termina in 2;
        	dp[3][0] = 1;
        	dp[3][1] = 2;
        	dp[3][2] = 3;
        	// se calculeaza cazul general:
        	for (long long int i = 4; i <= n; i++) {
        		// daca se adauga un 0, sirurile vor deveni:
        		if (i % 3 == 1) {
        			dp[i][0] = (dp[i - 1][0] % MOD + (dp[i - 1][2] + 1) % MOD) % MOD;
        			dp[i][1] = dp[i - 1][1];
        			dp[i][2] = dp[i - 1][2];
        		}
        		// daca se adauga un 1, sirurile vor deveni:
        		if (i % 3 == 2) {
        			dp[i][0] = dp[i - 1][0];
        			dp[i][1] = (dp[i - 1][1] % MOD + (dp[i - 1][0] + 1) % MOD) % MOD;
        			dp[i][2] = dp[i - 1][2];
        		}
        		// daca se adauga un 2, sirurile vor deveni:
        		if (i % 3 == 0) {
        			dp[i][0] = dp[i - 1][0];
        			dp[i][1] = dp[i - 1][1];
        			dp[i][2] = (dp[i - 1][2] % MOD + (dp[i - 1][1] + 1) % MOD) % MOD;
        		}
        	}
        	// numarul total de siruri este egal cu cele ce se termina in 0
        	// + cele ce se termina in 1 + cele ce se termina in 2
    		return (dp[n][0] % MOD + (dp[n][1] % MOD + dp[n][2] % MOD) % MOD) % MOD;
    	}
    		// scrierea
		void print_output(long long int result) {
    	    		ofstream fout("trigigel.out");
        		fout << result;
        		fout.close();
    		}
};

int main() {
	auto* task = new (std::nothrow) Task();
    	if (!task) {
        	std::cerr << "new failed: WTF are you doing? Throw your PC!\n";
        	return -1;
    	}
    	task->solve();
    	delete task;
    	return 0;
}
