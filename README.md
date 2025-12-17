# push_swap

A sorting algorithm project from 42/1337 that focuses on data structures, algorithms, and performance optimization.

## Overview

`push_swap` is a program that sorts a stack of integers using a limited set of operations and two stacks:

- **Stack A**: initialized with the input numbers  
- **Stack B**: empty at the start  

The goal is to sort stack A in ascending order while minimizing the number of operations.

The program prints the operations used to sort the stack.

## Rules

- Input must contain **only integers**
- No **duplicate** values are allowed
- If the input is already sorted, the program prints nothing
- On invalid input, the program prints `Error` followed by a newline

## Allowed Operations

### Swap
- `sa` : swap the first two elements of stack A
- `sb` : swap the first two elements of stack B
- `ss` : `sa` and `sb` at the same time

### Push
- `pa` : push the top element of stack B to stack A
- `pb` : push the top element of stack A to stack B

### Rotate
- `ra` : rotate stack A upwards
- `rb` : rotate stack B upwards
- `rr` : `ra` and `rb` at the same time

### Reverse Rotate
- `rra` : rotate stack A downwards
- `rrb` : rotate stack B downwards
- `rrr` : `rra` and `rrb` at the same time

## Algorithm

The program follows these main steps:

1. **Parsing & Validation**
   - check valid integers
   - check duplicates
   - handle overflow

2. **Indexing**
   - each value is replaced by its rank to simplify comparisons

3. **Sorting**
   - small stacks (2–5 elements) are handled with dedicated logic
   - bigger stacks use a Turk-style strategy:
     - push elements to stack B
     - compute target positions in stack A
     - calculate rotation costs
     - execute the cheapest move
     - final alignment of stack A

## Installation

```bash
make
```

Useful targets:
- `make` : build push_swap
- `make bonus` : build checker (bonus)
- `make clean`
- `make fclean`
- `make re`

## Usage

```bash
./push_swap 3 2 1
./push_swap "3 2 1"
```

Count operations:

```bash
ARG="3 2 1 6 5"
./push_swap $ARG | wc -l
```

## Examples

```bash
$ ./push_swap 2 1
sa

$ ./push_swap 3 2 1
sa
rra
```

## Checker

Using the official checker:

```bash
ARG="3 2 1"
./push_swap $ARG | ./checker_linux $ARG
```

Expected output:
- `OK` if sorted correctly
- `KO` if not sorted
- `Error` on invalid input

Bonus checker:

```bash
ARG="3 2 1"
./push_swap $ARG | ./checker $ARG
```