#include "data.h"
/*
extern FILE * fin;
extern char token[256];
extern int col, row;
int prerow, precol;  //出错前的行号、列号
 */
//关键字表
extern char Keyword[20][10];
//bool运算符
extern char Boolop[2][5];


bool isdigit(char ch)
{
    return '0' <= ch && ch <= '9' ;
}

bool isalpha(char ch)
{
    return ('a' <= ch && ch<= 'z')|| ('A' <= ch && ch <= 'Z');
}
/*

int iskeyword(char ch[]){
    for (int i=0; i<20; i++) {
        if (strcmp(ch, Keyword[i])==0) {
            return i+begin;
        }
    }
    return -2;
}

int isboolop(char ch[]){
    for (int i=0; i<2; i++) {
        if (strcmp(ch, Boolop[i])==0) {
            return i+andd;
        }
        
    }
    return -2;
}

*/
// getToken每次调用从源文件中依次读取下一个单词，保存到全局变量lookahead
void getToken()
{
    char ch;
    char token[1000];
    
    ch=getc(fin);
    
    while (ch == ' ' || ch == '\n' || ch == '\t') ch = getc(fin);  //跳过所有的空格和分隔符
    
    
    if (isalpha(ch))   //如果是字母，则进行标识符处理
    {
        int j = 0;
        token[j++] = ch;
        ch = getc(fin);
        while (isalpha(ch))  //如果是字母则组合标识符；如果不是则标识符组合结束
        {
            token[j++] = ch; //组合的标识符保存在token中
            ch = getc(fin);  //读下一个字符
        }
        token[j] = '\0';     //标识符组合结束
        
        lookahead.type=ID;
        strcpy(lookahead.p, token);
        
        if(ch!=EOF) fseek(fin, -1, 1);   ////当前不是文件尾，回退一个字符
    }
    else if (isdigit(ch))//数字处理
    {
        int j = 0;
        token[j++] = ch;
        ch = getc(fin);  //读下一个字符
        while (isdigit(ch))  //如果是数字则组合整数；如果不是则整数组合结束
        {
            token[j++] = ch;  //组合整数保存在token中
            ch = getc(fin);  //读下一个字符
        }
        token[j] = '\0';  //整数组合结束
        
        lookahead.type=INTC;
        lookahead.val=atoi(token);
        strcpy(lookahead.p, token);
        
        if (ch != EOF) fseek(fin, -1, 1);   //回退一个字符
    }
    
    else if (ch=='+')
        lookahead.type=PLUS;
    else if (ch == '-')
        lookahead.type=MINUS;
    else if (ch == '*')
        lookahead.type=MUL;
    else if (ch == '/')
        lookahead.type=DIV;
    else if (ch == '(')
        lookahead.type= LP;
    else if (ch == ')')
        lookahead.type= RP;
    else
    {
        if(ch == EOF)
            lookahead.type =END;  
        else{
            lookahead.p[0]=ch;
            lookahead.p[1]='\0';
            lookahead.type =ERR;
        }
    }
    
}


