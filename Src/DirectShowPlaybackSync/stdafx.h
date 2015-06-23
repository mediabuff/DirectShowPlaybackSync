// stdafx.h : include file for standard system include files,
// or project specific include files that are used frequently, but
// are changed infrequently
//

#pragma once

#include "targetver.h"

#define WIN32_LEAN_AND_MEAN             // Exclude rarely-used stuff from Windows headers
// Windows Header Files:
#include <windows.h>


#define _ATL_CSTRING_EXPLICIT_CONSTRUCTORS      // some CString constructors will be explicit

#include <atlbase.h>
#include <atlstr.h>
#include <initguid.h>

// 478b2211-7007-4736-bd37-d9e7a890e946
DEFINE_GUID(CLSID_PlaybackSyncFilter, 0x478b2211, 0x7007, 0x4736, 0xbd, 0x37, 0xd9, 0xe7, 0xa8, 0x90, 0xe9, 0x46);