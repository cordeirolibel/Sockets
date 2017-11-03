#include <FL/Fl.H>
#include <FL/Fl_Double_Window.H>
#include <FL/Fl_Window.H>
#include <FL/Fl_Box.H>
#include <FL/Fl_Button.H>
#include <FL/Fl_Input.H>
#include <FL/Fl_Text_Display.H>
#include <FL/fl_message.H>

#include "ServerSocket.h"
#include "SocketException.h"
#include <string>
#include <iostream>

using namespace std;

Fl_Box *receive_box;
ServerSocket *server;
ServerSocket *new_sock;

void receive_button_pushed(Fl_Widget*, long int) {
	
	string data;

	try	{
		*new_sock >> data;
		cout << "We received this response from the client:\n\"" << data << "\"\n";
		receive_box->label(data.c_str());
		*new_sock << data;
	}
	catch ( SocketException& ) {}

	cout << "We received this response from the server:\n\"" << data << "\"\n";
}

int main ( ) 
{ 	
	cout << "running....\n";

	try	{
		// Create the socket
		server = new ServerSocket ( 30000 );

	}
	catch ( SocketException& e )
	{
		cout << "Exception was caught:" << e.description() << "\nExiting.\n";
	}

	///======================================================
	/// ===== Criando Janela
	///======================================================

	// Criando janela base
	int w_max = Fl::w()/2;
	int h_max = Fl::h()/2;
	int w{w_max}, h{h_max};
	string title{"Server Socket"};
	Fl_Window *window = new Fl_Window(w, 0, w, h, title.c_str());

	// Titulo no topo
	char str1[] = "Server Socket: Comunicacao de Dados (UTFPR)";
	Fl_Box *box1 = new Fl_Box(w_max*0.05,h_max*0.05,w_max*0.9,h_max*0.05,str1);
	box1->labelsize(16);
	box1->labelfont(FL_BOLD);

	// Creditos no final
	char str2[] = "Credits: https://github.com/gabrielsouzaesilva and https://github.com/cordeirolibel/";
	Fl_Box *box2 = new Fl_Box(w_max*0.05,h_max*0.95,w_max*0.9,h_max*0.05,str2);
	box2->labelsize(10);

	// Receive Line
	receive_box = new Fl_Box (w_max*0.1 , h_max*0.2, w_max*0.4, h_max*0.08, "--");
	Fl_Button *receive_button = new Fl_Button(w_max*0.55, h_max*0.2, w_max*0.2, h_max*0.08, "Receive");
	receive_button->callback(receive_button_pushed);

	///======================================================
	/// ===== Loop
	///======================================================

	window->show();

	int k = 30;
	while(k--){
		Fl::wait(0.01);
	}

	while (true){
		new_sock = new ServerSocket;
		server->accept(*new_sock);
		while(true){
			Fl::wait(0.1);
		}
			
	}
	return 0;
}
