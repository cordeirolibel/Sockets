#include <FL/Fl.H>
#include <FL/Fl_Double_Window.H>
#include <FL/Fl_Window.H>
#include <FL/Fl_Box.H>
#include <FL/Fl_Button.H>
#include <FL/Fl_Input.H>
#include <FL/Fl_Text_Display.H>


#include "ClientSocket.h"
#include "SocketException.h"

#include <iostream>
#include <string>

using namespace std;

ClientSocket *client_socket;
Fl_Input *send_input;

void send_button_pushed(Fl_Widget*, long int) {

	string reply;

	try	{
		*client_socket << send_input->value();
		*client_socket >> reply;
	}
	catch ( SocketException& ) {}

	cout << "We received this response from the server:\n\"" << reply << "\"\n";
}


int main ()
{
	///======================================================
	/// ===== Conectando 
	///======================================================
	try{
		client_socket = new ClientSocket ( "127.0.0.1/8", 30000 );
	}
	catch ( SocketException& e ){
		cout << "Exception was caught:" << e.description() << "\n";
	}
	
	///======================================================
	/// ===== Criando Janela
	///======================================================

	// Criando janela base
	int w_max = Fl::w()/2;
	int h_max = Fl::h()/2;
	int w{w_max}, h{h_max};
	string title{"Client Socket"};
	Fl_Double_Window *window = new Fl_Double_Window(w, 0, w, h, title.c_str());

	// Titulo no topo
	char str1[] = "Client Socket: Comunicacao de Dados (UTFPR)";
	Fl_Box *box1 = new Fl_Box(w_max*0.05,h_max*0.05,w_max*0.9,h_max*0.05,str1);
	box1->labelsize(16);
	box1->labelfont(FL_BOLD);

	// Creditos no final
	char str2[] = "Credits: https://github.com/gabrielsouzaesilva and https://github.com/cordeirolibel/";
	Fl_Box *box2 = new Fl_Box(w_max*0.05,h_max*0.95,w_max*0.9,h_max*0.05,str2);
	box2->labelsize(10);

	// Send Line
	send_input = new Fl_Input (w_max*0.1 , h_max*0.2, w_max*0.4, h_max*0.08, "Data:");
	Fl_Button *send_button = new Fl_Button(w_max*0.55, h_max*0.2, w_max*0.2, h_max*0.08, "Send");
	send_button->callback(send_button_pushed);


	///======================================================
	/// ===== Loop
	///======================================================
	window->show();

	int k = 1;
	while (true){
		cout << k << ' ' << Fl::wait(0.1) << endl;
		k++;
	}



	return 0;
}
