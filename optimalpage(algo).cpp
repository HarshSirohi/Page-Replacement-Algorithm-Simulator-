// Optimal Page Replacement
// in this we Look into the future and remove the page that won’t be needed for the longest time
int optimalPageReplacement(const vector<int>& pages, int frames) {
    vector<int> memory;
    int pageFaults = 0;

    for (int i = 0; i < pages.size(); i++) {
        int page = pages[i];

        auto it = find(memory.begin(), memory.end(), page);
        if (it == memory.end()) {  // Page not found in memory
            if (memory.size() == frames) {  // If memory is full, find the page to remove
                int farthestIndex = -1, removeIndex = -1;
                for (int j = 0; j < memory.size(); j++) {
                    int nextUse = pages.size();
                    for (int k = i + 1; k < pages.size(); k++) {
                        if (pages[k] == memory[j]) {
                            nextUse = k;
                            break;
                        }
                    }
                    if (nextUse > farthestIndex) {
                        farthestIndex = nextUse;
                        removeIndex = j;
                    }
                }
                memory.erase(memory.begin() + removeIndex);
            }
            memory.push_back(page);
            pageFaults++;
        }
    }
    return pageFaults;
}
