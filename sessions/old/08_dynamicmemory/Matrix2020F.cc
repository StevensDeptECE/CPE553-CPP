#include <stdio.h>
#include <iostream>
#include <memory.h>
using namespace std;

class Matrix {
private:
    uint32_t rows, cols;
    double* m;
public:
    Matrix(uint32_t rows, uint32_t cols, double v = 0): rows(rows), cols(cols), m(new double[rows*cols]) {
        for (int i = 0; i < rows*cols; i++) {
            m[i] = v;
        }

//        set n bytes of s to c
//        memset(s, c, n)
//        memset(m, 0, rows*cols*sizeof(double)); this only works for zero! not 3.5
    }

    ~Matrix(){
     delete [] m;
    }

    Matrix (const Matrix& orig): rows(orig.rows), cols(orig.cols), m(new double[orig.rows*orig.cols]){
        memcpy(m, orig.m, orig.rows * orig.cols * sizeof(double));
    }

    Matrix& operator =(const Matrix& original)
    {
        rows = original.rows;
        cols = original.cols;
        swap(m, original.m);
        return *this;        
    }    
    

    //move constuctor
    Matrix(Matrix && mat) : rows(mat.rows), cols(mat.cols), m(mat.m){
        mat.m = nullptr; //wipe the pointer of the object about to die
    }    
};