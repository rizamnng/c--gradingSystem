#include<iostream>
#include<vector>
#include<stdlib.h>
#include<fstream>
#include<sstream>
#include<iomanip>
using namespace std;
class Record
{
	string name;
	double Mattendance;
	string Msa;
	double Mquizzes;
	string Msq;
	double Mparticipation;
	string Msp;
	double Mexams;
	string Mse;
	double Fattendance;
	string Fsa;
	double Fquizzes;
	string Fsq;
	double Fparticipation;
	string Fsp;
	double Fexams;
	string Fse;
	
	public:
		void setData(string n,double Ma,double Mq, double Mp,double Me, double Fa,double Fq,double Fp, double Fe)
		{
			name=n;
			Mattendance=Ma;
			Mquizzes=Mq;
			Mparticipation=Mp;
			Mexams=Me;
			Fattendance=Fa;
			Fquizzes=Fq;
			Fparticipation=Fp;
			Fexams=Fe;
		}
		void setScores(string m1,string m2,string m3,string m4,string f1,string f2,string f3,string f4)
		{
			Msa=m1;
			Msq=m2;
			Msp=m3;
			Mse=m4;
			Fsa=f1;
			Fsq=f2;
			Fsp=f3;
			Fse=f4;
			
		}
		string getName()
		{
			return name;
		}
		double getAttendance()
		{
			return Mattendance;
		}
		double getQuizzes()
		{
			return Mquizzes;
		}
		double getParticipation()
		{
			return Mparticipation;
		}
		double getExam()
		{
			return Mexams;
		}
		double getFAttendance()
		{
			return Fattendance;
		}
		double getFQuizzes()
		{
			return Fquizzes;
		}
		double getFParticipation()
		{
			return Fparticipation;
		}
		double getFExam()
		{
			return Fexams;
		}
		string getMsa()
		{
			return Msa;
		}
		string getMsq()
		{
			return Msq;
		}
		string getMsp()
		{
			return Msp;
		}
		string getMse()
		{
			return Mse;
		}
		string getFsa()
		{
			return Fsa;
		}
		string getFsq()
		{
			return Fsq;
		}
		string getFsp()
		{
			return Fsp;
		}
		string getFse()
		{
			return Fse;
		}
		
};

class LoginInfo
{
	string userName;
	string password;
	public:
		void setInfo(string us, string pass)
		{
			userName=us;
			password=pass;
		}
		string getUS()
		{
			return userName;
		}
		string getpass()
		{
			return password;
		}
		void display()
		{
			cout<<userName<<" "<<password<<endl;
		}
};

void loadaccount(vector <LoginInfo> &);
void firstpage(int& ,int&,string&);
void addSection();
void sectionName();
void display(int &);
void addstudent(string section);
void displayrecords(int &action);
void attendance(string section);
void quizzes(string);
void participation(string);
void exam(string);
void edit(string);
void delet(string);
void viewRecordsMid(string);
void load(string section,vector <Record> &S);
void viewRecordsMid(vector<Record> );
void searchAddAttendance(string);
void searchAddQuizzes(string);
void searchAddParticipation(string);
void searchAddExam(string);
void searchRecord(vector <Record> );
void computeGrades(vector <Record> );
void viewRecordsFinal(vector<Record>);
void displayFinal(int &act);
void attendanceFinal(string );
void quizzesFinal(string section);
void participationFinal(string);
void examFinal(string);
void searchAttendanceFinal(string);
void searchQuizzesFinal(string );
void searchParticipationFinal(string);
void searchExamFinal(string);
void searchFinalRecord(vector <Record> );
void computeFinalGrades(vector <Record> );
void computeSemGrades(vector <Record> );
void editSectionName();
void deleteSection();
void signup();

int main()
{
	string username,password;
	vector <LoginInfo> AC;
	bool found;
	found=false;
	loadaccount(AC);
	while(!found)
	{
		system("cls");
		cout<<endl<<endl<<endl<<endl<<endl<<"\t\t\t\t\t=============================="<<endl;
		cout<<"\t\t\t\t\t ===========LOG IN=========== "<<endl<<endl;
		cout<<setw(60)<<"username: ";
		cin>>username;
		cout<<setw(60)<<"password: ";
		cin>>password;
		for(int i=0;i<AC.size();i++)
		{
			if(username==AC[i].getUS() && password==AC[i].getpass())
			{ 
				system("cls");
				found=true;
				int act,t;
				string sec;
				firstpage(act,t,sec);
				while (act!=t+4)
				{
					if (act==t)
					{
						addSection();
					}
					else if(act==t+1)
					{
						editSectionName();
		
					}
					else if(act==t+2)
					{
						deleteSection();
					}
					else if(act==t+3)
					{
						signup();
					}
					else if(act<t and act>0)
					{
						system("cls");
						int periods;
						cout<<endl<<endl<<endl;
						cout<<"\t\t\t\t\t==========================="<<endl<<endl;
						cout<<"\t\t\t\t\t         1 =Midterm        "<<endl;
						cout<<"\t\t\t\t\t         2 =Finals         "<<endl;
						cout<<"\t\t\t\t\t          3 =Back          "<<endl<<endl;
						cout<<"\t\t\t\t\t==========================="<<endl;
						cout<<"\t\t\t\t\t            ==> ";
						cin>>periods;
						while(periods!=3)
						{
							if(periods==1)
							{
								int c;
								vector <Record> V;
								system("cls");
								load(sec,V);
								viewRecordsMid(V);
								cout<<endl<<endl<<endl;
								display(c);
								while(c!=7)
								{
									switch (c)
									{
										case 1:
											int ans;
											system("cls");
											cout<<endl<<endl<<endl;
											cout<<"\t\t\t\t\t==============================="<<endl<<endl;
											cout<<"\t\t\t\t\t           1 =ALL "<<endl;
											cout<<"\t\t\t\t\t          2 =SEARCH"<<endl;
											cout<<"\t\t\t\t\t           3 =BACK"<<endl<<endl;
											cout<<"\t\t\t\t\t==============================="<<endl<<endl;
											cout<<"\t\t\t\t\t              ==> ";
											cin>>ans;
											while(ans!=3)
											{
												int ch1;
												if(ans==1)
												{
													displayrecords(ch1);
													while(ch1!=5)
													{
														switch(ch1)
														{
															case 1:
																attendance(sec);
																break;
															case 2:
																quizzes(sec);
																break;
															case 3:
																participation(sec);
																break;
															case 4:
																exam(sec);
																break;
														}
														displayrecords(ch1);	
													}
												}
												else if(ans==2)
												{
													displayrecords(ch1);
													while(ch1!=5)
													{
														switch(ch1)
														{
															case 1:
																searchAddAttendance(sec);
																break;
															case 2:
																searchAddQuizzes(sec);
																break;
															case 3:
																searchAddParticipation(sec);
																break;
															case 4:
																searchAddExam(sec);
																break;
														}
														displayrecords(ch1);	
													}
												}
												system("cls");
												cout<<endl<<endl<<endl;
												cout<<"\t\t\t\t\t==============================="<<endl<<endl;
												cout<<"\t\t\t\t\t           1 =ALL "<<endl;
												cout<<"\t\t\t\t\t          2 =SEARCH"<<endl;
												cout<<"\t\t\t\t\t           3 =BACK"<<endl<<endl;
												cout<<"\t\t\t\t\t==============================="<<endl<<endl;
												cout<<"\t\t\t\t\t              ==> ";
												cin>>ans;
											}
											
											break;
										case 2:
											addstudent(sec);
											break;
										case 3:
											edit(sec);
											break;
										case 4:
											delet(sec);
											break;
										case 5:
											load(sec,V);
											searchRecord(V);
											break;
										case 6:
											load(sec,V);
											computeGrades(V);
											break;
									}
									system("cls");
									load(sec,V);
									viewRecordsMid(V);
									cout<<endl<<endl<<endl;
									display(c);
								}
						
							}
							else if(periods==2)
							{
								int w;
								vector <Record> W;
								system("cls");
								load(sec,W);
								viewRecordsFinal(W);
								cout<<endl<<endl<<endl;
								displayFinal(w);
								while(w!=7)
								{
									switch (w)
									{
										case 1:
											int ans;
											system("cls");
											cout<<endl<<endl<<endl;
											cout<<"\t\t\t\t\t==============================="<<endl<<endl;
											cout<<"\t\t\t\t\t           1 =ALL "<<endl;
											cout<<"\t\t\t\t\t          2 =SEARCH"<<endl;
											cout<<"\t\t\t\t\t           3 =BACK"<<endl<<endl;
											cout<<"\t\t\t\t\t==============================="<<endl<<endl;
											cout<<"\t\t\t\t\t              ==> ";
											cin>>ans;
											while(ans!=3)
											{
												int ch1;
												if(ans==1)
												{
													displayrecords(ch1);
													while(ch1!=5)
													{
														switch(ch1)
														{
															case 1:
																attendanceFinal(sec);
																break;
															case 2:
																quizzesFinal(sec);
																break;
															case 3:
																participationFinal(sec);
																break;
															case 4:
																examFinal(sec);
																break;
														}
														displayrecords(ch1);	
													}
												}
												else if(ans==2)
												{
													displayrecords(ch1);
													while(ch1!=5)
													{
														switch(ch1)
														{
															case 1:
																searchAttendanceFinal(sec);
																break;
															case 2:
																searchQuizzesFinal(sec);
																break;
															case 3:
																searchParticipationFinal(sec);
																break;
															case 4:
																searchExamFinal(sec);
																break;
														}
														displayrecords(ch1);	
													}
												}
												system("cls");
												cout<<endl<<endl<<endl;
												cout<<"\t\t\t\t\t==============================="<<endl<<endl;
												cout<<"\t\t\t\t\t           1 =ALL "<<endl;
												cout<<"\t\t\t\t\t          2 =SEARCH"<<endl;
												cout<<"\t\t\t\t\t           3 =BACK"<<endl<<endl;
												cout<<"\t\t\t\t\t==============================="<<endl<<endl;
												cout<<"\t\t\t\t\t              ==> ";
												cin>>ans;
											}
											
											break;
										case 2:
											edit(sec);
											break;
										case 3:
											delet(sec);
											break;
										case 4:
											load(sec,W);
											searchFinalRecord(W);
											break;
										case 5:
											computeFinalGrades(W);
											break;
										case 6:
											load(sec,W);
											computeSemGrades(W);
											break;
									}
									system("cls");
									load(sec,W);
									viewRecordsFinal(W);
									cout<<endl<<endl<<endl;
									displayFinal(w);
								}
								
							}
							system("cls");
							cout<<endl<<endl<<endl;
							cout<<"\t\t\t\t\t==========================="<<endl<<endl;
							cout<<"\t\t\t\t\t         1 =Midterm        "<<endl;
							cout<<"\t\t\t\t\t         2 =Finals         "<<endl;
							cout<<"\t\t\t\t\t          3 =Back          "<<endl<<endl;
							cout<<"\t\t\t\t\t==========================="<<endl;
							cout<<"\t\t\t\t\t            ==> ";
							cin>>periods;
						}
					}
					system("cls");
					firstpage(act,t,sec);
				}
				
			}
		}
		string ch="g";
		while(ch!="y" && ch!="n")
		{
			system("cls");
			cout<<endl<<endl<<endl;
			cout<<"\t\t\t\t\t==============================="<<endl<<endl;
			cout<<"\t\t\t\t\t      LOG IN AGAIN? y/n: ";
			cin>>ch;
			cout<<endl;
			cout<<"\t\t\t\t\t==============================="<<endl<<endl;
		
			if (ch=="y")
			{
				found=false;
				loadaccount(AC);
			}
			else if(ch=="n")
			{
				cout<<"\t\t\t\t\t==============================="<<endl<<endl;
				cout<<"\t\t\t\t\t          THANK YOU! "<<endl<<endl;
				cout<<"\t\t\t\t\t==============================="<<endl<<endl;
			}
		}
	}

return 0;
}

void loadaccount(vector <LoginInfo> &S)
{
	ifstream read("Admin Accounts.txt");
	LoginInfo L;
	string u, p;
	while(read>>u>>p)
	{
		L.setInfo(u,p);
		S.push_back(L);
	}
	read.close();

}
void signup()
{
	system("cls");
	ofstream Write("Admin Accounts.txt",ios::app);
	string u,p;
	cout<<endl<<endl;
	cout<<"\t\t\t\t============SIGN IN============"<<endl<<endl;
	cout<<"\t\t\t\t  username: ";
	cin>>u;
	cout<<"\t\t\t\t  password: ";
	cin>>p;
	cout<<endl<<endl;
	cout<<"\t\t\t\t==============================="<<endl<<endl;
	Write<<u<<" "<<p<<endl;
	Write.close();
	cout<<"\t\t\t\t==============================="<<endl<<endl;
	cout<<"\t\t\t\t\tADDED SUCCESSFULLY!"<<endl<<endl;
	cout<<"\t\t\t\t==============================="<<endl<<endl;
	system("PAUSE");
}

void firstpage(int &action,int &c,string &section)
{
	vector <string> s;
	s.clear();
	ifstream read("sections.txt");
	cout<<endl<<endl<<"\t\t\t\t\t%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%"<<endl<<endl;
	c=1;
	while(getline(read,section))
	{
		cout<<"\t\t\t\t\t\t"<<c<<" ="<<section<<endl;
		c++;
		s.push_back(section);
	}
	read.close();
	cout<<"\t\t\t\t\t\t"<<c<<" ="<<"ADD CLASS"<<endl;
	cout<<"\t\t\t\t\t\t"<<c+1<<" ="<<"EDIT CLASS NAME"<<endl;
	cout<<"\t\t\t\t\t\t"<<c+2<<" ="<<"DELETE CLASS"<<endl;
	cout<<"\t\t\t\t\t\t"<<c+3<<" ="<<"ADD ADMIN"<<endl;
	cout<<"\t\t\t\t\t\t"<<c+4<<" ="<<"LOG OUT";
	cout<<endl<<endl<<"\t\t\t\t\t%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%"<<endl<<endl;
	cout<<"\t\t\t\t\t\t\t"<<"\t==> ";
	cin>>action;
	if (action<c)
	{
		section=s[action-1];
	}
	
}

