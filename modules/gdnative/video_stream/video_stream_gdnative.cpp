/*************************************************************************/
/*  video_stream_gdnative.cpp                                            */
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

#include "modules/gdnative/video_stream/video_stream_gdnative.h"
#include "scene/resources/video_stream.h"
#include "modules/gdnative/gdnative.h"

VideoStreamGDNative::VideoStreamGDNative() {
}

VideoStreamGDNative::~VideoStreamGDNative() {
}

void VideoStreamGDNative::set_audio_track(int p_track) {
}

Ref<VideoStreamPlayback> VideoStreamGDNative::instance_playback() {
	return Ref<VideoStreamPlayback>();
}

void VideoStreamGDNative::_bind_methods() {
}

void VideoStreamPlaybackGDNative::_bind_methods()
{
	ClassDB::bind_method(D_METHOD("stop"), &VideoStreamPlaybackGDNative::stop);
	ClassDB::bind_method(D_METHOD("play"), &VideoStreamPlaybackGDNative::play);
	ClassDB::bind_method(D_METHOD("is_playing"), &VideoStreamPlaybackGDNative::is_playing);
	ClassDB::bind_method(D_METHOD("set_paused", "paused"), &VideoStreamPlaybackGDNative::set_paused);
	ClassDB::bind_method(D_METHOD("is_paused"), &VideoStreamPlaybackGDNative::is_paused);
	ClassDB::bind_method(D_METHOD("set_loop", "enabled"), &VideoStreamPlaybackGDNative::set_loop);
	ClassDB::bind_method(D_METHOD("has_loop"), &VideoStreamPlaybackGDNative::has_loop);
	ClassDB::bind_method(D_METHOD("get_length"), &VideoStreamPlaybackGDNative::get_length);
	ClassDB::bind_method(D_METHOD("get_playback_position"), &VideoStreamPlaybackGDNative::get_playback_position);
	ClassDB::bind_method(D_METHOD("seek"), &VideoStreamPlaybackGDNative::seek);
	ClassDB::bind_method(D_METHOD("set_audio_track", "idx"), &VideoStreamPlaybackGDNative::set_audio_track);
	ClassDB::bind_method(D_METHOD("get_texture"), &VideoStreamPlaybackGDNative::get_texture);
	ClassDB::bind_method(D_METHOD("update", "delta"), &VideoStreamPlaybackGDNative::update);
//	TODO bind set_mix_callback
//	ClassDB::bind_method(D_METHOD("set_mix_callback", "callback", "userdata"), &VideoStreamPlaybackGDNative::set_mix_callback);
	ClassDB::bind_method(D_METHOD("get_channels"), &VideoStreamPlaybackGDNative::get_channels);
	ClassDB::bind_method(D_METHOD("get_mix_rate"), &VideoStreamPlaybackGDNative::get_mix_rate);
}

VideoStreamPlaybackGDNative::VideoStreamPlaybackGDNative()
{
}

VideoStreamPlaybackGDNative::~VideoStreamPlaybackGDNative()
{
}

void VideoStreamPlaybackGDNative::stop()
{
}

void VideoStreamPlaybackGDNative::play()
{
}

bool VideoStreamPlaybackGDNative::is_playing() const
{
	return false;
}

void VideoStreamPlaybackGDNative::set_paused(bool p_paused)
{
}

bool VideoStreamPlaybackGDNative::is_paused() const
{
	return false;
}

void VideoStreamPlaybackGDNative::set_loop(bool p_enable)
{
}

bool VideoStreamPlaybackGDNative::has_loop() const
{
	return false;
}

float VideoStreamPlaybackGDNative::get_length() const
{
	return 0.0f;
}

float VideoStreamPlaybackGDNative::get_playback_position() const
{
	return 0.0f;
}

void VideoStreamPlaybackGDNative::seek(float p_time)
{
}

void VideoStreamPlaybackGDNative::set_audio_track(int p_idx)
{
}

Ref<Texture> VideoStreamPlaybackGDNative::get_texture()
{
	return Ref<Texture>();
}

void VideoStreamPlaybackGDNative::update(float p_delta)
{
}

void VideoStreamPlaybackGDNative::set_mix_callback(AudioMixCallback p_callback, void * p_userdata)
{
}

int VideoStreamPlaybackGDNative::get_channels() const
{
	return 0;
}

int VideoStreamPlaybackGDNative::get_mix_rate() const
{
	return 0;
}
