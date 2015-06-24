#pragma once

#include <streams.h>
#include "PlaybackSyncInterface.h"

class PlaybackSyncFilterDummyStream;

class PlaybackReferenceClock : public CSystemClock
{
public:
	PlaybackReferenceClock(LPCTSTR pName, LPUNKNOWN pUnk, HRESULT *phr) : CSystemClock(pName, pUnk, phr) { }
};

class PlaybackSyncFilter : public CBaseFilter, IPlaybackSync
{
public:

	PlaybackSyncFilter(LPUNKNOWN lpunk, HRESULT *phr);
	~PlaybackSyncFilter();

	DECLARE_IUNKNOWN

	int GetPinCount();
	CBasePin *GetPin(int n);

	CCritSec * GetStateLock();

	STDMETHOD(GetStartReferenceTime)(REFERENCE_TIME* time);

	STDMETHOD(NonDelegatingQueryInterface)(REFIID riid, __deref_out void **ppv);

	static CUnknown * WINAPI CreateInstance(LPUNKNOWN lpunk, HRESULT *phr);

private:

	CCritSec _stateLock;
	PlaybackSyncFilterDummyStream* _dummyStream;
	PlaybackReferenceClock _clock;

};

