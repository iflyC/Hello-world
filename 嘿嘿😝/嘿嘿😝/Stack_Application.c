//
//  Stack_Application.c
//  嘿嘿😝
//
//  Created by iflyC on 2018/11/7.
//  Copyright © 2018年 iflyC. All rights reserved.
//

#include "Stack_Application.h"
#include "LinkStack.h"
int isLeft(char c)
{
    int ret = 0;
    switch (c) {
        case '(':
        case '<':
        case '{':
        case '[':
            ret = 1;
        default:
            break;
    }
    return ret;
}
int isRight(char c)
{
    int ret = 0;
    switch (c) {
        case ')':
        case '>':
        case '}':
        case ']':
            ret = 1;
        default:
            break;
    }
    return ret;
}
int match(char left, char right)
{
    int ret = 0;
    switch (left) {
        case '<':
            ret = right == '>';
            break;
        case '{':
            ret = right == '}';
            break;
        case '[':
            ret = right == ']';
            break;
        case '(':
            ret = right == ')';
            break;
        default:
            break;
    }
    return ret;
}

int scaner(char *code)
{
    LinkStack *stack = LinkStack_Create();
    int ret = 0;
    int i = 0;

    while (code[i] != '\0') {
        // 左符号入栈
        if(isLeft(code[i]))
        {
            LinkStack_Push(stack, code+i);
        }
        if(isRight(code[i]))
        {
            char *c = (char *)LinkStack_Pop(stack);
            if(c == NULL ||!match(*c, code[i]))
            {
                printf("字符%c找不到匹配",code[i]);
                ret = 0;
                break;
            }
        }
        i++;

    }
    if(code[i] == '\0' && LinkStack_Size(stack) == 0)
    {
        ret = 1;
        printf("匹配成功");
    }else{
        ret = 0;
        printf("匹配失败");
    }
    LinkStack_Destroy(stack);
    return ret;
}
/*
    1. 数字直接输出
    2. 符号
         左括号 ：直接入栈
         运算符号：高于当前优先级直接入栈，低于则弹出栈顶元素并输出，再入栈
         右括号： 弹出栈顶元素并输出，直到匹配到左括号
    3. 遍历结束，讲栈中所有元素弹出并输出
 */
int isNumber(char c)
{
    return c >= '0' && c <= '9';
}
int isOperator(char c)
{
    int ret = 0;
    switch (c) {
        case '+':
        case '-':
        case '*':
        case '/':
            ret = 1;
            break;
        default:
            break;
    }
    return ret;
}
int getPriority(char o)
{
    int ret = 0;
    if(o == '+' || o == '-')
    {
        ret = 1;
    }
    if(o == '*' || o == '/')
    {
        ret = 2;
    }
    return ret;
}
void transform(char *code)
{

    LinkStack *stack = LinkStack_Create();
    int i = 0;
    while (code[i] != '\0') {

        if(isNumber(code[i]))
        {
            printf("%c",code[i]);
        }
        else if(isOperator(code[i]))
        {

            while(getPriority((char)(long)LinkStack_Top(stack)) >= getPriority(code[i]))
            {
                printf("%c",(char)(int)LinkStack_Pop(stack));
            }
            LinkStack_Push(stack, (void *)(long)code[i]);
        }
        else if(code[i] == '(')
        {
            LinkStack_Push(stack, (void*)(long)code[i]);
        }
        else if(code[i] == ')')
        {
           while((char)(int)LinkStack_Top(stack) != '(')
           {
               printf("%c",(char)(long)LinkStack_Pop(stack));
           }
            LinkStack_Pop(stack);
        }else{
            printf("invalid expression");
            break;
        }

        i++;
    }
    while(LinkStack_Size(stack) > 0)
    {
        printf("%c",(char)(int)LinkStack_Pop(stack));
    }
    LinkStack_Destroy(stack);
}
int value(char c)
{
    return c - '0';
}
int express(int left, char o, int right)
{
    int ret = 0;
    switch (o) {
        case '+':
            ret = left + right;
            break;
        case '-':
            ret = left - right;
            break;
        case '*':
            ret = left * right;
            break;
        case '/':
            ret = left / right;
            break;
        default:
            break;
    }
    return ret;
}
int computer(char *code)
{
    int ret = 0;
    int i = 0;
    LinkStack *stack = LinkStack_Create();

    while (code[i] != '\0') {

        if(isNumber(code[i]))
        {
            LinkStack_Push(stack, (void *)value(code[i]));
        }else if (isOperator(code[i]))
        {

            int right = (int)LinkStack_Pop(stack);
            int left = (int)LinkStack_Pop(stack);
            int result = express(left, code[i], right);
            LinkStack_Push(stack, (void*)result);
        }else{
            printf("invalid expression");
            break;
        }
        i++;
    }
    if(LinkStack_Size(stack) == 1 && code[i] == '\0')
    {
        ret = (int)LinkStack_Pop(stack);
    }else{
        printf("invalid expression");
    }

    LinkStack_Destroy(stack);
    printf("%d",ret);
    return ret;
}
