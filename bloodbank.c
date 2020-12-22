//Header Files
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <Windows.h>


//methods
void menu();
void details_donor();
void register_donor();
void getdonor_bygroup();
void getdonor_bycity();
void getdonor_byid();
void calculate_amt(int n);
void getplasma_donor();
void calculate_amt_plasma(int n);
int max_Donor_id();
int Donor_id();
void feedback();
void gotoxy(int x, int y);
void SetColor(int ForgC);


//structure that contians the deatils of the donor.
struct Blood_Donor
{
char Name[25];
char Blood_Group[4];
char Address[50];
char City[20];
char Phone_No[11];
char Email[40];
char Plasma[5];
int ID,Age;
};


//Global variables initialization
struct Blood_Donor b; //Declaring the Structure
FILE *fp;
int size;
COORD coordinate = {0,0};


//main method
int main()
{
	SetColor(0);
	menu();
	return 0;
}

//menu- To display different operations.
void menu()
{
	system("color 4e");
	SetColor(0);
	system("cls");
	gotoxy(30,8);printf("\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2");
	gotoxy(40,8);printf("\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2");
	gotoxy(50,8);printf("\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2");
	gotoxy(60,8);printf("\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2");
	gotoxy(70,8);printf("\xB2\xB2\xB2\xB2\xB2");
	Sleep(100);
	gotoxy(30,9);printf("\xB2");
	gotoxy(74,9);printf("\xB2");
	Sleep(50);
	gotoxy(30,10);printf("\xB2");
	gotoxy(33,10);printf("WELCOME TO BLOOD BANK MANAGEMENT SYSTEM");
	gotoxy(74,10);printf("\xB2");
	Sleep(100);
	gotoxy(30,11);printf("\xB2");
	gotoxy(74,11);printf("\xB2");
	Sleep(100);
	gotoxy(30,12);printf("\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2");
	gotoxy(40,12);printf("\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2");
	gotoxy(50,12);printf("\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2");
	gotoxy(60,12);printf("\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2");
	gotoxy(70,12);printf("\xB2\xB2\xB2\xB2\xB2");
	//printf("\n\n\n\n\n\n\n\n\n\n\n");
	//printf("\t\t\t\t ************************************************\n\n");
	//printf("\t\t\t\t|   *WELCOME TO BLOOD BANK MANAGEMENT SYSTEM*    |\n\n");
	//printf("\t\t\t\t ************************************************\n\n");
	Sleep(2000);
	system("cls");
	int option;
	while(1)
	{
		system("color 8e");
		SetColor(0);
		printf("\n\n\n\n\n\n\n");
		printf("\t\t\t\t -----------------------------------------------\n\n");
		Sleep(50);
		printf("\t\t\t\t|            *BLOOD DONOR DATABASE*             |\n\n");
		Sleep(100);
		printf("\t\t\t\t -----------------------------------------------\n\n");
		Sleep(100);
		printf("\t\t\t\t|\t1.Register as a new donor.   \t\t|\n");
		Sleep(100);
		printf("\t\t\t\t|\t2.Search donor using Blood Group.    \t|\n");
		Sleep(100);
		printf("\t\t\t\t|\t3.Search donor using Donor Id.   \t|\n");
		Sleep(100);
		printf("\t\t\t\t|\t4.Search donor using City.   \t\t|\n");
		Sleep(100);
		printf("\t\t\t\t|\t5.search for Plasma Donation.   \t|\n");
		Sleep(100);
		printf("\t\t\t\t|\t6.Check details of the donors using ID. |\n");
		Sleep(100);
		printf("\t\t\t\t|\t7.Feedback. \t\t\t\t|\n");
		Sleep(100);
		printf("\t\t\t\t|\t8.Exit. \t\t\t\t|\n");
		Sleep(100);
		printf("\t\t\t\t ------------------------------------------------\n\n");
		Sleep(100);
		printf("\t\t\t\t\t->Enter your Choice: - ");
		scanf("%d",&option);
		system("cls");
		switch(option)
		{
			case 1 :register_donor();
					break;

			case 2 :getdonor_bygroup();
					break;

			case 3 :getdonor_byid();
					break;

			case 4 :getdonor_bycity();
					break;
					
			case 5 :getplasma_donor();
					break;
					
			case 6 :details_donor();
					break;

			case 7 :feedback();
					break;

			case 8 :system("color 0e");
					exit(1);

			default: printf("\n\n\n\n\t\t\t\t\tENTER A VALID OPTION.");
					
		}
	}
}


