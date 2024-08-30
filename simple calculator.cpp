#include<iostream>
#include<cmath>
#include<limits>
using namespace std;
class A{
	double a;
	double b;
	public:
    void set(double a,double b)
	{
    	this->a=a;
    	this->b=b;
    
	}
    void input() {
        cout << "Enter First number: ";
        while (!(cin >> a)) { 
            cout << "Invalid input! Please enter a numeric value: ";
            cin.clear();  
            cin.ignore(numeric_limits<streamsize>::max(), '\n');  
        }

        cout << "Enter Second number: ";
        while (!(cin >> b)) {  
            cout << "Invalid input! Please enter a numeric value: ";
            cin.clear();  
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); 
        }
    }
	void add()
	{
		cout<<"sum is : "<< a+b<< endl ;
	}
		void sub()
	{
		cout<<"Subtraction is : "<< a-b<< endl;
	}
		void div()
	{
			 if (b != 0) { 
            cout << "Quotient is : " << a / b << endl;
        } else {
            cout << "Error: Division by zero is not allowed." << endl;
        }
	}
		void mul()
	{
		cout<<"Multiplication is : "<< a*b<< endl;
	}
	
};
int main() {
    A obj;  
    char choice;
    string i = "";  

    while (i != "stop") {
        obj.input();  
        cout << "Enter choice : "<<endl<<"( + for add )"<<endl<<"( - for subtract )"<<endl<<"( * for multiply )"<<endl<<"( / for divide )";
        cin >> choice;
        switch (choice) {
            case '+':
                obj.add();
                break;
            case '-':
                obj.sub();
                break;
            case '*':
                obj.mul();
                break;
            case '/':
                obj.div();
                break;
            default:
                cout << "Enter correct choice" << endl;
        }

        cout << "To stop the program, enter 'stop'. Otherwise, press enter to continue: ";
        cin.ignore(); 
        getline(cin, i);  
    }

    return 0;
}