void addSection()
{
	system("cls");
	ofstream write("sections.txt",ios::app);
	ifstream read("sections.txt");
	bool add;
	string name,nm;
	add=false;
	int c=0;
	cin.ignore();
	cout<<endl<<endl<<endl;
	cout<<"\t\t\t\t\t==============================="<<endl<<endl;
	cout<<"\t\t\t\t\t\tCLASS NAME: ";
	getline(cin,name);
	cout<<endl<<endl;
	cout<<"\t\t\t\t\t==============================="<<endl<<endl;
	while(getline(read,nm))
	{
		if(nm==name)
		{
			c=1;
		}
	}
	if(c==0)
	{
		write<<name<<endl;
		name=name+".txt";
		ofstream write1;
		write1.open(name.c_str());
		write1.close();
		cout<<"\t\t\t\t\t==============================="<<endl<<endl;
		cout<<"\t\t\t\t\t\tADDED SUCCESSFULLY! "<<endl<<endl;
		cout<<"\t\t\t\t\t==============================="<<endl<<endl;
	}
	else
	{
		cout<<"\t\t\t\t\t==============================="<<endl<<endl;
		cout<<"\t\t\t\t\t     ALREADY ON THE LISTS! "<<endl<<endl;
		cout<<"\t\t\t\t\t==============================="<<endl<<endl;
	}
	write.close();
	read.close();
	system("pause");
}

void editSectionName()
{
	system("cls");
	ifstream read("sections.txt");
	string stname,name,newname;
	ofstream write("new.txt");
	cin.ignore();
	cout<<endl<<endl<<endl;
	cout<<"\t\t\t\t\t==============================="<<endl<<endl;
	cout<<"\t\t\t\t\t    CLASS NAME: ";
	getline(cin,stname);
	cout<<endl;
	cout<<"\t\t\t\t\t==============================="<<endl<<endl;
	int c=0;
	while(getline(read,name))
	{
		if(stname!=name)
		{
			write<<name<<endl;
		}
		else
		{
			cout<<"\t\t\t\t\t==============================="<<endl<<endl;
			cout<<"\t\t\t\t\t   NEW CLASS NAME: ";
			getline(cin,newname);
			cout<<endl;
			cout<<"\t\t\t\t\t==============================="<<endl<<endl;
			write<<newname<<endl;
			newname=newname+".txt";
			stname=stname+".txt";
			rename(stname.c_str(),newname.c_str());
			cout<<"\t\t\t\t\t==============================="<<endl<<endl;
			cout<<"\t\t\t\t\t    EDITED SUCCESSFULLY!      "<<endl<<endl;
			cout<<"\t\t\t\t\t==============================="<<endl<<endl;
			c=1;
		}
	}
	if(c==0)
	{
		cout<<"\t\t\t\t\t==============================="<<endl<<endl;
		cout<<"\t\t\t\t\t           NO RECORD "<<endl<<endl;
		cout<<"\t\t\t\t\t==============================="<<endl<<endl;
	}
	read.close();
	write.close();
	remove("sections.txt");
	rename("new.txt","sections.txt");
	system("pause");
}

void deleteSection()
{
	system("cls");
	ifstream read("sections.txt");
	string stname,name,newname;
	ofstream write("new.txt");
	cin.ignore();
	cout<<endl<<endl<<endl;
	cout<<"\t\t\t\t\t==============================="<<endl<<endl;
	cout<<"\t\t\t\t\t    CLASS NAME: ";
	getline(cin,stname);
	cout<<endl;
	cout<<"\t\t\t\t\t==============================="<<endl<<endl;
	int c=0;
	while(getline(read,name))
	{
		if(stname!=name)
		{
			write<<name<<endl;
		}
		else
		{
			cout<<"\t\t\t\t\t==============================="<<endl<<endl;
			cout<<"\t\t\t\t\t     DELETED SUCCESSFULLY!     "<<endl<<endl;
			cout<<"\t\t\t\t\t==============================="<<endl<<endl;
			c=1;
		}
	}
	if(c==0)
	{
		cout<<"\t\t\t\t\t==============================="<<endl<<endl;
		cout<<"\t\t\t\t\t           NO RECORD "<<endl<<endl;
		cout<<"\t\t\t\t\t==============================="<<endl<<endl;
	}
	stname=stname+".txt";
	read.close();
	write.close();
	remove(stname.c_str());
	remove("sections.txt");
	rename("new.txt","sections.txt");
	system("pause");
	
}

void display(int &act)
{
	cout<<"\t\t\t\t\t==============================="<<endl<<endl;
	cout<<"\t\t\t\t\t         1 =ADD RECORDS        "<<endl;
	cout<<"\t\t\t\t\t         2 =ADD STUDENT        "<<endl;
	cout<<"\t\t\t\t\t     3 =EDIT STUDENTS NAME     "<<endl;
	cout<<"\t\t\t\t\t   4 =DELETE STUDENTS RECORD   "<<endl;
	cout<<"\t\t\t\t\t        5 =SEARCH RECORD       "<<endl;
	cout<<"\t\t\t\t\t       6 =COMPUTE GRADES       "<<endl;
	cout<<"\t\t\t\t\t            7 =BACK            "<<endl<<endl;
	cout<<"\t\t\t\t\t==============================="<<endl<<endl;
	cout<<"\t\t\t\t\t              ==> ";
	cin>>act;
}

void addstudent(string section)
{
	system("cls");
	string Cname;
	section=section+".txt";
	cin.ignore();
	cout<<endl<<endl<<endl;
	cout<<"\t\t\t\t\t==============================="<<endl<<endl;
	cout<<"\t\t\t\t\t   Complete Name: ";
	getline(cin,Cname);
	cout<<endl<<"\t\t\t\t\t==============================="<<endl<<endl;
	ifstream read(section.c_str());
	string name,mids,atten,quiz,part,ex,a1,a2,a3,a4,g1,g2,g3,g4,c1,c2,c3,c4;
	string fin,at,at1,at2,at3,q,q1,q2,q3,p,p1,p2,p3,e,e1,e2,e3;
	int count=0;
	string check;
	while(getline(read,name),getline(read,mids),getline(read,atten),getline(read,a1),getline(read,g1),getline(read,c1),getline(read,quiz),getline(read,a2),getline(read,g2),getline(read,c2),getline(read,part),getline(read,a3),getline(read,g3),getline(read,c3),getline(read,ex),getline(read,a4),getline(read,g4),getline(read,c4),getline(read,fin),getline(read,at),getline(read,at1),getline(read,at2),getline(read,at3),getline(read,q),getline(read,q1),getline(read,q2),getline(read,q3),getline(read,p),getline(read,p1),getline(read,p2),getline(read,p3),getline(read,e),getline(read,e1),getline(read,e2),getline(read,e3))
	{
		if(Cname==name)
		{
			cout<<"\t\t\t\t\t==============================="<<endl<<endl;
			cout<<"\t\t\t\t\t     ALREADY ON THE LISTS! "<<endl<<endl;
			cout<<"\t\t\t\t\t==============================="<<endl<<endl;
			count=1;
		}
	}
	read.close();
	ofstream write(section.c_str(),ios::app);
	if(count==0)
	{
		write<<Cname<<endl;
		write<<"midterm"<<endl;
		write<<"attendance"<<endl;
		write<<"0"<<endl;
		write<<"0"<<endl;
		write<<"0"<<endl;
		write<<"quizzes"<<endl;
		write<<"0"<<endl;
		write<<"0"<<endl;
		write<<"0"<<endl;
		write<<"participation"<<endl;
		write<<"0"<<endl;
		write<<"0"<<endl;
		write<<"0"<<endl;
		write<<"exam"<<endl;
		write<<"0"<<endl;
		write<<"0"<<endl;
		write<<"0"<<endl;
		write<<"finals"<<endl;
		write<<"attendance"<<endl;
		write<<"0"<<endl;
		write<<"0"<<endl;
		write<<"0"<<endl;
		write<<"quizzes"<<endl;
		write<<"0"<<endl;
		write<<"0"<<endl;
		write<<"0"<<endl;
		write<<"participation"<<endl;
		write<<"0"<<endl;
		write<<"0"<<endl;
		write<<"0"<<endl;
		write<<"exam"<<endl;
		write<<"0"<<endl;
		write<<"0"<<endl;
		write<<"0"<<endl;
		
		cout<<"\t\t\t\t\t==============================="<<endl<<endl;
		cout<<"\t\t\t\t\t\tADDED SUCCESSFULLY! "<<endl<<endl;
		cout<<"\t\t\t\t\t==============================="<<endl<<endl;
	}
	write.close();
	
	system("pause");
	
}

void displayrecords(int &action)
{
	system("cls");
	cout<<endl<<endl<<endl;
	cout<<"\t\t\t\t\t==============ADD RECORDS=============="<<endl<<endl;
	cout<<"\t\t\t\t\t             1 =ATTENDANCE             "<<endl;
	cout<<"\t\t\t\t\t              2 =QUIZZES               "<<endl;
	cout<<"\t\t\t\t\t           3 =PARTICIPATION            "<<endl;
	cout<<"\t\t\t\t\t               4 =EXAM                 "<<endl;
	cout<<"\t\t\t\t\t               5 =BACK                 "<<endl<<endl;
	cout<<"\t\t\t\t\t======================================="<<endl<<endl;
	cout<<"\t\t\t\t\t                 ==> ";
	cin>>action;
	
	
}

void attendance(string section)
{
	system("cls");
	section=section+".txt";
	ifstream read(section.c_str());
	ofstream write("new.txt");
	string name,mids,atten,quiz,part,ex,a1,a2,a3,a4,g1,g2,g3,g4,c1,c2,c3,c4;
	string fin,at,at1,at2,at3,q,q1,q2,q3,p,p1,p2,p3,e,e1,e2,e3;
	string check;
	cout<<endl<<endl<<endl;
	cout<<"\t\t\t\t\t                ATTENDANCE"<<endl;
	cout<<"\t\t\t\t\t========================================="<<endl;
	cout<<"\t\t\t\t\t =======1 IF PRESENT===0 IF ABSENT======"<<endl<<endl;
	while(getline(read,name),getline(read,mids),getline(read,atten),getline(read,a1),getline(read,g1),getline(read,c1),getline(read,quiz),getline(read,a2),getline(read,g2),getline(read,c2),getline(read,part),getline(read,a3),getline(read,g3),getline(read,c3),getline(read,ex),getline(read,a4),getline(read,g4),getline(read,c4),getline(read,fin),getline(read,at),getline(read,at1),getline(read,at2),getline(read,at3),getline(read,q),getline(read,q1),getline(read,q2),getline(read,q3),getline(read,p),getline(read,p1),getline(read,p2),getline(read,p3),getline(read,e),getline(read,e1),getline(read,e2),getline(read,e3))
	{
		double grade=0,count=0,add=0,temp;
		cout<<"\t\t\t\t\t\t"<<name<<": ";
		cin>>check;
		if(check=="1")
		{
			add=1;
		}
		a1=a1+" "+check;
		write<<name<<endl;
		write<<mids<<endl;
		write<<atten<<endl;
		write<<a1<<endl;
		stringstream geek(g1);
		geek>>grade;
		stringstream ano(c1);
		ano>>count;
		temp=(grade/100)*count;
		count=count+1;
		temp=temp+add;
		grade=(temp/count)*100;
		write<<grade<<endl;
		write<<count<<endl;
		write<<quiz<<endl;
		write<<a2<<endl;
		write<<g2<<endl;
		write<<c2<<endl;
		write<<part<<endl;
		write<<a3<<endl;
		write<<g3<<endl;
		write<<c3<<endl;
		write<<ex<<endl;
		write<<a4<<endl;
		write<<g4<<endl;
		write<<c4<<endl;	
		write<<fin<<endl;
		write<<at<<endl;
		write<<at1<<endl;
		write<<at2<<endl;
		write<<at3<<endl;
		write<<q<<endl;
		write<<q1<<endl;
		write<<q2<<endl;
		write<<q3<<endl;
		write<<p<<endl;
		write<<p1<<endl;
		write<<p2<<endl;
		write<<p3<<endl;
		write<<e<<endl;
		write<<e1<<endl;
		write<<e2<<endl;
		write<<e3<<endl;
	}
	cout<<endl<<"\t\t\t\t\t========================================="<<endl;
	system("pause");
	write.close();
	read.close();
	remove(section.c_str());
	rename("new.txt",section.c_str());
}

