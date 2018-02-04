/*************************************************************************/
/*  gi_probe.cpp                                                         */
/*************************************************************************/
/*                       This file is part of:                           */
/*                           GODOT ENGINE                                */
/*                      https://godotengine.org                          */
/*************************************************************************/
/* Copyright (c) 2007-2018 Juan Linietsky, Ariel Manzur.                 */
/* Copyright (c) 2014-2018 Godot Engine contributors (cf. AUTHORS.md)    */
/*                                                                       */
/* Permission is hereby granted, free of charge, to any person obtaining */
/* a copy of this software and associated documentation files (the       */
/* "Software"), to deal in the Software without restriction, including   */
/* without limitation the rights to use, copy, modify, merge, publish,   */
/* distribute, sublicense, and/or sell copies of the Software, and to    */
/* permit persons to whom the Software is furnished to do so, subject to */
/* the following conditions:                                             */
/*                                                                       */
/* The above copyright notice and this permission notice shall be        */
/* included in all copies or substantial portions of the Software.       */
/*                                                                       */
/* THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,       */
/* EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF    */
/* MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.*/
/* IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY  */
/* CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT,  */
/* TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE     */
/* SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.                */
/*************************************************************************/

#include "gi_probe.h"

#include "mesh_instance.h"
#include "voxel_light_baker.h"

void GIProbeData::set_bounds(const AABB &p_bounds) {

	VS::get_singleton()->gi_probe_set_bounds(probe, p_bounds);
}

AABB GIProbeData::get_bounds() const {

	return VS::get_singleton()->gi_probe_get_bounds(probe);
}

void GIProbeData::set_cell_size(float p_size) {

	VS::get_singleton()->gi_probe_set_cell_size(probe, p_size);
}

float GIProbeData::get_cell_size() const {

	return VS::get_singleton()->gi_probe_get_cell_size(probe);
}

void GIProbeData::set_to_cell_xform(const Transform &p_xform) {

	VS::get_singleton()->gi_probe_set_to_cell_xform(probe, p_xform);
}

Transform GIProbeData::get_to_cell_xform() const {

	return VS::get_singleton()->gi_probe_get_to_cell_xform(probe);
}

void GIProbeData::set_dynamic_data(const PoolVector<int> &p_data) {

	VS::get_singleton()->gi_probe_set_dynamic_data(probe, p_data);
}
PoolVector<int> GIProbeData::get_dynamic_data() const {

	return VS::get_singleton()->gi_probe_get_dynamic_data(probe);
}

void GIProbeData::set_dynamic_range(int p_range) {

	VS::get_singleton()->gi_probe_set_dynamic_range(probe, p_range);
}

void GIProbeData::set_energy(float p_range) {

	VS::get_singleton()->gi_probe_set_energy(probe, p_range);
}

float GIProbeData::get_energy() const {

	return VS::get_singleton()->gi_probe_get_energy(probe);
}

void GIProbeData::set_bias(float p_range) {

	VS::get_singleton()->gi_probe_set_bias(probe, p_range);
}

float GIProbeData::get_bias() const {

	return VS::get_singleton()->gi_probe_get_bias(probe);
}

void GIProbeData::set_normal_bias(float p_range) {

	VS::get_singleton()->gi_probe_set_normal_bias(probe, p_range);
}

float GIProbeData::get_normal_bias() const {

	return VS::get_singleton()->gi_probe_get_normal_bias(probe);
}

void GIProbeData::set_propagation(float p_range) {

	VS::get_singleton()->gi_probe_set_propagation(probe, p_range);
}

float GIProbeData::get_propagation() const {

	return VS::get_singleton()->gi_probe_get_propagation(probe);
}

void GIProbeData::set_interior(bool p_enable) {

	VS::get_singleton()->gi_probe_set_interior(probe, p_enable);
}

bool GIProbeData::is_interior() const {

	return VS::get_singleton()->gi_probe_is_interior(probe);
}

bool GIProbeData::is_compressed() const {

	return VS::get_singleton()->gi_probe_is_compressed(probe);
}

void GIProbeData::set_compress(bool p_enable) {

	VS::get_singleton()->gi_probe_set_compress(probe, p_enable);
}

int GIProbeData::get_dynamic_range() const {

	return VS::get_singleton()->gi_probe_get_dynamic_range(probe);
}

RID GIProbeData::get_rid() const {

	return probe;
}

