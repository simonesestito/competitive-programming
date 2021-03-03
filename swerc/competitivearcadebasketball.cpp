#include <iostream>
#include <unordered_map>

int main() {
    std::unordered_map<std::string, int> scores;

    int n, winPoints, m;
    std::cin >> n;
    std::cin >> winPoints;
    std::cin >> m;

    for (int i = 0; i < n; i++) {
        std::string name;
        std::cin >> name;
        scores[name] = 0;
    }

    int winCount = 0;

    for (int i = 0; i < m; i++) {
        std::string name;
        int points;
        std::cin >> name;
        std::cin >> points;

        if (scores[name] < winPoints) {
            scores[name] += points;
            if (scores[name] >= winPoints) {
                std::cout << name << " wins!\n";
                winCount++;
            }
        }
    }

    if (winCount == 0)
        std::cout << "No winner!\n";
}