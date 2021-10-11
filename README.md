# PA-Tema
Exemple clasice de probleme rezolvate prin tehnicile Divide et Impera, Greedy si Dynamic Programming, si rezolvarile corespunzatoare

Am vrut sa folosesc limbajul c++ pentru a-mi scrie tema, deoarece acesta este limbajul pe care l-am folosit la laboratoare pana acum, si eram deja familiarizat cu a rezolva exercitii in el; de
asemenea, l-am mai folosit pentru diferite facilitati pe care le pune la dispoziitie fata de C de exemplu, precum functia sort() care sorteaza un vector si, pe langa ca deja era preimplementata,
mai si sorteaza vectorul in mod foarte eficient.
Am pornit de la modelul scheletului din laboratoare pentru a crea cate un fisier in care sa rezolv fiecare dintre probleme, deoarece eram familiarizat cu modul in care functioneaza acest schelet
si din cauza ca, fiind prima oara cand imi scriu o tema in c++, nu doream sa intampin erori neprevazute, ce sa nu tina de corectitudinea rezolvarii pe care o scriam.
Fiecare fisier cod respecta urmatoarea forma: se creeaza o clasa Task, iar in interiorul clasei acesteia exista 3 metode: read_input(), print_output(int result), get_result(). read_input() citeste
din fisier datele problemei si le retine in mod corespunator, print_output scrie rezultatul obtinut in get_result() in fisierul de iesire, iar get_result este metoda in care se afla rezolvarea
efectiva a cerintelor  




Exercitiul 1 (crypto):




	Am incercat sa rezolv acest exercitiu folosind tehnica greedy.

	Am facut urmatoarea observatie consultand exemplul din enuntul temei si testele atasate de arhiva temei: ca sa crestem productivitatea intregului lant de calculatoare cu o unitate,
atunci trebuie sa upgradam toate calculatoarele de productie minima. De exemplu, daca avem primele doua procesoare de productie 1, urmatoarele doua de productie 2, si alte doua de productie 3,
atunci productia totala este 1, adica influentata de calculatoarele de productie minima. Pentru a mari productia totala cu 1 unitate, trebuie sa marim productia calculatoarelor de productie minima
cu 1 unitate fiecare. Astfel, primele patru calculatoare vor fi de productie 4, iar celelalte doua de productie 3, productia totala crescand. Practi aceasta este ideea dupa care functioneaza 
proramul pe care l-am scris: pentru a ajunge mai usor la toate calculatoarele de productie minima din sir, le sortez crescator in functie de productie, (adica de exemplu sirul de procesoare de 
productie
2 1 3 1 2 va deveni: 1 1 2 2 3) si aplic ideea pe care am enuntat-o anterior. Astfel, pentru a obtine prodictia maxima, va fi nevoie de cel mult n iteratii in vectorul de procesoare, deci se va 
executa toata aceasta operatie in timp O(n). In interiorul for-ului se intampla urmatoarele lucruri: se tine minte in variabia cost_upgrade cat costa upgradarea tuturor calculatoarelor verificate 
pana in
momentul i. Daca productia maxima ce s-a inregistrat in cazul primelor i - 1 calculatoare este mai mica ca si productia calculatorului curent, atunci se verifica daca exista suficienti bani in buuget
pentru a aduce toate calculatoarele de  productie prod_max la aceeasi productie ca si productia lui i. Daca costurile necesare nu depasesc bugetul (buget), atunci se scade din buget cat e nevoie si 
se
actualizeaza productia maxima. In caz contrar, se vede daca exista suficienti bani in buget pentru a mari cat mai mult productia primelor calculatoare (este clar ca nu se poate mari pana la noua 
productie maxima din lipsa de buget, insa se poate mari suficient de mult pentru a mari productia maxima deja existenta), se actualizeaza prod_max si apoi se returneaza.
	Dupa ce se termina for-ul, exista posibilitatea sa mai existe bani in buget, si s-ar putea de asemenea ca acesti bani sa fie suficienti pentru a face upgrade-uri la calculatoarele din retea. 
