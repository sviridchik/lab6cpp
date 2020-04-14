#ifndef TREE_H
#define TREE_H
#include <mainwindow.h>
//#include <my_pair.h>
//template <typename T>

class tree
{
public:
    tree(){};
    struct node{
           int key;
           QString value;
           node *left;
           node *right;
           int height_y;
           node(int k, QString v,int h){
              key = k;
              value = v;
              height_y = h;
              left = NULL;
              right = NULL;
           }
       };
    template <typename T1,typename T2>
    struct my_pair{
      T1 first;
      T2 second;
    };

    node* Merge(node* t1, node* t2){
        if(t1 == NULL) return t2;
        if(t2 == NULL) return t1;
        if(t1->height_y > t2->height_y) {
            t1->right = Merge(t1->right,t2);
            //ставится смерджинная вершинка
            return t1;
        }
        else{
            t2->left = Merge(t1,t2->left);
            return t2;
        }

    }

//    my_pair <node* , node*> Split (int kk, node* tr){
        my_pair<node* , node*> Split (int kk, node* tr){

        if(tr == NULL){
            return {NULL,NULL};
        }else if(kk>tr->key){
            my_pair<node*,node*> temp = Split(kk,tr->right);
            // приклеиваем с нужной ветки, что ненужно
            tr->right = temp.first;
            return {tr,temp.second};
        }else{
            my_pair <node*, node*> temp = Split(kk, tr->left);
            tr->left = temp.second;
            return {temp.first, tr};
        }
    }

    QString Search(int kk, node* tr){
        if(tr == NULL){
            //qwertyuio
            throw  -1;
        }
        if(tr->key>kk){
            return Search(kk,tr->left);
        }else{
            if(tr->key<kk){
                return Search(kk, tr->right);
            }else{
                return tr->value;
            }
        }
    }

    node* Insert(int kk,QString sv, node* tr){
        my_pair<node*,node*> temp = Split(kk,tr);
//        node(int k, QString v,int h
        node* newNode = new node(kk,sv,rand());
        return Merge(Merge(temp.first,newNode),temp.second);
    }

    node* Remove(int kk, node*tr){
        my_pair<node*, node*> temp1 = Split(kk, tr);
        my_pair<node*, node*> temp2 = Split(kk+1, temp1.second);
        my_pair<node*, node*> p = Split(kk, tr);
        return Merge(temp1.first, temp2.second);
    }


    node* Remove1(int kk, node*tr){
        my_pair<node*, node*> temp = Split(kk, tr);
        node* Q = temp.second;
        node* pQ = NULL;
        if (Q->left==NULL){
            temp.second = temp.second->right;
        }else{
            while(Q->left!=NULL){
                pQ = Q;
                Q=Q->left;
            }
            pQ->left = Q->right;
        }
        return Merge(temp.first, temp.second);
    }
    int list_count(node* Q)
    {
     if (Q==NULL){return 0;}
     if (Q->left == NULL && Q->right==NULL)
      return 1;
     return list_count(Q->left) + list_count(Q->right);
    }

//    void my_count(node* tree, QMap<int,int>&m, int level)
//    {
////        m[level]++;

////        if (tree->left)  my_count(tree->left,m,level+1);
////        if (tree->right) my_count(tree->right,m,level+1);
//          if (tree->left == NULL && tree->right==NULL){m[level]++;}
////}else/*{
////              m[level]=0;
////          }*/

//        if (tree->left)  my_count(tree->left,m,level+1);
//        if (tree->right) my_count(tree->right,m,level+1);
//    }
    void my_count(node* tree, int *m, int level)
    {
//        m[level]++;

//        if (tree->left)  my_count(tree->left,m,level+1);
//        if (tree->right) my_count(tree->right,m,level+1);
          if (tree->left == NULL && tree->right==NULL){m[level]++;}
//}else/*{
//              m[level]=0;
//          }*/

        if (tree->left)  my_count(tree->left,m,level+1);
        if (tree->right) my_count(tree->right,m,level+1);
    }

};

#endif // TREE_H
