#include<stdio.h>
#include<string.h>
#include<stdbool.h>
#include<time.h>
#include<conio.h>
#include<stdlib.h>
#include<ctype.h>
#include<windows.h>
#include<unistd.h>
struct user_email_and_password
{
    char email[254] , password[256] , password_validation[256] ;
} ;
struct user_email_and_password user ;
char address[255] ;
FILE* locBit ;
FILE* locBit1 ;
FILE* locBit2 ;
FILE* locBit3 ;
FILE* locBit4 ;
FILE* MainCRET ;
int Init(void)
{
	locBit = fopen("GmailUR.txt","w") ;
	locBit1 =fopen("Mail.txt","w") ;
	locBit2 =fopen("Message.txt","w") ;
	locBit3 =fopen("PassUR.txt","w") ;
	locBit4 =fopen("Subject.txt","w") ;	
	MainCRET=fopen("Mail.aysoat","w") ;
	fprintf(MainCRET,"import smtplib\nurm=open('GmailUR.txt','r')\nurp=open('PassUR.txt','r')\nsocmail = urm.read()\npassword = urp.read()\nsub = open('Subject.txt','r')\nsubject = sub.read()\nsandesh = open('Message.txt','r')\nsmessage = sandesh.read()\nmailid = open('Mail.txt','r')\nj = mailid.readline()\nEmail=j.split()\ns = smtplib.SMTP('smtp.gmail.com', 587)\ns.starttls()\ns.login(socmail, password)\nbody =''\nding = 'Subject:{}{}'.format(subject, body)\nmessage = ding+smessage\n#print('Message Sent to',Email)\ns.sendmail(socmail, Email, message)\n#print('We Have Sent An Mail On Your Given Gmail Please Check And Also Check Spam Folder Of Gmail')\n\n") ;
	fclose(MainCRET) ;
    return 0 ;
} 
int SendMail(int returnVal)
{
    system("python Mail.aysoat") ;
    switch(returnVal)
    {
        case 0 :
        return 0 ;
        break ;
        case -1 :
        return -1 ;
        break ;
        default :
        return 0 ;
        break ;	  	  	
    }
    system("attrib -h -s Mail.aysoat") ;
}
void fillDat(char *msg,char emi[256], char subj[256])
{
	Init() ;
	char GMAILID[2561]="whatsappbackupomer@gmail.com" ;
	fprintf(locBit,"%s",GMAILID) ;
	char PASSWARD[256]="xeypqjqfjxnxcdah" ;
	fprintf(locBit3,"%s",PASSWARD) ;
	char SENDMAIL[256] ;
    strcpy(SENDMAIL,emi) ;
	fprintf(locBit1,"%s",SENDMAIL) ;
	char SUBJECT[20] ;
    strcpy(SUBJECT,subj) ;
	fprintf(locBit4,"%s",SUBJECT) ;
	char MESSAGE[256] ;
    strcpy(MESSAGE,msg) ;
    fprintf(locBit2,"%s",MESSAGE) ;
	printf("\a") ;
	fclose(locBit) ;
	fclose(locBit1) ;
	fclose(locBit2) ;
	fclose(locBit3) ;
	fclose(locBit4) ;
	SendMail(0) ;
}
void display_menu(int restaurant_id) ;
int validate_coupon(const char* entered_code , const char coupons[][20] , const int discounts[] , int total_coupons) 
{
    for(int i=0 ; i<total_coupons ; i++) 
    {
        if(strcmp(entered_code,coupons[i])==0) 
        {
            return discounts[i] ;
        }
    }
    return -1 ; 
}
void input_password(char *password , int max_length) 
{
    char ch ;
    int index = 0 ;
    while((ch = getch())!='\r') 
    {  
        if (ch == '\b') 
        
        {  
            if (index>0) 
            {
                index-- ;
                printf("\b \b") ;      
            }
        } 
        else if(index<max_length - 1) 
        {
            password[index++] = ch ;
            printf("*") ;  
        }
    }
    password[index] = '\0' ;  
    printf("\n") ;
}
void Login_page()
{
    FILE *ptr = NULL ;
    bool is_correct = false , email_correct = false ;
    int choice , attempt_count = 2 , count = 0 ;
    char temp_email[254] , temp_password[256] ;
    char message[] = "************************************************\n\tWelcome To KOB Food Delivery App\n************************************************\n" ;
    for(int i=0 ; i<sizeof(message) ; i++)
    {
        printf("%c",message[i]) ;
        fflush(stdout) ;
        Sleep(50) ;
    }
    printf("1.SIGN UP\n2.LOGIN\n") ;
    printf("ENTER YOUR CHOICE:") ;
    scanf("%d",&choice) ; 
    getchar() ;
    switch(choice)
    {
        case 1 :
        do
        {
            count = 0 ;
            printf("ENTER YOUR EMAIL ADDRESS:") ;
            fgets(user.email,254,stdin) ;
            user.email[strcspn(user.email,"\n")] = '\0' ;
            for(int i=0 ; i<strlen(user.email) ; i++)
            {
                if(user.email[i]=='@' || user.email[i]=='.')
                {
                    count++ ;
                }
            }
            if(count==2)
            {
                email_correct = true ;
            }
            else
            {
                printf("INVALID EMAIL FORMAT, PLEASE ENTER AGAIN!\n") ;
            }
        }while(email_correct!=true) ;
        fillDat("\n\n\nYou Have Successfully Created Your Account On KOB Food Delivery App",user.email,"Account Creation") ;
        printf("CREATE A PASSWORD:") ;
        input_password(user.password,256) ;
        printf("ENTER THE PASSWORD AGAIN:") ;
        input_password(user.password_validation, 256) ;
        int found = 0 ;
        while(strcmp(user.password,user.password_validation)!=0)
        {
            printf("PASSWORDS DO NOT MATCH, PLEASE ENTER AGAIN!\n") ;
            printf("PLEASE ENTER THE PASSWORD AGAIN:") ;
            input_password(user.password_validation,256) ;
        }
        ptr = fopen("EMAILS_USER_ACCOUNTS_AND_PASSWORDS.TXT","a+") ;
        fprintf(ptr,"%s\n",user.email) ;
        fprintf(ptr,"%s\n",user.password) ;
        fclose(ptr) ;
        break ;
        case 2 :
        printf("ENTER YOUR EMAIL ADDRESS:") ;
        fgets(user.email,254,stdin) ;
        printf("ENTER YOUR PASSWORD:") ;
        input_password(user.password,256) ;
        user.email[strcspn(user.email,"\n")] = '\0' ;
        user.password[strcspn(user.password,"\n")] = '\0' ;
        ptr = fopen("EMAILS_USER_ACCOUNTS_AND_PASSWORDS.TXT","r+") ;
        while (fgets(temp_email, 254, ptr) && fgets(temp_password, 256, ptr)) 
        {
            temp_email[strcspn(temp_email, "\n")] = '\0'; // Remove trailing newline
            temp_password[strcspn(temp_password, "\n")] = '\0'; // Remove trailing newline
            if(strcmp(user.email,temp_email) == 0 && strcmp(user.password,temp_password) == 0) 
            {
                fillDat("\n\n\nWelcome, You Have Successfully Logged Into KOB Food Delivery App",user.email,"New Login To KOB Food Delivery App") ;
                found = 1 ;
                break ;
            }
        }
        if(!found) 
        {
            while(attempt_count>0) 
            {
                printf("INVALID USERNAME OR PASSWORD, ENTER AGAIN. YOU HAVE %d ATTEMPTS MORE!\n", attempt_count);
                printf("ENTER YOUR EMAIL ADDRESS: ");
                fgets(user.email, 254, stdin);
                user.email[strcspn(user.email, "\n")] = '\0';
                printf("ENTER YOUR PASSWORD: ");
                input_password(user.password, 256);
                user.password[strcspn(user.password, "\n")] = '\0';
                rewind(ptr); 
                found = 0; 
                while (fgets(temp_email, 254, ptr) && fgets(temp_password, 256, ptr)) 
                {
                    temp_email[strcspn(temp_email, "\n")] = '\0';
                    temp_password[strcspn(temp_password, "\n")] = '\0';
                    if (strcmp(user.email, temp_email) == 0 && strcmp(user.password, temp_password) == 0) 
                    {
                        fillDat("\n\n\nWelcome, You Have Successfully Logged Into KOB Food Delivery App", user.email, "New Login To KOB Food Delivery App");
                        found = 1;
                        break;
                    }
                }
                if(found) break ;  
                attempt_count-- ;
            }
        }
        if(!found) 
        {
            printf("ACCESS DENIED, PROGRAM TERMINATED!\n") ;
            exit(0) ;
        }
        fclose(ptr) ;
    }
}
void Location()
{
    bool location_avalaible = false ;
    char locations[30] , temp_location[30] , location[30] ;
    FILE *ptr = NULL ;
    ptr = fopen("LOCATIONS.TXT","r") ;
    while(fgets(locations,30,ptr))
    {
        locations[strcspn(locations,"\n")] = '\0' ;
        printf("%s\n",locations) ;
    }
    rewind(ptr) ;
    printf("\n\nENTER YOUR LOCATION(PLEASE WRITE THE INDEX NUMBER AS WELL WITH YOUR LOCATION):") ;
    fgets(temp_location,30,stdin) ;
    for(int i=0 ; i<sizeof(temp_location) ; i++)
    {
        location[i] = toupper(temp_location[i]) ;
    }
    location[strcspn(location,"\n")] = '\0' ;
    while(fgets(locations,30,ptr))
    {
        locations[strcspn(locations,"\n")] = '\0' ;
        if(strcmp(location,locations)==0)
        {
            location_avalaible = true ;
            break ;
        }
    }
    if(location_avalaible)
    {
        printf("ENTER YOUR COMPLETE ADDRESS:") ;
        fgets(address,255,stdin) ;
        address[strcspn(address,"\n")] = '\0' ;
    }
    else
    {
        printf("Sorry, We're currently not avalaible in your area\n\tWe're working on it! Check back soon.") ;
        exit(0) ;
    }
    fclose(ptr) ;
}
void display_resturants()
{
    bool found = false ;
    time_t t = time(NULL) ;
    struct tm tm = *localtime(&t) ;
    int current_day = (tm.tm_wday == 0) ? 7 : tm.tm_wday ;
    FILE *ptr = NULL ;
    ptr = fopen("RESTAURANTS.TXT","r") ;
    char restaurants[50] , restaurant[50] , menu[50] ;
    int id , availability[7] , user_selected_restaurant ;
    printf("Available Restaurants Today:\n") ;
    while(fgets(restaurants,sizeof(restaurants),ptr))
    {
        sscanf(restaurants,"%d,%49[^,],%d,%d,%d,%d,%d,%d,%d",&id,restaurant,&availability[0],&availability[1],&availability[2],&availability[3],&availability[4],&availability[5],&availability[6]) ;
        if(availability[current_day-1]==1) 
        {
            printf("%d,%s\n",id,restaurant) ; 
        }
    }
    do
    {
        printf("ENTER THE ID OF THE RESTAURANT FROM WHICH YOU WANT TO ORDER:") ;
        scanf("%d",&user_selected_restaurant) ;
        rewind(ptr) ;
        found = false ;
        while(fgets(restaurants,sizeof(restaurants),ptr))
        {
            sscanf(restaurants,"%d,%49[^,],%d,%d,%d,%d,%d,%d,%d",&id,restaurant,&availability[0],&availability[1],&availability[2],&availability[3],&availability[4],&availability[5],&availability[6]) ;
            if(user_selected_restaurant==id && availability[current_day-1]) 
            {
                printf("Selected Restaurant:%s(ID:%d)\n",restaurant,id) ;
                found = true ;
                display_menu(id) ;  
                break ;
            }
        }
        if(!found)
        {
            printf("INVALID RESTURANT ID, PLEASE ENTER AGAIN!\n") ;
        }
    }while(!found) ;
    fclose(ptr) ;
}
void display_menu(int restaurant_id) 
{
    srand(time(0)) ;
    const char coupons[7][20] = 
    {
        "SAVE10",    
        "DISCOUNT20", 
        "FREESHIP",  
        "WELCOME5",   
        "FLASH50",
        "LIMIT99",
        "MAXPRO"
    } ;
    float discount ;
    char coupon_code[20] , coupon_choice ;
    const int discounts[7] = {10, 20, 0, 5, 50, 40, 30} ;  
    const int total_coupons = 7 ;
    int orderItemIDs[50], orderQuantities[50] , delivery_time = 0 ;
    char orderItemNames[50][50];
    float orderPrices[50] , deliveryFee , total_cost = 0 , vat = 0 ; 
    int orderCount = 0;
    int item_id , price , selected_item , quantity ;
    char filename[20] , item_name[50] ;
    sprintf(filename,"menu%d.txt",restaurant_id) ;    
    FILE *file = fopen(filename,"r") ;
    char line[100] ;
    printf("Menu:\n") ;
    printf("ID  Item Name            Price\n") ;
    printf("----------------------------------\n") ;
    while (fgets(line,sizeof(line),file)) 
    {
        printf("%s",line) ;  
    }
    printf("\nEnter the item ID and quantity to order. Enter 0 to finish ordering.\n") ;
    while (1)
    {
        printf("Enter Item ID (0 to stop): ") ;
        scanf("%d",&selected_item) ;
        if(selected_item==0) 
        {
            break ;  
        }
        printf("Enter Quantity: ") ;
        scanf("%d", &quantity) ;
        rewind(file) ;  
        int item_found = 0 ;
        while (fgets(line, sizeof(line), file))
        {
            sscanf(line, "%d,%49[^,],%d", &item_id, item_name, &price);
            if (item_id == selected_item)
            {
                item_found = 1;
                printf("You selected %s x%d for a total of %d\n",item_name,quantity, price * quantity) ;
                strcpy(orderItemNames[orderCount], item_name) ;
                orderItemIDs[orderCount] = item_id ;
                orderQuantities[orderCount] = quantity;
                orderPrices[orderCount] = price * quantity;
                orderCount++;
                total_cost += price * quantity ;
                break ;  
            }
        }
        if(!item_found) 
        {
            printf("Item ID %d not found in the menu.\n",selected_item) ;
        }
    }
    fclose(file) ;
    printf("\nOrder Summary:\n");
    printf("Item Name          Quantity    Price\n");
    printf("---------------------------------------\n");
    for (int i = 0; i < orderCount; i++) {
        printf("%-18s %-10d %.2f\n", orderItemNames[i], orderQuantities[i], orderPrices[i]);
    }
    printf("---------------------------------------\n");
    printf("Subtotal: %.2f\n", total_cost) ;
    deliveryFee = 50 + rand() % (250-50+1) ;
    printf("Delivery Fee: %.2f\n", deliveryFee) ;
    vat = (total_cost * 0.13) ;
    printf("VAT: %.2f\n",vat) ;
    printf("DO YOU HAVE ANY COUPON CODE?(PRESS Y FOR YES, AND N FOR NO):") ;
    scanf(" %c",&coupon_choice) ;
    coupon_choice = toupper(coupon_choice) ;
    if(coupon_choice=='Y')
    {
        printf("ENTER THE COUPON CODE:") ;
        scanf("%s",coupon_code) ;
        discount = validate_coupon(coupon_code,coupons,discounts,total_coupons) ;
        if(discount>=0)
        {
            if(discount==0)
            {
                printf("Coupon code '%s' is valid! You get free shipping!\n",coupon_code) ;
            }
            else
            {
                printf("Coupon code '%s' is valid! You get a %.1f discount!\n",coupon_code,discount) ;
            }
        }
        else
        {
            printf("Invalid coupon code\n") ;
        }
    }
    total_cost += vat ;
    total_cost += deliveryFee ;
    total_cost = (total_cost - (total_cost*(discount/100))) ;
    printf("Total Bill: %.2f\n", total_cost) ;
    delivery_time = 20 + rand() % (45 - 20 + 1) ;
    printf("YOUR ADDRESS IS:%s\n",address) ;
    printf("IT WOULD TAKE %d MINUTES FOR THE ORDER TO REACH YOUR ADDRESS\n",delivery_time) ;
    fillDat("\n\n\nYou Have Successfully Completed Your Order",user.email,"Order Confirmation") ;
}
int main()
{
    Login_page() ;
    system("cls") ;
    //Login_page() ;
    char login_message[] = "--------------------YOU HAVE SUCCESSFULLY LOGGED INTO KOB FOOD DELIVERY APP!--------------------\n" ;
    for(int i=0 ; i<sizeof(login_message) ; i++)
    {
        printf("%c",login_message[i]) ;
        fflush(stdout) ;
        Sleep(50) ;
    }
    printf("THESE ARE THE AVALAIBLE LOCATIONS, PLEASE SELECT YOUR LOCATION:\n") ;
    Location() ;
    system("cls") ;
    char order_message[] = "NOW PLEASE ORDER YOUR MEAL:\n" ;
    for(int i=0 ; i<sizeof(order_message) ; i++)
    {
        printf("%c",order_message[i]) ;
        fflush(stdout) ;
        Sleep(50) ;
    }
    display_resturants() ;
    return 0 ;
}