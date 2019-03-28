// wxWidgets "Hello World" Program
// For compilers that support precompilation, includes "wx/wx.h".
#include <Interface.hpp>
#include <wx/wxprec.h>
#ifndef WX_PRECOMP
    #include <wx/wx.h>
#endif

bool MyApp::OnInit()
{   
	// Création de la fenetre avec définition de la Taille et positionnement de la fenetre sur l'écran
    MyFrame *frame = new MyFrame("RPN Calculator", wxPoint(50, 50), wxSize(370, 188) );
	
	// Fonction permettant d'afficher la fenêtre
    frame->Show(true);
    return true;
}

MyFrame::MyFrame(const wxString& title, const wxPoint& pos, const wxSize& size) 
: wxFrame(NULL, wxID_ANY, title, pos, size)
{
    wxMenu *menuFile = new wxMenu;
    menuFile->Append(ID_Hello, "&Hello...\tCtrl-H",
                     "Help string shown in status bar for this menu item");

    menuFile->AppendSeparator();
    menuFile->Append(wxID_EXIT);
    
    wxMenu *menuHelp = new wxMenu;
    menuHelp->Append(wxID_ABOUT);
    
    wxMenuBar *menuBar = new wxMenuBar;
    menuBar->Append(menuFile, "&File");
    menuBar->Append(menuHelp, "&Help");
    
    SetMenuBar( menuBar );
    CreateStatusBar(2 ,wxID_ANY);

    SetStatusText("Welcome to wxWidgets!");

    Bind(wxEVT_MENU, &MyFrame::OnHello, this, ID_Hello);
    Bind(wxEVT_MENU, &MyFrame::OnAbout, this, wxID_ABOUT);
    Bind(wxEVT_MENU, &MyFrame::OnExit, this, wxID_EXIT);
    Bind(wxEVT_BUTTON, &MyFrame::Touche_0_Clicked, this, ID_BT_0);

    // Création des boutons avec définition de la Taille et positionnement des boutons par rapport aux autres
	// Largeur bouton : 60, Hauteur : 27, Largeur entre les boutons : 5
	
	// Ligne 4/4 par rapport aux boutons
     btnPi = new wxButton(this, ID_BT_PI, _T("PI"), wxPoint(5,133),wxSize(60, 27));
     btnPourcent = new wxButton(this, ID_BT_POURCENT, _T("%"), wxPoint(5+60, 133),wxSize(60, 27));
	 btnPlus = new wxButton(this, ID_BT_PLUS, _T("+"), wxPoint(5+2*60, 133),wxSize(60, 27));
	 btn0 = new wxButton(this, ID_BT_0, _T("0"), wxPoint(5+3*60, 133),wxSize(60, 27));
	 btnVirgule = new wxButton(this, ID_BT_VIRGULE, _T(","), wxPoint(5+4*60, 133),wxSize(60, 27));
	 btnEgale = new wxButton(this, ID_BT_EGALE, _T("="), wxPoint(5+5*60, 133),wxSize(60, 27));

	
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
		btnEgale->SetBackgroundColour(wxColour(255, 0, 0,70));
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
	
	// Création de la zone wxTextCtrl permettant d'afficher et de récupérer les valeurs
	// avec une taille et une position fixe dans la fenêtre
    BoxResult = new wxTextCtrl(this,wxID_ANY, wxT(""), wxPoint(5,-70),wxSize(360, 180));
    BoxResult->SetEditable(false); //On rend la zone de text non editable au clavier
	
	btn0->Connect(wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(MyFrame::Touche_0_Clicked),NULL, this);
    
}

MyFrame::~MyFrame()
{
    btn0->Disconnect(wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(MyFrame::Touche_0_Clicked),NULL, this);
}

void MyFrame::OnExit(wxCommandEvent& event)
{
    Close(true);
}
void MyFrame::OnAbout(wxCommandEvent& event)
{
    wxMessageBox("This is a wxWidgets Hello World example",
                 "About Hello World", wxOK | wxICON_INFORMATION);
}
void MyFrame::OnHello(wxCommandEvent& event)
{
    wxLogMessage("Hello world from wxWidgets!");
}

/*-_-_-_-_-_-_-_-_-_-_-* BOUTON Operation *-_-_-_-_-_-_-_-_-_-_-*/

//void MyFrame::Touche_FOIS_Clicked(wxCommandEvent &event)
//{
	//*BoxResult << ("x");
	//calcul+="x";
	
//}

//void MyFrame::Touche_DIV_Clicked(wxCommandEvent &event)
//{
	//*BoxResult <<("/");
	//calcul+="/";
//}

//void MyFrame::Touche_PLUS_Clicked(wxCommandEvent &event)
//{
	//*BoxResult <<("+");
	//calcul+="+";
//}

