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

#ifndef _VIDEOSOURCEMPEG2_H_
#define _VIDEOSOURCEMPEG2_H_

class VideoSourceMPEG2 : public vdxunknown<IVDXStreamSource>, public IVDXVideoSource
{
private:
	InputFileMPEG2* const parentPtr;

	unsigned char*  read_buffer1;
	long            buffer1_frame;
	unsigned char*  read_buffer2;
	long            buffer2_frame;

	sint64          mSampleFirst;
	sint64          mSampleLast;

#ifdef SUPPORT_DSC
	unsigned char*  DirectFormat;
	int             DirectFormatLen;
	bool            DirectTested;
#endif

public:
	VideoSourceMPEG2(InputFileMPEG2* const pp);
	~VideoSourceMPEG2();

	// IVDXUnknown
	int         VDXAPIENTRY AddRef() override;
	int         VDXAPIENTRY Release() override;
	void*       VDXAPIENTRY AsInterface(uint32 iid) override;

	// IVDXStreamSource
	void        VDXAPIENTRY GetStreamSourceInfo(VDXStreamSourceInfo&) override;
	bool        VDXAPIENTRY Read(sint64 lStart, uint32 lCount, void *lpBuffer, uint32 cbBuffer, uint32 *lBytesRead, uint32 *lSamplesRead) override;
	const void* VDXAPIENTRY GetDirectFormat() override;
	int         VDXAPIENTRY GetDirectFormatLen() override;
	ErrorMode   VDXAPIENTRY GetDecodeErrorMode() override;
	void        VDXAPIENTRY SetDecodeErrorMode(ErrorMode mode) override;
	bool        VDXAPIENTRY IsDecodeErrorModeSupported(ErrorMode mode) override;
	bool        VDXAPIENTRY IsVBR() override;
	sint64      VDXAPIENTRY TimeToPositionVBR(sint64 us) override;
	sint64      VDXAPIENTRY PositionToTimeVBR(sint64 samples) override;

	// IVDXVideoSource
	void        VDXAPIENTRY GetVideoSourceInfo(VDXVideoSourceInfo& info) override;
	bool        VDXAPIENTRY CreateVideoDecoderModel(IVDXVideoDecoderModel **ppModel) override;
	bool        VDXAPIENTRY CreateVideoDecoder(IVDXVideoDecoder **ppDecoder) override;
	void        VDXAPIENTRY GetSampleInfo(sint64 sample_num, VDXVideoFrameInfo& frameInfo) override;
	bool        VDXAPIENTRY IsKey(sint64 sample_num) override;
	sint64      VDXAPIENTRY GetFrameNumberForSample(sint64 sample_num) override;
	sint64      VDXAPIENTRY GetSampleNumberForFrame(sint64 frame_num) override;
	sint64      VDXAPIENTRY GetRealFrame(sint64 frame_num) override;
	sint64      VDXAPIENTRY GetSampleBytePosition(sint64 sample_num) override;
};

#endif	// _VIDEOSOURCEMPEG2_H_
