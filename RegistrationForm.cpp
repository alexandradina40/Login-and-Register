//---------------------------------------------------------------------------

#include <fmx.h>
#include <fstream>
#include <vector>
#pragma hdrstop

#include "RegistrationForm.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.fmx"
TMyRegistrationForm *MyRegistrationForm;
//---------------------------------------------------------------------------
__fastcall TMyRegistrationForm::TMyRegistrationForm(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TMyRegistrationForm::SaveButtonClick(TObject *Sender)
{
	  fstream MyFile;
	  MyFile.open("RegisteredUser.txt",ios:: app);
	  if(MyFile.is_open())
	  {
		  AnsiString firstname=FirstNameEdit->Text;
		  AnsiString lastname=LastNameEdit->Text;
		  AnsiString age=AgeEdit->Text;
		  AnsiString username=UserNameEdit->Text;
		  AnsiString password=PasswordEdit->Text;

		  MyFile<<firstname<<","<<lastname<<","<<age<<","<<username<<","<<password<<"\n";
		  MyFile.close();
		  this->Close();
	  }
}
//---------------------------------------------------------------------------

