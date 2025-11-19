#include "searchdialog.h"
#include "ui_searchdialog.h"

SearchDialog::SearchDialog(QWidget *parent, QPlainTextEdit * textEdit)
    : QDialog(parent)
    , ui(new Ui::SearchDialog)
{
    ui->setupUi(this);
    pTextEdit = textEdit;
    ui->rbDown->setChecked(true);
}

SearchDialog::~SearchDialog()
{
    delete ui;
}

void SearchDialog::on_bt_next_clicked()
{
    QString target = ui->lineEdit->text().trimmed(); // 去除首尾空格
    if (target == "" || pTextEdit == nullptr)
        return;

    if (target.isEmpty()) { // 处理查找目标为空的情况
        QMessageBox::information(this, "提示", "请输入查找内容！", QMessageBox::Ok);
        ui->lineEdit->setFocus(); // 光标定位到输入框
        return;
    }

    QString text = pTextEdit->toPlainText();
    QTextCursor c = pTextEdit->textCursor();
    int index = -1;

    // 读取「区分大小写」复选框的状态（cbCaseSensetive）
    Qt::CaseSensitivity caseSensitivity = ui->radioButton->isChecked()
                                              ? Qt::CaseSensitive
                                              : Qt::CaseInsensitive;

    if (ui->rbDown->isChecked()) { // 向下查找
        // 从光标当前位置开始查找（不包含当前光标位置的字符，避免重复匹配）
        index = text.indexOf(target, c.position(), caseSensitivity);
        if (index >= 0) {
            c.setPosition(index); // 定位到匹配起始位置
            // 选中匹配内容（从起始位置到起始+目标长度）
            c.setPosition(index + target.length(), QTextCursor::KeepAnchor);
            pTextEdit->setTextCursor(c);
        }
    } else if (ui->rbUp->isChecked()) { // 向上查找
        // 关键修正：lastIndexOf的第二个参数改为 c.position() - 1（从光标前一个字符开始找）
        index = text.lastIndexOf(target, c.position() - 1, caseSensitivity);
        if (index >= 0) {
            c.setPosition(index + target.length()); // 定位到匹配结束位置
            // 反向选中（从结束位置到起始位置）
            c.setPosition(index, QTextCursor::KeepAnchor);
            pTextEdit->setTextCursor(c);
        }
    }

    // 找不到目标的提示
    if (index < 0) {
        QMessageBox msg(this);
        msg.setWindowTitle("记事本");
        msg.setText(QString("找不到“%1”").arg(target)); // 优化提示文本格式
        msg.setWindowFlag(Qt::Drawer);
        msg.setIcon(QMessageBox::Information);
        msg.setStandardButtons(QMessageBox::Ok);
        msg.exec();
    }
}



void SearchDialog::on_bt_cancel_clicked()
{
    accept();
}

