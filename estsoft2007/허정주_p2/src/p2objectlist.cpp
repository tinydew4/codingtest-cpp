//---------------------------------------------------------------------------
#include "p2objectlist.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
//---------------------------------------------------------------------------
// TObjectItem
//---------------------------------------------------------------------------
TObjectItem::TObjectItem(void)
    : m_pObject(0), m_pPrev(0), m_pNext(0)
{
}
//---------------------------------------------------------------------------
void TObjectItem::AddObject(void *a_Object)
{
    m_pObject = a_Object;
}
//---------------------------------------------------------------------------

//---------------------------------------------------------------------------
// TObjectList
//---------------------------------------------------------------------------
TObjectList::operator TObjectList(void)
{
    return *this;
}
//---------------------------------------------------------------------------
TObjectList::TObjectList(void)
    : m_pFirst(0), m_pLast(0), m_pCurrent(0)
{
}
//---------------------------------------------------------------------------
TObjectList::~TObjectList(void)
{
    if (m_pFirst)
    {
        TObjectItem *Item;
        m_pCurrent = m_pFirst;
        while (m_pCurrent)
        {
            Item = m_pCurrent;
            m_pCurrent = m_pCurrent->Next;
            delete Item;
        }
    }
}
//---------------------------------------------------------------------------
TObjectItem* TObjectList::Add(void)
{
    TObjectItem *Item = new TObjectItem;
    if (m_pFirst)
    {
        m_pLast->Next = Item;
        Item->Prev = m_pLast;
    }
    else
    {
        m_pFirst = Item;
    }
    m_pLast  = Item;

    return Item;
}
//---------------------------------------------------------------------------
void TObjectList::Delete(TObjectItem *Value)
{
    if (Value == 0)
        return;
        
    if (Value == m_pCurrent)
        m_pCurrent = m_pCurrent->Prev;

    if (Value->Prev == 0)
        m_pFirst = Value->Next;
    else
        Value->Prev->Next = Value->Next;

    if (Value->Next == 0)
        m_pLast = Value->Prev;
    else
        Value->Next->Prev = Value->Prev;

    delete Value;
}
//---------------------------------------------------------------------------
void TObjectList::Delete(const int &Index)
{
    TObjectItem *Temp = First();
    for (int i = Index; i--;)
        Temp = Next();
    if (Temp)
        Delete(Temp);
}
//---------------------------------------------------------------------------
void TObjectList::DeleteSelected(void)
{
    Delete(m_pCurrent);
}
//---------------------------------------------------------------------------
void TObjectList::Clear(void)
{
    TObjectItem *Item;
    m_pCurrent = m_pFirst;
    while (m_pCurrent)
    {
        Item = m_pCurrent;
        m_pCurrent = m_pCurrent->Next;
        if (Item->Object)
            delete Item->Object;
        delete Item;
    }
}
//---------------------------------------------------------------------------
TObjectItem* TObjectList::First(void)
{
    return (m_pCurrent = m_pFirst);
}
//---------------------------------------------------------------------------
TObjectItem* TObjectList::Last(void)
{
    return m_pLast;
}
//---------------------------------------------------------------------------
TObjectItem* TObjectList::Next(void)
{
    if (m_pCurrent != 0)
    {
        if (m_pCurrent != m_pLast)
            m_pCurrent = m_pCurrent->Next;
        else
            return 0;
    }
    else
        m_pCurrent = m_pFirst;

    return m_pCurrent;
}
//---------------------------------------------------------------------------

