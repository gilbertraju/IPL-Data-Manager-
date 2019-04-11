#include <iostream>
#include <fstream>
#include <string>
#include<windows.h>
#include <algorithm> 
using namespace std;




void SearchPlayers();
void SearchTeams();
//void SearchStadium();
void ModifyPlayers();
void ModifyTeams();
//void ModifyStadium();
int UpdateP(int upd);

int main()
{

	int sel,sel1,sel2;
	//--------------------------------------Home------------------------------------------//
	Home:
		system("cls");
	
	cout<<"						IPL Cricket Tournament Organizer"<<endl;
	cout<<"\n\n";
	cout<<"1.Search\n2.Modify Details\n3.Schedule\n\n";
	cout<<"Select the function you want to perform: ";
	cin>>sel;
	
	if(sel<1||sel>3)
	goto Home;
	//--------------------------------Search Home------------------------------------------//
	switch(sel){
case 1:{
	
	Search:
		system("cls");
		cout<<"						Search"<<endl;
	cout<<"\n\n";
	cout<<"1.Search Players\n2.Search Teams\n\n";
	cout<<"Select what you want to search: ";
	cin>>sel1;
	if(sel1<1||sel1>2)
	goto Search;
	//-------------------------------Search Players-----------------------------------------//
	
	switch(sel1){
case 1:{
 SearchPlayers();
	break;
}
case 2:{
	SearchTeams();	
	break;
}	
/*case 3:{

//SearchStadium();

	break;
}	
*/
}
break;
}

case 2:
	{
		
	Modify:
		system("cls");
		cout<<"						Modify Details"<<endl;
	cout<<"\n\n";
	cout<<"1.Modify Player Details\n2.Modify Team Details\n\n";
	cout<<"Select what you want to modify: ";
	cin>>sel1;
	if(sel1<1||sel1>2)
	goto Modify;
	//-------------------------------Search Players-----------------------------------------//
	
	switch(sel1){
case 1:{
 ModifyPlayers();
	break;
}
case 2:{
	ModifyTeams();	
	break;
}
	
case 3:{
//ModifyStadium();

	break;
		}	
	
}
		break;
}
	
	case 3:
		{
			int rep=0;
			system("cls");
	string teams[2][4]={{"MI","CSK","RCB","DC"},{"KKR","RR","KXIP","SRH"}};	
	
	  repeat:
     random_shuffle(&teams[0][0], &teams[0][0] + 2*4);	   
			string temp;
			for(int i=1;i<9;i++){
			
			temp = teams[0][1];
			teams[0][1]	= teams[1][0];
			teams[1][0]	= teams[1][1];
			teams[1][1]	= teams[1][2];
			teams[1][2]	= teams[1][3];
			teams[1][3]	= teams[0][3];
			teams[0][3]	= teams[0][2];
			teams[0][2]	= temp;
			
			cout<<"\nWEEK "<<i<<" Fixtures\n"<<endl;
			cout<<"Match 1-"<<teams[0][0]<<" Vs "<<teams[1][0]<<endl;
			cout<<"Match 2-"<<teams[0][1]<<" Vs "<<teams[1][1]<<endl;
			cout<<"Match 3-"<<teams[0][2]<<" Vs "<<teams[1][2]<<endl;
			cout<<"Match 4-"<<teams[0][3]<<" Vs "<<teams[1][3]<<endl;
			
		}
		cout<<"\n\nPress 0 to randomize again...."<<endl;
		cin>>rep;
			if(rep==0){
			system("cls");	
			goto repeat;
		}
			
			
			
		}
}
	
	return 0;
}


//-----------------------Classes & Functions--------------------------------//

