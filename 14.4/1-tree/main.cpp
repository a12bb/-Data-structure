#include "function.h"

int main() {
    BiTree pnew;//用来指向新申请的结点
    BiTree tree=NULL;//tree是指向树根的代表树
    char c;
    ptag_t phead=NULL,ptail=NULL,listpnew=NULL,pcur;
    //abcdefghij
    while (scanf("%c",&c)) {
        if (c == '\n') {
            break;//读取到换行就结束
        }

        //calloc申请的空间大小是两个参数直接相乘，并对空间初始化，赋值为0
        pnew = (BiTree) calloc(1, sizeof(BiTNode));
        pnew->c = c;
        listpnew = (ptag_t) calloc(1, sizeof(tag_t));//给队列结点申请空间
        listpnew->p = pnew;
        //如果是树的第一个结点
        if (NULL == tree) {
            tree = pnew;//tree指向树的根结点
            phead = listpnew;//第一个结点，既是队列头，也是队列尾
            ptail = listpnew;
            pcur = listpnew;//pcur要指向要进入树的父亲元素
        } else {
            //让元素先入队列
            ptail->pnext = listpnew;
            ptail = listpnew;
            //接下来把b放入树中
            if (NULL == pcur->p->lchild) {
                pcur->p->lchild = pnew;//pcur左孩子为空就放左孩子
            } else if (NULL == pcur->p->rchild) {
                pcur->p->rchild = pnew;//pcur右孩子为空就放右孩子
                pcur = pcur->pnext;//当前左右孩子都有，pcur指向下一个
            }
        }
    }
    return 0;
}
