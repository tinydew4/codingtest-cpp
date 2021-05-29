//---------------------------------------------------------------------------
#include <assert.h>
#pragma hdrstop

#include "p1treelist.h"
#include "p1treeitem.h"
//---------------------------------------------------------------------------
std::ostream& operator<<(std::ostream& a_OStream, const TTreeList &a_TreeList)
{
	a_OStream << *(a_TreeList.m_pHead);
	return a_OStream;
}
//---------------------------------------------------------------------------
TTreeList::TTreeList(void)
	: m_pHead(new TTreeItem), m_pTemp(new TTreeItem)
{
}
//---------------------------------------------------------------------------
TTreeList::~TTreeList(void)
{
	if (m_pHead)
		delete m_pHead;
	if (m_pTemp)
		delete m_pTemp;
}
//---------------------------------------------------------------------------
bool TTreeList::IsValid(void) const
{
	return m_pHead->IsValid();
}
//---------------------------------------------------------------------------
void TTreeList::SetSize(const int &Size)
{
	m_pHead->Init(Size);
}
//---------------------------------------------------------------------------
bool TTreeList::NextStep(void)
{
	if (m_pHead->HasDepth() <= 2)
		return false;

	TTreeItem *From = m_pHead;
	TTreeItem *To   = GetNextMove(&From);
	if (To == NULL)
		return false;

	// Move From -> To
	To->Assign(From);
	From->ChildNull();

	return IsValid();
}
//---------------------------------------------------------------------------
TTreeItem* TTreeList::GetNextMove(TTreeItem **Item)
{
	// 이동할 것 찾기, 이동할 지점이 있는 것 만
	assert(Item);

	TTreeItem *Result = NULL;
	TTreeItem *Source = NULL;

	if ((*Item)->HasTermChild())
	{
		// 단말 노드의 부모, 이동 가능한 단말 노드 반환
		m_pTemp->Assign((*Item));
		(*Item)->ChildNull();
		__try
		{
			return GetTarget((*Item), (*Item)->GetParent(), m_pTemp);
		}
		__finally
		{
			(*Item)->Assign(m_pTemp);
			m_pTemp->ChildNull();
		}
	}

	if ((Source = (*Item)->GetRight())->HasChild() > 0 &&
		(Result = GetNextMove(&Source)) != NULL)
	{
		(*Item) = Source;
		return Result;
	}

	if ((Source = (*Item)->GetLeft())->HasChild() > 0 &&
		(Result = GetNextMove(&Source)) != NULL)
	{
		(*Item) = Source;
		return Result;
	}

	// 내 밑으로 아무도 못 움직여...
	return NULL;
}
//---------------------------------------------------------------------------
// Before: 이전에 확인하고 온 곳, 방향 확인용
// Target: 현재 확인해야할 곳
// From: 이동 대상. 최초 호출에서 설정. 내부에서는 그냥 전달
TTreeItem* TTreeList::GetTarget(TTreeItem *Before, TTreeItem *Target, TTreeItem *From)
{
	// 이동할 곳 찾기

	TTreeItem *Result = NULL;

	if (Target == NULL)
		return NULL;

	// 단말노드라면
	if (Target->HasChild() == false)
	{
		// 임시 추가
		Target->Assign(From);
		__try
		{
			// 여기에 추가했을 때 유효하면
			if (m_pHead->IsValid())
				return Target;
		}
		__finally
		{
			// 임시 추가정보 제거
			Target->ChildNull();
		}

		return NULL;
	}

	// 위에서 내려옴. 오른쪽 확인
	if (Target->GetParent() == Before)
	{
		if ((Result = GetTarget(Target, Target->GetRight(), From)) != NULL)
			return Result;
		Before = Target->GetRight();
	}

	// 오른쪽에서 올라옴. 왼쪽 확인
	if (Target->GetRight() == Before)
	{
		if ((Result = GetTarget(Target, Target->GetLeft(), From)) != NULL)
			return Result;
		Before = Target->GetLeft();
	}

	// 왼쪽에서 올라옴. 위로 가기
	if (Target->GetLeft() == Before)
	{
		if ((Result = GetTarget(Target, Target->GetParent(), From)) != NULL)
			return Result;
	}

	return NULL;
}
//---------------------------------------------------------------------------
