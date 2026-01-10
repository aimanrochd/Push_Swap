push_swap
📌 Description

push_swap is an algorithmic project from the 42 Network.
The goal is to sort a list of integers using two stacks and a limited set of operations, while minimizing the number of moves.

The program prints the operations needed to sort the numbers in ascending order.

🎯 Objectives

Sort integers in ascending order

Use only allowed operations

Produce the smallest possible number of moves

Handle errors correctly

Respect 42 Norm

🧠 How It Works

Stack A contains all numbers at the start

Stack B is empty

Numbers are sorted by moving elements between stacks using predefined operations

The program outputs the operations line by line

⚙️ Allowed Operations
Operation	Description
sa	swap the first two elements of stack A
sb	swap the first two elements of stack B
ss	sa and sb simultaneously
pa	push the top of B onto A
pb	push the top of A onto B
ra	rotate stack A up
rb	rotate stack B up
rr	ra and rb simultaneously
rra	reverse rotate stack A
rrb	reverse rotate stack B
rrr	rra and rrb simultaneously
🖥️ Usage
Compilation
make

Execution
./push_swap 4 67 3 87 23

Output
pb
ra
sa
pa

🚫 Error Handling

The program prints Error and exits if:

Arguments are not integers

There are duplicate numbers

Input is invalid

If the stack is already sorted, nothing is printed.

🧩 Sorting Strategy
Small inputs

2 numbers → swap if needed

3 numbers → optimized hardcoded cases

5 numbers → push smallest values to stack B, sort, then push back

Large inputs

Assign each number an index (ranking)

Divide stack A into chunks

Push chunks to stack B

Push back to A in correct order

📊 Performance Goals
Input size	Expected operations
100 numbers	< 700
500 numbers	< 5500
🧪 Testing
Random test
ARG=$(seq 1 100 | shuf | tr '\n' ' ')
./push_swap $ARG | wc -l

Checker
./push_swap $ARG | ./checker $ARG

📁 Project Structure
push_swap/
├── Makefile
├── push_swap.c
├── includes/
│   └── push_swap.h
├── parsing/
│   └── parse_args.c
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

🧠 Skills Developed

Algorithm optimization

Stack-based sorting

Time complexity analysis

Memory management in C

Defensive programming

✅ Author

arochd
42 Student – Push_swap Project
