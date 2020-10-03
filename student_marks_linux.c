#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
int percentage(int x,int y);
int pass(int x);

void main(){
    char name[100];
    int marks,i,num,sub,j,tot=0,enter_full_marks;

    printf("enter number of students : ");
    scanf("%d",&num);

    printf("\nenter no.of subjects : ");
    scanf("%d",&sub);

    printf("\n enter the total marks of a subject :");
    scanf("%d",&enter_full_marks);
    FILE *fptr;
    fptr =(fopen("student.txt","w"));
    //if file has not created 

    if(fptr == NULL){
        printf("error!");
        exit(1);
    }

    for ( i = 0; i < num; ++i)
    {
       
        printf("\n for students%d \n enter the student name : ",i+1);
        scanf("%s",name);

        fprintf(fptr,"\n name: %s ",name);
        int failedSubjects = 0;
        for(j=1; j <=sub; j++){

            printf("enter the marks of subject %d: ",j);
            scanf("%d",&marks);
                int PassOfSubject = pass(enter_full_marks);//you will get the pass percentage 
                //checks that the student has passed the subjects or not 
                if (marks < PassOfSubject){

                    failedSubjects = failedSubjects + 1;
                }
                //if the student entered more than full marks then it will give error 
                if(marks > enter_full_marks){
                    printf("error!\n");
                    sleep(0.5);
                    printf("error!\n");
                    sleep(0.5);
                    printf("error!\n");
                    sleep(0.5);
                    printf("error!\n");
                    sleep(0.5);

                    printf("\n **********************you have entered more than  %d marks******************* \n",enter_full_marks);
                    sleep(2);
                    printf("\nthe program has exit !");
                    sleep(1);
                    printf("\n please try again ");
                    exit(1);
                }
            fprintf(fptr,"\n marks of subject %d : %d",j,marks);

            tot = tot + marks;//total marks of all subjects 
            
        }
        int full_marks = enter_full_marks * sub;//total full marks of all subject
        double percen = percentage(tot,full_marks);//it is a function
        fprintf(fptr,"\n total marks of the student is : %d / %d",tot,full_marks);

       
        fprintf(fptr,"\n the percentage is : %.2lf%%",percen);
        if(percen < 35.00 && failedSubjects > 0){
            
            fprintf(fptr,"\n the student have failed in %d subjects",failedSubjects);

        }
        else if(percen > 35.00 && failedSubjects > 0){
                fprintf(fptr,"\nthe student have failed in %d subjects",failedSubjects);
        }
        else{
            fprintf(fptr,"\n the student has passed!");
        }
        //for reset the values
        failedSubjects = 0;
        tot = 0;
        fprintf(fptr,"\n*********************************\n");
    }
    //after the progarm end 
    printf("loading.... ");
    sleep(3);
    printf("\n the file has created as students.txt\n \n");
    printf("all the information will be in it ");
    sleep(3);
    printf("\n \n \n \n thanks for using our code \n \n \n ");

    fclose(fptr);

}
int percentage(int x,int y){
    int per = (float)x / (float)y * 100.0;
    return(per);
}
// taking 35% of the total full marks
int pass(int x){
    
    int y = x * 35 /100;
    
    return(y);
}

