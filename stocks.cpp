#include <bits/stdc++.h>
using namespace std;
// clasa obiect i =n care retin datele fiecarei linii din fisierul de intrare
struct Object {
	// in suma pastrez cat costa actiunea
    double suma;
    	// in cazDefavorabil cat va valora in cazul cel mai nedorit
    double cazDefavorabil;
    	// in cazFavorabil cat va valora in cazul cel mai bun
    double cazFavorabil;
    	// in pierdere, suma maxima de bani pe care o poate pierde Gigel daca
    	// cumpara actiunea asta
    int pierdere;
    	// in castig, suma maxima de bani pe care o poate castiga Gigel daca
    	// cumpara actiunea asta
    int castig;
// constuctor
    Object(double _s, double _cazDef, double _cazFav, int _pier, int _cas)
        : suma(_s)
        , cazDefavorabil(_cazDef)
        , cazFavorabil(_cazFav)
        , pierdere(_pier)
        , castig(_cas) { }
};



class Task {
 public:
	void solve() {
        	read_input();
        	print_output(get_result());
    	}

 private:
	int n, buget, loss;
    	vector<Object> o;
    	// se face citirea din fisierul de intrare
    	void read_input() {
        	ifstream fin("stocks.in");
        	fin >> n >> buget >> loss;
        	for (int i = 1, s, caz_d, caz_f; i <= n; i++) {
        	    	fin >> s >> caz_d >> caz_f;
            		o.push_back(Object(s, caz_d, caz_f, s - caz_d, caz_f - s));
        	}
        	fin.close();
    	}

	int get_result() {
		int L = loss + 1, B = buget + 1, N = n + 1;
		// matrice necesara pentru a retine solutiile probremelor
		// mai mici sau egale cu problema noastra
		vector<vector<vector<int>>> dp(N, vector<vector<int>> (L, vector<int>(B, 0)));
		// in cazul initial, indiferent de cat e pierderea maxima sau
		// bugetul de care dispune Gie=gel, daca se cumpara 0 actiuni,
		// profitul maxim este tot 0
    		for (int l = 0; l <= loss ; l++)
    			for (int b = 0; b <= buget; b++)
    				dp[0][l][b] = 0;
    		// in continuare este rezolvat cazul general:
    		// daca suntem la elementul i + 1, presupunem
    		// ca toate problemele anterioare sunt deja
    		// rezolvate
    		for (int i = 0; i < n; i++) {
    			for (int l = 0; l <= loss; l++) {
    				for (int b = 0; b <= buget; b++) {
    					// actiunea i + 1 o putem sau nu
    					// folosi pentru a ne maximiza
    					// castigul:
    					// daca NU, atunci în acest caz, o să
    					// alegem cea mai bună soluție formată
    					// cu celelalte i−1 actiuni
    					dp[i + 1][l][b] = dp[i][l][b];
    					// daca DA, atunci avem nevoie sa
    					// dispunem de suficienti bani pentru
    					// a o cumpara si ca pierderea pe care
    					// ne-o poate pricinui, sa nu depaseasca
    					// l (adica pierderea maxima din
    					// momentul acesta)
    					if (l - o[i].pierdere >= 0 && b - o[i].suma >= 0) {
						int sol = dp[i][l - o[i].pierdere][b - o[i].suma] + o[i].castig;
						// alegem solutia care e mai avantajoasa
    						dp[i + 1][l][b] = max(dp[i + 1][l][b], sol);
    					}
    				}
    			}
    		}
    		// in dp[n][loss][buget] se afla stocat profitul maxim cerut;
    		// se returneaza profitul
    		return dp[n][loss][buget];
    	}
	// se scrie raspunsul in fisierul de iesire
    	void print_output(int result) {
    	    	ofstream fout("stocks.out");
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
