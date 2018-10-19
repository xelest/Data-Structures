
//Authors: HERNANDEZ, Mark Anthony V. & MONSERRATE, Jeremy James
//MALAYAN COLLEGES LAGUNA
//August 12, 2017
//Machine Problem: PATH FINDER

#include <stdio.h>
#include <conio.h>
#include <iostream>
#include <string>
#include <iomanip>
#include <Windows.h>

using namespace std;

int DMAX = 10;
int IMAX = 10;
int GMAX = 7;
struct Node
{
	Node *top = NULL;
	Node *next = NULL;
	Node *prev = NULL;
	Node *bot = NULL;

	bool pass = false;

	string name;

	int dist_top = NULL; //distance from top
	int dist_next = NULL; //distance from next
	int dist_prev = NULL; //distance from prev
	int dist_bot = NULL; //distance from bottom

	string arrDiners[10];
	int arrDinerDistance[10];
	string arrGasStations[7];
	int arrGasStationDistance[7];
	string arrInns[10];
	int arrInnDistance[10];

}*current, *head = NULL, *tail, *newNode, *pin1, *pin2, *pin3, *pin4, *start, *destination;


void nulifier()
{
	newNode->top = NULL;   // 1
	newNode->next = NULL;  // 2
	newNode->prev = NULL;  // 3 
	newNode->bot = NULL;   // 4
	
	//current->next = NULL;  // 1
	//current->prev = NULL;  // 2 
	//current->bot = NULL;   // 3
	//current->top = NULL;   // 4

}
void LocationsList()
{
	// UI - menu for enlisted (default) locations), does not include newly added location on the map
	string locations[20] =
	{
		" [1] San Pedro",
		" [2] Binan",
		" [3] Sta. Rosa",
		" [4] Cabuyao",
		" [5] Calamba",
		" [6] Los Banos",
		" [7] Bay",
		" [8] Victoria",
		" [9] Pila",
		"[10] Sta. Cruz",
		"[11] Pagsanjan",
		"[12] Cavinti",
		"[13] Alaminos",
		"[14] San Pablo",
		"[15] Rizal",
		"[16] Liliw",
		"[17] Luisiana",
		"[18] Calauan",
		"[19] Nagcarlan",
		"[20] Magdalena" };

	cout << endl;
	int col1 = 0, col2 = 5, col3 = 10, col4 = 15;
	cout << "\t==================================================================================" << endl;
	for (int z = 0; z < 5; z++)
	{
		cout << "\t||" << "\t" << locations[col1] << "\t" << locations[col2] << "\t" << locations[col3] << "\t" << locations[col4] << "\t\t||" << endl;
		col1 = col1 + 1; 		col2 = col2 + 1;		col3 = col3 + 1; 		col4 = col4 + 1;
	}
	cout << "\t==================================================================================";
}
void ConsoleMessage(int x) // UI - Selector
{
	char c[150]; string message="";

	string msg1 = ">Console Message > : try again.";
	string msg2 = "select TARGET location: ";
	string msg3 = ">Console Message > : Can't go that direction. Choose a different path.";
	string msg4 = ">Console Message > : Unable to make connection. Choose again.";
	string msg5 = ">Console > : ";
	string msg6 = "Creation Successful. You may check it from main menu. Choose #1";

	if (x == 1) //invalid choice, try again
	{
		message = msg1;
		cout << "\n\t";
		for (int i = 0; i < message.length(); i++)
		{
			c[i] = message.at(i);
			Sleep(15);
			cout << message[i];
		}
		cout << "\n\t"; system("pause");
	}

	else if (x == 2) // message marquee 
	{
		message = msg2; 
		for (int i = 0; i < message.length(); i++)
		{
			c[i] = message.at(i);
			Sleep(15);
			cout << message[i];
		}
		
	}

	else if (x == 3) // message marquee 
	{
		message = msg3;
		cout << "\t";
		for (int i = 0; i < message.length(); i++)
		{
			c[i] = message.at(i);
			Sleep(15);
			cout << message[i];
		}
		cout << "\n\t"; system("pause");
	}

	else if (x == 4) // message marquee 
	{
		message = msg4;
		cout << "\t";
		for (int i = 0; i < message.length(); i++)
		{
			c[i] = message.at(i);
			Sleep(15);
			cout << message[i];
		}
		cout << "\n\t"; system("pause");
	}

	else if (x == 5) // message marquee 
	{
		message = msg5;
		cout << "\t";
		for (int i = 0; i < message.length(); i++)
		{
			c[i] = message.at(i);
			Sleep(15);
			cout << message[i];
		}
		cout << "\n\t"; system("pause");
	}

	else if (x == 6) // message marquee 
	{
		message = msg6;
		cout << "\t";
		for (int i = 0; i < message.length(); i++)
		{
			c[i] = message.at(i);
			Sleep(15);
			cout << message[i];
		}
		cout << "\n\t"; system("pause");
	}
}
void MainMenu()
{
	cout << "\n\t " << endl;
	cout << "\t[1] Select a location." << endl;
	cout << "\t    (view: nearby locations, manually visit each location)\n" << endl;

	cout << "\t[2] Travel Mode." << endl;
	cout << "\t    (select: Starting (from) - Destination (to))\n" << endl;

	cout << "\t[3] Peek-A-View." << endl;
	cout << "\t    (view: nearby establishments, manually visit each location )\n" << endl;

	cout << "\t[4] Register New Establishment." << endl;
	cout << "\t    (Add: a diner / gas station / inn to a certain location)\n" << endl;

	cout << "\t[5] Add a New Location." << endl;
	cout << "\t    (add new location to the map)\n" << endl;

	cout << "\n\t[0] exit" << endl;
	cout << "\n\tchoice: ";
}
void Create_Connect(string Name, int Dist_top, int Dist_prev, int Dist_next, int Dist_bot, int insertion_point)
{
	// Create_Connect(Location Name, Distance from TOP, Distance from NEXT, Distance from PREVIOUS, Distance from BOTTOM, insertion POINT);

	if (insertion_point == 0) // first location
	{
		newNode = new Node;
		nulifier();
		newNode->name = Name;
		newNode->dist_top = Dist_top;
		newNode->dist_next = Dist_next;
		newNode->dist_prev = Dist_prev;
		newNode->dist_bot = Dist_bot;
		head = newNode;
		tail = newNode;
		current = newNode;
	}
	else if (insertion_point == 1) // - insert to tail
	{
		newNode = new Node;
		nulifier();
		newNode->name = Name;
		newNode->dist_top = Dist_top;
		newNode->dist_next = Dist_next;
		newNode->dist_prev = Dist_prev;
		newNode->dist_bot = Dist_bot;
		current->next = newNode;
		newNode->prev = current;
		tail = newNode;
		tail = tail->next;
		current = current->next;
		current = newNode;
	}
	else if (insertion_point == 2) // insert to next, not using tail
	{
		newNode = new Node;
		nulifier();
		newNode->name = Name;
		newNode->dist_top = Dist_top;
		newNode->dist_next = Dist_next;
		newNode->dist_prev = Dist_prev;
		newNode->dist_bot = Dist_bot;
		current->next = newNode;
		newNode->prev = current;
		current = newNode;
	}
	else if (insertion_point == 3) //  insert to bottom, not using tail
	{
		
		newNode = new Node;
		nulifier();
		newNode->name = Name;
		newNode->dist_top = Dist_top;
		newNode->dist_next = Dist_next;
		newNode->dist_prev = Dist_prev;
		newNode->dist_bot = Dist_bot;
		current->bot = newNode;
		newNode->prev = current;
		current = newNode;

	}
	else if (insertion_point == 4) // just create prepa without manipulation
	{
		newNode = new Node;
		nulifier();
		newNode->name = Name;
		newNode->dist_top = Dist_top;
		newNode->dist_next = Dist_next;
		newNode->dist_prev = Dist_prev;
		newNode->dist_bot = Dist_bot;
	}
	else
	{
		ConsoleMessage(1);
	}
	

}
void Preview()
{
	//int target;
	string new_name, top, bot, prev, next;
	//int distance_top, distance_bot, distance_next, distance_prev;

	if (current->top != NULL)
	{
		top = current->top->name;
	}
	else
		top = "  - - - ";
	if (current->next != NULL)
	{

		next = current->next->name;
	}
	else
		next = "  - - - ";
	if (current->prev != NULL)
	{

		prev = current->prev->name;
	}
	else
		prev = "  - - - ";
	if (current->bot != NULL)
	{

		bot = current->bot->name;
	}
	else
		bot = "  - - - ";

	cout << "\tTOP     : " << top << endl;
	cout << "\tRIGHT   : " << next << endl;
	cout << "\tLEFT    : " << prev << endl;
	cout << "\tBOTTOM  : " << bot << endl;
}
void Navbar()
{
	string nav_top, nav_right, nav_left, nav_bottom;
	int Dist_top, Dist_next, Dist_prev, Dist_bot;
	if (current->top != NULL)
	{
		nav_top = current->top->name;
	}
	else
		nav_top = "  - - - ";
	if (current->next != NULL)
	{

		nav_right = current->next->name;
	}
	else
		nav_right = "  - - - ";
	if (current->prev != NULL)
	{

		nav_left = current->prev->name;
	}
	else          
		nav_left = "  - - - ";
	if (current->bot != NULL)
	{

		nav_bottom = current->bot->name;
	}
	else
		nav_bottom = "  - - - ";



	if (current->dist_top != NULL)
	{
		Dist_top = current->dist_top;
	}
	else
		Dist_top = current->dist_top;

	if (current->dist_next != NULL)
	{
		Dist_next = current->dist_next;
	}
	else
		Dist_next = current->dist_next;

	if (current->dist_prev != NULL)
	{
		Dist_prev = current->dist_prev;
	}
	else
		Dist_prev = current->dist_prev;

	if (current->dist_bot != NULL)
	{
		Dist_bot = current->dist_bot;
	}
	else
		Dist_bot = current->dist_bot;

	cout << "\n";
	cout << setw(5) << " " << setw(12) << "" << setw(5) << "[" << nav_top << "]" << setw(16) << " " << setw(7) << "              Loc     Dist" << endl;
	cout << setw(5) << " " << setw(16) << "" << setw(5) << "|" << setw(20) << " " << setw(7) << "  | TOP    : " << nav_top <<setw(5) << Dist_top<< endl;
	cout << setw(5) << " " << setw(5) << "[" << setw(8) << nav_left << "]" << "--" << "[" << current->name << "]" << "--" << "[" << nav_right << "]" << setw(5) << " " << setw(7) << "| LEFT   : " << nav_left << setw(5) << Dist_prev << endl;
	cout << setw(5) << " " << setw(16) << " " << setw(5) << "|" << setw(20) << " " << setw(7) << "  | RIGHT  : " << nav_right << setw(5) << Dist_next << endl;
	cout << setw(5) << " " << setw(12) << " " << setw(5) << "[" << nav_bottom << "]" << setw(16) << " " << setw(7) << " | BOTTOM : " << nav_bottom << setw(5) << Dist_bot << endl;
}
void Navbar_template()
{
	string nav_top, nav_right, nav_left, nav_bottom;
	int Dist_top, Dist_next, Dist_prev, Dist_bot;
	if (newNode->top != NULL)
	{
		nav_top = newNode->top->name;
	}
	else
		nav_top = "  - - - ";
	if (newNode->next != NULL)
	{

		nav_right = newNode->next->name;
	}
	else
		nav_right = "  - - - ";
	if (newNode->prev != NULL)
	{

		nav_left = newNode->prev->name;
	}
	else
		nav_left = "  - - - ";
	if (newNode->bot != NULL)
	{

		nav_bottom = newNode->bot->name;
	}
	else
		nav_bottom = "  - - - ";



	if (newNode->dist_top != NULL)
	{
		Dist_top = newNode->dist_top;
	}
	else
		Dist_top = newNode->dist_top;

	if (newNode->dist_next != NULL)
	{
		Dist_next = newNode->dist_next;
	}
	else
		Dist_next = newNode->dist_next;

	if (newNode->dist_prev != NULL)
	{
		Dist_prev = newNode->dist_prev;
	}
	else
		Dist_prev = newNode->dist_prev;

	if (newNode->dist_bot != NULL)
	{
		Dist_bot = newNode->dist_bot;
	}
	else
		Dist_bot = newNode->dist_bot;

	cout << "\n";
	cout << setw(5) << " " << setw(12) << "" << setw(5) << "[" << nav_top << "]" << setw(16) << " " << setw(7) << "              Loc     Dist" << endl;
	cout << setw(5) << " " << setw(16) << "" << setw(5) << "|" << setw(20) << " " << setw(7) << "  | TOP    : " << nav_top << setw(5) << Dist_top << endl;
	cout << setw(5) << " " << setw(5) << "[" << setw(8) << nav_left << "]" << "--" << "[" << newNode->name << "]" << "--" << "[" << nav_right << "]" << setw(5) << " " << setw(7) << "| LEFT   : " << nav_left << setw(5) << Dist_prev << endl;
	cout << setw(5) << " " << setw(16) << " " << setw(5) << "|" << setw(20) << " " << setw(7) << "  | RIGHT  : " << nav_right << setw(5) << Dist_next << endl;
	cout << setw(5) << " " << setw(12) << " " << setw(5) << "[" << nav_bottom << "]" << setw(16) << " " << setw(7) << " | BOTTOM : " << nav_bottom << setw(5) << Dist_bot << endl;
}
void Visit(int x)
{
	 // only used to set location for current, durring MAP CREATION and visiting EACH NODE
	 // stored pre-defined locations only, does not include newly added locations
	 // this was also used to check EACH node to see which are connected 
	 // note: NOT USED for the algo for the SHORTEST PATH
		for (int i = 0; i < 1; i++)
		{
			current = head;
			if (x == 1) //1. San Pedro
				current = head;
			else if (x == 2) ///2. Binan 
				current = current->next;
			else if (x == 3) //3. Sta. Rosa
				current = current->next->next;
			else if (x == 4) //4. Cabuyao
				current = current->next->next->next;
			else if (x == 5) //5. Calamba
				current = current->next->next->next->next;
			else if (x == 6) //6. Los Banos
				current = current->next->next->next->next->next;
			else if (x == 7) //7.Bay
				current = current->next->next->next->next->next->next;
			else if (x == 8) //8.Victoria
				current = current->next->next->next->next->next->next->next;
			else if (x == 9) //9.Pila
				current = current->next->next->next->next->next->next->next->next;
			else if (x == 10) //10.Sta. Cruz
				current = current->next->next->next->next->next->next->next->next->next;
			else if (x == 11) //11.Lumban
				current = current->next->next->next->next->next->next->next->next->next->next;
			else if (x == 12) //12.Cavinti
				current = current->next->next->next->next->next->next->next->next->next->next->next;
			else if (x == 13) //13.Alaminos
				current = current->next->next->next->next->next->next->bot;
			else if (x == 14) //14.San Pablo
				current = current->next->next->next->next->next->next->bot->next;
			else if (x == 15) //15.Rizal
				current = current->next->next->next->next->next->next->bot->next->next;
			else if (x == 16) //16.Liliw
				current = current->next->next->next->next->next->next->bot->next->next->next;
			else if (x == 17) //17.Luisiana
				current = current->next->next->next->next->next->next->bot->next->next->next->next;
			else if (x == 18) //18.Calauan
				current = current->next->next->next->next->next->next->bot->top;
			else if (x == 19) //19.Nagcarlan
				current = current->next->next->next->next->next->next->next->bot;
			else if (x == 20) //20.Magdalena
				current = current->next->next->next->next->next->next->next->next->bot;
			else if (x == 0)
				break;
			else
				ConsoleMessage(1);
		}
}
void ResetVisited()
{
	for (int i = 1; i <= 20; i++)
	{
		Visit(i); current->pass = false;
	}
}
void Create_Map() // MANUAL MAP CREATION
{
	string diners = "diners";
	string inns = "inns";
	string gas = "gas";
	// initialized manually first location / starting location
	// instead of using pass by value, manual creation of map through DL
	// to demonstrate knowledge in using pointers and linked list - doubly linked list

	// Create_Connect(Location Name, Distance from TOP, Distance from PREVIOUS, Distance from NEXT, Distance from BOTTOM, insertion POINT);

	 /*1*/Create_Connect("SanPedro", NULL, NULL, 13, NULL, 0);
	 /*2*/Create_Connect("  Binan ", NULL, 13, 12, NULL, 1);
	 /*3*/Create_Connect("Sta.Rosa", NULL, 12, 9, NULL, 1); 
	 /*4*/Create_Connect("Cabuyao ", NULL, 9, 13, NULL, 1);
	 /*5*/Create_Connect("Calamba ", NULL, 13, 21, NULL, 1);
	 /*6*/Create_Connect("LosBanos", NULL, 21, 7, NULL, 1);
	 /*7*/Create_Connect("  Bay   ", NULL, 7, 20, 27, 1);
	 /*8*/Create_Connect("Victoria", NULL, 20, 13, 14, 1);
	 /*9*/Create_Connect("  Pila  ", NULL, 6, 7, 17, 1);
	/*10*/Create_Connect("Sta.Cruz", NULL, 7, 6, NULL, 1);
	/*11*/Create_Connect("Pgsanjan", NULL, 6, 16, 12, 1);
	/*12*/Create_Connect("Cavinti ", NULL, 16, NULL, 19, 1);

	Visit(7); //1.prepares insertion point (current), 2.connect newNode to current
	/*13*/Create_Connect("Alaminos", 19, 27, 11, NULL, 4);
	current->bot = newNode;
	newNode->prev = current;
	current = newNode;

	/*14*/Create_Connect("SanPablo", 11, 11, 15, NULL, 2); 
	/*15*/Create_Connect(" Rizal  ", NULL, 11, 20, NULL, 2);
	/*16*/Create_Connect(" Liliw  ", 9, 20, 18, NULL, 2);

	/*17*/Create_Connect("Luisiana", NULL, 6, 11, NULL, 4);
	current->next = newNode;
	newNode->prev = current;
	current = newNode;

	//closing the graph, tail manipulation connecting to endpoint current
	Visit(12); tail = current;
	Visit(17); current->next = tail;
	tail->bot = current;

	//challenge part inserting 18.Calauan
	//step 1 - position pins to attach for other pointers later on
	Visit(13); pin1 = current; //13.Alaminos
	Visit(14); pin2 = current; //14.San Pablo
	//step 2- create the node
	/*18*/Create_Connect(" Calauan", NULL, 6, NULL, 11, 4);
	//step 3 - manipulate the node pointers to attach to the pins
	newNode->prev = pin1;
	newNode->bot = pin2;
	//step 4 - go back to the pins and attach them to the newnode
	Visit(13); current->top = newNode; //victoria
	Visit(14); current->top = newNode; //san pablo
	current = newNode;

	//inserting 20
	Visit(9); pin1 = current;
	Visit(11); pin2 = current;
	/*20*/Create_Connect("Mgdalena", 11, 17, NULL, 16, 4);
	newNode->top = pin2;
	newNode->prev = pin1;
	Visit(9); current->bot = newNode;
	Visit(11); current->bot = newNode;
	current = newNode;

	//challenge part 4 pointers / pin manipulation
	//step 1 - create pins to mark attachment points
	Visit(8); pin1 = current; //Liliw - left / prev
	Visit(20); pin2 = current; // Magdalena- top
	Visit(16); pin3 = current; //Victoria - right  / next
	Visit(14); pin4 = current; //San Pablo - bottom
	//step2 - create the newNode
	/*19*/Create_Connect("Ngcarlan", 16, 6, 9, 20, 4);
	//step3 - manipulate the newNode pointers, link them to the pins
	newNode->top = pin2; // Magdalena- top
	newNode->next = pin3; //Victoria - right  / next
	newNode->prev = pin1; //Liliw - left / prev
	newNode->bot = pin4; //San Pablo - bottom
	//step4 - after linking, now link EACH pin to the newNode;
	pin1->bot = newNode;
	pin2->bot = newNode;
	pin3->top = newNode;
	pin4->top = newNode;
}
void Manual_SelectLocation()
{
	int target;
	current = head;
	do
	{
		system("cls");
		LocationsList();
		cout << "\n\t[0] Main Menu                               [99] UP [98] Down [97] Left [96] Right" << endl;
		cout << "\t==================================================================================";
		Navbar();
		cout << "\n\t"; ConsoleMessage(2);
		cin >> target; //select target location to peak
		if (target == 0)
			break;
		if (target == 99)
		{
			if (current->top != NULL)
				current = current->top;
			else
				ConsoleMessage(3);
		}
		else if (target == 98)
		{
			if (current->bot != NULL)
				current = current->bot;
			else
				ConsoleMessage(3);
		}
		else if (target == 97)
		{
			if (current->prev != NULL)
				current = current->prev;
			else
				ConsoleMessage(3);
		}
		else if (target == 96)
		{
			if (current->next != NULL)
				current = current->next;
			else
				ConsoleMessage(3);
		}
		else if (target <= 20)
		{
			Visit(target); // pass value to go2 to fetch / assign location for inquiry
		}
		else
		{
			ConsoleMessage(3);
		}
		
	} while (target != 0);
}
void Register_Establishments()
{
	int target;
	string reg_name;
	int reg_distance;
	int inn = 0, diner = 0, gas=0;
	do
	{
		system("cls");
		LocationsList();
		cout << "\n\t[0] Main Menu                       Register: [99] Diners [98] Gas Statn [97] Inns" << endl;
		cout << "\t==================================================================================\n";

		cout << "\n\tWhere do you want to register your Establishment? 1-20: ";
		cin >> target;
		

		if (target == 0)
			break;
		if (target <= 20)
			Visit(target);
		cout << "\tYou are about to register an establishment at " << current->name << endl;

		cout << "\n\t[99] Register a Diner "<< endl;
		cout << "\t[98] Register Gasoline Station" << endl;
		cout << "\t[97] Register Inns, Hotels, Motels" << endl;
		cout << "\n\tchoice : ";
		cin >> target;
		
		if (target == 99)
		{
			DMAX = DMAX + 1;
			cout << "\tDiner's Name: ";
			cin >> reg_name;
			current->arrDiners[DMAX] = reg_name;
			cout << "\tDistance from town: ";
			cin >> reg_distance;
			current->arrDinerDistance[DMAX] = reg_distance;
		}

		if (target == 98)
		{
			GMAX = GMAX + 1;
			cout << "\tGas Station's Name: ";
			cin >> reg_name;
			current->arrGasStations[GMAX] = reg_name;
			cout << "\tDistance from town: ";
			cin >> reg_distance;
			current->arrGasStationDistance[GMAX] = reg_distance;
		}

		if (target == 97)
		{
			IMAX = IMAX + 1;
			cout << "\tInn's Name: ";
			cin >> reg_name;
			current->arrInns[IMAX+1] = reg_name;
			cout << "\tDistance from town: ";
			cin >> reg_distance;
			current->arrInnDistance[IMAX] = reg_distance;
		}
	} while (target != 0);
}
void Manual_Add_New_Location()
{
	int target, distance;
	string nav_top, nav_right, nav_left, nav_bottom;
	string new_name, top, bot, prev, next;
	int Dist_top, Dist_next, Dist_prev, Dist_bot;
	//int distance_top, distance_bot, distance_next, distance_prev;
	do
	{
		system("cls");
		LocationsList();
		cout << "\n\t[0] Main Menu                                          Register: [99] New Location " << endl;
		cout << "\t==================================================================================\n";

		cout << "\n\tThe new location will only be able to connect to 4 distinct location at max" << endl;
		cout << "\tif the concurrent connections are already maxed out it will not be added to the list" << endl;
		cout << "\tof location, the connections made to it can be checked if they are connected to your " << endl;
		cout << "\tnewly created location by checking each of the locations connected to it" << endl;
	

		cout << "\n\t 1-20 for locations" << endl;
		cout << "\t 98 for for NULL or NO connection" << endl;
	
			cout << "\n\tNew Location's Name (8 - chars): ";
			cin >> new_name;

			newNode = new Node;
			newNode->name = new_name;
			/*newNode->dist_top = NULL;
			newNode->dist_next = NULL;
			newNode->dist_prev = NULL;
			newNode->dist_bot = NULL;*/
			nulifier();
			newNode->next = NULL;
			newNode->prev = NULL;
			newNode->top = NULL;
			newNode->bot = NULL;

			
			

			//TOP =  
			do
			{
				system("cls");
				LocationsList();
				cout << "\n\t[0] Main Menu" << endl;
				cout << "\t==================================================================================\n";
				cout << "\n\t1-20 for locations" << endl;
				cout << "\t98 for for NULL or NO connection" << endl;

				Navbar_template();
				cout << "\n\tWhat location is on TOP of your New Location? : ";
				cin >> target;
				if (target == 98)
				{
					newNode->top = NULL;
					break;
				}
				if (target == 0)
					break;

				cout << "\n\tWhat is the Distance from your  New Location? : ";
				cin >> distance;
				newNode->dist_top = distance;

				Visit(target);
				newNode->top = current;
				
				if (current->top == NULL)
				{
					//newNode->top = current->top;
					current->top = newNode;
					current->dist_top = distance;
					break;
				}
								
				if (current->next == NULL)
				{
					//newNode->top = current->top;
					current->next = newNode;
					current->dist_next = distance;
					break;
				}
					
				if (current->prev == NULL)
				{
					//newNode->top = current->top;
					current->prev = newNode;
					current->dist_prev = distance;
					break;
				}
					
				if (current->bot == NULL)
				{
					//newNode->top = current->top;
					current->bot = newNode;
					current->dist_bot = distance;
					break;
				}
				
			} while (target <= 20);
	
			
			// NEXT - RIGHT
			do
			{
				system("cls");
				LocationsList();
				cout << "\n\t[0] Main Menu" << endl;
				cout << "\t==================================================================================\n";
				cout << "\n\t1-20 for locations" << endl;
				cout << "\t98 for for NULL or NO connection" << endl;
				Navbar_template();
				cout << "\n\tWhat location is on RIGHT of your New Location? : ";
				cin >> target;
				if (target == 98)
				{
					newNode->next = NULL;
					break;
				}
				if (target == 0)
					break;

				cout << "\n\tWhat is the Distance from your  New Location? : ";
				cin >> distance;
				newNode->dist_next = distance;

				Visit(target);
				newNode->next = current;

				if (current->top == NULL)
				{
					//newNode->next = current->top;
					current->top = newNode;
					current->dist_top = distance;
					break;
				}

				if (current->next == NULL)
				{
					//newNode->next = current->top;
					current->next = newNode;
					current->dist_next = distance;
					break;
				}

				if (current->prev == NULL)
				{
					//newNode->next = current->top;
					current->prev = newNode;
					current->dist_prev = distance;
					break;
				}

				if (current->bot == NULL)
				{
					//newNode->next = current->top;
					current->bot = newNode;
					current->dist_bot = distance;
					break;
				}
				
			} while (target <= 20);

			// PREVIOUS - LEFT
			do
			{
				system("cls");
				LocationsList();
				cout << "\n\t[0] Main Menu" << endl;
				cout << "\t==================================================================================\n";
				cout << "\n\t1-20 for locations" << endl;
				cout << "\t98 for for NULL or NO connection" << endl;
				Navbar_template();
				cout << "\n\tWhat location is on LEFT of your New Location? : ";
				cin >> target;

				if (target == 98)
				{
					newNode->prev = NULL;
					break;
				}
				if (target == 0)
					break;

				cout << "\n\tWhat is the Distance from your  New Location? : ";
				cin >> distance;
				newNode->dist_prev = distance;

				Visit(target);
				newNode->prev = current;

				if (current->top == NULL)
				{
					//newNode->prev = current->top;
					current->top = newNode;
					current->dist_top = distance;
					break;
				}

				if (current->next == NULL)
				{
					//newNode->prev = current->top;
					current->next = newNode;
					current->dist_next = distance;
					break;
				}

				if (current->prev == NULL)
				{
					//newNode->prev = current->top;
					current->prev = newNode;
					current->dist_prev = distance;
					break;
				}

				if (current->bot == NULL)
				{
					//newNode->prev = current->top;
					current->bot = newNode;
					current->dist_bot = distance;
					break;
				}

			} while (target <= 20);

			// BOTTOM
			do
			{
				system("cls");
				LocationsList();
				cout << "\n\t[0] Main Menu" << endl;
				cout << "\t==================================================================================\n";
				cout << "\n\t1-20 for locations" << endl;
				cout << "\t98 for for NULL or NO connection" << endl;
				Navbar_template();
				cout << "\n\tWhat location is at the BOTTOM of your New Location? : ";
				cin >> target;
				if (target == 98)
				{
					newNode->bot = NULL;
					break;
				}
				if (target == 0)
					break;

				cout << "\n\tWhat is the Distance from your  New Location? : ";
				cin >> distance;
				newNode->dist_bot = distance;

				Visit(target);
				newNode->bot = current;

				if (current->top == NULL)
				{
					//newNode->bot = current->top;
					current->top = newNode;
					current->dist_top = distance;
					break;
				}

				if (current->next == NULL)
				{
					//newNode->bot = current->top;
					current->next = newNode;
					current->dist_next = distance;
					break;
				}

				if (current->prev == NULL)
				{
					//newNode->bot = current->top;
					current->prev = newNode;
					current->dist_prev = distance;
					break;
				}

				if (current->bot == NULL)
				{
					//newNode->bot = current->top;S
					current->bot = newNode;
					current->dist_bot = distance;
					break;
				}

			} while (target <= 20);
			
			system("cls");
			LocationsList();
			cout << "\n\t[0] Main Menu" << endl;
			cout << "\t==================================================================================\n";
			Navbar_template();
			cout << "\n"; ConsoleMessage(6);
			system("pause");
			break;
	} while (target != 0);
}
void Prio_NEXT()
{
	current = start;
	while (current != destination)
	{
		if (destination == current->next)
		{
			current = current->next;
			cout << current->name;
			break;
		}

		if (destination == current->top)
		{
			current = current->top;
			cout << current->name;
			break;
		}

		if (destination == current->bot)
		{
			current = current->bot;
			cout << current->name;
			break;
		}

		if (destination == current->prev)
		{
			current = current->prev;
			cout << current->name;
			break;
		}

		if (current == destination)
		{
			cout << current->name;
			break;
		}



		if (current->next != NULL)
		{
			if (current->next->pass == false)
			{
				current->pass = true;
				current = current->next;
				current->pass = true;
				cout << current->name << "->";
			}
		}

		if (current == destination)
			break;

		if (current->bot != NULL)
		{
			if (current->bot->pass == false)
			{
				current->pass = true;
				current = current->bot;
				current->pass = true;
				cout << current->name << "->";
			}
		}

		if (current == destination)
			break;

		if (current->top != NULL)
		{
			if (current->top->pass == false)
			{
				current->pass = true;
				current = current->top;
				current->pass = true;
				cout << current->name << "->";
			}
		}

		if (current == destination)
			break;

		if (current->prev != NULL)
		{
			if (current->prev->pass == false)
			{
				current->pass = true;
				current = current->prev;
				current->pass = true;
				cout << current->name << "->";
			}
		}

		if (current == destination)
			break;
	}
}
void Prio_PREV()
{
	current = start;
	while (current != destination)
	{
		if (destination == current->prev)
		{
			current = current->prev;
			cout << current->name;
			break;
		}

		if (destination == current->top)
		{
			current = current->top;
			cout << current->name;
			break;
		}
			
		if (destination == current->bot)
		{
			current = current->bot;
			cout << current->name;
			break;
		}

		if (destination == current->next)
		{
			current = current->next;
			cout << current->name;
			break;
		}


		if (current == destination)
		{
			cout << current->name;
			break;
		}
			

		if (current->prev != NULL)
		{
			if (current->prev->pass == false)
			{
				current->pass = true;
				current = current->prev;
				current->pass = true;
				cout << current->name << "->";
			}continue;
		}continue;

		if (current == destination)
			break;

		if (current->top != NULL)
		{
			if (current->top->pass == false)
			{
				current->pass = true;
				current = current->top;
				current->pass = true;
				cout << current->name << "->";
			}continue;
		}continue;

		if (current == destination)
			break;

		if (current->bot != NULL)
		{
			if (current->bot->pass == false)
			{
				current->pass = true;
				current = current->bot;
				current->pass = true;
				cout << current->name << "->";
			}continue;
		}continue;

		if (current == destination)
			break;


		if (current->next != NULL)
		{
			if (current->next->pass == false)
			{
				current->pass = true;
				current = current->next;
				current->pass = true;
				cout << current->name << "->";
			}continue;
		}continue;

		if (current == destination)
			break;
	
		if (current->prev == NULL||current->prev->pass == true)
		{
			if (current->top == NULL || current->top->pass == true)
			{
				if (current->bot == NULL || current->bot->pass == true)
				{
					if (current->next == NULL || current->next->pass == true)
					{
						current = current->next;
					}
					current = current->next;
				}
				current = current->bot;
			}
			current = current->top;
		}
		current = current->prev;
	}
}
void Find_Path(int from, int to) // PATH FINDER ALGORITHM , HEURISTICS , TRY-CHECK-APPROACH
{
	int counter = 0;
	ResetVisited();
	current = start;

		if (from < to) //forward manner
		{
			cout << "\n\t";
			cout << current->name << "->";
			Prio_NEXT();

		}
		else if (from > to) // backward
		{
			cout << current->name << "->";
			Prio_PREV();				
				
		}
		else // equal
		{
			cout << "\n\t" << current->name;
		}


}
void Travel_to_from() // maneuver current pointer to set start location *from
{
	int from, to;
	do
	{
		system("cls");
		LocationsList();
		cout << "\n\t[0] Main Menu" << endl;
		cout << "\t==================================================================================";
		cout << "\n\tselect STARTING location: ";
		cin >> from;
		Visit(from);
		if (from == 0 || from > 20)
			break;
		if (from > 20)
			continue;
		start = current; //set starting location

		cout << "\tselect TARGET destination: ";
		cin >> to;
		if (to == 0)
			break;
		if (to > 20)
			continue;
		Visit(to);
		destination = current; //set endpoint location
		current = start ;
		cout << "\t=================================================";
		cout << setw(27) << "\n\tStarting location is set (from) : " << start->name << endl;
		cout << setw(27) << "\tDestination is set (to)         : " << destination->name << endl;
		cout << "\t=================================================\n";
		
		current = start;
		Find_Path(from, to);

		if (from < 0 || to < 0)
			break;
		cout << "\t";  system("pause");

	} while (from != 0|| to != 0);
}
void Peek_A_View()
{
	int target = 0, category;
	current = head;
	do
	{
		int  inn = 0, diner = 0, gas = 0;
	system("cls");
	LocationsList();
	cout << "\n\t[0] Main Menu                           View: [99] Diners [98] Gas Statn [97] Inns" << endl;
	cout << "\t==================================================================================\n";
	cout << "\n\tselect a location: ";
	cin >> target;
	if (target == 0)
		break;
	else if (target <= 20)
		Visit(target);

	cout << "\n\tSelect a category to view: ";
	cin >> category;
	cout << "\n\n";
	if (category == 97) // inns
	{
		Visit(target);
		for (int i = 0; i <= IMAX; i++)
		{
			cout << "\t" << current->arrInns[i] << " " << current->arrInnDistance[i] << endl;
		}
		system("pause");
	}
	else if (category == 98) // Gas Stations
	{
		Visit(target);
		for (int x = 0; x <= GMAX; x++)
		{
			cout << "\t" << current->arrGasStations[x] << " " << current->arrGasStationDistance[x] << endl;
		}
		system("pause");
	}
	else if (category == 99) // diners
	{
		Visit(target);
		for (int j = 0; j <= DMAX; j++)
		{
			cout << "\t" << current->arrDiners[j] << " " << current->arrDinerDistance[j] << endl;
		}
		system("pause");
	}
	else if (category == 0)
	{
		break;
	}
	else
	{
		ConsoleMessage(1);
	}
		
	} while (target != 0);
}

