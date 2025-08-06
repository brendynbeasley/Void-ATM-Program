#include <iostream>
#include <iomanip>

void showBalance(double balance); //function
double deposit(); //global variable outside main function
double withdraw(double balance); //global variable outside main function


int main(){

double balance = 0;
int choice = 0;

std::cout << "Hello welcome to Beasley ATM. Select your choice.\n"; //in future lets add login/pass screen

do{
    std::cout << "1. BALANCE\n";
    std::cout << "2. DEPOSIT\n";
    std::cout << "3. WITHDRAW\n";
    std::cout << "4. LOGOUT\n";

    std::cin >> choice;
    std::cin.clear();
    fflush(stdin);

    switch(choice){
        case 1: showBalance(balance);
            break;
         case 2: balance = balance + deposit();
                showBalance(balance);
            break;
         case 3: balance -= withdraw(balance);
                showBalance(balance);
            break;
         case 4: std::cout << "Successfully logged out.\n";
            break;
        default: std::cout << "Invalid output!\n";
        }

        }while(choice != 4);




    return 0;
}

void showBalance(double balance){
std::cout << "Your current balance is: $" << std::setprecision(2) << std::fixed << balance << '\n';
}
double deposit(){
    double amount = 0;

    std::cout << "Enter amount to be deposited: ";
    std::cin >> amount;

    if(amount > 0){
        std::cout << "You have successfully deposited $" << amount << '\n';
        return amount;
    }
    else{
        std::cout << "You have entered an invalid amount. Please enter a valid amount.";
        return 0;
    } 
}
double withdraw(double balance){
    double amount = 0;

    std::cout << "Enter amount to be withdrawn: ";
    std::cin >> amount;

    if(amount > balance){
        std::cout << "Insufficient funds!\n";
        return 0;
    }
    else if(amount < 0){
        std::cout << "Thats not a valid amount!\n";
        return 0;
    }
    else{
        std::cout << "You have successfully withdrew $" << amount << '\n';
        return amount;
    }

    return amount;

}
