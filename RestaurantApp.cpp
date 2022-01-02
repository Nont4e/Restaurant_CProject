#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <unistd.h>
#include <time.h>

bool check[10],checkD[10],checkF[10];
int pp,table,food[15],set,number,mem_c=3,oc=0,discount,mem_ch;
int f_list[15][10][10],temp_list[15][10][10];
char order[3],mem[100],con,enter=0,choice,input;
float sumbill;
//Booked table
int seat[]={2,2,2,2,4,4,4,4,8,8},stat[]={0,0,0,0,0,0,0,0,0,0};
//Food Name
char food_n [][20][100]={{"[APP]","Mini Burger","Garlic Bread","French Fries","Mexican Style Nachos","Ham N' Cheese Sandwich","BBQ Chicken Wings","Caesar Salad","Smoke Salmon Salad"}
,{"[MC] ","Chicken Parmesan","BBQ Pork Ribs","NYC Beef Steak","Beef Wellington","Grilled Salmon Steak","Mushroom Risotto","Italian Style Pizza","Spaghetti carbonara"}
,{"[DS] ","Tiramisu","Lemon Tart","Souffle","Cannoli","Parfait","Bing-su","Chocolate Lava Cake","Panacotta"}
,{"[D]  ","Green Tea Frappe","Chinese Tea","Chocolate Drink","Fruit Smoothie","Italian Soda","Lemonade","Soft Drink","Water"}
,{"[AD] ","Margarita","Martini","French 75","Mint Julep","Vodka On The Rock","Blue Kamikaze","Red Wine","Beer"}};
//Food List
float food_c[][20]={{0,49.0,69.0,49.0,49.0,149.0,79.0,69.0,89.0},
{0,119.0,249.0,219.0,299.0,279.0,349.0,299.0,119.0},
{0,99.0,179.0,149.0,99.0,99.0,199.0,109.0,129.0},
{0,89.0,59.0,79.0,69.0,99.0,59.0,39.0,19.0},
{0,129.0,139.0,219.0,119.0,209.0,159.0,79.0,59.0}};
//MEMBERSHIP
char mem_name[10000][100]={"natchanon","chansida","aoravee"};
char mem_num[10000][100]={"6188042","6188010","6188003"}; 
int mem_detail[10000][2]={{3,289},{2,581},{4,802}};

void start();

void end(); 

void clearbuffer(){
int c;
while ((c = getchar()) != '\n' && c != EOF){ }
}

void list(int table,char order[0],int set){
	int menu= order[0]-48;
		for(int i=0;i<=food[table];i++)
			if(temp_list[table][set][menu]==0){
				temp_list[table][set][menu]=1;
				food[table]++;
				break;
				}
			else{
				temp_list[table][set][menu]++;
				break;			
	}
}

void foodlist(){
	for(int i=0;i<5;i++){
			for(int j=0;j<=8;j++){
				if(temp_list[table][i][j]!=0){
					if(i<3)
					checkF[table]=1;
					else
					checkD[table]=1;
					f_list[table][i][j]+=temp_list[table][i][j];}	
			}
		}
	}

void reorder(){
	system("cls");
		printf("[Order food or drink]\n");
		printf("\nList of Occupied Table:\n");
		if(oc==0)
			printf("NONE\n");
		else
		for(int i=0;i<10;i++)
			if(stat[i]==1)
				printf("Table %d\n",i+1);
		printf("\nEnter the table number [1-10] (0 to exit): %d\n",table);
}

void redo(){
		for(int i=0;i<5;i++){
			for(int j=0;j<=8;j++){
				if(f_list[table][i][j]!=0){
					f_list[table][i][j]=0;}	
			}
		}
		start();
	}

void clear(){
		for(int i=0;i<5;i++){
			for(int j=0;j<=8;j++){
				if(temp_list[table][i][j]!=0){
					temp_list[table][i][j]=0;}	
			}
		}
		start();
	}

