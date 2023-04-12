#include <iostream>
using namespace std;

int main() 
    // Initialize default values
{
	int dpin = 0000;
    int pin;
    float balance = 1000;
    int wrong_attempts = 0;
    int choice;

    // Start program
    cout << "Welcome to Mobile Money Service!" << endl;

    // Loop until user selects exit option
    do {
        // Display menu options
        cout << "\n1. Check Balance" << endl;
        cout << "2. Send Money" << endl;
        cout << "3. Change Pin" << endl;
        cout << "4. Exit" << endl;

        // Get user's choice
        cout << "Enter your choice: ";
        cin >> choice;

        // Handle user's choice
        switch (choice) {
            case 1:
                // Check your balance
                cout<<"Enter pin"<<endl;
                cin>>pin;
                if(pin==dpin){
                cout<< "Your balance is: " << balance <<"GH "<<endl;
                }
                if(pin!=dpin){
                    cout<<"wrong pin. Please try again"<<endl;
                }
                break;
            case 2:
                // Send money
                int recipient_number, amount;
                cout << "Enter recipient's number: ";
                cin >> recipient_number;
               
                cout << "Enter amount to send: ";
                cin >> amount;
                 cout<<"enter pin"<<endl;
                cin>>pin;
                
				 while(pin!=dpin&&wrong_attempts<2){
                    cout<<"wrong pin. Please try again"<<endl;
                    cin>>pin;
                    wrong_attempts++;
                }
                if (amount > balance) {
                    cout << "Insufficient balance." << endl;
                } 
				else {
                    balance -= amount;
                    cout << "You have successfully sent " << amount << "GH to " << recipient_number << "." << endl;
                }
                break;
            case 3:
                // Change pin
                int current_pin, new_pin;
                cout << "Enter current pin: ";
                cin >> current_pin;

                if (current_pin == pin) {
                    cout << "Enter new pin: ";
                    cin >> new_pin;
                    pin = new_pin;
                    cout << "Pin successfully changed." << endl;
                } else {
                    wrong_attempts++;
                    if (wrong_attempts == 3) {
                        cout << "Too many wrong attempts. Exiting program." << endl;
                        return 0;
                    } else {
                        cout << "Incorrect pin. Try again." << endl;
                    }
                }
                break;
            case 4:
                // Exit program
                cout << "Exiting program." << endl;
                return 0;
            default:
                cout << "Invalid choice. Try again." << endl;
                break;
        }

	 
}
while (choice==4);{
	cout << "Exit programes"<<endl;
}
}
