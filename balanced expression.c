//stack->parenthesis//
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define MAX 50


int stack[MAX];                                                 //globally creating stack
int top=-1;                                                     //globally initializing top=-1

void push(char);                                                //function declarations
char pop();
int match(char a,char b);
int check(char[]);

int main(){                                                     //main function
        char exp[MAX];
        int valid;
        printf("Enter the expression:");
        gets(exp);
        valid=check(exp);                                       //function call to check if open parantheses have their closing parantheses
        if(valid==1)
                printf("Valid expression\n");
        else
                printf("Invalid expression\n");

        return 0;
}
int check(char exp[]){
        int i;
        char temp;
        for(i=0;i<strlen(exp);i++){
                if(exp[i]=='(' || exp[i]=='{'  ||  exp[i]=='[')
                        push(exp[i]);                                                   //push fn call to push open bracket to the stack
                if(exp[i]==')' || exp[i]=='}'  ||  exp[i]==']')
                if(top==-1){
                        printf("Right paranteses are more than left parentheses\n");
                       return 0;
                }
                else{
                        temp=pop();                                             //pop fn call to pop the last pushed element from the stack
                        if(!match(temp,exp[i])){                                //match fn call to
                                printf("Mismatched parentheses are:");
                                printf("%c and %c\n",temp,exp[i]);
                           	return 0;
                        }
                }
        }

        if(top==-1){
                printf("Balanced Parentheses\n");
                return 1;
        }
        else{
                printf("Left parentheses are more than right parentheses\n");
                return 0;
        }
}
int match(char a,char b){                                                       //fn defn to check similar braces
        if(a=='[' && b==']')
                return 1;
        if(a=='{' && b=='}')
                return 1;
        if(a=='(' && b==')')
                return 1;
        return 0;
}
void push(char item){                                                           //push function
        if(top==(MAX-1))
        {
                printf("Stack Overflow\n");
                return;
        }
        stack[++top]=item;
}

char pop(){                                                                     //pop function
        if(top==-1)
        {
                printf("Stack Underflow\n");
                exit(1);
        }
        return(stack[top--]);
}
