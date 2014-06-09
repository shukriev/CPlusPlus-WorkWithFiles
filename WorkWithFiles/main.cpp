#include <cstdlib>
#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>

using namespace std;
struct Student{
int faknom;
char name[15];
char fname[15];
double points;
};
Student stud[250];
int sizen;
//=================Create File==============
void Create(ofstream& f)
{Student s={0,"", "", 0.0};   
         for(int i=0;i<=250;i++)
f.write(reinterpret_cast<const char*>(&s),sizeof(Student));
f.close();
}
//-----------------NewStudent---------------
void newStudents(fstream& f)
{int i,n;
cout<<"Vav broi studenti:";
cin>>n;
cout<<"-----------------"<<endl;
for(i=0;i<n;i++){
                 cout<<"Vav faknom ot 1 do 250: ";
Student s;
                 cin>>s.faknom;            
                 cout<<"Vavedete ime:";
                 cin>>s.name;
                 cout<<"Vavedete familia:";
                 cin>>s.fname;
                 cout<<"Vavedete to4ki:";
                 cin>>s.points;
                 cout<<endl;
f.seekp((s.faknom - 1)*sizeof(Student));
f.write(reinterpret_cast<const char*>(&s),sizeof(Student));
                 cout<<endl; 
                 } 
f.close();
}
//------------------------GET Stuent-------------------------
int get_nom()
{cout<<"Vavedete fakulteten nomer ";
int nom;
        do
          cin>>nom;
        while(nom<1 || nom>250);
return nom;
}
//------------Instanciq-----------------------------------
void OutLine(ostream &f, const Student &c)
{f<<setiosflags(ios::left)<<setw(11)<<c.faknom
  <<setw(21)<<c.fname<<setw(11)<<c.name
  <<setw(10)<<c.points<<endl;
 }
//--------------Vavejdane na studenti----------------------
void addStudent(fstream& f)
{int nom=get_nom();
f.seekg((nom-1)*sizeof(Student));
Student s;
f.read((char*)(&s),sizeof(Student));
        if(s.faknom==0){
                        s.faknom=nom;
                        cout<<"Vavedete ime ";
                        cin>>s.name;
                        cout<<"Vavedete familia ";
                        cin>>s.fname;
                        cout<<"Vavedete tochki ";
                        cin>>s.points;
f.seekp((nom-1)*sizeof(Student));
f.write((const char*)(&s),sizeof(Student));
                       }else{
                        cerr<<"Fakulteten nomer "<<nom<<" Sushtestyvva"<<endl;
                        } 
f.close();                     
}
//---------------------AverageResult------------------------
void avgResults(fstream &f)
{Student s;
int i=0;
double avg=0;
f.read(reinterpret_cast<char*>(&s),sizeof(Student)); 
while(f.good()){
                if(s.faknom !=0){
                                  i++;
                                  avg=(avg+s.points)/i;
                                 }
f.read(reinterpret_cast<char*>(&s),sizeof(Student)); 
               }
      cout<<"|------------------------------|"<<endl;
      cout<<" Sredno aritmetichnoto e: "<<avg<<endl;
      cout<<"|------------------------------|"<<endl;
f.close();
}
//-------------Izvejdane na vsi4ki danni-------------------
void listFile(fstream& f)
{cout<<setiosflags(ios::left)<<setw(10)<<"Fakulteten nomer"
                              <<setw(16)<<"Familia"<<setw(11)
                              <<"Ime"<<setw(10)<<"Tochki"<<endl;
Student s;
f.read(reinterpret_cast<char *>(&s),sizeof(Student));
while(f.good()){
                      if(s.faknom !=0)      
                                      OutLine(cout,s);
f.read(reinterpret_cast<char *>(&s),sizeof(Student));
               }
f.close();
}
//----------------ReadFile-------------------------------
int readFile(fstream& f,Student (&studen)[250],int &size)
{
int n,i=0;
Student s; 
while(f.good()){
f.read(reinterpret_cast<char *>(&s),sizeof(Student)); 
            if(s.faknom != 0){                      
                                studen[i].faknom=s.faknom;
                                strcpy(studen[i].name,s.name);
                                strcpy(studen[i].fname,s.fname);
                                studen[i].points=s.points;            
                                i++;                  
                              }       
               }
size=i;
cout<<setiosflags(ios::left)<<setw(10)<<"Fakulteten nomer"
                            <<setw(16)<<"Familia"<<setw(11)
                            <<"Ime"<<setw(10)<<"Tochki"<<endl;
for(n=0;n<i;n++){
cout<<setiosflags(ios::left)<<setw(11)<<stud[n].faknom
                            <<setw(21)<<stud[n].fname<<setw(11)<<stud[n].name
                            <<setw(10)<<stud[n].points<<endl;                                 
                }
cout<<"|---------------------------|"<<endl;
cout<<" "<<i<<"- zapisani studenti"<<endl;     
cout<<"|---------------------------|"<<endl; 

f.close();  
}
//---------------------Sort----------------------------------
void sort(Student (&studen)[250]){
int l,j;
Student min;
           for(l=0;l<sizen;l++)
           for(j=0;j<sizen-l-1;j++)
           
           if(stud[j].points<stud[j+1].points){
   
           min.points=stud[j].points;
           min.faknom=stud[j].faknom;
           strcpy(min.name,stud[j].name);
           strcpy(min.fname,stud[j].fname);
           
           stud[j].points=stud[j+1].points;
           stud[j].faknom=stud[j+1].faknom; 
           strcpy(stud[j].name,stud[j+1].name);
           strcpy(stud[j].fname,stud[j+1].fname);
           
           stud[j+1].points=min.points;
           stud[j+1].faknom=min.faknom; 
           strcpy(stud[j+1].name,min.name);
           strcpy(stud[j+1].fname,min.fname);
                                              }          
cout<<setiosflags(ios::left)<<setw(10)<<"Fakulteten nomer"
                            <<setw(16)<<"Familia"<<setw(11)
                            <<"Ime"<<setw(10)<<"Tochki"<<endl;
           for(int p=0;p<sizen;p++){
        
cout<<setiosflags(ios::left)<<setw(11)<<stud[p].faknom
                            <<setw(21)<<stud[p].fname<<setw(11)<<stud[p].name
                            <<setw(10)<<stud[p].points<<endl;
                                   }
     
}

