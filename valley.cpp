#include <bits/stdc++.h>
using namespace std;

class Task {
 public:
	void solve() {
        	read_input();
        	print_output(get_result());
    	}

 private:
	long int n;
	vector <long int> varf;
	// valorile nu se mai retin intr-o structura, ca la primele 2 probleme
	// acum se retin intr-un vector de inaltimi.
    	void read_input() {
        	ifstream fin("valley.in");
        	fin >> n;
        	for (int i = 0, vf; i < n; i++) {
        	    	fin >> vf;
            		varf.push_back(vf);
        	}
        	fin.close();
    	}
	// gaseste si returneaza indexum minimului global
    	long int minim_global() {
    		long int minim = INT_MAX;
    		int index = 0;
    		for (long int i = 0; i < n; i++)
    			if (minim >= varf[i]) {
    				minim = varf[i];
    				index = i;
    			}
    		return index;
    	}

	long int get_result() {
		// este pastrat minimul local al pantei descendente
		long int minim = varf[0];
		long int timp = 0;
		// se retine indexul minimului global;
		// acest punct va fi punctul de intersectie dintre
		// viitorul sufix si prefix (punctul unde se termina
		// prefixul si incepe sufixul)
		int index = minim_global();
		// cu ajutorul acestui for se sapa panta descendenta;
		// se parcurge vectorul de inaltimi pana in punctul minim
		// unde se va opri prefixul. se actualizeaza progresiv minimul
		// local. Daca se intalenste un varf mai inalt ca cel minim,
		// atunci se doreste aducerea sa la inaltimea celui minim,
		// asta necesitand varf[i] - minim ore. Valoarea se retine
		// in variabila timp, care contine timpul total al lucrarii;
		// daca inaltimea varfului curent este mai mica ca cea a
		// varfului minim, atunci valoarea minimului se actualizeaza
        	for (int i = 0; i < index; i++) {
        		if (varf[i] >= minim) {
        			timp += varf[i] - minim;
        		} else {
        			minim = varf[i];
        			}
        	}
        	// este pastrat minimul local al pantei ascendente
        	minim = varf[n - 1];
        	// cu ajutorul acestui for se sapa panta ascendenta;
        	// acest for este analog primului for
        	for (int i = n - 1; i > index; i--) {
        		if (varf[i] >= minim) {
        			timp += varf[i] - minim;
        		} else {
        			minim = varf[i];
        			}
        	}
        	// se returneaza timpul total
        	return timp;
    	}

    	void print_output(long int result) {
    	    	ofstream fout("valley.out");
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