void DefaultEstablishments()
{

	string arrDiners[10] = { "Rosie's Diner", "70's Bistro", "N.Y. Style Restaurant", "Carlo's Roofdeck",
		"Mexican Food Hub", "16th Ave. Diner", "Mang Donalds", "Wing Warehouse",
		"Tita Jo's Kitchenette", "Oneding's Porkchop" };
	int arrDinerDistance[10] = { 8, 10, 6, 11, 15, 9, 13, 7, 12, 12 };

	string arrGasStations[7] = { "Phoenix", "PTT", "Shell", "Diesel Depot", "Caltex", "Petron", "RePhil" };
	int arrGasStationDistance[7] = { 5, 4, 9, 7, 3, 9, 11 };

	string arrInns[10] = { "Starflower Inn", "SOGO Hotel", "Diamond Inn", "Astrotel", "Golden Gate Inn",
		"Mahal Kita Inn", "Mariposa", "Calypso Inn", "Victoria Court", "Log Inn" };
	int arrInnDistance[10] = { 4, 3, 8, 5, 11, 9, 13, 6, 7, 10 };

	for (int j = 1; j <= 20; j++)
	{
		for (int i = 0; i < GMAX; i++)
		{
			Visit(j);		
			current->arrGasStations[i] = arrGasStations[i];
			current->arrGasStationDistance[i];
			if (i == GMAX)
				break;
		}

		for (int x = 0; x < IMAX; x++)
		{

		Visit(j);
		current->arrInns[x] = arrInns[x];
		current->arrInnDistance[x] = arrInnDistance[x]; 
		if (x == IMAX)
			break;
		}

		for (int y = 0; y < DMAX; y++)
		{
			Visit(j);
			current->arrDiners[y] = arrDiners[y];
			current->arrDinerDistance[y] = arrDinerDistance[y];
			if (j == DMAX)
				break;
		}
	}
}

int main()
{
	int choice = 0, ans = 1;
	Create_Map();
	DefaultEstablishments();
	do
	{
		system("cls");
		MainMenu();
		cin >> choice;

		if (choice == 1)
		{
			Manual_SelectLocation();
		}
		else if (choice == 2)
		{
			Travel_to_from();
		}
		else if (choice == 3)
		{
			Peek_A_View();
		}
		else if (choice == 4)
		{
			Register_Establishments();
		}
		else if (choice == 5)
		{
			Manual_Add_New_Location();
		}
		else if (choice == 0)
		{
			cout << "\n\t thank you. bye.";
			break;
		}
		else
		{
			ConsoleMessage(1);
		}


	} while (choice != 0);


	cout << "\n\n\t"; system("pause");

	_getche();
}

