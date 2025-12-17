#include "modifypatwidget.h"
#include "ui_modifypatwidget.h"

ModifyPatWidget::ModifyPatWidget(QWidget *parent, int index)
    : QWidget(parent)
    , ui(new Ui::ModifyPatWidget)
{
    ui->setupUi(this);

    // 初始化性别下拉框
    ui->dbComboSex->addItem("男");
    ui->dbComboSex->addItem("女");

    // 设置UID和创建时间不可编辑
    ui->dbEditID->setReadOnly(true);
    ui->dbCreatedTimestamp->setReadOnly(true);

    dataMapper = new QDataWidgetMapper();
    QSqlTableModel *tabModel = SingleToDB::getInstance()->patienTabModel;
    dataMapper->setModel(SingleToDB::getInstance()->patienTabModel);
    dataMapper->setSubmitPolicy(QDataWidgetMapper::ManualSubmit); // 改为手动提交，与模型策略一致

    dataMapper->addMapping(ui->dbEditID, tabModel->fieldIndex("ID"));
    dataMapper->addMapping(ui->dbEditName, tabModel->fieldIndex("NAME"));
    dataMapper->addMapping(ui->dbEditIDCard, tabModel->fieldIndex("ID_CARD"));
    dataMapper->addMapping(ui->dbSpinHeight, tabModel->fieldIndex("HEIGHT"));
    dataMapper->addMapping(ui->dbSpinWeight, tabModel->fieldIndex("WEIGHT"));
    dataMapper->addMapping(ui->dbEditMobile, tabModel->fieldIndex("MOBILEPHONE"));
    dataMapper->addMapping(ui->dbDateEditDOB, tabModel->fieldIndex("DOB"));
    dataMapper->addMapping(ui->dbComboSex, tabModel->fieldIndex("SEX"));
    dataMapper->addMapping(ui->dbCreatedTimestamp, tabModel->fieldIndex("CREATEDTIMESTAMP"));

    dataMapper->setCurrentIndex(index);
}

ModifyPatWidget::~ModifyPatWidget()
{
    qDebug()<<"析构 ModifyPatWidget";
    delete ui;
}

void ModifyPatWidget::on_saveBtn_2_clicked()
{
    dataMapper->submit();
    if (SingleToDB::getInstance()->submitPatientEdit()) {  // 提交修改
        emit goLastWidget();  // 返回上一页
    }
    else {
        qDebug() << "修改失败：" << SingleToDB::getInstance()->patienTabModel->lastError().text();
    }
}


void ModifyPatWidget::on_backBtn_2_clicked()
{
    SingleToDB::getInstance()->revertPatientEdit();  // 撤销未提交的修改
    emit goLastWidget();  // 返回上一页
}

