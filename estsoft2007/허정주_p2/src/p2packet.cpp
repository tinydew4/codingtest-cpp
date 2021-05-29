//---------------------------------------------------------------------------
#include "p2packet.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
//---------------------------------------------------------------------------
std::istream& operator>>(std::istream &a_IStream, TPacket &a_Packet)
{
    a_IStream >> a_Packet.m_pNumber >> a_Packet.m_pStart >> a_Packet.m_pEnd;

    if (a_Packet.m_pStart > a_Packet.m_pEnd)
        throw std::range_error(EPORDER);

    if (a_Packet.m_pEnd - a_Packet.m_pStart >= 64)
        throw std::overflow_error(EPOVERFLOW);

    return a_IStream;
}
//---------------------------------------------------------------------------
std::ostream& operator<<(std::ostream &a_OStream, TPacket &a_Packet)
{
    return (a_OStream << a_Packet.m_pNumber
        << " " << a_Packet.m_pStart
        << " " << a_Packet.m_pEnd);
}
//---------------------------------------------------------------------------
TPacket::TPacket(void)
    : m_pNumber(0), m_pStart(0), m_pEnd(0)
{
}
//---------------------------------------------------------------------------
TPacket::TPacket(int a_Number, int a_Start, int a_End)
    : m_pNumber(a_Number), m_pStart(a_Start), m_pEnd(a_End)
{
}
//---------------------------------------------------------------------------
TPacket& TPacket::operator=(const TPacket& a_Packet)
{
    m_pNumber = a_Packet.Number;
    m_pStart  = a_Packet.Start;
    m_pEnd    = a_Packet.End;

    return *this;
}
//---------------------------------------------------------------------------
bool TPacket::IsFirst(void) const
{
    return (m_pStart == 1);
}
//---------------------------------------------------------------------------
int TPacket::GetSize(void) const
{
    return (m_pStart <= m_pEnd? m_pEnd - m_pStart + 1: 0);
}
//---------------------------------------------------------------------------
int TPacket::Add(const TPacket &a_Packet)
{
    // 난 메세지 처음이 아닌데...
    if (m_pStart != 0 && m_pStart != 1)
        return -1;

    // 중간에 빠졌어...
    if (a_Packet.Start - (m_pEnd + 1) != 0)
        return 0;

    return (m_pEnd = a_Packet.End);
}
//---------------------------------------------------------------------------

