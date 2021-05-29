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
	// �̵��� �� ã��, �̵��� ������ �ִ� �� ��
	assert(Item);

	TTreeItem *Result = NULL;
	TTreeItem *Source = NULL;

	if ((*Item)->HasTermChild())
	{
		// �ܸ� ����� �θ�, �̵� ������ �ܸ� ��� ��ȯ
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

	// �� ������ �ƹ��� �� ������...
	return NULL;
}
//---------------------------------------------------------------------------
// Before: ������ Ȯ���ϰ� �� ��, ���� Ȯ�ο�
// Target: ���� Ȯ���ؾ��� ��
// From: �̵� ���. ���� ȣ�⿡�� ����. ���ο����� �׳� ����
TTreeItem* TTreeList::GetTarget(TTreeItem *Before, TTreeItem *Target, TTreeItem *From)
{
	// �̵��� �� ã��

	TTreeItem *Result = NULL;

	if (Target == NULL)
		return NULL;

	// �ܸ������
	if (Target->HasChild() == false)
	{
		// �ӽ� �߰�
		Target->Assign(From);
		__try
		{
			// ���⿡ �߰����� �� ��ȿ�ϸ�
			if (m_pHead->IsValid())
				return Target;
		}
		__finally
		{
			// �ӽ� �߰����� ����
			Target->ChildNull();
		}

		return NULL;
	}

	// ������ ������. ������ Ȯ��
	if (Target->GetParent() == Before)
	{
		if ((Result = GetTarget(Target, Target->GetRight(), From)) != NULL)
			return Result;
		Before = Target->GetRight();
	}

	// �����ʿ��� �ö��. ���� Ȯ��
	if (Target->GetRight() == Before)
	{
		if ((Result = GetTarget(Target, Target->GetLeft(), From)) != NULL)
			return Result;
		Before = Target->GetLeft();
	}

	// ���ʿ��� �ö��. ���� ����
	if (Target->GetLeft() == Before)
	{
		if ((Result = GetTarget(Target, Target->GetParent(), From)) != NULL)
			return Result;
	}

	return NULL;
}
//---------------------------------------------------------------------------
