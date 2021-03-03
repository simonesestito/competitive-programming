#include <iostream>

// https://imgur.com/a/kxUu2KB
// ^^^^^^^^

int main() {
    int n, m;
    std::cin >> n; // swathers
    std::cin >> m; // stages

    int workers[n][m];
    // No init required
    // never accessed before init

    for (int i = 0; i < n; i++) {
        // Incremental cost calculation
        for (int j = 0; j < m; j++) {
            int pij;
            std::cin >> pij;

            // Add offset time / waiting time
            // Safe access in arrays
            if (i > 0 && j == 0)
                pij += workers[i-1][j];
            else if (i == 0 && j > 0)
                pij += workers[i][j-1];
            else if (i > 0 && j > 0) {
                if (workers[i-1][j] > workers[i][j-1])
                    pij += workers[i-1][j];
                else
                    pij += workers[i][j-1];

            }

            workers[i][j] = pij;
        }
        std::cout << workers[i][m-1] << ' ';
    }

    std::cout << std::endl;
}