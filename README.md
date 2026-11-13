## 🖥️ OS Lab Practicals

### 📅 Weekly Experiments Performed

| Week | Experiment Description | Code |
| :---: | :--- | :--- |
| **1** | Demonstration of `fork()` System Call | [`week1_fork.c`](weekly-experiments/week1_fork.c) |
| **2** | Parent Process Computes Sum of Odd Numbers and Child Process Computes Sum of Even Numbers Using `fork()` | [`week2_odd_even_sum.c`](weekly-experiments/week2_odd_even_sum.c) |
| **3** | Demonstration of `wait()` System Call | [`week3_wait.c`](weekly-experiments/week3_wait.c) |
| **4** | Implementation of Orphan Process and Zombie Process | [`week4_orphan.c`](weekly-experiments/week4_orphan.c)<br>[`week4_zombie.c`](weekly-experiments/week4_zombie.c) |
| **5** | Implementation of Pipe | [`week5_pipe.c`](weekly-experiments/week5_pipe.c) |
| **6** | Implementation of FIFO / Named Pipe | [`week6_fifo_writer.c`](weekly-experiments/week6_fifo_writer.c)<br>[`week6_fifo_reader.c`](weekly-experiments/week6_fifo_reader.c) |
| **7** | Implementation of Message Queue | [`week7_msgq_sender.c`](weekly-experiments/week7_msgq_sender.c)<br>[`week7_msgq_receiver.c`](weekly-experiments/week7_msgq_receiver.c) |
| **8** | Implementation of Shared Memory | [`week8_shm_writer.c`](weekly-experiments/week8_shm_writer.c)<br>[`week8_shm_reader.c`](weekly-experiments/week8_shm_reader.c) |
| **9** | Implementation of First-Come, First-Served (FCFS) CPU Scheduling | [`week9_fcfs.c`](weekly-experiments/week9_fcfs.c) |
| **10** | Implementation of Shortest Job First (SJF) CPU Scheduling | [`week10_sjf.c`](weekly-experiments/week10_sjf.c) |
| **11** | Implementation of Priority Scheduling | [`week11_priority.c`](weekly-experiments/week11_priority.c) |
| **12** | Implementation of FIFO Page Replacement Algorithm | [`week12_fifo_page_replacement.c`](weekly-experiments/week12_fifo_page_replacement.c) |
| **13** | Implementation of Least Recently Used (LRU) Page Replacement Algorithm | [`week13_lru.c`](weekly-experiments/week13_lru.c) |

### ➕ Additional Experiments

| No. | Experiment Description | Code |
| :---: | :--- | :--- |
| **A1** | `fork()` and `exec()` system calls | [`extra1_fork_exec.c`](weekly-experiments/extra1_fork_exec.c) |
| **A2** | Implementation of Unix pipeline: `ls \| wc` | [`extra2_ls_wc_pipeline.c`](weekly-experiments/extra2_ls_wc_pipeline.c) |

**Compile & run:** `gcc weekly-experiments/week1_fork.c -o week1 && ./week1`  
For weeks 6–8 run the writer/sender and the reader/receiver (week 6: in two terminals, reader first).

---

### 📝 Lab Practice Questions

| Q.No. | Problem Statement |
| :---: | :--- |
| **1** | Write a C program using `fork()`. Create an array of 5 integers (e.g., `{10, 5, 20, 8, 2}`). The child process should find and print the minimum number in the array. The parent process should wait for the child to finish, and then find and print the maximum number in the array. |
| **2** | Write a C program using `pipe()`. The child process should send the string message "OS Lab Practical Exam" to the parent using the pipe. The parent process should read this message from the pipe and write it into a new file named `practical.txt`. |
| **3** | WAP to print fibonacci series upto n in child process & print factorial of n in parent process. |
| **4** | WAP in which the child process will call another child process. |
| **5** | Write a C program where no. is Prime or not in child. In parent process calculate factorial. Print cPid & Pid. |
| **6** | WAP to call a func^n fibonacci in child & Print fibonacci series upto n & in parent process call a func^n armstrong & Print all armstrong upto n. |
| **7** | WAP to find sum of elements in an array within child process & then check whether given sum is prime or not in parent process. |
