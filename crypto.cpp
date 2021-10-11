#include <bits/stdc++.h>
using namespace std;
// clasa Object folosita
struct Object {
    int productie;
    int upgrade;
// constructoul
    Object(int _productie, int _upgrade)
        : productie(_productie)
        , upgrade(_upgrade) { }
};
// comparatorul folosit de sort, care sorteaza vectorul de obiecte
// crescator cu productivitatea
bool comparator(Object a, Object b) {
	return ((a.productie) < (b.productie));
}

class Task {
 public:
	void solve() {
        	read_input();
        	print_output(get_result());
    	}

 private:
	int n, b;
    	vector<Object> objs;
    	// citirea din fisierul de intrare
    	void read_input() {
        	ifstream fin("crypto.in");
        	fin >> n >> b;
        	for (int i = 0, productie, upgrade; i < n; i++) {
        	    	fin >> productie >> upgrade;
        	    	// in vectorul de obiecte se pun obiectele
            		objs.push_back(Object(productie, upgrade));
        	}
        	fin.close();
    	}

	int get_result() {
		// se sorteaza vectorul de procesoare crescator dupa productie
        	sort(objs.begin(), objs.end(), comparator);
        	// la inceput, costul de a face upgrade-uri si
        	// productia maxima sunt 0
        	// se vor mari in timpul parcurgerii vectorului
        	long int cost_upgrade = 0, prod_max = 0;
        	// se parcurge vectorul sortat
        	for (int i = 0; i < n; i++) {
        		// daca productia procesorului curent depaseste
        		// productia maxima inregistrata pana acum
        		if (objs[i].productie - prod_max > 0) {
        			// se verifica daca sunt suficienti bani in
        			// buget pentru a face upgrade la procesoare
        			// pentru ca productia lor sa devina egala
        			// cu noul prod_max, adica
        			// objs[i].productie;
        			// daca sunt bani, atunci se scade din buget
        			// suma necesara si se actualizeaza prod_max
        			if (1LL * cost_upgrade * (objs[i].productie - prod_max) <= 1LL * b) {
        				b -= cost_upgrade * (objs[i].productie - prod_max);
        				prod_max = objs[i].productie;
        			// in caz contrar, se fac cate upgrade-uri se
        			// pot face in limita bugetului, iar prod_max
        			// se returneaza
        			} else {
        				prod_max += b / cost_upgrade;
        				return prod_max;
        			}
        		}
        		// costul de a face upgrade creste odata cu avansarea
        		// in vector
        		cost_upgrade += objs[i].upgrade;
        	}
        	// daca mai raman bani in buget dupa ce s-a parcurs tot
        	// vectorul, se fac cate upgrade-uri se mai pot face
        	// in limita bugetului.
        	prod_max += b / cost_upgrade;
        	// returneaza prod_max;
        	return prod_max;
    	}
	// scrierea in fisierul de iesire
    	void print_output(int result) {
    	    	ofstream fout("crypto.out");
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
