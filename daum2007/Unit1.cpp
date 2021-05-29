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
    // TEdit 컨트롤의 텍스트 중앙정렬
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
    // 정수만 입력/수정/삭제 가능
    if ( ( '0' > Key || Key > '9' ) && Key != 8 )
    {
        Key = 0;
    }
}
//---------------------------------------------------------------------------
int __fastcall GetInteger( AnsiString Value )
{
    // 문자열을 입력받아 정수면 그 수를, 아니면 0을 반환
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
    // 세 값 중 하나라도 비어있으면 처리안함
    if ( Edit1->Text.IsEmpty() == true ||
        Edit2->Text.IsEmpty() == true ||
        Edit3->Text.IsEmpty() == true )
    {
        return;
    }

    // 각 값을 읽어옴
    int p = GetInteger( Edit1->Text );
    int q = GetInteger( Edit2->Text );
    int n = GetInteger( Edit3->Text );

    // 결과 뷰어 초기화
    Memo1->Lines->Clear();

    // q 값이 0 이면 Div by zero
    if ( q == 0 )
    {
        Memo1->Lines->Add( "Division by zero!!!" );
        return;
    }

    Memo1->Lines->BeginUpdate();

    // 정수부 연산
    while ( p > q )
    {
        Memo1->Lines->Text = Memo1->Lines->Text + IntToStr( static_cast<int>( p / q ) );
        p %= q;
    }

    // 소수점 출력
    Memo1->Lines->Text = Memo1->Lines->Text + ".";

    // 소수부 연산
    while ( n-- > 0 )
    {
        p *= 10;
        Memo1->Lines->Text = Memo1->Lines->Text + IntToStr( static_cast<int>( p / q ) );
        p %= q;
    }

    Memo1->Lines->EndUpdate();
}
//---------------------------------------------------------------------------

