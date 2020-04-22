#ifndef MATRIX3D_H
#define MATRIX3D_H
#include<vector3d.hpp>
class Matrix3D
{
private:
    double** a;
public:
    Matrix3D(int _a1, int _a2, int _a3, int _a4, int _a5, int _a6, int _a7, int _a8, int _a9);
    Matrix3D(): Matrix3D(0,0,0,0,0,0,0,0,0);
    ~Matrix3D();
    double getValue(unsigned int i, unsigned int j) const;
    void setValue(unsigned int i, unsigned int j, double value) const;
    Matrix3D operator* (const double c) const;
    Matrix3D operator+ (const Matrix3D& m) const;
    Matrix3D operator- (const Matrix3D& m) const;
    Matrix3D operator* (const Matrix3D& m);
    Vector3D operator* (const Vector3D& v);
    double det();
};
#endif // MATRIX_H
