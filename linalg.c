#ifdef _DEBUG
#include <stdio.h>
#endif

#include <string.h>
#include <math.h>

#include "linalg.h"

Float4 *mm4mul(Mat4 a, Mat4 b, Mat4 m) {
   int i, j, h;
   Mat4 r;

   memset(r, 0, sizeof(Mat4));
   for (h = 0; h < 4; h++) {
      for (i = 0; i < 4; i++) {
         for (j = 0; j < 4; j++) {
            r[i][h] += a[j][h] * b[i][j];
         }
      }
   }

   memcpy(m, r, sizeof(Mat4));

   return m;
}

float *mv4mul(Mat4 m, Vec4 v) {
   int i, j;
   Vec4 r;

   memset(r, 0, sizeof(Vec4));
   for (i = 0; i < 4; i++) {
      for (j = 0; j < 4; j++) {
         r[i] += m[j][i] * v[j];
      }
   }

   memcpy(v, r, sizeof(Vec4));

   return v;
}

float vv4dot(Vec4 a, Vec4 b) {
   int i;
   float r = 0;

   for (i = 0; i < 4; i++) {
      r += a[i] * b[i];
   }

   return r;
}

float vv3dot(Vec3 a, Vec3 b) {
   int i;
   float r = 0;

   for (i = 0; i < 3; i++) {
      r += a[i] * b[i];
   }

   return r;
}

Float4 *m4identity(Mat4 m) {
   int i;

   memset(m, 0, sizeof(Mat4));
   for (i = 0; i < 4; i++) {
      m[i][i] = 1;
   }

   return m;
}

Float4 *m4translate(Vec3 v, Mat4 m) {
   m4identity(m);
   m[3][0] = v[0];
   m[3][1] = v[1];
   m[3][2] = v[2];

   return m;
}

Float4 *m4scale(Vec3 v, Mat4 m) {
   m4identity(m);
   m[0][0] = v[0];
   m[1][1] = v[1];
   m[2][2] = v[2];

   return m;
}

Float4 *m4rotate(Vec3 a, Mat4 m) {
   float cx, cy, cz;
   float sx, sy, sz;
   float sxsy;

   cx = cos(a[0]);
   cy = cos(a[1]);
   cz = cos(a[2]);

   sx = sin(a[0]);
   sy = sin(a[1]);
   sz = sin(a[2]);

   sxsy = sx * sy;

   m[0][0] =  cy * cz;
   m[1][0] =  cx * sz + sxsy * cz;
   m[2][0] =  sx * sz - cx * sy * cz;
   m[3][0] =  0;

   m[0][1] = -cy * sz;
   m[1][1] =  cx * cz - sxsy * sz;
   m[2][1] =  sx * cz + cx * sy * sz;
   m[3][1] =  0;

   m[0][2] =  sy;
   m[1][2] = -sx * cy;
   m[2][2] =  cx * cy;
   m[3][2] =  0;

   m[0][3] = 0;
   m[1][3] = 0;
   m[2][3] = 0;
   m[3][3] = 1;

   return m;
}

Float4 *m4ortho(float left, float right, float bottom, float top, float near, float far, Mat4 m) {
   Vec3 g;
   Mat4 a, b, c;

   mm4mul(m4translate(vec3(-((right+left)/(right-left)),
                           -((top+bottom)/(top-bottom)),
                           -((far+near)/(far-near)), g), a),
          m4scale(vec3( 2/(right-left),
                        2/(top-bottom),
                       -2/(far-near), g), b), 
          c);

   memcpy(m, c, sizeof(Mat4));

   return m;
}

float *vec4(float x, float y, float z, float w, Vec4 v) {
   v[0] = x;
   v[1] = y;
   v[2] = z;
   v[3] = w;

   return v;
}

float *vec3(float x, float y, float z, Vec3 v) {
   v[0] = x;
   v[1] = y;
   v[2] = z;

   return v;
}

#ifdef _DEBUG
/* Debug */

void m4print(Mat4 m) {
   int i, j;

   for (i = 0; i < 4; i++) {
      for (j = 0; j < 4; j++) {
         printf("%f\t", m[j][i]);
      }
      putchar('\n');
   }
}

void v4print(Vec4 v) {
   int i;

   for (i = 0; i < 4; i++) {
      printf("%f ", v[i]);
   }
   putchar('\n');
}

#endif
