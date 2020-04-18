#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>

tree tree;
tree::node* root =  NULL;
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QTime now = QTime::currentTime();
    srand(now.msec());
}

MainWindow::~MainWindow()
{
    delete ui;
}


QTreeWidgetItem* visualRoot;
int k;

void MainWindow::rec(tree::node* t, QTreeWidgetItem*  prev){
    if (t!=NULL)
       {

           k++;
       }

       QTreeWidgetItem* x = new QTreeWidgetItem();
       x->setText(0,QString::number(t->key));
       prev->addChild(x);
       if (t->left!=NULL)
           rec(t->left,x);
       if (t->right!=NULL)
           rec(t->right,x);
}

void MainWindow::on_draw_clicked()
{
    ui->treeWidget->clear();
    ui->treeWidget->setHeaderLabel("All the beauty in thus programm");
    visualRoot = new QTreeWidgetItem();
    if(root == NULL){
        return;
    }
    rec(root,visualRoot);
    ui->treeWidget->addTopLevelItem(visualRoot);
//    paint = true;
//    parent->repaint();
}

void MainWindow::on_insert_clicked()
{
    if (ui->input_value_int->text() == "" || ui->input_value_str->text() == "")return;
    root = tree.Insert((ui->input_value_int->text().toInt()),( ui->input_value_str->text()),root);
    QMessageBox::information(parent,"Well done","Successfully add to tree");
}

void MainWindow::on_remove_clicked()
{
    if (ui->remove_value->text()=="") return;

     root = tree.Remove(ui->remove_value->text().toInt(),root);
     QMessageBox::information(parent,"Well done","Successfully removed node");
}

void MainWindow::on_Search_clicked()
{
    try {
           QString temp = tree.Search(ui->search_value->text().toInt(),root);
            QMessageBox::information(parent,"Well done",temp);
        }
        catch (int) {
            QMessageBox::critical(parent," ","Error");
        }
}
int ii =0;
QStringList str = {"beatiful","important","hi","interest","qwerty","angelina","tosha","huge","lesha","ulia"};
void MainWindow::on_random_clicked()
{
    int mas[25] = {0};
    for (int i=0;i<15; i++){
        int temp = rand()%25;
        while(mas[temp] == 1){
           temp = rand()%25;}

        mas[temp] = 1;

        root = tree.Insert(temp,str[rand()%10],root);
        ii++;
    }
}

void MainWindow::on_delete_2_clicked()
{
    root = NULL;
}

int u = 0;

void MainWindow::AddTable(int value1, QString value2)
{
    ui->tableWidget->setItem(u,0,new QTableWidgetItem(QString::number(value1)));
    ui->tableWidget->setItem(u,1,new QTableWidgetItem(value2));
    u++;
}
//прямой

void MainWindow::NLR(tree::node* Q)
{
    if (Q==NULL) return;
    AddTable(Q->key, Q->value);
    NLR(Q->left);
    NLR(Q->right);
}
void MainWindow::on_nlp_clicked()
{
    u = 0;
      ui->tableWidget->clear();
      ui->tableWidget->setHorizontalHeaderLabels({"->","NLP"});
      ui->tableWidget->setHorizontalHeaderLabels({"Ключ","Информация"});
      NLR(root);
}
//центриррованный
void MainWindow::LNR(tree::node* Q)
{
    if (Q==NULL) return;
    LNR(Q->left);
    AddTable(Q->key, Q->value);
    LNR(Q->right);
}

void MainWindow::on_lnr_clicked()
{

    u = 0;
    ui->tableWidget->clear();
    ui->tableWidget->setHorizontalHeaderLabels({"Ключ","Информация"});
    LNR(root);
}

void MainWindow::LRN(tree::node* Q)
{
    if (Q==NULL) return;
    LRN(Q->left);
    LRN(Q->right);
    AddTable(Q->key, Q->value);
}

//обратный
void MainWindow::on_lrn_clicked()
{
    u = 0;
    ui->tableWidget->clear();
    ui->tableWidget->setHorizontalHeaderLabels({"Ключ","Информация"});
    LRN(root);
}
int uu = 0;
void MainWindow::on_count_clicked()
{
//    QMap<int,int> m;
//     QMap<int, int>::iterator i;
    uu = 0;
    int m[125]={0};
    ui->tableWidget_2->clear();
     ui->tableWidget_2->setHorizontalHeaderLabels({"On the level ","leaves"});
        tree.my_count(root,m,0);
        for (int i =0; i<125; i++)
        {

         ui->tableWidget_2->setItem(uu,0,new QTableWidgetItem(QString::number(i)));
         ui->tableWidget_2->setItem(uu,1,new QTableWidgetItem(QString::number(m[i])));
         uu++;
        }
}
