#include<ctype.h>
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
struct Treenode{
 char data;
 struct Treenode *left;
 struct Treenode *right;
};
struct Treenode *createNode(char val)
{
 struct Treenode *newNode=(struct Treenode *)malloc(sizeof(struct Treenode));
 newNode->data=val;
 newNode->left=NULL;
 newNode->right=NULL;
 return newNode;
}
int isOperator(char c)
{
 if ( (c=='+') || (c=='-') || (c=='*') || (c=='/') || (c=='$') )
 return 1;
 return 0;
}
struct Treenode *ExpressionTree(char postfix[])
{
 struct Treenode *stack[50];
 int top=-1,i;
 for(i=0;postfix[i]!='\0';i++)
 {
 struct Treenode *newNode=createNode(postfix[i]);
 if(isdigit(postfix[i]))
 {
 stack[++top]= newNode;
 }
 else if(isOperator(postfix[i]))
 {
 newNode->right=stack[top--];
 newNode->left=stack[top--];
 stack[++top]=newNode;
 }
 }
 return stack[top];
}
void inorder(struct Treenode *r)
{
 if(r!=NULL)
 {
 inorder(r->left);
 printf("%c",r->data);
 inorder(r->right);
 }
}
int evaluateTree(struct Treenode *root)
{
 if(root->data=='+')
 {
 return evaluateTree(root->left)+evaluateTree(root->right);
 }
 else if(root->data=='-')
 {
 return evaluateTree(root->left)-evaluateTree(root->right);
 }
 else if(root->data=='*')
 {
 return evaluateTree(root->left)*evaluateTree(root->right);
 }
 else if(root->data=='/')
 {
 return evaluateTree(root->left)/evaluateTree(root->right);
 }
 else if(root->data=='$')
 {
 return pow(evaluateTree(root->left),evaluateTree(root->right));
 }
 else
 {
 return root->data-'0';
 }
}
void freeExpressionTree(struct Treenode *root)
{
 if(root!=NULL)
 {
 freeExpressionTree(root->left);
 freeExpressionTree(root->right);
 free(root);
 }
}
main()
{
 char postfix[50];
 printf("enter a postfix expression:\n");
 scanf("%s",postfix);
 struct Treenode *root=ExpressionTree(postfix);
 printf("In order Traversal of the given expression is:\n");
 inorder(root);
 printf("\n");
 int result=evaluateTree(root);
 printf("Result of given postfix expression is:%d\n",result);
 freeExpressionTree(root);
 return 0;
}
