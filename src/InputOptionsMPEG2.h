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

#ifndef _INPUTOPTIONSMPEG2_H_
#define _INPUTOPTIONSMPEG2_H_

class InputOptionsMPEG2 : public vdxunknown<IVDXInputOptions> {
private:
	static  INT_PTR CALLBACK OptionsDlgProc(HWND hDlg, UINT message, WPARAM wParam, LPARAM lParam);

public:
	InputOptionsMPEG2();

	// IVDXInputOptions
	uint32  VDXAPIENTRY Write(void *buf, uint32 buflen);

	void    OptionsDlg(HWND hwndParent);
	static  void InitDialogTitle(HWND hDlg, const char *pTitle);

	struct  OptionsMPEG2 {
		uint32  len;
		bool    fMultipleOpen;
		bool    fCreateIndex;
		bool    fAllowDSC;
		bool    fAllowMatrix;
	} opts;
};

#endif  // _INPUTOPTIONSMPEG2_H_