Se actualizeaza prod_max si se returneaza.

	Complexitate: O (nlogn)




Exercitiul 2 (stocks):




	Am rezolvat aceasta problema folosind principiul programarii dinamice.
	
	Am observat ca aceasta problema este o problema din categoria RUCSAC de probleme ce se pot rezolva cu ajutorul programarii dinamice, categorie prezentata in cadrul primului labortor de dp.
Rezolvarea pe care am scris-o se aseamana cu cea prezentata in laborator, care rezolva problema rucsac cu o constrangere. Problema stocks este practic problema rucsac cu 2 constrangeri (loss si 
buget).
Daca in problema rucsac clasica trebuia sa punem obiecte intr-un rucsac astfel incat sa maximizam profitul total si sa nu depasim greutatea rucsacului, aici trebuie sa maximizam profitul unor 
actiuni,
astfel incat sa ne incadram intr-un buget (sa nu il depasim), si pierderea pe crae aceste actuini ne-o poate cauza sa nu fie mai mare decat un maxLoss (loss). Practic, ce e in plus fata de rezolvarea
problemei clasice, este ca de fiecare data cand calculam profitul maxim la pasul i trebuie sa tinem cont ca actiunea pe care o cumaram in acel moment sa nu fie prea costisitoare (sa avem destui bani 
pentru a ne-o permite) si ca pierderea posibila pe care ne-ar aduce-o, impreuna cu pierderile posibile ale celorlalte actiun cumparate pana atunci, sa nu fie mai mare de loss (cel citit din fisier).
Dupa ce am calculat solutiile tuturor problemelor mai mici sau egale ca problema noastra, o returnam, (fiind salvata la coordonatele n, loss, buget din matricea dp).

	Complexitate: O(n * loss * buget)


Exercitiul 3 (valley):




	Ca sa pot forma o panta trebuie sa am in vedere urmatoarele aspecte: Am necvoie de o panta descandenta (ca sa cobor), una ascendena (ca sa urc), si un punct in care sa termin cu coboratul si 
sa incep urcatul, adica un punct comun al sufixului cu prefixul. Cum panta ce coboara trebuie sa inceaa din varf[0], iar panta care urca sa se termine in varf[n - 1], trebuie sa gasesc punctul comun 
prefixului cu sufixul. Cum Gigel vrea sa termine in timp minim excavatul, nu are rost ca atunci cand gaseste acest punct sa il mai sape ca sa ii reduca altitudinea, asa ca punctul acesta, daca va fi 
cel mai de jos, este ideal pentru Gigel. Astfel caut elementul cu valoare minima din vector si il setez ca punctul comun al sufixului cu prefixul. Astfel, am toate punctele necesare ce sa imi arate 
unde trenuie sa inceapa si sa se sfarseasca cele 2 pante. Panta descendenta va incepe in primul punct din vector si se va termina in punctul minim, iar panta ascendenta va incepe in punctul minim si 
se va termina in ultimul punct din vector. Practic, intai salvez in index valoarea acestui punct minim, si apoi prin cele 2 for-uri din cod sap cele 2 pante. Panta ascendenta, la final, va fi cea 
care porneste din varf[0] si se termina in varf[index], iar panta ascendenta va fi cea care incepe din varf[index] si se termina in varf[n - 1]. Timpul total pentru excavat se salveaza in variabila 
timp, care se returneaza la final. Mai multe explicatii despre cum functioneaza cele 2 for-uri se gasesc in comentariile atasate de cod.
	
	Complexitate: O(n);

	
Exercitiul 4 (ridge):



	Folosesc si aici programarea dinamica.
	
	Ideea este urmatoarea: salvez intr-o matrice cat costa sa reduc din varfuri pentru a obtine oricare 2 varfuri distincte. Ca sa obtin varfuri distince, trebuie sa sap un anumit numar de 
