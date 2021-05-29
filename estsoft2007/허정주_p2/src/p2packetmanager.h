//---------------------------------------------------------------------------
#ifndef p2packetmanagerH
#define p2packetmanagerH
//---------------------------------------------------------------------------
#include "p2packet.h"
#include "p2objectlist.h"
#include "p2msgsize.h"
//---------------------------------------------------------------------------
#include <iostream>
using namespace std;
class TPacketManager
{
public:
    void SetSize(int a_Size);
    void Add(const TPacket &a_Packet);
    bool CompareSize(const TMsgSize &a_MsgSize) const;

    __declspec(property(get = m_pMaxBuf))     int BufferMax;
    __declspec(property(get = GetBufferSize)) int BufferSize;
public:
    TPacketManager(void);
    virtual ~TPacketManager(void);
private:
    TPacket *m_pPacket;
    int m_pCount;
    int m_pMaxBuf;

    TObjectList *m_pBufferList;
    int GetBufferSize(void);
    int BufferFlush(void);
};
//---------------------------------------------------------------------------
#endif
