#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
using namespace std;

string downloadPage(string url){
string command="powershell -Command \"try { (Invoke-WebRequest -Uri '"+url+"' -UseBasicParsing).Content | Out-File -Encoding utf8 page.html } catch { exit 1 }\"";
int result=system(command.c_str());
if(result!=0)return "";
ifstream file("page.html");
string html((istreambuf_iterator<char>(file)),istreambuf_iterator<char>());
file.close();
return html;
}

string removeTags(string text){
string result;
bool inside=false;
for(char c:text){
if(c=='<')inside=true;
else if(c=='>')inside=false;
else if(!inside)result+=c;
}
return result;
}

void showTitle(const string& html){
size_t start=html.find("<title");
start=html.find(">",start);
size_t end=html.find("</title>",start);
if(start!=string::npos&&end!=string::npos)
cout<<"\nPage Title: "<<removeTags(html.substr(start+1,end-start-1))<<"\n";
else
cout<<"\nTitle not found.\n";
}

void showHeadings(const string& html){
size_t pos=0;
int count=0;
cout<<"\n========== HEADINGS ==========\n";
while((pos=html.find("<h",pos))!=string::npos){
size_t start=html.find(">",pos);
size_t end=html.find("</h",start);
if(start==string::npos||end==string::npos)break;
string heading=removeTags(html.substr(start+1,end-start-1));
if(!heading.empty())cout<<++count<<". "<<heading<<"\n";
pos=end+3;
}
if(count==0)cout<<"No headings found.\n";
}

void showLinks(const string& html){
size_t pos=0;
int count=0;
cout<<"\n========== LINKS ==========\n";
while((pos=html.find("href=",pos))!=string::npos&&count<10){
size_t start=pos+6;
char quote=html[start];
size_t end=html.find(quote,start+1);
if(end==string::npos)break;
cout<<++count<<". "<<html.substr(start+1,end-start-1)<<"\n";
pos=end+1;
}
if(count==0)cout<<"No links found.\n";
}

int main(){
string url,html;
int choice;
cout<<"=====================================\n";
cout<<"       COGNIFYZ WEB SCRAPER\n";
cout<<"=====================================\n";
cout<<"Enter website URL: ";
cin>>url;
cout<<"\nFetching webpage...\n";
html=downloadPage(url);
if(html.empty()){
cout<<"Unable to fetch webpage.\n";
return 1;
}
cout<<"Webpage fetched successfully!\n";
do{
cout<<"\n========== MENU ==========\n";
cout<<"1. View Page Title\n";
cout<<"2. View Headings\n";
cout<<"3. View Links\n";
cout<<"4. Exit\n";
cout<<"===========================\n";
cout<<"Enter your choice: ";
cin>>choice;
switch(choice){
case 1:showTitle(html);break;
case 2:showHeadings(html);break;
case 3:showLinks(html);break;
case 4:cout<<"\nThank you for using Cognifyz Web Scraper!\n";break;
default:cout<<"\nInvalid choice. Please try again.\n";
}
}while(choice!=4);
return 0;
}
