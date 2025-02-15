# 🔄 Push_swap

## 📋 Overview
Push_swap is a sorting algorithm project that sorts data using two stacks and a limited set of operations. The goal is to sort the numbers in stack A in ascending order using the most efficient sequence of operations possible.

## 💻 Installation

```bash
# Clone the repository
git clone https://github.com/fatheddine-bicane/push_swap.git
cd push_swap

# Compile push_swap
make

# Compile checker (bonus)
make checker
```

## 🎯 Available Operations

| Operation | Description |
|-----------|-------------|
| `sa` | Swap first 2 elements of stack A |
| `sb` | Swap first 2 elements of stack B |
| `ss` | `sa` and `sb` at the same time |
| `pa` | Push top element from stack B to stack A |
| `pb` | Push top element from stack A to stack B |
| `ra` | Rotate stack A (first becomes last) |
| `rb` | Rotate stack B (first becomes last) |
| `rr` | `ra` and `rb` at the same time |
| `rra` | Reverse rotate stack A (last becomes first) |
| `rrb` | Reverse rotate stack B (last becomes first) |
| `rrr` | `rra` and `rrb` at the same time |

## 🚀 Usage

### Push_swap Program
```bash
# Format
./push_swap <numbers>

# Examples
./push_swap 2 1 3 6 5 8
./push_swap "1 2 3 4 5"
```

### Checker Program
```bash
# Format
./push_swap <numbers> | ./checker <numbers>

# Examples
./push_swap 4 67 3 87 23 | ./checker 4 67 3 87 23
echo -e "sa\npb\nrr\npa\n" | ./checker 4 67 3 87 23
```

## 💡 Examples with Visualization

### Example 1: Simple Sort
```bash
$> ./push_swap 3 1 2
sa
ra
```

Initial state:
```
Stack A: 3 1 2
Stack B: (empty)
```

Final state:
```
Stack A: 1 2 3
Stack B: (empty)
```

### Example 2: With Checker
```bash
$> ./push_swap 4 2 1 3 | ./checker 4 2 1 3
OK
```

## 📊 Performance

| Stack Size | Max Operations |
|------------|---------------|
| 3 numbers  | ≤ 3 ops      |
| 5 numbers  | ≤ 12 ops     |
| 100 numbers| ≤ 700 ops    |
| 500 numbers| ≤ 5500 ops   |

## ⚙️ Compilation Commands

```bash
# Main program
make        # Compiles push_swap
make clean  # Removes object files
make fclean # Removes object files and executable
make re     # Rebuilds the program

# Checker program
make checker      # Compiles checker
make clean_checker# Removes checker object files
```

## 🧪 Testing

```bash
# Test with 3 numbers
ARG="2 1 3"; ./push_swap $ARG | ./checker $ARG

# Test with random numbers
ARG=$(shuf -i 1-100 -n 100 | tr "\n" " "); ./push_swap $ARG | ./checker $ARG

# Count number of operations
./push_swap $ARG | wc -l
```

## 🔍 Error Handling

The program handles various error cases:
- Duplicate numbers
- Non-numeric input
- Numbers outside INT range
- Missing arguments

```bash
$> ./push_swap 1 2 2 3
Error
$> ./push_swap 1 2 abc 3
Error
```

## Author
Created by [fatheddine-bicane]
