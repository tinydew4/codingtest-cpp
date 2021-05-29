//---------------------------------------------------------------------------
#ifndef p1treelistH
#define p1treelistH
//---------------------------------------------------------------------------
#include <istream>
//---------------------------------------------------------------------------
class TTreeItem;
class TTreeList
{
public:
	friend std::ostream& operator<<(std::ostream& a_OStream, const TTreeList &a_TreeList);

	bool IsValid(void) const;

	void SetSize(const int &Size);
	bool NextStep(void);
public:
	TTreeList(void);
	virtual ~TTreeList(void);
private:
	TTreeItem *m_pHead;
	TTreeItem *m_pTemp;

	TTreeItem* GetNextMove(TTreeItem **Item);
	TTreeItem* GetTarget(TTreeItem *Source, TTreeItem *Target, TTreeItem *From);
};
//---------------------------------------------------------------------------
std::ostream& operator<<(std::ofstream& a_OStream, const TTreeList &a_TreeList);
//---------------------------------------------------------------------------
#endif
