## 🖥️ OS Lab Practicals

### 📅 Lab Practicals

| Practical | Experiment Description | Code |
| :---: | :--- | :---: |
| **1** | Demonstration of `fork()` System Call | [`p1.c`](p1.c) |
| **2** | Parent Process Computes Sum of Odd Numbers and Child Process Computes Sum of Even Numbers Using `fork()` | [`p2.c`](p2.c) |
| **3** | Demonstration of `wait()` System Call | [`p3.c`](p3.c) |
| **4** | Implementation of Orphan Process and Zombie Process | [`p4.c`](p4.c) |
| **5** | Implementation of Pipe | [`p5.c`](p5.c) |
| **6** | Implementation of FIFO / Named Pipe | [`p6.c`](p6.c) |
| **7** | Implementation of Message Queue | [`p7.c`](p7.c) |
| **8** | Implementation of Shared Memory | [`p8.c`](p8.c) |
| **9** | Implementation of First-Come, First-Served (FCFS) CPU Scheduling | [`p9.c`](p9.c) |
| **10** | Implementation of Shortest Job First (SJF) CPU Scheduling | [`p10.c`](p10.c) |
| **11** | Implementation of Priority Scheduling | [`p11.c`](p11.c) |
| **12** | Implementation of FIFO Page Replacement Algorithm | [`p12.c`](p12.c) |
| **13** | Implementation of Least Recently Used (LRU) Page Replacement Algorithm | [`p13.c`](p13.c) |
| **14** | `fork()` and `exec()` System Calls *(Additional)* | [`p14.c`](p14.c) |
| **15** | Implementation of Unix Pipeline: `ls \| wc` *(Additional)* | [`p15.c`](p15.c) |

---

### 📝 Lab Practice Questions

| Q.No. | Problem Statement | Code |
| :---: | :--- | :---: |
| **1** | Write a C program using `fork()`. Create an array of 5 integers (e.g., `{10, 5, 20, 8, 2}`). The child process should find and print the minimum number in the array. The parent process should wait for the child to finish, and then find and print the maximum number in the array. | [`q1.c`](q1.c) |
| **2** | Write a C program using `pipe()`. The child process should send the string message "OS Lab Practical Exam" to the parent using the pipe. The parent process should read this message from the pipe and write it into a new file named `practical.txt`. | [`q2.c`](q2.c) |
| **3** | WAP to print fibonacci series upto n in child process & print factorial of n in parent process. | [`q3.c`](q3.c) |
| **4** | WAP in which the child process will call another child process. | [`q4.c`](q4.c) |
| **5** | Write a C program where no. is Prime or not in child. In parent process calculate factorial. Print cPid & Pid. | [`q5.c`](q5.c) |
| **6** | WAP to call a func^n fibonacci in child & Print fibonacci series upto n & in parent process call a func^n armstrong & Print all armstrong upto n. | [`q6.c`](q6.c) |
| **7** | WAP to find sum of elements in an array within child process & then check whether given sum is prime or not in parent process. | [`q7.c`](q7.c) |
