#include "AntColonyTSL.h"
#include "../Graph.h"
#include "../GraphAlgorithms.h"

using namespace s21;

int main() {
    Graph G;
    G.LoadGraphFromFile("1.txt");

    double alpha = 0.8, beta = 1.2, rho = 0.5, q_k = 0.6, d_ph = 0.6;
    int iter = 500, a_c = 1;

    int proc = 0;

    for (q_k = 0.6; q_k < 1.5; q_k += 0.2) {
        for (d_ph = 0.4; d_ph < 1.3; d_ph += 0.2, ++proc) {
            if ([&](){
                for (int k = 0; k < 30; ++k) {
                    AntColony<int> ac(G.GetMatrix(), alpha, beta, rho, iter, a_c, q_k, d_ph);
                    if (ac.Solve().distance != 253) {
                        return false;
                    }
                }
                return true;
            }()) {
                std::cout << '\t' << q_k << ' ' << d_ph << ' ' << iter << '\n';
            }
            std::cout << (double)proc * 100.0 / 25.0 << "%\n";
        }
    }

    return 0;
}