//To register as a new donor.
void register_donor()
{
	system("color 8e");
	SetColor(0);
	char a = 'Y';
	fp=fopen("blood_database.txt","a");    //Opening a Binary File
	if(fp==NULL)
	{
		puts("FILE DOES NOT EXIST");
		exit(1);
	}
	fseek(fp,0,SEEK_END);       //Putting the Pointer at the end of the File
	if( a == 'Y' || a == 'y')
	{
		printf("\n\n\n\n");
		printf("\t\t\t\t\tEnter Name :- ");
		fflush(stdin);
		gets(b.Name);
		fflush(stdin);
		printf("\n\t\t\t\t\tEnter Your Age :- ");
		scanf("%d",&b.Age);
		if(b.Age <18 || b.Age >65)
		{
			printf("\n\t\t\t\t\tYOU ARE NOT ELIGIBLE FOR DONATING BLOOD !!");
			int x;
			printf("\n\n\t\t\t\t\tEnter [1] to go back to menu");
			scanf("%d",&x);
			while(x != 1)
			{
				printf("\n\t\t\t\t\tEnter [1] to go back to menu");
				scanf("%d",&x);
			}
			if(x == 1)
			{
				system("cls");
				return;
			}
		}
		b.ID = Donor_id();
		fflush(stdin);
		printf("\n\t\t\t\t\tEnter address :- ");
		gets(b.Address);
		fflush(stdin);
		printf("\n\t\t\t\t\tEnter city :- ");
		gets(b.City);
		int n= strlen(b.City);
		for(int i=0;i<n;i++)
		{
			if(isalpha(b.City[i]))
			{
				b.City[i] = tolower(b.City[i]);
			}
		}
		fflush(stdin);
		printf("\n\t\t\t\t\tEnter Blood group :- ");
		gets(b.Blood_Group);
		n= strlen(b.Blood_Group);
		for(int i=0;i<n;i++)
		{
			if(isalpha(b.Blood_Group[i]))
			{
				b.Blood_Group[i] = tolower(b.Blood_Group[i]);
			}
		}
		while(1)
		{
			if(strcmp(b.Blood_Group,"a+") == 0 || strcmp(b.Blood_Group,"a-") == 0 || strcmp(b.Blood_Group,"b+") == 0 || strcmp(b.Blood_Group,"b-") == 0 || strcmp(b.Blood_Group,"ab+") == 0 || strcmp(b.Blood_Group,"ab-") == 0 || strcmp(b.Blood_Group,"o+") == 0 || strcmp(b.Blood_Group,"o-") == 0 )
			{
				break;
			}
			else
			{
				printf("\n\t\t\t\t\tEnter a valid blood Group :-");
				gets(b.Blood_Group);
				n= strlen(b.Blood_Group);
				for(int i=0;i<n;i++)
				{
					if(isalpha(b.Blood_Group[i]))
					{
						b.Blood_Group[i] = tolower(b.Blood_Group[i]);
					}
				}
			}
		}
		fflush(stdin);
		printf("\n\t\t\t\t\tEnter your 10 Digit Mobile Number :- ");
		gets(b.Phone_No);
		while(strlen(b.Phone_No) != 10)
		{
			printf("\n\t\t\t\t\tEnter a valid phone number :-");
			gets(b.Phone_No);
		}	
		fflush(stdin);
		printf("\n\t\t\t\t\tEnter your Email id :-");
		scanf("%s",b.Email);
		fflush(stdin);
		printf("\n\t\t\t\t\tIf you have recovered from the virus.\n\t\t\t\t\tTell us weather you are willing to donate plasma?(yes/no) : -");
		scanf("%s",b.Plasma);
		for(int i=0;i<n;i++)
		{
			if(isalpha(b.Plasma[i]))
			{
				b.Plasma[i] = tolower(b.Plasma[i]);
			}
		}
		printf("\n\n\t\t\t\t\tTHANKS FOR THE VALUABLE INFORMATION THAT IS SHARED WITH US.\n");
		printf("\n\t\t\t\t\tYour Donor ID is : - %d\n",b.ID);
		fwrite(&b,sizeof(struct Blood_Donor),1,fp);
		fclose(fp);									//Closing the File
		printf("\n\t\t\t\t\tDo you want to add another data.    Enter(Y / N) :-");
		fflush(stdin);
		scanf("%c",&a);
		if( a == 'Y' || a == 'y')
		{
			system("cls");
			register_donor();
		}
		else
		{
			int x;
			printf("\n\n\t\t\t\t\tEnter [1] to go back to menu :-");
			fflush(stdin);
			scanf("%d",&x);
			while(x != 1)
			{
				printf("\n\t\t\t\t\tEnter [1] to go back to menu :-");
				fflush(stdin);
				scanf("%d",&x);
			}
			if(x == 1)
			{
				system("cls");
				return;
			}
		}
	}		 
}


