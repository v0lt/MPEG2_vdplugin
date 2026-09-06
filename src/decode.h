///////////////////////////////////////////////////////////////////////
// MPEG-2 Plugin for VirtualDub 1.10.1+
// Copyright (C) 2007-2012 fccHandler
// Copyright (C) 1998-2012 Avery Lee
// Copyright (C) 2026 v0lt
//
// This program is free software; you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation; either version 2 of the License, or
// (at your option) any later version.
//
// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.
//
// You should have received a copy of the GNU General Public License
// along with this program; if not, write to the Free Software
// Foundation, Inc., 675 Mass Ave, Cambridge, MA 02139, USA.
///////////////////////////////////////////////////////////////////////

#ifndef _VIDEODECODERMPEG2_H_
#define _VIDEODECODERMPEG2_H_

class VideoDecoderMPEG2 : public vdxunknown<IVDXVideoDecoder> {

private:
	InputFileMPEG2* const parentPtr;
	IMPEG2Decoder*  mpDecoder  = nullptr;

	sint64          mPrevFrame = -1;;
	unsigned char*  pMemBlock  = nullptr;

protected:
	VDXPixmap       mPixmap = {};
	unsigned char*  mFrameBuffer = nullptr;

public:
	VideoDecoderMPEG2(InputFileMPEG2 *pp);
	~VideoDecoderMPEG2();

	// IVDXVideoDecoder
	const void*         VDXAPIENTRY DecodeFrame(const void *inputBuffer, uint32 data_len, bool is_preroll, sint64 sampleNumber, sint64 targetFrame);
	uint32              VDXAPIENTRY GetDecodePadding();
	void                VDXAPIENTRY Reset();
	bool                VDXAPIENTRY IsFrameBufferValid();
	const VDXPixmap&    VDXAPIENTRY GetFrameBuffer();
	bool                VDXAPIENTRY SetTargetFormat(int format, bool useDIBAlignment);
	bool                VDXAPIENTRY SetDecompressedFormat(const VDXBITMAPINFOHEADER *pbih);
	bool                VDXAPIENTRY IsDecodable(sint64 sample_num);
	const void*         VDXAPIENTRY GetFrameBufferBase();

	// VideoDecoderMPEG2
	bool    Init();
};


class VideoDecoderModelMPEG2 : public vdxunknown<IVDXVideoDecoderModel> {

private:
	InputFileMPEG2 *const parentPtr;

	int frame_forw, frame_back, frame_bidir, frame_aux;

	sint64 mSampleFirst;
	sint64 mSampleLast;

	sint64 stream_current_frame;
	sint64 stream_desired_frame;

	sint64 prev_field_IP(sint64 f64) const;
	sint64 next_field_IP(sint64 f64) const;

public:
	VideoDecoderModelMPEG2(InputFileMPEG2 *pp);
	~VideoDecoderModelMPEG2();

	// IVDXVideoDecoderModel
	void    VDXAPIENTRY Reset();
	void    VDXAPIENTRY SetDesiredFrame(sint64 frame_num);
	sint64  VDXAPIENTRY GetNextRequiredSample(bool& is_preroll);
	int     VDXAPIENTRY GetRequiredCount();
};


#endif	// _VIDEODECODERMPEG2_H_