void GIProbeData::_bind_methods() {

	ClassDB::bind_method(D_METHOD("set_bounds", "bounds"), &GIProbeData::set_bounds);
	ClassDB::bind_method(D_METHOD("get_bounds"), &GIProbeData::get_bounds);

	ClassDB::bind_method(D_METHOD("set_cell_size", "cell_size"), &GIProbeData::set_cell_size);
	ClassDB::bind_method(D_METHOD("get_cell_size"), &GIProbeData::get_cell_size);

	ClassDB::bind_method(D_METHOD("set_to_cell_xform", "to_cell_xform"), &GIProbeData::set_to_cell_xform);
	ClassDB::bind_method(D_METHOD("get_to_cell_xform"), &GIProbeData::get_to_cell_xform);

	ClassDB::bind_method(D_METHOD("set_dynamic_data", "dynamic_data"), &GIProbeData::set_dynamic_data);
	ClassDB::bind_method(D_METHOD("get_dynamic_data"), &GIProbeData::get_dynamic_data);

	ClassDB::bind_method(D_METHOD("set_dynamic_range", "dynamic_range"), &GIProbeData::set_dynamic_range);
	ClassDB::bind_method(D_METHOD("get_dynamic_range"), &GIProbeData::get_dynamic_range);

	ClassDB::bind_method(D_METHOD("set_energy", "energy"), &GIProbeData::set_energy);
	ClassDB::bind_method(D_METHOD("get_energy"), &GIProbeData::get_energy);

	ClassDB::bind_method(D_METHOD("set_bias", "bias"), &GIProbeData::set_bias);
	ClassDB::bind_method(D_METHOD("get_bias"), &GIProbeData::get_bias);

	ClassDB::bind_method(D_METHOD("set_normal_bias", "bias"), &GIProbeData::set_normal_bias);
	ClassDB::bind_method(D_METHOD("get_normal_bias"), &GIProbeData::get_normal_bias);

	ClassDB::bind_method(D_METHOD("set_propagation", "propagation"), &GIProbeData::set_propagation);
	ClassDB::bind_method(D_METHOD("get_propagation"), &GIProbeData::get_propagation);

	ClassDB::bind_method(D_METHOD("set_interior", "interior"), &GIProbeData::set_interior);
	ClassDB::bind_method(D_METHOD("is_interior"), &GIProbeData::is_interior);

	ClassDB::bind_method(D_METHOD("set_compress", "compress"), &GIProbeData::set_compress);
	ClassDB::bind_method(D_METHOD("is_compressed"), &GIProbeData::is_compressed);

	ADD_PROPERTY(PropertyInfo(Variant::AABB, "bounds", PROPERTY_HINT_NONE, "", PROPERTY_USAGE_NOEDITOR), "set_bounds", "get_bounds");
	ADD_PROPERTY(PropertyInfo(Variant::REAL, "cell_size", PROPERTY_HINT_NONE, "", PROPERTY_USAGE_NOEDITOR), "set_cell_size", "get_cell_size");
	ADD_PROPERTY(PropertyInfo(Variant::TRANSFORM, "to_cell_xform", PROPERTY_HINT_NONE, "", PROPERTY_USAGE_NOEDITOR), "set_to_cell_xform", "get_to_cell_xform");

	ADD_PROPERTY(PropertyInfo(Variant::POOL_INT_ARRAY, "dynamic_data", PROPERTY_HINT_NONE, "", PROPERTY_USAGE_NOEDITOR), "set_dynamic_data", "get_dynamic_data");
	ADD_PROPERTY(PropertyInfo(Variant::INT, "dynamic_range", PROPERTY_HINT_NONE, "", PROPERTY_USAGE_NOEDITOR), "set_dynamic_range", "get_dynamic_range");
	ADD_PROPERTY(PropertyInfo(Variant::REAL, "energy", PROPERTY_HINT_NONE, "", PROPERTY_USAGE_NOEDITOR), "set_energy", "get_energy");
	ADD_PROPERTY(PropertyInfo(Variant::REAL, "bias", PROPERTY_HINT_NONE, "", PROPERTY_USAGE_NOEDITOR), "set_bias", "get_bias");
	ADD_PROPERTY(PropertyInfo(Variant::REAL, "normal_bias", PROPERTY_HINT_NONE, "", PROPERTY_USAGE_NOEDITOR), "set_normal_bias", "get_normal_bias");
	ADD_PROPERTY(PropertyInfo(Variant::REAL, "propagation", PROPERTY_HINT_NONE, "", PROPERTY_USAGE_NOEDITOR), "set_propagation", "get_propagation");
	ADD_PROPERTY(PropertyInfo(Variant::BOOL, "interior", PROPERTY_HINT_NONE, "", PROPERTY_USAGE_NOEDITOR), "set_interior", "is_interior");
	ADD_PROPERTY(PropertyInfo(Variant::BOOL, "compress", PROPERTY_HINT_NONE, "", PROPERTY_USAGE_NOEDITOR), "set_compress", "is_compressed");
}

GIProbeData::GIProbeData() {

	probe = VS::get_singleton()->gi_probe_create();
}

GIProbeData::~GIProbeData() {

	VS::get_singleton()->free(probe);
}

//////////////////////
//////////////////////

void GIProbe::set_probe_data(const Ref<GIProbeData> &p_data) {

	if (p_data.is_valid()) {
		VS::get_singleton()->instance_set_base(get_instance(), p_data->get_rid());
	} else {
		VS::get_singleton()->instance_set_base(get_instance(), RID());
	}

	probe_data = p_data;
}

Ref<GIProbeData> GIProbe::get_probe_data() const {

	return probe_data;
}

void GIProbe::set_subdiv(Subdiv p_subdiv) {

	ERR_FAIL_INDEX(p_subdiv, SUBDIV_MAX);
	subdiv = p_subdiv;
	update_gizmo();
}

GIProbe::Subdiv GIProbe::get_subdiv() const {

	return subdiv;
}

void GIProbe::set_extents(const Vector3 &p_extents) {

	extents = p_extents;
	update_gizmo();
}

Vector3 GIProbe::get_extents() const {

	return extents;
}

void GIProbe::set_dynamic_range(int p_dynamic_range) {

	dynamic_range = p_dynamic_range;
}
int GIProbe::get_dynamic_range() const {

	return dynamic_range;
}