void quizzes(string section)
{
	system("cls");
	section=section+".txt";
	ifstream read(section.c_str());
	ofstream write("new.txt");
	string name,mids,atten,quiz,part,ex,a1,a2,a3,a4,g1,g2,g3,g4,c1,c2,c3,c4;
	string fin,at,at1,at2,at3,q,q1,q2,q3,p,p1,p2,p3,e,e1,e2,e3;
	string check;
	cout<<endl<<endl<<endl;
	cout<<"\t\t\t\t                       QUIZZES"<<endl;
	cout<<"\t\t\t\t======================================================"<<endl;
	cout<<"\t\t\t\t ===PLS INPUT THE SCORES PERCENTAGE IN TOTAL SCORE==="<<endl<<endl;
	while(getline(read,name),getline(read,mids),getline(read,atten),getline(read,a1),getline(read,g1),getline(read,c1),getline(read,quiz),getline(read,a2),getline(read,g2),getline(read,c2),getline(read,part),getline(read,a3),getline(read,g3),getline(read,c3),getline(read,ex),getline(read,a4),getline(read,g4),getline(read,c4),getline(read,fin),getline(read,at),getline(read,at1),getline(read,at2),getline(read,at3),getline(read,q),getline(read,q1),getline(read,q2),getline(read,q3),getline(read,p),getline(read,p1),getline(read,p2),getline(read,p3),getline(read,e),getline(read,e1),getline(read,e2),getline(read,e3))
	{
		double grade=0,count=0,temp;
		string score;
		double scores=0;
		cout<<"\t\t\t\t\t\t    "<<name<<": ";
		cin>>score;
		write<<name<<endl;
		write<<mids<<endl;
		write<<atten<<endl;
		write<<a1<<endl;
		write<<g1<<endl;
		write<<c1<<endl;
		stringstream geek(g2);
		geek>>grade;
		stringstream ano(c2);
		ano>>count;
		stringstream sc(score);
		sc>>scores;
		temp=(grade/100)*(count*100);
		count=count+1;
		temp=temp+scores;
		grade=(temp/(count*100))*100;
		write<<quiz<<endl;
		a2=a2+" "+ score;
		write<<a2<<endl;
		write<<grade<<endl;
		write<<count<<endl;
		write<<part<<endl;
		write<<a3<<endl;
		write<<g3<<endl;
		write<<c3<<endl;
		write<<ex<<endl;
		write<<a4<<endl;
		write<<g4<<endl;
		write<<c4<<endl;	
		write<<fin<<endl;
		write<<at<<endl;
		write<<at1<<endl;
		write<<at2<<endl;
		write<<at3<<endl;
		write<<q<<endl;
		write<<q1<<endl;
		write<<q2<<endl;
		write<<q3<<endl;
		write<<p<<endl;
		write<<p1<<endl;
		write<<p2<<endl;
		write<<p3<<endl;
		write<<e<<endl;
		write<<e1<<endl;
		write<<e2<<endl;
		write<<e3<<endl;
	}
	cout<<endl<<"\t\t\t\t======================================================="<<endl;
	system("pause");
	write.close();
	read.close();
	remove(section.c_str());
	rename("new.txt",section.c_str());
}

void participation(string section)
{
	system("cls");
	section=section+".txt";
	ifstream read(section.c_str());
	ofstream write("new.txt");
	string name,mids,atten,quiz,part,ex,a1,a2,a3,a4,g1,g2,g3,g4,c1,c2,c3,c4;
	string fin,at,at1,at2,at3,q,q1,q2,q3,p,p1,p2,p3,e,e1,e2,e3;
	string check;
	cout<<endl<<endl<<endl;
	cout<<"\t\t\t\t                      PARTICIPATION"<<endl;
	cout<<"\t\t\t\t======================================================"<<endl;
	cout<<"\t\t\t\t ===PLS INPUT THE SCORES PERCENTAGE IN TOTAL SCORE==="<<endl<<endl;
	while(getline(read,name),getline(read,mids),getline(read,atten),getline(read,a1),getline(read,g1),getline(read,c1),getline(read,quiz),getline(read,a2),getline(read,g2),getline(read,c2),getline(read,part),getline(read,a3),getline(read,g3),getline(read,c3),getline(read,ex),getline(read,a4),getline(read,g4),getline(read,c4),getline(read,fin),getline(read,at),getline(read,at1),getline(read,at2),getline(read,at3),getline(read,q),getline(read,q1),getline(read,q2),getline(read,q3),getline(read,p),getline(read,p1),getline(read,p2),getline(read,p3),getline(read,e),getline(read,e1),getline(read,e2),getline(read,e3))
	{
		double grade=0,count=0,temp;
		string score;
		double scores=0;
		cout<<"\t\t\t\t\t\t    "<<name<<": ";
		cin>>score;
		write<<name<<endl;
		write<<mids<<endl;
		write<<atten<<endl;
		write<<a1<<endl;
		write<<g1<<endl;
		write<<c1<<endl;
		write<<quiz<<endl;
		write<<a2<<endl;
		write<<g2<<endl;
		write<<c2<<endl;
		stringstream geek(g3);
		geek>>grade;
		stringstream ano(c3);
		ano>>count;
		stringstream sc(score);
		sc>>scores;
		temp=(grade/100)*(count*100);
		count=count+1;
		temp=temp+scores;
		grade=(temp/(count*100))*100;
		a3=a3+" "+ score;
		write<<part<<endl;
		write<<a3<<endl;
		write<<grade<<endl;
		write<<count<<endl;
		write<<ex<<endl;
		write<<a4<<endl;
		write<<g4<<endl;
		write<<c4<<endl;
		write<<fin<<endl;
		write<<at<<endl;
		write<<at1<<endl;
		write<<at2<<endl;
		write<<at3<<endl;
		write<<q<<endl;
		write<<q1<<endl;
		write<<q2<<endl;
		write<<q3<<endl;
		write<<p<<endl;
		write<<p1<<endl;
		write<<p2<<endl;
		write<<p3<<endl;
		write<<e<<endl;
		write<<e1<<endl;
		write<<e2<<endl;
		write<<e3<<endl;	
	}
	cout<<endl<<"\t\t\t\t======================================================"<<endl;
	system("pause");
	write.close();
	read.close();
	remove(section.c_str());
	rename("new.txt",section.c_str());
}

void exam(string section)
{
	system("cls");
	section=section+".txt";
	ifstream read(section.c_str());
	ofstream write("new.txt");
	string name,mids,atten,quiz,part,ex,a1,a2,a3,a4,g1,g2,g3,g4,c1,c2,c3,c4;
	string fin,at,at1,at2,at3,q,q1,q2,q3,p,p1,p2,p3,e,e1,e2,e3;
	string check;
	cout<<endl<<endl<<endl;
	cout<<"\t\t\t\t                      MAJOR EXAM"<<endl;
	cout<<"\t\t\t\t======================================================"<<endl;
	cout<<"\t\t\t\t ===PLS INPUT THE SCORES PERCENTAGE IN TOTAL SCORE==="<<endl<<endl;
	while(getline(read,name),getline(read,mids),getline(read,atten),getline(read,a1),getline(read,g1),getline(read,c1),getline(read,quiz),getline(read,a2),getline(read,g2),getline(read,c2),getline(read,part),getline(read,a3),getline(read,g3),getline(read,c3),getline(read,ex),getline(read,a4),getline(read,g4),getline(read,c4),getline(read,fin),getline(read,at),getline(read,at1),getline(read,at2),getline(read,at3),getline(read,q),getline(read,q1),getline(read,q2),getline(read,q3),getline(read,p),getline(read,p1),getline(read,p2),getline(read,p3),getline(read,e),getline(read,e1),getline(read,e2),getline(read,e3))
	{
		double grade=0,count=0,temp;
		string score;
		double scores=0;
		cout<<"\t\t\t\t\t\t    "<<name<<": ";
		cin>>score;
		write<<name<<endl;
		write<<mids<<endl;
		write<<atten<<endl;
		write<<a1<<endl;
		write<<g1<<endl;
		write<<c1<<endl;
		write<<quiz<<endl;
		write<<a2<<endl;
		write<<g2<<endl;
		write<<c2<<endl;
		write<<part<<endl;
		write<<a3<<endl;
		write<<g3<<endl;
		write<<c3<<endl;
		stringstream geek(g4);
		geek>>grade;
		stringstream ano(c4);
		ano>>count;
		stringstream sc(score);
		sc>>scores;
		temp=(grade/100)*(count*100);
		count=count+1;
		temp=temp+scores;
		grade=(temp/(count*100))*100;
		a4=a4+" "+ score;
		write<<ex<<endl;
		write<<a4<<endl;
		write<<grade<<endl;
		write<<count<<endl;
		write<<fin<<endl;
		write<<at<<endl;
		write<<at1<<endl;
		write<<at2<<endl;
		write<<at3<<endl;
		write<<q<<endl;
		write<<q1<<endl;
		write<<q2<<endl;
		write<<q3<<endl;
		write<<p<<endl;
		write<<p1<<endl;
		write<<p2<<endl;
		write<<p3<<endl;
		write<<e<<endl;
		write<<e1<<endl;
		write<<e2<<endl;
		write<<e3<<endl;
	}
	cout<<endl<<"\t\t\t\t======================================================"<<endl;
	system("pause");
	write.close();
	read.close();
	remove(section.c_str());
	rename("new.txt",section.c_str());
}

void edit(string section)
{
	system("cls");
	string student,newname;
	cout<<endl<<endl<<endl;
	cin.ignore();
	cout<<"\t\t\t\t                     EDIT STUDENTS' NAME"<<endl;
	cout<<"\t\t\t\t======================================================"<<endl<<endl;
	cout<<"\t\t\t\t      STUDENTS OLD NAME: ";
	getline(cin,student);
	cout<<endl<<"\t\t\t\t======================================================"<<endl<<endl;
	section=section+".txt";
	ifstream read(section.c_str());
	ofstream write("new.txt");
	string name,mids,atten,quiz,part,ex,a1,a2,a3,a4,g1,g2,g3,g4,c1,c2,c3,c4;
	string fin,at,at1,at2,at3,q,q1,q2,q3,p,p1,p2,p3,e,e1,e2,e3;
	int count=0;
	while(getline(read,name),getline(read,mids),getline(read,atten),getline(read,a1),getline(read,g1),getline(read,c1),getline(read,quiz),getline(read,a2),getline(read,g2),getline(read,c2),getline(read,part),getline(read,a3),getline(read,g3),getline(read,c3),getline(read,ex),getline(read,a4),getline(read,g4),getline(read,c4),getline(read,fin),getline(read,at),getline(read,at1),getline(read,at2),getline(read,at3),getline(read,q),getline(read,q1),getline(read,q2),getline(read,q3),getline(read,p),getline(read,p1),getline(read,p2),getline(read,p3),getline(read,e),getline(read,e1),getline(read,e2),getline(read,e3))
	{
		if(name==student)
		{
			cout<<"\t\t\t\t======================================================"<<endl<<endl;
			cout<<"\t\t\t\t      STUDENTS' NEW NAME: ";
			getline(cin,newname);
			cout<<endl<<"\t\t\t\t======================================================"<<endl<<endl;
			name=newname;
			count=1;
			cout<<"\t\t\t\t======================================================"<<endl<<endl;
			cout<<"\t\t\t\t                 EDITED SUCCESSFULLY!      "<<endl<<endl;
			cout<<"\t\t\t\t======================================================"<<endl<<endl;
		}
		write<<name<<endl;
		write<<mids<<endl;
		write<<atten<<endl;
		write<<a1<<endl;
		write<<g1<<endl;
		write<<c1<<endl;
		write<<quiz<<endl;
		write<<a2<<endl;
		write<<g2<<endl;
		write<<c2<<endl;
		write<<part<<endl;
		write<<a3<<endl;
		write<<g3<<endl;
		write<<c3<<endl;
		write<<ex<<endl;
		write<<a4<<endl;
		write<<g4<<endl;
		write<<c4<<endl;
		write<<fin<<endl;
		write<<at<<endl;
		write<<at1<<endl;
		write<<at2<<endl;
		write<<at3<<endl;
		write<<q<<endl;
		write<<q1<<endl;
		write<<q2<<endl;
		write<<q3<<endl;
		write<<p<<endl;
		write<<p1<<endl;
		write<<p2<<endl;
		write<<p3<<endl;
		write<<e<<endl;
		write<<e1<<endl;
		write<<e2<<endl;
		write<<e3<<endl;
	}
	write.close();
	read.close();
	remove(section.c_str());
	rename("new.txt",section.c_str());
	if(count==0)
	{
		cout<<"\t\t\t\t======================================================"<<endl<<endl;
		cout<<"\t\t\t\t                     NO RECORD!      "<<endl<<endl;
		cout<<"\t\t\t\t======================================================"<<endl<<endl;
	}
	system("pause");
}

