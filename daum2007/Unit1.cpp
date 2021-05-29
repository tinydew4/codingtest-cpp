//---------------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop

#include "Unit1.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;
//---------------------------------------------------------------------------
void __fastcall SetAlignCenter( TEdit *Edt )
{
    // TEdit ��Ʈ���� �ؽ�Ʈ �߾�����
    SetWindowLong(
        Edt->Handle,
        GWL_STYLE,
        GetWindowLong( Edt->Handle, GWL_STYLE ) | ES_CENTER
    );
    Edt->Repaint();
}
//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
    : TForm(Owner)
{
    SetAlignCenter( Edit1 );
    SetAlignCenter( Edit2 );
    SetAlignCenter( Edit3 );
}
//---------------------------------------------------------------------------
void __fastcall TForm1::EditIntKeyPress(TObject *Sender, char &Key)
{
    // ������ �Է�/����/���� ����
    if ( ( '0' > Key || Key > '9' ) && Key != 8 )
    {
        Key = 0;
    }
}
//---------------------------------------------------------------------------
int __fastcall GetInteger( AnsiString Value )
{
    // ���ڿ��� �Է¹޾� ������ �� ����, �ƴϸ� 0�� ��ȯ
    try
    {
        return Value.ToInt();
    }
    catch ( ... )
    {
        return 0;
    }
}
//---------------------------------------------------------------------------
void __fastcall TForm1::SpeedButton1Click(TObject *Sender)
{
    // �� �� �� �ϳ��� ��������� ó������
    if ( Edit1->Text.IsEmpty() == true ||
        Edit2->Text.IsEmpty() == true ||
        Edit3->Text.IsEmpty() == true )
    {
        return;
    }

    // �� ���� �о��
    int p = GetInteger( Edit1->Text );
    int q = GetInteger( Edit2->Text );
    int n = GetInteger( Edit3->Text );

    // ��� ��� �ʱ�ȭ
    Memo1->Lines->Clear();

    // q ���� 0 �̸� Div by zero
    if ( q == 0 )
    {
        Memo1->Lines->Add( "Division by zero!!!" );
        return;
    }

    Memo1->Lines->BeginUpdate();

    // ������ ����
    while ( p > q )
    {
        Memo1->Lines->Text = Memo1->Lines->Text + IntToStr( static_cast<int>( p / q ) );
        p %= q;
    }

    // �Ҽ��� ���
    Memo1->Lines->Text = Memo1->Lines->Text + ".";

    // �Ҽ��� ����
    while ( n-- > 0 )
    {
        p *= 10;
        Memo1->Lines->Text = Memo1->Lines->Text + IntToStr( static_cast<int>( p / q ) );
        p %= q;
    }

    Memo1->Lines->EndUpdate();
}
//---------------------------------------------------------------------------

