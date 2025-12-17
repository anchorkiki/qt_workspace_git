#include "AddPatientWidget.h"
#include "ui_addpatientwidget.h"

AddPatientWidget::AddPatientWidget(QWidget *parent, int rowIndex)
    : QWidget(parent)
    , ui(new Ui::AddPatientWidget)
    , m_rowIndex(rowIndex)
{
    ui->setupUi(this);

    // 初始化性别下拉框
    ui->genderComb->addItem("男");
    ui->genderComb->addItem("女");

    // 设置身高和体重的范围
    ui->heighSpinB->setRange(50, 250);
    ui->weightSpinB->setRange(10, 200);

    // 设置UID和创建时间不可编辑
    ui->idEdit->setReadOnly(true);
    ui->dbCreatedTimestamp->setReadOnly(true);

    // 从数据库获取最新UID（最大ID+1）
    int maxId = SingleToDB::getInstance()->getMaxPatientID();
    int newIdNum = maxId + 1; // 最大数字+1
    // 格式化为P001、P002...
    QString uid = QString::asprintf("P%03d", newIdNum);
    ui->idEdit->setText(uid);

    // 自动设置创建时间为当前时间
    QString currentTime = QDateTime::currentDateTime().toString("yyyy-MM-dd HH:mm:ss");
    qDebug() << "当前时间：" << currentTime; // 检查是否有值
    ui->dbCreatedTimestamp->setText(currentTime);

    // 初始化数据映射器（关联UI控件与模型）
    dataMapper = new QDataWidgetMapper(this);
    QSqlTableModel *tabModel = SingleToDB::getInstance()->patienTabModel;
    dataMapper->setModel(tabModel);
    dataMapper->setSubmitPolicy(QDataWidgetMapper::ManualSubmit); // 手动提交

    // 映射控件到数据库字段
    dataMapper->addMapping(ui->nameEdit, tabModel->fieldIndex("NAME"));
    dataMapper->addMapping(ui->identityEdit, tabModel->fieldIndex("ID_CARD"));
    dataMapper->addMapping(ui->genderComb, tabModel->fieldIndex("SEX"));
    dataMapper->addMapping(ui->bornSpinB, tabModel->fieldIndex("DOB"));
    dataMapper->addMapping(ui->heighSpinB, tabModel->fieldIndex("HEIGHT"));
    dataMapper->addMapping(ui->weightSpinB, tabModel->fieldIndex("WEIGHT"));
    dataMapper->addMapping(ui->phoneEdit, tabModel->fieldIndex("MOBILEPHONE"));

    // 定位到新增的行
    dataMapper->setCurrentIndex(m_rowIndex);
}

AddPatientWidget::~AddPatientWidget()
{
    qDebug()<<"析构 AddPatientWidget";
    delete ui;
}

void AddPatientWidget::on_saveBtn_clicked()
{
    dataMapper->submit();
    if (SingleToDB::getInstance()->submitPatientEdit()) {  // 提交成功后返回
        emit goLastWidget();
    } else {
        qDebug() << "保存失败：" << SingleToDB::getInstance()->patienTabModel->lastError().text();
    }
}


void AddPatientWidget::on_backBtn_clicked()
{
    SingleToDB::getInstance()->revertPatientEdit();  // 撤销修改
    emit goLastWidget();  // 发射返回信号
}

