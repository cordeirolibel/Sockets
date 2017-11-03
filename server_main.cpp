#include <FL/Fl.H>
#include <FL/Fl_Window.H>
#include <FL/Fl_Box.H>
#include <FL/Fl_Button.H>
#include <FL/Fl_Input.H>
#include <FL/Fl_Text_Display.H>

#include "ServerSocket.h"
#include "SocketException.h"
#include <string>
#include <iostream>

using namespace std;
Fl_Window *window;

ServerSocket *server;
ServerSocket *new_sock;

Fl_Input *send_input;
Fl_Box *bin_send_box;
Fl_Box *ami_send_box;

Fl_Box *bin_receive_box;
Fl_Box *ami_receive_box;
Fl_Box *receive_box;

string ascii_to_bin(string str){
	return ("bin:"+str);
}
string bin_to_ami(string str){
	return ("ami:"+str);
}
string ami_to_bin(string str){
	return (str.substr(4));
}
string bin_to_ascii(string str){
	return (str.substr(4));
}

void send_button_pushed(Fl_Widget*, long int) {

	string data = send_input->value();

	string bin = ascii_to_bin(data);
	string ami = bin_to_ami(bin);

	try	{
		*new_sock << ami;
		*new_sock >> ami;
	}
	catch ( SocketException& ) {}

	bin = "Binario: "+bin;
	ami = "AMI: "+ami;
	bin_send_box->copy_label(bin.c_str());
	ami_send_box->copy_label(ami.c_str());

	cout << "Send: " << data << endl;
	cout << "  " << bin << endl;
	cout << "  " << ami << endl;

	window->redraw();
}

void receive_button_pushed(Fl_Widget*, long int) {
	
	string data;

	try	{
		*new_sock >> data;
		*new_sock << data;
	}
	catch ( SocketException& ) {}

	string bin = ami_to_bin(data);
	string ascii = bin_to_ascii(bin);

	data = "AMI: "+data;
	bin = "Binario: "+bin;
	bin_receive_box->copy_label(bin.c_str());
	ami_receive_box->copy_label(data.c_str());
	receive_box->copy_label(ascii.c_str());
	cout << bin_receive_box->label() << ami_receive_box->label() <<receive_box->label()<< endl;

	cout << "Receive: " << ascii << endl;
	cout << "  " << bin << endl;
	cout << "  " << data << endl;

	window->redraw();
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
	int w_max = Fl::w()/2.5;
	int h_max = Fl::h()/2.5;
	int w{w_max}, h{h_max};
	string title{"Server Socket"};
	window = new Fl_Window(w, 0, w, h, title.c_str());

	// Titulo no topo
	char str1[] = "Server Socket: Comunicacao de Dados (UTFPR)";
	Fl_Box *box1 = new Fl_Box(w_max*0.05,h_max*0.05,w_max*0.9,h_max*0.05,str1);
	box1->labelsize(16);
	box1->labelfont(FL_BOLD);

	// Creditos no final
	char str2[] = "Credits: https://github.com/gabrielsouzaesilva and https://github.com/cordeirolibel/";
	Fl_Box *box2 = new Fl_Box(w_max*0.05,h_max*0.95,w_max*0.9,h_max*0.05,str2);
	box2->labelsize(10);

	// Send Line
	send_input = new Fl_Input (w_max*0.15 , h_max*0.15, w_max*0.4, h_max*0.08, "Data:");
	Fl_Button *send_button = new Fl_Button(w_max*0.6, h_max*0.15, w_max*0.2, h_max*0.08, "Send");
	send_button->callback(send_button_pushed);

	// Binario e AMI send lines
	bin_send_box = new Fl_Box(w_max*0.05,h_max*0.35,w_max*0.9,h_max*0.05,"Binario: ");
	bin_send_box->align (FL_ALIGN_TOP_LEFT );
	ami_send_box = new Fl_Box(w_max*0.05,h_max*0.45,w_max*0.9,h_max*0.05,"AMI: ");
	ami_send_box->align (FL_ALIGN_TOP_LEFT );

	// Receive Line
	receive_box = new Fl_Box (w_max*0.15 , h_max*0.55, w_max*0.4, h_max*0.08, "--");
	Fl_Button *receive_button = new Fl_Button(w_max*0.6, h_max*0.55, w_max*0.2, h_max*0.08, "Receive");
	receive_button->callback(receive_button_pushed);

	// Binario e AMI receive lines
	bin_receive_box = new Fl_Box(w_max*0.05,h_max*0.75,w_max*0.9,h_max*0.05,"Binario: ");
	bin_receive_box->align (FL_ALIGN_TOP_LEFT );
	ami_receive_box = new Fl_Box(w_max*0.05,h_max*0.85,w_max*0.9,h_max*0.05,"AMI: ");
	ami_receive_box->align (FL_ALIGN_TOP_LEFT );

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
			Fl::wait(1);
		}
			
	}
	return 0;
}