void book(){
		pp=0;
		system("cls");
		printf("[Book a table]\n\nEnter the number of people: ");
		scanf("%d",&pp); 
		clearbuffer();
		if(pp<=0)
		{
		printf("Invalid Number!");
		sleep(1.5);
		book();
		}
		for(int i=0;i<10;i++)
			stat[i]!=1 ? (pp > seat[i] ? stat[i]=2 : stat[i]=0):stat[i]=1; 
		printf("\n============================================================\n");
		printf("%-20s %30s\n","List of tables","Status");
		printf("============================================================\n");
		for(int i=0;i<10;i++){
		printf("Table %d: %d Seats\t\t\t",i+1,seat[i]);
		printf("%-15s",stat[i]==0 ? "Available": stat[i]==1 ? "Occupied":"Not enough seat");
		printf("\n");	
		}
	book2:{
		table = -1;
		printf("\nEnter a table number (input 0 to cancel): ");
		scanf("%d",&table);
		clearbuffer();
		if(table == 0)
			start();
		else if(table <= 10 && table >= 1 && stat[table-1]==0){
			stat[table-1]=1;
			oc++;
			printf("Booking Completed");
			sleep(2);
			start();
		}
		else{ 
			printf("Invalid choice!");
			goto book2;
		}
	}
}
	
