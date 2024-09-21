#include <iostream>
#include <vector> 
using std::string; 

class BankSystem {

private:
    int accountNumber;
    string accountHolder;
    float balance;

public: 
    // Constructor
    BankSystem(int accNumber, string accHolder, float initialBalance) {
        accountNumber = accNumber;
        accountHolder = accHolder;
        balance = initialBalance;      
    }

    // Getter for account number
    int getAccountNumber() const {
        return accountNumber;
    }

    void viewDetails() {
        std::cout << "Account Number: " << accountNumber << std::endl;
        std::cout << "Account Holder: " << accountHolder << std::endl;
        std::cout << "Balance: " << balance << " $" << std::endl;
    }

    float deposit() {
        std::cout << "How much would you like to deposit into your account: ";
        float depositAmount;
        while (!(std::cin >> depositAmount)) {
            std::cout << "Please make sure that you input a valid amount." << std::endl;
            std::cin.clear();
            std::cin.ignore(1000, '\n');
        }
        if (depositAmount > 0) {
            balance += depositAmount;
            std::cout << "Your account balance after depositing is: " << balance << " $" << std::endl;
        } else {
            std::cout << "Deposit amount must be positive." << std::endl;
        }
        return balance;
    }
    
    float withdraw() {
        std::cout << "How much would you like to withdraw: ";
        float withdrawAmount;
        while (!(std::cin >> withdrawAmount)) {
            std::cout << "Please make sure you input a valid amount." << std::endl;
            std::cin.clear();
            std::cin.ignore(1000, '\n');
        }
        if (withdrawAmount > balance) {
            std::cout << "Sorry, insufficient balance." << std::endl;
        } else if (withdrawAmount > 0) {
            balance -= withdrawAmount;
            std::cout << "Withdrawal successful. Your new balance is: " << balance << " $" << std::endl;
        } else {
            std::cout << "Invalid amount." << std::endl;
        }
        return balance;
    }

    void transfer(float transferAmount, BankSystem &destinationAccount) {
        if (transferAmount > 0 && balance >= transferAmount) {
            balance -= transferAmount;
            destinationAccount.balance += transferAmount;
            std::cout << "The transfer was successful. New balance: " << balance << std::endl;
        } else {
            std::cout << "Insufficient funds or invalid amount." << std::endl; 
        }
    }
};

// Store multiple accounts globally
std::vector<BankSystem> accounts;

void createAccount() {
    int accNumber;
    string accHolder;
    float initialBalance; 

    std::cout << "What is your account number: ";
    while (!(std::cin >> accNumber)) {
        std::cout << "Please make sure that you type a valid number." << std::endl;
        std::cin.clear();
        std::cin.ignore(1000, '\n');
    }
    std::cin.ignore();
    std::cout << "What is your name? ";
    std::getline(std::cin, accHolder);

    std::cout << "Please enter the initial balance: $";
    while (!(std::cin >> initialBalance)) {
        std::cout << "Please make sure you type a valid amount: ";
        std::cin.clear();
        std::cin.ignore(1000, '\n');
    }
    
    // Add the new account to the accounts vector
    accounts.push_back(BankSystem(accNumber, accHolder, initialBalance));
}

void displayMenu() {
    std::cout << "\nMenu:\n";
    std::cout << "1. Create New Account\n";
    std::cout << "2. View Account Details\n";
    std::cout << "3. Deposit Money\n";
    std::cout << "4. Withdraw Money\n";
    std::cout << "5. Transfer money\n";
    std::cout << "6. Exit\n";
    std::cout << "Enter your choice: ";
}

void viewAccountDetails() {
    int accNumber;
    std::cout << "Enter the account number to view details: ";
    std::cin >> accNumber;

    for (int i = 0; i < accounts.size(); i++) {
        if (accounts[i].getAccountNumber() == accNumber) {
            accounts[i].viewDetails();
            return;
        }
    }
    std::cout << "Account not found.\n";
}
int main() {
    int choice;
    do {
        displayMenu();
        std::cin >> choice;

        switch (choice) {
        case 1:
            createAccount();
            break;
        case 2:
            viewAccountDetails();
            break;
        case 3: {
            // Handle deposit
            int accNumber;
            std::cout << "Please provide an account number: ";
            while (!(std::cin >> accNumber)) {
                std::cout << "Please type a valid account number." << std::endl;
                std::cin.clear();
                std::cin.ignore(1000, '\n');
            }

            for (int i = 0; i < accounts.size(); i++) {
                if (accounts[i].getAccountNumber() == accNumber) {
                    accounts[i].deposit();
                    return 0;  // Exit the function after deposit is successful
                }
            }
            std::cout << "Account not found." << std::endl;
            break;
        }
        case 4: {
            // Handle withdraw
            int accNumber;
            std::cout << "Please provide an account number: ";
            while (!(std::cin >> accNumber)) {
                std::cout << "Please make sure you provide a valid account number." << std::endl;
                std::cin.clear();
                std::cin.ignore(1000, '\n');
            }

            for (int i = 0; i < accounts.size(); i++) {
                if (accounts[i].getAccountNumber() == accNumber) {
                    accounts[i].withdraw();
                    return 0;  // Exit the function after withdrawal is successful
                }
            }
            std::cout << "Account not found." << std::endl;
            break;
        }
        case 5:
            // Handle money transfer
            break;
        case 6:
            std::cout << "Exiting the program.\n";
            break;
        default:
            std::cout << "Please choose a valid option.\n";
        }
    } while (choice != 6);

    return 0;  // Add return 0 to signify successful program termination
}
