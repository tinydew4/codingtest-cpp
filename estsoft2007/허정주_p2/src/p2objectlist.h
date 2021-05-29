//---------------------------------------------------------------------------
#ifndef p2objectlistH
#define p2objectlistH
//---------------------------------------------------------------------------
class TObjectItem
{
public:
    __declspec(property(get = m_pPrev, put = m_pPrev)) TObjectItem* Prev;
    __declspec(property(get = m_pNext, put = m_pNext)) TObjectItem* Next;
    __declspec(property(get = m_pObject)) void *Object;

    void AddObject(void *a_Object);
public:
    TObjectItem(void);
private:
    void *m_pObject;

    TObjectItem* m_pPrev;
    TObjectItem* m_pNext;
};
//---------------------------------------------------------------------------
class TObjectList
{
public:
    operator TObjectList(void);

    TObjectItem* Add(void);
    void Delete(TObjectItem *Value);
    void Delete(const int &Index);
    void DeleteSelected(void);

    void Clear(void);

    TObjectItem* First(void);
    TObjectItem* Last(void);
    TObjectItem* Next(void);
public:
    TObjectList(void);
    virtual ~TObjectList(void);
private:
    TObjectItem* m_pFirst;
    TObjectItem* m_pLast;

    TObjectItem* m_pCurrent;
};
//---------------------------------------------------------------------------
#endif
