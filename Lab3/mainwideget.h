#ifndef MAINWIDGET_H
#define MAINWIDGET_H

#include <QWidget>

// ========== 登录相关 ==========
#include "loginwidget.h"
#include "choosewidget.h"

// ========== 医生管理相关 ==========
#include "docwidget.h"          // 医生主页面
#include "adddoctorwidget.h"    // 添加医生页面
#include "modifydocwidget.h"    // 修改医生页面
#include "deldocwidget.h"       // 删除医生页面

// ========== 患者管理相关 ==========
#include "patientwidget.h"      // 患者主页面
#include "addpatientwidget.h"   // 添加患者页面
#include "modifypatwidget.h"    // 修改患者页面
#include "delpatientwidget.h"   // 删除患者页面

// ========== 科室/主题相关 ==========
#include "subwidget.h"          // 科室主页面（取消原注释，确保引入）
#include "addsubwidget.h"       // 添加科室页面
#include "modifysubwidget.h"    // 修改科室页面
#include "delsubwidget.h"       // 删除科室页面

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWideget;
}
QT_END_NAMESPACE

class MainWideget : public QWidget
{
    Q_OBJECT

public:
    MainWideget(QWidget *parent = nullptr);
    ~MainWideget();

private slots:
    // 页面切换槽函数
    void onSwitchToLogin();
    void onSwitchToChoose();
    void onSwitchToSub();
    void onSwitchToDoc();
    void onSwitchToPatient();
    void onSwitchToAddSub();
    void onSwitchToModifySub();
    void onSwitchToDelSub();
    void onSwitchToAddDoctor();
    void onSwitchToModifyDoc();
    void onSwitchToDelDoc();
    void onSwitchToAddPatient();
    void onSwitchToModifyPatient();
    void onSwitchToDelPatient();

private:
    Ui::MainWideget *ui;

    // 页面实例指针（严格匹配头文件中的类名，避免大小写/拼写错误）
    LoginWidget *loginWidget;
    ChooseWidget *chooseWidget;
    SubWidget *subWidget;
    DocWidget *docWidget;
    PatientWidget *patientWidget;
    AddSubWidget *addSubWidget;
    ModifySubWidget *modifySubWidget;
    DelSubWidget *delSubWidget;
    AddDoctorWidget *addDoctorWidget;
    ModifyDocWidget *modifyDocWidget;
    DelDocWidget *delDocWidget;
    AddPatientWidget *addPatientWidget;
    ModifyPatWidget *modifyPatWidget;
    DelPatientWidget *delPatientWidget;
};

#endif // MAINWIDGET_H
