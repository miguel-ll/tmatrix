#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>
//#define N 4
//#define N 3

int pivot(int N, int A[][N], int row) {
	if (row > N-1) return 400;
	for(int i=0;i<N;i++) {
		if(A[row][i] != 0) {
			return A[row][i];
		}
	}
	return 0;
}

int mypow(int base, int exponent)
{
int result = 1;
for(;exponent>0;exponent--)
{
result *= base;
}
return result;
}

void init_m(int N, int A[][N], int num) {
	for(int i=0;i<N;i++)
	    for(int j=0;j<N;j++)
	        A[i][j] = num;
}

void identity(int N, int A[][N]) {
	init_m(N,A,0);
	for(int i=0; i<N;i++)
	    A[i][i] = 1;
}

void multiply_m(int N, int A[][N], int B[][N], int C[][N]) {
    init_m(N,C,0);
    int i, j, k;
    for (i = 0; i < N; i++) {
        for (j = 0; j < N; j++) {
            for (k = 0; k < N; k++)
                C[i][j] += A[i][k] * B[k][j];
        }
    }
}

void scalar_product(int num, int N, int A[][N], int B[][N]) {
	int i, j;
	for(i = 0; i < N; i++)
	    for(j = 0; j < N; j++)
	        B[i][j] = num * A[i][j];
}

void sum_m(int N, int A[][N], int B[][N], int C[][N]) {
	    for (int i = 0; i < N; i++)
            for (int j = 0; j < N; j++)
                C[i][j] = A[i][j] + B[i][j];
}

void sub_m(int N, int A[][N], int B[][N], int C[][N]) {
	    for (int i = 0; i < N; i++)
            for (int j = 0; j < N; j++)
                C[i][j] = A[i][j] - B[i][j];
}

void transpose(int N, int A[][N], int B[][N]) {
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            B[i][j] = A[j][i];
}

void double_transpose(int N, double A[][N], double B[][N]) {
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            B[i][j] = A[j][i];
}

int bareiss_det(int N, int A[][N]) {
    int i, j, k, p, divider;
    for(i=0;i<N;i++) {
	p = A[i][i];
	for(j=0;j<N;j++) {
	    if(i != j) {
	        for(k=i+1;k<N; k++) {
		    if (i==0)
			divider = 1;
		    else
			divider = A[i-1][i-1];
                    A[j][k] = ((p*A[j][k]) - (A[j][i]*A[i][k])) / divider;
		}
	    }
        }
    }
    return A[N-1][N-1];
}

double double_bareiss_det(int N, double A[][N]) {
    int i, j, k, p, divider;
    for(i=0;i<N;i++) {
	p = A[i][i];
	for(j=0;j<N;j++) {
	    if(i != j) {
	        for(k=i+1;k<N; k++) {
		    if (i==0)
			divider = 1;
		    else
			divider = A[i-1][i-1];
                    A[j][k] = ((p*A[j][k]) - (A[j][i]*A[i][k])) / divider;
		}
	    }
        }
    }
    return A[N-1][N-1];
}

int leibniz_det(int num, int A[][num]) {
    int res = 0;
    switch(num) {
	case 2:
          res = - (A[1][0]*A[0][1]) + (A[0][0]*A[1][1]);
	  break;
	case 3:
	     res = (A[0][0] * A[1][1] * A[2][2]) - (A[0][0] * A[1][2] * A[2][1]) + (A[0][1] * A[1][2] * A[2][0]) - (A[0][1] * A[1][0] * A[2][2]) + (A[0][2] * A[1][0] * A[2][1]) - (A[0][2] * A[1][1] * A[2][0]);
	case 4:
	     res = (A[0][0]*A[1][1]*A[2][2]*A[3][3]) + (A[0][0]*A[2][1]*A[3][2]*A[1][3]) + (A[0][0]*A[3][1]*A[1][2]*A[2][3]) + (A[1][0]*A[0][1]*A[3][2]*A[2][3]) + (A[1][0]*A[2][1]*A[0][2]*A[3][3]) + (A[1][0]*A[3][1]*A[2][2]*A[0][3]) + (A[2][0]*A[0][1]*A[1][2]*A[3][3]) + (A[2][0]*A[1][1]*A[3][2]*A[0][3]) + (A[2][0]*A[3][1]*A[0][2]*A[1][3]) + (A[3][0]*A[0][1]*A[2][2]*A[1][3]) + (A[3][0]*A[1][1]*A[0][2]*A[2][3]) + (A[3][0]*A[2][1]*A[1][2]*A[0][3]) - (A[0][0]*A[1][1]*A[3][2]*A[2][3]) - (A[0][0]*A[2][1]*A[1][2]*A[3][3]) - (A[0][0]*A[3][1]*A[2][2]*A[1][3]) - (A[1][0]*A[0][1]*A[2][2]*A[3][3]) - (A[1][0]*A[2][1]*A[3][2]*A[0][3]) - (A[1][0]*A[3][1]*A[0][2]*A[2][3]) - (A[2][0]*A[0][1]*A[3][2]*A[1][3]) - (A[2][0]*A[1][1]*A[0][2]*A[3][3]) - (A[2][0]*A[3][1]*A[1][2]*A[0][3]) - (A[3][0]*A[0][1]*A[1][2]*A[2][3]) - (A[3][0]*A[1][1]*A[2][2]*A[0][3]) - (A[3][0]*A[2][1]*A[0][2]*A[1][3]);
	default:
	    break;
    }
    return res;
}