//To search for donor using blood group.
void getdonor_bygroup()
{
	SetColor(0);
	system("color 4e");
	int i=0,n;
	char blood_group[10];
	char a='y';
	fp=fopen("blood_database.txt","r");
	if(fp==NULL)
	{
		puts("CONNOT OPEN THE FILE.");
		exit(1);
	}
	fflush(stdin);
	printf("\n\n\n\n\n");
	printf("\n\t\t\t\t\tEnter the Blood Group : -");
	gets(blood_group);
	n= strlen(blood_group);
	for(int i=0;i<n;i++)
	{
		if(isalpha(blood_group[i]))
		{
			blood_group[i] = tolower(blood_group[i]);
		}
	}
	while(1)
	{
		if(strcmp(blood_group,"a+") == 0 || strcmp(blood_group,"a-") == 0 || strcmp(blood_group,"b+") == 0 || strcmp(blood_group,"b-") == 0 || strcmp(blood_group,"ab+") == 0 || strcmp(blood_group,"ab-") == 0 || strcmp(blood_group,"o+") == 0 || strcmp(blood_group,"o-") == 0 )
		{
			break;
		}
		else
		{
			printf("\n\t\t\t\t\tEnter a valid blood Group :-");
			gets(blood_group);
			n= strlen(blood_group);
			for(int i=0;i<n;i++)
			{
				if(isalpha(blood_group[i]))
				{
					blood_group[i] = tolower(blood_group[i]);
				}
			}
		}
	}
	rewind(fp);

	while(fread(&b,sizeof(struct Blood_Donor),1,fp)==1)
	{
		if(a=='Y'||a=='y')
		{
			if(strcmp(b.Blood_Group,blood_group)==0)      //checking for the matching Bloodgroup in the Database.
			{
				printf("\n\t\t\t\t\tDETAILS OF THE DONOR WITH BLOOD GROUP '%s'",blood_group);
				printf("\n\t\t\t\t\tName: %s",b.Name);
				printf("\n\t\t\t\t\tDonor Id: %d",b.ID);
				printf("\n\t\t\t\t\tAge: %d",b.Age);
				printf("\n\t\t\t\t\tAddress of the donor: %s",b.Address);
				printf("\n\t\t\t\t\tCity: %s ",b.City);
				printf("\n\t\t\t\t\tPhone No:- %s",b.Phone_No);
				printf("\n\t\t\t\t\tEmail: %s",b.Email);
				printf("\n\t\t\t\t\tBlood Group: %s",b.Blood_Group);
				printf("\n\t\t\t\t\tENTER Y TO GET MORE BLOOD BAGS!! :-");
				fflush(stdin);
				scanf("%c",&a);
				i++;
			}	
		}
	}
	
	if(a=='n'||a=='N')	
	{
		fclose(fp);
	}
	if(a=='y'||a=='Y')
	{
		printf("\n\t\t\t\t\tSORRY GUYS NO MORE RECORDS REGARDING YOUR BLOOD GROUP.!!!\n");
		fclose(fp);
		if(strcmp(blood_group,"a+") == 0 )
		{
			printf("\n\t\t\t\tWE SUGGEST YOU TO CHECK FOLLOWING BLOOD GROUPS IN REPLACEMENT FOR 'A+' BLOOD GROUP\n");
			printf("\n\t\t\t\t\t[1]'A-'\t[2]'O+'\t[3]'O-'");
		}
		if(strcmp(blood_group,"a-") == 0 )
		{
			printf("\n\t\t\t\tWE SUGGEST YOU TO CHECK FOLLOWING BLOOD GROUPS IN REPLACEMENT FOR 'A-' BLOOD GROUP\n");
			printf("\n\t\t\t\t\t[1]'O-'");
		}
		if(strcmp(blood_group,"b+") == 0 )
		{
			printf("\n\t\t\t\tWE SUGGEST YOU TO CHECK FOLLOWING BLOOD GROUPS IN REPLACEMENT FOR 'B+' BLOOD GROUP\n");
			printf("\n\t\t\t\t\t[1]'B-'\t[2]'O+'\t[3]'O-'");
		}
		if(strcmp(blood_group,"b-") == 0 )
		{
			printf("\n\t\t\t\tWE SUGGEST YOU TO CHECK FOLLOWING BLOOD GROUPS IN REPLACEMENT FOR 'B-' BLOOD GROUP\n");
			printf("\n\t\t\t\t\t[1]'O-'");
		}
		if(strcmp(blood_group,"ab+") == 0 )
		{
			printf("\n\t\t\t\tWE SUGGEST YOU TO CHECK FOLLOWING BLOOD GROUPS IN REPLACEMENT FOR 'AB+' BLOOD GROUP\n");
			printf("\n\t\t\t\t\t[1]'A-'\t[2]'A+'\t[3]'O+'\t[4]'O-'\t[5]'B+'\t[6]'B-'\t[7]'AB-'");
		}
		if(strcmp(blood_group,"ab-") == 0 )
		{
			printf("\n\t\t\t\tWE SUGGEST YOU TO CHECK FOLLOWING BLOOD GROUPS IN REPLACEMENT FOR 'AB-' BLOOD GROUP\n");
			printf("\n\t\t\t\t\t[1]'A-'\t[2]'O-'\t[3]'B-'");
		}
		if(strcmp(blood_group,"o+") == 0 )
		{
			printf("\n\t\t\t\tWE SUGGEST YOU TO CHECK FOLLOWING BLOOD GROUPS IN REPLACEMENT FOR 'O+' BLOOD GROUP\n");
			printf("\n\t\t\t\t\t[1]'O-'");
		}
		if(strcmp(blood_group,"o-") == 0 )
		{}
	}
	if(i>=1)
	{
		calculate_amt(i);
	}
	int x;
	printf("\n\n\t\t\t\t\tEnter [1] to go back to menu : -");
	fflush(stdin);
	scanf("%d",&x);
	while(x != 1)
	{
		printf("\n\t\t\t\t\tEnter [1] to go back to menu : -");
		fflush(stdin);
		scanf("%d",&x);
	}
	if(x == 1)
	{
		system("cls");
		return;
	}
}


