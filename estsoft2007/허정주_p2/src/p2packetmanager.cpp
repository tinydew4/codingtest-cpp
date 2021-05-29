//---------------------------------------------------------------------------
#include "p2packetmanager.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
//---------------------------------------------------------------------------
TPacketManager::TPacketManager(void)
    : m_pPacket(NULL), m_pBufferList(NULL), m_pCount(0), m_pMaxBuf(0)
{
    m_pBufferList = new TObjectList;
}
//---------------------------------------------------------------------------
TPacketManager::~TPacketManager(void)
{
    if (m_pPacket)
        delete[] m_pPacket;

    if (m_pBufferList)
    {
        TObjectItem *Item;
        for (Item = m_pBufferList->First(); Item != NULL; Item = m_pBufferList->Last())
            delete Item->Object;

        delete m_pBufferList;
    }
}
//---------------------------------------------------------------------------
int TPacketManager::GetBufferSize(void)
{
    TObjectItem *Item;
    int result = 0;

    for (Item = m_pBufferList->First(); Item != NULL; Item = m_pBufferList->Next())
        result += ((TPacket*)Item->Object)->GetSize();

    return result;
}
//---------------------------------------------------------------------------
void TPacketManager::SetSize(int a_Size)
{
    if (m_pPacket)
    {
        delete[] m_pPacket;
        m_pPacket = NULL;
    }

    m_pPacket = new TPacket[a_Size];
    m_pCount = a_Size;
    m_pMaxBuf = 0;

    m_pBufferList->Clear();
}
//---------------------------------------------------------------------------
void TPacketManager::Add(const TPacket &a_Packet)
{
    int result;
    try
    {
        if (a_Packet.IsFirst())
        {
            // 신규등록
            if (m_pPacket[a_Packet.Number - 1].Number != 0)
                throw std::logic_error(EPINVALID);
            m_pPacket[a_Packet.Number - 1] = a_Packet;
        }
        else
        {
            // 기존추가
            result = m_pPacket[a_Packet.Number - 1].Add(a_Packet);
            if (result == -1)
                throw std::logic_error(EPINVALID);

            if (result == 0)
            {
                // 버퍼 등록
                TObjectItem *Item = m_pBufferList->Add();
                TPacket *Packet = new TPacket(a_Packet);
                Item->AddObject((void*)Packet);
                return;
            }
        }

        // 버퍼방출, 더이상 방출할 것이 없을 때 까지...
        while (BufferFlush() > 0);
    }
    __finally
    {
        // m_pMaxBuf 설정
        if (m_pMaxBuf < GetBufferSize())
            m_pMaxBuf = GetBufferSize();
    }
}
//---------------------------------------------------------------------------
int TPacketManager::BufferFlush(void)
{
    // 버퍼 방출
    int result, nCount = 0;

    for (TObjectItem *Item = m_pBufferList->First(); Item != NULL; Item = m_pBufferList->Next())
    {
        TPacket *Packet = (TPacket*)Item->Object;
        result = m_pPacket[Packet->Number - 1].Add(*Packet);
        if (result == -1)
            throw std::logic_error(EPINVALID);
        else if (result > 0)
        {
            m_pBufferList->DeleteSelected();
            nCount++;
        }
    }
    return nCount;
}
//---------------------------------------------------------------------------
bool TPacketManager::CompareSize(const TMsgSize &a_MsgSize) const
{
    if (m_pCount != a_MsgSize.Count)
        return false;

    TPacket *Packet;
    TObjectItem *Item;
    int i = 0;

    for (Item = m_pBufferList->First(); Item != NULL; Item = m_pBufferList->Next(), i++)
    {
        Packet = (TPacket*)(Item->Object);
        cout << Packet->Start << " - " << Packet->End << endl;
        cout << (i + 1) << ": " << Packet->GetSize() << ", " << a_MsgSize.GetSize(i) << endl;
        if (Packet->GetSize() != a_MsgSize.GetSize(i))
            return false;
    }

    return true;
}
//---------------------------------------------------------------------------

