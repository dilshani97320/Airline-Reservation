#include<fstream>
#include<iostream>
#include <sstream>     // istringstream function
#include<string>
using namespace std;

struct seat{ // structure for seat
	string row;
	string clz;
	string no;
};

class flight{
	public:                                                                        
		string flightNo;
		string dateAndTime;
		string deAirport;
		string arAirport;
		int B_clz; 
		int E_clz; 
		int rows;
		seat obj[100];  //create structure array
		
	
		
};

	flight flightArray[1000]; //array for class
	int count; // Number of flight 

	int getFlightCount(){ // get number of flight
		ifstream file("flights.txt");  //open file 
		string ch;
		int i=0;
		int count=0;
		while(getline(file,ch)!=NULL){ // run until the line is not empty
			if(i==0){
				if(!ch.empty()){  
					count++;
					i++;   
				}
			}
			else{
				if(ch.empty()){  
					i++;
					getline(file,ch);
					if(!ch.empty()){
						count++;
						i++;
					}
					else{
						i++;
					}
					
				}
				else{
					i++;
				}
			}
		}
		return count;
	}
	
void display(){
	
	int i;
	for(i=0;i<count;i++){
		cout<<endl<<"Flight No--> "<<flightArray[i].flightNo;                     //show details of flights
		cout<<endl<<"Departure date/time--> "<<flightArray[i].dateAndTime;
		cout<<endl<<"Arrival airport--> "<<flightArray[i].arAirport;
		cout<<endl<<"Departure airport--> "<<flightArray[i].deAirport;
		cout<<endl;
	}
}
void searchFlight(){
	string flightNo;
	cout<<endl<<"Enter the Flight No  :";
	cin>>flightNo;
	int available;
	int i;
	int flight; // which flight on the text
	for(i=0;i<count;i++){
		if(flightNo == flightArray[i].flightNo){ //check if , the flight available
			flight = i;  
			available = 1;
			break;   
		}
	}
	if(available == 1){   
		cout<<endl<<"Flight No--> "<<flightArray[i].flightNo;
		cout<<endl<<"Departure date/time--> "<<flightArray[i].dateAndTime;
		cout<<endl<<"Arrival airport --> "<<flightArray[i].arAirport;
		cout<<endl<<"Departure airport --> "<<flightArray[i].deAirport;
		int available;
	
		int j;
		int i;
		int flight; // which flight on the text
		for(i=0;i<count;i++){
			if(flightNo == flightArray[i].flightNo){
				flight = i;
				available = 1;
				break;
			}
		}
		flightArray[flight].E_clz = 0;  
		flightArray[flight].B_clz = 0; 
		for(j=0;j<60;j++){
			if(flightArray[flight].obj[j].clz == "B"){  //check if the class is business class
				flightArray[flight].B_clz = flightArray[flight].B_clz + flightArray[flight].obj[j].no.length();  //to get number of seats available in business class
			}else{
				flightArray[flight].E_clz = flightArray[flight].E_clz + flightArray[flight].obj[j].no.length();   //to get number of seats available in economical class
			}
		
		}
		cout<<endl<<"Available class-E seats : "<<flightArray[flight].E_clz;    
		cout<<endl<<"Available class-B seats : "<<flightArray[flight].B_clz;    
	}else{
		cout<<endl<<"Sorry,  flight is not available..."; 
	}
}
void availableSeats(){
	string flightNo;
	cout<<endl<<"Enter the Flight number  :";
	cin>>flightNo;
	int noOfSeats;
	cout<<endl<<"Enter No of seats, you want :";
	cin>>noOfSeats;
	int available;
	int noOfAvailableSeats;
	
	int j;
	int i;
	int flight; //  flight which was want to user
	for(i=0;i<count;i++){
		if(flightNo == flightArray[i].flightNo){
			flight= i;
			available = 1;
			break;
		}
	}
	flightArray[flight].E_clz = 0;   
	flightArray[flight].B_clz = 0;  
	for(j=0;j<60;j++){
		if(flightArray[flight].obj[j].clz == "B"){
			flightArray[flight].B_clz = flightArray[flight].B_clz + flightArray[flight].obj[j].no.length(); //call length function to find seats
		}else{
			flightArray[flight].E_clz = flightArray[flight].E_clz + flightArray[flight].obj[j].no.length();
		}
		
	}
	
	noOfAvailableSeats = flightArray[flight].E_clz + flightArray[flight].B_clz; //gets total number of seats
	if(available == 1){
		if(noOfSeats > noOfAvailableSeats){  
			cout<<endl<<"Not Available ";
			cout<<endl<<"class-B : ";
			cout<<flightArray[flight].B_clz;                  
			cout<<endl<<"class-E : ";
			cout<<flightArray[flight].E_clz;   //print available economic  class seats
		}else{        //if seats are available
			
			cout<<endl<<"Available class-B : "<<flightArray[flight].B_clz;
			for(j=0;j<60;j++){
				if(flightArray[flight].obj[j].clz == "B"){
					cout<<endl<<flightArray[flight].obj[j].row<<"  "<<flightArray[flight].obj[j].clz<<" "<<flightArray[flight].obj[j].no;
					//print seat details of business class
				}
			}
			cout<<endl<<"Available class-E  : "<<flightArray[flight].E_clz;
			for(j=0;j<60;j++){
				if(flightArray[flight].obj[j].clz == "E"){
					cout<<endl<<flightArray[flight].obj[j].row<<"  "<<flightArray[flight].obj[j].clz<<" "<<flightArray[flight].obj[j].no;  
					 //print seat details of economic class
				}
			}
		}
	}else{
		cout<<endl<<"Sorry,  flight is not available..."; 
	}
	
}
void Booking(){
	string flightNo;
	string row;
	string column;
	cout<<endl<<"Enter the Flight No  :";
	cin>>flightNo;
	int available;
	int booked;
	int i;
	int flight; // flight which chose
	int j;
	for(i=0;i<count;i++){  
		if(flightNo == flightArray[i].flightNo){
			flight = i;
			available = 1;
			break;
		}
	}
	if(available == 1){
		cout<<endl<<" row-->  :";
		cin>>row;
		cout<<endl<<" column-->  :";
		cin>>column;
		for(j=0;j<=60;j++){
			
			if(flightArray[flight].obj[j].row==row){   
				if(flightArray[flight].obj[j].no.find(column)!=string::npos){     
					flightArray[flight].obj[j].no.erase(flightArray[flight].obj[j].no.find(column),1); 
					booked = 1;
					break;
				}else{
					booked = 0;
				}
				
			}
			
		}
		
		if(booked == 1){
			cout<<endl<<"seat booking is successfull";
			
		}else{
			cout<<endl<<" INVALID INPUT!";
		}
			
	}else{
		cout<<endl<<"Sorry,  flight is not available..."; //if searched flight is not available
	}
}


