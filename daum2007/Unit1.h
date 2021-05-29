//---------------------------------------------------------------------------
#ifndef Unit1H
#define Unit1H
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <Buttons.hpp>
#include <ExtCtrls.hpp>
//---------------------------------------------------------------------------
class TForm1 : public TForm
{
__published:	// IDE-managed Components
    TEdit *Edit1;
    TEdit *Edit2;
    TEdit *Edit3;
    TPanel *Panel1;
    TPanel *Panel2;
    TPanel *Panel3;
    TMemo *Memo1;
    TSpeedButton *SpeedButton1;
    void __fastcall EditIntKeyPress(TObject *Sender, char &Key);
    void __fastcall SpeedButton1Click(TObject *Sender);
private:	// User declarations
public:		// User declarations
    __fastcall TForm1(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TForm1 *Form1;
//---------------------------------------------------------------------------
#endif
