#define INTERFACE_MAIN
#ifndef INTERFACE_MAIN
//Mettre en commentaire le define pour éviter les conflits de main hors des tests
#else
// For compilers that support precompilation, includes "wx/wx.h".
#include "interface.hpp"
#include "calculator.h"
#include <string>
#include <wx/wxprec.h>
#ifndef WX_PRECOMP
    #include <wx/wx.h>
#endif

using namespace std;

Calculator my_calc;

bool MyApp::OnInit()
{   
    // Création de l'objet calculatrice
	// Création de la fenetre avec définition de la Taille et positionnement de la fenetre sur l'écran
    MyFrame *frame = new MyFrame("RPN Calculator", wxPoint(50, 50), wxSize(370, 165), wxDEFAULT_FRAME_STYLE & ~(wxRESIZE_BORDER));
    //MyFrame *frame = new MyFrame("RPN Calculator", wxPoint(50, 50), wxSize(370, 165));
	// Fonction permettant d'afficher la fenêtre
    frame->Show(true);
    return true;
}

MyFrame::MyFrame(const wxString& title, const wxPoint& pos, const wxSize& size, long style)
: wxFrame(NULL, wxID_ANY, title, pos, size, style)
{
    wxMenu *menuHelp = new wxMenu;
    menuHelp->Append(wxID_ABOUT);
    
    wxMenuBar *menuBar = new wxMenuBar;

    menuBar->Append(menuHelp, "&Help");

    SetMenuBar( menuBar );

    Bind(wxEVT_MENU, &MyFrame::OnHello, this, ID_Hello);
    Bind(wxEVT_MENU, &MyFrame::OnAbout, this, wxID_ABOUT);
    Bind(wxEVT_MENU, &MyFrame::OnExit, this, wxID_EXIT);

    // Création des boutons avec définition de la Taille et positionnement des boutons par rapport aux autres
	// Largeur bouton : 60, Hauteur : 27, Largeur entre les boutons : 5
	
	// Ligne 4/4 par rapport aux boutons
     btnPi = new wxButton(this, ID_BT_PI, _T("PI"), wxPoint(5,133),wxSize(60, 27));
     btnPourcent = new wxButton(this, ID_BT_POURCENT, _T("%"), wxPoint(5+60, 133),wxSize(60, 27));
	 btnPlus = new wxButton(this, ID_BT_PLUS, _T("+"), wxPoint(5+2*60, 133),wxSize(60, 27));
	 btn0 = new wxButton(this, ID_BT_0, _T("0"), wxPoint(5+3*60, 133),wxSize(60, 27));
	 btnVirgule = new wxButton(this, ID_BT_VIRGULE, _T(","), wxPoint(5+4*60, 133),wxSize(60, 27));
     btnEnter = new wxButton(this, ID_BT_ENTER, _T("ENTER"), wxPoint(5+5*60, 133),wxSize(60, 27));

	
	// Ligne 3/4 par rapport aux boutons
	 btnPuiss2 = new wxButton(this, ID_BT_PUISS2, _T("^2"), wxPoint(5,133-32),wxSize(60, 27));
	 btnMC = new wxButton(this, ID_BT_MC, _T("MC"), wxPoint(5+60, 133-32),wxSize(60, 27));
	 btnMoins = new wxButton(this, ID_BT_MOINS, _T("-"), wxPoint(5+2*60, 133-32),wxSize(60, 27));
	 btn1 = new wxButton(this, ID_BT_1, _T("1"), wxPoint(5+3*60, 133-32),wxSize(60, 27));
	 btn2 = new wxButton(this, ID_BT_2, _T("2"), wxPoint(5+4*60, 133-32),wxSize(60, 27));
	 btn3 = new wxButton(this, ID_BT_3, _T("3"), wxPoint(5+5*60, 133-32),wxSize(60, 27));
	
	// Ligne 2/4 par rapport aux boutons
	 btnClr = new wxButton(this, ID_BT_CLR, _T("Clear"), wxPoint(5,133-2*32),wxSize(60, 27));
     btnMR = new wxButton(this, ID_BT_MR, _T("MR"), wxPoint(5+60, 133-2*32),wxSize(60, 27));
	 btnFois = new wxButton(this, ID_BT_FOIS, _T("x"), wxPoint(5+2*60, 133-2*32),wxSize(60, 27));
	 btn4 = new wxButton(this, ID_BT_4, _T("4"), wxPoint(5+3*60, 133-2*32),wxSize(60, 27));
	 btn5 = new wxButton(this, ID_BT_5, _T("5"), wxPoint(5+4*60, 133-2*32),wxSize(60, 27));
	 btn6 = new wxButton(this, ID_BT_6, _T("6"), wxPoint(5+5*60, 133-2*32),wxSize(60, 27));
	
	// Ligne 1/4 par rapport aux boutons
	 btnDel = new wxButton(this, ID_BT_DEL, _T("Del"), wxPoint(5,133-3*32),wxSize(60, 27));
     btnMemPlus = new wxButton(this, ID_BT_MPLUS, _T("Mem+"), wxPoint(5+60, 133-3*32),wxSize(60, 27));
	 btnDiviser = new wxButton(this, ID_BT_DIVISER, _T("/"), wxPoint(5+2*60, 133-3*32),wxSize(60, 27));
	 btn7 = new wxButton(this, ID_BT_7, _T("7"), wxPoint(5+3*60, 133-3*32),wxSize(60, 27));
	 btn8 = new wxButton(this, ID_BT_8, _T("8"), wxPoint(5+4*60, 133-3*32),wxSize(60, 27));
	 btn9 = new wxButton(this, ID_BT_9, _T("9"), wxPoint(5+5*60, 133-3*32),wxSize(60, 27));
	
        btnPlus->SetBackgroundColour(wxColour(250, 164, 1,100));
		btnFois->SetBackgroundColour(wxColour(250, 164, 1,100));
		btnMoins->SetBackgroundColour(wxColour(250, 164, 1,100));
		btnDiviser->SetBackgroundColour(wxColour(250, 164, 1,100));
        btnEnter->SetBackgroundColour(wxColour(255, 0, 0,70));
		btnClr->SetBackgroundColour(wxColour(187, 210, 225,70));
		btnDel->SetBackgroundColour(wxColour(255, 0, 0,70));
		btnMR->SetBackgroundColour(wxColour(187, 210, 225,70));
        btnPi->SetBackgroundColour(wxColour(187, 210, 225,70));
		btnMR->SetBackgroundColour(wxColour(187, 210, 225,70));
		btnMC->SetBackgroundColour(wxColour(187, 210, 225,70));
		btnPuiss2->SetBackgroundColour(wxColour(187, 210, 225,70));
		btnPourcent->SetBackgroundColour(wxColour(187, 210, 225,70));
		btnMemPlus->SetBackgroundColour(wxColour(187, 210, 225,70));
	
	wxFont myFont(9, wxFONTFAMILY_MODERN, wxNORMAL, wxFONTWEIGHT_BOLD);
	this->SetFont(myFont);
	
	// Création de la zone wxTextCtrl permettant d'afficher et de récupérer les valeurs
	// avec une taille et une position fixe dans la fenêtre
    BoxResult = new wxTextCtrl(this,wxID_ANY, wxT("0"), wxPoint(5,-70),wxSize(360, 180), wxTE_RIGHT);
    BoxResult->SetEditable(false); //On rend la zone de texte non editable au clavier
	
	btn0->Connect(wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(MyFrame::Touche_0_Clicked),NULL, this);
    btn1->Connect(wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(MyFrame::Touche_1_Clicked),NULL, this);
    btn2->Connect(wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(MyFrame::Touche_2_Clicked),NULL, this);
    btn3->Connect(wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(MyFrame::Touche_3_Clicked),NULL, this);
    btn4->Connect(wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(MyFrame::Touche_4_Clicked),NULL, this);
    btn5->Connect(wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(MyFrame::Touche_5_Clicked),NULL, this);
    btn6->Connect(wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(MyFrame::Touche_6_Clicked),NULL, this);
    btn7->Connect(wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(MyFrame::Touche_7_Clicked),NULL, this);
    btn8->Connect(wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(MyFrame::Touche_8_Clicked),NULL, this);
    btn9->Connect(wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(MyFrame::Touche_9_Clicked),NULL, this);
    btnPi->Connect(wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(MyFrame::Touche_PI_Clicked),NULL, this);
    btnPourcent->Connect(wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(MyFrame::Touche_POURCENT_Clicked),NULL, this);
    btnPlus->Connect(wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(MyFrame::Touche_PLUS_Clicked),NULL, this);
    btnVirgule->Connect(wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(MyFrame::Touche_VIRGULE_Clicked),NULL, this);
    btnEnter->Connect(wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(MyFrame::Touche_ENTER_Clicked),NULL, this);
    btnPuiss2->Connect(wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(MyFrame::Touche_PUISS2_Clicked),NULL, this);
    btnMC->Connect(wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(MyFrame::Touche_MC_Clicked),NULL, this);
    btnMoins->Connect(wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(MyFrame::Touche_MOINS_Clicked),NULL, this);
    btnClr->Connect(wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(MyFrame::Touche_CLEAR_Clicked),NULL, this);
    btnMR->Connect(wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(MyFrame::Touche_MR_Clicked),NULL, this);
    btnFois->Connect(wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(MyFrame::Touche_FOIS_Clicked),NULL, this);
    btnDel->Connect(wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(MyFrame::Touche_DEL_Clicked),NULL, this);
    btnMemPlus->Connect(wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(MyFrame::Touche_MPLUS_Clicked),NULL, this);
    btnDiviser->Connect(wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(MyFrame::Touche_DIV_Clicked),NULL, this);
}