void GIProbe::set_energy(float p_energy) {

	energy = p_energy;
	if (probe_data.is_valid()) {
		probe_data->set_energy(energy);
	}
}
float GIProbe::get_energy() const {

	return energy;
}

void GIProbe::set_bias(float p_bias) {

	bias = p_bias;
	if (probe_data.is_valid()) {
		probe_data->set_bias(bias);
	}
}
float GIProbe::get_bias() const {

	return bias;
}

void GIProbe::set_normal_bias(float p_normal_bias) {

	normal_bias = p_normal_bias;
	if (probe_data.is_valid()) {
		probe_data->set_normal_bias(normal_bias);
	}
}
float GIProbe::get_normal_bias() const {

	return normal_bias;
}

void GIProbe::set_propagation(float p_propagation) {

	propagation = p_propagation;
	if (probe_data.is_valid()) {
		probe_data->set_propagation(propagation);
	}
}
float GIProbe::get_propagation() const {

	return propagation;
}

void GIProbe::set_interior(bool p_enable) {

	interior = p_enable;
	if (probe_data.is_valid()) {
		probe_data->set_interior(p_enable);
	}
}

bool GIProbe::is_interior() const {

	return interior;
}

void GIProbe::set_compress(bool p_enable) {

	compress = p_enable;
	if (probe_data.is_valid()) {
		probe_data->set_compress(p_enable);
	}
}

bool GIProbe::is_compressed() const {

	return compress;
}

#include "math.h"

#define FINDMINMAX(x0, x1, x2, min, max) \
	min = max = x0;                      \
	if (x1 < min) min = x1;              \
	if (x1 > max) max = x1;              \
	if (x2 < min) min = x2;              \
	if (x2 > max) max = x2;

static bool planeBoxOverlap(Vector3 normal, float d, Vector3 maxbox) {
	int q;
	Vector3 vmin, vmax;
	for (q = 0; q <= 2; q++) {
		if (normal[q] > 0.0f) {
			vmin[q] = -maxbox[q];
			vmax[q] = maxbox[q];
		} else {
			vmin[q] = maxbox[q];
			vmax[q] = -maxbox[q];
		}
	}
	if (normal.dot(vmin) + d > 0.0f) return false;
	if (normal.dot(vmax) + d >= 0.0f) return true;

	return false;
}

/*======================== X-tests ========================*/
#define AXISTEST_X01(a, b, fa, fb)                 \
	p0 = a * v0.y - b * v0.z;                      \
	p2 = a * v2.y - b * v2.z;                      \
	if (p0 < p2) {                                 \
		min = p0;                                  \
		max = p2;                                  \
	} else {                                       \
		min = p2;                                  \
		max = p0;                                  \
	}                                              \
	rad = fa * boxhalfsize.y + fb * boxhalfsize.z; \
	if (min > rad || max < -rad) return false;

#define AXISTEST_X2(a, b, fa, fb)                  \
	p0 = a * v0.y - b * v0.z;                      \
	p1 = a * v1.y - b * v1.z;                      \
	if (p0 < p1) {                                 \
		min = p0;                                  \
		max = p1;                                  \
	} else {                                       \
		min = p1;                                  \
		max = p0;                                  \
	}                                              \
	rad = fa * boxhalfsize.y + fb * boxhalfsize.z; \
	if (min > rad || max < -rad) return false;

/*======================== Y-tests ========================*/
#define AXISTEST_Y02(a, b, fa, fb)                 \
	p0 = -a * v0.x + b * v0.z;                     \
	p2 = -a * v2.x + b * v2.z;                     \
	if (p0 < p2) {                                 \
		min = p0;                                  \
		max = p2;                                  \
	} else {                                       \
		min = p2;                                  \
		max = p0;                                  \
	}                                              \
	rad = fa * boxhalfsize.x + fb * boxhalfsize.z; \
	if (min > rad || max < -rad) return false;

#define AXISTEST_Y1(a, b, fa, fb)                  \
	p0 = -a * v0.x + b * v0.z;                     \
	p1 = -a * v1.x + b * v1.z;                     \
	if (p0 < p1) {                                 \
		min = p0;                                  \
		max = p1;                                  \
	} else {                                       \
		min = p1;                                  \
		max = p0;                                  \
	}                                              \
	rad = fa * boxhalfsize.x + fb * boxhalfsize.z; \
	if (min > rad || max < -rad) return false;

/*======================== Z-tests ========================*/

#define AXISTEST_Z12(a, b, fa, fb)                 \
	p1 = a * v1.x - b * v1.y;                      \
	p2 = a * v2.x - b * v2.y;                      \
	if (p2 < p1) {                                 \
		min = p2;                                  \
		max = p1;                                  \
	} else {                                       \
		min = p1;                                  \
		max = p2;                                  \
	}                                              \
	rad = fa * boxhalfsize.x + fb * boxhalfsize.y; \
	if (min > rad || max < -rad) return false;

#define AXISTEST_Z0(a, b, fa, fb)                  \
	p0 = a * v0.x - b * v0.y;                      \
	p1 = a * v1.x - b * v1.y;                      \
	if (p0 < p1) {                                 \
		min = p0;                                  \
		max = p1;                                  \
	} else {                                       \
		min = p1;                                  \
		max = p0;                                  \
	}                                              \
	rad = fa * boxhalfsize.x + fb * boxhalfsize.y; \
	if (min > rad || max < -rad) return false;

