//---------------------------------------------------------------------------
#include <assert>
#pragma hdrstop

#include "p2manager.h"
#include "p2common.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
//---------------------------------------------------------------------------
TManager::TManager(std::istream &a_IFile, std::ostream &a_OFile)
    : m_pIFile(a_IFile), m_pOFile(a_OFile)
{
}
//---------------------------------------------------------------------------
void TManager::ReadHead(int *N, int *M)
{
    assert(N);
    assert(M);

    m_pIFile >> *N >> *M;

    if (*N == 0 && *M == 0)
        return;
    if (!(0 < *N && *N < 6))
        throw std::out_of_range(EPMSGMANY);
    if (!(0 < *M && *M < 1001))
        throw std::out_of_range(EPCNTMANY);
}
//---------------------------------------------------------------------------
void TManager::ReadSize(const int &N)
{
    m_pPacketManager.SetSize(N);
    m_pMsgSize.SetSize(N);

    m_pIFile >> m_pMsgSize;
}
//---------------------------------------------------------------------------
void TManager::ReadPacket(TPacket *Temp, const int &N)
{
    assert(Temp);

    m_pIFile >> *Temp;
    if (!(0 < Temp->Number && Temp->Number <= N))
        throw std::out_of_range(EPINVALID);

    m_pPacketManager.Add(*Temp);
}
//---------------------------------------------------------------------------
void TManager::Run(void)
{
    int N, M, Count = 0;
    TPacket Temp;

    while (1)
    {
        ReadHead(&N, &M);     // N M �б�
        if (N == 0 && M == 0)
            break;

        ReadSize(N);          // �޼��� ũ�� �б�
        for (; M--;)          // M ���� Packet ���� �б�
            ReadPacket(&Temp, N);

        // �ִ� ����ũ�� ���
        m_pOFile << "Case " << (++Count) << ": "
            << m_pPacketManager.BufferMax << std::endl << std::endl;

        // �޼��� ũ�� ���� ����
        if (m_pPacketManager.CompareSize(m_pMsgSize) == false)
            throw std::length_error(EPDIFFSIZE);
    }
}
//---------------------------------------------------------------------------
