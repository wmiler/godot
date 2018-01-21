/*************************************************************************/
/*  video_stream_gdnative.h                                              */
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

#ifndef VIDEO_STREAM_GDNATIVE_H
#define VIDEO_STREAM_GDNATIVE_H

#include "scene/resources/video_stream.h"
#include "modules/gdnative/gdnative.h"

class VideoStreamPlaybackGDNative : public VideoStreamPlayback {

	GDCLASS(VideoStreamPlaybackGDNative, VideoStreamPlayback);

protected:
	static void _bind_methods();

public:
	VideoStreamPlaybackGDNative();
	~VideoStreamPlaybackGDNative();

	virtual void stop() override;
	virtual void play() override;

	virtual bool is_playing() const override;

	virtual void set_paused(bool p_paused) override;
	virtual bool is_paused() const override;

	virtual void set_loop(bool p_enable) override;
	virtual bool has_loop() const override;

	virtual float get_length() const override;

	virtual float get_playback_position() const override;
	virtual void seek(float p_time) override;

	virtual void set_audio_track(int p_idx) override;

	virtual Ref<Texture> get_texture() override;
	virtual void update(float p_delta) override;

	virtual void set_mix_callback(AudioMixCallback p_callback, void *p_userdata) override;
	virtual int get_channels() const override;
	virtual int get_mix_rate() const override;
};

class VideoStreamGDNative : public VideoStream {
    GDCLASS(VideoStreamGDNative, VideoStream)

protected:
    static void _bind_methods();

public:
    VideoStreamGDNative();
    ~VideoStreamGDNative();

    virtual void set_audio_track(int p_track) override;
    virtual Ref<VideoStreamPlayback> instance_playback() override;
};

#endif // VIDEO_STREAM_GDNATIVE_H
