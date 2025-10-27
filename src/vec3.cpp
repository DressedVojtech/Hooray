#include "vec3.h"

// Constructors

vec3::vec3() {
    x = 0;
    y = 0;
    z = 0;
}

vec3::vec3(float X, float Y, float Z) {
    x = X;
    y = Y;
    z = Z;
}

vec3::vec3(int X, int Y, int Z) {
    x = static_cast<float>(X);
    y = static_cast<float>(Y);
    z = static_cast<float>(Z);
}

vec3::vec3(const vec3&) = default;

// Operators

vec3 vec3::operator + (vec3 A) {
    return vec3(x + A.x, y + A.y, z + A.z);
}

vec3 vec3::operator + (float A) {
    return vec3(x + A, y + A, z + A);
}

vec3 vec3::operator - (vec3 A) {
    return vec3(x - A.x, y - A.y, z - A.z);
}

vec3 vec3::operator - (float A) {
    return vec3(x - A, y - A, z - A);
}

float vec3::operator * (vec3 A) {
    return (x*A.x + y*A.y + z*A.z);
}

vec3 vec3::operator % (vec3 A) {
    return vec3(y * A.z - z * A.y, z * A.x - x * A.z, x * A.y - y * A.x);
}

vec3 vec3::operator * (float A) {
    return vec3(x * A, y * A, z * A);
}

vec3 vec3::operator / (float A) {
    return vec3(x / A, y / A, z / A);
}

vec3& vec3::operator += (vec3 A) {
    x += A.x; y += A.y; z += A.z;
    return *this;
}

vec3& vec3::operator -= (vec3 A) {
    x -= A.x; y -= A.y; z -= A.z;
    return *this;
}

bool vec3::operator == (vec3 A) {
    return ((x == A.x) && (y == A.y) && (z == A.z));
}

bool vec3::operator != (vec3 A) {
    return  !((x == A.x) && (y == A.y) && (z == A.z));
}

float vec3::distance(vec3 A) {
    return sqrt(pow(x - A.x, 2) + pow(y - A.y, 2) + pow(z - A.z, 2));
}

float vec3::magnitude() {
    return sqrt(pow(x, 2) + pow (y, 2) + pow(z, 2));
}