unitati din fiecare. Aceste unitati pot fi egale cu 0, 1, 2, ... varf_maxim, insa cum o astfel de implementare ar necesita foarte multe resurse, iar timpul nu ar fi suficient pentru a-mi 
trece testele, ma folosesc de cazul foarte generos in care trebuie sa sap cel mult 2 unitati dintr-un varf pentru a-l duce la nivelul cerut. De fiecare data cand sunt in dreptul unui varf vad cat 
este nevoie sa decupez din el si din varful imediat precedent pentru a le face sa respecte proprietatea din enunt, calculez costul pentru cele 2 actiuni, iar costul insumat este costul total de care 
am nevoie. Am 3 cazuri: cazul in care e nevoie sa decupez 0 unitati din varful precedent, cazul in care e nevoie de 1 si cazul in care e nevoie de 2; fiecare dintre aceste actiuni se realizeaza cu 
cate un cost. Calculez minimul dintre aceste valori si il adaug la costul necesar pentru a prelucra creasta. In final, voi avea pe linia n - 1 (N din program) 3 candidati posibili pentru costul
minim: dp[N][0], dp[N][1], dp[N][2]. Il aleg pe cel minim si il returnez. 
	
	Complexitate: O(n)

https://www.geeksforgeeks.org/minimize-the-cost-to-make-all-the-adjacent-elements-distinct-in-an-array/?ref=rp
	
Exercitiul 5 (trigigel):




	Am folosit programarea dinamica pentru a rezolva acest exercitiu.
	
	Am facut urmatoarele observatii:
	
	- ca sa formam un sir valid de k elemente, este nevoie de un sir de k - 1 elemente valida, si de inca un element care concatenat la sir, sa dea un sir valid. (valid, adica sa respecte 
proprietatea din cerinta). 
	- pentru asta trebuie sa avem in vedere urmatoarele aspecte: dupa 0 sa se afle obligatoriu 1, dupa 1 sa se afle 2 si dupa 2 sa se afle 0.
	- de asemenea, numarul total de subsiruri cerute este egal cu numarul total de subsiruri ce se terminain 0, 1 si 2.
	- daca adaug un 0, atunci numarul subsirurilor ce se termina in 0 se mareste, insa al celor ce se termina in 1 si 2 ramane neschimbat; analog pentru 1 si 2.
	
	Deci pentru un numar k dat, numarul total de subsiruri de lungime cel mult k va fi egal cu (numarul de subsiruri ce se termina in 0) + (numarul de subsiruri ce se termina in 1) + (numarul de 
subsiruri ce se termina in 2). Consider ca cunosc numarul acestor siruri de la pasul k - 1. Daca al k-lea element este un 0, atunci secventele care se termina in 0 al secventei de k numere de acum 
va fi egala cu: (numarul de subsiruri care se termina in 0 de la pasul k - 1) + 1 (0 insusi este un subsir de un element care se termina in 0) + (numarul de subsiruri care se termina in 2 de la 
pasul k - 1, doearece acestor siruri li se va adauga cate un 0, si astfel vor forma siruri ce se termina in 0). NUmarul de siruri ce se termina in 1 si 2 ramane acelasi ca cel de la pasul anterior 
(adica k - 1). Analog pentru cazurile in care al k-lea element este 1 sau 2.
	Cand ajung la n, numarul de siruri cerute va fi stocat in dp[n] (dp este matricea folosita la rezolvare). Acest numar se returneaza.
	
	Complexitate: O(n)

Link-uri folosite:

https://ocw.cs.pub.ro/courses/pa/laboratoare/laborator-02
https://ocw.cs.pub.ro/courses/pa/laboratoare/laborator-03
https://ocw.cs.pub.ro/courses/pa/laboratoare/laborator-04
https://www.geeksforgeeks.org/minimize-the-cost-to-make-all-the-adjacent-elements-distinct-in-an-array/?ref=rp
