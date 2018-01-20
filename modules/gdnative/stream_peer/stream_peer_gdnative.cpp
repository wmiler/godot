/*************************************************************************/
/*  stream_peer_gdnative.cpp                                             */
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

#include "modules/gdnative/stream_peer/stream_peer_gdnative.h"
#include "core/io/stream_peer.h"
#include "modules/gdnative/gdnative.h"

StreamPeerGDNative::StreamPeerGDNative() {
}

StreamPeerGDNative::~StreamPeerGDNative() {
}

Error StreamPeerGDNative::put_data(const uint8_t *p_data, int p_bytes) {
    return OK;
}

Error StreamPeerGDNative::put_partial_data(const uint8_t *p_data, int p_bytes, int &r_sent) {
	return OK;
}

Error StreamPeerGDNative::get_data(uint8_t *p_buffer, int p_bytes) {
    return OK;
}

Error StreamPeerGDNative::get_partial_data(uint8_t *p_buffer, int p_bytes, int &r_received) {
    return OK;
}

int StreamPeerGDNative::get_available_bytes() const {
    return 0;
}

void StreamPeerGDNative::_bind_methods() {
}
