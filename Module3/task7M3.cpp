#include<iostream>
#include<vector>
using namespace std;

class Matrix {
protected:  
    int row;
    int col;
    vector<vector<int>> intMatrix;
    vector<vector<double>> doubleMatrix;
    
public:
    Matrix(int r, int c) : row(r), col(c) {
        intMatrix.resize(r, vector<int>(c, 0));
        doubleMatrix.resize(r, vector<double>(c, 0.0));
    }
    
    void setValue(int r, int c, int value) {
        if(r < row && c < col) intMatrix[r][c] = value;
    }
    
    void setValue(int r, int c, double value) {
        if(r < row && c < col) doubleMatrix[r][c] = value;
    }
    
    virtual void display() = 0;  
    virtual ~Matrix() {}  
};

class SquareMatrix : public Matrix {
public:
    SquareMatrix(int r, int c) : Matrix(r, c) {
        if(r != c) cout << "Warning: Not a square matrix!\n";
    }
    
    void display() override {
        cout << "SquareMatrix (" << row << "x" << col << "):\n";
        for(int i = 0; i < row; i++) {
            for(int j = 0; j < col; j++) {
                cout << intMatrix[i][j] << " ";
            }
            cout << endl;
        }
    }
};

class IdentityMatrix : public Matrix {
public:
    IdentityMatrix(int r, int c) : Matrix(r, c) {
        if(r != c) cout << "Warning: Not a square matrix!\n";
        for(int i = 0; i < row && i < col; i++) {
            intMatrix[i][i] = 1;
            doubleMatrix[i][i] = 1.0;
        }
    }
    
    void display() override {
        cout << "IdentityMatrix (" << row << "x" << col << "):\n";
        for(int i = 0; i < row; i++) {
            for(int j = 0; j < col; j++) {
                cout << intMatrix[i][j] << " ";
            }
            cout << endl;
        }
    }
};

Matrix operator+(const Matrix& m1, const Matrix& m2) {
    if(m1.row != m2.row || m1.col != m2.col) {
        throw "Matrices must be same dimensions!";
    }
    
    Matrix result(m1.row, m1.col);
    
    for(int i = 0; i < m1.row; i++) {
        for(int j = 0; j < m1.col; j++) {
        }
    }
    return result;
}

int main() {
 
    cout << "1. Overloaded setValue(int) and setValue(double)\n";
    
    SquareMatrix sq(2, 2);
    sq.setValue(0, 0, 10);        // int version
    sq.setValue(0, 1, 20);        // int version
    sq.setValue(1, 0, 3.14);      // double version (truncated to int)
    sq.display();
    
    cout << "\n2. Overloaded operator+\n";
    SquareMatrix a(2, 2), b(2, 2);
    a.setValue(0, 0, 5);
    a.setValue(0, 1, 7);
    b.setValue(0, 0, 3);
    b.setValue(0, 1, 2);
    
    cout << "Matrix A:\n";
    a.display();
    cout << "Matrix B:\n";
    b.display();
    
    
    cout<<"Case2"<<endl;
    cout << "Same display() call, different behaviors:\n\n";
    
    // Base class pointers - polymorphic behavior!
    Matrix* m1 = new SquareMatrix(2, 2);
    Matrix* m2 = new IdentityMatrix(3, 3);
    Matrix* m3 = new SquareMatrix(3, 3);
    
    // Set some values
    dynamic_cast<SquareMatrix*>(m1)->setValue(0, 0, 400);
    dynamic_cast<SquareMatrix*>(m1)->setValue(1, 1, 639);
    dynamic_cast<SquareMatrix*>(m3)->setValue(0, 0, 99);
    
    
    cout << "Calling display() on SquareMatrix*:\n";
    m1->display();
    
    cout << "\nCalling display() on IdentityMatrix*:\n";
    m2->display();
    
    cout << "\nCalling display() on another SquareMatrix*:\n";
    m3->display();
    
    delete m1;
    delete m2;
    delete m3;
    
    return 0;
}