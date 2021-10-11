#include <bits/stdc++.h>
using namespace std;

#define MINIM 1e16
// structura Object in care retin informatia de pe fiecare linie
struct Object {
    int varf;
    int cost;
// constuctorul
    Object(int _varf, int _cost)
        : varf(_varf)
        , cost(_cost) { }
};

class Task {
 public:
	void solve() {
        	read_input();
        	print_output(get_result());
    	}

 private:
	long long int n, b;
    	vector<Object> objs;
    	// citirea din fisierul de intrare
    	void read_input() {
        	ifstream fin("ridge.in");
        	fin >> n;
        	for (long long int i = 0, varf, cost; i < n; i++) {
        	    	fin >> varf >> cost;
            		objs.push_back(Object(varf, cost));
        	}
        	fin.close();
    	}

	long long int get_result() {
		long long int N = n - 1;
		// matricea dp pentru rezolvare:
		// dp[i][j] = costul minim necesar pentru a aduce varful i
		// la restrictiile din enunt, taind din el j unitati
    		vector <vector <long long int> > dp(n + 1, vector<long long int> (3, 0));
		long long int costMin = MINIM;
		// cazul de baza:
		// pentru varful 0 (primul varf din sir), costul pentru a taia
		// 0, 1, sau 2 din el este egal cu costul de a taia o unitate,
		// inmultit cu numarul de taieturi:
  		for (int i = 0; i < 3; i++)
  			dp[0][i] = i * objs[0].cost;
  		// cazul general:
  		// pentru fiecare varf i, verificam care este costul minim
  		// pe crae trebuie sa il facem ca sa il facem sa fie diferit
  		// de vecinii sai:
    		for (int i = 1; i <= n; i++) {
    			// vedem daca e nevoie sa taiem 0, 1, sau 2 unitati
    			// din varful i - 1;
    			// pentru aceasta:
        		for (int j = 0; j < 3; j++) {
        			costMin = MINIM;
            			for (int k = 0; k < 3; k++)
            				if (objs[i].varf - j != objs[i - 1].varf - k)
                				costMin = min(costMin, dp[i - 1][k]);
                		// dupa for-ul de mai sus, in costMin va ramane
                		// costul minim necesar pentru a prelucra varful i - 1;
                		// costul total pentru varful i va fi cel format din costul
                		// necesar pentru a il reduce cu j unitati + costul minim
                		// ca sa reducem varful din spatele lui,
                		// pentru a ne asigura ca cele 2 varfuri
                		// consecutive sa fie distincte
            			dp[i][j] = j * objs[i].cost + costMin;
        		}
    		}
    		costMin = MINIM;
    		// costul returnat este costul minim dintre cele 3 cazuri:
  		return min (min (costMin, dp[N][0]), min (dp[N][1], dp[N][2]));
	}
	// scrierea din fisierul de iesire
    	void print_output(long long int result) {
    	    	ofstream fout("ridge.out");
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
