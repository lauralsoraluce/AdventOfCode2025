#include <iostream>
#include <string>
#include <cmath>
#include <set>
using namespace std;

int main() {
    long long start, end;
    char discard;
    long long count = 0;

    while (cin >> start >> discard >> end) {

        if (start <= end) {
            set<long long> seen;

            int start_len = to_string(start).length();
            int end_len = to_string(end).length();

            // CORRECCIÓN 1: Bucle para manejar saltos de longitud (ej: 99 a 100)
            for (int curr_len = start_len; curr_len <= end_len; curr_len++) {
                
                int half_len = curr_len / 2;
                long long root;

                // CORRECCIÓN 2: Menor o IGUAL (<=) para detectar mitades exactas
                for (int i = 1; i <= half_len; i++) {
                    
                    if (curr_len % i == 0) {
                        
                        // Si estamos en la longitud inicial, usamos 'start' como base.
                        // Si hemos saltado (ej: buscando numeros de 3 cifras y start era de 2),
                        // la raíz debe empezar en el mínimo posible (ej: 1, 10, 100...).
                        if (curr_len == start_len) {
                            root = stoll(to_string(start).substr(0, i));
                        } else {
                            // Truco matemático para obtener 1, 10, 100...
                            root = pow(10, i - 1);
                        }

                        bool searching = true;
                        while (searching) {
                            string candidate_str = to_string(root);
                            
                            // Si la raíz crece más que el patrón permitido, paramos
                            if (candidate_str.length() != i) {
                                searching = false;
                            } else {
                                string candidate_str2 = "";
                                for (int j = 0; j < curr_len / i; j++) {
                                    candidate_str2 += candidate_str;
                                }
                                
                                long long candidate = stoll(candidate_str2);
                                
                                if (candidate > end) {
                                    searching = false;
                                } else {
                                    if (candidate >= start) {
                                        seen.insert(candidate);
                                    }
                                    root++;
                                }
                            }
                        }
                    }
                }
            }
            
            // Sumamos los únicos encontrados en este rango
            for (long long id : seen) {
                count += id;
            }
        }
        cin >> discard;
    }

    cout << "The sum of invalid IDs is: " << count << endl;
    return 0;
}