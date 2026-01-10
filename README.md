# push_swap

## 📌 Project Description

**push_swap** is an algorithmic project from the **42 Network**.  
The objective is to sort a list of integers in ascending order using **two stacks**
(`a` and `b`) and a **restricted set of operations**, while producing the **smallest
possible number of instructions**.

The program outputs the list of operations needed to sort the numbers — **not the
sorted result itself**.

---

## 🎯 Objectives

- Sort integers using stack operations only
- Optimize the number of moves
- Handle all invalid inputs safely
- Follow the **42 Norm**
- Avoid memory leaks and undefined behavior

---

## 🧠 Project Rules

- Stack **A** contains all numbers at start
- Stack **B** is empty
- Numbers must end sorted in **stack A**
- Only allowed operations may be used
- Each operation is printed on a new line

---

## ⚙️ Allowed Operations

| Operation | Description |
|---------|-------------|
| `sa` | Swap first two elements of stack A |
| `sb` | Swap first two elements of stack B |
| `ss` | `sa` and `sb` at the same time |
| `pa` | Push top of B to A |
| `pb` | Push top of A to B |
| `ra` | Rotate stack A up |
| `rb` | Rotate stack B up |
| `rr` | `ra` and `rb` at the same time |
| `rra` | Reverse rotate stack A |
| `rrb` | Reverse rotate stack B |
| `rrr` | `rra` and `rrb` at the same time |

---

## 🚨 Error Handling

The program prints **`Error\n`** and exits if:

- An argument is **not a valid integer**
- A number is outside the **INT_MIN / INT_MAX** range
- There are **duplicate values**
- Input is malformed (empty string, invalid signs, etc.)

Example:
```bash
./push_swap 1 2 2
Error
---

## 🖥️ Usage

### Compilation
```bash
make

Execution
```bash
./push_swap 4 67 3 87 23

Output Example :

pb
ra
sa
pa

📊 Performance Targets

The goal is to stay within these limits during evaluation:

Input Size	Maximum Moves
100 numbers	≤ 700
500 numbers	≤ 5500

🧪 Testing
Random test (100 numbers)
ARG=$(seq 1 100 | shuf | tr '\n' ' ')
./push_swap $ARG | wc -l

Random test (500 numbers)
ARG=$(seq 1 500 | shuf | tr '\n' ' ')
./push_swap $ARG | wc -l

Checker validation
./push_swap $ARG | ./checker $ARG


Expected output:

OK

🧩 Sorting Strategy
Small Inputs

2 elements → swap if needed

3 elements → hardcoded logic

5 elements → push smallest values to stack B, sort stack A, then push back

Large Inputs

Assign each number an index (ranking)

Divide stack A into chunks

Push chunks to stack B

Push back to stack A starting from the largest values

This strategy minimizes rotations and the total number of operations.

Project Structure  :
push_swap/
├── Makefile
├── push_swap.c
├── includes/
│   └── push_swap.h
├── parsing/
│   └── parsing.c
├── operations/
│   ├── swap.c
│   ├── push.c
│   ├── rotate.c
│   └── reverse_rotate.c
├── sorting/
│   ├── sort_small.c
│   └── sort_big.c
└── utils/
    └── stack_utils.c
🧠 Skills Learned

Stack manipulation

Algorithm optimization

Time and space complexity

Defensive programming

Memory management in C

Writing efficient parsing logic

Debugging complex logic under constraints
