class Solution {
public:
    int numBusesToDestination(vector<vector<int>>& routes, int source, int target) {
        if (source == target) {
            return 0; // Already at the target
        }

        unordered_map<int, vector<int>> stopToRoutes;
        for (int i = 0; i < routes.size(); ++i) {
            for (int stop : routes[i]) {
                stopToRoutes[stop].push_back(i);
            }
        }

        queue<int> bfsQueue;
        unordered_set<int> visitedStops;
        unordered_set<int> visitedRoutes;

        bfsQueue.push(source);
        visitedStops.insert(source);

        int busCount = 0;

        while (!bfsQueue.empty()) {
            int stopsInLevel = bfsQueue.size();

            for (int i = 0; i < stopsInLevel; ++i) {
                int currentStop = bfsQueue.front();
                bfsQueue.pop();

                for (int routeIndex : stopToRoutes[currentStop]) {
                    if (visitedRoutes.count(routeIndex)) {
                        continue;
                    }

                    visitedRoutes.insert(routeIndex);

                    for (int nextStop : routes[routeIndex]) {
                        if (nextStop == target) {
                            return busCount + 1;
                        }

                        if (!visitedStops.count(nextStop)) {
                            visitedStops.insert(nextStop);
                            bfsQueue.push(nextStop);
                        }
                    }
                }
            }

            busCount++;
        }

        return -1; // No path found
    }
};