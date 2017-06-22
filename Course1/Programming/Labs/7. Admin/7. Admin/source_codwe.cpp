#include <iostream>
#include <string>
#include <Windows.h>
#include <string.h>
#include <fstream>
#include <locale.h>
using namespace std;

//����� �������
typedef unsigned long tNumber;

//��� ���������� � �������
typedef unsigned long tSettled;

//��� ������
typedef string tType_room;

//��� ������ �� ���������� ����
typedef string tSeats;

//����
typedef unsigned long tFloor;

//������
typedef string tRepair;

//��� �� ����
typedef string tSea_views;

//��������� ��� �������� ���������� �� ����� ������
typedef struct Room 
{
	tNumber Number;
	tSettled Settled;
	tType_room Type_room;
	tSeats Seats;
	tFloor Floor;
	tRepair Repair;
	tSea_views Sea_views;
	Room *Next, *Prev;
	Room() { Settled = 0; };
}tRoom;

//���
typedef string tName;

//����� � ����� ��������
typedef string tSeries;

//���� ��������
typedef string tBirthday;

//����� �������
typedef unsigned long tNumber;

//���� �������
typedef string tArrival;

//���� ���������
typedef string tEviction;

//��������� ����������
typedef unsigned long tCost;

//��������� ��� �������� ���������� �� ����� ����������
typedef struct tGuest 
{
	tName Name;
	tSeries Series;
	tBirthday Birthday;
	tNumber Number;
	tArrival Arrival;
	tEviction Eviction;
	tCost Cost;
	tGuest *Next, *Prev;
} tGuest;

tRoom *All = NULL;//��� ������
tRoom *Free = NULL;//���������
tRoom *Busy = NULL;//�������
tRoom *Reserved = NULL;//�����������������
tRoom *temp_room = NULL;

tGuest *Guest = NULL;//����������
tGuest *temp_guest = NULL;

void list_of_numbers();
tRoom* Add_Room(tRoom *Room);//����������
void Output(tRoom *Room_temp);
void bypass(tRoom *Room);//�����
void number_search(tRoom *Room);
void number_search1(tRoom *Room_temp, int fiel, string element);
bool check_for_null(tRoom *Room_temp);
void editing ();//��������������
tRoom* Delete(tRoom *Room, int element);
void sort(tRoom *Room_temp);
int prior(string element);
tRoom* Sort(tRoom *Room_temp); 
void list_of_guest();
void Add_Guest();//����������� ����������
void bypas_guest();//�����
void Output_guest(tGuest *Guest_temp);//����� ���� � ������
tType_room type_search(tNumber Number, tRoom *Room, string find);
void eviction();
tRoom* edition1(tRoom *Room_temp, int number);
tRoom* select_one(tRoom* cha, tNumber Number);
void exemption_numbers();//������������ ������
void lodger_eviction(tNumber number);//��������� ����������
void Delete_Guest(int element);
int change_date();//�������� ������
void early_eviction();
void search_lodger();
void search_lodger1(int fiel, string element);
tRoom* Load(tRoom* Room, string list);
void Save(tRoom* Room, string list);
void Save_All();

void main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	All = Load(All, "All.txt");
	Free = Load(Free, "Free.txt");
	Busy = Load(Busy, "Busy.txt");
	Reserved = Load(Reserved, "Reserved.txt");
	while (true)
	{
		printf("\n1 - ������ �� �������� �������\n2 - ������ � ������������� ������������\n3 - ������ � ������������� ������������\n4 - ����� ���������� �� ������ ���������\n0 - �����\n������� ����� ��������: ");
		int choice = 0;
		scanf_s("%d", &choice);
		switch (choice)
		{
			case 1://������ �������
				list_of_numbers();
				break;
			case 2: //������ ������
				list_of_guest();
				break;
			case 3: //���������
				eviction();
				break;
			case 4:
				search_lodger();
				break;
			case 0:
				Save_All();
				return;
			default:
				system("cls");
				printf("������ �����. ������� ����� �� 0 �� 7\n");
				break;
		}
	}
}

void Save(tRoom* Room, string list)
{
	tRoom *Room_temp = Room;
	if (Room_temp != NULL)
	{
		while (Room_temp ->Next != NULL)
			Room_temp = Room_temp->Next;
		ofstream file(list);
		if (file == NULL)
		{
			cout << "������ ��� �������� ����� " << list << endl;
			system("pause");
			exit(0);
		}
		while (Room_temp != NULL)
		{
			file << Room_temp->Number << " ";
			file << Room_temp->Type_room << " ";
			file << Room_temp->Seats << " ";
			file << Room_temp->Floor << " ";
			file << Room_temp->Repair << " ";
			file << Room_temp->Sea_views << " ";
			file << Room_temp->Settled << "\n";
			Room_temp = Room_temp->Prev;
		}
	}
	if (list == "All.txt" && Guest != NULL)///////////�������� ������ �����������
	{
		ofstream filek("Visitor.txt");
		while (Guest ->Next != NULL)
			Guest = Guest->Next;
		if (filek == NULL)
		{
			cout << "������ ��� �������� ����� <<Visitor.txt>>" << endl ;
			system("pause");
			exit(0);
		}
		while (Guest != NULL)
		{
			filek << Guest->Number << " ";
			filek << Guest->Name << " ";
			filek << Guest->Series << " ";
			filek << Guest->Birthday << " ";
			filek << Guest->Arrival << " ";
			filek << Guest->Eviction << " ";
			filek << Guest->Cost << "\n";
			Guest = Guest->Prev;
		}
	}
}

