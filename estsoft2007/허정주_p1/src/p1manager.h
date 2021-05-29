//---------------------------------------------------------------------------
#ifndef p1managerH
#define p1managerH
//---------------------------------------------------------------------------
#include <istream>
//---------------------------------------------------------------------------
class TTreeList;
class TManager
{
public:
	void Run(void);
public:
	TManager(std::istream &a_IStream, std::ostream &a_OStream);
	virtual ~TManager(void);
private:
	TTreeList *m_pTreeList;

	std::istream &m_pIStream;
	std::ostream &m_pOStream;
};
//---------------------------------------------------------------------------
#endif
