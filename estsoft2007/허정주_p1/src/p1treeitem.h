//---------------------------------------------------------------------------
#ifndef p1treeitemH
#define p1treeitemH
//---------------------------------------------------------------------------
#include <istream>
//---------------------------------------------------------------------------
class TTreeItem
{
public:
	friend std::ostream& operator<<(std::ostream& a_OStream, const TTreeItem &Item);

	void Clear(void);
	void Init(const int &Size);

	void Assign(TTreeItem *Value); // Assign childs
	void ChildNull(void);          // m_pChildLeft = m_pChildRight = NULL

	bool HasParent(void) const;
	int HasChild(void) const; // 자식 노드 유무, 말단노드는 false
	bool HasTermChild(void) const;

	TTreeItem* GetParent(void) const;
	void SetParent(TTreeItem *Value);

	TTreeItem* GetLeft(void) const;
	TTreeItem* GetRight(void) const;

	void Recover(void);

	int GetDepth(void) const; // 부모로부터의 깊이
	int HasDepth(TTreeItem *Adder = NULL) const; // 이 노드 하부의 깊이
	int HasShallow(void) const;

	bool IsValid(TTreeItem *Adder = NULL) const;
public:
	TTreeItem(const int &Depth = 1);
	TTreeItem(TTreeItem *AOwner);
	virtual ~TTreeItem(void);
private:
	TTreeItem *m_pParent;

	TTreeItem *m_pChildLeft;
	TTreeItem *m_pChildRight;

	int m_pDepth;
};
//---------------------------------------------------------------------------
std::ostream& operator<<(std::ostream& a_OStream, const TTreeItem &Item);
//---------------------------------------------------------------------------
#endif
