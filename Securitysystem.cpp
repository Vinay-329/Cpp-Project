#include<iostream>
#include<fstream>//open the file 
#include<sstream>
#include<string>
using namespace std;
int main(){
    int a,i=0;
    string text,old,password1,password2,pass,name,password0,age,user,word,word1;
    string cred[2],cp[2];
    cout<<"        Security System        "<<endl;

    cout<<"_______________________________"<<endl<<endl;
    cout<<"|          1.Register         |"<<endl; 
    cout<<"|          2.Login            | "<<endl;
    cout<<"|          3.Change Password  | "<<endl;
    cout<<"|__________4.End Program______|"<<endl;  
    do{
        cout<<endl<<endl;
        cout<<"Enter your choice:-";
        cin>>a;
        switch (a)
        {
            case 1:
            {
                cout<<"----------Register-----------"<<endl<<endl;
                cout<<"Please enter username:-";
                cin>>name;
                cout<<"Please enter the password:-";
                cin>>password0;
                cout<<"Please enter the age:-";
                cin>>age;

                ofstream of1;//ofstream is used for the writing of file
                of1.open("file.txt");
                if(of1.is_open())
                {
                    of1<<name<<"\n";
                    of1<<password0;
                    cout<<"Registration successful"<<endl; 
                }
             break;
        
            }//everything is ok upto here.
            case 2:{
                i=0;
                cout<<"--------Login---------"<<endl<<endl;

                ifstream of2;//ifsteam is used for reading of file
                of2.open("file.txt");
                cout<<"Please enter the username:-";
                cin>>user;
                cout<<"Please enter the password:-";
                cin>>pass;
                if(of2.is_open())
                {
                    while(!of2.eof())
                    {
                        while(getline(of2,text))//using getline function file will be read line by line 
                        {
                            istringstream iss(text); //is used to stream the string and store it using the extraction opreater
                            iss>>word; //this is a extraction opreator
                            cred[i]=word;//in the first postion username will be stored and second postion password
                            i++;//so we have to increase it by i++
      
                        } 
                        if(user == cred[0] && pass==cred[1])
                        {
                            cout<<"-----Login successfull-----";
                            cout<<endl<<endl;

                            cout<<"   Details:  "<<endl;
                            cout<<"Username: "+ name<<endl;
                            cout<<"Password: "+ pass<<endl;
                            cout<<"Age: "+ age<<endl;

                        }
                        else
                        {
                            cout<<endl<<endl;
                            cout<<"Incorrect Credentails"<<endl;
                            cout<<"      1.Press 2 to login     "<<endl;
                            cout<<"      2.Press 3 to change password     "<<endl;
                            break;
                        }
                    }
                } 
                break;
            }
            case 3:
            {
            i=0;
            cout<<"---------Change Password--------"<<endl;
            ifstream of0;
            of0.open("file.txt");
            cout<<"Enter the old password:-";
            cin>>old;
            if(of0.is_open())
            {
                while(of0.eof())
                {
                    while(getline(of0,text))
                    {
                        istringstream  iss(text);//some problem in case3 because it is not changing the password
                        iss>>word1;
                        cp[i]=word1; 
                        i++;

                    }
                    if(old == cp[1])
                    {
                    of0.close();
                    ofstream of1;
                    if(of1.is_open())
                    {
                        cout<<"Enter your new password:-";
                        cin>>password1;
                        cout<<"Enter your password again:-";
                        cin>>password2;

                        if(password1==password2)
                        {
                            of1<<cp[0]<<"\n";
                            of1<<password1;
                            cout<<"Password changed successfully"<<endl;
                        }
                        else
                        {
                            of1<<cp[0]<<"\n";
                            of1<<old;
                            cout<<"Password do not match"<<endl;
                        }
                    }
                }
                else{
                    cout<<"Please enter a valid password"<<endl;
                    break;
                }
            }
        }
        break;
    }
       case 4:
        {
            cout<<"-----**-------Thank You-------**--------";
            break;
        }
        default:
        {
            cout<<"Enter a valid choice";
        }
    }  
}
 while(a!=4);
    return 0;
}