void SearchTeams()
{
	
	string search="";
    int count = 0;
    string line="";
    ifstream fin;

    fin.open("TeamDetails.txt",ios::in);
    cout << "							Search Teams";
    cout<<"\n\n";
    cout << "Type the name of the Team you want to search for: ";
    //cin>>search;
    int pos;
    cin.ignore();
    getline(cin,search);
	//int len=search.length();
    if(fin.is_open()) 
    {
    	while(getline(fin, line)){
      //getline(fin, line);
       
            if (line.find(search,0)!= (string:: npos))
			{
				cout << line << endl;
				pos=fin.tellg();
				fin.seekg(pos );
				for (int i = 0;getline(fin, line)&&i<27;i++)
				{
							
					cout << line << endl;
										
				}
				break;
			}
}
        }
        else
        cout<<"ERROR";
        
        fin.close();


}
void SearchPlayers()
{

		
			
	string search="";
    int count = 0;
    string line="";
    ifstream fin;
	cin.ignore();
	recheck:
    fin.open("PlayerDetails.txt",ios::in);
    cout << "							Search Players";
    cout<<"\n\n";
    cout << "Type the name of the Player you want to search for: ";
    //cin>>search;
    int pos;
    
    getline(cin,search);
	//int len=search.length();
    if(fin.is_open()) 
    {
    	while(getline(fin, line)){
      //getline(fin, line);
       
            if (line.find(search,0)!= (string:: npos))
			{	
			
				cout<<"\n\n";
				cout << line << endl;
				pos=fin.tellg();
				fin.seekg(pos-2);
				for (int i = 0;getline(fin, line)&&i<24;i++)
				{
							
					cout << line << endl;
										
				}
				count =1;
				break;
			}
			else
			count=0;
}
        
        if(count==0){
        	cout<<"\n\nPlayer with name "<<search<<" could not be found.................\n\n"<<endl;
        	
        	goto recheck;
		}
	}
        else
        cout<<"ERROR";
        
        fin.close();

	
}
/*
void SearchStadium()
{
	
		
	string search="";
    int count = 0;
    string line="";
    ifstream fin;

    fin.open("StadiumDetails.txt",ios::in);
    cout << "							Search Stadiums";
    cout<<"\n\n";
    cout << "Type the name of the Stadium you want to search for: ";
    //cin>>search;
    int pos;
    cin.ignore();
    getline(cin,search);
	//int len=search.length();
    if(fin.is_open()) 
    {
    	while(getline(fin, line)){
      //getline(fin, line);
       
            if (line.find(search,0)!= (string:: npos))
			{
				cout << line << endl;
				pos=fin.tellg();
				fin.seekg(pos );
				for (int i = 0;getline(fin, line)&&i<27;i++)
				{
							
					cout << line << endl;
										
				}
				break;
			}
}
        }
        else
        cout<<"ERROR";
        
        fin.close();


	
	
}
*/
//--------------------------------

