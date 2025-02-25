#include <iostream>
#include <vector>
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
