Tema2-PA
========
Rogoz Claudia 
321CA

Problema 1 


Pentru implementare m-am folosit de urmatoarele functii:

-remove_digiti: primeste ca parametrii numarul de procesat, impreuna cu un vector care va retine numarul de aparitii ale fiecarei cifre 

-prim_heuristic: functie care verifica daca un anumit numar primit ca parametru este prim sau nu 

-next_prime: algoritmul aplicat este cel de backtracking; cifrele din care se alege sunt : 1, 3, 7, 9. (un numar prim se poate termina numai cu aceste cifre);  se genereazza recursiv toate combinatiile posibile cu cele 4 cifre si numarul corespunzator de aparitii; Pentru aceasta m-am folosit de o stiva de perechi de forma <ultima cifra adaugata; numarul prim obtinut prin adaugarea ultimei cifre>

-generate_prime: genereaza prima cifra cu care poate incepe un numar pitiprim;
apeleaza functia next_prime prntru generarea urmatoarelor cifre

In functia main am citit pe rand numerele din fisierul de intrare pitiprim.in. 
Datele de iesire sunt scrise in "pitiprim.out"