//------------search student by name----------------------
void searchStudentByname(fstream& f)
{cout<<"vavedete familia na student ";
char fnam[15];
cin>>fnam;
cout<<setiosflags(ios::left)<<setw(10)<<"Fakulteten nomer"
                            <<setw(16)<<"Familia"<<setw(11)
                            <<"Ime"<<setw(10)<<"Tochki"<<endl;
Student s;
f.read(reinterpret_cast<char*>(&s),sizeof(Student));
while(f.good()){
                if(strstr(s.fname,fnam)!=NULL)
                                              OutLine(cout,s);
f.read(reinterpret_cast<char *>(&s),sizeof(Student));          
               }
f.close();
}
//-----------------displayStudentsWithMax-----------------
void displayStudentMaxPoints(fstream& f)
{cout<<setiosflags(ios::left)<<setw(10)<<"Fakulteten nomer"
                             <<setw(16)<<"Familia"<<setw(11)
                             <<"Ime"<<setw(10)<<"Tochki"<<endl;
Student s;
f.read(reinterpret_cast<char*>(&s),sizeof(Student));
while(f.good()){
          if(s.faknom !=0 && s.points==100)
                                          OutLine(cout,s);
f.read(reinterpret_cast<char *>(&s),sizeof(Student));
               }
f.close();
}
//------------------------Tekstov---------------------------
void TextFile(fstream& f)
{ofstream outf("file.txt",ios::out);
          if(!outf){
                    cerr<<"File couldn't be opened."<<endl;
	                return;
                 	}
                    f.seekg(0);
Student s;
f.read(reinterpret_cast<char*>(&s),sizeof(Student));
while (f.good()){
          if (s.faknom !=0)
	                       	OutLine(outf,s);
f.read(reinterpret_cast<char*>(&s), sizeof(Student));
               	}
outf.close();
f.close();
}


//----------------------MENU---------------------------------
enum menu{NEW=1,INSERT=2,BNAME=3,AVG=4,MAXP=5,LIST=6,READ=7,SORT=8,TXT=9,END=10};
int getRequest()
{cout<<endl
     <<"1-Vav.studenti \n"
     <<"2-Dob.student \n"
     <<"3-Tursene na stud.po ime\n"
     <<"4-Sr.na tochki \n"
     <<"5-Izvejdane na stud. s max.T.\n"
     <<"6-Izv.na vs. stud. \n"
     <<"7-Izvejdane na masiva predi sortirane \n"
     <<"8-Sortirane na masiva \n"
     <<"9-Text file\n"
     <<"10-Kray \n"<<endl;
        int request;
        do{
            cout<<"Menu(1-9)=";
            cin>>request;
          }while(request<NEW || request>END);
return request;
}
//==============================================================
int main(int argc, char *argv[])
{ofstream f1("file.dat",ios::out);
Create(f1);
f1.close();
fstream f;
int request;
while((request=getRequest()) !=END)
{f.open("file.dat",ios::in|ios::out);
         if(!f){
                 cerr<<"Faylat ne moje da b1de otvoren";
                 return 1;
               }else{
                      switch(request){
                             case NEW:     newStudents(f);break;
                             case INSERT:  addStudent(f);break;
                             case BNAME:   searchStudentByname(f);break;
                             case AVG:     avgResults(f);break;
                             case MAXP:    displayStudentMaxPoints(f);break;
                             case LIST:    listFile(f);break; 
                             case READ:    readFile(f,stud,sizen);break;                           
                             case SORT:    sort(stud);break;
                             case TXT:     TextFile(f);break;
                         
                                    }
                            
f.clear();
                   }
}
    
    system("PAUSE");
    return EXIT_SUCCESS;
}
