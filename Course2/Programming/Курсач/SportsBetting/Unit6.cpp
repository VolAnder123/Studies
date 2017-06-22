//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Unit6.h"
#include "Unit5.h"
#include "Unit4.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm6 *Form6;
//---------------------------------------------------------------------------
__fastcall TForm6::TForm6(TComponent* Owner)
        : TForm(Owner)
{
}
//---------------------------------------------------------------------------
void TForm6::OpenStatistic()
{
        list<string> AllUsers = Form5->FindAllUsers();
        int size = AllUsers.size();
        for (int i = 0; i < size; i++)
        {
                string login = AllUsers.front();
                AllUsers.pop_front();
                if(login == "administrator")
                {
                        continue;
                }
                string pathBet = path + login + "\\" + login + "Bet.txt";
                ifstream file(pathBet.c_str());
                string str;
                OneBet bet;
                while(!file.eof())
                {
		        getline(file, str, '\t');
                        string temp;     //�������� ���������� temp �.�. � ��������� �������
                        getline(file, temp, '\n');//str ��������� ��. � �� ��� ������ �����
                        if (str.empty())
                        {
                                continue;
                        }
                        if(str == "�������")
                        {
                                getline(file, str, '\t');
                                bet.date = str;
                                getline(file, str, ' ');
                                getline(file, str, ' ');
                                getline(file, str, ' ');
                                getline(file, str, ' ');
                                getline(file, str, ' ');
                                getline(file, str, ' ');
                                bet.currency = str;
                                getline(file, str, ' ');
                                getline(file, str, '\n');
                                bet.win = StrToFloat(str.c_str());

                        }
                        else if ((str == "��������") || (str == "\n��������"))
                        {
                                getline(file, str, '\t');
                                bet.date = str;
                                getline(file, str, ' ');
                                getline(file, str, ' ');
                                getline(file, str, ' ');
                                getline(file, str, ' ');
                                getline(file, str, ' ');
                                getline(file, str, ' ');
                                bet.currency = str;
                                getline(file, str, ' ');
                                getline(file, str, '\n');
                                bet.win = StrToFloat(str.c_str());
                                do
                                {
                                        getline(file, str, '\n');
                                }while (str != "/��������\t");
                        }
                        else if ((str == "�������") || (str == "\n�������"))
                        {
                                getline(file, str, '\n');
                                getline(file, str, '\t');
                                bet.date = str;
                                getline(file, str, ' ');
                                getline(file, str, ' ');
                                getline(file, str, ' ');
                                getline(file, str, ' ');
                                getline(file, str, ' ');
                                getline(file, str, ' ');
                                bet.currency = str;
                                getline(file, str, ' ');
                                getline(file, str, '\n');
                                bet.win = StrToFloat(str.c_str());
                                do
                                {
                                        getline(file, str, '\n');
                                }while (str != "/�������\t");
                        }
                        allStatistic.push_back(bet);
                }
                file.close();
        }
}

void TForm6::CalculateStatistic(TDate date1, TDate date2)
{
        TDate delta = date2 - date1;
        double days = delta.Val;
        if (days == 0)
        {
                days = 1;
        }
        int _date1 = int(date1.Val);
        int _date2 = int(date2.Val);
        int size = allStatistic.size();
        int allBet = 0;
        float balance = 0;
        int winBet = 0;
        list<OneBet> copyAllStatistic = allStatistic;
        for (int i = 0; i < size; i++)
        {
                OneBet bet = copyAllStatistic.front();
                copyAllStatistic.pop_front();
                TDate temp = StrToDate(bet.date.c_str());
                int _temp = int(temp.Val);
                if ((_temp <= _date2) && (_temp >= _date1))
                {       
                        allBet++;
                        balance += bet.win;
                        if (bet.win > 0)
                        {
                                winBet++;
                        }
                }
        }
        if (allBet > 0)
        {
                balance = -balance;
                Edit1->Text = FloatToStr(balance);
                Edit2->Text = IntToStr(allBet);
                double betInOneDay = allBet / days;
                betInOneDay = int(betInOneDay*100 + 0.5)/100.0;
                Edit3->Text = FloatToStr(betInOneDay);
                double procent = ((double(winBet) / allBet) * 100);
                Edit4->Text = FloatToStr(procent);
        }
        else
        {
                Edit1->Text = "0";
                Edit2->Text = "0";
                Edit3->Text = "0";
                Edit4->Text = "0";
        }
        Label10->Caption = "� " + DateToStr(date1) + " �� " + DateToStr(date2);
}

void __fastcall TForm6::FormCreate(TObject *Sender)
{
        Edit1->Clear();
        Edit2->Clear();
        Edit3->Clear();
        Edit4->Clear();
        DateTimePicker2->Date = Date();
        string date2 = (DateToStr(DateTimePicker2->Date)).c_str();
        int pos = date2.find('.', 1);
        string day = date2.substr(0, pos);
        string monthAndYear = date2.substr(pos, date2.length() - 1);
        int day1 = StrToInt(day.c_str());
        day1--;
        string date1 = (FloatToStr(day1)).c_str() + monthAndYear;
        DateTimePicker1->Date = StrToDate(date1.c_str());
}
//---------------------------------------------------------------------------


void __fastcall TForm6::DateTimePicker1Change(TObject *Sender)
{
        TDate date1 = DateTimePicker1->Date;
        TDate date2 = DateTimePicker2->Date;
        Form6->CalculateStatistic(date1, date2);
}
//---------------------------------------------------------------------------

void __fastcall TForm6::DateTimePicker2Change(TObject *Sender)
{
        TDate date1 = DateTimePicker1->Date;
        TDate date2 = DateTimePicker2->Date;
        Form6->CalculateStatistic(date1, date2);
}
//---------------------------------------------------------------------------

void __fastcall TForm6::Label4Click(TObject *Sender)
{
        TDate date1 = dateOfficeBirthDay;
        TDate date2 = Date();
        Form6->CalculateStatistic(date1, date2);
}
//---------------------------------------------------------------------------



