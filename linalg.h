#ifndef _LINALG_H_
#define _LINALG_H_

typedef double Vec3[3];
typedef double Vec4[4];
typedef double Mat4[4][4];
typedef double Double4[4];

Double4 *mm4mul(Mat4 a, Mat4 b, Mat4 r);
double *mv4mul(Mat4 m, Vec4 v, Vec4 vr);
Double4 *m4inv(Mat4 a, Mat4 m);
double vv4dot(Vec4 a, Vec4 b);
double vv3dot(Vec3 a, Vec3 b);
Double4 *mm4identity(Mat4 m);
Double4 *mm4translate(Vec3 v, Mat4 m);
Double4 *mm4scale(Vec3 v, Mat4 m);
Double4 *mm4rotate(Vec3 a, Mat4 m);
Double4 *m4ortho(double left, double right, double bottom,
                 double top, double near, double far, Mat4 m);
Double4 *m4perspective(double fov, double aspect, double near,
                       double far, Mat4 m);
double *vec4(double x, double y, double z, double w, Vec4 v);
double *vec3(double x, double y, double z, Vec3 v);

#ifdef _DEBUG
/* Debug */
void m4print(Mat4 m);
void v4print(Vec4 v);
#endif

#endif