void ModifyPlayers()
{
	int sel1;
	string name,role,team;
	ModifyP:
		system("cls");
		cout<<"						Modify PLayer Details"<<endl;
	cout<<"\n\n";
	
	cout<<"1.Add a New Player\n2.Update Player Details\n3.Delete Player\n0.Home\n\n";
	cout<<"Select what you want to do: ";
	cin>>sel1;
	if(sel1<1||sel1>4)
	goto ModifyP;
	
	switch(sel1)
	{
		case 1:
			{
				system("cls");
	string updt;
	ofstream fout;
	fout.open("PlayerDetails.txt",ios::ate|ios::app);
	fout<<"\n\n";
				
		cout<<"						Add a New Player"<<endl;
	cout<<"\n\n";
	
	cout<<"Name: ";
	cin>>updt;
	fout<<"                                                  :      NAME                 :       "<<updt<<"       :"<<endl;
	fout<<"                                                  :~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~:"<<endl<<"\n";
	
	cout<<"\n\t\t\t\t\tBATTING\n";
	fout<<" BATTING"<<endl<<"\n";
	
	cout<<"No. of Innings: ";
	cin.ignore();
	cin>>updt;
	fout<<"	MATCH                :		"<<updt<<endl;
	
	cout<<"Not Outs: ";
	cin>>updt;
	fout<<"	Not-out              :          "<<updt<<endl;
	
	cout<<"Total Runs: ";
	cin>>updt;
	fout<<"	RUNS                 :          "<<updt<<endl;
	
	cout<<"Highest Score: ";
	cin>>updt;
	fout<<"	HIGHEST SCORE        :          "<<updt<<endl;
	
	cout<<"Average: ";
	cin>>updt;
	fout<<"	AVERAGE              :          "<<updt<<endl;
	
	cout<<"Strike Rate: ";
	cin>>updt;
	fout<<"	STRIKE-RATE          :          "<<updt<<endl;
	
	cout<<"Total Centuries: ";
	cin>>updt;
	fout<<"	100                  :          "<<updt<<endl;
	
	cout<<"Total Half-Centuries: ";
	cin>>updt;
	fout<<"	50                   :          "<<updt<<endl;
		
	cout<<"\n\t\t\t\t\tBOWLING\n";
	fout<<"\n BOWLING"<<endl<<"\n";
	
	cout<<"Total Matches: ";
	cin>>updt;
	fout<<"	MATCH		     : 		"<<updt<<endl;
	
	cout<<"Total Wickets: ";
	cin>>updt;
	fout<<"	WICKETS		     :		"<<updt<<endl;
	
	cout<<"BBM-(wkt/runs): ";
	cin>>updt;
	fout<<"	BBM		     :		"<<updt<<endl;
	
	cout<<"Bowling Average: ";
	cin>>updt;
	fout<<"	AVERAGE		     :          "<<updt<<endl;
	
	cout<<"Ecomony: ";
	cin>>updt;
	fout<<"	ECOMONY              :		"<<updt<<endl;
	
	cout<<"4 Wickets: ";
	cin>>updt;
	fout<<"	4W                   :		"<<updt<<endl;
	
	cout<<"5 Wicktes: ";
	cin>>updt;
	fout<<"	5W                   :		"<<updt<<endl<<"\n\n\n";
	
	
	cout<<"\nNew Data Saved..........";
break;	

			}
			
case 2:
	{
		
		system("cls");
	
	string search="";
    int count = 0;
    string line="";
    int upd;
    ifstream fin;

    fin.open("PlayerDetails.txt",ios::in);
    cout << "\n							Update Existing Player Details";
    cout<<"\n\n";
    cout << "Enter the name of thr Player: ";
    //cin>>search;
    int pos;
    cin.ignore();
    getline(cin,search);
	int len=search.length();
    if(fin.is_open()) 
    {
    	while(getline(fin, line)){
      //getline(fin, line);
       
            if (line.find(search,0)!= (string:: npos))
			{
				pos=fin.tellg();
				fin.seekg(pos);
				cout <<"Found "<<search<<"\n"<<endl;
				repeat:
				cout<<"\n1.Change Batting Details\n2.Change Bowling Details\n0.Home\n";
				cout<<"\nEnter What You Want To Change: ";
				//cin.ignore();
				cin>>upd;
				fin.close();
				UpdateP(upd);
				count=0;			
				break;
			}
			else{
			count=1;	
			
		}
}
if(count==1)
cout<<"Cannot Find a Player with the Name "<<search;
        }
        else
        cout<<"Could Not Open The File";
        
        fin.close();

	
		break;
	}
	
	
case 3:
{
	reset:
		system("cls");
	
	string search="";
    int count = 0;
    string line="";
    int upd;
    ifstream fin;
    ofstream fout;

    fin.open("PlayerDetails.txt");
    fout.open("temp.txt");
    cout << "\n							Delete Player Details";
    cout<<"\n\n";
    cout << "Enter the name of thr Player: ";
    //cin>>search;
    int pos;
    char res = ' ';
    cin.ignore();
    getline(cin,search);
	//int len=search.length();
	cout<<"\n\n ARE YOU SURE ?(Y/N): ";
	cin>>res;
	if(res=='N'||res=='n')
	goto reset;
	
    if(fin.is_open()) 
    {
    	while(getline(fin, line)){
      //getline(fin, line);
       
            if (line.find(search,0)!= (string:: npos))
			{	
			pos=fin.tellg();
				fin.seekg(pos);	
				for (int i = 0;getline(fin, line)&&i<24;i++)
				{
				
				continue;						
				}
			continue;	
			}
			else{
			fout<<line<<endl;
			
		}
}
cout<<"\nSuccefully Deleted..................."<<endl;
   }
        else
        cout<<"Could Not Open The File";
        
        fin.close();
		fout.close();
        remove("PlayerDetails.txt");
        rename("temp.txt","PlayerDetails.txt");
	
	
	
	break;
}
	}
	
}

