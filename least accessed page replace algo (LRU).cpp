// LRU (Least Recently Used)
// When a page needs to be replaced, remove the least recently used page.

#include <unordered_map>

int lruPageReplacement(const vector<int>& pages, int frames) {
    vector<int> memory;
    unordered_map<int, int> lastUsed;
    int pageFaults = 0;

    for (int i = 0; i < pages.size(); i++) {
        int page = pages[i];

        auto it = find(memory.begin(), memory.end(), page);
        if (it == memory.end()) {  // Page not found in memory
            if (memory.size() == frames) {  // If memory is full, remove LRU page
                int lruIndex = 0;
                for (int j = 1; j < memory.size(); j++) {
                    if (lastUsed[memory[j]] < lastUsed[memory[lruIndex]]) {
                        lruIndex = j;
                    }
                }
                memory.erase(memory.begin() + lruIndex);
            }
            memory.push_back(page);
            pageFaults++;
        }
        lastUsed[page] = i;  // Update last used time
    }
    return pageFaults;
}
