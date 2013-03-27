#ifndef _LINALG_H_
#define _LINALG_H_

typedef float Vec3[3];
typedef float Vec4[4];
typedef float Mat4[4][4];
typedef float Float4[4];

Float4 *mm4mul(Mat4 a, Mat4 b, Mat4 r);
float *mv4mul(Mat4 m, Vec4 v);
float vv4dot(Vec4 a, Vec4 b);
float vv3dot(Vec3 a, Vec3 b);
Float4 *mm4identity(Mat4 m);
Float4 *mm4translate(Vec3 v, Mat4 m);
Float4 *mm4scale(Vec3 v, Mat4 m);
Float4 *mm4rotate(Vec3 a, Mat4 m);
Float4 *m4ortho(float left, float right, float bottom, float top, float near, float far, Mat4 m);
float *vec4(float x, float y, float z, float w, Vec4 v);
float *vec3(float x, float y, float z, Vec3 v);

#ifdef _DEBUG
/* Debug */
void m4print(Mat4 m);
void v4print(Vec4 v);
#endif

#endif