void Save_All()
{
	Save(All, "All.txt");
	Save(Free, "Free.txt");
	Save(Busy, "Busy.txt");
	Save(Reserved, "Reserved.txt");
}

tRoom* Load(tRoom* Room, string list)
{
	tRoom* newelement = new tRoom;
	ifstream file(list);
	string str;
	Room = NULL;
	if (file == NULL)
	{
		cout << "������ ��� �������� ����� " << list << endl;
		system("pause");
		exit(0);
	}
	while (!file.eof())
	{
		getline(file, str, ' ');
		if (str.empty() || str == "\n")
			break;
		newelement->Number = stoi(str);
		getline(file, str, ' ');
		if (str == "�������" || str == "�����������")
		{
			newelement->Type_room = str + " �����";
			getline(file, str, ' ');
		}
		else
			newelement->Type_room = str;
		getline(file, newelement->Seats, ' ');
		getline(file, str, ' ');
		newelement->Floor = stoi(str);
		getline(file, newelement->Repair, ' ');
		getline(file, newelement->Sea_views, ' ');
		getline(file, str, '\n');
		newelement->Settled = stoi(str);
		newelement->Prev = Room;
		newelement->Next = NULL;
		if (Room)
		{
			temp_room->Next = newelement;
			temp_room->Next->Prev = temp_room;
			temp_room = temp_room->Next;
		}
		else
			temp_room = Room = newelement;
		newelement = new tRoom;
	}
	if (list == "All.txt")///////////�������� ������ �����������
	{
		tGuest* newelement = new tGuest;
		ifstream filek("Visitor.txt");
		string stro4ka;
		Guest = NULL;
		if (filek == NULL)
		{
			cout << "������ ��� �������� ����� <<Visitor.txt>>" << endl ;
			system("pause");
			exit(0);
		}
		while (!filek.eof())
		{
			getline(filek, stro4ka, ' ');				
			if (stro4ka.empty() || stro4ka == " " || stro4ka == "\n")
				break;
			newelement->Number = stoi(stro4ka);
			getline(filek, newelement->Name, ' ');
			getline(filek, stro4ka, ' ');
			newelement->Name = newelement->Name + " " + stro4ka;
			getline(filek, newelement->Series, ' ');
			getline(filek, newelement->Birthday, ' ');
			getline(filek, newelement->Arrival, ' ');
			getline(filek, newelement->Eviction, ' ');
			getline(filek, stro4ka, '\n');
			if (stro4ka.empty() || stro4ka == " " || stro4ka == "\n")
				newelement->Cost = 0;
			else
				newelement->Cost = stoi(stro4ka);
			newelement->Prev = Guest;
			newelement->Next = NULL;
			if (Guest)
			{
				temp_guest->Next = newelement;
				temp_guest->Next->Prev = temp_guest;
				temp_guest = temp_guest->Next;
			}
			else
				temp_guest = Guest = newelement;
				newelement = new tGuest;
		}
	}
	return Room;
}
/////++++++++++++++
void search_lodger()
{
	int choice = 0;
	string search;
	printf("�������� ����\n1 - ���\n2 - ����� � ����� ��������\n3 - ���� ��������\n4 - ����� �������\n5 - ���� ���������\n6 - ���� ���������\n������� �����: ");
	scanf_s("%d", &choice);
	switch (choice)
	{
	case 1://����� �� ������
		printf("������� ���: ");
		break;
	case 2://����� �� ���������� ����
		printf("������� ����� � ����� ��������: ");
		break;
	case 3://����� �� ����
		printf("������� ���� ��������: ");
		break;
	case 4://����� �� �����
		printf("������� ����� �������: ");
		break;
	case 5://����� �� �������
		printf("������� ���� ���������: ");
		break;
	case 6:
		printf("������� ���� ���������: ");
		break;
	}
	cin.ignore();
	getline(cin, search);
	search_lodger1(choice, search);
}

void search_lodger1(int fiel, string element)
{
	bool found = false;
	string find;
	tGuest *temp = Guest;
	while (temp != NULL)
	{
		switch (fiel)
		{
		case 1:
			find = temp->Name;
			break;
		case 2:
			find = temp->Series;
			break;
		case 3:
			find = temp->Birthday;
			break;
		case 4:
			find = to_string(temp->Number);
			break;
		case 5:
			find = temp->Arrival;
			break;
		case 6:
			find = temp->Eviction;
			break;
		}
		if (find == element)
		{
			Output_guest(temp);
			found = true;
		}
		temp = temp->Prev;
	}
	if (!found)
	{
		printf("����� �� ��� �����������\n");
		system("pause");
	}
}

