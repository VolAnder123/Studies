//---------------------------------------------------------------------------

#include <vcl.h>
#include <iostream>
#include <string>
#include <Windows.h>
#include <string.h>
#include <fstream>
#include <locale.h>
#include <list>
#include <cstring.h>
#pragma hdrstop

#include "Unit3.h"
#include "Unit1.h"
#include "MadeBet.cpp"
using namespace std;
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm3 *Form3;
//---------------------------------------------------------------------------
__fastcall TForm3::TForm3(TComponent* Owner)
        : TForm(Owner)
{
}
//---------------------------------------------------------------------------

void __fastcall TForm3::FormCreate(TObject *Sender)
{
        Memo1->Clear();
        Memo2->Clear();
        Memo3->Clear();
        LoadResult();
}
//---------------------------------------------------------------------------
list<string> TForm3::LoadBet(ifstream& file, ofstream& fileCopy, string currencyData)
{
	string str;
        list<string> winMoneyList; 
	while(!file.eof())
	{
                string winAndCurrency = "";
		getline(file, str, '\t');
                string temp;     //�������� ���������� temp �.�. � ��������� �������
                getline(file, temp, '\n');//str ��������� ��. � �� ��� ������ �����
                if(str == "�������")
                {
                        winAndCurrency = LoadOrdinarMBet(file, fileCopy, currencyData);
                }
                else if ((str == "��������") || (str == "\n��������"))
                {
                        winAndCurrency = LoadExpressMBet(file, fileCopy, currencyData);
                }
                else if ((str == "�������") || (str == "\n�������"))
                {
                        winAndCurrency = LoadSystemMBet(file, fileCopy, currencyData);
                }
                if (winAndCurrency != "")
                {
                        winMoneyList.push_back(winAndCurrency);
                }
	}
        return winMoneyList;
}

Bet TForm3::LoadOneBet(ifstream& file)
{
        Bet newBet;
        string str;
        getline(file, str, '\t');
        if ((str == "/��������") || (str == "/��������\n") || (str == "/�������") || (str == "/�������\n"))
        {
                return newBet;//����������� �������� ���������� ���� Bet �� ���������
        }
        newBet.date = str;
        getline(file, str, ' ');
        newBet.home = str;
        getline(file, str, ' ');
        newBet.guest = str;
        getline(file, str, ' ');
        newBet.resultMatch = str;
        getline(file, str, ' ');
        newBet.coefficient = double(StrToFloat(str.c_str()));
        double sdaf = newBet.coefficient;
        newBet.coefficient = int(sdaf*100 + 0.5)/100.0;
        getline(file, str, ' ');
        newBet.money = StrToFloat(str.c_str());
        getline(file, str, ' ');
        newBet.currency = str;
        getline(file, str, ' ');
        newBet.isBetTreatment = StrToBool(str.c_str());
        getline(file, str, '\n');
        newBet.winning = StrToFloat(str.c_str());
        return newBet;
}

