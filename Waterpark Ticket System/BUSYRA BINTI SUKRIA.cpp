// Perthlis Waterpark System

#include <iostream>
#include <fstream>

using namespace std;

// Function to calculate the total price of a given quantity of tickets at a given price
double calculatePrice(int quantity, double price) {
    return quantity * price;
}

int main() {
	char custName[30];
    int seniorCitizens, adults, kids;
    double seniorCitizensPrice = 30.00, adultsPrice = 120.00, kidsPrice = 65.00, tax= 0.06;
    double seniorCitizensTotal, adultsTotal, kidsTotal, totalPrice, discountAmount;
    double tubePrice = 20, lockerPrice = 10;
    bool isMember, addTube, addLocker, proceed;
    double discount = 0.3;
    int numOfTube, numOfLocker;
    double prices[3];
    double sum = 0, average, highest = -99999, lowest = 99999;
    int counter = 0;
    string email;
    string website;
    
     	// Display information about the water park and ticket prices
    	cout << endl;
	 	cout << "  - W E L C O M E  T O  P E R T H L I S  W A T E R P A R K -  " << endl;
		cout << "  ___________________________________________________________" << endl;
		cout << " | Category of age| Range of age                | Ticket Fee |" << endl;
		cout << " |________________|_____________________________|____________|" << endl;
		cout << " | Future Kids    | below 4 years old           | Free       |" << endl;
		cout << " | Kids           | 4 years old - 17 years old  | RM 65.00   |" << endl;
		cout << " | Adults         | 18 years old - 60 years old | RM 120.00  |" << endl;
		cout << " | Senior Citizens| 61 years old and above      | RM 30.00   |" << endl;
		cout << " |________________|_____________________________|____________|" << endl;
		cout << "  \t\t   Tax 6% will be charge for our service" << endl;
		cout << "   \t\t\tDiscout 30% for membership " << endl;
		cout << endl;
		
	// Customer details 
    cout << " Please enter customer name: ";
    cin.get(custName , 30);
    cin.ignore(20, '\n');

	// User enter input for the number of tickets for each age group
    cout << " Please enter the number of kids tickets: ";
    cin >> kids;
    cout << " Please enter the number of adult tickets: ";
    cin >> adults;
    cout << " Please enter the number of senior citizens tickets: ";
    cin >> seniorCitizens;

		// Display information about add-on services
    	cout << "  _________________________ " << endl;
		cout << " | Add on       |  Fee     |" << endl;
		cout << " |______________|__________|" << endl;
		cout << " | Locker Rental| RM 10.00 |" << endl;
		cout << " | Tube Rental  | RM 20.00 |" << endl;
		cout << " |______________|__________|" << endl;
		cout << endl;

	// Use 2 ways selection to ask customers if their want to rental tube and locker or not
    cout << " Would you like to add a tube rental? (1 for yes / 0 for no) :  ";
    cin >> addTube;
    
    if (addTube) {
        cout << " How many tube rentals would you like to add? : ";
        cin >> numOfTube;
    }
	 else {
        numOfTube = 0;
    }
    
    cout << " Would you like to add a locker rental? (1 for yes / 0 for no) : ";
    cin >> addLocker;
    
    if (addLocker) {
        cout << " How many locker rentals would you like to add? : ";
        cin >> numOfLocker;
    } 
	else {
        numOfLocker = 0;
    }
  
	// Calculate the total price for each age group of tickets
    kidsTotal = calculatePrice(kids, kidsPrice);
    adultsTotal = calculatePrice(adults, adultsPrice);
    seniorCitizensTotal = calculatePrice(seniorCitizens, seniorCitizensPrice); 

	// Store the prices for each age group in an array
    prices[0] = kidsTotal;
    prices[1] = adultsTotal;
    prices[2] = seniorCitizensTotal;

	// Calculate the sum, average, highest, and lowest prices in the array
    for (int i = 0; i < 3; i++) {
        sum += prices[i];
        
        if (prices[i] > highest) {
            highest = prices[i];
        }
        if (prices[i] < lowest) {
            lowest = prices[i];
		}
	}
	
	totalPrice = seniorCitizensTotal + adultsTotal + kidsTotal + (numOfTube * tubePrice) + (numOfLocker * lockerPrice);
	average = sum / 3;
	counter += (seniorCitizens + adults + kids);
	
	cout << " Are you a member? (1 for yes / 0 for no) : ";
    cin >> isMember;
	
	 // Apply the member discount if applicable use selection
	if (isMember) {
        discountAmount = (totalPrice) * discount;
        totalPrice -= discountAmount;
    }
    else{
        discountAmount = (totalPrice) * 0;
        totalPrice -= discountAmount;
    }
    
    cout << " Do you want a receipt? (1 for yes / 0 for no) : ";
    cin >> proceed;
		
	if (proceed==1) {
    // Open the file to write the receipt
    ofstream receipt("receiptFile.txt");

        // Write the receipt to file
        receipt<< " ------------------------------------------------------------" << endl;
        receipt<< " \t\t Perthlis Waterpark System " << endl;
        receipt<< " ------------------------------------------------------------" << endl;
        receipt<< " Customer name : " << custName << endl;
        receipt<< " ------------------------------------------------------------" << endl;
		receipt<< " Category of age \tQuantity \tPrice "                          << endl;
        receipt<< " Kids \t"          <<"\t"             << kids              << "\t\t" << kidsTotal          << endl;
        receipt<< " Adults \t"        << "\t"            << adults            << "\t\t" << adultsTotal        << endl;
        receipt<< " Senior citizens \t"                  << seniorCitizens    << "\t\t" <<seniorCitizensTotal << endl;
        receipt<< " ------------------------------------------------------------" << endl;
        receipt<< " Total price tickets           RM " << seniorCitizensTotal + adultsTotal + kidsTotal << endl;
		receipt<< " Total add on                  RM " << (numOfTube * tubePrice) + (numOfLocker * lockerPrice) << endl;
		receipt<< " Discount                      RM " << discountAmount<< endl;
		receipt<< " Subtotal                      RM " << totalPrice << endl;
		receipt<< " Tax 6%                        RM " << tax * totalPrice << endl;
		receipt<< " Overall total price           RM " << totalPrice + (tax*totalPrice) << endl;
        // Close the file
        receipt.close();
    } 

	cout <<endl << "-----------------------------------------------------------------------" << endl;
	cout << " Customer name : " << custName << endl;
	cout << " Total price for kids tickets                           RM " << kidsTotal << endl;
	cout << " Total price for adult tickets                          RM " << adultsTotal << endl;
	cout << " Total price for senior citizens tickets                RM " << seniorCitizensTotal << endl;
	cout << "-----------------------------------------------------------------------" << endl;	
	cout <<endl;
	cout << " Total price tickets                                    RM " << seniorCitizensTotal + adultsTotal + kidsTotal << endl;
	cout << " Total add on                                           RM " << (numOfTube * tubePrice) + (numOfLocker * lockerPrice) << endl;
	cout << " Discount                                               RM " << discountAmount<< endl;
	cout << " Subtotal                                               RM " << totalPrice << endl;
	cout << " Tax 6%                                                 RM " << tax * totalPrice << endl;
	cout << " Overall total price                                    RM " << totalPrice + (tax*totalPrice)<< endl;
	cout << endl << "-----------------------------------------------------------------------" << endl;
	cout << " Average ticket price                                   RM " << average << endl;
	cout << " Highest ticket price                                   RM " << highest << endl;
	cout << " Lowest ticket price                                    RM " << lowest << endl;
	cout << " Total number of tickets purchased                         " << counter << endl;
	cout << "-----------------------------------------------------------------------" << endl;
	cout <<endl;
	
	// Open the file to read about us
	ifstream aboutUs("aboutUs.txt");
    cout <<" Email \t\t\t\t Website " << endl;
    
    while(!aboutUs.eof()) {
        aboutUs >> email;
        aboutUs >> website; 
        cout << email  << "\t" << website << endl;
    }
    aboutUs.close();
    
	cout <<endl;
	cout << " \t\t Thank You for purchasing with us! " << endl;
	cout << " \t\t\t Have a nice day!" << endl; 
	
	return 0;
}

