#include<iostream>
#include<fstream>
#include<string.h>
#include<sstream>
#include<windows.h>
using namespace std;
class Bank{
  private:
   string Account_name;
  int balance;
  int ATM_PIN;
 
  public:
  Bank():Account_name(" "), balance(0),ATM_PIN(0){}

setAccount_name(string id){
    Account_name=id;
}
setbalance(int amount){
    balance=amount;
}
setATM_PIN(int pass){
    ATM_PIN=pass;
}
 string getAccount_name(){
    return Account_name;
 }
 int getbalance(){
    return balance;
 }
 int getATM_PIN(){
    return ATM_PIN;
 }
};





 Deposit(Bank user){
    string id;
    int pass;
    cout<<"Enter your Account Name: ";
    cin>>id;
    cout<<"\n";
    cout<<"Enter your Account PIN: ";
    cin>>pass;
    ifstream f2("workspace.txt");
    ofstream f3("workspacetemp.txt");
     string line;
     bool net=false;
     while(getline(f2,line)){
        stringstream ss;
        ss<<line;
         string userid;
         int userpass;
         int userbalance;
         char delimiter;
         ss>>userid>>delimiter>>userpass>>delimiter>>userbalance;
         if(id == userid && pass==userpass){
            
            net=true;
            int cash;
            cout<<"Enter the amount ";
            cin>>cash;
            int newbalance=userbalance+cash;
            userbalance=newbalance;
            f3 <<"\t"<<userid<<" :"<<userpass<<" :"<< userbalance<<endl;
            cout<<"<-----DEPOSIT SUCCESSFUL----->"<<endl;
            Sleep(3000);
            cout<<"THE REMAINIG BALANCE:"<<userbalance<<endl;
}
         else{
            f3<<line<<endl;
         }
        
     }
       if(!net){
            cout<<"INCORRECt ACCOUNT NAME or PASSWORD \n";}
         f2.close();
         f3.close();
         remove("workspace.txt");
         rename("workspacetemp.txt","workspace.txt");
         }
     
    


 NewAccount(Bank user){
    system("cls");
    string id;
    int pass;
    cout<<"ENTER THE Account Name: ";
    cin>>id;
    user.setAccount_name(id);
    cout<<"Enter the PASSWORD OR PIN: ";
    cin>>pass;
    user.setATM_PIN(pass);
    ofstream f1("workspace.txt",ios::app);
    if(!f1){
        cout<<"\t FILE CAN'T OPEN";
    }
    f1<<"\t"<<user.getAccount_name()<<" : "<<user.getATM_PIN()<<" : "<<user.getbalance()<<endl;
    cout<<"<------Account Created Successfully----->\n"<<endl;
    f1.close();

};
    withdraw(Bank user)
    {
      system("cls");
      string id;
    int pass;
    cout<<"Enter your Account Name: ";
    cin>>id;
    cout<<"\n";
    cout<<"Enter your Account PIN: ";
    cin>>pass;
    ifstream f2("workspace.txt");
    ofstream f3("workspacetemp.txt");
     string line;
     bool net=false;
     while(getline(f2,line)){
        stringstream ss;
        ss<<line;
         string userid;
         int userpass;
         int userbalance;
         char delimiter;
         ss>>userid>>delimiter>>userpass>>delimiter>>userbalance;
         if(id == userid && pass==userpass){

            
            net=true;
            int cash;
            cout<<"Enter the amount  ";
            cin>>cash;
            int newbalance;
            if(userbalance>=cash){
            newbalance=userbalance-cash;
            userbalance=newbalance;
            f3 <<"\t"<<userid<<" :"<<userpass<<" :"<< userbalance<<endl;
            cout<<"THE REMAINIG BALANCE:"<<userbalance<<endl;
            }
            else{
               cout<<"balance is not suffiecient "<<endl;
            }
}
         else{
            f3<<line<<endl;
         }
        
     }
       if(!net){
            cout<<"INCORRECt ACCOUNT NAME or PASSWORD \n";}
         f2.close();
         f3.close();
         remove("workspace.txt");
         rename("workspacetemp.txt","workspace.txt");
         }

    

int main(){
    Bank user;
    bool term=false;
    
   
    while(!term){
    int c;
    cout<<"\t\t<----WELCOME TO UTTARAKHAND  BANK  OF INDIA----->\n";
     cout<<"\t\t PRESS 1 TO OPEN ACCOUNT\n";
     cout<<"\t\t PRESS 3 TO Withdraw Money\n";
      cout<<"\t\t PRESS 2 TO  Desposit MONEY\n";
      cout<<"\t\t PRESS 4 TO exit\n";
      cout<<"\t\t Enter your Choice : ";
      cin>>c;
 
      if(c==1){
        NewAccount(user);
        
         }
      else if (c==2)
      {
        Deposit(user);
        
      }
      else if(c==3){
         withdraw(user);
      }
      else if(c==4){
         term=true;
      }
    }
        


}


