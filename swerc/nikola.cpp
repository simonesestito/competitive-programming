#include <iostream>
#include <queue>
#include <unordered_set>
#include <map>

struct Path
{
    int cost;
    int jump;
    int index;

    Path(int _cost, int _jump, int _index) : cost(_cost), jump(_jump), index(_index) {}

    bool operator<(const Path &path) const
    {
        if (this->cost == path.cost)
        {
            if (this->jump == path.jump)
            {
                return this->index < path.index;
            }
            return this->jump < path.jump;
        }
        return this->cost < path.cost;
    }

    bool operator>(const Path &path) const
    {
        if (this->cost == path.cost)
        {
            if (this->jump == path.jump)
            {
                return this->index > path.index;
            }
            return this->jump > path.jump;
        }
        return this->cost > path.cost;
    }
};

int main()
{
    int n;
    std::cin >> n;

    int fees[n];
    for (int &fee : fees)
        std::cin >> fee;

    std::priority_queue<
        Path,
        std::vector<Path>,
        std::greater<std::vector<Path>::value_type>>
        queue;
    queue.push(Path(fees[1], 1, 1));

    std::unordered_set<int> alreadyTriedFrom[n]; // jumps

    Path curr = queue.top();
    while ((curr = queue.top()).index != n - 1)
    {
        queue.pop();

        auto &currAlreadyTried = alreadyTriedFrom[curr.index];
        bool alreadyTried = currAlreadyTried.find(curr.jump) != currAlreadyTried.end();
        if (alreadyTried)
        {
            continue;
        }
        else
        {
            currAlreadyTried.insert(curr.jump);
        }

        int forward = curr.index + curr.jump + 1;
        int back = curr.index - curr.jump;

        if (forward < n)
            queue.push(Path(curr.cost + fees[forward], curr.jump + 1, forward));

        if (back > -1)
            queue.push(Path(curr.cost + fees[back], curr.jump, back));
    }

    std::cout << curr.cost << std::endl;
}