void delet(string section)
{
	system("cls");
	string student;
	cin.ignore();
	cout<<endl<<endl<<endl;
	cout<<"\t\t\t\t                   DELETE STUDENTS' NAME"<<endl;
	cout<<"\t\t\t\t======================================================"<<endl<<endl;
	cout<<"\t\t\t\t      STUDENTS NAME: ";
	getline(cin,student);
	cout<<endl<<"\t\t\t\t======================================================"<<endl<<endl;
	section=section+".txt";
	ifstream read(section.c_str());
	ofstream write("new.txt");
	string name,mids,atten,quiz,part,ex,a1,a2,a3,a4,g1,g2,g3,g4,c1,c2,c3,c4;
	string fin,at,at1,at2,at3,q,q1,q2,q3,p,p1,p2,p3,e,e1,e2,e3;
	int count=0;
	while(getline(read,name),getline(read,mids),getline(read,atten),getline(read,a1),getline(read,g1),getline(read,c1),getline(read,quiz),getline(read,a2),getline(read,g2),getline(read,c2),getline(read,part),getline(read,a3),getline(read,g3),getline(read,c3),getline(read,ex),getline(read,a4),getline(read,g4),getline(read,c4),getline(read,fin),getline(read,at),getline(read,at1),getline(read,at2),getline(read,at3),getline(read,q),getline(read,q1),getline(read,q2),getline(read,q3),getline(read,p),getline(read,p1),getline(read,p2),getline(read,p3),getline(read,e),getline(read,e1),getline(read,e2),getline(read,e3))
	{
		if(name!=student)
		{
			write<<name<<endl;
			write<<mids<<endl;
			write<<atten<<endl;
			write<<a1<<endl;
			write<<g1<<endl;
			write<<c1<<endl;
			write<<quiz<<endl;
			write<<a2<<endl;
			write<<g2<<endl;
			write<<c2<<endl;
			write<<part<<endl;
			write<<a3<<endl;
			write<<g3<<endl;
			write<<c3<<endl;
			write<<ex<<endl;
			write<<a4<<endl;
			write<<g4<<endl;
			write<<c4<<endl;
			write<<fin<<endl;
			write<<at<<endl;
			write<<at1<<endl;
			write<<at2<<endl;
			write<<at3<<endl;
			write<<q<<endl;
			write<<q1<<endl;
			write<<q2<<endl;
			write<<q3<<endl;
			write<<p<<endl;
			write<<p1<<endl;
			write<<p2<<endl;
			write<<p3<<endl;
			write<<e<<endl;
			write<<e1<<endl;
			write<<e2<<endl;
			write<<e3<<endl;
		}
		else
		{
			cout<<"\t\t\t\t======================================================"<<endl<<endl;
			cout<<"\t\t\t\t                 DELETED SUCCESSFULLY!      "<<endl<<endl;
			cout<<"\t\t\t\t======================================================"<<endl<<endl;
			count=1;
		}
		
	}
	write.close();
	read.close();
	remove(section.c_str());
	rename("new.txt",section.c_str());
	if(count==0)
	{
		cout<<"\t\t\t\t======================================================"<<endl<<endl;
		cout<<"\t\t\t\t                     NO RECORD!      "<<endl<<endl;
		cout<<"\t\t\t\t======================================================"<<endl<<endl;
	}
	system("pause");
}
void viewRecordsMid(vector<Record> S)
{
	string name,mids,atten,quiz,part,ex,a1,a2,a3,a4,g1,g2,g3,g4,c1,c2,c3,c4;
	string fin,at,at1,at2,at3,q,q1,q2,q3,p,p1,p2,p3,e,e1,e2,e3;
	cout<<"							MID-TERM"<<endl;
	cout << left   
		<< setw(30) << "NAME"                   
        << setw(20) << "ATTENDACE"    
        << setw(20) << "QUIZZES"  
        << setw(20) << "PARTICIPATION"
		<< setw(20) << "MAJOR EXAM"<< endl;
	for(int i=0;i<S.size();i++)
	{
		cout << left   
		<< setw(30) << S[i].getName()              
        << setw(20) << S[i].getAttendance() 
        << setw(20) << S[i].getQuizzes()
        << setw(20) << S[i].getParticipation()
		<< setw(20) << S[i].getExam()<< endl;
	}
}

void load(string section,vector <Record> &S)
{
	S.clear();
	Record A;
	section=section+".txt";
	ifstream read(section.c_str());
	string name,mids,atten,quiz,part,ex,a1,a2,a3,a4,g1,g2,g3,g4,c1,c2,c3,c4;
	string fin,at,at1,at2,at3,q,q1,q2,q3,p,p1,p2,p3,e,e1,e2,e3;
	double gram,grqm,grpm,grem,graf,grqf,grpf,gref;
	while(getline(read,name),getline(read,mids),getline(read,atten),getline(read,a1),getline(read,g1),getline(read,c1),getline(read,quiz),getline(read,a2),getline(read,g2),getline(read,c2),getline(read,part),getline(read,a3),getline(read,g3),getline(read,c3),getline(read,ex),getline(read,a4),getline(read,g4),getline(read,c4),getline(read,fin),getline(read,at),getline(read,at1),getline(read,at2),getline(read,at3),getline(read,q),getline(read,q1),getline(read,q2),getline(read,q3),getline(read,p),getline(read,p1),getline(read,p2),getline(read,p3),getline(read,e),getline(read,e1),getline(read,e2),getline(read,e3))
	{
		stringstream a(g1);
		a>>gram;
		stringstream b(g2);
		b>>grqm;
		stringstream c(g3);
		c>>grpm;
		stringstream d(g4);
		d>>grem;
		stringstream s(at2);
		s>>graf;
		stringstream f(q2);
		f>>grqf;
		stringstream g(p2);
		g>>grpf;
		stringstream h(e2);
		h>>gref;
		A.setData(name,gram,grqm,grpm,grem,graf,grqf,grpf,gref);
		A.setScores(a1,a2,a3,a4,at1,q1,p1,e1);
		S.push_back(A);
	}
	read.close();
	
}

void searchAddAttendance(string section)
{
	system("cls");
	string stname;
	cin.ignore();
	cout<<endl<<endl<<endl;
	cout<<"\t\t\t\t\t========================================="<<endl<<endl;
	cout<<"\t\t\t\t\t   STUDENTS' NAME: ";
	getline(cin,stname);
	cout<<endl<<"\t\t\t\t\t========================================="<<endl;
	section=section+".txt";
	ifstream read(section.c_str());
	ofstream write("new.txt");
	string name,mids,atten,quiz,part,ex,a1,a2,a3,a4,g1,g2,g3,g4,c1,c2,c3,c4;
	string fin,at,at1,at2,at3,q,q1,q2,q3,p,p1,p2,p3,e,e1,e2,e3;
	string check;
	int c=0;
	while(getline(read,name),getline(read,mids),getline(read,atten),getline(read,a1),getline(read,g1),getline(read,c1),getline(read,quiz),getline(read,a2),getline(read,g2),getline(read,c2),getline(read,part),getline(read,a3),getline(read,g3),getline(read,c3),getline(read,ex),getline(read,a4),getline(read,g4),getline(read,c4),getline(read,fin),getline(read,at),getline(read,at1),getline(read,at2),getline(read,at3),getline(read,q),getline(read,q1),getline(read,q2),getline(read,q3),getline(read,p),getline(read,p1),getline(read,p2),getline(read,p3),getline(read,e),getline(read,e1),getline(read,e2),getline(read,e3))
	{
		write<<name<<endl;
		write<<mids<<endl;
		write<<atten<<endl;
		if(name==stname)
		{
			system("cls");
			cout<<endl<<endl<<endl;
			cout<<"\t\t\t\t\t                ATTENDANCE"<<endl;
			cout<<"\t\t\t\t\t========================================="<<endl;
			cout<<"\t\t\t\t\t =======1 IF PRESENT===0 IF ABSENT======"<<endl<<endl;
			double grade=0,count=0,add=0,temp;
			cout<<"\t\t\t\t\t   "<<name<<": ";
			cin>>check;
			if(check=="1")
			{
				add=1;
			}
			a1=a1+" "+check;
			write<<a1<<endl;
			stringstream geek(g1);
			geek>>grade;
			stringstream ano(c1);
			ano>>count;
			temp=(grade/100)*count;
			count=count+1;
			temp=temp+add;
			grade=(temp/count)*100;
			write<<grade<<endl;
			write<<count<<endl;
			cout<<endl<<"\t\t\t\t\t========================================="<<endl<<endl;
			cout<<"\t\t\t\t\t========================================="<<endl<<endl;
			cout<<"\t\t\t\t\t                 ADDED! "<<endl<<endl;
			cout<<"\t\t\t\t\t========================================="<<endl<<endl;
			c=1;
		
		}
		else
		{
			write<<a1<<endl;
			write<<g1<<endl;
			write<<c1<<endl;
		}
		write<<quiz<<endl;
		write<<a2<<endl;
		write<<g2<<endl;
		write<<c2<<endl;
		write<<part<<endl;
		write<<a3<<endl;
		write<<g3<<endl;
		write<<c3<<endl;
		write<<ex<<endl;
		write<<a4<<endl;
		write<<g4<<endl;
		write<<c4<<endl;	
		write<<fin<<endl;
		write<<at<<endl;
		write<<at1<<endl;
		write<<at2<<endl;
		write<<at3<<endl;
		write<<q<<endl;
		write<<q1<<endl;
		write<<q2<<endl;
		write<<q3<<endl;
		write<<p<<endl;
		write<<p1<<endl;
		write<<p2<<endl;
		write<<p3<<endl;
		write<<e<<endl;
		write<<e1<<endl;
		write<<e2<<endl;
		write<<e3<<endl;
		
	}
	write.close();
	read.close();
	remove(section.c_str());
	rename("new.txt",section.c_str());
	if(c==0)
	{
		cout<<"\t\t\t\t\t========================================="<<endl<<endl;
		cout<<"\t\t\t\t\t                 NO RECORD! "<<endl<<endl;
		cout<<"\t\t\t\t\t========================================="<<endl<<endl;
	}
	system("pause");
}

void searchAddQuizzes(string section)
{
	system("cls");
	string stname;
	cin.ignore();
	cout<<endl<<endl<<endl;
	cout<<"\t\t\t\t======================================================"<<endl<<endl;
	cout<<"\t\t\t\t     STUDENTS' NAME: ";
	getline(cin,stname);
	cout<<"\t\t\t\t======================================================"<<endl;
	section=section+".txt";
	ifstream read(section.c_str());
	ofstream write("new.txt");
	string name,mids,atten,quiz,part,ex,a1,a2,a3,a4,g1,g2,g3,g4,c1,c2,c3,c4;
	string fin,at,at1,at2,at3,q,q1,q2,q3,p,p1,p2,p3,e,e1,e2,e3;
	string check;
	int c=0;
	while(getline(read,name),getline(read,mids),getline(read,atten),getline(read,a1),getline(read,g1),getline(read,c1),getline(read,quiz),getline(read,a2),getline(read,g2),getline(read,c2),getline(read,part),getline(read,a3),getline(read,g3),getline(read,c3),getline(read,ex),getline(read,a4),getline(read,g4),getline(read,c4),getline(read,fin),getline(read,at),getline(read,at1),getline(read,at2),getline(read,at3),getline(read,q),getline(read,q1),getline(read,q2),getline(read,q3),getline(read,p),getline(read,p1),getline(read,p2),getline(read,p3),getline(read,e),getline(read,e1),getline(read,e2),getline(read,e3))
	{
		
		write<<name<<endl;
		write<<mids<<endl;
		write<<atten<<endl;
		write<<a1<<endl;
		write<<g1<<endl;
		write<<c1<<endl;
		write<<quiz<<endl;
		if(stname==name)
		{
			system("cls");
			cout<<endl<<endl<<endl;
			cout<<"\t\t\t\t                       QUIZZES"<<endl;
			cout<<"\t\t\t\t======================================================"<<endl;
			cout<<"\t\t\t\t ===PLS INPUT THE SCORES PERCENTAGE IN TOTAL SCORE==="<<endl<<endl;
			double grade=0,count=0,temp;
			string score;
			double scores=0;
			cout<<"\t\t\t\t          "<<name<<": ";
			cin>>score;
			stringstream geek(g2);
			geek>>grade;
			stringstream ano(c2);
			ano>>count;
			stringstream sc(score);
			sc>>scores;
			temp=(grade/100)*(count*100);
			count=count+1;
			temp=temp+scores;
			grade=(temp/(count*100))*100;
			a2=a2+" "+ score;
			write<<a2<<endl;
			write<<grade<<endl;
			write<<count<<endl;
			c=1;
			cout<<endl<<"\t\t\t\t======================================================"<<endl<<endl;
			cout<<"\t\t\t\t======================================================"<<endl<<endl;
			cout<<"\t\t\t\t                  ADDED SUCCESSFULLY!"<<endl<<endl;
			cout<<"\t\t\t\t======================================================"<<endl;
		}
		else
		{
			write<<a2<<endl;
			write<<g2<<endl;
			write<<c2<<endl;
		}
		write<<part<<endl;
		write<<a3<<endl;
		write<<g3<<endl;
		write<<c3<<endl;
		write<<ex<<endl;
		write<<a4<<endl;
		write<<g4<<endl;
		write<<c4<<endl;	
		write<<fin<<endl;
		write<<at<<endl;
		write<<at1<<endl;
		write<<at2<<endl;
		write<<at3<<endl;
		write<<q<<endl;
		write<<q1<<endl;
		write<<q2<<endl;
		write<<q3<<endl;
		write<<p<<endl;
		write<<p1<<endl;
		write<<p2<<endl;
		write<<p3<<endl;
		write<<e<<endl;
		write<<e1<<endl;
		write<<e2<<endl;
		write<<e3<<endl;
	}
	write.close();
	read.close();
	remove(section.c_str());
	rename("new.txt",section.c_str());
	if(c==0)
	{
		cout<<"\t\t\t\t======================================================"<<endl<<endl;
		cout<<"\t\t\t\t                    NO RECORD!"<<endl<<endl;
		cout<<"\t\t\t\t======================================================"<<endl;
	}
	system("pause");
}

