
#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>
#include <unordered_set>
// Ask the user for the number of pages and frames (available memory slots).
using namespace std;

int main() {
    int frames, n;
    cout << "Enter number of frames: ";
    cin >> frames;
    
    cout << "Enter number of pages: ";
    cin >> n;
    
    vector<int> pages(n);
    cout << "Enter page sequence: ";
    for (int i = 0; i < n; i++) {
        cin >> pages[i];
    }
    
    cout << "You entered: ";
    for (int page : pages) {
        cout << page << " ";
    }
    cout << endl;
    
    return 0;
}

// 1st algo FIFO
// Using Algorithm FIFO (First-In-First-Out) in which a queue to track the order of pages added.
// When a new page arrives:
// If there is space in memory, add it.
// If memory is full, remove the oldest page (first in the queue) and add the new one.
// Track page faults

// same as above with different name
void getUserInput(vector<int>& referenceString, int& numFrames) {
    int numPages;
    cout << "Enter the number of pages: ";
    cin >> numPages;

    cout << "Enter the reference string (space-separated): ";
    referenceString.resize(numPages);
    for (int i = 0; i < numPages; i++) {
        cin >> referenceString[i];
    }

    cout << "Enter the number of frames: ";
    cin >> numFrames;
}

// FIFO Page Replacement Algorithm
int fifoPageReplacement(const vector<int>& pages, int frames) {
    queue<int> memoryQueue;
    unordered_set<int> memorySet;
    int pageFaults = 0;

    for (int page : pages) {
        if (memorySet.find(page) == memorySet.end()) {
            if (memoryQueue.size() == frames) {
                int oldest = memoryQueue.front();
                memoryQueue.pop();
                memorySet.erase(oldest);
            }
            memoryQueue.push(page);
            memorySet.insert(page);
            pageFaults++;
        }
    }
    return pageFaults;
}


// 2nd algo (LRU)
// it removes the least recently used page.


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


// 3rd way of replcing page
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





// for displaying the result of FIFO
// there are so many algos that we are using in it so we have to display there results also (basically testing all these algos)
void testPageReplacementAlgorithms(const vector<int>& referenceString, int numFrames) {
    cout << "\nResults:\n";
    
    cout << "FIFO Page Faults: " << fifoPageReplacement(referenceString, numFrames) << "\n";
    cout << "LRU Page Faults: " << lruPageReplacement(referenceString, numFrames) << "\n";
    cout << "Optimal Page Faults: " << optimalPageReplacement(referenceString, numFrames) << "\n";

}



int main() {
    vector<int> referenceString;
    int numFrames;
    getUserInput(referenceString, numFrames);
    testPageReplacementAlgorithms(referenceString, numFrames);

    return 0;
}