void ordering(){
		system("cls");
		printf("[Order food or drink]\n");
		printf("\nList of Occupied Table:\n");
		if(oc==0)
			printf("NONE\n");
		else
			for(int i=0;i<10;i++)
				if(stat[i]==1)
				printf("Table %d\n",i+1);
		printf("\nEnter the table number [1-10] (0 to exit): ");
		scanf("%d",&table); clearbuffer();
			if(table==0)
				start();
			else if(stat[table-1]==1)
				goto orderA;
			else {
				printf("Invalid choice!");
				sleep(1.5);
					ordering();}
		
		orderA:{
			set = 0;
			printf("============================================================\n");
			printf("Order food and drink\n");
			printf("============================================================\n");
			printf("\n%-40s %-13s","  Appetizer","Price (Baht)\n");
			printf("------------------------------------------------------------\n");
			printf("%-40s %-3s"," [1]Mini Burger","49.0\n");
			printf("%-40s %-3s"," [2]Garlic Bread","69.0\n");
			printf("%-40s %-3s"," [3]French Fries","49.0\n");
			printf("%-40s %-3s"," [4]Mexican Style Nachos","49.0\n");
			printf("%-40s %-3s"," [5]Ham N Cheese Sandwich","149.0\n");
			printf("%-40s %-3s"," [6]BBQ Chicken Wings","79.0\n");
			printf("%-40s %-3s"," [7]Caesar salad","69.0\n");
			printf("%-40s %-3s"," [8]Smoke Salmon Salad","89.0\n");
			printf("------------------------------------------------------------\n");
			printf("Press = to go the next page, Press 0 to stop\n");
			orderA1:{
				printf("Enter the choice: ");
				scanf(" %s",order);
				if(strlen(order)==1){
				if(strcmp(order,"0")==0)
					goto orderlist;
				else if(strcmp(order,"1")>=0 && strcmp(order,"8")<=0){
					list(table,order,set);
					goto orderA1;}
				else if(strcmp(order,"=")==0){
					reorder();
					goto orderB;}
				else {
					printf("Invalid choice!\n");
					goto orderA1;}
					}
				else{
					printf("Invalid choice!\n");
					goto orderA1;}
			}
		}	
		orderB:{
			set = 1;
			printf("============================================================\n");
			printf("Order food and drink\n");
			printf("============================================================\n");
			printf("\n%-40s %-13s","  Main course","Price (Baht)\n");
			printf("------------------------------------------------------------\n");
			printf("%-40s %-3s"," [1]Chicken Parmesan","119.0\n");
			printf("%-40s %-3s"," [2]BBQ Pork Ribs","249.0\n");
			printf("%-40s %-3s"," [3]NYC Beef Steak","219.0\n");
			printf("%-40s %-3s"," [4]Beef Wellington","299.0\n");
			printf("%-40s %-3s"," [5]Grilled Salmon Steak","279.0\n");
			printf("%-40s %-3s"," [6]Lobster & Broccoli Stir-fry","349.0\n");
			printf("%-40s %-3s"," [7]Italian Style Pizza","299.0\n");
			printf("%-40s %-3s"," [8]Spaghetti Carbonara","119.0\n");
			printf("------------------------------------------------------------\n");
			printf("Press - to go to previous page ,Press = to go the next page\nPress 0 to stop\n");
			orderB1:{
				printf("Enter the choice: ");
				scanf("%s",order);
				if(strlen(order)==1){
				if(strcmp(order,"0")==0)
					goto orderlist;
				else if(strcmp(order,"1")>=0 && strcmp(order,"8")<=0){
					list(table,order,set);goto orderB1;}
				else if(strcmp(order,"-")==0){
					reorder();goto orderA;}
				else if(strcmp(order,"=")==0){
					reorder();goto orderC;}
				else {
					printf("Invalid choice!\n");
					goto orderB1;}
				}
				else{
					printf("Invalid choice!\n");
					goto orderB1;}
				
			}
		}	
		orderC:{
			set=2;
			printf("============================================================\n");
			printf("Order food and drink\n");
			printf("============================================================\n");
			printf("\n%-40s %-13s","  Desserts","Price (Baht)\n");
			printf("------------------------------------------------------------\n");
			printf("%-40s %-3s"," [1]Tiramisu","99.0\n");
			printf("%-40s %-3s"," [2]Lemon tart","179.0\n");
			printf("%-40s %-3s"," [3]Souffle","149.0\n");
			printf("%-40s %-3s"," [4]Cannoli","99.0\n");
			printf("%-40s %-3s"," [5]Parfait","99.0\n");
			printf("%-40s %-3s"," [6]Bing-su","199.0\n");
			printf("%-40s %-3s"," [7]Chocolate Lava Cake","109.0\n");
			printf("%-40s %-3s"," [8]Panacotta","129.0\n");
			printf("------------------------------------------------------------\n");
			printf("Press - to go to previous page ,Press = to go the next page\nPress 0 to stop\n");
			orderC1:{
				printf("Enter the choice: ");
				scanf("%s",order);
				if(strlen(order)==1){
				if(strcmp(order,"0")==0)
					goto orderlist;
				else if(strcmp(order,"1")>=0 && strcmp(order,"8")<=0){
					list(table,order,set);goto orderC1;}
				else if(strcmp(order,"-")==0){
					reorder();goto orderB;}
				else if(strcmp(order,"=")==0){
					reorder();goto orderD;}
				else {
					printf("Invalid choice!\n");
					goto orderC1;}
				}
				else{
					printf("Invalid choice!\n");
					goto orderC1;}
			}
		}	
		orderD:{
			set=3;
			printf("============================================================\n");
			printf("Order food and drink\n");
			printf("============================================================\n");
			printf("\n%-40s %-13s","  Drinks","Price (Baht)\n");
			printf("------------------------------------------------------------\n");
			printf("%-40s %-3s"," [1]Green Tea Frappe","89.0\n");
			printf("%-40s %-3s"," [2]Chinese Tea","59.0\n");
			printf("%-40s %-3s"," [3]Chocolate Drink","79.0\n");
			printf("%-40s %-3s"," [4]Fruit Smoothies","69.0\n");
			printf("%-40s %-3s"," [5]Italian Soda","99.0\n");
			printf("%-40s %-3s"," [6]Lemonade","59.0\n");
			printf("%-40s %-3s"," [7]Soft Drink","39.0\n");
			printf("%-40s %-3s"," [8]Waters","19.0\n");
			printf("------------------------------------------------------------\n");
			printf("Press - to go to previous page ,Press = to go the next page\nPress 0 to stop\n");
			orderD1:{
				printf("Enter the choice: ");
				scanf("%s",order);
				if(strlen(order)==1){
				if(strcmp(order,"0")==0)
					goto orderlist;
				else if(strcmp(order,"1")>=0 && strcmp(order,"8")<=0){
				list(table,order,set);goto orderD1;}
				else if(strcmp(order,"-")==0){
					reorder();goto orderC;}
				else if(strcmp(order,"=")==0){
					reorder();goto orderE;}
				else {
					printf("Invalid choice!\n");
					goto orderD1;}
				}
				else{
					printf("Invalid choice!\n");
					goto orderD1;}
			}
		}	
		orderE:{
			set=4;
			printf("============================================================\n");
			printf("Order food and drink\n");
			printf("============================================================\n");
			printf("\n%-40s %-13s","  Alcoholic Drinks","Price (Baht)\n");
			printf("------------------------------------------------------------\n");
			printf("%-40s %-3s"," [1]Margarita","129.0\n");
			printf("%-40s %-3s"," [2]Martini","139.0\n");
			printf("%-40s %-3s"," [3]French 75","219.0\n");
			printf("%-40s %-3s"," [4]Mint Julep","119.0\n");
			printf("%-40s %-3s"," [5]Vodka On The Rock","209.0\n");
			printf("%-40s %-3s"," [6]Blue Kamikaze","159.0\n");
			printf("%-40s %-3s"," [7]Red Wine","79.0\n");
			printf("%-40s %-3s"," [8]Beer","59.0\n");
			printf("------------------------------------------------------------\n");
			printf("Press - to go to previous page, Press 0 to stop\n");
			orderE1:{
				printf("Enter the choice: ");
				scanf("%s",order);
				if(strlen(order)==1){
				if(strcmp(order,"0")==0)
					goto orderlist;
				else if(strcmp(order,"1")>=0 && strcmp(order,"8")<=0){
					list(table,order,set);goto orderE1;}
				else if(strcmp(order,"-")==0){
					reorder();goto orderD;}
				else {
					printf("Invalid choice!\n");
					goto orderE1;}
				}
				else {
					printf("Invalid choice!\n");
					goto orderE1;}
				
			}
		}	
		orderlist:{
			if(food[table]!=0){
			printf("\nYou have order the following:\n");
			for(int i=0;i<5;i++){
				for(int j=1;j<=8;j++){
					if(temp_list[table][i][j]!=0)
						printf("%s %s x%d\n",food_n[i][0],food_n[i][j],temp_list[table][i][j]);	
				}
			}
			confirmlist:{
				printf("Confirm? (Y|N): ");
				scanf(" %c",&con);
				if(con == 'y' || con == 'Y'){
					foodlist();
					check[table]=1;
					clear();
				}
				else if (con == 'n' || con == 'N')
					clear();		
				else{
					printf("Invalid Input!\n");
					goto confirmlist;} 
			}
		}
			else{
			printf("You have order nothing.");
			getchar();
			while(enter != '\n'){
				enter = getchar();
				}
				start();
			}		
		}
	}
		
