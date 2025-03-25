# Page-Replacement-Algorithm-Simulator-
# Efficient Page Replacement Algorithm Simulator

***** What is This?**********************************************************************************************************************************************
The **Efficient Page Replacement Algorithm Simulator** is a C++-based project that simulates and compares different page replacement algorithms used in operating systems. It helps analyze how memory management works and which algorithm performs best under various conditions.


***** Why Are We Using It? *****************************************************************************************************************************************
In operating systems, memory is limited, and multiple processes require space to execute. When the required memory is full, the OS must replace an old page with a new one. **Choosing the right page to replace is crucial for efficiency**—this is where page replacement algorithms come in. Our simulator helps understand and compare these algorithms to find the best approach.


***** Technologies & Tools Used*****************************************************************************************
- **Programming Language:** C++ ,HTML,CSS
- **Data Structures:** Arrays, Queues, Stacks, Maps
- **Algorithms Implemented:** FIFO, LRU, OPT,
- **Input Handling:** User input for reference string and memory frames


##  Purpose of Each Component:

 ***** Module 1: Input Handling******************************************************************************************
->>**What It Does:**
- Takes user input for the number of memory frames.
- Accepts a page reference string (manual input or random generation).
- Validates inputs and sends data to processing.

***** Module 2: Algorithm Processing***************************************************************************************
->> **What It Does:**
- Implements multiple page replacement algorithms.
- Tracks page faults, memory state changes, and hits.
- Compares results from different algorithms.

***** Module 3: Output & Visualization**************************************************************************************
-> **What It Does:**
- Displays page fault count and hit ratio.
- Compares different algorithms side by side.
- (Optional) Provides graphical visualization of memory usage.

*****  The Problem We Are Solving********************************************************************************************
- **Limited Memory:** Systems cannot load all requested pages at once.
- **High Page Faults:** Poor algorithm choice leads to performance issues.
- **Inefficient Memory Use:** Some algorithms perform better depending on the workload.

***** Expected Outcome ******************************************************************************************************
- Understanding **which algorithm performs best** under different conditions.
- Reducing **page faults** and optimizing **memory utilization**.
- Learning **how real-world OS memory management works**.

***** Future Enhancements*****************************************************************************************************
- Adding more algorithms for testing.
- Implementing a GUI for better visualization.
- Optimizing execution speed and memory usage.








