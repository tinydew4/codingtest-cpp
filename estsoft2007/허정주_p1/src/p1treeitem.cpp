//---------------------------------------------------------------------------
#include <assert.h>
#include "p1common.h"
#pragma hdrstop

#include "p1treeitem.h"
//---------------------------------------------------------------------------
std::ostream& operator<<(std::ostream& a_OStream, const TTreeItem &Item)
{
	static int PrintCount = 0;

	if (Item.HasParent() == false)
		PrintCount = 0;

	if (Item.HasChild() > 0)
		a_OStream << *(Item.m_pChildLeft) << *(Item.m_pChildRight);
	else
		(PrintCount++ > 0? a_OStream << ",": a_OStream) << Item.m_pDepth;

	return a_OStream;
}
//---------------------------------------------------------------------------
TTreeItem::TTreeItem(const int &Depth)
	: m_pParent(NULL), m_pDepth(Depth), m_pChildLeft(NULL), m_pChildRight(NULL)
{
}
//---------------------------------------------------------------------------
TTreeItem::TTreeItem(TTreeItem *AOwner)
	: m_pParent(AOwner), m_pDepth(AOwner->GetDepth() + 1), m_pChildLeft(NULL), m_pChildRight(NULL)
{
}
//---------------------------------------------------------------------------
TTreeItem::~TTreeItem(void)
{
	Clear();
}
//---------------------------------------------------------------------------
void TTreeItem::Clear(void)
{
	if (HasChild() == 0)
		return;

	if (m_pChildLeft != NULL)
		delete m_pChildLeft;
	if (m_pChildRight != NULL)
		delete m_pChildRight;
}
//---------------------------------------------------------------------------
void TTreeItem::Init(const int &Size)
{
	if (Size <= 1)
		return;

	Clear();

	m_pChildLeft = new TTreeItem(this);
	m_pChildRight = new TTreeItem(this);

	m_pChildRight->Init(Size - 1);
}
//---------------------------------------------------------------------------
void TTreeItem::Assign(TTreeItem *Value)
{
	assert(HasChild() >= 0);

	if (this != Value)
	{
		m_pChildLeft  = Value->GetLeft();
		m_pChildLeft->SetParent(this);
		m_pChildRight = Value->GetRight();
		m_pChildRight->SetParent(this);
	}
}
//---------------------------------------------------------------------------
void TTreeItem::ChildNull(void)
{
	m_pChildLeft = NULL;
	m_pChildRight = NULL;
}
//---------------------------------------------------------------------------
void TTreeItem::Recover(void)
{
	assert(HasChild() >= 0);

	if (HasChild() == 0)
		return;

	assert(m_pChildLeft->GetParent() == m_pChildRight->GetParent());

	TTreeItem *P = m_pChildLeft->GetParent();

	assert(P);

	P->Assign(this);
}
//---------------------------------------------------------------------------
bool TTreeItem::HasParent(void) const
{
	assert(HasChild() >= 0);

	return (m_pParent != NULL);
}
//---------------------------------------------------------------------------
TTreeItem* TTreeItem::GetParent(void) const
{
	assert(HasChild() >= 0);

	return m_pParent;
}
//---------------------------------------------------------------------------
void TTreeItem::SetParent(TTreeItem *Value)
{
	assert(HasChild() >= 0);

	if (m_pParent != Value)
	{
		m_pParent = Value;
		m_pDepth = Value->GetDepth() + 1;
	}
}
//---------------------------------------------------------------------------
TTreeItem* TTreeItem::GetLeft(void) const
{
	assert(HasChild() >= 0);

	return m_pChildLeft;
}
//---------------------------------------------------------------------------
TTreeItem* TTreeItem::GetRight(void) const
{
	assert(HasChild() >= 0);

	return m_pChildRight;
}
//---------------------------------------------------------------------------
int TTreeItem::GetDepth(void) const
{
	return m_pDepth;
}
//---------------------------------------------------------------------------
int TTreeItem::HasDepth(TTreeItem *Adder) const
{
	assert(HasChild() >= 0);

	if (HasChild() == false)
		return (this != Adder? m_pDepth: m_pDepth + 1);

	return Max(m_pChildLeft->HasDepth(), m_pChildRight->HasDepth());
}
//---------------------------------------------------------------------------
int TTreeItem::HasShallow(void) const
{
	assert(HasChild() >= 0);

	if (HasChild() == false)
		return m_pDepth;

	return Min(m_pChildLeft->HasDepth(), m_pChildRight->HasDepth());
}
//---------------------------------------------------------------------------
int TTreeItem::HasChild(void) const
{
	if (m_pChildLeft != NULL && m_pChildRight != NULL)
		return 1;
	else if (m_pChildLeft == NULL && m_pChildRight == NULL)
		return 0;

	return -1;
}
//---------------------------------------------------------------------------
bool TTreeItem::HasTermChild(void) const
{
	assert(HasChild() >= 0);

	return (HasChild() &&
		m_pChildLeft->HasChild() <= 0 &&
		m_pChildRight->HasChild() <= 0);
}
//---------------------------------------------------------------------------
bool TTreeItem::IsValid(TTreeItem *Adder) const
{
	assert(HasChild() >= 0);

	if (m_pChildLeft == NULL)
		return true;

	if (m_pChildLeft->HasDepth(Adder) > m_pChildRight->HasDepth(Adder))
		return false;

	if (m_pChildLeft->IsValid(Adder) == false)
		return false;
	if (m_pChildRight->IsValid(Adder) == false)
		return false;

	return true;
}
//---------------------------------------------------------------------------
