/*
*  service.h
*  contains sever related functions setup
*/

 void services()
 {
    int leftpos=73;
    system("cls");
    window();
    flag_menu=21;
    gotoxy(76,10);printf("SERVICES");
    gotoxy(leftpos,15);printf("1. Add Services ");
    gotoxy(leftpos,18);printf("2. View Services");
    gotoxy(leftpos,21);printf("3. Edit Services");
    gotoxy(leftpos,24);printf("4. Search Services");
    gotoxy(leftpos,27);printf("5. Delete Services");
    gotoxy(leftpos,30);printf("Enter Your Choice:");
    }


 void add_services()
 {
    int leftpos=73;
    system("cls");
    window();
    flag_menu=211;
    int temp_id,i=0;char another='y';
    gotoxy(74,10);printf("ADD SERVICE");
    fp=fopen("save\\service.dat","ab+");
         gotoxy(leftpos,15);printf("Item ID: ");
         gotoxy(leftpos,18);printf("Item Name: ");
         gotoxy(leftpos,21);printf("Item Rate: ");
         gotoxy(leftpos,24);printf("Quantity: ");
         gotoxy(leftpos+9,15);scanf("%d",&temp_id);
         if(check_item_id(temp_id)==0)
         {
            gotoxy(leftpos,30);printf("The Item ID already exists");
            gotoxy(leftpos,31);printf("Try another one");
            getch();
            add_services();
         }
         service1.item_id=temp_id;fflush(stdin);
         gotoxy(leftpos+13,18);gets(service1.item_name);
        gotoxy(leftpos+13,21);scanf("%d",&service1.item_price);
        gotoxy(leftpos+13,24);scanf("%d",&service1.item_qty);
        fseek(fp,-sizeof(service1),SEEK_CUR);
        fwrite(&service1,sizeof(service1),1,fp);
        gotoxy(leftpos,31);printf("The data is successfully saved.");
        fclose(fp);
 }

void view_services()
{
    int leftpos1=40;
    system("cls");
    window();
    flag_menu=212;
    int i=0;
    gotoxy(74,10);printf("VIEW SERVICE");
    fp=fopen("save\\service.dat","rb");
    gotoxy(leftpos1+10,15);printf("Item ID");gotoxy(leftpos1+20,15);printf("Item Name");gotoxy(leftpos1+40,15);printf("Price");gotoxy(leftpos1+60,15);printf("Quantity");
    while(fread(&service1,sizeof(service1),1,fp)==1)
    {
        gotoxy(leftpos1+10,18+i);printf("%d",service1.item_id);
        gotoxy(leftpos1+20,18+i);printf("%s",service1.item_name);
        gotoxy(leftpos1+40,18+i);printf("%d",service1.item_price);
        gotoxy(leftpos1+60,18+i);printf("%d",service1.item_qty);
        i++;
    }
    fclose(fp);
}

void search_services()
{
    int leftpos=73;
    system("cls");
    window();
    flag_menu=214;
    int temp_id ,flag=0;char temp_name[25];
    fp=fopen("save\\service.dat","rb");
    gotoxy(73,10);printf("SEARCH SERVICE");
    gotoxy(leftpos,15);printf("1. Search by ID");
    gotoxy(leftpos,18);printf("2. Search by Name");
    gotoxy(leftpos,21);printf("Enter your choice: ");
    switch(getch())
    {
        case '1':
        {
            system("cls");
            window();
            gotoxy(74,10);printf("SEARCH BY ID");
            gotoxy(leftpos,15);printf("Enter the ID to search:");gotoxy(leftpos+25,15);scanf("%d",&temp_id);
            while(fread(&service1,sizeof(service1),1,fp)==1)
            {
                if(temp_id==service1.item_id)
                {
                    flag=9;
                    gotoxy(leftpos,16);printf("The record is found");
                    gotoxy(leftpos+2,19);printf("Item ID : %d",service1.item_id);
                    gotoxy(leftpos+2,22);printf("Item Name: %s",service1.item_name);
                    gotoxy(leftpos+2,25);printf("Item Price: Rs. %d",service1.item_price);
                    gotoxy(leftpos+2,28);printf("Quantity: %d",service1.item_qty);
                }
            }
       }
            if(flag==0)
            {
                gotoxy(leftpos,16);printf("Sorry!! No record found");

            }

        break;
        case '2':
        {
            system("cls");
            rewind(fp);
            window();
            gotoxy(73,10);printf("SEARCH BY NAME");
            gotoxy(leftpos,15);printf("Enter the Name to search:");fflush(stdin);gets(temp_name);
            while(fread(&service1,sizeof(service1),1,fp)==1)
            {
                  if(strcmp(temp_name,service1.item_name)==0)
                {
                    flag=10;
                    gotoxy(leftpos,16);printf("The record is found");
                    gotoxy(leftpos+2,19);printf("Item ID : %d",service1.item_id);
                    gotoxy(leftpos+2,22);printf("Item Name: %s",service1.item_name);
                    gotoxy(leftpos+2,25);printf("Item Price: Rs. %d",service1.item_price);
                    gotoxy(leftpos+2,28);printf("Quantity: %d",service1.item_qty);
                    }
            }
            if(flag==0)
            {
                    gotoxy(leftpos,16);printf("Sorry!! No record found");
            }
    }
    break;
    default:
        search_services();
            break;
    }
    fclose(fp);
 }

