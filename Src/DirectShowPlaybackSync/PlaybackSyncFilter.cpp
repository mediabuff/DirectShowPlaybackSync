#include "stdafx.h"
#include "PlaybackSyncFilter.h"


PlaybackSyncFilter::PlaybackSyncFilter(LPUNKNOWN lpunk, HRESULT *phr) 
	: CBaseFilter("Sync filter", lpunk, &_stateLock, CLSID_PlaybackSyncFilter, phr)
{
	
}

PlaybackSyncFilter::~PlaybackSyncFilter()
{

}

int PlaybackSyncFilter::GetPinCount()
{
	return  0;
}

CBasePin *PlaybackSyncFilter::GetPin(int n)
{
	return NULL;
}

CUnknown * WINAPI PlaybackSyncFilter::CreateInstance(LPUNKNOWN lpunk, HRESULT *phr)
{
	ASSERT(phr);

	CUnknown *punk = new PlaybackSyncFilter(lpunk, phr);
	if (punk == NULL)
	{
		if (phr)
			*phr = E_OUTOFMEMORY;
	}
	return punk;
}