string TForm3::LoadOrdinarMBet(ifstream& file, ofstream& fileCopy, string currencyData)
{
        Bet newBet = LoadOneBet(file);
        float win = 0;//���������� ������
        string winAndCurrency = "";//���� ����� �� �������� ����� ���������� ��������, �� ������ �������� ���
        if(newBet.date <= currencyData)
        {
                int size = resultList.size();
                list <Result> copymBResult = resultList;
                for (int i = 0; i < size; i++)
                {
                        Result tempResult = copymBResult.front();
                        copymBResult.pop_front();
                        if ((tempResult.home == newBet.home) && (tempResult.guest == newBet.guest))
                        {
                                if (tempResult.date == newBet.date)
                                {
                                   //������ ������� � �� ����������
                                   if((tempResult.result == newBet.resultMatch) && (newBet.isBetTreatment == false))
                                   {
                                        ToMemo(newBet, Memo2);
                                        win = newBet.money * newBet.coefficient;
                                        Memo2->Lines->Add("\t�������: " + FloatToStr(win));
                                        string win1 = (FloatToStr(win)).c_str();
                                        winAndCurrency = win1 + " " + newBet.currency;
                                        newBet.isBetTreatment = true;
                                        newBet.winning = win;
                                   }
                                   //������ ������� � ����������
                                   else if((tempResult.result == newBet.resultMatch) && (newBet.isBetTreatment == true))
                                   {
                                        ToMemo(newBet, Memo2);
                                        win = newBet.money * newBet.coefficient;
                                        Memo2->Lines->Add("\t�������: " + FloatToStr(win));
                                   }
                                   //������ �� �������
                                   else
                                   {
                                        ToMemo(newBet, Memo3);
                                        Memo3->Lines->Add("\t�������: 0");
                                        newBet.isBetTreatment = true;
                                        newBet.winning = -newBet.money;
                                   }
                                }
                        }
                }
        }
        else
        {
                ToMemo(newBet, Memo1);
        }
        List temp;
        temp.push_back(newBet);
        SaveOrdinarToFile(temp, fileCopy, defaultCurrency, defaultMoney);
        temp.clear();
        return winAndCurrency;
}

//��������� ������ ���� ��������
string TForm3::LoadExpressMBet(ifstream& file, ofstream& fileCopy, string currencyData)
{
        string str;
        bool isWin = false;
        bool isLose = false;
        bool isCurrent = false;
        bool isGotMoney = false;
        List temp;
        float win = 0;//���������� ������
        float money;
        string currency;
        float coefExpress = 1;
        string winAndCurrency = "";//���� ����� �� �������� ����� ���������� ��������, �� ������ �������� ���
        string forMemo = "��������\n";
        Bet newBet;
        while(!file.eof())
        {
                Bet newBet = LoadOneBet(file);
                if (!newBet.date.empty())
                {
                        if(newBet.date <= currencyData)
                        {
                                money = newBet.money;
                                currency = newBet.currency;
                                int size = resultList.size();
                                list <Result> copymBResult = resultList;
                                for (int i = 0; i < size; i++)
                                {
                                        Result tempResult = copymBResult.front();
                                        copymBResult.pop_front();
                                        if ((tempResult.home == newBet.home) && (tempResult.guest == newBet.guest))
                                        {
                                                if (tempResult.date == newBet.date)
                                                {
                                                        //������ ������� � �� ����������
                                                        if((tempResult.result == newBet.resultMatch) && (newBet.isBetTreatment == false))
                                                        {
                                                                coefExpress *= newBet.coefficient;
                                                                newBet.isBetTreatment = true;
                                                                isWin = true;
                                                                isGotMoney = false;
                                                        }
                                                        else if((tempResult.result == newBet.resultMatch) && (newBet.isBetTreatment == true))
                                                        {
                                                                coefExpress *= newBet.coefficient;
                                                                isWin = true;
                                                                isGotMoney = true;
                                                        }
                                                        //������ �� �������
                                                        else
                                                        {
                                                                newBet.isBetTreatment = true;
                                                                isLose = true;
                                                        }
                                                }
                                                else
                                                {
                                                        isCurrent = true;
                                                }
                                                string kef = FloatToStr(newBet.coefficient).c_str();
                                                forMemo += newBet.date + " " + newBet.home + " " + newBet.guest + " " + newBet.resultMatch + " ��: " + kef + "\n";
                                                temp.push_back(newBet);
                                        }

                                }
                        }
                        else
                        {
                                isCurrent = true;
                                string kef = FloatToStr(newBet.coefficient).c_str();
                                forMemo += newBet.date + " " + newBet.home + " " + newBet.guest + " " + newBet.resultMatch + " ��: " + kef + "\n";
                                temp.push_back(newBet);
                        }

                }
                else
                {
                        getline(file, str, '\n');
                        break;
                }
        }//��� while
        string koef1 = (FloatToStr(coefExpress)).c_str();
        string money1 = (FloatToStr(newBet.money)).c_str();
        forMemo  += "��: " + koef1 + " �����: " + money1 + " " + newBet.currency + "\n";
        List copyTemp = temp;
        temp.clear();
        int size = copyTemp.size();
        if (isCurrent)//������� ��������
        {
                win = coefExpress * money;
                ExpressAndSystemToMemo(forMemo, Memo1);
                for (int i = 0; i < size; i++)
                {
                        Bet bet = copyTemp.front();
                        copyTemp.pop_front();
                        bet.isBetTreatment = false;
                        bet.winning = 0;
                        temp.push_back(bet);
                }
        }
        else if (isWin && !isLose && !isCurrent) //�������� ������
        {
                win = coefExpress * money;
                string win1 = (FloatToStr(win)).c_str();
                forMemo  += "\t�������: " + win1 + "\n";
                if (!isGotMoney)
                {
                        winAndCurrency = win1 + " " + currency;
                }
                ExpressAndSystemToMemo(forMemo, Memo2);
                for (int i = 0; i < size; i++)
                {
                        Bet bet = copyTemp.front();
                        copyTemp.pop_front();
                        bet.winning = win;
                        temp.push_back(bet);
                }
        }
        else if (isLose)
        {
                forMemo  += "\t�������: 0\n";
                ExpressAndSystemToMemo(forMemo, Memo3); 
                for (int i = 0; i < size; i++)
                {
                        Bet bet = copyTemp.front();
                        copyTemp.pop_front();
                        bet.isBetTreatment = true;
                        bet.winning = 0;
                        temp.push_back(bet);
                } 
        }
        SaveExpressToFile(temp, fileCopy, defaultCurrency, defaultMoney);
        temp.clear();
        return winAndCurrency;
}

