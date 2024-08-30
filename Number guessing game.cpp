#include<iostream>
#include<stdlib.h>
#include<ctime>
using namespace std;
int main()
{
    int a,b,n,i,choice;
    cout<<"                                    ********** NUMBER GUESING GAME **********\n";
    cout<<"                           *****~~~~~~***** Welcome In Number Guesing Game *****~~~~~~*****\n\n";
    cout<<"   GUIDELINES TO PLAY GAME:\n";
    cout<<"*. In These Game User Have to Guess the Number Which is randomly generate by Computer In Between 1~100 Number.\n";
    cout<<"*. You Have Different Levels You Can Choose Any One Of Them.\n";
    cout<<"*. You Will Get Number Of Attempts According To Your Levels.\n";
    cout<<"*. Enter 1 For Easy Level And You Will Get Only 10 Attempts.\n*  Enter 2 For Medium Level And You Will Get Only 7 Attempts.\n*. Enter 3 For Difficult Level And You Will Get Only 5 Attempts.\n";
    cout<<"*. And Then Enter The Number Between 1~100 For Finding The secret Number.\n";
    cout<<"*. When Guess Number is Match To The Secret Number Then User Will Win.\n\n";
    cout<<"                          *******.NOW ITS TURN TO PLAY THE GAME.********\n";
    cout<<"                                      **~*. GOOD LUCK .*~**\n\n";
	cout<<"Press Any Key To Start The Game\n";
	getchar();
    cout<<"\n ENTER YOUR CHOICE.\n";
    cout<<"1.Easy Level\n";
    cout<<"2.Medium Level\n";
    cout<<"3.Difficult Level\n";
    cin>>choice;
    switch(choice)
      {
	    case 1:
		    cout<<"** You Have Only 10 Chance To Win The Game.\n\n";
		    b=10;
		    break;
	    case 2:
	    	cout<<"**. You Have Only 7 Chance To Win The Game.\n\n";
	    	b=7;
		    break;
	    case 3:
		    cout<<"**. You Have Only 5 Chance To Win The Game.\n\n";
		    b=5;
		    break;
	    default:
		   cout<<"                     ******                THIS IS INVALID CHOICE          ****** \n\n      ;                                    Please Enter Valid Choice.\n";
		   exit(0);
       }
    	srand(time(NULL));
		n=rand()%100+1; 
	for(i=1;i<=b;i++)
        {
           cout<<"**. Enter Your Number Between 1~100.\n";
           cin>>a;
		   if(a>=1&&a<=100)
	         {
		        if(n>a)
	              {
		            cout<<"Secret Number Is Greater Than User Number.\n";
	               }
	            else if(n==a)
      	          {
	     	        cout<<"Secret Number Is Equal To User Number.\n";
		            break;
	              }  
	            else
     	          {
		             cout<<"Secret Number Is Less Than User Input.\n";
      	          } 
		       cout<<"You Have Only "<<b-i<<"Remaining choices\n\n";
              }  
            else 
              {
   
                 cout<<"Invalid Number \n\n Please Enter The Number Between 1~100\n";
	             exit(0);
	           }
     
        }
    if(a==n)
	{
        cout<<"                                          *******             USER WIN        *******\n\n"; 
        cout<<"                                                     CONGRATS! USER WIN THIS GAME.\n";
	}
    else
	{
        cout<<"                                     *******                 USER LOSE        ********\n\n";
        cout<<"                                                        SORRY! UsER LOSE THIS GAME .\n";
        cout<<"                                                         PLEASE TRY AGAIN TO WIN.\n\n";
    }
    cout<<"                                                         ***.. Secret Number Is :"<<n;
}
