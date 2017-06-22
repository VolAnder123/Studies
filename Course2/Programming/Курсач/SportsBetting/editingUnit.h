//---------------------------------------------------------------------------

#ifndef editingUnitH
#define editingUnitH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <ComCtrls.hpp>
#include <Buttons.hpp>
#include <iostream>
#include <string>
#include <Windows.h>
#include <string.h>
#include <fstream>
#include <locale.h>
#include <list>
#include <cstring.h>
#include "WorkWithFile.h"
using namespace std;
//---------------------------------------------------------------------------
class TEditing : public TForm
{
__published:	// IDE-managed Components
        TPageControl *PageControl1;
        TTabSheet *TabSheet1;
        TDateTimePicker *DateTimePicker1;
        TUpDown *UpDown1;
        TUpDown *UpDown2;
        TEdit *Edit1;
        TEdit *Edit2;
        TEdit *Edit3;
        TEdit *Edit4;
        TEdit *Edit5;
        TEdit *Edit6;
        TEdit *Edit7;
        TLabel *Label1;
        TLabel *Label2;
        TLabel *Label3;
        TLabel *Label4;
        TLabel *Label5;
        TLabel *Label6;
        TLabel *Label7;
        TLabel *Label8;
        TComboBox *ComboBox1;
        TBitBtn *BitBtn1;
        TTabSheet *TabSheet2;
        TLabel *Label9;
        TDateTimePicker *DateTimePicker2;
        TLabel *Label10;
        TEdit *Edit8;
        TLabel *Label11;
        TEdit *Edit9;
        TBitBtn *BitBtn2;
        TLabel *Label12;
        TComboBox *ComboBox2;
        TTabSheet *TabSheet3;
        TLabel *Label13;
        TDateTimePicker *DateTimePicker3;
        TLabel *Label14;
        TEdit *Edit10;
        TLabel *Label15;
        TEdit *Edit11;
        TLabel *Label16;
        TLabel *Label17;
        TComboBox *ComboBox3;
        TBitBtn *BitBtn3;
        TComboBox *ComboBox4;
        TTabSheet *TabSheet4;
        TLabel *Label18;
        TDateTimePicker *DateTimePicker4;
        TLabel *Label19;
        TComboBox *ComboBox5;
        TLabel *Label20;
        TEdit *Edit12;
        TLabel *Label21;
        TEdit *Edit13;
        TBitBtn *BitBtn4;
        TLabel *Label22;
        void __fastcall FormCreate(TObject *Sender);
        void __fastcall UpDown2MouseUp(TObject *Sender,
          TMouseButton Button, TShiftState Shift, int X, int Y);
        void __fastcall BitBtn1Click(TObject *Sender);
        void __fastcall BitBtn2Click(TObject *Sender);
        void __fastcall BitBtn3Click(TObject *Sender);
        void __fastcall BitBtn4Click(TObject *Sender);
        void __fastcall Edit3Change(TObject *Sender);
private:	// User declarations
public:		// User declarations
        __fastcall TEditing(TComponent* Owner);
        void DeleteMatch(list<Match>& matchList, string date, string teamHome, string teamGuest);
        void DeleteResult(string date, string teamHome, string teamGuest);
};
//---------------------------------------------------------------------------
extern PACKAGE TEditing *Editing;
//---------------------------------------------------------------------------
#endif
