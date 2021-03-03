#include <iostream>
#include <queue>
#include <tuple>

typedef std::pair<int, int> xypair;

void fill2(int (&image)[100][100], int i, int j, int n, int m) {
    std::queue<xypair> queue;
    queue.push(xypair(i, j));

    while (!queue.empty()) {
        int i, j;
        std::tie(i, j) = queue.front();
        queue.pop();

        if (image[i][j] == 0b11) {
            image[i][j] = 0b01;

            if (i > 0)
                queue.push(xypair(i-1, j));
            if (i < n-1)
                queue.push(xypair(i+1, j));
            if (j > 0)
                queue.push(xypair(i, j-1));
            if (j < m-1)
                queue.push(xypair(i, j+1));
        }
    }
}

int main() {
    int n, m, caseNo;
    caseNo = 0;
    while (std::cin >> n) {
        caseNo++;

        std::cin >> m;

        int image[100][100];
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                char input;
                std::cin >> input;

                if (input == '-')
                    // 0b01 = visited star
                    // 0b11 = unvisited star
                    // 0b00 = not a star
                    image[i][j] = 0b11;
                else
                    image[i][j] = 0b00;
            }
        }

        // Run
        int count = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (image[i][j] == 0b11) {
                    // Not visited star
                    count++;
                    fill2(image, i, j, n, m);
                }
            }
        }

        std::cout << "Case "
                  << caseNo 
                  << ": "
                  << count
                  << std::endl;
    }
}