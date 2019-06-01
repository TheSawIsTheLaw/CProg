#include <stdio.h>

#define FILE_ERROR -1
#define SCAN_ERROR -2

int goto_zeroes(const int row, const int col, int mat[row][col])
{
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col; j++)
			mat[i][j] = 0;
	}
	return 0;
}

int fill_matrix(FILE *const in, const int row, const int col, int matrix[row][col])
{
	if (!in)
		return FILE_ERROR;
	int c, r, n, into;
	fscanf(in, "%d", &r);
	fscanf(in, "%d", &c);
	n = fscanf(in, "%d", &into);
	while(n == 1)
	{
		matrix[r - 1][c - 1] = into;
		fscanf(in, "%d", &r);
		fscanf(in, "%d", &c);
		n = fscanf(in, "%d", &into);
	}
	return 0;
}

int is_sqr(const int row, const int col, const int i, const int j, int matrix[row][col])
{
	for (int q = 0; q < row && q < col; q++)
	{
		if (matrix[i + q][j + q] || matrix[i - q][j - q] || matrix[i][j - q] || matrix[i][j + q] ||
		    matrix[i - q][j] || matrix[i + q][j] || matrix[i + q][j - q] || matrix[i - q][j + q])
			return q;	
	}
	return 0;
}

int the_biggest_sqr_zero(const int row, const int col, int matrix[row][col])
{
	int max_sqr = 0, sqr;
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col; j++)
		{
			sqr = is_sqr(row, col, i, j, matrix);
			if (sqr > max_sqr)
				max_sqr = sqr;
		}
	}
	return max_sqr;
}

int main(void)
{
	FILE *in = fopen("in.txt", "rt");
	
	if (!in)
		return FILE_ERROR;

	int row, rc = fscanf(in, "%d", &row);
	if (rc != 1)
		return SCAN_ERROR;
	int col;
	rc = fscanf(in, "%d", &col);
	if (rc != 1)
		return SCAN_ERROR;
	
	int ones;
	rc = fscanf(in, "%d", &ones);
	if (rc != 1)
		return SCAN_ERROR;
	
	int matrix[row][col];
	
	goto_zeroes(row, col, matrix);
	
	fill_matrix(in, row, col, matrix);
	
	fclose(in);
	
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col; j++)
			printf("%d ", matrix[i][j]);
		printf("\n");
	}
	
	int max_sqr = the_biggest_sqr_zero(row, col, matrix);
	printf("max sqr is %d", max_sqr);
	return 0;
}