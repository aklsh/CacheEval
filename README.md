CacheEval: Evaluating the L1 cache parameters
=============================================

Pre-requisites
--------------
python3, gcc, x86_64 processor

**DISCLAIMER: This works only for x86_64 processors as the program uses instructions specific to that architecture. Make sure that your processor supports the RDTSC instruction.**

Notes
-----
- To build and run program: `make eval`
  - You will have to edit `inc/options.h` to define `STRIDE` and `ASSOC` values, as well as comment/uncomment whether to calculate Block Size and/or Associativity.
  - To use the data to plot figures, tee the output to data/data_\*.txt and **remove the unnecessary comment lines**. It is critical to do so, and the plotting program will throw an error otherwise. Refer to plot.py for exact data file(s) name(s).
- To generate plots: `make plots`
- To generate report: `make pdf`

References
----------
[1] INTEL CORPORATION. Intel® 64 and IA-32 Architectures Software Developer’s Manual Combined Volumes: 1, 2A, 2B, 2C, 2D, 3A, 3B, 3C, 3D, and 4, 2021.
