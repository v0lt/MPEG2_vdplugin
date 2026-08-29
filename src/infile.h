///////////////////////////////////////////////////////////////////////
// MPEG-2 Plugin for VirtualDub 1.8.1+
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

#ifndef _INFILE_H
#define _INFILE_H

#define MAX_FILES 16

class inFile {

private:
	enum { BUF_SIZE  = 65536 };

	BYTE	bBuff[BUF_SIZE];
	LPWSTR  pFileName;

	LARGE_INTEGER m_Pos;
	LARGE_INTEGER m_Total;
	LARGE_INTEGER m_Size[MAX_FILES];

	HANDLE	hFile[MAX_FILES];
	bool	bDirty;

	void    inRefresh();
	void    outFlush();

public:
	inFile::inFile();
	inFile::~inFile();

	static  char *wchar_to_ansi(const wchar_t *szWchar, int len);

	bool    inOpen(const wchar_t *szFile);
	bool    inAppend(const wchar_t *szFile);

	__int64 inSize() const;
	__int64 inPos() const;
	bool    inEOF() const;

	LPCWSTR FileName() const { return pFileName; }

	bool    inSeek(__int64 iAbsPos);

	long    inRead(void *lpBuffer, long lBytes);
	int     inByte();

	bool    outOpen(const wchar_t *szFile);
	long    outWrite(const void *lpBuffer, long lBytes);
};

#endif	// _INFILE_H