MyFrame::~MyFrame()
{
    btn0->Disconnect(wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(MyFrame::Touche_0_Clicked),NULL, this);
    btn1->Disconnect(wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(MyFrame::Touche_1_Clicked),NULL, this);
    btn2->Disconnect(wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(MyFrame::Touche_2_Clicked),NULL, this);
    btn3->Disconnect(wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(MyFrame::Touche_3_Clicked),NULL, this);
    btn4->Disconnect(wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(MyFrame::Touche_4_Clicked),NULL, this);
    btn5->Disconnect(wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(MyFrame::Touche_5_Clicked),NULL, this);
    btn6->Disconnect(wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(MyFrame::Touche_6_Clicked),NULL, this);
    btn7->Disconnect(wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(MyFrame::Touche_7_Clicked),NULL, this);
    btn8->Disconnect(wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(MyFrame::Touche_8_Clicked),NULL, this);
    btn9->Disconnect(wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(MyFrame::Touche_9_Clicked),NULL, this);
    btnEnter->Disconnect(wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(MyFrame::Touche_ENTER_Clicked),NULL, this);
}

void MyFrame::OnExit(wxCommandEvent& event)
{
    Close(true);
}
void MyFrame::OnAbout(wxCommandEvent& event)
{
    wxMessageBox("Authors : Arnaud Queftaigne, Damien Virgiglio, Mathieu Fernandez, T. M.-F.",
                 "About", wxOK | wxICON_INFORMATION);
}
void MyFrame::OnHello(wxCommandEvent& event)
{
    wxLogMessage("Hello world from wxWidgets!");
}