double gauss_elim(int n, double a[][n]){
    int i,j,k;
    for(i=0;i<n-1;i++){
        //Partial Pivoting
        for(k=i+1;k<n;k++){
            //If diagonal element(absolute vallue) is smaller than any of the terms below it
            if(fabs(a[i][i])<fabs(a[k][i])){
                //Swap the rows
                for(j=0;j<n;j++){
                    double temp;
                    temp=a[i][j];
                    a[i][j]=a[k][j];
                    a[k][j]=temp;
                }
            }
        }
        //Begin Gauss Elimination
        for(k=i+1;k<n;k++){
            double  term = a[k][i]/ a[i][i];
            for(j=0;j<n;j++)
                a[k][j]=a[k][j]-(term*a[i][j]);
        }
    }
    double res = 1.0;
    for(i=0;i<n;i++)
	res *= a[i][i];
}

int rank_m(int n, double matrix[][n]) {
	int i,j;
	int ct = 0;
	int rk = 0;
	for (i=0;i<n;i++) {
	for(j=0;j<n;j++) {
		if(matrix[i][j]== 0)
		    ct++;
	}
			if(ct == n) { 
		   rk++;
		   ct=0;
		}
}
return (n-rk);
}

void double_print_m(int m, int n, double matrix[m][n]){
    int i,j;
    for(i=0;i<m;i++){
	printf("|");
        for(j=0;j<n;j++){
            printf("%lf ",matrix[i][j]);
        }
        printf("|\n");
    }
}

void print_m(int m, int n, int matrix[m][n]){
    int i,j;
    for(i=0;i<m;i++){
	printf("|");
        for(j=0;j<n;j++){
            printf(" %d ",matrix[i][j]);
        }
        printf("|\n");
    }
}

void double_copy_m(int m, int n, double matrix1[m][n], double matrix2[m][n]){
    int i,j;
    for(i=0;i<m;i++){
        for(j=0;j<n;j++){
            matrix2[i][j]=matrix1[i][j];
        }
    }
}

void copy_m(int m, int n, int matrix1[m][n], int matrix2[m][n]){
    int i,j;
    for(i=0;i<m;i++){
        for(j=0;j<n;j++){
            matrix2[i][j]=matrix1[i][j];
        }
    }
}

void make_double(int m, int n, int matrix1[m][n], double matrix2[m][n]){
    int i,j;
    for(i=0;i<m;i++){
        for(j=0;j<n;j++){
            matrix2[i][j]=(double)matrix1[i][j];
        }
    }
}

void make_int(int m, int n, double matrix1[m][n], int matrix2[m][n]){
    int i,j;
    for(i=0;i<m;i++){
        for(j=0;j<n;j++){
            matrix2[i][j]=(int)matrix1[i][j];
        }
    }
}

void random_m(int m, int n, int z, int mat[m][n]) {
	int i,j;
	srand(time(NULL));
	for(i=0;i<m;i++)
	    for(j=0;j<n;j++)
	        mat[i][j] = rand() % z + 1;
}

int main() {
 /* double A[4][4] = { {4.0, 3.0, 1.0, 5.0},
                    {2.0, 3.0, 2.0, 3.0},
                    {1.0, 3.0, 2.0, 2.0},
                    {2.0, 1.0, 2.0, 5.0}};
*/
    //int B[N][N], C[N][N];
    int Q[4][4];
    printf("the matrix:\n\n");
    random_m(4,4,100,Q);
    print_m(4,4,Q);
    int i,j;
    int Z[4][4];
    double D[4][4];
    init_m(4,D,1);
  int E[4][4] = {{2,5,3,2},
	            {3,6,1,1},
		    {1,3,4,3},
                    {2,1,1,1}};
    /*         printf("first matrix:\n");
    print_m(4,4,E);
   make_double(4,4,E,D);
    printf("\ntransformed in double: \n");
    double_print_m(4,4,D);
    printf("\nretransformed in int: \n");
    make_int(4,4,D,Z);
    print_m(4,4,Z);*/
    
double F[3][3] = {{1.0,2.0,3.0}, {3.0,4.0,3.0},{1.0,1.0,1.0}};
 //  double_print_m(2,2,F);
  //  int F[2][2] = {{2,2},
    //               {4,4}};
   //scalar_product(3, A, B);
  // transpose(A,B);
   //sub_m(A, B, C);
    //multiply_m(A,A,C);
   /* int res = leibniz_det(4, E);
    printf("det: %d\n", res);
    printf("Result matrix is \n");
    print_m(4,4,E);*/
//   identity(6,D);
  // int d = bareiss_det(4,E);
   // printf("det: %d\n", d);
    //print_m(4,4,E);
  double g= double_bareiss_det(3,F);
  printf("\ndet: %lf\n",g);
   double_print_m(3,3,F);
/*    int r = rank_m(2,F);
    printf("rank: %d\n", r);*/
    //print_m(6,6,D);
    return 0;
}

