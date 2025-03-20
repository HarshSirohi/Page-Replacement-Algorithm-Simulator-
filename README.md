# Page-Replacement-Algorithm-Simulator-
This is a C++-based simulator designed to test and compare different page replacement algorithms used in operating systems. It helps analyze how efficiently each algorithm manages memory pages by tracking page faults, hits, and performance metrics.
basic input and output file === Ask the user for the number of  pages and frames (available memory slots).


This module is responsible for implementing and executing various **page replacement algorithms** used in operating systems. It processes the **page reference string** and manages memory frames according to the chosen algorithm, keeping track of **page faults, hits, and efficiency**.

## Responsibilities
1. **Receive Input Data:**
   - Accept the number of frames and the page reference string from **Module 1**.
2. **Execute Page Replacement Algorithms:**
   - Implement FIFO, LRU, OPT, and other algorithms.
   - Simulate memory management step by step.
3. **Track Performance Metrics:**
   - Count **page faults** and **hits**.
   - Maintain a history of frame states.
4. **Prepare Data for Output:**
   - Format results for **Module 3** to display.

## Step-by-Step Execution
### Step 1: Receive Input
- Fetch the **number of frames** and **reference string**.
- Store these values in appropriate data structures (e.g., arrays, vectors).

### Step 2: Choose Algorithm
- Based on user selection, execute one or more of the following algorithms:

#### FIFO (First-In-First-Out)
- Replace the **oldest page** in memory when a new page arrives.
- Uses a **queue** to track the order of arrival.
- Simple but may suffer from **Belady’s anomaly**.

#### LRU (Least Recently Used)
- Replaces the **least recently accessed** page.
- Uses a **stack or hashmap** for tracking usage history.
- More efficient than FIFO but requires additional bookkeeping.

#### Optimal (OPT)
- Replaces the page that **will not be used for the longest time in the future**.
- Requires **future knowledge**, so it's mostly used for theoretical comparison.

#### MRU (Most Recently Used)
- Opposite of LRU; replaces the **most recently accessed page**.
- Useful in specific workloads where recent pages are less likely to be needed.

#### LFU (Least Frequently Used)
- Replaces the **least frequently accessed** page.
- Uses a **counter** to track usage frequency.

### Step 3: Track Performance
- **Count page faults** whenever a new page is loaded.
- **Track hits** when a requested page is already in memory.
- Maintain a **log of frame changes** for debugging and visualization.

### Step 4: Prepare Results for Output
- Compile **total page faults and hit ratio**.
- Store results in a structured format.
- Pass data to **Module 3** for display.

## Data Flow
1. **Input from Module 1** → Frames & Reference String
2. **Processing in Module 2** → Run Algorithms, Track Metrics
3. **Output to Module 3** → Results & Performance Comparison

## Next Steps
- Ensure integration with Module 1 & 3.
- Optimize data structures for performance.
- Expand algorithm support if needed.

This module is the **core of the simulator**, ensuring that different page replacement methods can be tested and compared effectively.


