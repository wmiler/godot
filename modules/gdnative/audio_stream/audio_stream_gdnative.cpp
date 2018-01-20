/*************************************************************************/
/*  audio_stream_gdnative.cpp                                            */
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


#include "modules/gdnative/audio_Stream/audio_stream_gdnative.h"
#include "servers/audio/audio_stream.h"
#include "modules/gdnative/gdnative.h"

AudioStreamGDNative::AudioStreamGDNative() {
}

AudioStreamGDNative::~AudioStreamGDNative() {
}

Ref<AudioStreamPlayback> AudioStreamGDNative::instance_playback() {
    return Ref<AudioStreamPlayback>();
}

String AudioStreamGDNative::get_stream_name() const {
    return String();
}

void AudioStreamGDNative::_bind_methods() {
}

void AudioStreamPlaybackGDNative::_bind_methods() {
	ClassDB::bind_method(D_METHOD("start", "from_pos"), &AudioStreamPlaybackGDNative::start, DEFVAL(0));
	ClassDB::bind_method(D_METHOD("stop"), &AudioStreamPlaybackGDNative::stop);
	ClassDB::bind_method(D_METHOD("is_playing"), &AudioStreamPlaybackGDNative::is_playing);
	ClassDB::bind_method(D_METHOD("get_loop_count"), &AudioStreamPlaybackGDNative::get_loop_count);
	ClassDB::bind_method(D_METHOD("get_playback_position"), &AudioStreamPlaybackGDNative::get_playback_position);
	ClassDB::bind_method(D_METHOD("seek", "time"), &AudioStreamPlaybackGDNative::seek);
//	TODO bind mix
//	ClassDB::bind_method(D_METHOD("mix", "buffer", "rate_scale", "frames"), &AudioStreamPlaybackGDNative::mix);
	ClassDB::bind_method(D_METHOD("get_length"), &AudioStreamPlaybackGDNative::get_length);
}

void AudioStreamPlaybackGDNative::start(float p_from_pos)
{
}

void AudioStreamPlaybackGDNative::stop()
{
}

bool AudioStreamPlaybackGDNative::is_playing() const
{
	return false;
}

int AudioStreamPlaybackGDNative::get_loop_count() const
{
	return 0;
}

float AudioStreamPlaybackGDNative::get_playback_position() const
{
	return 0.0f;
}

void AudioStreamPlaybackGDNative::seek(float p_time)
{
}

void AudioStreamPlaybackGDNative::mix(AudioFrame * p_buffer, float p_rate_scale, int p_frames)
{
}

float AudioStreamPlaybackGDNative::get_length() const
{
	return 0.0f;
}