void searchAddParticipation(string section)
{
	system("cls");
	string stname;
	cin.ignore();
	cout<<endl<<endl<<endl;
	cout<<"\t\t\t\t======================================================"<<endl<<endl;
	cout<<"\t\t\t\t     STUDENTS' NAME: ";
	getline(cin,stname);
	cout<<"\t\t\t\t======================================================"<<endl<<endl;
	section=section+".txt";
	ifstream read(section.c_str());
	ofstream write("new.txt");
	string name,mids,atten,quiz,part,ex,a1,a2,a3,a4,g1,g2,g3,g4,c1,c2,c3,c4;
	string fin,at,at1,at2,at3,q,q1,q2,q3,p,p1,p2,p3,e,e1,e2,e3;
	string check;
	int c=0;
	while(getline(read,name),getline(read,mids),getline(read,atten),getline(read,a1),getline(read,g1),getline(read,c1),getline(read,quiz),getline(read,a2),getline(read,g2),getline(read,c2),getline(read,part),getline(read,a3),getline(read,g3),getline(read,c3),getline(read,ex),getline(read,a4),getline(read,g4),getline(read,c4),getline(read,fin),getline(read,at),getline(read,at1),getline(read,at2),getline(read,at3),getline(read,q),getline(read,q1),getline(read,q2),getline(read,q3),getline(read,p),getline(read,p1),getline(read,p2),getline(read,p3),getline(read,e),getline(read,e1),getline(read,e2),getline(read,e3))
	{
		write<<name<<endl;
		write<<mids<<endl;
		write<<atten<<endl;
		write<<a1<<endl;
		write<<g1<<endl;
		write<<c1<<endl;
		write<<quiz<<endl;
		write<<a2<<endl;
		write<<g2<<endl;
		write<<c2<<endl;
		write<<part<<endl;
		if(stname==name)
		{
			system("cls");
			cout<<endl<<endl<<endl;
			cout<<"\t\t\t\t                      PARTICIPATION"<<endl;
			cout<<"\t\t\t\t======================================================"<<endl;
			cout<<"\t\t\t\t ===PLS INPUT THE SCORES PERCENTAGE IN TOTAL SCORE==="<<endl<<endl;
			double grade=0,count=0,temp;
			string score;
			double scores=0;
			cout<<"\t\t\t\t         "<<name<<": ";
			cin>>score;
			stringstream geek(g3);
			geek>>grade;
			stringstream ano(c3);
			ano>>count;
			stringstream sc(score);
			sc>>scores;
			temp=(grade/100)*(count*100);
			count=count+1;
			temp=temp+scores;
			grade=(temp/(count*100))*100;
			a3=a3+" "+ score;
			write<<a3<<endl;
			write<<grade<<endl;
			write<<count<<endl;
			c=1;
			cout<<endl<<"\t\t\t\t======================================================"<<endl;
			cout<<"\t\t\t\t======================================================"<<endl<<endl;
			cout<<"\t\t\t\t                  ADDED SUCCESSFULLY!"<<endl<<endl;
			cout<<"\t\t\t\t======================================================"<<endl;
		}
		else
		{
			write<<a3<<endl;
			write<<g3<<endl;
			write<<c3<<endl;
		}
		write<<ex<<endl;
		write<<a4<<endl;
		write<<g4<<endl;
		write<<c4<<endl;
		write<<fin<<endl;
		write<<at<<endl;
		write<<at1<<endl;
		write<<at2<<endl;
		write<<at3<<endl;
		write<<q<<endl;
		write<<q1<<endl;
		write<<q2<<endl;
		write<<q3<<endl;
		write<<p<<endl;
		write<<p1<<endl;
		write<<p2<<endl;
		write<<p3<<endl;
		write<<e<<endl;
		write<<e1<<endl;
		write<<e2<<endl;
		write<<e3<<endl;	
	}
	write.close();
	read.close();
	remove(section.c_str());
	rename("new.txt",section.c_str());
	if(c==0)
	{
		cout<<"\t\t\t\t======================================================"<<endl<<endl;
		cout<<"\t\t\t\t                    NO RECORD!"<<endl<<endl;
		cout<<"\t\t\t\t======================================================"<<endl;
	}
	system("pause");
}

void searchAddExam(string section)
{
	system("cls");
	string stname;
	cin.ignore();
	cout<<endl<<endl<<endl;
	cout<<"\t\t\t\t======================================================"<<endl<<endl;
	cout<<"\t\t\t\t     STUDENTS' NAME: ";
	getline(cin,stname);
	cout<<"\t\t\t\t======================================================"<<endl<<endl;
	section=section+".txt";
	ifstream read(section.c_str());
	ofstream write("new.txt");
	string name,mids,atten,quiz,part,ex,a1,a2,a3,a4,g1,g2,g3,g4,c1,c2,c3,c4;
	string fin,at,at1,at2,at3,q,q1,q2,q3,p,p1,p2,p3,e,e1,e2,e3;
	string check;
	int c=0;
	while(getline(read,name),getline(read,mids),getline(read,atten),getline(read,a1),getline(read,g1),getline(read,c1),getline(read,quiz),getline(read,a2),getline(read,g2),getline(read,c2),getline(read,part),getline(read,a3),getline(read,g3),getline(read,c3),getline(read,ex),getline(read,a4),getline(read,g4),getline(read,c4),getline(read,fin),getline(read,at),getline(read,at1),getline(read,at2),getline(read,at3),getline(read,q),getline(read,q1),getline(read,q2),getline(read,q3),getline(read,p),getline(read,p1),getline(read,p2),getline(read,p3),getline(read,e),getline(read,e1),getline(read,e2),getline(read,e3))
	{
		write<<name<<endl;
		write<<mids<<endl;
		write<<atten<<endl;
		write<<a1<<endl;
		write<<g1<<endl;
		write<<c1<<endl;
		write<<quiz<<endl;
		write<<a2<<endl;
		write<<g2<<endl;
		write<<c2<<endl;
		write<<part<<endl;
		write<<a3<<endl;
		write<<g3<<endl;
		write<<c3<<endl;
		write<<ex<<endl;
		if(stname==name)
		{
			system("cls");
			cout<<endl<<endl<<endl;
			cout<<"\t\t\t\t                      MAJOR EXAM"<<endl;
			cout<<"\t\t\t\t======================================================"<<endl;
			cout<<"\t\t\t\t ===PLS INPUT THE SCORES PERCENTAGE IN TOTAL SCORE==="<<endl<<endl;
			double grade=0,count=0,temp;
			string score;
			double scores=0;
			cout<<"\t\t\t\t        "<<name<<": ";
			cin>>score;
			stringstream geek(g4);
			geek>>grade;
			stringstream ano(c4);
			ano>>count;
			stringstream sc(score);
			sc>>scores;
			temp=(grade/100)*(count*100);
			count=count+1;
			temp=temp+scores;
			grade=(temp/(count*100))*100;
			a4=a4+" "+ score;
			write<<a4<<endl;
			write<<grade<<endl;
			write<<count<<endl;
			cout<<endl<<"\t\t\t\t======================================================"<<endl;
			cout<<"\t\t\t\t======================================================"<<endl<<endl;
			cout<<"\t\t\t\t                  ADDED SUCCESSFULLY!"<<endl<<endl;
			cout<<"\t\t\t\t======================================================"<<endl;
			c=1;
		}
		else
		{
			write<<a4<<endl;
			write<<g4<<endl;
			write<<c4<<endl;
		}
		write<<fin<<endl;
		write<<at<<endl;
		write<<at1<<endl;
		write<<at2<<endl;
		write<<at3<<endl;
		write<<q<<endl;
		write<<q1<<endl;
		write<<q2<<endl;
		write<<q3<<endl;
		write<<p<<endl;
		write<<p1<<endl;
		write<<p2<<endl;
		write<<p3<<endl;
		write<<e<<endl;
		write<<e1<<endl;
		write<<e2<<endl;
		write<<e3<<endl;
	}
	write.close();
	read.close();
	remove(section.c_str());
	rename("new.txt",section.c_str());
	if(c==0)
	{
		cout<<"\t\t\t\t======================================================"<<endl<<endl;
		cout<<"\t\t\t\t                    NO RECORD!"<<endl<<endl;
		cout<<"\t\t\t\t======================================================"<<endl;
	}
	system("pause");
}

void searchRecord(vector <Record> S)
{
	system("cls");
	string name,a1,a2,a3,a4;
	string a,q,p,e;
	cin.ignore();
	cout<<endl<<endl<<endl;
	cout<<"\t\t\t\t\t         SEARCH RECORD         "<<endl;
	cout<<"\t\t\t\t\t==============================="<<endl<<endl;
	cout<<"\t\t\t\t\t  STUDENTS' NAME: ";
	getline(cin,name);
	cout<<endl<<"\t\t\t\t\t==============================="<<endl<<endl;
	int c=0;
	for(int i=0;i<S.size();i++)
	{
		if(name==S[i].getName())
		{
			a1=S[i].getMsa();
			for(int b=0;b+2<a1.size();b++)
			{
				a.push_back(a1[b+2]);
			}
			a2=S[i].getMsq();
			for(int b=0;b+2<a2.size();b++)
			{
				q.push_back(a2[b+2]);
			}
			a3=S[i].getMsp();
			for(int b=0;b+2<a3.size();b++)
			{
				p.push_back(a3[b+2]);
			}
			a4=S[i].getMse();
			for(int b=0;b+2<a4.size();b++)
			{
				e.push_back(a4[b+2]);
			}
			system("cls");
			cout<<endl<<endl<<endl;
			cout<<"							MID-TERM"<<endl;
			cout<<"\t\t\t\t\t======================================"<<endl<<endl;
			cout<<"							"<<S[i].getName()<<endl;
			cout<< right                
	        	<< setw(60) << "ATTENDACE: "   
				<<a<<endl
				<<setw(60)<<"GRADE: "
				<<S[i].getAttendance()<<endl
	        	<< setw(60) << "QUIZZES: "  
	        	<<q<<endl
	        	<<setw(60)<<"GRADE: "
	        	<<S[i].getQuizzes()<<endl
	       		<< setw(60) << "PARTICIPATION: "
	       		<<p<<endl
	       		<<setw(60)<<"GRADE: "
	       		<<S[i].getParticipation()<<endl
			   	<< setw(60) << "MAJOR EXAM: "
			   	<<e<<endl
			   	<<setw(60)<<"GRADE: "
			   	<<S[i].getExam()<<endl<<endl;
			cout<<"\t\t\t\t\t======================================"<<endl<<endl;
			c=1;
		}
	}
	if(c==0)
	{
		cout<<"\t\t\t\t\t==============================="<<endl<<endl;
		cout<<"\t\t\t\t\t           NO RECORD "<<endl<<endl;
		cout<<"\t\t\t\t\t==============================="<<endl<<endl;
	}
	system("pause");
}

void computeGrades(vector <Record> S)
{
	int ch;
	system("cls");
	cout<<endl<<endl<<endl;
	cout<<"\t\t\t\t\t==============================="<<endl<<endl;
	cout<<"\t\t\t\t\t           1 =ALL"<<endl;
	cout<<"\t\t\t\t\t          2 =SEARCH"<<endl;
	cout<<"\t\t\t\t\t           3 =BACK"<<endl;
	cout<<endl<<"\t\t\t\t\t==============================="<<endl;
	cout<<"\t\t\t\t\t             ==> ";
	cin>>ch;
	while(ch!=3)
	{
		switch(ch)
		{
			case 1:
				system("cls");
				cout<<endl<<endl<<endl;
				cout<<"\t\t\t\t\t        MID-TERM GRADES"<<endl;
				cout<<"\t\t\t\t\t==============================="<<endl<<endl;
				for(int i=0;i<S.size();i++)
				{
					double a,q,p,e,grade;
					a=S[i].getAttendance();
					q=S[i].getQuizzes();
					p=S[i].getParticipation();
					e=S[i].getExam();
					a=(a/100)*10;
					q=(q/100)*20;
					p=(p/100)*40;
					e=(e/100)*30;
					grade=a+q+p+e;
					cout<<"\t\t\t\t\t     "<<S[i].getName()<<": "<<grade<<endl;
				}
				cout<<endl<<"\t\t\t\t\t==============================="<<endl<<endl;
				system("pause");
				break;
			case 2:
				system("cls");
				string name;
				cin.ignore();
				cout<<endl<<endl<<endl;
				cout<<"\t\t\t\t\t==============================="<<endl<<endl;
				cout<<"\t\t\t\t\t STUDENTS' NAME: ";
				getline(cin,name);
				cout<<endl;
				cout<<"\t\t\t\t\t==============================="<<endl<<endl;
				int count=0;
				system("cls");
				cout<<endl<<endl<<endl;
				cout<<"\t\t\t\t\t        MID-TERM GRADES"<<endl;
				cout<<"\t\t\t\t\t==============================="<<endl<<endl;
				for(int i=0;i<S.size();i++)
				{
					if(name==S[i].getName())
					{
						double a,q,p,e,grade;
						a=S[i].getAttendance();
						q=S[i].getQuizzes();
						p=S[i].getParticipation();
						e=S[i].getExam();
						a=q*.10;
						q=q*.20;
						p=p*.40;
						e=e*.30;
						grade=a+q+p+e;
						cout<<"\t\t\t\t\t     "<<S[i].getName()<<": "<<grade<<endl;
						count=1;
						cout<<endl<<"\t\t\t\t\t==============================="<<endl<<endl;
					}
					
				}
				if(count==0)
				{
					cout<<"\t\t\t\t\t==============================="<<endl<<endl;
					cout<<"\t\t\t\t\t           NO RECORD "<<endl<<endl;
					cout<<"\t\t\t\t\t==============================="<<endl<<endl;
				}
				system("pause");
				break;
				
		}
		system("cls");
		cout<<endl<<endl<<endl;
		cout<<"\t\t\t\t\t==============================="<<endl<<endl;
		cout<<"\t\t\t\t\t           1 =ALL"<<endl;
		cout<<"\t\t\t\t\t          2 =SEARCH"<<endl;
		cout<<"\t\t\t\t\t           3 =BACK"<<endl;
		cout<<endl<<"\t\t\t\t\t==============================="<<endl;
		cout<<"\t\t\t\t\t             ==> ";
		cin>>ch;
	}
}

