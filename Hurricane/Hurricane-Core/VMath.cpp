#include "VMath.h"
using namespace MATH;

Vec3 VMath::reflect(const Vec3& v, const Vec3& n){
	Vec3 result;
	float scalar = 2.0f * dot(v, n);
	Vec3 temp = n * scalar;
	result = v - temp;
	return result;
}

Vec3 VMath::reflect(const Vec3& v, const Plane& p){
	/// There is some ambiguity between which "reflect" will be called
	/// below, if "reflect" sees the "plane" as a "plane," we have 
	/// infinite recursion  thus the static_cast to Vec3
	return reflect(v, static_cast<Vec3>(p));
}

Vec3 VMath::reflect2(const Vec3& v, const Plane& p){
	Vec3 result;
	float length = mag(v);
	Vec3 v2 = normalize(v);
	float scalar = 2.0f * dot(v2, p);
	Vec3 temp = p * scalar;
	result = v2 - temp;
	result = result *  length;
	return result;
}

float VMath::distance(const Vec3 &a, const Vec3 &b){
	Vec3 r = a - b;
	return(mag(r));
}

float VMath::distance(const Vec3 &v, const Plane &p){
	return v.x*p.x + v.y*p.y + v.z*p.z - p.d;
}

float VMath::distance(const Sphere &s, const Plane &p){
	return distance((Vec3)s, p) - s.r;
}