void delete_services()
{
    int leftpos=73;
    system("cls");
    FILE *temp_file;
    int temp_id,flag=0;
    window();
    flag_menu=215;
    gotoxy(73,0);printf("REMOVE SERVICE");
    gotoxy(leftpos,15);printf("Enter the ID to delete: ");gotoxy(leftpos+26,15);scanf("%d",&temp_id);
    fp=fopen("save\\service.dat","rb+");
    while(fread(&service1,sizeof(service1),1,fp)==1)
    {
        if(temp_id==service1.item_id)
        {
            flag=11;
            gotoxy(leftpos,16);printf("The record is found");
            gotoxy(leftpos+2,19);printf("Item ID : %d",service1.item_id);
            gotoxy(leftpos+2,22);printf("Item Name: %s",service1.item_name);
            gotoxy(leftpos+2,25);printf("Item Price= Rs. %d",service1.item_price);
            gotoxy(leftpos+2,28);printf("Quantity: %d",service1.item_qty);
        }
    }
    if(flag==0)
    {
           gotoxy(leftpos,16);printf("Sorry!! No record found");
    }
    if(flag==11)
    {
        gotoxy(leftpos,32);printf("Are You Sure to Delete?(y/n)");
        if(getch()=='y')
        {
            temp_file=fopen("save\\TEMP.dat","wb");
            rewind(fp);
            while(fread(&service1,sizeof(service1),1,fp)==1)
            {
                if(temp_id!=service1.item_id)
                {
                fseek(fp,0,SEEK_END);
                fwrite(&service1,sizeof(service1),1,temp_file);
                }

            }

            fclose(temp_file);
             fclose(fp);
            remove("save\\service.dat");
            rename("save\\TEMP.dat","save\\service.dat");
            fp=fopen("save\\service.dat","rb+");
            gotoxy(leftpos,34);printf("The Item is deleted");
        }
    }
}

int check_item_id(int id)
{
     FILE *item_id_Chk;
    item_id_Chk=fopen("service.dat","rb");
    while(fread(&service1,sizeof(service1),1,item_id_Chk)==1)
    {
        if(id==service1.item_id)
        {
            fclose(item_id_Chk);
            return 0;
        }
    }
    return 1;
}

void edit_services()
{
    int leftpos=73;
    system("cls");
    int temp_id,flag=0,temp_id2;
    fp=fopen("save\\service.dat","rb+");
    window();
    flag_menu=213;
    gotoxy(74,10);printf("EDIT SERVICE");
    gotoxy(leftpos,15);printf("Enter the ID to Modify:");fflush(stdin);scanf("%d",&temp_id);
    while(fread(&service1,sizeof(service1),1,fp)==1)
    {
        if(temp_id==service1.item_id)
        {
            gotoxy(leftpos-1,16);printf("The record is found");
            gotoxy(leftpos,18);printf("Enter new ID:");
            gotoxy(leftpos,20);printf("Enter new Name:");
            gotoxy(leftpos,22);printf("Enter new Price:");
            gotoxy(leftpos,24);printf("Enter new quantity:");
            gotoxy(leftpos+13,18);scanf("%d",&temp_id2);
            if(check_item_id(temp_id2)==0 && temp_id2!=temp_id)
            {
                gotoxy(leftpos,36);printf("The Item ID already exists");
                gotoxy(leftpos,38);printf("Try another one");
                getch();
                edit_services();

            }
            service1.item_id=temp_id2;
            gotoxy(87,20);fflush(stdin);gets(service1.item_name);
            gotoxy(90,22);scanf("%f",&service1.item_price);
            fseek(fp,-sizeof(service1),SEEK_CUR);
            fwrite(&service1,sizeof(service1),1,fp);
            fclose(fp);
            flag=12;
        }
    }
    if(flag==12)
    {
        gotoxy(leftpos,35);printf("The Item is successfully modified");
    }
    if(flag==0)
    {
        gotoxy(leftpos,30);printf("Sorry !! No record found");
        gotoxy(leftpos,31);printf("Press any key....");
    }
}