void disbill(){
		system("cls");
		enter=0;
		sumbill=0;
		printf("[Display and clear a bill]\n\n");
		printf("List of occupied tables:\n");
		if(oc==0)
			printf("NONE\n");
		else
			for(int i=0;i<10;i++)
				if(stat[i]==1)
				printf("Table %d\n",i+1);
				printf("\nEnter the table number [1-10] (0 to exit): ");
				scanf("%d",&table);
		if(table == 0)
			start();
		if(stat[table-1] == 0){
			printf("There is no one sitting at the table.\nPress Enter to go back to the main menu.");
			getchar();
		while(enter != '\n'){
			enter = getchar();
			}
			start();
		}
		else if(check[table]==0){
			printf("There is no any ordered food or drink.\nPress Enter to go back to the main menu.");
			getchar();
			while(enter != '\n'){
			enter = getchar();
			}
			start();
		}		
		printf("\nYou have order the following:\n\n");
		printf("============================================================\n");
		printf ("%-30s%-10s%-20s\n", "Food Menu", "Qty.", "Price (Baht)");
		printf("============================================================\n");
		if(checkF[table]==1){
			for(int i=0;i<3;i++){
				for(int j=1;j<=8;j++){
					if(f_list[table][i][j]!=0){
						printf("%-30sx%-9d %-10.2f\n",food_n[i][j],f_list[table][i][j],food_c[i][j]*f_list[table][i][j]);	
						sumbill += f_list[table][i][j]*food_c[i][j];}
				}
			}
		}
		else
		printf("None");
		printf("\n\n============================================================\n");
		printf ("%-30s%-10s%-20s\n", "Drink Menu", "Qty.", "Price (Baht)");
		printf("============================================================\n");
		if(checkD[table]==1){
			for(int i=3;i<5;i++){
				for(int j=1;j<=8;j++){
					if(f_list[table][i][j]!=0){
						printf("%-30sx%-9d %-10.2f\n",food_n[i][j],f_list[table][i][j],food_c[i][j]*f_list[table][i][j]);	
						sumbill += f_list[table][i][j]*food_c[i][j];}
				}
			}
		}
		else
		printf("None");
		printf ("\n\n** Total amount : $%.2f\n", sumbill);
		confirmMem:{
			printf("Do you have member card? (Y|N): ");
			scanf(" %c",&con);
			if(con == 'y' || con == 'Y')
				goto member;
			else if(con == 'n' || con == 'N'){
				printf("Do you want to register? (Y|N): ");
				confirmRGS:{
				scanf(" %c",&con);
				if(con == 'y' || con == 'Y'){
					goto regis;}
				else if(con == 'n' || con == 'N'){
					goto bill2;}
				else{
					printf("Invalid Input!");
					goto confirmRGS;}
				}
			}	
			else{
				printf("Invalid Input!\n");
				goto confirmMem;
			}
		}
	member:{
		mem_ch = 0;
		number = -1;
		printf("Input Card ID (7 Digits)or name (Lower characters): ");
		scanf(" %s",mem);
		
		if(strcmp(mem,"0")>=0 && strcmp(mem,"9")<=0){
			if(strlen(mem)!=7){
			printf("Invalid input!\n");
			goto member;
			}
			else{
			for(int i=0;i<mem_c;i++){
				if(strcmp(mem,mem_num[i])==0){
					number = i;break;
					}
				}
			}
		}
		else if(strcmp(mem,"a")>=0 && strcmp(mem,"z")<=0){
			for(int i=0;i<mem_c;i++){
				if(strcmp(mem,mem_name[i])==0){
					number = i;
					mem_ch++;
					}
			}
		}
		
		if(mem_ch>1){
		number = -1;
		printf("Found %d results\n Please input your Card ID: ",mem_ch);
		scanf(" %s",mem);
		for(int i=0;i<mem_c;i++){
			if(strcmp(mem,mem_num[i])==0){
				number = i;break;
				}
			}
		}
		
		if(number == -1){
		printf("============================================================\n");
		printf("Not found in the database\n");
		printf("Do you want to register? (Y|N): ");
		confirmRegis:{
			scanf(" %c",&con);
			if(con == 'y' || con == 'Y'){
				goto regis;}
			else if(con == 'n' || con == 'N'){
				goto bill2;}
			else{
				printf("Invalid Input!");
				goto confirmRegis;}
			}
		}
		else{
		printf("============================================================\n");
		printf("Member Detail:\n");
		printf("============================================================\n");
		printf("Member Name: %s \n",mem_name[number]);
		printf("Card Rank: %s \n",mem_detail[number][0]==1?"Silver":mem_detail[number][0]==2?"Gold":mem_detail[number][0]==3?"Platinum":"Diamond");
		printf("Card Number: %s \n",mem_num[number]);
		printf("You have %d Points\n",mem_detail[number][1]);
		printf("------------------------------------------------------------\n");		
		if((mem_detail[number][0]==1 && mem_detail[number][1]>=200) || (mem_detail[number][0]==2 && mem_detail[number][1]>=300) || (mem_detail[number][0]==3 && mem_detail[number][1]>=400))
			confirmUp:{
			printf("Do you want to upgrade card rank?(Y|N): ");
			scanf(" %c",&con);
			if(con == 'Y' || con == 'y'){
				if(mem_detail[number][0]==1)
					mem_detail[number][1]-=200;
				else if(mem_detail[number][0]==2)
					mem_detail[number][1]-=300;
				else if(mem_detail[number][0]==3)
					mem_detail[number][1]-=400;
				mem_detail[number][0]++;
				printf("Your Card Rank has been upgraded!\n");
			}
			else if(con != 'N' || con != 'n'){
				printf("Invalid Input!");
				goto confirmUp;
				}
			}
		if(mem_detail[number][1]>=500){
			confirmEx:{
			discount = mem_detail[number][0]==1?10:mem_detail[number][0]==2?15:mem_detail[number][0]==3?20:25;
			printf("Do you want to exchange 500 points for %d%% Discounts? (Y|N) ",discount);
			scanf(" %c",&con);
			if(con == 'y' || con == 'Y'){
				mem_detail[number][1]-=500;
				printf("You have remaining %d points",mem_detail[number][1]);
				sleep(3);
				goto bill2;
				}
			else if(con == 'n' || con == 'N'){
				discount = 0;
				sleep(3);
				goto bill2;	}
			else{
				printf("Invalid Input!");
				goto confirmEx;}
			}
		}
		else{
			printf("You don't enough points for exchanging right now.");
			discount =0;
			sleep(3);
			goto bill2;}
		}
	}
	regis:{
		char name[50],num[10];
		printf("Input your name (All lower character): ");
		scanf(" %s",name);
		strcpy(mem_name[mem_c],name);
		printf("Input your ID (7 Digits): ");
		scanf(" %s",num);
		while(strlen(num)!=7){
		printf("Invalid Input!\n");
		printf("Input your ID (7 Digits): ");
		scanf(" %s",num);
		}
		do{
		for(int i=0;i<mem_c;i++){
			number = -1;
			if(strcmp(num,mem_num[i])==0){
				number = i;
				break;
				}
			}
		if(number!=-1){
		printf("This ID already used!\n");
		printf("Input your ID (7 Digits): ");
		scanf(" %s",num);
			}
		}while(number!=-1);
		
		strcpy(mem_num[mem_c],num);
		mem_c++;
		number=mem_c-1;
		mem_detail[number][0]=1;
		printf("Register completed.\n");
		printf("============================================================\n");
		printf("Member Detail[%d]:\n",number);
		printf("============================================================\n");
		printf("Member Name: %s \n",mem_name[number]);
		printf("Card Rank: %s \n",mem_detail[number][0]==1?"Silver":mem_detail[number][0]==2?"Gold":mem_detail[number][0]==3?"Platinum":"Diamond");
		printf("Card Number: %s \n",mem_num[number]);
		printf("You have %d Points\n",mem_detail[number][1]);
		printf("------------------------------------------------------------\n");		
		sleep(3);
		goto bill2;
		}
	bill2:{
		system("cls");
		printf("\nYou have order the following:\n\n");
		printf("============================================================\n");
		printf ("%-30s%-10s%-20s\n", "Food Menu", "Qty.", "Price (Baht)");
		printf("============================================================\n");
		if(checkF[table]==1){
			for(int i=0;i<3;i++){
				for(int j=1;j<=8;j++){
					if(f_list[table][i][j]!=0){
						printf("%-30sx%-9d %-10.2f\n",food_n[i][j],f_list[table][i][j],food_c[i][j]*f_list[table][i][j]);	
						}
				}
			}
		}
		else
		printf("None");
		printf("\n\n============================================================\n");
		printf ("%-30s%-10s%-20s\n", "Drink Menu", "Qty.", "Price (Baht)");
		printf("============================================================\n");
		if(checkD[table]==1){
			for(int i=3;i<5;i++){
				for(int j=1;j<=8;j++){
					if(f_list[table][i][j]!=0){
						printf("%-30sx%-9d %-10.2f\n",food_n[i][j],f_list[table][i][j],food_c[i][j]*f_list[table][i][j]);	
						}
				}
			}
		}
		else
		printf("None");
			if(discount > 0){
			printf("\n\nDiscount %d%% \t\t\t\t-%-10.2f",discount,sumbill*discount/100);
			}
			printf ("\n** Total amount : $%.2f\n", sumbill-sumbill*discount/100);
			printf("\nDo you want to clear the bill? (Y|N): ");
			confirmClear:{
				scanf(" %c",&con);
				if(con == 'y' || con == 'Y'){
					stat[table-1]=0;
					check[table]=0;
					oc--;
					food[table]=0;
					if(number!=-1 && int(sumbill)/100)
					printf("You recieve %d points\n",int(sumbill)/100);
					mem_detail[number][1]+=sumbill/100;
					printf("Thank you please come again!");
					sleep(2);
					redo();}
				else if(con == 'n' || con == 'N'){
					if(discount > 0)
						mem_detail[number][1]+=500;
					start();
					}
				else{
					printf("Invalid Input!\n");
					goto confirmClear;}
			}	
	}
}

int main(){			
	start();
}

void start(){
		system("cls");
		printf("============================================================\n");
		printf("ICT Restaurant System\n");
		printf("============================================================\n");
		printf("[1] Book a table\n[2] Order food & drink\n");
		printf("[3] Display and clear the bill\n[0] Exit\n");
		printf("------------------------------------------------------------\n");
		printf("Enter your choice: ");
		scanf(" %c",&choice);
		switch(choice){
			case '0':
				end();
			case '1':
				book();
			case '2':
				ordering();
			case '3':
				disbill();
			default:
				start();
			}
	}
	
void end(){
		system("cls");
		sleep(1);
		printf("MADE BY\n\nAoravee Donnomprai 6188003\n");
		printf("\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
		sleep(1);
		printf("Chansida Makaranond 6188010\n");
		printf("\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
		sleep(1);
		printf("Natchanon Thanawaree 6188042\n");
		printf("\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
		sleep(2);
		printf("This program is shutting down");
		for(int i=0;i<3;i++){
		printf(".");
		sleep(2);
		}
		system("cls");
		exit(0);
}




