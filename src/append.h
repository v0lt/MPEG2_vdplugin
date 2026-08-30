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

#ifndef f_APPEND_H
#define f_APPEND_H

class AppendNames {
public:
	LPWSTR fName[MAX_FILES];
	int num_files;

	AppendNames() {
		num_files = 0;
		for (int i = 0; i < MAX_FILES; ++i) fName[i] = NULL;
	}

	~AppendNames() {
		for (int i = MAX_FILES - 1; i >= 0; --i) delete[] fName[i];
	}
};

wchar_t *copy_string(const wchar_t *szString);
void AppendDlg(AppendNames *an, inFile *pIn, bool bShowUI, HMODULE hModule, HWND hwndParent);

#endif	// f_APPEND_H