void exitBooking(){
	
	ofstream newFile("flights.txt");
	for(int i=0;i<count;i++){
		int k=0;
		newFile<<flightArray[i].flightNo<<endl;
		newFile<<flightArray[i].dateAndTime<<endl;
		newFile<<flightArray[i].deAirport<<endl;        
		newFile<<flightArray[i].arAirport<<endl;             // wirte data to the text file
		while(1){
			if(flightArray[i].obj[k].row==""){
				break;
			}
			else{
				newFile<<flightArray[i].obj[k].row<<" "<<flightArray[i].obj[k].clz<<" "<<flightArray[i].obj[k].no<<endl;
			}
			
			k++;
		}
		newFile<<endl;
	}newFile.close();
	exit(0);
}
	
	
	
	
	

int main(){
	int choise;
	
	count=getFlightCount();  
	string line;
	
	ifstream file("flights.txt");
	
	
	int se_no=0; 
	seat st[100];
	
	int i;
	int x=0;
	for(i=0;i<count;i++){
	string line;			
	int y=0;
	while(!file.eof()){
     getline(file,line);
	 //check the text file line is not ! empty 
		
	if(!line.empty()){  
		
	if(y==0){
		flightArray[i].flightNo=line;
	
		y++;
	}
	else if(y==1){
	   flightArray[i].dateAndTime=line;
	
	   y++;
	}
	else if(y==2){
		flightArray[i].arAirport=line;
	
		y++;
	}
	else if (y==3){
		flightArray[i].deAirport=line;
	
		y++;
		
	}
	else if(y>=4){
		
		
		istringstream ss(line);
		ss >> flightArray[i].obj[se_no].row >> flightArray[i].obj[se_no].clz >> flightArray[i].obj[se_no].no;
		
	
		y++;
		se_no++;
	
	}
		}else
		{
			y=0;
			i++;
			se_no=0;
		}
			
	}
	}
		
	    int run = 1;
    while(1){
    	cout<<endl<<"*************MAIN MENU **************"<<endl<<endl; 
		cout<<"*************************************"; 
		cout<<endl<<"1--> Display available flights";
		cout<<endl<<"2--> View flight";
		cout<<endl<<"3--> Seat availability";
		cout<<endl<<"4--> Seat booking";
		cout<<endl<<"5--> Exit"<<endl<<endl;
		cout<<endl<<"Enter an option:";  
		cin>>choise;
		bool ignore=false;
		while(!cin)   
		{
			if(!ignore)   
			{
				cout<<"INVALID CHOISE"<<endl;
				
				ignore=true;
				
			}
			
			cin.clear(); 
			cin.ignore();
			cin>>choise;
		}
		
		
		switch(choise){
			case 1: 
				display(); 
				break;  
			case 2:
				searchFlight();  
				break;
			case 3:
				availableSeats();      
				break;
			case 4:
				Booking();     
				break;
			case 5:
				run = 0;
				
				exitBooking();
				break;
			default:    
				cout<<endl<<"INVALID CHOISE ";
				
				break;
				
			
		}
	}
	
	return 0;
}

	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	