static bool fast_tri_box_overlap(const Vector3 &boxcenter, const Vector3 boxhalfsize, const Vector3 *triverts) {

	/*    use separating axis theorem to test overlap between triangle and box */
	/*    need to test for overlap in these directions: */
	/*    1) the {x,y,z}-directions (actually, since we use the AABB of the triangle */
	/*       we do not even need to test these) */
	/*    2) normal of the triangle */
	/*    3) crossproduct(edge from tri, {x,y,z}-directin) */
	/*       this gives 3x3=9 more tests */
	Vector3 v0, v1, v2;
	float min, max, d, p0, p1, p2, rad, fex, fey, fez;
	Vector3 normal, e0, e1, e2;

	/* This is the fastest branch on Sun */
	/* move everything so that the boxcenter is in (0,0,0) */

	v0 = triverts[0] - boxcenter;
	v1 = triverts[1] - boxcenter;
	v2 = triverts[2] - boxcenter;

	/* compute triangle edges */
	e0 = v1 - v0; /* tri edge 0 */
	e1 = v2 - v1; /* tri edge 1 */
	e2 = v0 - v2; /* tri edge 2 */

	/* Bullet 3:  */
	/*  test the 9 tests first (this was faster) */
	fex = Math::abs(e0.x);
	fey = Math::abs(e0.y);
	fez = Math::abs(e0.z);
	AXISTEST_X01(e0.z, e0.y, fez, fey);
	AXISTEST_Y02(e0.z, e0.x, fez, fex);
	AXISTEST_Z12(e0.y, e0.x, fey, fex);

	fex = Math::abs(e1.x);
	fey = Math::abs(e1.y);
	fez = Math::abs(e1.z);
	AXISTEST_X01(e1.z, e1.y, fez, fey);
	AXISTEST_Y02(e1.z, e1.x, fez, fex);
	AXISTEST_Z0(e1.y, e1.x, fey, fex);

	fex = Math::abs(e2.x);
	fey = Math::abs(e2.y);
	fez = Math::abs(e2.z);
	AXISTEST_X2(e2.z, e2.y, fez, fey);
	AXISTEST_Y1(e2.z, e2.x, fez, fex);
	AXISTEST_Z12(e2.y, e2.x, fey, fex);

	/* Bullet 1: */
	/*  first test overlap in the {x,y,z}-directions */
	/*  find min, max of the triangle each direction, and test for overlap in */
	/*  that direction -- this is equivalent to testing a minimal AABB around */
	/*  the triangle against the AABB */

	/* test in X-direction */
	FINDMINMAX(v0.x, v1.x, v2.x, min, max);
	if (min > boxhalfsize.x || max < -boxhalfsize.x) return false;

	/* test in Y-direction */
	FINDMINMAX(v0.y, v1.y, v2.y, min, max);
	if (min > boxhalfsize.y || max < -boxhalfsize.y) return false;

	/* test in Z-direction */
	FINDMINMAX(v0.z, v1.z, v2.z, min, max);
	if (min > boxhalfsize.z || max < -boxhalfsize.z) return false;

	/* Bullet 2: */
	/*  test if the box intersects the plane of the triangle */
	/*  compute plane equation of triangle: normal*x+d=0 */
	normal = e0.cross(e1);
	d = -normal.dot(v0); /* plane eq: normal.x+d=0 */
	if (!planeBoxOverlap(normal, d, boxhalfsize)) return false;

	return true; /* box and triangle overlaps */
}

static _FORCE_INLINE_ Vector2 get_uv(const Vector3 &p_pos, const Vector3 *p_vtx, const Vector2 *p_uv) {

	if (p_pos.distance_squared_to(p_vtx[0]) < CMP_EPSILON2)
		return p_uv[0];
	if (p_pos.distance_squared_to(p_vtx[1]) < CMP_EPSILON2)
		return p_uv[1];
	if (p_pos.distance_squared_to(p_vtx[2]) < CMP_EPSILON2)
		return p_uv[2];

	Vector3 v0 = p_vtx[1] - p_vtx[0];
	Vector3 v1 = p_vtx[2] - p_vtx[0];
	Vector3 v2 = p_pos - p_vtx[0];

	float d00 = v0.dot(v0);
	float d01 = v0.dot(v1);
	float d11 = v1.dot(v1);
	float d20 = v2.dot(v0);
	float d21 = v2.dot(v1);
	float denom = (d00 * d11 - d01 * d01);
	if (denom == 0)
		return p_uv[0];
	float v = (d11 * d20 - d01 * d21) / denom;
	float w = (d00 * d21 - d01 * d20) / denom;
	float u = 1.0f - v - w;

	return p_uv[0] * u + p_uv[1] * v + p_uv[2] * w;
}

