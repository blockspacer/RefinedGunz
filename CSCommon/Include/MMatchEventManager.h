#pragma once

#include <vector>

#include "MMatchEvent.h"

typedef std::vector< MMatchEvent* >		EventPtrVec;
typedef std::map< DWORD, MMatchEvent* >	EventPtrMap;


class MMatchEventManager
{
public:
	MMatchEventManager();
	~MMatchEventManager();

	void			AddEvent(MMatchEvent* pEvent);
	void			AddEventList(EventPtrVec& EvnPtrVec);
	void			ChangeEventList(EventPtrVec& EvnPtrVec);
	void			DeleteEvent(const DWORD dwEventID);
	void			Clear();
	void			StartNewEvent();
	size_t			GetEventCount(const DWORD dwEventID);
	bool			Empty() { return m_EventVec.empty(); }
	MMATCH_GAMETYPE GetLastSetGameType() { return m_GameType; }
	void			SetGameType(const MMATCH_GAMETYPE GameType) { m_GameType = GameType; }

	void CustomCheckEventObj(const DWORD dwEventID, class MMatchObject* pObj, void* pContext);
	void CustomCheckEventObj(const DWORD dwEventListID, const DWORD dwEventID, MMatchObject* pObj, void* pContext);
	void CheckEventObj(MMatchObject* pObj, u64 dwCurTime);
	void Run();

	void SetLastCheckTime(u64 dwCurTime);

	static void ClearEventPtrVec(EventPtrVec& EvnPtrVec)
	{
		EventPtrVec::iterator it, end;
		end = EvnPtrVec.end();
		for (it = EvnPtrVec.begin(); it != end; ++it)
			delete (*it);
		EvnPtrVec.clear();
	}

private:
	MMATCH_GAMETYPE m_GameType;
	EventPtrVec		m_EventVec;
	EventPtrMap		m_EventMap;
};