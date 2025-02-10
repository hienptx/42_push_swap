# :file_cabinet: Push_swap 

## :mag_right: Overview
Push_swap is an algorithmic project that sorts a list of 500 random numbers in ascending order using only a limited set of operations and two stacks (**Stack A** and **Stack B**). The goal is to achieve the sorting using the least number of operations.

## :gear: Allowed Operations
- **sa (swap a)**: Swap the first two elements of stack A.
- **sb (swap b)**: Swap the first two elements of stack B.
- **ss**: Perform sa and sb simultaneously.
- **pa (push a)**: Move the top element from stack B to stack A.
- **pb (push b)**: Move the top element from stack A to stack B.
- **ra (rotate a)**: Shift all elements of stack A up by one.
- **rb (rotate b)**: Shift all elements of stack B up by one.
- **rr**: Perform ra and rb simultaneously.
- **rra (reverse rotate a)**: Shift all elements of stack A down by one.
- **rrb (reverse rotate b)**: Shift all elements of stack B down by one.
- **rrr**: Perform rra and rrb simultaneously.

## :triangular_flag_on_post: Sorting Strategy
Push_swap uses different sorting strategies depending on the size of the list:
- **3 elements:** A simple **bubble sort**-like comparison-based sorting.
- **Up to 10 elements:** A variation of **selection sort** combined with push operations.
- **Up to 100 elements:** A **partitioning method** that splits the list into smaller sections and sorts efficiently.
- **500 elements:** Using a **chunking strategy**, which splits the numbers into smaller groups for optimized sorting, combined with a **radix sort**-based approach to minimize operations.

## :eyes: Example Workflow
1. **Splitting Stack A**: The elements are divided into smaller groups and pushed to Stack B.
2. **Sorting Small Chunks**: Sorting is performed within the small groups.
3. **Reassembling the Stack**: The elements are pushed back into Stack A in order.

## :art: Illustration

<p align="center">
  <a href="https://www.youtube.com/watch?v=K0LpDF8qIB">
    <img src="https://img.youtube.com/vi/K0LpDF8qIBw/0.jpg" alt="Watch the video\n" />
  </a>
</p>

## :floppy_disk: Installation & Usage 
![Sorting process](assets/push_swap_sorting.png)

### :wrench: Compilation
```bash
make
```
### :running: Running the Program
```bash
./push_swap "list of numbers"
```
Example:
```bash
./push_swap 3 2 1 5 4
```

## :rocket: Performance Optimization
- The algorithm minimizes the number of operations to stay within the required limits.
- Efficient use of stack operations ensures optimized performance for large data sets.

## :bust_in_silhouette: Contributors
- [Hien Pham](https://github.com/hienptx)

## :scroll: License
This project is licensed under the MIT License - see the LICENSE file for details.