//To search for donor using donor's ID.
void getdonor_byid()
{
	SetColor(0);
	system("color 4e");
	int i=0;
	int id;
	char a='y';
	fp=fopen("blood_database.txt","r");
	if(fp==NULL)
	{
		printf("Cannot Open File");
		exit(1);
	}
	fflush(stdin);
	printf("\n\n\n\n");
	printf("\n\t\t\t\t\tEnter the Donor Id :-");
	scanf("%d",&id);
	int max_id = max_Donor_id();
	while(id <= 1000 || id >=max_id)
	{
		printf("\n\n\t\t\t\t\tSORRY INVALID INPUT\n");
		printf("\n\t\t\t\t\tEnter correct Donor Id :-");
		scanf("%d",&id);
		//system("cls");
	}
	rewind(fp);

	while(fread(&b,sizeof(struct Blood_Donor),1,fp)==1)
	{
		if(a=='Y'||a=='y')
		{
			if(b.ID==id)      //checking for the mathching donor's ID in the Database.
			{
				printf("\n\t\t\t\t\tDETAILS OF THE DONOR WITH ID '%d'",b.ID);
				printf("\n\t\t\t\t\tName: %s",b.Name);
				printf("\n\t\t\t\t\tDonor Id: %d",b.ID);
				printf("\n\t\t\t\t\tAge: %d",b.Age);
				printf("\n\t\t\t\t\tAddress of the donor: %s",b.Address);
				printf("\n\t\t\t\t\tCity: %s ",b.City);
				printf("\n\t\t\t\t\tPhone No:- %s",b.Phone_No);
				printf("\n\t\t\t\t\tEmail: %s",b.Email);
				printf("\n\t\t\t\t\tBlood Group: %s\n",b.Blood_Group);
				i++;
			}
		}
	}
	if(i>=1)
	{
		calculate_amt(i);
	}
	int x;
	printf("\n\n\t\t\t\t\tEnter [1] to go back to menu : -");
	fflush(stdin);
	scanf("%d",&x);
	while(x != 1)
	{
		printf("\n\t\t\t\t\tEnter [1] to go back to menu : -");
		fflush(stdin);
		scanf("%d",&x);
	}
	if(x == 1)
	{
		system("cls");
		return;
	}
}


