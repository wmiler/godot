/*************************************************************************/
/*  networked_multiplayer_peer_gdnative.cpp                              */
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

#include "networked_multiplayer_peer_gdnative.h"
#include "core/io/networked_multiplayer_peer.h"

NetworkedMultiplayerPeerGDNative::NetworkedMultiplayerPeerGDNative() {
	data = nullptr;
	interface = nullptr;
}

NetworkedMultiplayerPeerGDNative::~NetworkedMultiplayerPeerGDNative() {
	//if (is_initialized()) {
	//	uninitialize();
	//};

	// cleanup after ourselves
	cleanup();
}

void NetworkedMultiplayerPeerGDNative::cleanup() {
	if (interface != NULL) {
		// interface->destructor(data);
		data = NULL;
		interface = NULL;
	}
}

void NetworkedMultiplayerPeerGDNative::set_interface(const godot_networked_multiplayer_peer_interface_gdnative * p_interface)
{
	if (interface) {
		cleanup();
	}

	interface = p_interface;

	data = interface->constructor((godot_object *)this);
}

inline int NetworkedMultiplayerPeerGDNative::get_available_packet_count() const {
	return interface->get_available_packet_count(data);
}

Error NetworkedMultiplayerPeerGDNative::get_packet(const uint8_t **r_buffer, int &r_buffer_size) {
	return (Error)interface->get_packet(data, r_buffer, &r_buffer_size);
}

///< buffer is GONE after next get_packet

Error NetworkedMultiplayerPeerGDNative::put_packet(const uint8_t *p_buffer, int p_buffer_size) {
	return (Error)interface->put_packet(data, p_buffer, p_buffer_size);
}

int NetworkedMultiplayerPeerGDNative::get_max_packet_size(void) const {
	return interface->get_max_packet_size(data);
}

void NetworkedMultiplayerPeerGDNative::set_transfer_mode(TransferMode p_mode) {
	interface->set_transfer_mode(data, p_mode);
}

NetworkedMultiplayerPeer::TransferMode NetworkedMultiplayerPeerGDNative::get_transfer_mode() const {
	return interface->get_transfer_mode(data);
}

void NetworkedMultiplayerPeerGDNative::set_target_peer(int p_peer_id) {
	interface->set_target_peer(data, p_peer_id);
}

int NetworkedMultiplayerPeerGDNative::get_packet_peer() const {
	return interface->get_packet_peer(data);
}

bool NetworkedMultiplayerPeerGDNative::is_server() const {
	return interface->is_server(data);
}

void NetworkedMultiplayerPeerGDNative::poll() {
	interface->poll(data);
}

int NetworkedMultiplayerPeerGDNative::get_unique_id() const {
	return interface->get_unique_id(data);
}

void NetworkedMultiplayerPeerGDNative::set_refuse_new_connections(bool p_enable) {
	interface->set_refuse_new_connections(data, p_enable);
}

bool NetworkedMultiplayerPeerGDNative::is_refusing_new_connections() const {
	return interface->is_refusing_new_connections(data);
}

NetworkedMultiplayerPeer::ConnectionStatus NetworkedMultiplayerPeerGDNative::get_connection_status() const {
	return interface->get_connection_status(data);
}
