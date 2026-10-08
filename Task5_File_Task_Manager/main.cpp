#include <iostream>
#include <fstream>
#include <vector>
#include <string>
using namespace std;

class Task{
public:
int id;
string title;
string description;
bool completed;
Task(int taskId,string taskTitle,string taskDescription,bool taskCompleted=false){
id=taskId;
title=taskTitle;
description=taskDescription;
completed=taskCompleted;
}
};

void saveTasks(const vector<Task>& tasks){
ofstream file("tasks.txt");
if(!file){
cout<<"\nError: Unable to save tasks.\n";
return;
}
for(const Task& task:tasks){
file<<task.id<<"\n";
file<<task.title<<"\n";
file<<task.description<<"\n";
file<<task.completed<<"\n";
}
file.close();
}

void loadTasks(vector<Task>& tasks){
ifstream file("tasks.txt");
if(!file)return;
int id;
bool completed;
string title,description;
while(file>>id){
file.ignore();
getline(file,title);
getline(file,description);
file>>completed;
file.ignore();
tasks.push_back(Task(id,title,description,completed));
}
file.close();
}

void displayTasks(const vector<Task>& tasks){
if(tasks.empty()){
cout<<"\nNo tasks available.\n";
return;
}
cout<<"\n========== TASK LIST ==========\n";
for(const Task& task:tasks){
cout<<"\nTask ID: "<<task.id;
cout<<"\nTitle: "<<task.title;
cout<<"\nDescription: "<<task.description;
cout<<"\nStatus: "<<(task.completed?"Completed":"Pending");
cout<<"\n-------------------------------\n";
}
}

void createTask(vector<Task>& tasks){
int id;
string title,description;
cout<<"\nEnter Task ID: ";
cin>>id;
cin.ignore();
for(const Task& task:tasks){
if(task.id==id){
cout<<"\nError: Task ID already exists.\n";
return;
}
}
cout<<"Enter Task Title: ";
getline(cin,title);
cout<<"Enter Task Description: ";
getline(cin,description);
if(title.empty()||description.empty()){
cout<<"\nError: Title and description cannot be empty.\n";
return;
}
tasks.push_back(Task(id,title,description));
saveTasks(tasks);
cout<<"\nTask created successfully!\n";
}

void updateTask(vector<Task>& tasks){
int id;
cout<<"\nEnter Task ID to update: ";
cin>>id;
cin.ignore();
for(Task& task:tasks){
if(task.id==id){
cout<<"Enter new title: ";
getline(cin,task.title);
cout<<"Enter new description: ";
getline(cin,task.description);
int status;
cout<<"Enter status (1=Completed, 0=Pending): ";
cin>>status;
if(status!=0&&status!=1){
cout<<"\nError: Invalid status.\n";
return;
}
task.completed=(status==1);
saveTasks(tasks);
cout<<"\nTask updated successfully!\n";
return;
}
}
cout<<"\nTask not found.\n";
}

void deleteTask(vector<Task>& tasks){
int id;
cout<<"\nEnter Task ID to delete: ";
cin>>id;
for(auto it=tasks.begin();it!=tasks.end();++it){
if(it->id==id){
tasks.erase(it);
saveTasks(tasks);
cout<<"\nTask deleted successfully!\n";
return;
}
}
cout<<"\nTask not found.\n";
}

int main(){
vector<Task> tasks;
int choice;
loadTasks(tasks);
cout<<"=====================================\n";
cout<<"      COGNIFYZ FILE TASK MANAGER\n";
cout<<"=====================================\n";
do{
cout<<"\n========== MENU ==========\n";
cout<<"1. Create Task\n";
cout<<"2. View Tasks\n";
cout<<"3. Update Task\n";
cout<<"4. Delete Task\n";
cout<<"5. Exit\n";
cout<<"===========================\n";
cout<<"Enter your choice: ";
if(!(cin>>choice)){
cin.clear();
cin.ignore(1000,'\n');
cout<<"\nInvalid input. Please enter a number.\n";
continue;
}
switch(choice){
case 1:createTask(tasks);break;
case 2:displayTasks(tasks);break;
case 3:updateTask(tasks);break;
case 4:deleteTask(tasks);break;
case 5:cout<<"\nThank you for using Cognifyz File Task Manager!\n";break;
default:cout<<"\nInvalid choice. Please try again.\n";
}
}while(choice!=5);
return 0;
}
