/*************************************************************************/
/*  networked_multiplayer_peer_interface.h                               */
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

#ifndef GODOT_NETWORKED_MULTIPLAYER_PEER_INTERFACE
#define GODOT_NETWORKED_MULTIPLAYER_PEER_INTERFACE

#include <gdnative/gdnative.h>

#ifdef __cplusplus
extern "C" {
#endif

typedef struct {
	void *(*constructor)(godot_object *);
	void (*destructor)(void *);
	godot_int (*get_available_packet_count)(const void *);
	godot_error (*get_packet)(const void *, const uint8_t **r_buffer, int *r_buffer_size);
	godot_error (*put_packet)(const void *, const uint8_t *p_buffer, int p_buffer_size);
	godot_int (*get_max_packet_size)(const void *);
	void (*set_transfer_mode)(const void *, int p_mode);
	godot_int(*get_transfer_mode)(const void *);
	void (*set_target_peer)(const void *, int p_peer_id);
	godot_int (*get_packet_peer)(const void *);
	godot_bool (*is_server)(const void *);
	void (*poll)(const void *);
	godot_int (*get_unique_id)(const void *);
	void (*set_refuse_new_connections)(const void *, bool p_enable);
	godot_bool (*is_refusing_new_connections)(const void *);
	godot_int(*get_connection_status)(const void *);
} godot_networked_multiplayer_peer_interface_gdnative;

void GDAPI godot_networked_multiplayer_peer_register_interface(const godot_networked_multiplayer_peer_interface_gdnative *p_interface);

#ifdef __cplusplus
}
#endif

#endif /* !GODOT_NETWORKED_MULTIPLAYER_PEER_INTERFACE */
