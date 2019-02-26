#include "data.h"
extern Token lookahead;
extern char Keyword[20][10];

char* err_msg[] =
{
    /*  0 */    "",
    /*  1 */    "缺少：function，或function拼写错误！",
    /*  2 */    "缺少：begin，或begin拼写错误！",
    /*  3 */    "缺少：end，或end拼写错误！",
    /*  4 */    "缺少：integer，或integer拼写错误！",
    /*  5 */    "缺少：if，或if拼写错误！",
    /*  6 */    "缺少：then，或then拼写错误！",
    /*  7 */    "缺少：else，或else拼写错误！",
    /*  8 */    "缺少：and，或and拼写错误！",
    /*  9 */    "缺少：or，或or拼写错误！",
    /* 10 */    "缺少：标识符，或标识符拼写错误！",
    /* 11 */    "缺少：整数，或整数拼写错误！",
    /* 12 */    "缺少：+，或+拼写错误！",
    /* 13 */    "缺少：-，或-拼写错误！",
    /* 14 */    "缺少：*，或*拼写错误！",
    /* 15 */    "缺少：/，或/拼写错误！",
    /* 16 */    "缺少：(，或(拼写错误！",
    /* 17 */    "缺少：)，)写错误！",
    /* 18 */    "缺少：=，或=拼写错误！",
    /* 19 */    "缺少：，或，拼写错误！",
    /* 20 */    "缺少：；或；拼写错误！",
    /* 21 */    "缺少：>，或>拼写错误！",
    /* 22 */    "缺少：<；或<拼写错误！",
    /* 23 */    "程序尾部出现多余单词！",
    /* 24 */    "非法语句"
};


//错误处理： 提示相应错误信息，关闭正在分析的源文件，结束程序
//           这是很烂的一种错误处理，只能发现第一个错误，而且后续编译工作都中断。
void error(int n) {
    printf("%s\n", err_msg[n]);
    fclose(fin);
    exit(0);
}
void advance(){
    getToken();
}

void match(int Tok)
{
    if (lookahead.type == Tok) getToken();
    else error(Tok);
}




/*
BiTNode * x();
BiTNode * y();

//生成语法树
BiTNode * express()
{
    BiTNode * result1 =x();
    while (lookahead.type=PLUS||lookahead.type==MINUS) {
        if (lookahead.type==PLUS) {
            match(PLUS);
            
        }
        else match(MINUS);
        BiTNode* result2=x(); //将result1和result2构成一个新的TreeNode节点，该节点的左右子树就是result1和result2，再将result1指向新构成的子树的根节点
        result1->rchild=result2;
    }
    

    return result1;
}

BiTNode * x()
{
    BiTNode* term1=y();
    while (lookahead.type==MUL||lookahead.type==DIV) {
        if (lookahead.type==MUL) {
            match(MUL);
        }
        else{
            match(DIV);
        }
        BiTNode* term2=y();
        term1->rchild=term2;
    }
    return term1;
}


BiTNode* y()           //对应叶子节点
{
    BiTNode FIR=*CreateBiTree();
    BiTNode*  sym;
    if(lookahead.type==ID)
    {
        getToken();
        sym=CreateBiTree();
        sym->lchild=&FIR;
    }
    else if(lookahead.type==INTC)
    {
        getToken();
        sym=CreateBiTree();
        sym->lchild=&FIR;
    }
    
    else if(lookahead.type==LP)
    {
        match(LP);
        express();
    }
    else printf("error");
    return sym;// 返回运算符
}


 */
int mark_lp;

Token before;
void id();//从单词类型为变量和整数的单词往后检索一个Token
void lp();//从单词类型为左括号的单词往后检索一个Token
void rp();//从单词类型为右括号的单词往后检索一个Token
void sym();//从单词类型为运算符的单词往后检索一个Token
void judge();//主judge函数，main函数调用该函数，进行语法分析
void  judge(){
    mark_lp=0;
    while (lookahead.type!=ERR) {
        if (lookahead.type==ID||lookahead.type==INTC) {
            id();
            continue;
        }
        if (lookahead.type==LP) {
            lp();
            mark_lp++;
            continue;
        }
        if (lookahead.type==RP) {
            rp();
            mark_lp--;
            continue;
        }
        if (lookahead.type==5||lookahead.type==6||lookahead.type==7||lookahead.type==8) {
            sym();
            continue;
        }
        
    }
    if (mark_lp!=0) {
        cout<<"分析失败！"<<endl;
        exit(0);
    }
    cout<<"分析成功！"<<endl;
}
void id(){
    before=lookahead;
    getToken();
    //print();
    if(lookahead.type==ID||lookahead.type==INTC||lookahead.type==LP){
        cout<<"分析失败！"<<endl;
        exit(0);
    }
}

void lp(){
    getToken();
    //print();
    //printf("%d\n",lookahead.type);
    if (lookahead.type==RP||lookahead.type==5||lookahead.type==6||lookahead.type==7||lookahead.type==8) {
        cout<<"分析失败！"<<endl;
        exit(0);
    }
}

void rp(){
    getToken();
    //print();
    if (lookahead.type==INTC||lookahead.type==ID||lookahead.type==LP) {
        cout<<"分析失败！"<<endl;
        exit(0);
    }
}
/*
void print(){
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
}
 //检测输出所用的print函数
*/
void sym(){
    getToken();
    if (lookahead.type!=INTC&&lookahead.type!=ID&&lookahead.type!=LP) {
        cout<<"分析失败！"<<endl;
        exit(0);

    }
}
//四则运算文法
//  <表达式>-><项> [ +|- <项>]
//  <项>-><因子> [ *|/ <因子>]
//  <因子>->id | digits | (  <表达式>  )



//<表达式>-><项> [ +|- <项>]


void term();
void factor();


void expression()
{

    term();
     while (lookahead.type==PLUS||lookahead.type==MINUS) {
        if (lookahead.type==PLUS) {
            match(PLUS);
        }
        else match(MINUS);
        term();
    }
}



//<项>-><因子> [ *|/ <因子>]
void term()
{
    factor();
    while (lookahead.type==MUL||lookahead.type==DIV) {
        if (lookahead.type==MUL) {
            match(MUL);
        }
        else match(DIV);
        factor();
    }
   
}


//  <因子>->id | digits | (  <表达式>  )
void factor()
{
    
    if(lookahead.type==ID) getToken();
    else if(lookahead.type==INTC) getToken();
    else if(lookahead.type==LP)
            {
                match(LP);
                expression();
            }
    else printf("error");
}








