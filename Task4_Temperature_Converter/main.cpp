#include <iostream>
using namespace std;
int main(){
int choice;
double temperature,result;
cout<<"=====================================\n";
cout<<"     COGNIFYZ TEMPERATURE CONVERTER\n";
cout<<"=====================================\n";
do{
cout<<"\n========== MENU ==========\n";
cout<<"1. Celsius to Fahrenheit\n";
cout<<"2. Fahrenheit to Celsius\n";
cout<<"3. Exit\n";
cout<<"===========================\n";
cout<<"Enter your choice: ";
cin>>choice;
if(choice==1){
cout<<"Enter temperature in Celsius: ";
cin>>temperature;
result=(temperature*9/5)+32;
cout<<"Temperature in Fahrenheit: "<<result<<" F\n";
}
else if(choice==2){
cout<<"Enter temperature in Fahrenheit: ";
cin>>temperature;
result=(temperature-32)*5/9;
cout<<"Temperature in Celsius: "<<result<<" C\n";
}
else if(choice==3){
cout<<"\nThank you for using Cognifyz Temperature Converter!\n";
}
else{
cout<<"\nInvalid choice. Please try again.\n";
}
}while(choice!=3);
return 0;
}
