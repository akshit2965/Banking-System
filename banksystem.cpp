#include <iostream>
#include <vector>
using namespace std;
class BankAccount
{
private:
    string name;
    int acc_number;
    double balance;

public:
    BankAccount(string name, int acc_number, double balance)
    {
        this->name = name;
        this->acc_number = acc_number;
        this->balance = balance;
    }
    string getname()
    {
        return name;
    }
    int getacc_number()
    {
        return acc_number;
    }
    double getbalance()
    {
        return balance;
    }
    void deposit(double amount)
    {
        balance = balance + amount;
        cout << "amount credited: " << amount << endl;
    }
    void withdraw(double amount)
    {
        if (balance >= amount)
        {
            balance = balance - amount;
        }
        else
        {
            cout << "insufficient balance " << endl;
        }
    }
};
class BankingSystem
{
private:
    vector<BankAccount> accounts;

public:
    void add_account(string name, int acc_number, double balance)
    {
        accounts.push_back(BankAccount(name, acc_number, balance));
        cout << "ACCOUNT CREATED " << endl;
    }
    void del_acc(int number)
    {
        for (auto it = accounts.begin(); it != accounts.end(); ++it)
        {
            if (it->getacc_number() == number)
            {
                accounts.erase(it);
                cout << "Account Deleted Successfully!" << endl;
                return;
            }
        }
        cout << "Account not found!" << endl;
    }
    void show_all_acc()
    {
        cout << "ACCOUNT HOLDERS: ";
        for (int i = 0; i < accounts.size(); i++)
        {
            cout << "NAME: " << accounts[i].getname() << " , " << "ACCOUNT NUMBER: " << accounts[i].getacc_number() << " , " << "BALANCE: " << accounts[i].getbalance() << endl;
        }
    }
    BankAccount *findAccount(int acc_number)
    {
        for (int i = 0; i < accounts.size(); i++)
        {
            if (accounts[i].getacc_number() == acc_number)
            {
                return &accounts[i];
            }
        }
        return nullptr;
    }
};
int main()
{
    BankingSystem bank;
    int choice;
    char option;

    do
    {
        cout << "MAIN MENU" << endl;
        cout << "1.ADD NEW ACCOUNT" << endl;
        cout << "2.SHOW BALANCE" << endl;
        cout << "3.DEPOSIT MONEY" << endl;
        cout << "4.WITHDRAW MONEY" << endl;
        cout << "5.DELETE ACCOUNT" << endl;
        cout << "6.EXIT" << endl;
        cout << "ENTER CHOICE: " << endl;
        cin >> choice;
        cout << endl;
        switch (choice)
        {
        case 1:
        {
            string name;
            int acc_number;
            double balance;
            cout << "Enter name: " << endl;
            cin >> name;
            cout << endl;
            cout << "Enter account number: " << endl;
            cin >> acc_number;
            cout << endl;
            cout << "Enter opening balance: " << endl;
            cin >> balance;
            cout << endl;
            bank.add_account(name, acc_number, balance);
            cout << "Account Created" << endl;
            break;
        }
        case 2:
        {
            int acc;
            cout << "Enter account number: ";
            cin >> acc;
            cout << endl;
            BankAccount *account = bank.findAccount(acc);
            if (account != NULL)
            {
                cout << "Available Balance: " << account->getbalance();
            }

            else
            {
                cout << "Account not found";
            }
            break;
        }
        case 3:
        {
            int accountNum;
            double amount;
            cout << "Enter Account Number to Deposit Money :";
            cin >> accountNum;
            BankAccount *account = bank.findAccount(accountNum);
            if (account != NULL)
            {
                cout << "\t\tEnter Amount to Deposit :";
                cin >> amount;
                account->deposit(amount);
                cout << "\t\t" << amount << " Deposit Successfully ...." << endl;
            }
            else
            {
                cout << "\t\tAcount Not Found ..." << endl;
            }
            break;
        }
        case 4:
        {
            int accountNum;
            double amount;
            cout << "Enter Account Number to Withdraw Money :";
            cin >> accountNum;
            BankAccount *account = bank.findAccount(accountNum);
            if (account != NULL)
            {
                cout << "\t\tEnter Amount to withdraw :";
                cin >> amount;
                account->withdraw(amount);
                cout << "\t\t" << amount << " withdraw Successfull ...." << endl;
            }
            else
            {
                cout << "\t\tAcount Not Found ..." << endl;
            }
            break;
        }
        case 5:
        {
            int accountNum;
            cout << "Enter Account Number to delete :";
            cin >> accountNum;
            BankAccount *account = bank.findAccount(accountNum);
            if (account != nullptr)
            {
                bank.del_acc(accountNum);
                cout << "\t\t" << " account deleted  Successfully ...." << endl;
            }
            else
            {
                cout << "\t\tAcount Not Found ..." << endl;
            }
            break;
        }
        case 6:
        {
            exit(1);
            break;
        }
        }

        cout << "\tDo You Want to Countinue or Exit [Y/N]: ";
        cin >> option;

    } while (option == 'y' || option == 'Y');
    return 0;
}