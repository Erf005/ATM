#include <iostream>

using namespace std;

class ATM
{
    private:
        string username;
        int pin;
        double balance;

    public:

    ATM(string name,int pinNumber,double initialBalance)
    {
        username = name;
        pin = pinNumber;
        balance = initialBalance;
    }
        void checkbalance()
        {
            cout << "Your account has " << balance << "money in it.";
        }

        void deposit(double dAmount)
        {

            if(dAmount > 0)
            {
                balance += dAmount;
                cout << "you have deposited " << dAmount << "and your current balance is:" << balance << endl;
            }
            else
            {
                cout << "Invalid deposit amount" << endl;
            }
        }
        void withdraw(double wAmount)
        {
            if(wAmount <= balance)
            {
                balance -= wAmount;
                cout << "you have withdrew " << wAmount << "and your current balance is:" << balance << endl;
            }
            else
            {
                cout << "ERROR!!!The amount that you want to withdraw is larger than your current balance" << endl;
            }
        }
        
    bool validPin(int enteredPin)
    {
        if(enteredPin == pin)
        {
            return true;
        }
        else
        {
            return false;
        }
    } 

};



int main()
{

    ATM myaccount("Erfan",2547,1000);

    int enteredPin;
    cout << "Please enter your pin: ";
    cin >> enteredPin;

    if(!myaccount.validPin(enteredPin))
    {
        cout << "Incorrect pin.Exiting ...";

        return 1;
    }

    int choice;

    do 
    {

    cout << "you can choose to" << endl
         << "1.check balance " << endl
         << "2.deposit money " << endl
         << "3.withdraw money " << endl
         << "4.exit" << endl;

    cout << "please enter your choice: ";
    cin >> choice;

    
    
        switch (choice)
        {
        case 1:
            myaccount.checkbalance();
            break;
        case 2:
            int depositAmount;
            cout << "Enter the deposit amount: ";
            cin >> depositAmount;
            myaccount.deposit(depositAmount);
            break;
        case 3:
            int withdrawAmount;
            cout << "Enter the withdraw amount: ";
            cin >> withdrawAmount;
            myaccount.withdraw(withdrawAmount);
            break;
        
        
        default:
        cout << "Invalid input.Please try again.";
            break;
        }
    }while(choice != 4);

    return 0;

}