#include "stdafx.h"
#include "MAsyncDBJob_FriendList.h"

void MAsyncDBJob_FriendList::Run(void* pContext)
{
	_ASSERT(m_pFriendInfo);

	auto* pDBMgr = static_cast<IDatabase*>(pContext);

	// �ش�ĳ������ ģ����� ��������
	if (!pDBMgr->FriendGetList(m_nCID, m_pFriendInfo)) 
	{
		SetResult(MASYNC_RESULT_FAILED);
		return;
	}

	SetResult(MASYNC_RESULT_SUCCEED);
}