void GIProbe::_plot_face(int p_idx, int p_level, int p_x, int p_y, int p_z, const Vector3 *p_vtx, const Vector2 *p_uv, const Baker::MaterialCache &p_material, const Rect3 &p_aabb, Baker *p_baker) {

	if (p_level == p_baker->cell_subdiv - 1) {
		//plot the face by guessing it's albedo and emission value

		//find best axis to map to, for scanning values
		int closest_axis = 0;
		float closest_dot = 0;

		Plane plane = Plane(p_vtx[0], p_vtx[1], p_vtx[2]);
		Vector3 normal = plane.normal;

		for (int i = 0; i < 3; i++) {

			Vector3 axis;
			axis[i] = 1.0;
			float dot = ABS(normal.dot(axis));
			if (i == 0 || dot > closest_dot) {
				closest_axis = i;
				closest_dot = dot;
			}
		}

		Vector3 axis;
		axis[closest_axis] = 1.0;
		Vector3 t1;
		t1[(closest_axis + 1) % 3] = 1.0;
		Vector3 t2;
		t2[(closest_axis + 2) % 3] = 1.0;

		t1 *= p_aabb.size[(closest_axis + 1) % 3] / float(color_scan_cell_width);
		t2 *= p_aabb.size[(closest_axis + 2) % 3] / float(color_scan_cell_width);

		Color albedo_accum;
		Color emission_accum;
		Vector3 normal_accum;

		float alpha = 0.0;

		//map to a grid average in the best axis for this face
		for (int i = 0; i < color_scan_cell_width; i++) {

			Vector3 ofs_i = float(i) * t1;

			for (int j = 0; j < color_scan_cell_width; j++) {

				Vector3 ofs_j = float(j) * t2;

				Vector3 from = p_aabb.position + ofs_i + ofs_j;
				Vector3 to = from + t1 + t2 + axis * p_aabb.size[closest_axis];
				Vector3 half = (to - from) * 0.5;

				//is in this cell?
				if (!fast_tri_box_overlap(from + half, half, p_vtx)) {
					continue; //face does not span this cell
				}

				//go from -size to +size*2 to avoid skipping collisions
				Vector3 ray_from = from + (t1 + t2) * 0.5 - axis * p_aabb.size[closest_axis];
				Vector3 ray_to = ray_from + axis * p_aabb.size[closest_axis] * 2;

				if (normal.dot(ray_from - ray_to) < 0) {
					SWAP(ray_from, ray_to);
				}

				Vector3 intersection;

				if (!plane.intersects_segment(ray_from, ray_to, &intersection)) {
					if (ABS(plane.distance_to(ray_from)) < ABS(plane.distance_to(ray_to))) {
						intersection = plane.project(ray_from);
					} else {

						intersection = plane.project(ray_to);
					}
				}

				intersection = Face3(p_vtx[0], p_vtx[1], p_vtx[2]).get_closest_point_to(intersection);

				Vector2 uv = get_uv(intersection, p_vtx, p_uv);

				int uv_x = CLAMP(Math::fposmod(uv.x, static_cast<size_t>(1.0f)) * bake_texture_size, 0, bake_texture_size - 1);
				int uv_y = CLAMP(Math::fposmod(uv.y, static_cast<size_t>(1.0f)) * bake_texture_size, 0, bake_texture_size - 1);

				int ofs = uv_y * bake_texture_size + uv_x;
				albedo_accum.r += p_material.albedo[ofs].r;
				albedo_accum.g += p_material.albedo[ofs].g;
				albedo_accum.b += p_material.albedo[ofs].b;
				albedo_accum.a += p_material.albedo[ofs].a;

				emission_accum.r += p_material.emission[ofs].r;
				emission_accum.g += p_material.emission[ofs].g;
				emission_accum.b += p_material.emission[ofs].b;

				normal_accum += normal;

				alpha += 1.0;
			}
		}

		if (alpha == 0) {
			//could not in any way get texture information.. so use closest point to center

			Face3 f(p_vtx[0], p_vtx[1], p_vtx[2]);
			Vector3 inters = f.get_closest_point_to(p_aabb.position + p_aabb.size * 0.5);

			Vector2 uv = get_uv(inters, p_vtx, p_uv);

			int uv_x = CLAMP(Math::fposmod(uv.x, static_cast<size_t>(1.0)) * bake_texture_size, 0, bake_texture_size - 1);
			int uv_y = CLAMP(Math::fposmod(uv.y, static_cast<size_t>(1.0)) * bake_texture_size, 0, bake_texture_size - 1);

			int ofs = uv_y * bake_texture_size + uv_x;

			alpha = static_cast<size_t>(1.0) / (color_scan_cell_width * color_scan_cell_width);

			albedo_accum.r = p_material.albedo[ofs].r * alpha;
			albedo_accum.g = p_material.albedo[ofs].g * alpha;
			albedo_accum.b = p_material.albedo[ofs].b * alpha;
			albedo_accum.a = p_material.albedo[ofs].a * alpha;

			emission_accum.r = p_material.emission[ofs].r * alpha;
			emission_accum.g = p_material.emission[ofs].g * alpha;
			emission_accum.b = p_material.emission[ofs].b * alpha;

			normal_accum *= alpha;

		} else {

			float accdiv = 1.0 / (color_scan_cell_width * color_scan_cell_width);
			alpha *= accdiv;

			albedo_accum.r *= accdiv;
			albedo_accum.g *= accdiv;
			albedo_accum.b *= accdiv;
			albedo_accum.a *= accdiv;

			emission_accum.r *= accdiv;
			emission_accum.g *= accdiv;
			emission_accum.b *= accdiv;

			normal_accum *= accdiv;
		}

		//put this temporarily here, corrected in a later step
		p_baker->bake_cells[p_idx].albedo[0] += albedo_accum.r;
		p_baker->bake_cells[p_idx].albedo[1] += albedo_accum.g;
		p_baker->bake_cells[p_idx].albedo[2] += albedo_accum.b;
		p_baker->bake_cells[p_idx].emission[0] += emission_accum.r;
		p_baker->bake_cells[p_idx].emission[1] += emission_accum.g;
		p_baker->bake_cells[p_idx].emission[2] += emission_accum.b;
		p_baker->bake_cells[p_idx].normal[0] += normal_accum.x;
		p_baker->bake_cells[p_idx].normal[1] += normal_accum.y;
		p_baker->bake_cells[p_idx].normal[2] += normal_accum.z;
		p_baker->bake_cells[p_idx].alpha += alpha;

	} else {
		//go down

		int half = (1 << (p_baker->cell_subdiv - 1)) >> (p_level + 1);
		for (int i = 0; i < 8; i++) {

			Rect3 aabb = p_aabb;
			aabb.size *= 0.5;

			int nx = p_x;
			int ny = p_y;
			int nz = p_z;

			if (i & 1) {
				aabb.position.x += aabb.size.x;
				nx += half;
			}
			if (i & 2) {
				aabb.position.y += aabb.size.y;
				ny += half;
			}
			if (i & 4) {
				aabb.position.z += aabb.size.z;
				nz += half;
			}
			//make sure to not plot beyond limits
			if (nx < 0 || nx >= p_baker->axis_cell_size[0] || ny < 0 || ny >= p_baker->axis_cell_size[1] || nz < 0 || nz >= p_baker->axis_cell_size[2])
				continue;

			{
				Rect3 test_aabb = aabb;
				//test_aabb.grow_by(test_aabb.get_longest_axis_size()*0.05); //grow a bit to avoid numerical error in real-time
				Vector3 qsize = test_aabb.size * 0.5; //quarter size, for fast aabb test

				if (!fast_tri_box_overlap(test_aabb.position + qsize, qsize, p_vtx)) {
					//if (!Face3(p_vtx[0],p_vtx[1],p_vtx[2]).intersects_aabb2(aabb)) {
					//does not fit in child, go on
					continue;
				}
			}

			if (p_baker->bake_cells[p_idx].childs[i] == Baker::CHILD_EMPTY) {
				//sub cell must be created

				uint32_t child_idx = p_baker->bake_cells.size();
				p_baker->bake_cells[p_idx].childs[i] = child_idx;
				p_baker->bake_cells.resize(p_baker->bake_cells.size() + 1);
				p_baker->bake_cells[child_idx].level = p_level + 1;
			}

			_plot_face(p_baker->bake_cells[p_idx].childs[i], p_level + 1, nx, ny, nz, p_vtx, p_uv, p_material, aabb, p_baker);
		}
	}
}

