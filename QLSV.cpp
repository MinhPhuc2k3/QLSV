#include <bits/stdc++.h>
#include <string>
using namespace std;

class Student{
	private:
		string id;
		string name;
		string classid;
		string address;
		float math, literature, english;
	public:
		Student();
		void SetId();
		string GetId();
		void SetName();
		string GetName();
		string GetLastName();
		void SetClassId();
		string GetClassId();
		void SetAddress();
		string GetAddress();
		void SetGrade();
		float GetMath();
		float GetLiterature();
		float GetEnglish();
		float GetGrade();
		void Input();
		void Output();
};

Student::Student(){
	this -> id="";
	this ->name="";
	this ->classid="";
	this ->address="";
	this ->math=0;
	this ->literature=0;
	this ->english=0;
}

void Student::SetId(){
	fflush(stdin);
	getline(cin, id);
}

void Student::SetName(){
	fflush(stdin);
	getline(cin, name);
}

void Student::SetClassId(){
	fflush(stdin);
	getline(cin, classid);
}

void Student::SetAddress(){
	fflush(stdin);
	getline(cin, address);
}

void Student::SetGrade(){
	cout << "Diem toan: ";
	cin >> math;
	cout << endl;
	cout << "Diem van: ";
	cin >> literature;
	cout << endl;
	cout << "Diem anh: ";
	cin >> english;
	cout << endl;
}

string Student::GetId(){
	return id;
}

string Student::GetName(){
	return name;
}

string Student::GetLastName(){
	string ln="";
	int i=name.length()-1;
	while(name[i]!=' '){
		ln=name[i]+ln;
		i--;
	}
	return ln;
}

string Student::GetClassId(){
	return classid;
}
string Student::GetAddress(){
	return address;
}
float Student::GetMath(){
	return math;
}
float Student::GetLiterature(){
	return literature;
}
float Student::GetEnglish(){
	return english;
}
float Student::GetGrade(){
	return math + literature + english; 
}

void Student::Input(){
	cout << "Nhap ma sinh vien: ";SetId();
	cout << "Ho ten: ";SetName();
	cout << "Lop: ";SetClassId();
	cout << "Dia chi: ";SetAddress();
	SetGrade();
}

void Student::Output(){
	cout << setw(20)<< GetId();
	cout << setw(20)<< GetName();
	cout << setw(20)<< GetClassId();
	cout << setw(20)<< GetAddress();
	cout << setw(6) << GetMath();
	cout << setw(6) << GetLiterature();
	cout << setw(6) << GetEnglish();
	cout << setw(8) << GetGrade();
}

void PrintList(Student sv[], int k){
		for(int i=0; i<110;i++) cout << "=";
	cout<<"\n";
		for(int i=0; i<k; i++){
			cout<<"||" <<i+1;
		sv[i].Output();
		cout <<"||"<< endl;
	}
	
	for(int i=0; i<110; i++) cout << "=";
	cout<<"\n";
}

void AddStudent(Student sv[], int& k){
	int n;
	cout << "Vui long nhap so sinh vien can them: "<<endl;
	cin >> n;
	for(int i=k; i<k+n; i++){
		cout<<"Sinh vien thu "<<i+1<<":"<<endl;
		sv[i].Input();
	}
	k+=n;
}

void Edit(Student sv[],int k){
	int n;
	cout << "Chon so thu tu sinh vien can sua: "<< endl;
	cin >> n;
	cout << "Chon thong tin can sua: "<<endl;
	cout << "1.Ma sinh vien"<<endl;
	cout << "2.Ho ten"<<endl;
	cout << "3.Lop"<<endl;
	cout << "4.Dia chi"<<endl;
	cout << "5.Diem"<<endl;
	cout << "0.Quay lai"<<endl;
	int s;
	cin >>s;
	switch (s){
		case 1:{
			sv[n].SetId();
			break;
		}
		case 2:{
			sv[n].SetName();
			break;
		}
		case 3:{
			sv[n].SetClassId();
			break;
		}
		case 4:{
			sv[n].SetAddress();
			break;
		}
		case 5:{
			sv[n].SetGrade();
			break;
		}
		default:{
			break;
		}
	}
}

void RemoveStudent(Student sv[],int& k){
	int n;
	cout << "Vui long nhap so thu tu sinh vien can xoa: ";
	cin >> n;
	n--;
	for(int i=n; i<k-1;i++){
		sv[i]=sv[i+1];
	}
	k--;
}

void SortName(Student sv[], int k){
	for(int i=0; i<k; i++){
		for(int j=0; j<k-i-1; j++){
			if(sv[j].GetLastName().compare(sv[j+1].GetLastName())<0){
				Student x=sv[j];
				sv[j]=sv[j+1];
				sv[j+1]=x;
			}
		}
	}
}

void SortGrade(Student sv[], int k){
	for(int i=0; i<k; i++){
		for(int j=0; j<k-i-1; j++){
			if(sv[j].GetGrade()>sv[j+1].GetGrade()){
				Student x=sv[j];
				sv[j]=sv[j+1];
				sv[j+1]=x;
			}
		}
	}
}

void Filter(Student sv[], int k){
	for(int i=0; i<110;i++) cout << "=";
		for(int i=0; i< k; i++){
			if(sv[i].GetGrade()>=24){
				cout<<"\n";
				cout<<"||" <<i+1;
				sv[i].Output();
				cout <<"||"<< endl;
			}
		}
	for(int i=0; i<110;i++) cout << "=";
	cout << endl;
}

int main(){
	Student sv[1000];
	int k=0;//do dai list
	while(1){
		system("cls");
		int selection;
		cout << "--------------MENU------------------"<<endl;
		cout << "----1.Them sinh vien----------------"<<endl;
		cout << "----2.Sua thong tin sinh vien-------"<<endl;
		cout << "----3.Xoa sinh vien-----------------"<<endl;
		cout << "----4.Sap xep theo ten giam dan-----"<<endl;
		cout << "----5.Sap xep theo diem tang dan----"<<endl;
		cout << "----6.In danh sach sinh vien--------"<<endl;
		cout << "----7.Loc diem tren 24--------------"<<endl;
		cout << "----0.Thoat-------------------------"<<endl;
		cout << "Vui long nhon chuc nang: ";
		cin >> selection;
		switch(selection){
			case 1:{
				AddStudent(sv, k);
				system("pause");
				break;
			}
			case 2:{
				PrintList(sv, k);
				Edit(sv, k);
				system("pause");
				break;
			}
			case 3:{
				PrintList(sv, k);
				RemoveStudent(sv, k);
				break;
			}
			case 4:{
				SortName(sv, k);
				cout << "Sap xep thanh cong!"<<endl;
				PrintList(sv,k);
				system("pause");
				break;
			}
			case 5:{
				SortGrade(sv, k);
				cout << "Sap xep thanh cong!"<<endl;
				PrintList(sv,k);
				system("pause");				
				break;
			}
			case 6:{
				PrintList(sv,k);
				system("pause");
				break;
			}
			case 7:{
				Filter(sv, k);
				system("pause");
				break;
			}
			default:{
				break;
			}
		}
	}
}
