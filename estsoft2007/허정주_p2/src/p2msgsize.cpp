//---------------------------------------------------------------------------
#include "p2msgsize.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
//---------------------------------------------------------------------------
std::istream& operator>>(std::istream &a_IStream, TMsgSize &a_MsgSize)
{
    for (int j = a_MsgSize.m_pCount, i = 0; j--; i++)
        a_IStream >> a_MsgSize.m_pSize[i];

    return a_IStream;
}
//---------------------------------------------------------------------------
std::ostream& operator<<(std::ostream &a_OStream, TMsgSize &a_MsgSize)
{
    a_OStream << a_MsgSize.m_pSize[0];

    for (int j = a_MsgSize.m_pCount - 1, i = 1; j--; i++)
        a_OStream << " " << a_MsgSize.m_pSize[i];

    return a_OStream;
}
//---------------------------------------------------------------------------
TMsgSize::TMsgSize(void)
    : m_pSize(NULL), m_pCount(0)
{
}
//---------------------------------------------------------------------------
TMsgSize::TMsgSize(int a_Size)
    : m_pSize(NULL), m_pCount(a_Size)
{
    if (a_Size > 0)
        m_pSize = new int[a_Size];
}
//---------------------------------------------------------------------------
TMsgSize::~TMsgSize(void)
{
    if (m_pSize)
        delete[] m_pSize;
}
//---------------------------------------------------------------------------
int TMsgSize::GetSize(const int &Index) const
{
    return (m_pSize != NULL && (0 <= Index && Index < m_pCount)?
        m_pSize[Index] : -1);
}
//---------------------------------------------------------------------------
void TMsgSize::SetSize(int a_Size)
{
    if (a_Size == m_pCount)
    {
        // 이미 같다... 그냥 초기화
        for (int i = m_pCount; i--;)
            m_pSize[i] = 0;
    }
    else
    {
        if (m_pSize)
            delete m_pSize;
        if (a_Size > 0)
            m_pSize = new int[a_Size];
        m_pCount = a_Size;
    }
}
//---------------------------------------------------------------------------