void eviction()//������
{
	system("cls");
	while (true)
	{
		printf("1 - ����������� �����������, ����������� �������\n2 - ������������/�������� ������\n3 - ��������� ������\n4 - ������� � ���������� ����\n0 - �����\n������� �����: ");
		int choice = 0;
		cin.ignore();
		cin >> choice;
		switch (choice)
		{
		case 1:
			bypas_guest();
			break;
		case 2:
			printf("1 - ������������ ������\n2 - �������� ������\n������� �����: ");
			cin.ignore();
			cin >> choice;
			switch (choice)
			{
			case 1:
				exemption_numbers();
				break;
			case 2:
				printf("������� ����: ");
				change_date();
				break;
			}
			break;
		case 3:
			printf("������� ����, �� ������� ����� �������� ����������: ");
			early_eviction();
			break;
		case 4:
			return;
		case 0:
			Save_All();
			exit(0);
		}
	}
}

void exemption_numbers()//������������ ������
{
	if (Guest == NULL)
	{
		printf("������ ������ ����");
		system("pause");
		return;
	}
	int number = 0;
	printf("������� ������������� �����: ");
	cin >> number;
	tRoom *temp = Busy;
	while(temp != NULL && temp->Number != number) 
		temp = temp->Prev;
	if (temp == NULL)//���� �������� ���� � ������ ������� �������
	{
		while(Free != NULL && Free->Number != number) 
			Free = Free->Prev;
		Free->Settled--;
		while (Free->Next != NULL)
			Free = Free->Next;
	}
	else
	{
		tRoom *element = new tRoom;
		element = select_one(Busy, number);
		Busy =  Delete(Busy, number);
		element->Prev = Free;
		element->Next = NULL;
		if (Free == NULL)
			Free = element;
		else
		{
			Free->Next = element;
			Free = element;
		}
	}
	lodger_eviction(number);
}

void lodger_eviction(tNumber number)
{
	tGuest *temp = new tGuest;
	temp = Guest; 
	while(temp != NULL) 
	{
		if(temp->Number == number)
		{
			Delete_Guest(number);
			temp = Guest;
			while (temp->Next != NULL)
				temp = temp->Next;
		}
		else
			temp = temp->Prev;
	}
}

void Delete_Guest(int element)
{
	if (Guest == NULL)
		printf("������ ������-�� ����:(\n");
	else
	{
		tGuest *Room_temp = Guest;
		string opa;
		while(Room_temp != NULL)//���� ������ �������
			if(Room_temp->Number == element)
			{
				opa = Room_temp->Name;
				break;
			}
			else
				Room_temp = Room_temp->Prev;
		if(Room_temp->Prev == NULL)//���� ��������� ������ �������, ��
		{
			if (Room_temp->Next == NULL) 		//���� ���� ������� ������������
				Guest = Room_temp = NULL;
			else 				//���� �� ������, �� �� ������������
			{
				Room_temp->Next->Prev = NULL;
				Guest = Room_temp->Next;
			}
			delete Room_temp;
		}
		else if (Room_temp->Next == NULL)		//���� ������� ��������� �������, ��
		{
			Room_temp->Prev->Next = NULL;	//���������� ������� ��������� �� NULL
			Room_temp = Room_temp->Prev;		//��������� �� ��������� ������� //��������� �� �������������
			Guest = Room_temp;
		}		
		else //���� ������� ��������� � ������ ������
		{
			Room_temp->Prev->Next = Room_temp->Next; //���������� ������� ��������� �� ���������
			Room_temp->Next->Prev = Room_temp->Prev; //��������� ��������� �� ����������
			Room_temp = Room_temp->Prev;
			Guest = Room_temp->Next;
		}
		cout << "���������� " << opa << " �������" << endl;			
	}	
}

int change_date()
{
		string date, name;
		cin.ignore();
		getline(cin, date);
		printf("������� ���: ");
		getline(cin, name);
		while(Guest != NULL)//���� ������ �������
			if(Guest->Name == name)
				break;
			else
				Guest = Guest->Prev;

		if(Guest != NULL) 
		{
			Guest ->Eviction = date;
			int days = atoi(Guest->Eviction.substr(0, 2).c_str()) - atoi(Guest->Arrival.substr(0, 2).c_str());
			tRoom *temp = new tRoom;
			temp = Free;
			while (Free->Prev != NULL || (Free->Prev == NULL && Free->Next == NULL && Free != NULL))
			{
				if (Guest->Number == Free->Number)
				{
					Guest->Cost = 50 * days * prior(type_search(Guest->Number, Free, "Type_room")) * prior(type_search(Guest->Number, Free, "Seats")) * prior(type_search(Guest->Number, Free, "Repair")) * prior(type_search(Guest->Number, Free, "Sea_views"));
					break;
				}
				if (Free->Prev != NULL)
					Free = Free->Prev;
				else
					break;
			}
			if (Free->Prev == NULL)
			{
				temp = Busy;
				while (Busy->Prev != NULL || (Busy->Prev == NULL && Busy->Next == NULL && Busy != NULL))
				{
					if (Guest->Number == Busy->Number)
					{
						Guest->Cost = 50 * days * prior(type_search(Guest->Number, Busy, "Type_room")) * prior(type_search(Guest->Number, Busy, "Seats")) * prior(type_search(Guest->Number, Busy, "Repair")) * prior(type_search(Guest->Number, Busy, "Sea_views"));
						break;
					}
					if (Busy->Prev != NULL)
						Busy = Busy->Prev;
					else 
						break;
				}
			}
			while(Free->Next != NULL)
				Free = Free->Next;
			while(Busy->Next != NULL)
				Busy = Busy->Next;
			cout << "��������� ����������: " << Guest->Cost << "$" << endl; 
			while (Guest->Next != NULL)
				Guest = Guest->Next;
		}
		else 
		{
			system("cls");
			cout << "���������� � ������ " << name << " ���" << endl;
			system("pause");
		}
		return Guest->Number;
}