void GIProbe::_fixup_plot(int p_idx, int p_level, int p_x, int p_y, int p_z, Baker *p_baker) {

	if (p_level == p_baker->cell_subdiv - 1) {

		p_baker->leaf_voxel_count++;
		float alpha = p_baker->bake_cells[p_idx].alpha;

		p_baker->bake_cells[p_idx].albedo[0] /= alpha;
		p_baker->bake_cells[p_idx].albedo[1] /= alpha;
		p_baker->bake_cells[p_idx].albedo[2] /= alpha;

		//transfer emission to light
		p_baker->bake_cells[p_idx].emission[0] /= alpha;
		p_baker->bake_cells[p_idx].emission[1] /= alpha;
		p_baker->bake_cells[p_idx].emission[2] /= alpha;

		p_baker->bake_cells[p_idx].normal[0] /= alpha;
		p_baker->bake_cells[p_idx].normal[1] /= alpha;
		p_baker->bake_cells[p_idx].normal[2] /= alpha;

		Vector3 n(p_baker->bake_cells[p_idx].normal[0], p_baker->bake_cells[p_idx].normal[1], p_baker->bake_cells[p_idx].normal[2]);
		if (n.length() < 0.01) {
			//too much fight over normal, zero it
			p_baker->bake_cells[p_idx].normal[0] = 0;
			p_baker->bake_cells[p_idx].normal[1] = 0;
			p_baker->bake_cells[p_idx].normal[2] = 0;
		} else {
			n.normalize();
			p_baker->bake_cells[p_idx].normal[0] = n.x;
			p_baker->bake_cells[p_idx].normal[1] = n.y;
			p_baker->bake_cells[p_idx].normal[2] = n.z;
		}

		p_baker->bake_cells[p_idx].alpha = 1.0;

		/*
		//remove neighbours from used sides

		for(int n=0;n<6;n++) {

			int ofs[3]={0,0,0};

			ofs[n/2]=(n&1)?1:-1;

			//convert to x,y,z on this level
			int x=p_x;
			int y=p_y;
			int z=p_z;

			x+=ofs[0];
			y+=ofs[1];
			z+=ofs[2];

			int ofs_x=0;
			int ofs_y=0;
			int ofs_z=0;
			int size = 1<<p_level;
			int half=size/2;


			if (x<0 || x>=size || y<0 || y>=size || z<0 || z>=size) {
				//neighbour is out, can't use it
				p_baker->bake_cells[p_idx].used_sides&=~(1<<uint32_t(n));
				continue;
			}

			uint32_t neighbour=0;

			for(int i=0;i<p_baker->cell_subdiv-1;i++) {

				Baker::Cell *bc = &p_baker->bake_cells[neighbour];

				int child = 0;
				if (x >= ofs_x + half) {
					child|=1;
					ofs_x+=half;
				}
				if (y >= ofs_y + half) {
					child|=2;
					ofs_y+=half;
				}
				if (z >= ofs_z + half) {
					child|=4;
					ofs_z+=half;
				}

				neighbour = bc->childs[child];
				if (neighbour==Baker::CHILD_EMPTY) {
					break;
				}

				half>>=1;
			}

			if (neighbour!=Baker::CHILD_EMPTY) {
				p_baker->bake_cells[p_idx].used_sides&=~(1<<uint32_t(n));
			}
		}
		*/
	} else {

	MeshInstance *mi = Object::cast_to<MeshInstance>(p_at_node);
	if (mi && mi->get_flag(GeometryInstance::FLAG_USE_BAKED_LIGHT) && mi->is_visible_in_tree()) {
		Ref<Mesh> mesh = mi->get_mesh();
		if (mesh.is_valid()) {

			AABB aabb = mesh->get_aabb();

			Transform xf = get_global_transform().affine_inverse() * mi->get_global_transform();

			if (AABB(-extents, extents * 2).intersects(xf.xform(aabb))) {
				PlotMesh pm;
				pm.local_xform = xf;
				pm.mesh = mesh;
				for (int i = 0; i < mesh->get_surface_count(); i++) {
					pm.instance_materials.push_back(mi->get_surface_material(i));
				}
				pm.override_material = mi->get_material_override();
				plot_meshes.push_back(pm);
			}
		}
	}

	Spatial *s = Object::cast_to<Spatial>(p_at_node);
	if (s) {

		if (s->is_visible_in_tree()) {

			Array meshes = p_at_node->call("get_meshes");
			for (int i = 0; i < meshes.size(); i += 2) {

				Transform mxf = meshes[i];
				Ref<Mesh> mesh = meshes[i + 1];
				if (!mesh.is_valid())
					continue;

				AABB aabb = mesh->get_aabb();

				Transform xf = get_global_transform().affine_inverse() * (s->get_global_transform() * mxf);

				if (AABB(-extents, extents * 2).intersects(xf.xform(aabb))) {
					PlotMesh pm;
					pm.local_xform = xf;
					pm.mesh = mesh;
					plot_meshes.push_back(pm);
				}
			}
		}
	}

	for (int i = 0; i < p_at_node->get_child_count(); i++) {

		Node *child = p_at_node->get_child(i);
		if (!child->get_owner())
			continue; //maybe a helper

		_find_meshes(child, plot_meshes);
	}
}

GIProbe::BakeBeginFunc GIProbe::bake_begin_function = NULL;
GIProbe::BakeStepFunc GIProbe::bake_step_function = NULL;
GIProbe::BakeEndFunc GIProbe::bake_end_function = NULL;

void GIProbe::bake(Node *p_from_node, bool p_create_visual_debug) {

	static const int subdiv_value[SUBDIV_MAX] = { 7, 8, 9, 10 };

	VoxelLightBaker baker;

	baker.begin_bake(subdiv_value[subdiv], AABB(-extents, extents * 2.0));

	List<PlotMesh> mesh_list;

	_find_meshes(p_from_node ? p_from_node : get_parent(), mesh_list);

	if (bake_begin_function) {
		bake_begin_function(mesh_list.size() + 1);
	}

	int pmc = 0;

	for (List<PlotMesh>::Element *E = mesh_list.front(); E; E = E->next()) {

		if (bake_step_function) {
			bake_step_function(pmc, RTR("Plotting Meshes") + " " + itos(pmc) + "/" + itos(mesh_list.size()));
		}

		pmc++;

		baker.plot_mesh(E->get().local_xform, E->get().mesh, E->get().instance_materials, E->get().override_material);
	}
	if (bake_step_function) {
		bake_step_function(pmc++, RTR("Finishing Plot"));
	}

	baker.end_bake();

	//create the data for visual server

	PoolVector<int> data = baker.create_gi_probe_data();

	if (p_create_visual_debug) {
		MultiMeshInstance *mmi = memnew(MultiMeshInstance);
		mmi->set_multimesh(baker.create_debug_multimesh());
		add_child(mmi);
#ifdef TOOLS_ENABLED
		if (get_tree()->get_edited_scene_root() == this) {
			mmi->set_owner(this);
		} else {
			mmi->set_owner(get_owner());
		}
#else
		mmi->set_owner(get_owner());
#endif

	} else {

		Ref<GIProbeData> probe_data = get_probe_data();

		if (probe_data.is_null())
			probe_data.instance();

		probe_data->set_bounds(AABB(-extents, extents * 2.0));
		probe_data->set_cell_size(baker.get_cell_size());
		probe_data->set_dynamic_data(data);
		probe_data->set_dynamic_range(dynamic_range);
		probe_data->set_energy(energy);
		probe_data->set_bias(bias);
		probe_data->set_normal_bias(normal_bias);
		probe_data->set_propagation(propagation);
		probe_data->set_interior(interior);
		probe_data->set_compress(compress);
		probe_data->set_to_cell_xform(baker.get_to_cell_space_xform());

		set_probe_data(probe_data);
	}

	if (bake_end_function) {
		bake_end_function();
	}
}

void GIProbe::_debug_bake() {

	bake(NULL, true);
}

AABB GIProbe::get_aabb() const {

	return AABB(-extents, extents * 2);
}

PoolVector<Face3> GIProbe::get_faces(uint32_t p_usage_flags) const {

	return PoolVector<Face3>();
}

void GIProbe::_bind_methods() {

	ClassDB::bind_method(D_METHOD("set_probe_data", "data"), &GIProbe::set_probe_data);
	ClassDB::bind_method(D_METHOD("get_probe_data"), &GIProbe::get_probe_data);

	ClassDB::bind_method(D_METHOD("set_subdiv", "subdiv"), &GIProbe::set_subdiv);
	ClassDB::bind_method(D_METHOD("get_subdiv"), &GIProbe::get_subdiv);

	ClassDB::bind_method(D_METHOD("set_extents", "extents"), &GIProbe::set_extents);
	ClassDB::bind_method(D_METHOD("get_extents"), &GIProbe::get_extents);

	ClassDB::bind_method(D_METHOD("set_dynamic_range", "max"), &GIProbe::set_dynamic_range);
	ClassDB::bind_method(D_METHOD("get_dynamic_range"), &GIProbe::get_dynamic_range);

	ClassDB::bind_method(D_METHOD("set_energy", "max"), &GIProbe::set_energy);
	ClassDB::bind_method(D_METHOD("get_energy"), &GIProbe::get_energy);

	ClassDB::bind_method(D_METHOD("set_bias", "max"), &GIProbe::set_bias);
	ClassDB::bind_method(D_METHOD("get_bias"), &GIProbe::get_bias);

	ClassDB::bind_method(D_METHOD("set_normal_bias", "max"), &GIProbe::set_normal_bias);
	ClassDB::bind_method(D_METHOD("get_normal_bias"), &GIProbe::get_normal_bias);

	ClassDB::bind_method(D_METHOD("set_propagation", "max"), &GIProbe::set_propagation);
	ClassDB::bind_method(D_METHOD("get_propagation"), &GIProbe::get_propagation);

	ClassDB::bind_method(D_METHOD("set_interior", "enable"), &GIProbe::set_interior);
	ClassDB::bind_method(D_METHOD("is_interior"), &GIProbe::is_interior);

	ClassDB::bind_method(D_METHOD("set_compress", "enable"), &GIProbe::set_compress);
	ClassDB::bind_method(D_METHOD("is_compressed"), &GIProbe::is_compressed);

	ClassDB::bind_method(D_METHOD("bake", "from_node", "create_visual_debug"), &GIProbe::bake, DEFVAL(Variant()), DEFVAL(false));
	ClassDB::bind_method(D_METHOD("debug_bake"), &GIProbe::_debug_bake);
	ClassDB::set_method_flags(get_class_static(), _scs_create("debug_bake"), METHOD_FLAGS_DEFAULT | METHOD_FLAG_EDITOR);

	ADD_PROPERTY(PropertyInfo(Variant::INT, "subdiv", PROPERTY_HINT_ENUM, "64,128,256,512"), "set_subdiv", "get_subdiv");
	ADD_PROPERTY(PropertyInfo(Variant::VECTOR3, "extents"), "set_extents", "get_extents");
	ADD_PROPERTY(PropertyInfo(Variant::INT, "dynamic_range", PROPERTY_HINT_RANGE, "1,16,1"), "set_dynamic_range", "get_dynamic_range");
	ADD_PROPERTY(PropertyInfo(Variant::REAL, "energy", PROPERTY_HINT_RANGE, "0,16,0.01"), "set_energy", "get_energy");
	ADD_PROPERTY(PropertyInfo(Variant::REAL, "propagation", PROPERTY_HINT_RANGE, "0,1,0.01"), "set_propagation", "get_propagation");
	ADD_PROPERTY(PropertyInfo(Variant::REAL, "bias", PROPERTY_HINT_RANGE, "0,4,0.001"), "set_bias", "get_bias");
	ADD_PROPERTY(PropertyInfo(Variant::REAL, "normal_bias", PROPERTY_HINT_RANGE, "0,4,0.001"), "set_normal_bias", "get_normal_bias");
	ADD_PROPERTY(PropertyInfo(Variant::BOOL, "interior"), "set_interior", "is_interior");
	ADD_PROPERTY(PropertyInfo(Variant::BOOL, "compress"), "set_compress", "is_compressed");
	ADD_PROPERTY(PropertyInfo(Variant::OBJECT, "data", PROPERTY_HINT_RESOURCE_TYPE, "GIProbeData", PROPERTY_USAGE_DEFAULT | PROPERTY_USAGE_DO_NOT_SHARE_ON_DUPLICATE), "set_probe_data", "get_probe_data");

	BIND_ENUM_CONSTANT(SUBDIV_64);
	BIND_ENUM_CONSTANT(SUBDIV_128);
	BIND_ENUM_CONSTANT(SUBDIV_256);
	BIND_ENUM_CONSTANT(SUBDIV_512);
	BIND_ENUM_CONSTANT(SUBDIV_MAX);
}

GIProbe::GIProbe() {

	subdiv = SUBDIV_128;
	dynamic_range = 4;
	energy = 1.0;
	bias = 1.5;
	normal_bias = 0.0;
	propagation = 0.7;
	extents = Vector3(10, 10, 10);
	interior = false;
	compress = false;

	gi_probe = VS::get_singleton()->gi_probe_create();
}

GIProbe::~GIProbe() {
}
