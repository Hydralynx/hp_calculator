#include <wx/wxprec.h>
#ifndef WX_PRECOMP
    #include <wx/wx.h>
#endif

class MyApp : public wxApp
{
public:
    virtual bool OnInit();
};

class MyFrame : public wxFrame
{
public:
    MyFrame(const wxString& title, const wxPoint& pos, const wxSize& size, long style = wxDEFAULT_FRAME_STYLE);
    ~MyFrame();

protected:

	wxTextCtrl *BoxResult;
    void OnHello(wxCommandEvent& event);
    void OnExit(wxCommandEvent& event);
    void OnAbout(wxCommandEvent& event);
    void Touche_0_Clicked(wxCommandEvent &event);
    void Touche_1_Clicked(wxCommandEvent &event);
    void Touche_2_Clicked(wxCommandEvent &event);
    void Touche_3_Clicked(wxCommandEvent &event);
    void Touche_4_Clicked(wxCommandEvent &event);
    void Touche_5_Clicked(wxCommandEvent &event);
    void Touche_6_Clicked(wxCommandEvent &event);
    void Touche_7_Clicked(wxCommandEvent &event);
    void Touche_8_Clicked(wxCommandEvent &event);
    void Touche_9_Clicked(wxCommandEvent &event);
    void Touche_VIRGULE_Clicked(wxCommandEvent &event);
    void Touche_FOIS_Clicked(wxCommandEvent &event);
    void Touche_DIV_Clicked(wxCommandEvent &event);
    void Touche_PLUS_Clicked(wxCommandEvent &event);
    void Touche_MOINS_Clicked(wxCommandEvent &event);
    void Touche_PUISS2_Clicked(wxCommandEvent &event);
    void Touche_PI_Clicked(wxCommandEvent &event);
    void Touche_POURCENT_Clicked(wxCommandEvent &event);
    void Touche_DEL_Clicked(wxCommandEvent &event);
    void Touche_CLEAR_Clicked(wxCommandEvent &event);
    void Touche_EGALE_Clicked(wxCommandEvent &event);
    void Touche_MPLUS_Clicked(wxCommandEvent &event);
    void Touche_MC_Clicked(wxCommandEvent &event);
    void Touche_MR_Clicked(wxCommandEvent &event);
    void Touche_ENTER_Clicked(wxCommandEvent &event);

    wxButton *btnDel,*btnClr,*btnEnter;
	wxButton *btnFois,*btnDiviser,*btnPlus,*btnMoins, *btnPi, *btnPuiss2, *btnPourcent;        
	wxButton *btn0,*btn1,*btn2,*btn3,*btn4,*btn5,*btn6,*btn7,*btn8,*btn9,*btnVirgule;
	wxButton *btnMemPlus, *btnMR, *btnMC;
	 
	wxString calcul=wxT("");
	wxString save=wxT("");
    
};

enum
{
    ID_Hello = 1,
    ID_BT_DIVISER, ID_BT_PLUS,ID_BT_FOIS, ID_BT_MOINS, ID_BT_PI, ID_BT_POURCENT, ID_BT_PUISS2,
    ID_BT_MC,ID_BT_MR,ID_BT_MPLUS,
    ID_BT_0, ID_BT_1, ID_BT_2, ID_BT_3, ID_BT_4, ID_BT_5, ID_BT_6, ID_BT_7, ID_BT_8, ID_BT_9, ID_BT_VIRGULE,
    ID_BT_DEL, ID_BT_CLR, ID_BT_ENTER,

    ID_BOXR
};

wxIMPLEMENT_APP(MyApp);
