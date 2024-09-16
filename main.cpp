#include <iostream>
#include <string>

using namespace std;
class parson
{
protected:
    int id;
    string name,password;
    bool isAlphatic(string s)
    {
        for(int i=0; i<s.size(); i++)
        {
            char c=s[i];
            if(!isalpha(c))
            {
                return false;
            }
        }
        return true;
    }
public:
    void setId(int i)
    {
        id=i;
    }
    void setName(string n )
    {

            if(n .size()>=5&&n .size()<=20&&isAlphatic(n))
            {
                name=n;
            }
            else
            {
                cout<<"The name must be alphabetic and size between 5 and 20 "<<endl;
                cout<<"Try again to enter the name : ";
                cin>>n;
                setName(n);
                return;
            }

    }
    void setPassword(string p )
    {

            if(p.size()>=8&&p.size()<=20)
            {
                password=p;
            }
            else
            {
                cout<<"The password must be min size 8 and max size 20  "<<endl;
                cout<<"Try again to enter the password : ";
                cin>>p;
                setPassword(p);
                return;
            }


    }
    int getId()
    {
        return id;
    }
    string getName()
    {
        return name;
    }
    string getPassword()
    {
        return password;
    }
};
class Client:public parson
{
protected :
    double balance;
public:

    void setbalance(double b)
    {

            if(b>=1500)
            {
                balance=b;
            }
            else
            {
                cout<<"The minimum balance must be 1,500 "<<endl;
                return;
            }

    }

    double getBalance()
    {
        return balance;
    }
    void deposit(double amount)
    {
        if(amount>0)
        {
            balance+=amount;
            cout<<"The client balance after deposit "<<amount<<" = "<<balance<<endl;
        }
        else
        {
          cout<<"Deposit’s amount should be positive (Invalid amount).";

        }
    }
    void withdraw(double amount)
    {
        if(amount>0 && amount<=balance)
            {
          balance-=amount;
          cout<<"The client balance after withdraw "<<amount<<" = "<<balance<<endl;
            }
            else
            {
                cout<<"Invalid withdraw’s amount "<<endl;
            }
    }
    void transfareTO(double amount, Client& recipie)
    {
        if(amount>0&&amount<=balance)
        {
            recipie.balance+=amount;
            cout<<"The balance that recipient received = "<<recipie.balance<<endl;
            balance-=amount;
            cout<<"The remain balance of the client = "<<balance<<endl;
        }
        else
        {
            cout<<"Invalid transfer amount "<<endl;
        }
    }
    void checkBalance ()
    {
        cout<<"Your current balance : "<<balance<<endl;

    }
    void display()
    {
        cout << "Client Information:" << endl;
        cout<<"Name : "<< getName()<<endl;
        cout<<"Id : "<< getId()<<endl;
        cout<<"Balance : "<<getBalance()<<endl;
        cout<<"password : "<< getPassword()<<endl;

    }
};
class Employee:public parson
{


protected:
    double salary;
public:
    void setSalary(double s)
    {
        if(s<5000)
        {
            cout<<"Salary must be at least 5000 "<<endl;
            cout<<"Try again to enter your salary : ";
            cin>>s;
            setSalary(s);
        }
        else
        {
            salary=s;
        }
    }
    double getSalary()
    {
        return salary;
    }
    void display()
    {
        cout<<"Employee Information : "<<endl;
        cout <<"Name : "<<getName()<< endl;
        cout <<"ID : "<< getId() << endl;
        cout <<"Password : "<<getPassword()<< endl;
        cout<<"Salary : "<<getSalary()<<endl;
    }

};
class Admin:public Employee
{
public:
    void display()
    {
        cout<<"Admin Information : "<<endl;
        cout <<"Name : "<<getName()<< endl;
        cout <<"ID : "<< getId() << endl;
        cout <<"Password : "<<getPassword()<< endl;
        cout<<"Salary : "<<getSalary()<<endl;
    }



};

int main()
{
    Client c;
    Client ob;
    c.setName("Ali");
    c.setId(305051952005);
    c.setPassword("123456789");
    c.setbalance(2300);
    cout<<"Your balance before any thing = "<<c.getBalance()<<endl;
    c.deposit(500);
    c.withdraw(200);
    c.transfareTO(100,ob);
    c.checkBalance();
    c.display();

    Employee f;
    f.setName("John");
    f.setId(1001);
    f.setPassword("password123");
    f.setSalary(9000);
    f.display();

    Admin a;
    a.setId(1234566879);
    a.setName("Ahmad");
    a.setPassword("14567859");
    a.setSalary(70000);
    a.display();


    return 0;
}
