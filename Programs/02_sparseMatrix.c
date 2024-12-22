#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    int rows;
    int row;
    int col;
    int value;
} SparseMatrix;

SparseMatrix *create(int numElements)
{
    SparseMatrix *matrix = (SparseMatrix *)malloc(numElements * sizeof(SparseMatrix));
    matrix->rows = numElements;

    return matrix;
}

void insertElement(SparseMatrix *matrix, int row, int col, int value, int index)
{
    matrix[index].row = row;
    matrix[index].col = col;
    matrix[index].value = value;
}

int inputMatrix(int rows, int cols, int matrix[][cols])
{
    int numNonZeroElements = 0;
    printf("Enter the elements of the matrix:\n");
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            scanf("%d", &matrix[i][j]);
            if (matrix[i][j] != 0)
            {
                numNonZeroElements++;
            }
        }
    }
    return numNonZeroElements;
}

SparseMatrix *createSparseMatrix(int rows, int cols, int matrix[][cols], int numNonZeroElements)
{
    SparseMatrix *sparseMatrix = create(numNonZeroElements);
    int elementIndex = 0;

    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            if (matrix[i][j] != 0)
            {
                insertElement(sparseMatrix, i, j, matrix[i][j], elementIndex);
                elementIndex++;
            }
        }
    }

    return sparseMatrix;
}

void printSparseMatrix(const SparseMatrix *matrix)
{
    for (int i = 0; i < matrix->rows; i++)
    {
        printf("(%d, %d): %d", matrix[i].row, matrix[i].col, matrix[i].value);
        printf("\n");
    }
}

int main()
{
    int rows, cols;
    printf("Enter the number of rows: ");
    scanf("%d", &rows);
    printf("Enter the number of columns: ");
    scanf("%d", &cols);

    int matrix[rows][cols];
    int numNonZeroElements = inputMatrix(rows, cols, matrix);

    SparseMatrix *sparseMatrix = createSparseMatrix(rows, cols, matrix, numNonZeroElements);

    printf("\nSparse Matrix:\n");
    printSparseMatrix(sparseMatrix);

    return 0;
}
