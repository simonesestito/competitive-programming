#include <iostream>
#include <unordered_set>
#include <string.h>

const int INF = 15000;

inline int min(const int &a, const int &b)
{
    return a < b ? a : b;
}

struct Node
{
    std::unordered_set<int> children;
    int horrorIndex = INF;
};

void walkFrom(Node *graph, const int &horrorId, std::unordered_set<int> &seenIds, const int newCost)
{
    Node &horror = graph[horrorId];
    bool updated = newCost < horror.horrorIndex;
    if (updated) {
        horror.horrorIndex = newCost;
    }

    if (!updated && seenIds.find(horrorId) != seenIds.end())
    {
        // Horror ID already seen. Avoid loops.
        return;
    }

    seenIds.insert(horrorId);

    for (const int &childId : horror.children)
    {
        walkFrom(graph, childId, seenIds, newCost + 1);
    }
}

int main()
{
    int n, h, l;
    std::cin >> n >> h >> l;

    int horrors[h];
    for (int &horror : horrors)
        std::cin >> horror;

    Node graph[n];

    for (int _ = 0; _ < l; _++)
    {
        int aIndex, bIndex;
        std::cin >> aIndex >> bIndex;
        graph[aIndex].children.insert(bIndex);
        graph[bIndex].children.insert(aIndex);
    }

    // Walk
    for (const int &horror : horrors)
    {
        std::unordered_set<int> seenIds;
        walkFrom(graph, horror, seenIds, 0);
    }

    // Find max
    int maxId = 0;
    for (int i = 1; i < n; i++)
    {
        if (graph[i].horrorIndex > graph[maxId].horrorIndex)
            maxId = i;
    }

    std::cout << maxId << std::endl;
}