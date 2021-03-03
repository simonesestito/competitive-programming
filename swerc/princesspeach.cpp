#include <iostream>
#include <string.h>

int main() {
    int n, y;
    std::cin >> n;
    std::cin >> y;

    int numsCount = 0;
    // Are there repetitions?!?

    bool nums[n];
    for (bool &num : nums) {
        num = false;
    }

    for (int i = 0; i < y; i++) {
        int j;
        std::cin >> j;
        if (!nums[j]) {
            nums[j] = true;
            numsCount++;
        }
    }

    for (int i = 0; i < n; i++) {
        if (!nums[i])
            std::cout << i << '\n';
    }

    std::cout << "Mario got "
              << numsCount
              << " of the dangerous obstacles."
              << std::endl;
}