void ExpressAndSystemToMemo(string forMemo, TMemo *Memo)
{
                while(!forMemo.empty())
                {
                        int pos = forMemo.find('\n', 1);
                        string temp = forMemo.substr(0, pos);
                        forMemo = forMemo.substr(pos + 1, forMemo.length());
                        Memo->Lines->Add(temp.c_str());
                }
}

string TForm3::LoadSystemMBet(ifstream& file, ofstream& fileCopy, string currencyData)
{
        string str;
        bool isWin = false;
        bool isLose = false;
        bool isCurrent = false;
        bool isGotMoney = false;
        List temp;
        float win = 0;//���������� ������
        float money;
        string currency;
        string winAndCurrency = "";//���� ����� �� �������� ����� ���������� ��������, �� ������ �������� ���
        Bet newBet;
        getline(file, str, '\n');
        string dimension = str;
        int dim1 = StrToInt(dimension[0]);
        int dim2 = StrToInt(dimension[2]);
        int canLostGames = dim2 - dim1;
        int lostGames = 0;
        list<float> coefList;
        string forMemo = "�������\n";
        forMemo += "�����������: " + dimension + "\n";
        while(!file.eof())
        {
                Bet newBet = LoadOneBet(file);
                if (!newBet.date.empty())
                {
                        if(newBet.date <= currencyData)
                        {
                                money = newBet.money;
                                currency = newBet.currency;
                                int size = resultList.size();
                                list <Result> copymBResult = resultList;
                                for (int i = 0; i < size; i++)
                                {
                                        Result tempResult = copymBResult.front();
                                        copymBResult.pop_front();
                                        if ((tempResult.home == newBet.home) && (tempResult.guest == newBet.guest))
                                        {
                                                if (tempResult.date == newBet.date)
                                                {
                                                        //������ ������� � �� ����������
                                                        if((tempResult.result == newBet.resultMatch) && (newBet.isBetTreatment == false))
                                                        {
                                                                coefList.push_back(newBet.coefficient);
                                                                newBet.isBetTreatment = true;
                                                                isWin = true;
                                                                isGotMoney = false;
                                                        }
                                                        //������ ������� � ����������
                                                        else if((tempResult.result == newBet.resultMatch) && (newBet.isBetTreatment == true))
                                                        {
                                                                coefList.push_back(newBet.coefficient);
                                                                isWin = true;
                                                                isGotMoney = true;
                                                        }
                                                        //������ �� �������
                                                        else
                                                        {
                                                                coefList.push_back(0);
                                                                newBet.isBetTreatment = true;
                                                                if (lostGames >= canLostGames)
                                                                {
                                                                        isLose = true;
                                                                }
                                                                lostGames++;
                                                        }
                                                }
                                                else
                                                {
                                                        isCurrent = true;
                                                }
                                                forMemo += newBet.date + " " + newBet.home + " " + newBet.guest + " " + newBet.resultMatch + "\n";
                                                temp.push_back(newBet);
                                        }

                                }
                        }
                        else
                        {
                                forMemo += newBet.date + " " + newBet.home + " " + newBet.guest + " " + newBet.resultMatch + "\n";
                                temp.push_back(newBet);
                        }

                }
                else
                {
                        getline(file, str, '\n');
                        break;
                }
        }//��� while  
        string money1 = (FloatToStr(money)).c_str();  
        List copyTemp = temp;
        temp.clear();
        int size = copyTemp.size();
        if (isCurrent)  //�������� ������
        {
                forMemo  += "�����������: " + dimension + " �����: " + money1 + " " + newBet.currency + "\n";
                ExpressAndSystemToMemo(forMemo, Memo1);
                for (int i = 0; i < size; i++)
                {
                        Bet bet = copyTemp.front();
                        copyTemp.pop_front();
                        bet.isBetTreatment = false;
                        bet.winning = 0;
                        temp.push_back(bet);
                }
        }
        if (isWin && !isLose && !isCurrent) //������ �������
        {
                list <float> temp1 = CalculateSystem(coefList, money, dim1);
                temp1.pop_front();
                win = temp1.front();
                forMemo  += " �����: " + money1 + " " + newBet.currency + "\n";
                string winnn = (FloatToStr(win)).c_str();
                forMemo  += "\t�������: " + winnn + "\n";
                if (!isGotMoney)
                {
                        string win1 = (FloatToStr(win)).c_str();
                        winAndCurrency = win1 + " " + currency;
                }
                ExpressAndSystemToMemo(forMemo, Memo2);
                for (int i = 0; i < size; i++)
                {
                        Bet bet = copyTemp.front();
                        copyTemp.pop_front();
                        bet.winning = win;
                        temp.push_back(bet);
                }
        }
        else if (isLose)//������ �� �������
        {
                forMemo  += "�����������: " + dimension + " �����: " + money1 + " " + newBet.currency + "\n";
                forMemo  += "\t�������: 0\n";
                ExpressAndSystemToMemo(forMemo, Memo3);
                for (int i = 0; i < size; i++)
                {
                        Bet bet = copyTemp.front();
                        copyTemp.pop_front();
                        bet.isBetTreatment = true;
                        bet.winning = -bet.money;
                        temp.push_back(bet);
                }
        }
        SaveSystemToFile(temp, fileCopy, defaultCurrency, defaultMoney, dimension);
        temp.clear();
        return winAndCurrency;
}

void ToMemo(Bet bet, TMemo *Memo)
{
        string lines = bet.date + " " + bet.home + " " + bet.guest + " " + bet.resultMatch ;
        string koef = (FloatToStr(bet.coefficient)).c_str();
        string money = (FloatToStr(bet.money)).c_str();
        lines += " ��: " + koef + " �����: " + money + " " + bet.currency;
        Memo->Lines->Add("�������");
        Memo->Lines->Add(lines.c_str());
}


