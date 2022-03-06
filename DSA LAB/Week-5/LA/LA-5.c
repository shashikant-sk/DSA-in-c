// Two brackets are considered to be a matched pair if the an opening bracket (i.e., (, [, or { ) occurs to the left of a closing bracket 
// (i.e., ), ], or }) of the exact same type. There are three types of matched pairs of brackets: [], {}, and (). 
// A matching pair of brackets is not balanced if the set of brackets it encloses are not matched. 
// WAP to determine whether the input sequence of brackets is balanced or not. If a string is balanced, 
// it print YES on a new line; otherwise, print NO on a new line. 
// Example: Input: {[()]} and Output: YES
// Input: {[(])} and Output: NO
#include<stdio.h>

char stack[100];
int top = -1;

void isValid(char* e){
    while(*e != '\0'){
        if(*e=='(' || *e=='{' || *e=='[')stack[++top] = *e;
        else if((stack[top]=='('&&*e==')') || (stack[top]=='{'&&*e=='}') || (stack[top]=='['&&*e==']'))top--;
        else {printf("NO\n");return;}
        if(top==-1){printf("YES\n");return;}
        else e++;
    }
}

int main(){
    char input[100],*e;
    printf("Enter the bracket expression: ");
    scanf("%s",input);
    e=input;
    isValid(e);
    return 0;
}
