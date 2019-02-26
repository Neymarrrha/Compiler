#include "data.h"

FILE * fin;
Token lookahead;
//BiTree first;

//关键字表
char Keyword[20][10] = { "begin", "as", "sub", "end", "if", "then", "else", "call", "while",
    "do", "integer", "float", "input", "output", "var" };

//bool运算符
char Boolop[2][5] = { "and", "or" };

int main()
{
    
    char fileName[256]="/Users/mac/Desktop/Html/YYYYYUfa/YYYYYUfa/aaa.txt";
    
    ////printf("请输入源程序文件名（包括路径）：");
    //gets(fileName);
    
    if ((fin=fopen(fileName, "r"))==NULL)
    {
        printf("打开源程序文件出错!\n");
        return 0;
    }
    
    
    
    
    /*
     // 以下是测试代码，检查是否能依次正确输出源文件中的所有单词
     do
     {
     getToken();
     
     if(lookahead.type==ID)
     printf("%s\n",lookahead.p);
     else if(lookahead.type==INTC)
     printf("%d\n",lookahead.val);
     else if(lookahead.type==LP)
     printf("(\n");
     else if(lookahead.type==RP)
     printf(")\n");
     else if(lookahead.type==PLUS)
     printf("+\n");
     else if(lookahead.type==MINUS)
     printf("-\n");
     else if(lookahead.type==MUL)
     printf("*\n");
     else if(lookahead.type==DIV)
     printf("/\n");
     else if(lookahead.type==ERR)
     printf("err: %s\n",lookahead.p);
     
     
     }while(lookahead.type!=END);
    
     
    */
    
    
    getToken();
    //BiTNode* t=express();
    
    
    
    //judge();
    expression();   //文法起始符号对应的识别函数, 语法分析程序的起始入口
    cout<<"分析成功！"<<endl;
    return 0;
}

