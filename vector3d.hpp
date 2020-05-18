#ifndef VECTOR3D_H
#define VECTOR3D_H
#include<iostream>
using namespace std;
class Vector3D
{
private:
    double x,y,z;
public:
    Vector3D(double _x, double _y, double _z);
    Vector3D();
    double getValue(unsigned int i) const;
    void setValue(unsigned int i,double value);
    Vector3D operator* (const double a) const;
    Vector3D operator+ (const Vector3D& v);
    Vector3D operator- (const Vector3D& v);
    double operator* (const Vector3D& v);
};
ostream& operator<<(ostream& os, const Vector3D& v);
Vector3D operator* (double a, const Vector3D& v);
istream& operator>>(istream &is, Vector3D& v);
#endif
