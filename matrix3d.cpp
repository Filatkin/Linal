#include<iostream>
#include "matrix3d.hpp"
#include "vector3d.hpp"
Matrix3D::Matrix3D(int _a1, int _a2, int _a3, int _a4, int _a5, int _a6, int _a7, int _a8, int _a9)
    {
        a=new double* [3];
        for(unsigned int i=0;i<3;i++)
            a[i]=new double [3];
        a[0][0]=_a1;
        a[0][1]=_a2;
        a[0][2]=_a3;
        a[1][0]=_a4;
        a[1][1]=_a5;
        a[1][2]=_a6;
        a[2][0]=_a7;
        a[2][1]=_a8;
        a[2][2]=_a9;
    }
Matrix3D::Matrix3D()
{
    a=new double* [3];
        for(unsigned int i=0;i<3;i++)
            a[i]=new double [3];
}
Matrix3D::~Matrix3D()
    {
        for(unsigned int i=0;i<3;i++)
            delete [] a[i];
        delete [] a;
    }
double Matrix3D::getValue(unsigned int i, unsigned int j) const
    {
        return a[i][j];
    }
void Matrix3D::setValue(unsigned int i, unsigned int j, double value) const
    {
        a[i][j]=value;
    }
Matrix3D Matrix3D::operator* (const double c) const
    {
        Matrix3D M;
        for(unsigned int i=0;i<3;i++)
            for(unsigned int j=0;j<3;j++)
                M.setValue(i,j,a[i][j]*c);
        return M;
    }
Matrix3D Matrix3D::operator+ (const Matrix3D& m) const
    {
        Matrix3D M;
        for(unsigned int i=0;i<3;i++)
            for(unsigned int j=0;j<3;j++)
                M.setValue(i,j,a[i][j]+m.a[i][j]);
        return M;
    }
Matrix3D Matrix3D::operator- (const Matrix3D& m) const
    {
        Matrix3D M;
        for(unsigned int i=0;i<3;i++)
            for(unsigned int j=0;j<3;j++)
            M.setValue(i,j,a[i][j]-m.a[i][j]);
        return M;
    }
Matrix3D Matrix3D::operator* (const Matrix3D& m)
    {
        Matrix3D M;
        for(unsigned int i=0;i<3;i++)
        {
            for(unsigned int j=0;j<3;j++)
            {
                double c;
                c=0;
                for(unsigned int k=0;k<3;k++)
                {
                    c+=a[i][k]*m.getValue(k,j);
                }
                M.setValue(i,j,c);
            }
        }
        return M;
    }
Vector3D Matrix3D::operator* (const Vector3D& v)
    {
        Vector3D V;
        for(unsigned int i=0;i<3;i++)
        {
            double c;
            c=0;
            for(unsigned int k=0;k<3;k++)
            {
                c+=a[i][k]*v.getValue(k+1);
            }
            V.setValue(i+1,c);
        }
        return V;
    }
double Matrix3D::det()
    {
        return a[0][0]*(a[1][1]*a[2][2]-a[1][2]*a[2][1])-a[0][1]*(a[1][0]*a[2][2]-a[2][0]*a[1][2])+a[0][2]*(a[1][0]*a[2][1]-a[1][1]*a[2][0]);
    }
Matrix3D operator* (double c, const Matrix3D& m)
    {
        Matrix3D M;
        for(unsigned int i=0;i<3;i++)
            for(unsigned int j=0;j<3;j++)
                M.setValue(i,j,c*m.getValue(i,j));
        return M;
    }
ostream& operator<<(ostream& os, const Matrix3D& m)
{
    os <<endl<< m.getValue(0,0) << " " << m.getValue(0,1) <<" "<< m.getValue(0,2)<< endl;
    os << m.getValue(1,0) << " " << m.getValue(1,1) <<" "<< m.getValue(1,2)<< endl;
    os << m.getValue(2,0) << " " << m.getValue(2,1) <<" "<< m.getValue(2,2)<< endl;
    return os;
}
istream& operator>>(istream &is, Matrix3D& m)
{
    double a1,a2,a3,a4,a5,a6,a7,a8,a9;
    is >> a1 >> a2 >> a3 >> a4 >> a5 >> a6 >> a7 >> a8 >> a9;
    m.setValue(0,0,a1);
    m.setValue(0,1,a2);
    m.setValue(0,2,a3);
    m.setValue(1,0,a4);
    m.setValue(1,1,a5);
    m.setValue(1,2,a6);
    m.setValue(2,0,a7);
    m.setValue(2,1,a8);
    m.setValue(2,2,a9);
    return is;
}