void early_eviction()
{
	int number = change_date();
	bool w = false;
	tRoom *temp = Busy; 
	w = false;
	while(temp != NULL) 
		if(temp->Number == number)
		{
			w = true;
			break;
		}
		else
			temp = temp->Prev;
	if (w)//����� ����������� �� ������ ������� ������� � ������ ���������
	{
		tRoom *element = new tRoom;
		element = select_one(Busy, number);
		Busy =  Delete(Busy, number);
		element->Prev = Free;
		element->Next = NULL;
		if (Free == NULL)
			Free = element;
		else
		{
			Free->Next = element;
			Free = element;
		}
	}
	else
	{
		while(Free->Prev != NULL || (Free->Prev == NULL && Free->Next == NULL && Free != NULL))
			if(Free->Number == number)
			{
				w = true;
				break;
			}
			else if(Free->Prev != NULL)
					Free = Free->Prev;
			else 
				break;
		if (w)
			Free->Settled--;
		else
		{
			system("cls");
			cout << "������ ������ ���";
			system("pause");
		}
	}
	lodger_eviction(number);
}

void bypas_guest()//�����
{
	tGuest *Guest_temp = new tGuest;
	Guest_temp = Guest;
	string date;
	system("cls");
	if (Guest_temp == NULL)
		printf("������ ������-�� ����:(\n");
	else
	{
		printf("������� ����: ");
		cin.ignore();
		getline(cin, date);
		while (Guest_temp != NULL)
		{
			if (date == Guest_temp->Eviction)
				Output_guest(Guest_temp);
			Guest_temp = Guest_temp->Prev;
		}
	}
	system("pause");
}

void Output_guest(tGuest *Guest_temp)//����� ���� � ������
{
	printf("------------------------------------------\n");
	cout << "���: " << Guest_temp->Name << endl;
	cout << "����� � ����� ��������: " << Guest_temp->Series << endl;
	cout << "���� ��������: " << Guest_temp->Birthday << endl;
	cout << "����� �������: " << Guest_temp->Number << endl;
	cout << "���� �������: " << Guest_temp->Arrival << endl;
	cout << "���� �������: " << Guest_temp->Eviction;
	printf("\n------------------------------------------\n");
}

///////////////////////////////////////////////////////////////////����� ������ � ������������� ������������

void list_of_guest()
{
	system("cls");
	while (true)
	{
		printf("1 - ����� ����������� ������\n2 - ����������� ����������\n3 - ������� � ���������� ����\n0 - �����\n������� ����� ��������: ");
		int choice = 0;
		scanf_s("%d", &choice);
		system("cls");
		switch (choice)
		{
		case 1:
			number_search(Free);
			break;
		case 2:
			Add_Guest();
			break;
		case 3:
			return;
		case 0:
			Save_All();
			exit(0);
		default:
			system("cls");
			printf("������ �����. ������� ����� �� 0 �� 3\n");
			break;
		}
	}	
}

void Add_Guest()//����������� ����������
{
	tGuest *newelement = new tGuest;
	int choice = 0;
	system("cls");
	cin.ignore();
	printf("������� ����� �������: ");
	scanf_s("%d", &newelement->Number);
	if (select_one(Free, newelement->Number) == NULL)//���������, ���� �� ����� �����
	{
		system("cls");
		cout << "������ ������ ���" << endl;
		system("pause");
		return;
	}
	cin.ignore();
	printf("������� ���: ");
	getline (cin, newelement->Name);
	printf("������� ����� � ����� ��������: ");
	getline (cin, newelement->Series);
	printf("������� ���� ��������: ");
	getline (cin, newelement->Birthday);
	printf("������� ���� ���������: ");
	getline (cin, newelement->Arrival);
	printf("������� ���� ���������: ");
	getline (cin, newelement->Eviction);
	int days = atoi(newelement->Eviction.substr(0, 2).c_str()) - atoi(newelement->Arrival.substr(0, 2).c_str());
	newelement->Cost = 50 * days * prior(type_search(newelement->Number, Free, "Type_room")) * prior(type_search(newelement->Number, Free, "Seats")) * prior(type_search(newelement->Number, Free, "Repair")) * prior(type_search(newelement->Number, Free, "Sea_views"));
	cout << "��������� ����������: " << newelement->Cost << "$" << endl; 
	while (Free->Number != newelement->Number)//���� ������ �����
		Free = Free->Next;
	Free->Settled++;
	while (All->Number != Free->Number)
		All = All->Next;
	All->Settled++;
	if (Free->Settled == prior(type_search(newelement->Number, Free, "Seats")))//����� ����������� �� ������ ��������� ������� � ������ �������
	{
		tRoom *element = select_one(Free, newelement->Number);
		Free =  Delete(Free, newelement->Number);
		element->Prev = Busy;
		element->Next = NULL;
		if (Busy == NULL)
			Busy = element;
		else
		{
			Busy->Next = element;
			Busy = Busy->Next;
		}
	}
	while(Free->Next != NULL)
		Free = Free->Next;
	while(All->Next != NULL)
		All = All->Next;
/*	Guest_temp->Prev = Guest;
	Guest_temp->Next = NULL;
	if (Guest == NULL)
		Guest = Guest_temp;
	else
	{
		Guest->Next = Guest_temp;
		Guest = Guest_temp;
	}*/
}

