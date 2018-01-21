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

#include "modules/gdnative/networked_multiplayer_peer/networked_multiplayer_peer_gdnative.h"
#include "core/io/networked_multiplayer_peer.h"
#include "modules/gdnative/gdnative.h"

NetworkedMultiplayerPeerGDNative::NetworkedMultiplayerPeerGDNative() {
}

NetworkedMultiplayerPeerGDNative::~NetworkedMultiplayerPeerGDNative() {

}

int NetworkedMultiplayerPeerGDNative::get_available_packet_count() const {
    return 0;
}

Error NetworkedMultiplayerPeerGDNative::get_packet(const uint8_t **r_buffer, int &r_buffer_size) {
    return OK;
}

Error NetworkedMultiplayerPeerGDNative::put_packet(const uint8_t *p_buffer, int p_buffer_size) {
    return OK;
}

int NetworkedMultiplayerPeerGDNative::get_max_packet_size(void) const {
    return 0;
}

void NetworkedMultiplayerPeerGDNative::set_transfer_mode(TransferMode p_mode) {
}

NetworkedMultiplayerPeer::TransferMode NetworkedMultiplayerPeerGDNative::get_transfer_mode() const {
    return TransferMode::TRANSFER_MODE_RELIABLE;
}

void NetworkedMultiplayerPeerGDNative::set_target_peer(int p_peer_id) {
}

int NetworkedMultiplayerPeerGDNative::get_packet_peer() const {
    return 0;
}

bool NetworkedMultiplayerPeerGDNative::is_server() const {
    return false;
}

void NetworkedMultiplayerPeerGDNative::poll() {
}

int NetworkedMultiplayerPeerGDNative::get_unique_id() const {
    return 0;
}

void NetworkedMultiplayerPeerGDNative::set_refuse_new_connections(bool p_enable) {
}

bool NetworkedMultiplayerPeerGDNative::is_refusing_new_connections() const {
    return false;
}

NetworkedMultiplayerPeer::ConnectionStatus NetworkedMultiplayerPeerGDNative::get_connection_status() const {
    return ConnectionStatus::CONNECTION_CONNECTED;
}

void NetworkedMultiplayerPeerGDNative::_bind_methods() {
}