/*-_-_-_-_-_-_-_-_-_-_-* BOUTON Operation *-_-_-_-_-_-_-_-_-_-_-*/

void MyFrame::Touche_FOIS_Clicked(wxCommandEvent &event)
{
    // Si on n'a pas fait d'opération juste avant
    if (!my_calc.operatorFlagEnabled() && BoxResult->GetValue() != "ERROR")
    {
        // On convertit la wxString en string standard
        wxString temp_wxstring(BoxResult->GetValue());
        std::string stlstring = std::string(temp_wxstring.mb_str());

        // On transforme la string en double et on l'empile dans my_calc
        double number = stod(stlstring, NULL);
        my_calc.pushNumber(number);
    }
    BoxResult->Clear();
    BoxResult->AppendText(my_calc.multiply());
}

void MyFrame::Touche_DIV_Clicked(wxCommandEvent &event)
{
    if (!my_calc.operatorFlagEnabled() && BoxResult->GetValue() != "ERROR")
    {
        wxString temp_wxstring(BoxResult->GetValue());
        std::string stlstring = std::string(temp_wxstring.mb_str());
        double number = stod(stlstring, NULL);
        my_calc.pushNumber(number);
    }

    BoxResult->Clear();
    BoxResult->AppendText(my_calc.divide());
}