tRoom* select_one(tRoom* Room, tNumber Number)
{
    tRoom *old_temp = new tRoom;
	old_temp = Room;
    tRoom *Room_temp = new tRoom;
	while( old_temp != NULL )
		if (old_temp->Number == Number)
		{
			Room_temp->Number = old_temp->Number;
			Room_temp->Seats = old_temp->Seats;
			Room_temp->Type_room = old_temp->Type_room;
			Room_temp->Floor = old_temp->Floor;
			Room_temp->Repair = old_temp->Repair;
			Room_temp->Sea_views = old_temp->Sea_views;
			Room_temp->Settled = Room_temp->Settled;
			Room_temp->Next = Room_temp->Prev = NULL;
			return Room_temp;
		}
		else
			old_temp = old_temp->Prev;
	return NULL;
}	

tType_room type_search(tNumber Number, tRoom *Room, string find)
{
	tRoom *Room_temp = new tRoom;
	while (Room->Next != NULL)
		Room = Room->Next;
	Room_temp = Room;
	while (Room_temp != NULL)
		if (Room_temp->Number == Number)
		{
			if (find == "Type_room")
				return Room_temp->Type_room;
			if (find == "Seats")
				return Room_temp->Seats;
			if (find == "Repair")
				return Room_temp->Repair;
			if (find == "Sea_views")
				return Room_temp->Sea_views;
		}
		else
			Room_temp = Room_temp->Prev;
	return NULL;
}
/////////////////////////////////////////////////////////////////////////////////����� ������ � ������������� ������������
void list_of_numbers()//������ �������
{
	system("cls");
	while (true)
	{
		printf("1 - ����������� ���� �������\n2 - ����� ������ �� ������ ���������\n3 - �������������� ������ �������\n4 - ���������� ������� �� ������ ���������\n5 - ������� � ���������� ����\n0 - �����\n������� ����� ��������: ");
		int choice = 0;
		scanf_s("%d", &choice);
		system("cls");
		switch (choice)
		{
		case 1:
			bypass(All);
			break;
		case 2:
			printf("�������� ������ ��� ������\n1 - ���\n2 - ���������\n3 - �������\n4 - �����������������\n5 - �����\n0 - �����\n������� �����: ");
			scanf_s("%d", &choice);
			switch (choice)
			{
			case 1:
				number_search(All);
				break;
			case 2:
				number_search(Free);
				break;
			case 3:
				number_search(Busy);
				break;
			case 4:
				number_search(Reserved);
				break;
			case 5:
				break;
			case 0:
				Save_All();
				exit(0);
			}
			break;
		case 3:
			editing();
			break;
		case 4:
			if (check_for_null(All))
				All = Sort(All);
			bypass(All);
			break;
		case 5:
			return;
		case 0:
			Save_All();
			exit(0);
		default:
			system("cls");
			printf("������ �����. ������� ����� �� 0 �� 5\n");
			break;
		}
	}	
}

tRoom* Add_Room(tRoom *Room)//����������
{
	tRoom *newelement = new tRoom;
	int choice = 0;
	system("cls");
	printf("������� �����: ");
	scanf_s("%d", &newelement->Number);
	printf("�������� ��� ������:\n1 - ������� �����\n2 - ��������\n3 - ����\n4 - ����������� �����\n������� �����: ");
	scanf_s("%d", &choice);
    switch (choice)
		{
		case 1:
			newelement->Type_room = "������� �����";
			break;
		case 2:
			newelement->Type_room = "��������";
			break;
		case 3:
			newelement->Type_room = "����";
			break;
		case 4:
			newelement->Type_room = "����������� �����";
			break;
		default:
			printf("������ �����. ������� ����� �� 1 �� 4");
			break;
		}
	printf("�������� ���������� ���� � ������:\n1 - �����������\n2 - ����������\n3 - �����������\n4 - ��������������\n������� �����: ");
	scanf_s("%d", &choice);
    switch (choice)
		{
		case 1:
			newelement->Seats = "�����������";
			break;
		case 2:
			newelement->Seats = "����������";
			break;
		case 3:
			newelement->Seats = "�����������";
			break;
		case 4:
			newelement->Seats = "��������������";
			break;
		default:
			printf("������ �����. ������� ����� �� 1 �� 4");
			break;
		}
	printf("������� ����: ");
	scanf_s("%d", &newelement->Floor);
	printf("�������� ��������� �������:\n1 - ��������������\n2 - �������������\n������� �����: ");
	scanf_s("%d", &choice);
    switch (choice)
		{
		case 1:
			newelement->Repair = "��������������";
			break;
		case 2:
			newelement->Repair = "�������������";
			break;
		default:
			printf("������ �����. ������� ����� �� 1 �� 2");
			break;
		}
	printf("��� �� ����:\n1 - ����\n2 - ���\n������� �����: ");
	scanf_s("%d", &choice);
    switch (choice)
		{
		case 1:
			newelement->Sea_views = "����";
			break;
		case 2:
			newelement->Sea_views = "���";
			break;
		default:
			printf("������ �����. ������� ����� �� 1 �� 2");
			break;
		}
	newelement->Prev = Room;
	newelement->Next = NULL;
	temp_room = Room;
	while(temp_room->Next)
		temp_room = temp_room->Next;
	if (Room)
	{
		temp_room->Next = newelement;
		temp_room->Next->Prev = temp_room;
		temp_room = temp_room->Next;
	}
	else
		temp_room = Room = newelement;
	return Room;
}//���������� ������

tRoom* Delete(tRoom *Room, int element)
{
	if (Room == NULL)
	{
		printf("������ ������-�� ����:(\n");
		return NULL;
	}
	else
	{
		tRoom *Room_temp = new tRoom;
		Room_temp = Room;
		while(Room_temp != NULL)//���� ������ �������
			if(Room_temp->Number == element)
				break;
			else
				Room_temp = Room_temp->Prev;
		if (Room_temp == NULL)
			return Room;
		if(Room_temp->Prev == NULL)//���� ��������� ������ �������, ��
		{
			if (Room_temp->Next == NULL) 		//���� ���� ������� ������������
				Room = Room_temp = NULL;
			else 				//���� �� ������, �� �� ������������
			{
				Room_temp->Next->Prev = NULL;
				Room = Room_temp->Next;
			}
			delete Room_temp;
			return Room;
		}
		if (Room_temp->Next == NULL)		//���� ������� ��������� �������, ��
		{
			Room_temp->Prev->Next = NULL;	//���������� ������� ��������� �� NULL
			Room_temp = Room_temp->Prev;		//��������� �� ��������� ������� //��������� �� �������������
			Room = Room_temp;
			return Room;
		}		
		else //���� ������� ��������� � ������ ������
		{
			Room_temp->Prev->Next = Room_temp->Next; //���������� ������� ��������� �� ���������
			Room_temp->Next->Prev = Room_temp->Prev; //��������� ��������� �� ����������
			Room_temp = Room_temp->Prev;
			Room = Room_temp->Next;
			return Room;
		}
	}	
}

void Output(tRoom *Room_temp)//����� ���� � ������
{
	printf("------------------------------------------\n");
	printf("�����: %d\n����: %d",Room_temp->Number, Room_temp->Floor);
	cout<<"\n��� ������: "<<Room_temp->Type_room;
	cout<<", "<<Room_temp->Seats;
	cout<<"\n��������� �������: "<<Room_temp->Repair;
	cout<<"\n��� �� ����: "<<Room_temp->Sea_views;
	printf("\n------------------------------------------\n");
}

void bypass(tRoom *Room)//�����
{
	tRoom *Room_temp = Room;
	system("cls");
	if (Room_temp == NULL)
		printf("������ ������-�� ����:(\n");
	else
	{
		while (Room_temp ->Next != NULL)
			Room_temp = Room_temp->Next;
		while (Room_temp != NULL)
		{
			Output(Room_temp);
			Room_temp = Room_temp->Prev;
		}
	}
	system("pause");
	system("cls");
}

void number_search(tRoom *Room_temp)
{
	int choice = 0;
	int number = 0;
	printf("�������� ����\n1 - �����\n2 - ���������� ����\n3 - ���\n4 - ����\n5 - ������\n6 - ��� �� ����\n������� �����: ");
	scanf_s("%d", &choice);
	switch (choice)
	{
	case 1://����� �� ������
		printf("������� ������� �����: ");
		scanf_s("%d",&number);
		if (check_for_null(Room_temp))
			number_search1(Room_temp, 1,to_string(number));
		break;
	case 2://����� �� ���������� ����
		printf("������� ���� � ������:\n1 - ����\n2 - ���\n3 - ���\n4 - ������\n������� �����: ");
		scanf_s("%d", &choice);
		if (check_for_null(Room_temp))
			switch (choice)
			{
			case 1:
				number_search1(Room_temp, 2, "�����������");
				break;
			case 2:
				number_search1(Room_temp, 2, "����������");
				break;
			case 3:
				number_search1(Room_temp, 2, "�����������");
				break;
			case 4:
				number_search1(Room_temp, 2, "��������������");
				break;
			default:
				printf("������ �����. ������� ����� �� 1 �� 4");
				break;
			}
		break;
	case 3://����� �� ����
		printf("����� ��� ������:\n1 - ������� �����\n2 - ��������\n3 - ����\n4 - ����������� �����\n������� �����: ");
		scanf_s("%d", &choice);
		if (check_for_null(Room_temp))
			switch (choice)
			{
			case 1:
				number_search1(Room_temp, 3, "������� �����");
				break;
			case 2:
				number_search1(Room_temp, 3, "��������");
				break;
			case 3:
				number_search1(Room_temp, 3, "����");
				break;
			case 4:
				number_search1(Room_temp, 3, "����������� �����");
				break;
			default:
				printf("������ �����. ������� ����� �� 1 �� 4");
				break;
			}
		break;
	case 4://����� �� �����
		printf("������� ����: ");
		scanf_s("%d",&number);
		if (check_for_null(Room_temp))
			number_search1(Room_temp, 4, to_string(number));
		break;
	case 5://����� �� �������
		printf("�������� ��������� �������:\n1 - ��������������\n2 - �������������\n������� �����: ");
		scanf_s("%d", &choice);
		if (check_for_null(Room_temp))
			switch (choice)
			{
			case 1:
				number_search1(Room_temp, 5, "��������������");
				break;
			case 2:
				number_search1(Room_temp, 5, "�������������");
				break;
			default:
				printf("������ �����. ������� ����� �� 1 �� 2");
				break;
			}
		break;
	case 6:
		printf("��� �� ����:\n1 - ����\n2 - ���\n������� �����: ");
		scanf_s("%d", &choice);
		if (check_for_null(Room_temp))
			switch (choice)
			{
			case 1:
				number_search1(Room_temp, 6, "����");
				break;
			case 2:
				number_search1(Room_temp, 6, "���");
				break;
			default:
				printf("������ �����. ������� ����� �� 1 �� 2");
				break;
			}
		break;
	}
}