void viewRecordsFinal(vector<Record> S)
{
	string name,mids,atten,quiz,part,ex,a1,a2,a3,a4,g1,g2,g3,g4,c1,c2,c3,c4;
	string fin,at,at1,at2,at3,q,q1,q2,q3,p,p1,p2,p3,e,e1,e2,e3;
	cout<<"							FINALS"<<endl;
	cout << left   
		<< setw(30) << "NAME"                   
        << setw(20) << "ATTENDACE"    
        << setw(20) << "QUIZZES"  
        << setw(20) << "PARTICIPATION"
		<< setw(20) << "MAJOR EXAM"<< endl;
	for(int i=0;i<S.size();i++)
	{
		cout << left   
		<< setw(30) << S[i].getName()              
        << setw(20) << S[i].getFAttendance() 
        << setw(20) << S[i].getFQuizzes()
        << setw(20) << S[i].getFParticipation()
		<< setw(20) << S[i].getFExam()<< endl;
	}
}

void displayFinal(int &act)
{
	cout<<endl<<endl<<endl;
	cout<<"\t\t\t\t\t======================================"<<endl<<endl;
	cout<<"\t\t\t\t\t          1 =ADD RECORDS              "<<endl;
	cout<<"\t\t\t\t\t       2 =EDIT STUDENTS' NAME         "<<endl;
	cout<<"\t\t\t\t\t     3 =DELETE STUDENTS' RECORD       "<<endl;
	cout<<"\t\t\t\t\t         4 =SEARCH RECORD             "<<endl;
	cout<<"\t\t\t\t\t       5 =COMPUTE FINAL GRADES        "<<endl;
	cout<<"\t\t\t\t\t     6 =COMPUTE SEMESTRAL GRADES      "<<endl;
	cout<<"\t\t\t\t\t               7 =BACK                "<<endl<<endl;
	cout<<"\t\t\t\t\t======================================"<<endl;
	cout<<"\t\t\t\t\t                 ==> ";
	cin>>act;
}

void attendanceFinal(string section)
{
	system("cls");
	section=section+".txt";
	ifstream read(section.c_str());
	ofstream write("new.txt");
	string name,mids,atten,quiz,part,ex,a1,a2,a3,a4,g1,g2,g3,g4,c1,c2,c3,c4;
	string fin,at,at1,at2,at3,q,q1,q2,q3,p,p1,p2,p3,e,e1,e2,e3;
	string check;
	cout<<endl<<endl<<endl;
	cout<<"\t\t\t\t\t                ATTENDANCE"<<endl;
	cout<<"\t\t\t\t\t========================================="<<endl;
	cout<<"\t\t\t\t\t =======1 IF PRESENT===0 IF ABSENT======"<<endl<<endl;
	while(getline(read,name),getline(read,mids),getline(read,atten),getline(read,a1),getline(read,g1),getline(read,c1),getline(read,quiz),getline(read,a2),getline(read,g2),getline(read,c2),getline(read,part),getline(read,a3),getline(read,g3),getline(read,c3),getline(read,ex),getline(read,a4),getline(read,g4),getline(read,c4),getline(read,fin),getline(read,at),getline(read,at1),getline(read,at2),getline(read,at3),getline(read,q),getline(read,q1),getline(read,q2),getline(read,q3),getline(read,p),getline(read,p1),getline(read,p2),getline(read,p3),getline(read,e),getline(read,e1),getline(read,e2),getline(read,e3))
	{
		double grade=0,count=0,add=0,temp;
		cout<<"\t\t\t\t\t\t"<<name<<": ";
		cin>>check;
		if(check=="1")
		{
			add=1;
		}
		write<<name<<endl;
		write<<mids<<endl;
		write<<atten<<endl;
		write<<a1<<endl;
		write<<g1<<endl;
		write<<c1<<endl;
		write<<quiz<<endl;
		write<<a2<<endl;
		write<<g2<<endl;
		write<<c2<<endl;
		write<<part<<endl;
		write<<a3<<endl;
		write<<g3<<endl;
		write<<c3<<endl;
		write<<ex<<endl;
		write<<a4<<endl;
		write<<g4<<endl;
		write<<c4<<endl;	
		write<<fin<<endl;
		at1=at1+" "+check;
		write<<at<<endl;
		write<<at1<<endl;
		stringstream geek(at2);
		geek>>grade;
		stringstream ano(at3);
		ano>>count;
		temp=(grade/100)*count;
		count=count+1;
		temp=temp+add;
		grade=(temp/count)*100;
		write<<grade<<endl;
		write<<count<<endl;
		write<<q<<endl;
		write<<q1<<endl;
		write<<q2<<endl;
		write<<q3<<endl;
		write<<p<<endl;
		write<<p1<<endl;
		write<<p2<<endl;
		write<<p3<<endl;
		write<<e<<endl;
		write<<e1<<endl;
		write<<e2<<endl;
		write<<e3<<endl;
	}
	cout<<endl<<"\t\t\t\t\t========================================="<<endl;
	system("pause");
	write.close();
	read.close();
	remove(section.c_str());
	rename("new.txt",section.c_str());
}

void quizzesFinal(string section)
{
	system("cls");
	section=section+".txt";
	ifstream read(section.c_str());
	ofstream write("new.txt");
	string name,mids,atten,quiz,part,ex,a1,a2,a3,a4,g1,g2,g3,g4,c1,c2,c3,c4;
	string fin,at,at1,at2,at3,q,q1,q2,q3,p,p1,p2,p3,e,e1,e2,e3;
	string check;
	cout<<endl<<endl<<endl;
	cout<<"\t\t\t\t                       QUIZZES"<<endl;
	cout<<"\t\t\t\t======================================================"<<endl;
	cout<<"\t\t\t\t ===PLS INPUT THE SCORES PERCENTAGE IN TOTAL SCORE==="<<endl<<endl;
	while(getline(read,name),getline(read,mids),getline(read,atten),getline(read,a1),getline(read,g1),getline(read,c1),getline(read,quiz),getline(read,a2),getline(read,g2),getline(read,c2),getline(read,part),getline(read,a3),getline(read,g3),getline(read,c3),getline(read,ex),getline(read,a4),getline(read,g4),getline(read,c4),getline(read,fin),getline(read,at),getline(read,at1),getline(read,at2),getline(read,at3),getline(read,q),getline(read,q1),getline(read,q2),getline(read,q3),getline(read,p),getline(read,p1),getline(read,p2),getline(read,p3),getline(read,e),getline(read,e1),getline(read,e2),getline(read,e3))
	{
		double grade=0,count=0,temp;
		string score;
		double scores=0;
		cout<<"\t\t\t\t\t\t    "<<name<<": ";
		cin>>score;
		write<<name<<endl;
		write<<mids<<endl;
		write<<atten<<endl;
		write<<a1<<endl;
		write<<g1<<endl;
		write<<c1<<endl;
		write<<quiz<<endl;
		write<<a2<<endl;
		write<<g2<<endl;
		write<<c2<<endl;
		write<<part<<endl;
		write<<a3<<endl;
		write<<g3<<endl;
		write<<c3<<endl;
		write<<ex<<endl;
		write<<a4<<endl;
		write<<g4<<endl;
		write<<c4<<endl;	
		write<<fin<<endl;
		write<<at<<endl;
		write<<at1<<endl;
		write<<at2<<endl;
		write<<at3<<endl;
		write<<q<<endl;
		q1=q1+" "+ score;
		write<<q1<<endl;
		stringstream geek(q2);
		geek>>grade;
		stringstream ano(q3);
		ano>>count;
		stringstream sc(score);
		sc>>scores;
		temp=(grade/100)*(count*100);
		count=count+1;
		temp=temp+scores;
		grade=(temp/(count*100))*100;
		write<<grade<<endl;
		write<<count<<endl;
		write<<p<<endl;
		write<<p1<<endl;
		write<<p2<<endl;
		write<<p3<<endl;
		write<<e<<endl;
		write<<e1<<endl;
		write<<e2<<endl;
		write<<e3<<endl;
	}
	cout<<endl<<"\t\t\t\t======================================================="<<endl;
	system("pause");
	write.close();
	read.close();
	remove(section.c_str());
	rename("new.txt",section.c_str());
}

void participationFinal(string section)
{
	system("cls");
	section=section+".txt";
	ifstream read(section.c_str());
	ofstream write("new.txt");
	string name,mids,atten,quiz,part,ex,a1,a2,a3,a4,g1,g2,g3,g4,c1,c2,c3,c4;
	string fin,at,at1,at2,at3,q,q1,q2,q3,p,p1,p2,p3,e,e1,e2,e3;
	string check;
	cout<<endl<<endl<<endl;
	cout<<"\t\t\t\t                      PARTICIPATION"<<endl;
	cout<<"\t\t\t\t======================================================"<<endl;
	cout<<"\t\t\t\t ===PLS INPUT THE SCORES PERCENTAGE IN TOTAL SCORE==="<<endl<<endl;
	while(getline(read,name),getline(read,mids),getline(read,atten),getline(read,a1),getline(read,g1),getline(read,c1),getline(read,quiz),getline(read,a2),getline(read,g2),getline(read,c2),getline(read,part),getline(read,a3),getline(read,g3),getline(read,c3),getline(read,ex),getline(read,a4),getline(read,g4),getline(read,c4),getline(read,fin),getline(read,at),getline(read,at1),getline(read,at2),getline(read,at3),getline(read,q),getline(read,q1),getline(read,q2),getline(read,q3),getline(read,p),getline(read,p1),getline(read,p2),getline(read,p3),getline(read,e),getline(read,e1),getline(read,e2),getline(read,e3))
	{
		double grade=0,count=0,temp;
		string score;
		double scores=0;
		cout<<"\t\t\t\t\t\t    "<<name<<": ";
		cin>>score;
		write<<name<<endl;
		write<<mids<<endl;
		write<<atten<<endl;
		write<<a1<<endl;
		write<<g1<<endl;
		write<<c1<<endl;
		write<<quiz<<endl;
		write<<a2<<endl;
		write<<g2<<endl;
		write<<c2<<endl;
		write<<part<<endl;
		write<<a3<<endl;
		write<<g3<<endl;
		write<<c3<<endl;
		write<<ex<<endl;
		write<<a4<<endl;
		write<<g4<<endl;
		write<<c4<<endl;
		write<<fin<<endl;
		write<<at<<endl;
		write<<at1<<endl;
		write<<at2<<endl;
		write<<at3<<endl;
		write<<q<<endl;
		write<<q1<<endl;
		write<<q2<<endl;
		write<<q3<<endl;
		write<<p<<endl;
		p1=p1+" "+ score;
		write<<p1<<endl;
		stringstream geek(p2);
		geek>>grade;
		stringstream ano(p3);
		ano>>count;
		stringstream sc(score);
		sc>>scores;
		temp=(grade/100)*(count*100);
		count=count+1;
		temp=temp+scores;
		grade=(temp/(count*100))*100;
		write<<grade<<endl;
		write<<count<<endl;
		write<<e<<endl;
		write<<e1<<endl;
		write<<e2<<endl;
		write<<e3<<endl;	
	}
	cout<<endl<<"\t\t\t\t======================================================"<<endl;
	system("pause");
	write.close();
	read.close();
	remove(section.c_str());
	rename("new.txt",section.c_str());
}

void examFinal(string section)
{
	system("cls");
	section=section+".txt";
	ifstream read(section.c_str());
	ofstream write("new.txt");
	string name,mids,atten,quiz,part,ex,a1,a2,a3,a4,g1,g2,g3,g4,c1,c2,c3,c4;
	string fin,at,at1,at2,at3,q,q1,q2,q3,p,p1,p2,p3,e,e1,e2,e3;
	string check;
	cout<<endl<<endl<<endl;
	cout<<"\t\t\t\t                      MAJOR EXAM"<<endl;
	cout<<"\t\t\t\t======================================================"<<endl;
	cout<<"\t\t\t\t ===PLS INPUT THE SCORES PERCENTAGE IN TOTAL SCORE==="<<endl<<endl;
	while(getline(read,name),getline(read,mids),getline(read,atten),getline(read,a1),getline(read,g1),getline(read,c1),getline(read,quiz),getline(read,a2),getline(read,g2),getline(read,c2),getline(read,part),getline(read,a3),getline(read,g3),getline(read,c3),getline(read,ex),getline(read,a4),getline(read,g4),getline(read,c4),getline(read,fin),getline(read,at),getline(read,at1),getline(read,at2),getline(read,at3),getline(read,q),getline(read,q1),getline(read,q2),getline(read,q3),getline(read,p),getline(read,p1),getline(read,p2),getline(read,p3),getline(read,e),getline(read,e1),getline(read,e2),getline(read,e3))
	{
		double grade=0,count=0,temp;
		string score;
		double scores=0;
		cout<<"\t\t\t\t\t\t    "<<name<<": ";
		cin>>score;
		write<<name<<endl;
		write<<mids<<endl;
		write<<atten<<endl;
		write<<a1<<endl;
		write<<g1<<endl;
		write<<c1<<endl;
		write<<quiz<<endl;
		write<<a2<<endl;
		write<<g2<<endl;
		write<<c2<<endl;
		write<<part<<endl;
		write<<a3<<endl;
		write<<g3<<endl;
		write<<c3<<endl;
		write<<ex<<endl;
		write<<a4<<endl;
		write<<g4<<endl;
		write<<c4<<endl;
		write<<fin<<endl;
		write<<at<<endl;
		write<<at1<<endl;
		write<<at2<<endl;
		write<<at3<<endl;
		write<<q<<endl;
		write<<q1<<endl;
		write<<q2<<endl;
		write<<q3<<endl;
		write<<p<<endl;
		write<<p1<<endl;
		write<<p2<<endl;
		write<<p3<<endl;
		stringstream geek(e2);
		geek>>grade;
		stringstream ano(e3);
		ano>>count;
		stringstream sc(score);
		sc>>scores;
		temp=(grade/100)*(count*100);
		count=count+1;
		temp=temp+scores;
		grade=(temp/(count*100))*100;
		e1=e1+" "+ score;
		write<<e<<endl;
		write<<e1<<endl;
		write<<grade<<endl;
		write<<count<<endl;
	}
	cout<<endl<<"\t\t\t\t======================================================"<<endl;
	system("pause");
	write.close();
	read.close();
	remove(section.c_str());
	rename("new.txt",section.c_str());
}

