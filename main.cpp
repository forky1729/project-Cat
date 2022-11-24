#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "vec3.h"

struct Triangle
{
    vec3 r0, r1, r2;            //координаты вершин треугольника
    vec3 n0, n1, n2;            //координаты вектора нормали к каждой вершине
    vec3 t0, t1, t2;            //координаты ?цвета? (t2=0 всегда, но чтобы не вводить vec2 используется vec3)
};

struct intvec3                  //вспомогательная структура
{
    int x, y, z;
};

struct F                        //структура для сохранения соответсвия характеристик треугольника
{
    intvec3 u0, u1, u2, u3;
};

int main()
{
    std::vector<Triangle> triangle;
    std::vector<vec3> v;
    std::vector<vec3> vn;
    std::vector<vec3> vt;
    std::vector<F> f;
    std::ifstream file("Cat.obj");
    std::string str;
        while (std::getline(file, str))
        {
            vec3 r;
            F rf;
            char const *input = str.c_str();
            if (3==std::sscanf(input, "v %f %f %f", &r.x, &r.y, &r.z))
            {
                v.push_back(r);
            }
            if (3==std::sscanf(input, "vn %f %f %f", &r.x, &r.y, &r.z))
            {
                vn.push_back(r);
            }
            if (3==std::sscanf(input, "vt %f %f %f", &r.x, &r.y, &r.z))
            {
                vt.push_back(r);
            }
            if (12==std::sscanf(input, "f %i/%i/%i %i/%i/%i %i/%i/%i %i/%i/%i", &rf.u0.x, &rf.u0.y, &rf.u0.z, &rf.u1.x, &rf.u1.y, &rf.u1.z, &rf.u2.x, &rf.u2.y, &rf.u2.z, &rf.u3.x, &rf.u3.y, &rf.u3.z))
            {
                f.push_back(rf);
            }
        }
    file.close();
    for (int i = 0; i < f.size(); ++i)
    {
        triangle.push_back({v[f[i].u0.x], v[f[i].u1.x], v[f[i].u2.x], vn[f[i].u0.y], vn[f[i].u1.y], vn[f[i].u2.y], vt[f[i].u0.z], vt[f[i].u1.z], vt[f[i].u2.z]});
        triangle.push_back({v[f[i].u0.x], v[f[i].u2.x], v[f[i].u3.x], vn[f[i].u0.y], vn[f[i].u2.y], vn[f[i].u3.y], vt[f[i].u0.z], vt[f[i].u2.z], vt[f[i].u3.z]});
    }
}
