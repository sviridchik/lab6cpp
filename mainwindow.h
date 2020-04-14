#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTime>
#include <QButtonGroup>
#include <QObject>
#include <QtGui>
#include <QtCore>
#include <QPainter>
#include <QPaintEvent>
#include <QKeyEvent>
#include <QBrush>
#include <tree.h>
#include <tree.cpp>
#include <QTreeWidgetItem>
#include <QTime>
QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT


public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    bool paint = false;

    //    tree tree;
    //    tree::node* root =  NULL;33

private slots:
    void on_draw_clicked();
    void rec(tree::node* t, QTreeWidgetItem*  prev);

    void AddTable(int value1, QString value2);

    void NLR(tree::node* Q);
    void LNR(tree::node* Q);
    void LRN(tree::node* Q);


    void on_insert_clicked();

    void on_remove_clicked();

    void on_Search_clicked();

    void on_random_clicked();

    void on_delete_2_clicked();

    void on_nlp_clicked();

    void on_lnr_clicked();

    void on_lrn_clicked();

    void on_count_clicked();

private:
    Ui::MainWindow *ui;
    MainWindow *parent;
};

#endif // MAINWINDOW_H

//QTreeWidgetItem* x = new QTreeWidgetItem();
//    x->setText(0,QString::number(t->x.first));
//    prev->addChild(x);
//    if (t->left!=NULL)
//        rec (p*2,t->left,x);
//    if (t->right!=NULL)
////        rec (p*2+1,t->right,x);
