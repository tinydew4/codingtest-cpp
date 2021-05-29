//---------------------------------------------------------------------------
#ifndef p2managerH
#define p2managerH
//---------------------------------------------------------------------------
#include <istream>
#include "p2packetmanager.h"
//---------------------------------------------------------------------------
class TManager
{
public:
    void Run(void);
public:
    TManager(std::istream &a_IFile, std::ostream &a_OFile);
private:
    TPacketManager m_pPacketManager;
    TMsgSize m_pMsgSize;

    std::istream &m_pIFile;
    std::ostream &m_pOFile;

    void ReadHead(int *N, int *M);
    void ReadSize(const int &N);
    void ReadPacket(TPacket *Temp, const int &N);
};
//---------------------------------------------------------------------------
#endif
