/*
Student Name: Connor Sparkman
Student NetID: cps260
Compiler Used: Visual Studio
Program Description: User gives commands that can add events with event time length to a doubly linked list. The user can also utilize commands to remove events, find event time length, add to the list before and after events, as well as other commands.
*/
// Add our class header files
#include "Tokenizer.h"
#include "LinkedList.h"

#include <fstream>

using std::ifstream;
using std::cin;
using std::cout;
using std::endl;


// Interactive Shell Function
bool processText(istream& is, LinkedList& ll, bool interactive)
{
	string line;
	string command;

	// Command argument variables
	int intArg1;
	int intArg2;
	string strArg1;
	string strArg2;
	string strArg3;

	// Initialize our classes as objects
	Tokenizer tkn;

	while (true)
	{
		// Begin interactive tokenizer shell
		if (!interactive)
		{
			if (is.eof()) return true;
		}
		else { cout << ">> "; }

		// Read in a line from the user
		getline(is, line);

		// Set tokenizer line from user input
		tkn.setString(line);

		// Read the command string
		// Begin long chain of if statement
		tkn.readString(command);

		// Exit command. Just exits the interactive shell and
		// and end the program
		if (command == "exit")
		{
			cout << "Exiting ...." << endl;
			return false;
		}

		// Load file command
		if (command == "load")
		{
			// load expects a filename (string arg), so error if 
			// no filename is provided
			if (!tkn.readString(strArg1)) {
				cout << "Missing file name" << endl;
				continue; // skip back to the top of the read loop
			}
			ifstream fin;
			bool status = true;

			// Attempts to open filename
			fin.open(strArg1);

			// Process file if able to open
			if (fin.is_open())
				status = processText(fin, ll, false);
			// Error out if file cannot be opened
			else
				cout << "Failed to open the file" << endl;

			// Close file
			fin.close();
			if (!status) return false;
		}


		// Help Command
		if (command == "help")
		{
			// Help Menu Formatting Color Codes
			string commandColorCode = "\x1b[36m";
			string parameterColorCode = "\x1b[35m";
			string defaultColorCode = "\x1b[39m";

			// Lists all possible shell commands
			cout << "Commands" << endl
				<< "############" << endl
				<< commandColorCode << "exit\t\t" << defaultColorCode << "Exits the interactive shell" << endl
				<< commandColorCode << "load " << parameterColorCode << "String\t" << defaultColorCode << "Loads a file to execute a list of commands" << endl
				<< commandColorCode << "help\t\t" << defaultColorCode << "Lists all possible commands and their parameters" << endl
				<< commandColorCode << "append " << parameterColorCode << "Int\t" << defaultColorCode << "Appends a Node containing an Integer to the list" << endl
				<< commandColorCode << "prepend " << parameterColorCode << "Int\t" << defaultColorCode << "Prepends a Node containing an Integer to the list" << endl
				<< commandColorCode << "search " << parameterColorCode << "Int\t" << defaultColorCode << "Searches for a Node containing an Integer to the list" << endl
				<< commandColorCode << "remove " << parameterColorCode << "Int\t" << defaultColorCode << "Removes a Node containing an Integer to the list" << endl
				<< commandColorCode << "display\t\t" << defaultColorCode << "Prints the list [Head -> Tail]" << endl
				<< commandColorCode << "displayReverse\t" << defaultColorCode << "Prints the list [Tail -> Head]" << endl
				<< commandColorCode << "displayUntil\t" << defaultColorCode << "Prints the list until an indicated elapsed time" << endl
				<< commandColorCode << "clear\t" << defaultColorCode << "Clears the list of events" << endl
				<< commandColorCode << "find\t" << defaultColorCode << "Displays an event with elapsed time or indicates event doesn't exist" << endl
				<< commandColorCode << "length\t" << defaultColorCode << "Displays total elapsed time for sequence of events" << endl
				<< commandColorCode << "insert before\t" << defaultColorCode << "Inserts specified event immediately before an already existing event, or tells user event doesn't exist" << endl
				<< commandColorCode << "insert after\t" << defaultColorCode << "Inserts specified event immediately after an already existing event, or tells user event doesn't exist" << endl
				<< "############" << endl;
		}

		if (command == "append")
		{
			if (tkn.readString(strArg1) && tkn.readInteger(intArg1))
			{
				ll.append(strArg1, intArg1);
				cout << "Added Node Containing " << strArg1 << " " << intArg1 << " To End Of List" << endl;
			}
			else
			{
				cout << "Expected an Integer" << endl;
			}
		}

		if (command == "prepend")
		{
			if (tkn.readString(strArg1) && tkn.readInteger(intArg1))
			{
				ll.prepend(strArg1, intArg1);
				cout << "Added Node Containing " << strArg1 << " " << intArg1 << " To Beginning Of List" << endl;
			}
			else
			{
				cout << "Expected an Integer" << endl;
			}
		}

		if (command == "search")
		{
			if (tkn.readInteger(intArg1))
			{
				if (ll.search(intArg1)) // Tests to see if the event length given exists
				{
					cout << "Found Node Containing " << intArg1 << endl;
				}
				else
				{
					cout << "No Node Containing " << intArg1 << " Found" << endl;
				}
			}
			else
			{
				cout << "Expected an Integer" << endl;
			}
		}

		if (command == "remove")
		{
			if (tkn.readString(strArg1))
			{
				if (ll.remove(strArg1)) // Tests to see if the event given exists
				{
					cout << "Removed Node Containing " << strArg1 << endl;
				}
				else
				{
					cout << "No Node Containing " << strArg1 << " Found" << endl;
				}
			}
			else
			{
				cout << "Expected a string" << endl;
			}
		}

		if (command == "display")
		{
			tkn.readString(strArg1);
			if (strArg1 == "until")
			{
				if (tkn.readInteger(intArg1))
				{
					ll.displayUntil(intArg1);
				}
			}
			else
			{
				ll.display();
			}
		}

		if (command == "displayReverse")
		{
			ll.displayReverse();
		}


		if (command == "find")
		{
			if (tkn.readString(strArg1))
			{
				if (!ll.find(strArg1)) // Tests to see if the event given exists
				{
					cout << "Event doesn't exist." << endl;
				}

			}
		}

		if (command == "clear")
		{
			ll.~LinkedList();
		}

		if (command == "length")
		{
			ll.length();
		}

		if (command == "insert") // Once insert command is given, every input following is taken in and given a val using tkn
		{
			if (tkn.readString(strArg1))
			{
				if (tkn.readInteger(intArg1))
				{
					if (tkn.readString(strArg2))
					{
						if (strArg2 == "before")
						{
							if (tkn.readString(strArg3))
							{
								if (ll.insertBefore(strArg1, intArg1, strArg3)) // Tests to see if the event given exists
								{
									cout << "Added Node Containing " << strArg1 << " " << intArg1 << " before node containing " << strArg3 << endl;
								}
								else
								{
									cout << "Event doesn't exist" << endl;
								}
							}
						}
						else if (strArg2 == "after")
						{
							if (tkn.readString(strArg3))
							{
								if (ll.insertAfter(strArg1, intArg1, strArg3)) // Tests to see if the event given exists
								{
									cout << "Added Node Containing " << strArg1 << " " << intArg1 << " after node containing " << strArg3 << endl;
								}
								else
								{
									cout << "Event doesn't exist" << endl;
								}
							}
						}
					}
				}
			}
		}
	}
}

int main()
{
	LinkedList ll;
	// Passes cin, a linked list, and a bool to the function
	// This is needed to create an interacive shell
	processText(cin, ll, true);
	return 0;

}