//To search for blood donor using city.
void getdonor_bycity()
{
	SetColor(0);
	system("color 4e");
	int i;
	i=0;
	char city[20];
	char a='y';
	fp=fopen("blood_database.txt","r");
	if(fp==NULL)
	{
		puts("Cannot Open File");
		exit(1);
	}
	fflush(stdin);
	printf("\n\n\n\n\n\n\n\n\n");
	printf("\n\t\t\t\t\tEnter the City : -");
	scanf("%s",city);
	int n= strlen(city);
	for(int i=0;i<n;i++)
	{
		if(isalpha(city[i]))
		{
			city[i] = tolower(city[i]);
		}
	}
	rewind(fp);

	while(fread(&b,sizeof(struct Blood_Donor),1,fp)==1)
	{
		if(a=='Y'||a=='y')
		{
			if((strcmp(b.City,city))==0)      //checking the matching city in the database.
			{
				printf("\n\t\t\t\t\tDETAILS OF THE BLOOD DONOR IN THE CITY '%s'",city);
				printf("\n\t\t\t\t\tName: %s",b.Name);
				printf("\n\t\t\t\t\tDonor Id: %d",b.ID);
				printf("\n\t\t\t\t\tAge: %d",b.Age);
				printf("\n\t\t\t\t\tAddress of the donor: %s",b.Address);
				printf("\n\t\t\t\t\tCity: %s ",b.City);
				printf("\n\t\t\t\t\tPhone No:- %s",b.Phone_No);
				printf("\n\t\t\t\t\tEmail: %s",b.Email);
				printf("\n\t\t\t\t\tBlood Group: %s\n",b.Blood_Group);
				printf("\n\t\t\t\t\tENTER Y TO GET MORE BLOOD DONORS!!");
				fflush(stdin);
				scanf("%c",&a);
				i++;
			}
		}
	}
	if(i == 0)
	{
		printf("\n\t\t\t\t\tSORRY, WE DONT HAVE ANY RECORDS OF THE CITY - %s.",city);
	}
	if(a=='n'||a=='N')
	{
		fclose(fp);
	}
	if(i>=1 && (a=='y'||a=='Y'))
	{
		printf("\n\t\t\t\t\tSORRY GUYS NO MORE RECORDS IN THE CITY.!!!");
		fclose(fp);
	}
	if(i>=1)
	{
		 calculate_amt(i);
	}
	int x;
	printf("\n\n\t\t\t\t\tEnter [1] to go back to menu : -");
	fflush(stdin);
	scanf("%d",&x);
	while(x != 1)
	{
		printf("\n\n\t\t\t\t\tEnter [1] to go back to menu : -");
		fflush(stdin);
		scanf("%d",&x);
	}
	if(x == 1)
	{
		system("cls");
		return;
	}
}