void searchAttendanceFinal(string section)
{
	system("cls");
	string stname;
	cin.ignore();
	cout<<endl<<endl<<endl;
	cout<<"\t\t\t\t\t========================================="<<endl<<endl;
	cout<<"\t\t\t\t\t   STUDENTS' NAME: ";
	getline(cin,stname);
	cout<<endl<<"\t\t\t\t\t========================================="<<endl;
	section=section+".txt";
	ifstream read(section.c_str());
	ofstream write("new.txt");
	string name,mids,atten,quiz,part,ex,a1,a2,a3,a4,g1,g2,g3,g4,c1,c2,c3,c4;
	string fin,at,at1,at2,at3,q,q1,q2,q3,p,p1,p2,p3,e,e1,e2,e3;
	string check;
	int c=0;
	while(getline(read,name),getline(read,mids),getline(read,atten),getline(read,a1),getline(read,g1),getline(read,c1),getline(read,quiz),getline(read,a2),getline(read,g2),getline(read,c2),getline(read,part),getline(read,a3),getline(read,g3),getline(read,c3),getline(read,ex),getline(read,a4),getline(read,g4),getline(read,c4),getline(read,fin),getline(read,at),getline(read,at1),getline(read,at2),getline(read,at3),getline(read,q),getline(read,q1),getline(read,q2),getline(read,q3),getline(read,p),getline(read,p1),getline(read,p2),getline(read,p3),getline(read,e),getline(read,e1),getline(read,e2),getline(read,e3))
	{
		write<<name<<endl;
		write<<mids<<endl;
		write<<atten<<endl;
		write<<a1<<endl;
		write<<g1<<endl;
		write<<c1<<endl;
		write<<quiz<<endl;
		write<<a2<<endl;
		write<<g2<<endl;
		write<<c2<<endl;
		write<<part<<endl;
		write<<a3<<endl;
		write<<g3<<endl;
		write<<c3<<endl;
		write<<ex<<endl;
		write<<a4<<endl;
		write<<g4<<endl;
		write<<c4<<endl;	
		write<<fin<<endl;
		write<<at<<endl;
		if (stname==name)
		{
			system("cls");
			cout<<endl<<endl<<endl;
			cout<<"\t\t\t\t\t                ATTENDANCE"<<endl;
			cout<<"\t\t\t\t\t========================================="<<endl;
			cout<<"\t\t\t\t\t =======1 IF PRESENT===0 IF ABSENT======"<<endl<<endl;
			double grade=0,count=0,add=0,temp;
			cout<<"\t\t\t\t\t         "<<name<<": ";
			cin>>check;
			if(check=="1")
			{
				add=1;
			}
			at1=at1+" "+check;
			write<<at1<<endl;
			stringstream geek(at2);
			geek>>grade;
			stringstream ano(at3);
			ano>>count;
			temp=(grade/100)*count;
			count=count+1;
			temp=temp+add;
			grade=(temp/count)*100;
			write<<grade<<endl;
			write<<count<<endl;
			c=1;
			cout<<endl<<"\t\t\t\t\t========================================="<<endl<<endl;
			cout<<"\t\t\t\t\t========================================="<<endl<<endl;
			cout<<"\t\t\t\t\t                 ADDED! "<<endl<<endl;
			cout<<"\t\t\t\t\t========================================="<<endl<<endl;
		}
		else
		{
			write<<at1<<endl;
			write<<at2<<endl;
			write<<at3<<endl;
		}
		write<<q<<endl;
		write<<q1<<endl;
		write<<q2<<endl;
		write<<q3<<endl;
		write<<p<<endl;
		write<<p1<<endl;
		write<<p2<<endl;
		write<<p3<<endl;
		write<<e<<endl;
		write<<e1<<endl;
		write<<e2<<endl;
		write<<e3<<endl;
	}
	write.close();
	read.close();
	remove(section.c_str());
	rename("new.txt",section.c_str());
	if(c==0)
	{
		cout<<"\t\t\t\t\t========================================="<<endl<<endl;
		cout<<"\t\t\t\t\t                 NO RECORD! "<<endl<<endl;
		cout<<"\t\t\t\t\t========================================="<<endl<<endl;
	}
	system("pause");
}


void searchQuizzesFinal(string section)
{
	system("cls");
	string stname;
	cin.ignore();
	cout<<endl<<endl<<endl;
	cout<<"\t\t\t\t======================================================"<<endl<<endl;
	cout<<"\t\t\t\t     STUDENTS' NAME: ";
	getline(cin,stname);
	cout<<"\t\t\t\t======================================================"<<endl;
	section=section+".txt";
	ifstream read(section.c_str());
	ofstream write("new.txt");
	string name,mids,atten,quiz,part,ex,a1,a2,a3,a4,g1,g2,g3,g4,c1,c2,c3,c4;
	string fin,at,at1,at2,at3,q,q1,q2,q3,p,p1,p2,p3,e,e1,e2,e3;
	string check;
	int c=0;
	while(getline(read,name),getline(read,mids),getline(read,atten),getline(read,a1),getline(read,g1),getline(read,c1),getline(read,quiz),getline(read,a2),getline(read,g2),getline(read,c2),getline(read,part),getline(read,a3),getline(read,g3),getline(read,c3),getline(read,ex),getline(read,a4),getline(read,g4),getline(read,c4),getline(read,fin),getline(read,at),getline(read,at1),getline(read,at2),getline(read,at3),getline(read,q),getline(read,q1),getline(read,q2),getline(read,q3),getline(read,p),getline(read,p1),getline(read,p2),getline(read,p3),getline(read,e),getline(read,e1),getline(read,e2),getline(read,e3))
	{
		write<<name<<endl;
		write<<mids<<endl;
		write<<atten<<endl;
		write<<a1<<endl;
		write<<g1<<endl;
		write<<c1<<endl;
		write<<quiz<<endl;
		write<<a2<<endl;
		write<<g2<<endl;
		write<<c2<<endl;
		write<<part<<endl;
		write<<a3<<endl;
		write<<g3<<endl;
		write<<c3<<endl;
		write<<ex<<endl;
		write<<a4<<endl;
		write<<g4<<endl;
		write<<c4<<endl;	
		write<<fin<<endl;
		write<<at<<endl;
		write<<at1<<endl;
		write<<at2<<endl;
		write<<at3<<endl;
		write<<q<<endl;
		if(stname==name)
		{
			system("cls");
			cout<<endl<<endl<<endl;
			cout<<"\t\t\t\t                       QUIZZES"<<endl;
			cout<<"\t\t\t\t======================================================"<<endl;
			cout<<"\t\t\t\t ===PLS INPUT THE SCORES PERCENTAGE IN TOTAL SCORE==="<<endl<<endl;
			double grade=0,count=0,temp;
			string score;
			double scores=0;
			cout<<"\t\t\t\t        "<<name<<": ";
			cin>>score;
			q1=q1+" "+ score;
			write<<q1<<endl;
			stringstream geek(q2);
			geek>>grade;
			stringstream ano(q3);
			ano>>count;
			stringstream sc(score);
			sc>>scores;
			temp=(grade/100)*(count*100);
			count=count+1;
			temp=temp+scores;
			grade=(temp/(count*100))*100;
			write<<grade<<endl;
			write<<count<<endl;
			c=1;
			cout<<endl<<"\t\t\t\t======================================================"<<endl<<endl;
			cout<<"\t\t\t\t======================================================"<<endl<<endl;
			cout<<"\t\t\t\t                  ADDED SUCCESSFULLY!"<<endl<<endl;
			cout<<"\t\t\t\t======================================================"<<endl;
		}
		else
		{
			write<<q1<<endl;
			write<<q2<<endl;
			write<<q3<<endl;
		}
		write<<p<<endl;
		write<<p1<<endl;
		write<<p2<<endl;
		write<<p3<<endl;
		write<<e<<endl;
		write<<e1<<endl;
		write<<e2<<endl;
		write<<e3<<endl;
	}
	write.close();
	read.close();
	remove(section.c_str());
	rename("new.txt",section.c_str());
	if(c==0)
	{
		cout<<"\t\t\t\t======================================================"<<endl<<endl;
		cout<<"\t\t\t\t                    NO RECORD!"<<endl<<endl;
		cout<<"\t\t\t\t======================================================"<<endl;
	}
	system("pause");
}

void searchParticipationFinal(string section)
{
	system("cls");
	string stname;
	cin.ignore();
	cout<<endl<<endl<<endl;
	cout<<"\t\t\t\t======================================================"<<endl<<endl;
	cout<<"\t\t\t\t     STUDENTS' NAME: ";
	getline(cin,stname);
	cout<<"\t\t\t\t======================================================"<<endl;
	section=section+".txt";
	ifstream read(section.c_str());
	ofstream write("new.txt");
	string name,mids,atten,quiz,part,ex,a1,a2,a3,a4,g1,g2,g3,g4,c1,c2,c3,c4;
	string fin,at,at1,at2,at3,q,q1,q2,q3,p,p1,p2,p3,e,e1,e2,e3;
	string check;
	int c=0;
	while(getline(read,name),getline(read,mids),getline(read,atten),getline(read,a1),getline(read,g1),getline(read,c1),getline(read,quiz),getline(read,a2),getline(read,g2),getline(read,c2),getline(read,part),getline(read,a3),getline(read,g3),getline(read,c3),getline(read,ex),getline(read,a4),getline(read,g4),getline(read,c4),getline(read,fin),getline(read,at),getline(read,at1),getline(read,at2),getline(read,at3),getline(read,q),getline(read,q1),getline(read,q2),getline(read,q3),getline(read,p),getline(read,p1),getline(read,p2),getline(read,p3),getline(read,e),getline(read,e1),getline(read,e2),getline(read,e3))
	{
		write<<name<<endl;
		write<<mids<<endl;
		write<<atten<<endl;
		write<<a1<<endl;
		write<<g1<<endl;
		write<<c1<<endl;
		write<<quiz<<endl;
		write<<a2<<endl;
		write<<g2<<endl;
		write<<c2<<endl;
		write<<part<<endl;
		write<<a3<<endl;
		write<<g3<<endl;
		write<<c3<<endl;
		write<<ex<<endl;
		write<<a4<<endl;
		write<<g4<<endl;
		write<<c4<<endl;
		write<<fin<<endl;
		write<<at<<endl;
		write<<at1<<endl;
		write<<at2<<endl;
		write<<at3<<endl;
		write<<q<<endl;
		write<<q1<<endl;
		write<<q2<<endl;
		write<<q3<<endl;
		write<<p<<endl;
		if(stname==name)
		{
			system("cls");
			cout<<endl<<endl<<endl;
			cout<<"\t\t\t\t                      PARTICIPATION"<<endl;
			cout<<"\t\t\t\t======================================================"<<endl;
			cout<<"\t\t\t\t ===PLS INPUT THE SCORES PERCENTAGE IN TOTAL SCORE==="<<endl<<endl;
			double grade=0,count=0,temp;
			string score;
			double scores=0;
			cout<<"\t\t\t\t        "<<name<<": ";
			cin>>score;
			p1=p1+" "+ score;
			write<<p1<<endl;
			stringstream geek(p2);
			geek>>grade;
			stringstream ano(p3);
			ano>>count;
			stringstream sc(score);
			sc>>scores;
			temp=(grade/100)*(count*100);
			count=count+1;
			temp=temp+scores;
			grade=(temp/(count*100))*100;
			write<<grade<<endl;
			write<<count<<endl;
			c=1;
			cout<<endl<<"\t\t\t\t======================================================"<<endl;
			cout<<"\t\t\t\t======================================================"<<endl<<endl;
			cout<<"\t\t\t\t                  ADDED SUCCESSFULLY!"<<endl<<endl;
			cout<<"\t\t\t\t======================================================"<<endl;
		}
		else
		{
			write<<p1<<endl;
			write<<p2<<endl;
			write<<p3<<endl;
		}
		write<<e<<endl;
		write<<e1<<endl;
		write<<e2<<endl;
		write<<e3<<endl;	
	}
	write.close();
	read.close();
	remove(section.c_str());
	rename("new.txt",section.c_str());
	if(c==0)
	{
		cout<<"\t\t\t\t======================================================"<<endl<<endl;
		cout<<"\t\t\t\t                    NO RECORD!"<<endl<<endl;
		cout<<"\t\t\t\t======================================================"<<endl;
	}
	system("pause");
}