void MyFrame::Touche_PLUS_Clicked(wxCommandEvent &event)
{
    if (!my_calc.operatorFlagEnabled() && BoxResult->GetValue() != "ERROR")
    {
        wxString temp_wxstring(BoxResult->GetValue());
        std::string stlstring = std::string(temp_wxstring.mb_str());
        double number = stod(stlstring, NULL);
        my_calc.pushNumber(number);
    }

    BoxResult->Clear();
    BoxResult->AppendText(my_calc.add());
}

void MyFrame::Touche_MOINS_Clicked(wxCommandEvent &event)
{
    if (!my_calc.operatorFlagEnabled() && BoxResult->GetValue() != "ERROR")
    {
        wxString temp_wxstring(BoxResult->GetValue());
        std::string stlstring = std::string(temp_wxstring.mb_str());
        double number = stod(stlstring, NULL);
        my_calc.pushNumber(number);
    }

    BoxResult->Clear();
    BoxResult->WriteText(my_calc.substract());
}

void MyFrame::Touche_PUISS2_Clicked(wxCommandEvent &event)
{
    if (!my_calc.operatorFlagEnabled() && BoxResult->GetValue() != "ERROR")
    {
        wxString temp_wxstring(BoxResult->GetValue());
        std::string stlstring = std::string(temp_wxstring.mb_str());
        double number = stod(stlstring, NULL);
        my_calc.pushNumber(number);
    }

    BoxResult->Clear();
    BoxResult->WriteText(my_calc.square());
}

void MyFrame::Touche_PI_Clicked(wxCommandEvent &event)
{
    BoxResult->Clear();
    BoxResult->AppendText(std::to_string(3.141592));
    my_calc.enterFlagDisable();
    my_calc.operatorFlagDisable();
}

void MyFrame::Touche_POURCENT_Clicked(wxCommandEvent &event)
{
    if (!my_calc.operatorFlagEnabled() && BoxResult->GetValue() != "ERROR")
    {
        wxString temp_wxstring(BoxResult->GetValue());
        std::string stlstring = std::string(temp_wxstring.mb_str());
        double number = stod(stlstring, NULL);
        my_calc.pushNumber(number);
    }

    BoxResult->Clear();
    BoxResult->WriteText(my_calc.percent());
}

////*-_-_-_-_-_-_-_-_-_-_-* BOUTON CHIFFRE *-_-_-_-_-_-_-_-_-_-_-*//

void MyFrame::Touche_0_Clicked(wxCommandEvent &event)
{
    if (BoxResult->GetValue() == "0")
        return;

    if (my_calc.enterFlagEnabled())
        BoxResult->Clear();

    BoxResult->AppendText("0");
    my_calc.enterFlagDisable();
    my_calc.operatorFlagDisable();
}

void MyFrame::Touche_1_Clicked(wxCommandEvent &event)
{
    if (BoxResult->GetValue() == "0" || my_calc.enterFlagEnabled())
        BoxResult->Clear();

    BoxResult->AppendText("1");
    my_calc.enterFlagDisable();
    my_calc.operatorFlagDisable();
}

void MyFrame::Touche_2_Clicked(wxCommandEvent &event)
{
    if (BoxResult->GetValue() == "0" || my_calc.enterFlagEnabled())
        BoxResult->Clear();

    BoxResult->AppendText("2");
    my_calc.enterFlagDisable();
    my_calc.operatorFlagDisable();
}

void MyFrame::Touche_3_Clicked(wxCommandEvent &event)
{
    if (BoxResult->GetValue() == "0" || my_calc.enterFlagEnabled())
        BoxResult->Clear();

    BoxResult->AppendText("3");
    my_calc.enterFlagDisable();
    my_calc.operatorFlagDisable();
}

void MyFrame::Touche_4_Clicked(wxCommandEvent &event)
{
    if (BoxResult->GetValue() == "0" || my_calc.enterFlagEnabled())
        BoxResult->Clear();

    BoxResult->AppendText("4");
    my_calc.enterFlagDisable();
    my_calc.operatorFlagDisable();
}

void MyFrame::Touche_5_Clicked(wxCommandEvent &event)
{
    if (BoxResult->GetValue() == "0" || my_calc.enterFlagEnabled())
        BoxResult->Clear();

    BoxResult->AppendText("5");
    my_calc.enterFlagDisable();
    my_calc.operatorFlagDisable();
}

void MyFrame::Touche_6_Clicked(wxCommandEvent &event)
{
    if (BoxResult->GetValue() == "0" || my_calc.enterFlagEnabled())
        BoxResult->Clear();

    BoxResult->AppendText("6");
    my_calc.enterFlagDisable();
    my_calc.operatorFlagDisable();
}

