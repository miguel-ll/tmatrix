# tmatrix - fully-featured lib for matrix manipulation

## Required libraries

- `stdio.h` - printf.
- `math.h` - fabs.
- `stdlib.h` - srand.
- `time.h` - time. 

## functions

- `int pivot(int N, int A[][N], int row)` - returns the pivot in the desired row of a square matrix A of order N.
- `void init_m(int N, int A[][N], int num)` - fill a square matrix of order N with the number num.
- `void identity(int N, int A[][N])` - create an identity matrix of order N.
- `void multiply_m(int N, int A[][N], int B[][N], int C[][N])` - multiply a square matrix A by B and store the resulting matrix on C. C = **AB**.
- `void scalar_mult(int num, int N, int A[][N], int B[][N])` - multiply a square matrix A of order N by a scalar num, and store the resulting matrix on B. B = num**A**.
- `void sum_m(int N, int A[][N], int B[][N], int C[][N])` - sum a square matrix A of order N by B, and store the resulting matrix on C. C = **A**+**B**.
- `void sub_m(int N, int A[][N], int B[][N], int C[][N])` - subtract a square matrix A of order N by B, and store the resulting matrix on C. C = **A**+**B**.
- `void transpose(int N, int A[][N], int B[][N])` - transpose a square matrix A of order N into B. B = A<sup>T</sup>.
- `int bareiss_det(int N, int A[][N])` - returns the determinant of a square matrix A of order N using the bareiss algorithm. **Note that the modified matrix A will not be in its echelon form. This goes for leibniz_det and gauss_elim as well.**
- `int leibniz_det(int num, int A[][num])` - returns the determinant of a square matrix A of order num using the leibniz formula for determinants. **Note that this will only work if num is 2, 3, or 4. Otherwise, the function will return zero.** 
- `double gauss_elim(int n, double a[][n])` - returns the determinant of a square matrix a of order n using gauss elimination.
- `void double_print_m(int m, int n, double matrix[m][n])` - prints a m *x* n double matrix. 
- `void print_m(int m, int n, int matrix[m][n])` - prints a m *x* n int matrix. 
- `void double_copy_m(int m, int n, double matrix1[m][n], double matrix2[m][n])` - copy a m *x* n double matrix1 into a m *x* n double matrix2.
- `void copy_m(int m, int n, int matrix1[m][n], int matrix2[m][n])` - copy a m *x* n int matrix1 into a m *x* n int matrix2.
- `void make_double(int m, int n, int matrix1[m][n], double matrix2[m][n])` - turns the m *x* n int matrix1 into a m *x* n double matrix2.
-  `void make_int(int m, int n, double matrix1[m][n], int matrix2[m][n])` - turns the m *x* n double matrix1 into a m *x* n int matrix2.
-  `void random_m(int m, int n, int z, int mat[m][n])` - fill a m *x* n matrix with random numbers from 1 to z.

## TODO

- vector addition, subtraction, multiplication (dot product, cross product)
- more vector operations?
- rank matrix
- inverse
- solve a linear system

## How this works mathematically
