//---------------------------------------------------------------------------
#include "p1common.h"
#pragma hdrstop

#include "p1manager.h"
#include "p1treelist.h"
//---------------------------------------------------------------------------
TManager::TManager(std::istream &a_IStream, std::ostream &a_OStream)
	: m_pTreeList(NULL), m_pIStream(a_IStream), m_pOStream(a_OStream)
{
	m_pTreeList = new TTreeList;
}
//---------------------------------------------------------------------------
TManager::~TManager(void)
{
	if (m_pTreeList)
		delete m_pTreeList;
}
//---------------------------------------------------------------------------
void TManager::Run(void)
{
	int Size;

	m_pIStream >> Size;         // 크기 입력

	if (!(0 < Size && Size < 25))
		throw std::range_error(EINVARGS);

	m_pTreeList->SetSize(Size); // 초기화

	do
	{
		m_pOStream << *m_pTreeList << std::endl;
	} while (m_pTreeList->NextStep());
}
//---------------------------------------------------------------------------