void MyFrame::Touche_7_Clicked(wxCommandEvent &event)
{
    if (BoxResult->GetValue() == "0" || my_calc.enterFlagEnabled())
        BoxResult->Clear();

    BoxResult->AppendText("7");
    my_calc.enterFlagDisable();
    my_calc.operatorFlagDisable();
}

void MyFrame::Touche_8_Clicked(wxCommandEvent &event)
{
    if (BoxResult->GetValue() == "0" || my_calc.enterFlagEnabled())
        BoxResult->Clear();
    BoxResult->AppendText("8");
    my_calc.enterFlagDisable();
    my_calc.operatorFlagDisable();
}

void MyFrame::Touche_9_Clicked(wxCommandEvent &event)
{
    if (BoxResult->GetValue() == "0" || my_calc.enterFlagEnabled())
        BoxResult->Clear();

    BoxResult->AppendText("9");
    my_calc.enterFlagDisable();
    my_calc.operatorFlagDisable();
}

void MyFrame::Touche_VIRGULE_Clicked(wxCommandEvent &event)
{
    wxString sTemp = BoxResult->GetValue();

    if (sTemp.Find(".") == wxNOT_FOUND)
    {
            if (my_calc.enterFlagEnabled())
            {
                BoxResult->Clear();
                BoxResult->AppendText("0");
            }

            BoxResult->AppendText(".");
            my_calc.enterFlagDisable();
            my_calc.operatorFlagDisable();
    }
}


/*-_-_-_-_-_-_-_-_-_-_-*BOUTON M *-_-_-_-_-_-_-_-_-_-_-*/

void MyFrame::Touche_MC_Clicked(wxCommandEvent &event)
{
    // OBJECTIF : vider la pile mémoire de Calculator

    if (BoxResult->GetValue() == "ERROR")
    {
        BoxResult->Clear();
        BoxResult->AppendText("0");
    }


    my_calc.flushStack();

    my_calc.enterFlagDisable();
    my_calc.operatorFlagDisable();
}

void MyFrame::Touche_MPLUS_Clicked(wxCommandEvent &event)
{
    wxString sTemp = BoxResult->GetValue();
    if (sTemp != "" && sTemp != "ERROR")
    {
        wxString temp_wxstring(BoxResult->GetValue());
        std::string stlstring = std::string(temp_wxstring.mb_str());
        double number = stod(stlstring, NULL);
        my_calc.addToTop(number);
    }

}

void MyFrame::Touche_MR_Clicked(wxCommandEvent &event)
{
    // Afficher le dernier nombre en mémoire
    BoxResult->Clear();
    BoxResult->AppendText(my_calc.displayTop());
}

/*-_-_-_-_-_-_-_-_-_-_-* BOUTON AUTRES *-_-_-_-_-_-_-_-_-_-_-*/

void MyFrame::Touche_DEL_Clicked(wxCommandEvent &event)
{
    // OBJECTIF : effacer le dernier caractère tapé
    wxString sTemp = BoxResult->GetValue();
    if (sTemp != "ERROR")
    {
        sTemp.RemoveLast();
        BoxResult->Clear();

        if(sTemp == "")
            BoxResult->AppendText("0");
        else
            BoxResult->AppendText(sTemp);
    }
    else
    {
        BoxResult->Clear();
        BoxResult->AppendText("0");
    }
}

void MyFrame::Touche_CLEAR_Clicked(wxCommandEvent &event)
{
    // OBJECTIF : réinitialiser la zone d'affichage sans toucher à la mémoire
    BoxResult->Clear();
    BoxResult->AppendText("0");
    my_calc.operatorFlagDisable();
}

void MyFrame::Touche_ENTER_Clicked(wxCommandEvent &event)
{
    // OBJECTIF : capturer le nombre dans l'afficheur pour l'empiler dans Calculator

    // On convertit la wxString en string standard
    if (BoxResult->GetValue() != "ERROR")
    {
        wxString temp_wxstring(BoxResult->GetValue());
        std::string stlstring = std::string(temp_wxstring.mb_str());

        // On transforme la string en double et on l'empile
        double number = stod(stlstring, NULL);
        my_calc.pushNumber(number);
    }
}

#endif
