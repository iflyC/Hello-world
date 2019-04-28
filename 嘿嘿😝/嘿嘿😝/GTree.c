//
//  GTree.c
//  嘿嘿😝
//
//  Created by iflyC on 2018/11/19.
//  Copyright © 2018年 iflyC. All rights reserved.
//

#include "GTree.h"
#include "LinkList.h"
#include <stdlib.h>

typedef struct _tag_GTreeNode GTreeNode ;
struct _tag_GTreeNode
{
    GTreeData *data;
    GTreeNode *parent;
    LinkList *child;
};

typedef struct _tag_TLNode TLNode;
struct _tag_TLNode
{
    LinkListNode header;
    GTreeNode *node;
};
GTree *GTree_Create(void)
{
    return LinkList_Create();
}

void GTree_Destroy(GTree *tree)
{
    GTree_Clear(tree);
    free(tree);
}

void GTree_Clear(GTree *tree)
{
    GTree_Delete(tree, 0);
}
/*
 1. 参数有效性判断
 2.

 */
int GTree_Insert(GTree *tree,GTreeData *data,int pPos)
{
    LinkList *tlList = (LinkList *)tree;
    int ret =tlList != NULL && pPos < LinkList_Length(tlList);
    if(ret)
    {
        GTreeNode *trNode = (GTreeNode *)malloc(sizeof(GTreeNode));
        TLNode *tlNode = (TLNode *)malloc(sizeof(TLNode));
        TLNode *childNode = (TLNode *)malloc(sizeof(TLNode));
        // 或许指定位置父节点
        TLNode *parentNode = (TLNode *)LinkList_Get(tlList, pPos);

        ret = ret && trNode != NULL && tlNode != NULL && childNode != NULL;
        if(ret)
        {
            // 初始化节点
            trNode->data = data;
            trNode->parent = NULL;
            trNode->child = LinkList_Create();

            tlNode->node = trNode;
            childNode->node = trNode;
            // 插入组织链表中
            LinkList_Insert(tlList, LinkList_Length(tlList), (LinkListNode *)tlNode);

            if(parentNode != NULL)
            {
                // 插入父节点的child链表中
                trNode->parent = parentNode->node;
                LinkList_Insert(parentNode->node->child, LinkList_Length(parentNode->node->child), (LinkListNode *)childNode);
            }
        }else{
            free(trNode);
            free(tlNode);
            free(childNode);

        }
    }
    return ret;
}
static void recursive_Delete(LinkList *tlList,GTreeNode *trNode)
{
    if(tlList != NULL && trNode != NULL)
    {
        int index = -1;
        // 从组织链表中删除
        for(int i = 0; i < LinkList_Length(tlList); i++)
        {
            TLNode *tlNode = (TLNode *)LinkList_Get(tlList, i);

            if(tlNode->node == trNode)
            {
                LinkList_Delete(tlList, i);
                free(tlNode);
                index = i;
                break;
            }
        }
        if(index >= 0)
        {
            if(trNode->parent != NULL)
            {
                // 从父节点子节点链表中删除
                for(int i = 0; i < LinkList_Length(trNode->parent->child); i++)
                {
                    TLNode * childNode = (TLNode *)LinkList_Get(trNode->parent->child, i);
                    if(childNode->node == trNode)
                    {
                        LinkList_Delete(trNode->parent->child, i);
                        free(childNode);
                        break;
                    }
                }
            }
            // 删除自身子节点链表中节点
            while (LinkList_Length(trNode->child) > 0) {
                TLNode *childNode = (TLNode *)LinkList_Get(trNode->child, 0);

                recursive_Delete(tlList, childNode->node);
            }
            LinkList_Destroy(trNode->child);
            free(trNode);
        }
    }
}
GTreeData *GTree_Delete(GTree *tree,int pos)
{
    TLNode *tlNode = (TLNode *)LinkList_Get(tree, pos);
    GTreeData *ret = NULL;
    if(tlNode != NULL)
    {

        ret = tlNode->node->data;
        recursive_Delete(tree, tlNode->node);
    }
    return ret;
}

int GTree_Length(GTree *tree)
{
    LinkList *tlList = (LinkList *)tree;
    int ret = 0;
    if(tlList != NULL)
    {
        ret = LinkList_Length(tlList);
    }
    return ret;
}


static int recursive_degree(GTreeNode *node)
{
    int ret = -1;
    if(node != NULL)
    {
        ret = LinkList_Length(node->child);
        for(int i = 0; i < LinkList_Length(node->child); i++)
        {
            TLNode *tlNode = (TLNode *)LinkList_Get(node->child, i);
            int degree = recursive_degree(tlNode->node);
            if(ret < degree)
            {
                ret = degree;
            }
        }
    }
    return ret;
}
int GTree_Degree(GTree *tree)
{
    LinkList *tlList = (LinkList *)tree;
    int ret = 0;
    if(tlList != NULL)
    {
        TLNode *tlNode = (TLNode *)LinkList_Get(tlList, 0);
        if(tlNode != NULL)
        {
            ret = recursive_degree(tlNode->node);
        }
    }
    return ret;
}
static int recursive_height(GTreeNode *node)
{
    int ret = 0;
    int subHeight = 0;
    if(node != NULL)
    {
        for(int i =0; i < LinkList_Length(node->child); i++)
        {
            TLNode *tlNode = (TLNode *)LinkList_Get(node->child, i);
            subHeight = recursive_degree(tlNode->node);
            if(ret < subHeight)
            {
                ret = subHeight;
            }
        }
        ret += 1;
    }
    return ret;
}
int GTree_Height(GTree *tree)
{
    LinkList *tlList = (LinkList *)tree;
    int ret = 0;
    if(tlList != NULL)
    {
        TLNode *tlNode = (TLNode *)LinkList_Get(tlList, 0);
        if(tlNode != NULL)
        {
            ret = recursive_height(tlNode->node);
        }
    }
    return ret;
}
static void recursive_diplay(GTreeNode *trNode,int format,char div)
{
    for(int i =0; i < format; i++)
    {
        printf("%c",div);
    }
    printf("%c\n",(int)trNode->data);
    for(int i = 0; i < LinkList_Length(trNode->child);i++)
    {
        TLNode *childNode = (TLNode *)LinkList_Get(trNode->child, i);
        recursive_diplay(childNode->node, format + 2, div);
    }
}
void GTree_Display(GTree *tree)
{
    LinkList *tlList = (LinkList *)tree;
    TLNode *tlNode = (TLNode *)LinkList_Get(tlList, 0);
    if(tlNode != NULL)
    {
        recursive_diplay(tlNode->node, 0, '-');
    }
}
