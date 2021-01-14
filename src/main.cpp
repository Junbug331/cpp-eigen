#include <iostream>
#include <Eigen/Dense>

using namespace Eigen;
using namespace std;

int main()
{
    // Define 3x3 matrix of floats and sets
    Matrix<float, 3, 3> matrixA;
    matrixA.setZero();
    cout << matrixA << endl;

    // define 3x3 matrix of floats and set its entries to zero - built in typedef declaration
    Matrix3f matrixA1;
    matrixA1.setZero();
    cout << "\n" << matrixA1 << endl;

    // define a dynamic matrix, explicit declaration
    Matrix <float, Dynamic, Dynamic> MatrixB;

    // define a dynamic matrix - build in typedef declaration
    MatrixXf matrixB1;

    // constructor, allocate memory, but do not initialize
    MatrixXd matrixC(10, 10);

    // assigning matrix entries
    MatrixXd matrixC1(2, 2);
    matrixC1(0, 0) = 1;
    matrixC1(0, 1) = 2;
    matrixC1(1, 0) = 3;
    matrixC1(1, 1) = 4;

    cout << endl << matrixC1 << endl;

    // fill-in the matrix entries using << operation
    Matrix4f matrixD;
    matrixD << 1, 2, 3, 4,
               5, 6, 7, 8,
               9, 10, 11, 12,
               13, 14, 15, 16;
    cout << endl << matrixD << endl;

    int rowNumber = 5;
    int colNumber = 5;

    // matrix of zeros
    MatrixXf matrix1zeros;
    matrix1zeros = MatrixXf::Zero(rowNumber, colNumber);
    cout << endl << "matrix1zeros" << endl;
    cout << matrix1zeros << endl;
    // another option
    MatrixXf matrix1zeros1;
    matrix1zeros1.setZero(rowNumber, colNumber);
    cout << endl << "matrix1zeros1" << endl;
    cout << matrix1zeros1 << endl;

    // matrix of ones
    MatrixXf matrix1ones;
    matrix1ones = MatrixXf::Ones(rowNumber, colNumber);
    cout << endl << "matrix1ones" << endl;
    cout << matrix1ones << endl;
    // another option
    MatrixXf matrix1ones1;
    matrix1ones1.setOnes(rowNumber, colNumber);
    cout << endl << "matrix1ones1" << endl;
    cout << matrix1ones1 << endl;

    // matrix of constant
    float value = 1.1;
    MatrixXf matrix1const;
    matrix1const = MatrixXf::Constant(rowNumber, colNumber, value);
    cout << endl << "matrix1const" << endl;
    cout << matrix1const << endl;

    // another option
    MatrixXf matrix1const1;
    matrix1const1.setConstant(rowNumber, colNumber, value);
    cout << endl << "matrix1const1" << endl;
    cout << matrix1const1 << endl;

    // identity matrix
    rowNumber = 10;
    colNumber = 10;

    MatrixXd matrixIdentity;
    matrixIdentity = MatrixXd::Identity(rowNumber, colNumber);
    cout << endl << "matrixIdentity" << endl;
    cout << matrixIdentity << endl;

    MatrixXd matrixIdentity1;
    matrixIdentity1.setIdentity(rowNumber, colNumber);
    cout << endl << "matrixIdentity1" << endl;
    cout << matrixIdentity1 << endl;

    // access matrix element
    Matrix4f matrix4f;
    matrix4f << 1, 2, 3, 4,
                5, 6, 7, 8,
                9, 10, 11, 12,
                13, 14, 15, 16;
    // access the matrix composed of 1:2 rows and 1:2 cols of matrix4f
    cout << endl << "accessing a block of matrix(rect)" << endl;
    cout << matrix4f.block(1,0, 3,4) << endl;

    // accessing columns and rows of a matrix
    cout << endl << endl << "Row 1 of matrix4f is \n" << matrix4f.row(0);
    cout << endl << "Column 1 of matrix4f is \n" << matrix4f.col(0);

    // create a diagonal matrix out of a vector( 3x1 Matrix)
    Matrix<double, 3, 1> vector1;
    vector1 << 1, 2, 3;
    MatrixXd diagonalMatrix;
    diagonalMatrix = vector1.asDiagonal();
    cout << endl << endl << "Diagonal Matrix is\n" << diagonalMatrix << endl;

    // basic materix operation
    //matrix addition
    MatrixXd A1(2, 2);
    MatrixXd B1(2, 2);

    A1 << 1, 2,
          3, 4;
    B1 << 3, 4,
          5, 6;
    MatrixXd C1 = A1 + B1;
    cout << endl << "The sum of A1 and B1 is \n" << C1 << endl;

    // matrix mult
    MatrixXd D1 = A1 * B1;
    cout << endl << "The matrix product of A1 and B1 is\n" << D1 << endl;

    // multiplication by scalar
    int s1 = 2;
    MatrixXd F1 = s1 * A1;
    cout << endl << "The matrix scalar product of 2 and A1 is\n" << F1 << endl;

    // matrix transpose
    MatrixXd At;
    At = A1.transpose();
    cout << endl << "The original matrix is\n" << A1 << endl;
    cout << "The transpose of the matrix is\n" << At << endl;

    // we can use a transpose operator in expression
    MatrixXd R1;
    R1 = A1.transpose() + B1;
    cout << endl << "Matrix R1 = A1_t + B1 is\n" << R1 << endl;

    /* here we should be careful, the operation transpose() might lead to unexpected results
     * in this scenarios
     * A1 = A1.transpose();
     * cout << A1 << endl;
     * */

    // Correct and safe way to do the matrix is the following
    A1.transposeInPlace();
    // restore A1 to its original state
    A1.transposeInPlace();

    // matrix inverse
    MatrixXd G1;
    G1 = A1.inverse();
    cout << endl;
    cout << "The inverse of the matrix A1 is\n" << G1 << endl;
    cout << endl;
    cout << "G1 * A1 is \n" << G1 * A1 << endl;
    
    return 0;
}
