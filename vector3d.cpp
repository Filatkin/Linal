#include <iostream>
#include <vector3d.hpp>
Vector3D::Vector3D(double _x, double _y, double _z): x(_x), y(_y), z(_z)
    {

    }
Vector3D::Vector3D(): Vector3D(0,0,0)
    {

    }
double Vector3D::getValue(unsigned int i) const
    {
        if(i==1)
            return x;
        if(i==2)
            return y;
        if(i==3)
            return z;
        return 0;
    }
void Vector3D::setValue(unsigned int i,double value)
    {
        if(i==1)
            this->x=value;
        if(i==2)
            this->y=value;
        if(i==3)
            this->z=value;
    }
Vector3D::Vector3D operator* (const double a) const
    {
        return Vector3D(x*a,y*a,z*a);
    }
Vector3D::Vector3D operator+ (const Vector3D& v)
    {
        return Vector3D(x+v.x,y+v.y,z+v.z);
    }
Vector3D::Vector3D operator- (const Vector3D& v)
    {
        return Vector3D(x-v.x,y-v.y,z-v.z);
    }
double Vector3D::operator* (const Vector3D& v)
    {
        return x*v.x+y*v.y+z*v.z;
    }
Vector3D operator* (double a, const Vector3D& v)
{
    return Vector3D(v.getValue(1)*a, v.getValue(2)*a, v.getValue(3)*a);
}
ostream& operator<<(ostream& os, const Vector3D& v)
{
    os << "(" << v.getValue(1) << "; " << v.getValue(2) <<";"<< v.getValue(3)<< ")";
    return os;
}
istream& operator>>(istream &is, Vector3D& v)
{
    double x, y, z;
    is >> x >> y >> z;
    v.setValue(1,x);
    v.setValue(2,y);
    v.setValue(3,z);
    return is;
}
