/*************************************************************************/
/*  audio_stream_gdnative.h                                              */
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

#ifndef AUDIO_STREAM_GDNATIVE_H
#define AUDIO_STREAM_GDNATIVE_H

#include "servers/audio/audio_stream.h"
#include "modules/gdnative/gdnative.h"

class AudioStreamPlaybackGDNative : public AudioStreamPlayback {

	GDCLASS(AudioStreamPlaybackGDNative, AudioStreamPlayback)

protected:
	static void _bind_methods();

public:
	virtual void start(float p_from_pos = 0.0) override;
	virtual void stop() override;
	virtual bool is_playing() const override;

	virtual int get_loop_count() const override; //times it looped

	virtual float get_playback_position() const override;
	virtual void seek(float p_time) override;

	virtual void mix(AudioFrame *p_buffer, float p_rate_scale, int p_frames) override;

	virtual float get_length() const override; //if supported, otherwise return 0
};

class AudioStreamGDNative : public AudioStream {
    GDCLASS(AudioStreamGDNative, AudioStream)

protected:
    static void _bind_methods();

public:
    AudioStreamGDNative();
    ~AudioStreamGDNative();

    virtual Ref<AudioStreamPlayback> instance_playback() override;
    virtual String get_stream_name() const override;
};

#endif // AUDIO_STREAM_GDNATIVE_H