void searchExamFinal(string section)
{
	system("cls");
	string stname;
	cin.ignore();
	cout<<endl<<endl<<endl;
	cout<<"\t\t\t\t======================================================"<<endl<<endl;
	cout<<"\t\t\t\t     STUDENTS' NAME: ";
	getline(cin,stname);
	cout<<"\t\t\t\t======================================================"<<endl;
	section=section+".txt";
	ifstream read(section.c_str());
	ofstream write("new.txt");
	string name,mids,atten,quiz,part,ex,a1,a2,a3,a4,g1,g2,g3,g4,c1,c2,c3,c4;
	string fin,at,at1,at2,at3,q,q1,q2,q3,p,p1,p2,p3,e,e1,e2,e3;
	string check;
	int c=0;
	while(getline(read,name),getline(read,mids),getline(read,atten),getline(read,a1),getline(read,g1),getline(read,c1),getline(read,quiz),getline(read,a2),getline(read,g2),getline(read,c2),getline(read,part),getline(read,a3),getline(read,g3),getline(read,c3),getline(read,ex),getline(read,a4),getline(read,g4),getline(read,c4),getline(read,fin),getline(read,at),getline(read,at1),getline(read,at2),getline(read,at3),getline(read,q),getline(read,q1),getline(read,q2),getline(read,q3),getline(read,p),getline(read,p1),getline(read,p2),getline(read,p3),getline(read,e),getline(read,e1),getline(read,e2),getline(read,e3))
	{
		write<<name<<endl;
		write<<mids<<endl;
		write<<atten<<endl;
		write<<a1<<endl;
		write<<g1<<endl;
		write<<c1<<endl;
		write<<quiz<<endl;
		write<<a2<<endl;
		write<<g2<<endl;
		write<<c2<<endl;
		write<<part<<endl;
		write<<a3<<endl;
		write<<g3<<endl;
		write<<c3<<endl;
		write<<ex<<endl;
		write<<a4<<endl;
		write<<g4<<endl;
		write<<c4<<endl;
		write<<fin<<endl;
		write<<at<<endl;
		write<<at1<<endl;
		write<<at2<<endl;
		write<<at3<<endl;
		write<<q<<endl;
		write<<q1<<endl;
		write<<q2<<endl;
		write<<q3<<endl;
		write<<p<<endl;
		write<<p1<<endl;
		write<<p2<<endl;
		write<<p3<<endl;
		write<<e<<endl;
		if(stname==name)
		{
			system("cls");
			cout<<endl<<endl<<endl;
			cout<<"\t\t\t\t                      MAJOR EXAM"<<endl;
			cout<<"\t\t\t\t======================================================"<<endl;
			cout<<"\t\t\t\t ===PLS INPUT THE SCORES PERCENTAGE IN TOTAL SCORE==="<<endl<<endl;
			double grade=0,count=0,temp;
			string score;
			double scores=0;
			cout<<"\t\t\t\t        "<<name<<": ";
			cin>>score;
			stringstream geek(e2);
			geek>>grade;
			stringstream ano(e3);
			ano>>count;
			stringstream sc(score);
			sc>>scores;
			temp=(grade/100)*(count*100);
			count=count+1;
			temp=temp+scores;
			grade=(temp/(count*100))*100;
			e1=e1+" "+ score;
			write<<e1<<endl;
			write<<grade<<endl;
			write<<count<<endl;
			c=1;
			cout<<endl<<"\t\t\t\t======================================================"<<endl;
			cout<<"\t\t\t\t======================================================"<<endl<<endl;
			cout<<"\t\t\t\t                  ADDED SUCCESSFULLY!"<<endl<<endl;
			cout<<"\t\t\t\t======================================================"<<endl;
		}
		else
		{
			write<<e1<<endl;
			write<<e2<<endl;
			write<<e3<<endl;
		}
	}
	write.close();
	read.close();
	remove(section.c_str());
	rename("new.txt",section.c_str());
	if(c==0)
	{
		cout<<"\t\t\t\t======================================================"<<endl<<endl;
		cout<<"\t\t\t\t                    NO RECORD!"<<endl<<endl;
		cout<<"\t\t\t\t======================================================"<<endl;
	}
	system("pause");
}

void searchFinalRecord(vector <Record> S)
{
	system("cls");
	string name,a1,a2,a3,a4;
	string a,q,p,e;
	cin.ignore();
	cout<<endl<<endl<<endl;
	cout<<"\t\t\t\t\t         SEARCH RECORD         "<<endl;
	cout<<"\t\t\t\t\t==============================="<<endl<<endl;
	cout<<"\t\t\t\t\t  STUDENTS' NAME: ";
	getline(cin,name);
	cout<<endl<<"\t\t\t\t\t==============================="<<endl<<endl;
	int c=0;
	for(int i=0;i<S.size();i++)
	{
		if(name==S[i].getName())
		{
			a1=S[i].getFsa();
			for(int b=0;b+2<a1.size();b++)
			{
				a.push_back(a1[b+2]);
			}
			a2=S[i].getFsq();
			for(int b=0;b+2<a2.size();b++)
			{
				q.push_back(a2[b+2]);
			}
			a3=S[i].getFsp();
			for(int b=0;b+2<a3.size();b++)
			{
				p.push_back(a3[b+2]);
			}
			a4=S[i].getFse();
			for(int b=0;b+2<a4.size();b++)
			{
				e.push_back(a4[b+2]);
			}
			system("cls");
			cout<<endl<<endl<<endl;
			cout<<"							  FINALS"<<endl;
			cout<<"\t\t\t\t\t======================================"<<endl<<endl;
			cout<<"							"<<S[i].getName()<<endl;
			cout<< right                
	        	<< setw(60) << "ATTENDACE: "   
				<<a<<endl
				<<setw(60)<<"GRADE: "
				<<S[i].getFAttendance()<<endl
	        	<< setw(60) << "QUIZZES: "  
	        	<<q<<endl
	        	<<setw(60)<<"GRADE: "
	        	<<S[i].getFQuizzes()<<endl
	       		<< setw(60) << "PARTICIPATION: "
	       		<<p<<endl
	       		<<setw(60)<<"GRADE: "
	       		<<S[i].getFParticipation()<<endl
			   	<< setw(60) << "MAJOR EXAM: "
			   	<<e<<endl
			   	<<setw(60)<<"GRADE: "
			   	<<S[i].getFExam()<<endl;
			   	cout<<"\t\t\t\t\t======================================"<<endl<<endl;
			c=1;
		}
	}
	if(c==0)
	{
		cout<<"\t\t\t\t\t==============================="<<endl<<endl;
		cout<<"\t\t\t\t\t           NO RECORD "<<endl<<endl;
		cout<<"\t\t\t\t\t==============================="<<endl<<endl;
	}
	system("pause");
}

void computeFinalGrades(vector <Record> S)
{
	int ch;
	system("cls");
	cout<<endl<<endl<<endl;
	cout<<"\t\t\t\t\t==============================="<<endl<<endl;
	cout<<"\t\t\t\t\t           1 =ALL"<<endl;
	cout<<"\t\t\t\t\t          2 =SEARCH"<<endl;
	cout<<"\t\t\t\t\t           3 =BACK"<<endl;
	cout<<endl<<"\t\t\t\t\t==============================="<<endl;
	cout<<"\t\t\t\t\t             ==> ";
	cin>>ch;
	while(ch!=3)
	{
		switch(ch)
		{
			case 1:
				system("cls");
				cout<<endl<<endl<<endl;
				cout<<"\t\t\t\t\t             FINALS GRADE"<<endl;
				cout<<"\t\t\t\t\t======================================"<<endl<<endl;
				for(int i=0;i<S.size();i++)
				{
					double a,q,p,e,grade;
					a=S[i].getFAttendance();
					q=S[i].getFQuizzes();
					p=S[i].getFParticipation();
					e=S[i].getFExam();
					a=(a/100)*10;
					q=(q/100)*20;
					p=(p/100)*40;
					e=(e/100)*30;
					grade=a+q+p+e;
					cout<<"\t\t\t\t\t     "<<S[i].getName()<<": "<<grade<<endl;
				}
				cout<<endl<<"\t\t\t\t\t==============================="<<endl<<endl;
				system("pause");
				break;
			case 2:
				system("cls");
				string name;
				cin.ignore();
				cout<<endl<<endl<<endl;
				cout<<"\t\t\t\t\t==============================="<<endl<<endl;
				cout<<"\t\t\t\t\t STUDENTS' NAME: ";
				getline(cin,name);
				cout<<endl;
				cout<<"\t\t\t\t\t==============================="<<endl<<endl;
				int count=0;
				system("cls");
				cout<<endl<<endl<<endl;
				cout<<"\t\t\t\t\t          FINALS GRADE"<<endl;
				cout<<"\t\t\t\t\t==============================="<<endl<<endl;
				for(int i=0;i<S.size();i++)
				{
					if(name==S[i].getName())
					{
						double a,q,p,e,grade;
						a=S[i].getFAttendance();
						q=S[i].getFQuizzes();
						p=S[i].getFParticipation();
						e=S[i].getFExam();
						a=a*.10;
						q=q*.20;
						p=p*.40;
						e=e*.30;
						grade=a+q+p+e;
						cout<<"\t\t\t\t\t     "<<S[i].getName()<<": "<<grade<<endl;
						cout<<endl<<"\t\t\t\t\t==============================="<<endl<<endl;
						count=1;
					}
					
				}
				if(count==0)
				{
					cout<<"\t\t\t\t\t==============================="<<endl<<endl;
					cout<<"\t\t\t\t\t           NO RECORD "<<endl<<endl;
					cout<<"\t\t\t\t\t==============================="<<endl<<endl;
				}
				system("pause");
				break;
				
		}
		system("cls");
		cout<<endl<<endl<<endl;
		cout<<"\t\t\t\t\t==============================="<<endl<<endl;
		cout<<"\t\t\t\t\t           1 =ALL"<<endl;
		cout<<"\t\t\t\t\t          2 =SEARCH"<<endl;
		cout<<"\t\t\t\t\t           3 =BACK"<<endl;
		cout<<endl<<"\t\t\t\t\t==============================="<<endl;
		cout<<"\t\t\t\t\t             ==> ";
		cin>>ch;
	}
}

void computeSemGrades(vector <Record> S)
{
	int ch;
	system("cls");
	cout<<endl<<endl<<endl;
	cout<<"\t\t\t\t\t==============================="<<endl<<endl;
	cout<<"\t\t\t\t\t           1 =ALL"<<endl;
	cout<<"\t\t\t\t\t          2 =SEARCH"<<endl;
	cout<<"\t\t\t\t\t           3 =BACK"<<endl;
	cout<<endl<<"\t\t\t\t\t==============================="<<endl;
	cout<<"\t\t\t\t\t             ==> ";
	cin>>ch;
	while(ch!=3)
	{
		switch(ch)
		{
			case 1:
				system("cls");
				cout<<endl<<endl<<endl;
				cout<<"\t\t\t\t\t           SEMESTRAL GRADE"<<endl;
				cout<<"\t\t\t\t\t======================================"<<endl<<endl;
				for(int i=0;i<S.size();i++)
				{
					double a,q,p,e,gradeMid,gradeFin,ma,mq,mp,me,semGrade,t1,t2;
					ma=S[i].getAttendance();
					mq=S[i].getQuizzes();
					mp=S[i].getParticipation();
					me=S[i].getExam();
					ma=(ma/100)*10;
					mq=(mq/100)*20;
					mp=(mp/100)*40;
					me=(me/100)*30;
					gradeMid=ma+mq+mp+me;
					a=S[i].getFAttendance();
					q=S[i].getFQuizzes();
					p=S[i].getFParticipation();
					e=S[i].getFExam();
					a=(a/100)*10;
					q=(q/100)*20;
					p=(p/100)*40;
					e=(e/100)*30;
					gradeFin=a+q+p+e;
					t1=(1.0/3.0);
					t2=2.0/3.0;
					semGrade=(gradeMid*t1)+(gradeFin*t2);
					cout<<"\t\t\t\t\t     "<<S[i].getName()<<": "<<semGrade<<endl;
				}
				cout<<endl<<"\t\t\t\t\t======================================"<<endl<<endl;
				system("pause");
				break;
			case 2:
				system("cls");
				string name;
				cin.ignore();
				cout<<endl<<endl<<endl;
				cout<<"\t\t\t\t\t==============================="<<endl<<endl;
				cout<<"\t\t\t\t\t STUDENTS' NAME: ";
				getline(cin,name);
				cout<<endl;
				cout<<"\t\t\t\t\t==============================="<<endl<<endl;
				int count=0;
				for(int i=0;i<S.size();i++)
				{
					if(name==S[i].getName())
					{
						double a,q,p,e,gradeMid,gradeFin,ma,mq,mp,me,semGrade,t1,t2;
						ma=S[i].getAttendance();
						mq=S[i].getQuizzes();
						mp=S[i].getParticipation();
						me=S[i].getExam();
						ma=(ma/100)*10;
						mq=(mq/100)*20;
						mp=(mp/100)*40;
						me=(me/100)*30;
						gradeMid=ma+mq+mp+me;
						a=S[i].getFAttendance();
						q=S[i].getFQuizzes();
						p=S[i].getFParticipation();
						e=S[i].getFExam();
						a=(a/100)*10;
						q=(q/100)*20;
						p=(p/100)*40;
						e=(e/100)*30;
						gradeFin=a+q+p+e;
						t1=(1.0/3.0);
						t2=2.0/3.0;
						semGrade=(gradeMid*t1)+(gradeFin*t2);
						system("cls");
						cout<<endl<<endl<<endl;
						cout<<"\t\t\t\t\t        SEMESTRAL GRADE"<<endl;
						cout<<"\t\t\t\t\t==============================="<<endl<<endl;
						cout<<"\t\t\t\t\t     "<<S[i].getName()<<": "<<semGrade<<endl;
						cout<<endl<<"\t\t\t\t\t==============================="<<endl<<endl;
						count=1;
					}
				}
				if(count==0)
				{
					cout<<"\t\t\t\t\t==============================="<<endl<<endl;
					cout<<"\t\t\t\t\t           NO RECORD "<<endl<<endl;
					cout<<"\t\t\t\t\t==============================="<<endl<<endl;
				}
				system("pause");
				break;
		}
		system("cls");
		cout<<endl<<endl<<endl;
		cout<<"\t\t\t\t\t==============================="<<endl<<endl;
		cout<<"\t\t\t\t\t           1 =ALL"<<endl;
		cout<<"\t\t\t\t\t          2 =SEARCH"<<endl;
		cout<<"\t\t\t\t\t           3 =BACK"<<endl;
		cout<<endl<<"\t\t\t\t\t==============================="<<endl;
		cout<<"\t\t\t\t\t             ==> ";
		cin>>ch;
	}
}