//void MyFrame::Touche_MOINS_Clicked(wxCommandEvent &event)
//{
	//*BoxResult <<("-");
	//calcul+="-";
//}

//void MyFrame::Touche_PUISS2_Clicked(wxCommandEvent &event){
	//*BoxResult <<("^2");
	//calcul+="^2";
//}

//void MyFrame::Touche_PI_Clicked(wxCommandEvent &event)
//{
	//*BoxResult <<("3,14");
	//calcul+="3,14";                                   
//}

//void MyFrame::Touche_POURCENT_Clicked(wxCommandEvent &event)
//{
	//*BoxResult <<("%");
	//calcul+="%";                                   
//}




////*-_-_-_-_-_-_-_-_-_-_-* BOUTON CHIFFRE *-_-_-_-_-_-_-_-_-_-_-*//

void MyFrame::Touche_0_Clicked(wxCommandEvent &event)
{
    BoxResult->AppendText("0");
    //BoxResult << "0";
	//calcul+="0";
}

//void MyFrame::Touche_1_Clicked(wxCommandEvent &event)
//{
	//*BoxResult << "1";
	//calcul+="1";
//}

//void MyFrame::Touche_2_Clicked(wxCommandEvent &event)
//{
	//*BoxResult << "2";
	//calcul+="2";
//}

//void MyFrame::Touche_3_Clicked(wxCommandEvent &event)
//{
	//*BoxResult << "3";
	//calcul+="3";
//}

//void MyFrame::Touche_4_Clicked(wxCommandEvent &event)
//{
	//*BoxResult << "4";
	//calcul+="4";
//}

//void MyFrame::Touche_5_Clicked(wxCommandEvent &event)
//{
	//*BoxResult << "5";
	//calcul+="5";
//}

//void MyFrame::Touche_6_Clicked(wxCommandEvent &event)
//{
	//*BoxResult << "6";
	//calcul+="6";
//}

//void MyFrame::Touche_7_Clicked(wxCommandEvent &event)
//{
	//*BoxResult << "7";
	//calcul+="7";
//}

//void MyFrame::Touche_8_Clicked(wxCommandEvent &event)
//{
	//*BoxResult << "8";
	//calcul+="8";
//}

//void MyFrame::Touche_9_Clicked(wxCommandEvent &event)
//{
	//*BoxResult << "9";
	//calcul+="9";
//}

//void MyFrame::Touche_VIRGULE_Clicked(wxCommandEvent &event)
//{
	//*BoxResult << (",");
	//calcul+=",";
//}


/*-_-_-_-_-_-_-_-_-_-_-*BOUTON M *-_-_-_-_-_-_-_-_-_-_-*/
/*

void MyFrame::Touche_MC_Clicked(wxCommandEvent &event)
{
	//La touche MC permet d’effacer la mémoire.
	if(!save.empty())
		{save.clear();}
		btnClr->Disable();
		btnMR->Disable();
	//Penser à déactiver un bouton MC dans le cas où y a rien dans la mémoire (regarder comment le déactiver )
	
}

void MyFrame::Touche_MPLUS_Clicked(wxCommandEvent &event)
{ 
	//La touche M+ permet d’ajouter le nombre actuellement affiché sur l'écran de la calculatrice à la mémoire
	double val;
	if(*BoxResult->GetValue() .ToDouble(&val))
    {   
	 	if(!save.empty()){
	    		save.clear();                        //effacer le contenu de la chaine si la varaibale save n'est pas vide.
	    	}
	    	save <<val;
	    btnClr->Enable();
   		btnMR->Enable();
	}	
}

void MyFrame::Touche_MR_Clicked(wxCommandEvent &event)
{

	 //La touche MR permet d'afficher la valeur de la mémoire
   *BoxResult->SetValue(save);
   calcul+=save; //sauvgarder l'element stoker en mémoire dans Calcul
}





/*-_-_-_-_-_-_-_-_-_-_-* BOUTON AUTRES *-_-_-_-_-_-_-_-_-_-_-*/
/*
void MyFrame::Touche_DEL_Clicked(wxCommandEvent &event)
{
	if(!calcul.empty()){
		calcul.pop_back();
		*BoxResult->Clear();
		*BoxResult->Append->calcul;	
	}
	
}

void MyFrame::Touche_CLEAR_Clicked(wxCommandEvent &event)
{
	*BoxResult->Clear();
	calcul.clear();
}

void MyFrame::Touche_EGALE_Clicked(wxCommandEvent &event)
{
	if(!calcul.empty()){
		Calculator c(calcul); //Effectue le calcul
		BoxResult->Clear(); //Efface la zone d'affichage
		BoxResult <<c.getResult(); //Affiche le resultat
		calcul=c.getResult(); //Stock le resultat dans calcul pour faire un nouveau calcul avec le resultat
	}
}
*/
