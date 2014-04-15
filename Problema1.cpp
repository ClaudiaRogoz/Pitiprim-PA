	#include <iostream>
	#include <utility>
	#include <climits>	
	#include <fstream>
	#include <vector>
	#include <cmath>
	#include <stack>
	
	using namespace std;
	
	//un numar pitiprim poate incepe cu: 2, 3, 5, 7
	//se poate termina cu: 1,3,7,9
	int ending_prime[4] = {1, 3, 7, 9};
	int starting_prime[4] = {2, 3, 5, 7};
	
	//determina numarul de aparitii ale 
	//fiecarei cifre din cadrul numarului
	void remove_digit(long long n, int* v){
		
		while (n){
			v[n%10]++;
			n /= 10;
		}	
	}
	
	//true = daca parametrul este numar prim
	//false, altfel
	bool prime_heuristic(int prime_nu){
	    if (prime_nu %2 == 0) return false;
		    for (int i = 3; i<= sqrt(prime_nu); i+=2){
		        if(prime_nu %i == 0) return false;
	    }
	    return true;
	}
	
	int final;
	
	//algoritmul de backtarcking pentru generarea cifrelor  
	//temp = vector ce contine numarul de aparitii ale fiecarei cifre
	//l = stiva care va contine perechi de forma <ultima_cifra_adaugata;numarul final obtinut>
	//piti_largest = numarul maxim global obtinut in urma generarii tuturor combinatiilor posibile
	int next_prime(int *temp, stack< pair<int,int> > l,int &piti_largest){
		
		if(final < l.top().second)
			final = l.top().second;
		
		//pentru cele 4 cifre posibile care pot aparea
		//se face backtracking
		for(int i = 0 ; i< 4; i++){
			
			int next_in_line = ending_prime[i];
			
			//daca nu mai este nicio aparitie ramasa a cifrei curente
			if(temp[next_in_line] != 0){
				
				//ultima pereche adaugata in stiva (cifra;numar)
				int last_prime = l.top().first;
				int final_prime = l.top().second;
				
				pair<int, int> new_pair;
				
				new_pair = make_pair(next_in_line,final_prime*10 + next_in_line);
				
				//se verifica daca prin adaugarea cifrei curente se
				//obtine un numar prim
				if(prime_heuristic(new_pair.second)){
					
					//numarul de aparitii scade
					temp[next_in_line] --;
					
					//se updateaza maximul dintre numerele generate
					if(new_pair.second > piti_largest){ 
						piti_largest = new_pair.second;
						final = piti_largest;
		
						}
						
					//se updatezaza stiva
					l.push(new_pair);
					
					//se apeleaza recursiv functia de generare
					next_prime(temp, l, piti_largest);
					
					//efect de backtracking
					temp[next_in_line]++;
					l.pop();
				}
				
			}			
				
				
		}
		return final;	
	
	}
	
	//genereaza prima cifra cu care poate incepe un numar pitiprim
	int generate_prime(const int *v){
	
		int piti_largest = INT_MIN;
		int temp[10] = { };
		
		for(int i = 0; i<10 ;i++){
			temp[i] = v[i];
		}
		
		//se genereaza pe rand pentru cele 4 posibilitati: 2,3,5,7
		for(int i= 0; i<4; i++)
		{
			int first_in_line = starting_prime[i];
			
			//daca cifra apare numarului initial
			if(v[first_in_line] != 0){
			
					//se face o copie a vectorului de aparitii 
					//acesta va fi modificat
					for(int i = 0; i<10 ;i++){
						temp[i] = v[i];
					}
					
					//stiva care se initializeaza cu cifra generata 
					stack< pair<int,int> > stacka;
					pair<int,int> new_pair;
					
					//se scade numarul de aparitii ale cifrei curente
					temp[first_in_line] --;
					
					new_pair = make_pair(first_in_line, first_in_line);
					stacka.push(new_pair);
					
					//se apeleaza functia recursiva next_prime
					//pentru generarea urmatoarelor cifre
					int piti_prim = next_prime(temp, stacka, piti_largest);
					if(piti_largest < piti_prim)
						piti_largest = piti_prim;
			}
			
		}
		
		return piti_largest;
	}
	
	int main(int argc, char** argv){
		
		ifstream file("pitiprim.in");
		ofstream file_out("pitiprim.out");
		
        int n;
		long long number;
      
        if (file.is_open()){
			file>>n;
			for(int i =0; i< n; i++){
                
                file>>number;
                int used_prime[10] = { };
 
				remove_digit(number,used_prime);
				final = 0;
				int largest_piti = generate_prime(used_prime);				
				file_out<<largest_piti<<"\n";
			}
		}
		else cout<<"Unable to open file"<<"\n";

		file.close();
		file_out.close();
	}