void number_search1(tRoom *Room_temp, int fiel, string element)
{
	string find;
	bool found = false;
	while (Room_temp != NULL)
	{
		switch (fiel)
		{
		case 1:
			find = to_string(Room_temp->Number);
			break;
		case 2:
			find = Room_temp->Seats;
			break;
		case 3:
			find = Room_temp->Type_room;
			break;
		case 4:
			find = to_string(Room_temp->Floor);
			break;
		case 5:
			find = Room_temp->Repair;
			break;
		case 6:
			find = Room_temp->Sea_views;
			break;
		}
		if (find == element)
		{
			Output(Room_temp);
			found = true;
		}
		Room_temp = Room_temp->Prev;
	}
	if (!found)
	{
		printf("����� �� ��� �����������\n");
		system("pause");
	}
}

bool check_for_null(tRoom *Room_temp)
{
	if(Room_temp)
		return true;
	else
	{
		system("cls");
		printf("������ ������� ����\n");
		system("pause");
		return false;
	}
}

void editing()
{
	int choice = 0;
	int number = 0;
	bool found = false;
	tRoom *element = new tRoom;
	printf("1 - �������� �����\n2 - ������� �����\n3 - ������������� �����\n������� �����: ");
	scanf_s("%d",&choice);
	switch (choice)
	{
	case 1://����������
		All = Add_Room(All);
		element = select_one(All, All->Number);
		element->Prev = Free;
		element->Next = NULL;
		if (Free == NULL)
			Free = element;
		else
		{
			Free->Next = element;
			Free = Free->Next;
		}
		break;
	case 2://��������
		printf("������� ����� �������: ");
		scanf_s("%d", &number);
		if (select_one(Free, number))
		{
			Free = Delete(Free, number);
			All = Delete(All, number);
			found = true;
		}
		if (select_one(Busy, number))
		{
			Busy = Delete(Busy, number);
			All = Delete(All, number);
			found = true;
		}
		if (select_one(Reserved, number))
		{
			Reserved = Delete(Reserved, number);
			All = Delete(All, number);
			found = true;
		}
		if (found)
			cout << "������� �" << number << " �������" << endl; 
		else
			cout << "������� �" << number << " �� �������";
		break;
	case 3:
		printf("������� ����� �������: ");
		scanf_s("%d", &number);
		if (select_one(Free, number))
		{
			Free = edition1(Free, number);
			element = select_one(Free, number);
			found = true;
		}
		if (select_one(Busy, number))
		{
			Busy = edition1(Busy, number);
			element = select_one(Busy, number);
			found = true;
		}
		if (select_one(Reserved, number))
		{
			Reserved = edition1(Reserved, number);
			element = select_one(Reserved, number);
			found = true;
		}
		if (found)
		{
			All = Delete(All, number);
			while (All ->Next != NULL)
				All = All->Next;
			element->Prev = All;
			element->Next = NULL;
			if (All == NULL)
			All = element;
			else
			{
				All->Next = element;
				All = All->Next;
			}
			cout << "������� �" << number << " ���������������" << endl; 
		}
		else
			cout << "������� �" << number << " �� �������";
		break;
	}
}

