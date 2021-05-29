//---------------------------------------------------------------------------
#ifndef p2msgsizeH
#define p2msgsizeH
//---------------------------------------------------------------------------
#include <istream>
//---------------------------------------------------------------------------
class TMsgSize
{
public:
    friend std::istream& operator>>(std::istream &a_IStream, TMsgSize &a_MsgSize);
    friend std::ostream& operator<<(std::ostream &a_OStream, TMsgSize &a_MsgSize);
    __declspec(property(get = m_pCount)) int Count;

    int GetSize(const int &Index) const;
    void SetSize(int a_Size);
public:
    TMsgSize(void);
    TMsgSize(int a_Size);
    virtual ~TMsgSize(void);
private:
    int *m_pSize;
    int m_pCount;
};
//---------------------------------------------------------------------------
std::istream& operator>>(std::istream &a_IStream, TMsgSize &a_MsgSize);
std::ostream& operator<<(std::ostream &a_OStream, TMsgSize &a_MsgSize);
//---------------------------------------------------------------------------
#endif
 