//---------------------------------------------------------------------------

#include <fmx.h>
#include <fstream>
#include <vector>
#include <sstream>
#pragma hdrstop

#include "LoginForm.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.fmx"
TMyLoginForm *MyLoginForm;
//---------------------------------------------------------------------------
__fastcall TMyLoginForm::TMyLoginForm(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------

std :: vector <std:: string>delimitatedwords(std::string line)
{   std:: vector<std:: string>results;
	std :: stringstream s_stream(line);

	while(s_stream.good())
	{
		std:: string substr;
		getline(s_stream,substr,',');
		results.push_back(substr);
	}
	return results;
}

const char* convertCharToPtr(AnsiString ansistring)
{
	   return  ansistring.c_str();
}


void __fastcall TMyLoginForm::LogInButtonClick(TObject *Sender)
{
	fstream MyFile;
	int contor=0;
	 MyFile.open("RegisteredUser.txt",ios:: in);
	 if(MyFile.is_open())
	 {   int contor_for_username=0,contor_for_password=0,contor_trying=3;
		 std:: string line;

		 while(getline(MyFile,line))
		 {
			std:: vector <std :: string> parsedLine=delimitatedwords(line);
			const char* username=parsedLine.at(3).c_str();
			const char* password=parsedLine.at(4).c_str();

				if(std:: strcmp(convertCharToPtr(UserNameEdit->Text),username)==0)
				{

					contor_for_username=1;

					if(std:: strcmp(convertCharToPtr(PasswordEdit->Text),password)==0)
					{
					  contor_for_password=1;

					}
					else
					{

					  contor_for_username=1;
					}
					contor_trying--;
				}



		 }

		  if(contor_for_username==1 && contor_for_password==1)
		 {
		  MessageLabel->Text="Succes!";

		 }

		if(contor_for_username==0 && contor_for_password==0)
		 {
		  MessageLabel->Text="Username or password is incorrect";

		 }

		 if(contor_for_username==1 && contor_for_password==0)
		 {
		  MessageLabel->Text="Password is incorrect!";
		 }



	 }


}
//---------------------------------------------------------------------------



void __fastcall TMyLoginForm::FormCreate(TObject *Sender)
{
	LogInButton->Enabled=false;
}
//---------------------------------------------------------------------------



void __fastcall TMyLoginForm::PasswordEditValidating(TObject *Sender, UnicodeString &Text)

{
	LogInButton->Enabled=true;
}
//---------------------------------------------------------------------------



void __fastcall TMyLoginForm::FormClose(TObject *Sender, TCloseAction &Action)
{
    UserNameEdit->Text="";
	PasswordEdit->Text="";
	MessageLabel->Text="";
}
//---------------------------------------------------------------------------



