// Copyright (c) 2007-2017 Juan Linietsky, Ariel Manzur.
// Copyright (c) 2014-2017 Godot Engine contributors (cf. AUTHORS.md)

// Permission is hereby granted, free of charge, to any person obtaining a copy
// of this software and associated documentation files (the "Software"), to deal
// in the Software without restriction, including without limitation the rights
// to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
// copies of the Software, and to permit persons to whom the Software is
// furnished to do so, subject to the following conditions:

// The above copyright notice and this permission notice shall be included in all
// copies or substantial portions of the Software.

// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
// AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
// OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
// SOFTWARE.

// -- Godot Engine <https://godotengine.org>

#pragma once
#include "thirdparty/yojimbo/yojimbo.h"
#include <core/io/networked_multiplayer_peer.h>

class NetworkedMultiplayerYojimbo : public NetworkedMultiplayerPeer {
private:
	GDCLASS(NetworkedMultiplayerYojimbo, NetworkedMultiplayerPeer);
	Error initialize_yojimbo();
	yojimbo::ClientServerConfig config;
	yojimbo::Server *server;
	yojimbo::Client *client;
	yojimbo::Matcher *matcher;
	const int messagesToSend;
	uint64_t numMessagesSentToServer = 0;
	uint64_t numMessagesSentToClient = 0;
	uint64_t numMessagesReceivedFromClient = 0;
	uint64_t numMessagesReceivedFromServer = 0;
	int32_t client_id = 0;
	uint32_t gen_unique_id_() const;
	NetworkedMultiplayerPeer::ConnectionStatus connection_status;
	const int num_blocks = 256;
	const int block_size = 1024;
	const int memory_size = num_blocks * block_size;
	uint8_t *client_memory;
	uint8_t *server_memory;
	uint8_t *matcher_memory;

public:
	NetworkedMultiplayerYojimbo() :
			server(nullptr),
			client(nullptr),
			matcher(nullptr),
			messagesToSend(8),
			numMessagesSentToServer(0),
			numMessagesSentToClient(0),
			numMessagesReceivedFromClient(0),
			numMessagesReceivedFromServer(0) {
	}
	~NetworkedMultiplayerYojimbo() {
	}

	void close_connection();
	int32_t create_client(String ip, int port, int in_bandwidth = 0, int out_bandwidth = 0);
	int32_t create_server(int port, int max_clients = 32, int in_bandwidth = 0, int out_bandwidth = 0);
	void set_bind_ip(String ip);

	NetworkedMultiplayerPeer::ConnectionStatus get_connection_status() const;
	int32_t get_packet_peer() const;
	int32_t get_unique_id() const;
	void poll();
	void set_target_peer(int id);
	void set_transfer_mode(TransferMode p_mode);

	int32_t get_available_packet_count() const;
	Error get_packet(const uint8_t **, int &);
	Error get_packet_error() const;
	Error put_packet(const uint8_t *p_buffer, int p_buffer_size);
	virtual Error get_var(Variant &r_variant);
	virtual Error put_var(const Variant &p_packet);

	void set_refuse_new_connections(bool p_enable);
	bool is_refusing_new_connections() const;

	int32_t get_max_packet_size() const;
	NetworkedMultiplayerPeer::TransferMode get_transfer_mode() const;

	bool is_server() const;

	// Custom
	void set_log_level(int level);

protected:
	static void _bind_methods();
};
