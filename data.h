#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<iostream>
#include<vector>


#define INTC    1
#define ID      2
#define LP      3
#define RP      4
#define PLUS    5
#define MINUS   6
#define MUL     7
#define DIV     8
#define andd						17   //bool运算符and
#define orr						18   //bool运算符or

#define END     0
#define ERR    -1


//define keyword 保留字
#define begin					30
#define as						31
#define sub						32
#define end						33
#define IF						34
#define THEN					35
#define ELSE					36
#define call					37
#define WHILE					38
#define DO						39
#define INTEGER					40
#define FLOAT					41
#define input					42
#define output					43
#define var						44
#define FUN						45

using namespace std;

void getToken();
void expression();
void lrparser();
void judge();

struct Token
{
    int val;       //如果单词是整数,val保存该整数之值
    char p[256];   //如果单词是变量,p保存变量名
    int type;      //单词类型:  1:整数 INTC   2:变量 ID   3:(  LP  4:) RP 5:+ PLUS 6: - MINUS  7:*  MUL  8: /  DIV  -1:错误  ERR  0: 输入结束  END
};
extern FILE * fin;
extern Token lookahead;



/*
typedef struct BiTNode
{
    Token data;
    struct BiTNode *lchild,*rchild;
}
BiTNode,*BiTree;//定义结点类型
BiTree CreateBiTree()//创建树
{
    BiTree T;

    if(lookahead.type==END)
        T=NULL;
    else
    {
        T=(BiTNode *)malloc(sizeof(BiTNode));//为结点开辟空间
        T->data=lookahead;

    }
    return (T);
}
 
BiTNode * express();
 */