void ModifyTeams()
{
	

	int sel1;
	string updt1;
	ModifyP:
		system("cls");
		cout<<"						Modify Team Details"<<endl;
	cout<<"\n\n";
	
	cout<<"1.Add a New Team\n2.Update Existing Team Details\n3.Delete Team\n0.Home\n\n";
	cout<<"Select what you want to do: ";
	cin>>sel1;
	if(sel1<1||sel1>4)
	goto ModifyP;
	
	switch(sel1)
	{
		case 1:
			{
				system("cls");
	string updt;
	ofstream fout;
	fout.open("TeamDetails.txt",ios::ate|ios::app);
	fout<<"\n\n\n\n";
				
		cout<<"						Add a New Team"<<endl;
	cout<<"\n\n";
	
	cout<<"Name of Team: ";
	cin>>updt;
	fout<<updt<<endl;
	cout<<"\nEnter Details About The Team"<<endl;
	cin>>updt;
	fout<<updt<<endl;
	cout<<"\nEnter Details of 15 players:\n"<<endl;
	fout<<"Players			Role	"<<endl;
	for(int i=0;i<16;i++)
	{
	cout<<"Name of Player: ";
	cin>>updt;
	cout<<"Role of Player: ";
	cin>>updt1;
	fout<<" "<<updt<<"		"<<updt1<<"	"<<updt<<endl;
		
	}
	
	cout<<"\nNew Data Saved..........";
break;	

			}
			
case 2:
	{
	/*	
		system("cls");
	
	string search="";
    int count = 0;
    string line="";
    int upd;
    ifstream fin;

    fin.open("TeamDetails.txt",ios::in);
    cout << "\n							Update Existing Team Details";
    cout<<"\n\n";
    cout << "Enter the name of thr Player: ";
    //cin>>search;
    int pos;
    cin.ignore();
    getline(cin,search);
	int len=search.length();
    if(fin.is_open()) 
    {
    	while(getline(fin, line)){
      //getline(fin, line);
       
            if (line.find(search,0)!= (string:: npos))
			{
				pos=fin.tellg();
				fin.seekg(pos);
				cout <<"Found "<<search<<"\n"<<endl;
				repeat:
				cout<<"\n1.Change Batting Details\n2.Change Bowling Details\n0.Home\n";
				cout<<"\nEnter What You Want To Change: ";
				//cin.ignore();
				cin>>upd;
				fin.close();
				UpdateP(upd);
				count=0;			
				break;
			}
			else{
			count=1;	
			
		}
}
if(count==1)
cout<<"Cannot Find a Player with the Name "<<search;
        }
        else
        cout<<"Could Not Open The File";
        
        fin.close();

	*/
		break;
	}
	
	
case 3:
{
	reset:
		system("cls");
	
	string search="";
    int count = 0;
    string line="";
    int upd;
    ifstream fin;
    ofstream fout;

    fin.open("TeamDetails.txt");
    fout.open("temp.txt");
    cout << "\n							Delete Team Details";
    cout<<"\n\n";
    cout << "Enter the name of the Team: ";
    //cin>>search;
    int pos;
    char res = ' ';
    cin.ignore();
    getline(cin,search);
	//int len=search.length();
	cout<<"\n\n ARE YOU SURE ?(Y/N): ";
	cin>>res;
	if(res=='N'||res=='n')
	goto reset;
	
    if(fin.is_open()) 
    {
    	while(getline(fin, line)){
      //getline(fin, line);
       
            if (line.find(search,0)!= (string:: npos))
			{	
			pos=fin.tellg();
				fin.seekg(pos);	
				for (int i = 0;getline(fin, line)&&i<27;i++)
				{
				
				continue;						
				}
			continue;	
			}
			else{
			fout<<line<<endl;
			
		}
}
cout<<"\nSuccefully Deleted..................."<<endl;
   }
        else
        cout<<"Could Not Open The File";
        
        fin.close();
		fout.close();
        remove("TeamDetails.txt");
        rename("temp.txt","TeamDetails.txt");
	
	
	
	break;
}
	}

	
}

