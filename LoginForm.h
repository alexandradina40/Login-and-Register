//---------------------------------------------------------------------------

#ifndef LoginFormH
#define LoginFormH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <FMX.Controls.hpp>
#include <FMX.Forms.hpp>
#include <FMX.Controls.Presentation.hpp>
#include <FMX.Edit.hpp>
#include <FMX.StdCtrls.hpp>
#include <FMX.Types.hpp>
//---------------------------------------------------------------------------
class TMyLoginForm : public TForm
{
__published:	// IDE-managed Components
	TLabel *Label1;
	TEdit *UserNameEdit;
	TLabel *Label2;
	TEdit *PasswordEdit;
	TButton *LogInButton;
	TLabel *MessageLabel;
	void __fastcall LogInButtonClick(TObject *Sender);
	void __fastcall FormCreate(TObject *Sender);
	void __fastcall PasswordEditValidating(TObject *Sender, UnicodeString &Text);
	void __fastcall FormClose(TObject *Sender, TCloseAction &Action);










private:	// User declarations
public:		// User declarations
	__fastcall TMyLoginForm(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TMyLoginForm *MyLoginForm;
//---------------------------------------------------------------------------
#endif
