//---------------------------------------------------------------------------

#ifndef BettingH
#define BettingH
using namespace std;
struct Bet
{
        string date;
        string home;
        string guest;
        string resultMatch;
        double coefficient;
        float money;
        string currency;
        bool isBetTreatment;
        float winning;
};

string emptyCoupon = "����� ������ ����";
int defaultMoney = 0;
string defaultCurrency = "BLR";
typedef list<int> intList;
typedef list<Bet> List;
List  ordinarList;
List expressList;
List systemList;

list<string> Parse(string pars);
list<float> CalculateOrdinar(list<float> koefList, float money);
list<float> CalculateExpress(list<float> koefList, float money);
list<float> CalculateSystem(list<float> koefList, float money, int dimension);
void SaveOrdinarToFile(List& betList, ofstream& file, string currency, float money);
void SaveExpressToFile(List& betList, ofstream& file, string currency, float money);
void SaveSystemToFile(List& betList, ofstream& file, string currency, float money, string dimension);
list<intList> overkill(int size, int dimension);
float CalculateCoef(list<float> koefList, list<intList> allCombination, int dimension);
float GetElementList(list<float> koefList, int number);
//---------------------------------------------------------------------------
#endif
