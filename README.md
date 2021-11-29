# Banker-s-Assignment
Banker's Deadlock assignment for Operating Systems course:
## 🧐 About <a name = "about"></a>
Considering a system with five processes P0 through P4 and three resources of type A, B, C. Resource type A has 10 instances, B has 5 instances and type C has 7 instances. Suppose at time t0 following snapshot of the system has been taken:     
![image](https://user-images.githubusercontent.com/90359108/143931923-a512946a-419e-4c2b-aad7-f6e75eceb4c3.png)

Implement the Banker’s algorithm to answer the following question：Is the system in a safe state? If Yes, then what is the safe sequence?

## 🏁 Getting Started <a name = "getting_started"></a>
These instructions will get you a copy of the project up and running on your local machine for development and testing purposes.

### Prerequisites
g++ compiler
Compiled on Ubuntu 20.04

Test for g++ version
```
g++ --version
```
Installing g++ if not already installed
```
sudo apt update
sudo apt install g++
```
Confirming g++ installation
```
g++ --version
```

### Installing
1. Clone the Repository

```
git clone https://github.com/jhartm26/Banker-s-Assignment.git
```
2. Compile and run the program

```
g++ bankersDead.cpp -o run
./run
```
3. Exit the program after receiving results

```
Hit ctrl+c
```

## 🎈 Usage <a name="usage"></a>
This project is an implementation of the producer consumer problem using semaphores and shared memory.

### Example Output

![ExampleOutput2](https://user-images.githubusercontent.com/90359108/143932513-73e4e9ef-9628-4ae9-8e39-55e1c0e1748b.png)