//Calculating the Amount to be paid to the Donor
void calculate_amt(int n)
{
	float sum,amt;
	amt = 1200;
	float no_of_units = n;
	sum= no_of_units*amt;  
	printf("\n\n\t\t\t\t\tAmount to be paid to the Donor");
	printf("\n\t\t\t\t\tAmount paid per Unit = Rs.%f\n",amt);
	//printf("\t\t\t\t\tTotal Amount to be paid for %d units  = Rs.%f\n",n,sum);
}


//Feedback for the service.
void feedback()
{
	SetColor(0);
	system("color 8e");
	fflush(stdin);
	printf("\n\n\n\n\n\n\n\n\n");
	char review[100];
	printf("\t\t\t\tHope you got the information you were searching about.\n\t\t\t\tPlease take a minute to give us the feedback about our service\n\n\t\t\t\t\t->");
	fflush(stdin);
	gets(review);
	printf("\n\t\t\t\tThat is great to hear from you. \n\t\t\t\tAnd thank you so much for taking time to give your feedback\n\n");
	int x;
	printf("\n\n\t\t\t\tEnter [1] to go back to menu : -");
	fflush(stdin);
	scanf("%d",&x);
	while(x != 1)
	{
		printf("\n\t\t\t\tEnter [1] to go back to menu : -");
		fflush(stdin);
		scanf("%d",&x);
	}
	if(x == 1)
	{
		system("cls");
		return;
	}
	
}


//To search for plasma donor.
void getplasma_donor()
{
	SetColor(0);
	system("color 4e");
	int i=0;
	int id;
	char a='y';
	char blood_group[10];
	fp=fopen("blood_database.txt","r");
	if(fp==NULL)
	{
		printf("\t\t\t\t\tCannot Open File");
		exit(1);
	}
	fflush(stdin);
	printf("\n\n\n\n\n\n\n\n\n");
	printf("\t\t\t\t\tEnter the Blood Group :-");
	scanf("%s",blood_group);
	int n= strlen(blood_group);
	for(int i=0;i<n;i++)
	{
		if(isalpha(blood_group[i]))
		{
			blood_group[i] = tolower(blood_group[i]);
		}
	}
	char plasma[5] = "yes";
	rewind(fp);

	while(fread(&b,sizeof(struct Blood_Donor),1,fp)==1)
	{
		if(a=='Y'||a=='y')
		{
			if(strcmp(b.Blood_Group,blood_group)==0  && strcmp(b.Plasma,plasma)==0 )      //Mathching the Bloodgroup required with the one's present in Database
			{
				printf("\n\t\t\t\t\tDETAILS OF THE PLASMA DONOR WITH BLOOD GROUP '%s'",blood_group);
				printf("\n\t\t\t\t\tName: %s",b.Name);
				printf("\n\t\t\t\t\tDonor Id: %d",b.ID);
				printf("\n\t\t\t\t\tAge: %d",b.Age);
				printf("\n\t\t\t\t\tAddress of the donor: %s",b.Address);
				printf("\n\t\t\t\t\tCity: %s ",b.City);
				printf("\n\t\t\t\t\tPhone No:- %s",b.Phone_No);
				printf("\n\t\t\t\t\tEmail: %s",b.Email);
				printf("\n\t\t\t\t\tBlood Group: %s\n",b.Blood_Group);
				printf("\n\t\t\t\t\tENTER Y TO GET MORE BLOOD PLASMA DONORS!!");
				fflush(stdin);
				scanf("%c",&a);
				i++;
			}
		}
	}
	
	if(a=='n'||a=='N')
	{
		fclose(fp);
	}
	if(a=='Y'||a=='y')
	{
		
		printf("\n\t\t\t\t\tSORRY GUYS NO MORE RECORDS REGARDING PLASMA.!!!");
		fclose(fp);
	}
	if(i>=1)
	{
		
		calculate_amt_plasma(i);
	}
	int x;
	printf("\n\n\t\t\t\t\tEnter [1] to go back to menu :-");
	fflush(stdin);
	scanf("%d",&x);
	while(x != 1)
	{
		printf("\n\t\t\t\t\tEnter [1] to go back to menu :-");
		fflush(stdin);
		scanf("%d",&x);
	}
	if(x == 1)
	{
		system("cls");
		return;
	}
}


