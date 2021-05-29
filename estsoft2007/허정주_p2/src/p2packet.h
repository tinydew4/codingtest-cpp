//---------------------------------------------------------------------------
#ifndef p2packetH
#define p2packetH
//---------------------------------------------------------------------------
#include "p2common.h"
#include <istream>
//---------------------------------------------------------------------------
class TPacket
{
public:
    friend std::istream& operator>>(std::istream &a_IStream, TPacket &a_Packet);
    friend std::ostream& operator<<(std::ostream &a_OStream, TPacket &a_Packet);

    TPacket& operator=(const TPacket& a_Packet);

    __declspec(property(get = m_pNumber)) int Number;
    __declspec(property(get = m_pStart))  int Start;
    __declspec(property(get = m_pEnd))    int End;

    bool IsFirst(void) const;
    int GetSize(void) const;
    int Add(const TPacket &a_Packet);
public:
    TPacket(void);
    TPacket(int a_Number, int a_Start, int a_End);
private:
    int m_pNumber;
    int m_pStart;
    int m_pEnd;
};
//---------------------------------------------------------------------------
std::istream& operator>>(std::istream &a_IStream, TPacket &a_Packet);
std::ostream& operator<<(std::ostream &a_OStream, TPacket &a_Packet);
//---------------------------------------------------------------------------
#endif