/*
void ModifyStadium()
{
	
}
*/

 //-----------------------------------------
 int UpdateP(int upd)
 {
 	switch(upd){
 		
 		case 1:
		 {
		 	reset:
		 				system("cls");
	string updt[25],line;
	int pos;
	ofstream fout;
	ifstream fin;
	fin.open("PlayerDetails.txt");
	fout.open("temp.txt");
	fout<<"\n";
	char res;			
	cout<<"\n\t\t\t\t\t\t\tBATTING\n";
				
	cout<<"Name: ";
	cin>>updt[1];
	
//cin.ignore();	
	
	cout<<"No. of Innings: ";
	cin>>updt[2];
	
	
	cout<<"Not Outs: ";
	cin>>updt[3];
	
	
	cout<<"Total Runs: ";
	cin>>updt[4];
	
	
	cout<<"Highest Score: ";
	cin>>updt[5];
	
	
	cout<<"Average: ";
	cin>>updt[6];
	
		
	cout<<"Strike Rate: ";
	cin>>updt[7];
	
	
	cout<<"Total Centuries: ";  
	cin>>updt[8];
	
	
	cout<<"Total Half-Centuries: ";
	cin>>updt[9];
	
	cout<<"Are You Sure You Want to change?(Y/N): ";
	cin>>res;
		 	if(res=='N'||res=='n')
		 	goto reset;
		 	
	if(fin.is_open()) 
    {
    	while(getline(fin, line)){
      //getline(fin, line);
       
            if (line.find(updt[1],0)!= (string:: npos))
			{	
			pos=fin.tellg();
				fin.seekg(pos);	
				for (int i = 0;getline(fin, line)&&i<11;i++)
				{
				if(i==0){
				
				
	fout<<"                                                  :      NAME                 :       "<<updt[1]<<"       :"<<endl;
	
	fout<<"                                                  :~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~:"<<endl<<"\n";
	
	fout<<" BATTING"<<endl<<"\n";
	
	fout<<"	MATCH                :		"<<updt[2]<<endl;
	
	fout<<"	Not-out              :          "<<updt[3]<<endl;
	
	fout<<"	RUNS                 :          "<<updt[4]<<endl;
	
	fout<<"	HIGHEST SCORE        :          "<<updt[5]<<endl;
	
	fout<<"	AVERAGE              :          "<<updt[6]<<endl;
	
	fout<<"	STRIKE-RATE          :          "<<updt[7]<<endl;
	
	fout<<"	100                  :          "<<updt[8]<<endl;
	
	fout<<"	50                   :          "<<updt[9]<<endl;
}
	else{
	
		continue;
}
				
										
				}
			continue;	
			}
			else{
			fout<<line<<endl;
			
		}
}
cout<<"\nSuccefully Updated..................."<<endl;
   }
        else{
		
        cout<<"Could Not Open The File";
    }
        
        fin.close();
		fout.close();
        remove("PlayerDetails.txt");
        rename("temp.txt","PlayerDetails.txt");
	
		 	
		 	
			break;
		 }
		 case 2:
		 {
		 	
		 	
		 		 	reset1:
		 				system("cls");
	string updt[25],line;
	int pos;
	ofstream fout;
	ifstream fin;
	fin.open("PlayerDetails.txt");
	fout.open("temp.txt");
	fout<<"\n";
	char res;			
	cout<<"\n\t\t\t\t\t\t\tBOWLING\n";
				
	cout<<"Name: ";
	cin>>updt[1];
	
//cin.ignore();	
	
	
	cout<<"Total Matches: ";
	cin>>updt[2];
	
	cout<<"Total Wickets: ";
	cin>>updt[3];
	
	cout<<"BBM-(wkt/runs): ";
	cin>>updt[4];
	
	cout<<"Bowling Average: ";
	cin>>updt[5];
	
	cout<<"Ecomony: ";
	cin>>updt[6];
	
	cout<<"4 Wickets: ";
	cin>>updt[7];
	
	cout<<"5 Wicktes: ";
	cin>>updt[8];
	
	cout<<"Are You Sure You Want to change?(Y/N): ";
	cin>>res;
		 	if(res=='N'||res=='n')
		 	goto reset1;
		 	
	if(fin.is_open()) 
    {
    	while(getline(fin, line)){
      //getline(fin, line);
       
            if (line.find(updt[1],0)!= (string:: npos))
			{	
			pos=fin.tellg();
				fin.seekg(pos);	
					fout<<line<<endl;
				for (int i = 0;getline(fin, line)&&i<11;i++)
				{
					fout<<line<<endl;
					continue;
				}
				pos=fin.tellg();
				fin.seekg(pos);
				for (int i = 0;getline(fin, line)&&i<11;i++)
				{
				if(i==0){
				
					
	fout<<"\n BOWLING"<<endl<<"\n";
	
	fout<<"	MATCH                :		"<<updt[2]<<endl;
	
	fout<<"	WICKETS		     :		"<<updt[3]<<endl;
	
	fout<<"	BBM		     :		"<<updt[4]<<endl;
	
	fout<<"	AVERAGE		     :          "<<updt[5]<<endl;
	
	fout<<"	ECOMONY              :		"<<updt[6]<<endl;
	
	fout<<"	4W                   :		"<<updt[7]<<endl;
	
	fout<<"	5W                   :		"<<updt[8]<<endl<<"\n\n\n";
	
	
								}
								else{
	
										continue;
									}
							}
}
	
			else{
			fout<<line<<endl;
			
		}		
										
				}
					

cout<<"\nSuccefully Updated..................."<<endl;
}
        else{
		
        cout<<"Could Not Open The File";
    }
        
        fin.close();
		fout.close();
        remove("PlayerDetails.txt");
        rename("temp.txt","PlayerDetails.txt");
		
			break;
		 }
		
	 }
 	return 0;
 }
