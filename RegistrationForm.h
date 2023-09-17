//---------------------------------------------------------------------------

#ifndef RegistrationFormH
#define RegistrationFormH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <FMX.Controls.hpp>
#include <FMX.Forms.hpp>
#include <FMX.Controls.Presentation.hpp>
#include <FMX.Edit.hpp>
#include <FMX.StdCtrls.hpp>
#include <FMX.Types.hpp>
//---------------------------------------------------------------------------
class TMyRegistrationForm : public TForm
{
__published:	// IDE-managed Components
	TLabel *Label1;
	TEdit *FirstNameEdit;
	TLabel *Label2;
	TEdit *LastNameEdit;
	TLabel *Label3;
	TEdit *AgeEdit;
	TLabel *Label4;
	TEdit *UserNameEdit;
	TLabel *Label5;
	TEdit *PasswordEdit;
	TButton *SaveButton;
	void __fastcall SaveButtonClick(TObject *Sender);
private:	// User declarations
public:		// User declarations
	__fastcall TMyRegistrationForm(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TMyRegistrationForm *MyRegistrationForm;
//---------------------------------------------------------------------------
#endif
