#include <stdio.h>
#include <stdlib.h>


int main(){

    char employeeName[4][20];
    char employeeAge[4][20];
    int employeeSalary[4][20];
    int numberOfEmployee,i,j,choice,modifyID,deleteID;
    int numberOfRecords = 0;

    while(1){
        printf("1.Add Records.\n2.Delete Records.\n3.Modify Records.\n4.List Records.\n5.Save Data to File\n6.Read Data From File\n7.Exit\n");
        printf("Enter your choice: ");
        scanf("%d",&choice);

        ////////// add record /////////////
        if(choice==1){
            printf("Enter The Number of Employee: ");
            scanf("%d",&numberOfEmployee);

            for(i=numberOfRecords;i<(numberOfEmployee+numberOfRecords);i++){
                printf("Enter The Name of Employee: ");
                scanf("%s",&employeeName[i]);
                printf("Enter The Age of Employee: ");
                scanf("%s",&employeeAge[i]);
                printf("Enter The Salary of Employee: ");
                scanf("%s",&employeeSalary[i]);
            }
            numberOfEmployee = numberOfEmployee+numberOfRecords;
            numberOfRecords = i;
            i=0;

        }

        ////////// delete record /////////////
        if(choice==2){
            printf("Enter The Record of Employee To Be Deleted: ");
            scanf("%d",&deleteID);

            for(j=deleteID-1;j<numberOfEmployee;j++){
                //employeeName[j] = employeeName[j+1];
                //employeeAge[j] = employeeAge[j+1];
                //employeeSalary[j] = employeeSalary[j+1];
            }
        }

        ////////// modify record /////////////
        if(choice==3){
            printf("Enter The Record of Employee To Be Modigfied: ");
            scanf("%d",&modifyID);

            printf("Enter The Name of Employee: ");
            scanf("%s",&employeeName[modifyID]);
            printf("Enter The Age of Employee: ");
            scanf("%s",&employeeAge[modifyID]);
            printf("Enter The Salary of Employee: ");
            scanf("%s",&employeeSalary[modifyID]);

        }


        ////////// view record /////////////
        if(choice==4){
            for(i=0;i<numberOfEmployee;i++){
                printf("Record No. %d\n",i);
                printf("%s\t",employeeName[i]);
                printf("%s\t",employeeAge[i]);
                printf("%s\t",employeeSalary[i]);
                printf("\n");

            }
        }

        ////////// write record to file /////////////
        if(choice==5){

            FILE *f = fopen("file.txt", "w");
            if (f == NULL)
            {
                printf("Error opening file!\n");
                exit(1);
            }

            for(i=0;i<numberOfEmployee;i++){
                fprintf(f,"Record No. %d\n",i);
                fprintf(f,"%s\t",employeeName[i]);
                fprintf(f,"%s\t",employeeAge[i]);
                fprintf(f,"%s\t",employeeSalary[i]);
                fprintf(f,"\n");

            }
            fclose(f);

        }

////////// read record to file /////////////
        if(choice==6){

            FILE *f;
            char s[1000];
            f=fopen("file.txt","r");
            if (!f) return 1;
            while (fgets(s,1000,f)!=NULL)
                printf("%s",s);
            fclose(f);

        }

////////// exit /////////////
        if(choice==7){
            exit(1);
        }
    }

}