tRoom* edition1(tRoom *Room, int number)
{
	 	int choice = 0;
		while(Room != NULL)//���� ������ �������
			if(Room->Number == number)
				break;
			else
				Room = Room->Prev;
		printf("�������� ���� ��� ��������������\n1 - �����\n2 - ���������� ����\n3 - ���\n4 - ����\n5 - ������\n6 - ��� �� ����\n7 - �����\n0 - �����\n������� �����: ");
		fflush(stdin);
		scanf_s("%d", &choice);
		switch (choice)
		{
			case 1:
				printf("������� �����: ");
				scanf_s("%d",&number);
				if (check_for_null(Room))
						Room->Number = number;
				break;
			case 2:
				printf("���������� ���� � ������:\n1 - ����\n2 - ���\n3 - ���\n4 - ������\n������� �����: ");
				scanf_s("%d", &choice);
				if (check_for_null(Room))
					switch (choice)
					{
					case 1:
						Room->Seats = "�����������";
						break;
					case 2:
						Room->Seats = "����������";
						break;
					case 3:
						Room->Seats = "�����������";
						break;
					case 4:
						Room->Seats = "��������������";
						break;
					default:
						printf("������ �����. ������� ����� �� 1 �� 4");
						break;
					}
				break;
			case 3:
				printf("��� ������:\n1 - ������� �����\n2 - ��������\n3 - ����\n4 - ����������� �����\n������� �����: ");
				scanf_s("%d", &choice);
				if (check_for_null(Room))
					switch (choice)
					{
					case 1:
						Room->Type_room = "������� �����";
						break;
					case 2:
						Room->Type_room = "��������";
						break;
					case 3:
						Room->Type_room = "����";
						break;
					case 4:
						Room->Type_room = "����������� �����";
						break;
					default:
						printf("������ �����. ������� ����� �� 1 �� 4");
						break;
					}
				break;
			case 4:
				printf("������� ����: ");
				scanf_s("%d",&number);
				if (check_for_null(Room))
					Room->Floor = number;
				break;
			case 5:
				printf("�������� ��������� �������:\n1 - ��������������\n2 - �������������\n������� �����: ");
				scanf_s("%d", &choice);
				if (check_for_null(Room))
					switch (choice)
					{
					case 1:
						Room->Repair = "��������������";
						break;
					case 2:
						Room->Repair = "�������������";
						break;
					default:
						printf("������ �����. ������� ����� �� 1 �� 2");
						break;
					}
				break;
			case 6:
				printf("��� �� ����:\n1 - ����\n2 - ���\n������� �����: ");
				scanf_s("%d", &choice);
				if (check_for_null(Room))
					switch (choice)
					{
					case 1:
						Room->Sea_views = "����";
						break;
					case 2:
						Room->Sea_views = "���";
						break;
					default:
						printf("������ �����. ������� ����� �� 1 �� 2");
						break;
					}
				break;
			case 7:
				return Room;
			case 0:
				Save_All();
				exit(0);
		}
return Room;
}

tRoom* Sort(tRoom *Room_temp) 
{
	tRoom *tmp;
	tRoom *a;
    tRoom t;
    int flag = 1;
 	int choice = 0;
	printf("�������� ���� ��� ����������\n1 - �����\n2 - ���������� ����\n3 - ���\n4 - ����\n5 - ������\n6 - ��� �� ����\n������� �����: ");
	scanf_s("%d", &choice);
    while(flag == 1)
	{
        tmp = Room_temp;
		a = tmp->Prev;
        flag = 0;
		while(a)
		{
			bool w = false;
			switch (choice)
			{
				case 1 ://�� ������ 
					if(tmp->Number > a->Number)
						w = true;
					break;
				case 2 ://�� ���������� ����
					if(prior(tmp->Seats) > prior(a ->Seats)) 
						w = true;
					break;
				case 3 ://�� ����
					if(prior(tmp->Type_room) > prior(a ->Type_room)) 
						w = true;
					break;
				case 4 ://�� �����
					if (tmp->Floor > a->Floor)
						w = true;
					break;
				case 5 ://�� �������
					if(prior(tmp->Repair) > prior(a ->Repair)) 
						w = true;
					break;
				case 6 ://�� ���� �� ����
					if(prior(tmp->Sea_views) > prior(a ->Sea_views)) 
						w = true;
					break;
			}
			 if (w == true)
			 {
				t.Number = tmp->Number;
				t.Seats = tmp->Seats;
				t.Type_room = tmp->Type_room;
				t.Floor = tmp->Floor;
				t.Repair = tmp->Repair;
				t.Sea_views = tmp->Sea_views;
				t.Settled = tmp->Settled;

				tmp->Number = a->Number;
				tmp->Seats = a->Seats;
				tmp->Type_room = a->Type_room;
				tmp->Floor = a->Floor;
				tmp->Repair = a->Repair;
				tmp->Sea_views = a->Sea_views;
				tmp->Settled = a->Settled;

				a->Number = t.Number;
				a->Seats = t.Seats;
				a->Type_room = t.Type_room;
				a->Floor = t.Floor;
				a->Repair = t.Repair;
				a->Sea_views = t.Sea_views;
				a->Settled = t.Settled;
                flag = 1;
			 }
			 tmp = tmp->Prev;
			 a = a->Prev;
		}
	}
	return tmp;
}

int prior(string element)
{
	if (element == "�����������" || element == "������� �����" || element == "�������������" || element == "���")
		return 1;
	if (element == "����������" || element == "��������" || element == "��������������" || element == "����")
		return 2;
	if (element == "�����������" || element == "����")
		return 3;
	if (element == "��������������" || element == "����������� �����")
		return 4;
	return NULL;
}
