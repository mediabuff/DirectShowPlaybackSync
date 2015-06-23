#pragma once

#include "rpc.h"
#include "rpcndr.h"
#include <dshow.h>
#include <initguid.h>

DEFINE_GUID(CLSID_PlaybackSyncFilter, 0x478b2211, 0x7007, 0x4736, 0xbd, 0x37, 0xd9, 0xe7, 0xa8, 0x90, 0xe9, 0x46);

// 6fa50e5f-7fa9-4a8c-a41f-d4c7b912095d
DEFINE_GUID(IID_IPlaybackSync, 0x6fa50e5f, 0x7fa9, 0x4a8c, 0xa4, 0x1f, 0xd4, 0xc7, 0xb9, 0x12, 0x09, 0x5d);

MIDL_INTERFACE("6fa50e5f-7fa9-4a8c-a41f-d4c7b912095d")
IPlaybackSync : public IUnknown
{
public:
	virtual HRESULT STDMETHODCALLTYPE GetStartReferenceTime(REFERENCE_TIME* time) = 0;
};