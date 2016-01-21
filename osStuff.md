Stuff related to OS
===================

Difference between core and processor
-------------------------------------
A core is usually the basic computation unit of the CPU - it can run a single program context (or multiple ones if it supports HW threads such as hyperthreading on intel CPUs), maintaining the correct program state, registers, and correct execution order, and performing the operations through ALUs. For optmization purposes, a core can also hold on-core caches with copies of frequently used memory chunks.
A CPU may have one or more cores to perform tasks at a given time. These tasks are usually software processes and threads that the OS schedules. Note that the OS may have many threads to run, but the CPU can only run at a given time X such tasks, where X = number cores * number of HW-threads per core. The rest would have to wait for the OS to schedule them whether by preempting currently running tasks or any other means.
In addition to the one or many cores, the CPU will include some interconnect that connects the cores to the outside world, and usually also a large "last-level" shared cache. There are multiple other key elements required to make a CPU work, but their exact locations may differ according to design. You'll need a memory controller to talk to the memory, IO controllers (display, PCIe, USB, etc..). In the past these elements were outside the CPU, in the complementary "chipset", but most modern design have integrated them into the CPU.
In addition the CPU may have an integrated GPU, and pretty much everything else the designer wanted to keep close for performance, power and manufacturing considerations. CPU design is mostly trending in to what's called "SOC" - system on chip.
This is a "classic" design, used by most modern general purpose devices (client PC, servers, and also tablet and smartphones). You can find more elaborate designs, usually in the academy, where the computations is not done in basic "core-like" units.

Memory Layout of C Programs
---------------------------
https://www.quora.com/What-is-the-stack-and-heap-memory-architecture-used-by-C

Unix And C/C++ Runtime Memory Management For Programmers
--------------------------------------------------------
http://csserver.evansville.edu/~amr63/linux/unix_programming/unix-memory/unix-memory.html

Difference between API and ABI
------------------------------
- *API*: Application Program Interface
    - This is the set of public types/variables/functions that you expose from your application/library.
    - In C/C++ this is what you expose in the header files that you ship with the application.
- *ABI*: Application Binary Interface
    - This is how the compiler builds an application.
    - It defines things (but is not limited to):
        - How parameters are passed to functions (registers/stack).
        - Who cleans parameters from the stack (caller/callee).
        - Where the return value is placed for return.
        - How exceptions propagate.

- Sources:
    - https://en.wikipedia.org/wiki/Application_binary_interface
    - http://stackoverflow.com/questions/3784389/difference-between-api-and-abi

