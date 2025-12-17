#include "patientwidget.h"
#include "ui_patientwidget.h"
#include "singletodb.h"
#include <QMessageBox>

PatientWidget::PatientWidget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::PatientWidget)
{
    ui->setupUi(this);

    this->ui->tableView->setSelectionBehavior(QAbstractItemView::SelectRows);
    this->ui->tableView->setSelectionMode(QAbstractItemView::SingleSelection);
    this->ui->tableView->setEditTriggers(QAbstractItemView::NoEditTriggers);
    this->ui->tableView->setAlternatingRowColors(true);

    if(SingleToDB::getInstance()->initPatientModel()){
        this->ui->tableView->setModel(SingleToDB::getInstance()->patienTabModel);
        this->ui->tableView->setSelectionModel(SingleToDB::getInstance()->patientSelection);
    }


    // 增加按钮 -> 切换到添加页面
    // connect(ui->addBtn, &QPushButton::clicked, this, &PatientWidget::sigSwitchToAddPatient);
    // 修改按钮 -> 切换到修改页面
    // connect(ui->editBtn, &QPushButton::clicked, this, &PatientWidget::sigSwitchToModifyPatient);

}

PatientWidget::~PatientWidget()
{
    qDebug()<<"析构 PatientWidget";
    delete ui;
}

void PatientWidget::on_searchBtn_clicked()
{
    QString filter = QString("name like '%%1%'").arg(this->ui->txtSearch->text());
    SingleToDB::getInstance()->searchPatient(filter);
}


void PatientWidget::on_delBtn_clicked()
{
    // 检查是否有选中行
    auto selectionModel = ui->tableView->selectionModel();
    if (!selectionModel->hasSelection()) {
        QMessageBox::warning(this, "提示", "请先选中要删除的患者");
        return;
    }
    // 确认删除
    if (QMessageBox::question(this, "确认", "确定要删除选中的患者吗？") == QMessageBox::Yes) {
        SingleToDB::getInstance()->deleteCurrentPatient();
    }
}


void PatientWidget::on_addBtn_clicked()
{
    int curRow = SingleToDB::getInstance()->addNewPatient();
    emit sigSwitchToAddPatient(curRow);
}


void PatientWidget::on_editBtn_clicked()
{
    QModelIndex curIndex = SingleToDB::getInstance()->patientSelection->currentIndex();
    emit sigSwitchToModifyPatient(curIndex.row());
}
