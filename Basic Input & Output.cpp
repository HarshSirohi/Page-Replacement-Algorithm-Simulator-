
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
// for displaying the result of FIFO
void testPageReplacementAlgorithms(const vector<int>& referenceString, int numFrames) {
    cout << "\nResults:\n";
    cout << "FIFO Page Faults: " << fifoPageReplacement(referenceString,numFrames) << "\n";
}

int main() {
    vector<int> referenceString;
    int numFrames;
    getUserInput(referenceString, numFrames);
    testPageReplacementAlgorithms(referenceString, numFrames);

    return 0;
}