//Calculating the Amount to be paid to the plasma donor.
void calculate_amt_plasma(int n)
{
	float sum,amt;
	amt = 5000;
	float no_of_units = n;
	sum= no_of_units*amt;            
	printf("\n\t\t\t\t\tAmount paid per Unit = Rs.%f\n",amt);
	//printf("\t\t\t\t\tTotal Amount to be paid = Rs.%f\n",sum);
}


//To get the donor ID of the new donor who registers.
int Donor_id()
{
	FILE *fid;
	int number;
	fid=fopen("Donor_ID.txt","r");
   	fscanf(fid,"%d",&number);
    fclose(fid);
    fid=fopen("Donor_ID.txt","w");
    fprintf(fid,"%d",number+1);
    fclose(fid);
    return number;
}


int max_Donor_id()
{
	FILE *fid;
	int num;
	fid=fopen("Donor_ID.txt","r");
   	fscanf(fid,"%d",&num);
    fclose(fid);
	return num;
}


//diplay details of the donor.
void details_donor()
{
	system("color 8e");
	SetColor(0);
	int id;
	char a='y';
	fp=fopen("blood_database.txt","r");
	if(fp==NULL)
	{
		printf("Cannot Open File");
		exit(1);
	}
	fflush(stdin);
	printf("\n\n\n\n\n\n\n\n\n");
	printf("\n\t\t\t\t\tEnter the Donor Id : -");
	scanf("%d",&id);
	int max_id = max_Donor_id();
	while(id <= 1000 || id >=max_id)
	{
		printf("\n\n\t\t\t\t\tSORRY INVALID INPUT\n");
		printf("\n\t\t\t\t\tEnter correct Donor Id :-");
		scanf("%d",&id);
	}
	rewind(fp);

	while(fread(&b,sizeof(struct Blood_Donor),1,fp)==1)
	{
		if(b.ID==id)      //checking for the mathching donor's ID in the Database.
		{
			printf("\n\t\t\t\t\tDETAILS OF THE DONOR WITH ID '%d'",b.ID);
			printf("\n\t\t\t\t\tName: %s",b.Name);
			printf("\n\t\t\t\t\tDonor Id: %d",b.ID);
			printf("\n\t\t\t\t\tAge: %d",b.Age);
			printf("\n\t\t\t\t\tAddress of the donor: %s",b.Address);
			printf("\n\t\t\t\t\tCity: %s ",b.City);
			printf("\n\t\t\t\t\tPhone No:- %s",b.Phone_No);
			printf("\n\t\t\t\t\tEmail: %s",b.Email);
			printf("\n\t\t\t\t\tBlood Group: %s\n",b.Blood_Group);
			fclose(fp);
		}
	}
	int x;
	printf("\n\n\t\t\t\t\tEnter [1] to go back to menu :-");
	fflush(stdin);
	scanf("%d",&x);
	while(x != 1)
	{
		printf("\n\n\t\t\t\t\tEnter [1] to go back to menu :-");
		fflush(stdin);
		scanf("%d",&x);
	}
	if(x == 1)
	{
		system("cls");
		return;
	}
}

//To place the text
void gotoxy(int x, int y)
{
   coordinate.X = x; coordinate.Y =  y;
   SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),coordinate);
}

// To set th text color
void SetColor(int ForgC)
{
     WORD wColor;
     ///We will need this handle to get the current background attribute
     HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
     CONSOLE_SCREEN_BUFFER_INFO csbi;

     ///We use csbi for the wAttributes word.
     if(GetConsoleScreenBufferInfo(hStdOut, &csbi))
     {
        ///Mask out all but the background attribute, and add in the forgournd color
          wColor = (csbi.wAttributes & 0xF0) + (ForgC & 0x0F);
          SetConsoleTextAttribute(hStdOut, wColor);
     }
     return;
}