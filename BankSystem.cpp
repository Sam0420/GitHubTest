#include <iostream>
using std::string; 



class BankSystem{

private:
    int accountNumber;
    string accountHolder;
    float balance;

public: 
    
    BankSystem(int accNumber, string accHolder, float initialBalance){
        accountNumber = accNumber;
        accountHolder = accHolder;
        balance = initialBalance;      
    }

    void viewDetails(){
        std::cout << "Account Number: " << accountNumber << std::endl;
        std::cout << "Account Holder: " << accountHolder << std::endl;
        std::cout << "Balance: " << balance << std::endl;
    }

    float deposit(){
        std::cout << "How much would you like to deposit into your account" << std::endl;
        float depositAmount;
        while (!(std::cin>>depositAmount))
        {
            std::cout << "Please make sure that you input an Integer value" << std::endl;
            std::cin.clear();
            std::cin.ignore(1000, '\n');
        }
        if (depositAmount > 0) 
        {
            balance += depositAmount;
            std::cout << "Your account balance after depositing is: " << balance << " $" << std::endl;
        } 
        else 
        {
            std::cout << "Deposit amount must be positive." << std::endl;
        }
        return balance;
        
    }
    
    float withdraw()

    {
            std::cout << "How much would you like to withdraw" << std::endl;
            float withdrawAmount;
            while (!(std::cin >> withdrawAmount))
            {
                std::cout << "Please make sure you typed an integer" << std::endl;
                std::cin.clear();
                std::cin.ignore(1000, '\n');
            }
            if (withdrawAmount > balance){
                std::cout << "Sorry the withdraw amount is too high for the withdrawl" << std::endl;
            } else if (withdrawAmount <= balance && withdrawAmount > 0){
                balance -= withdrawAmount;
                std::cout << "Withdrawl Successful. Your new balance is: " << balance << std::endl;
            }
            else 
            {
                std::cout << "Invalid amount" << std::endl;
            }
        return balance;
    }

    void showDetails( int &accNumber, string &accHolder, float &initialBalance ){
        std::cout << "What is your account number: " << std::endl;
        while(!(std::cin >> accNumber)){
            std::cout << "Please make sure that you type numbers" << std::endl;
            std::cin.clear();
            std::cin.ignore(1000, '\n');
        }
        std::cin.ignore();
         std::cout << "What is your name? " << std::endl;
        while (!(std::getline(std::cin, accHolder))){
            std::cout << "Please make sure that you type text" << std::endl;
            std::cin.clear();
            std::cin.ignore(1000, '\n');
        }

        std::cout << "Please enter initial Balance: $" << std::endl; 
        while(!(std::cin >> initialBalance)){
            std::cout << "Please make sure you type numbers: " << std::endl;
            std::cin.clear();
            std::cin.ignore(1000, '\n');

         }
    }
 };


int main(){

    int accNumber; 
    string accHolder;
    float initialBalance;
    int choice;



 BankSystem myAccount(accNumber, accHolder, initialBalance);

    do
    {   
        std::cout << "\nMenu:\n";
        std::cout << "1. View Account Details\n";
        std::cout << "2. Deposit Money\n";
        std::cout << "3. Withdraw Money\n";
        std::cout << "4. Exit\n";
        std::cout << "Enter your choice: ";
        std::cin >> choice;

        switch (choice)
        {
        case 1 :
            myAccount.viewDetails();
            break;
        case 2 : 
            myAccount.deposit();
            break;
        
        case 3: 
            myAccount.withdraw();
            break;
        case 4: 
            std::cout << "End program. \n" << std::endl;
            break;
        default:
            std::cout << "Plese choose one of the options" << std::endl;
            break;
        }
        
    } while (choice != 4);
    
    


    return 0;
}
