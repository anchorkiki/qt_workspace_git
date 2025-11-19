#include "mainwindow.h"


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    this->statusLabel.setMaximumWidth(180);
    this->statusLabel.setText("length:" + QString::number(0) + "     line:" + QString::number(1));
    ui->statusbar->addPermanentWidget(&this->statusLabel);

    this->statusCursorLabel.setMaximumWidth(180);
    this->statusCursorLabel.setText("row:" + QString::number(0) + "     col:" + QString::number(1));
    ui->statusbar->addPermanentWidget(&this->statusCursorLabel);

    QLabel* author = new QLabel(ui->statusbar);
    author->setMaximumWidth(150);
    author->setText("蔡俊杰");
    ui->statusbar->addPermanentWidget(author);

    this->textChange_flag = false;

    ui->actionBack->setEnabled(false);
    ui->actionRecover->setEnabled(false);
    ui->actionCover->setEnabled(false);
    ui->actionCut->setEnabled(false);
    ui->actionPasta->setEnabled(false);

    QPlainTextEdit::LineWrapMode mode = ui->textEdit->lineWrapMode();
    if (mode == QTextEdit::NoWrap ) {
        ui->textEdit->setLineWrapMode(QPlainTextEdit::WidgetWidth);
        ui->actionAutoChangeLine->setChecked(false);
    } else {
        ui->textEdit->setLineWrapMode(QPlainTextEdit::NoWrap);
        ui->actionAutoChangeLine->setChecked(true);
    }

    ui->actionToolBar->setChecked(true);
    ui->actionStatus->setChecked(true);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_action_A_triggered()
{
    AboutDialog dlg;
    dlg.exec();
}


void MainWindow::on_actionFind_triggered()
{
    SearchDialog searchDlg(this, ui->textEdit);
    searchDlg.exec();
}


void MainWindow::on_actionStand_triggered()
{
    ReplaceDialog replaceDlg(this, ui->textEdit);
    replaceDlg.exec();
}


void MainWindow::on_actionNew_triggered()
{
    /*
     * 1.如果编辑了没有修改，则弹出是否保存
     * 2。选择保存，则保存；不保证，则不保存
     * 3.清空编辑器，修改标题名为默认标题名（新文件）
    */

    if (textChange_flag) { // 有未保存的编辑
        QMessageBox::StandardButton btn = QMessageBox::question(
            this,
            "保存提示",
            "有未保存的内容，是否保存？",
            QMessageBox::Save | QMessageBox::Discard | QMessageBox::Cancel
            );
        if (btn == QMessageBox::Save) {
            on_actionSave_triggered();
            if (filePath.isEmpty()) { // 若用户取消了保存对话框（仍为新文件），则不新建
                return;
            }
        } else if (btn == QMessageBox::Cancel) {
            return; // 取消新建操作
        }
        // 选择“Discard”则继续执行新建逻辑
    }
    filePath.clear(); // 标记为新文件
    ui->textEdit->clear();
    this->setWindowTitle("新建文本文件 - 编辑器");
    textChange_flag = false; // 新建后内容未修改，重置标记
}

void MainWindow::on_actionOpen_triggered()
{
    if (textChange_flag) { // 有未保存的编辑
        QMessageBox::StandardButton btn = QMessageBox::question(
            this,
            "保存提示",
            "有未保存的内容，是否保存？",
            QMessageBox::Save | QMessageBox::Discard | QMessageBox::Cancel
            );
        if (btn == QMessageBox::Save) {
            on_actionSave_triggered();
            if (filePath.isEmpty()) { // 若用户取消了保存对话框（仍为新文件），则不打开
                return;
            }
        } else if (btn == QMessageBox::Cancel) {
            return; // 取消打开操作
        }
        // 选择“Discard”则继续执行打开逻辑
    }
    QString fileName = QFileDialog::getOpenFileName(this, "打开文件", ".", tr("Text files (*.txt) ;; All(*.*)"));

    QFile file(fileName);
    if(!file.open(QFile::ReadOnly | QFile::Text)){
        QMessageBox::warning(this, "", "打开文件失败");
        return;
    }

    this->filePath = fileName;

    QTextStream in(&file);
    QString text = in.readAll();
    ui->textEdit->setPlainText(text); // 用setPlainText替代insertPlainText，避免重复插入
    file.close();

    this->setWindowTitle(QFileInfo(fileName).absoluteFilePath());
    textChange_flag = false; // 打开后内容未修改，重置标记
}

void MainWindow::on_actionSave_triggered()
{
    // ---- 步骤1：判断是否需要弹出保存对话框（新文件则弹窗，已有文件则直接保存）----
    if (filePath.isEmpty()) { // 新文件（还没保存过，filePath为空）
        QString filename = QFileDialog::getSaveFileName(
            this,
            "保存文件",
            "",
            "Text files (*.txt)"
            );
        if (filename.isEmpty()) { // 用户取消了保存对话框
            return;
        }
        filePath = filename; // 记录保存路径
    }

    // ---- 步骤2：执行文件写入操作 ----
    QFile file(filePath);
    if (!file.open(QFile::WriteOnly | QFile::Text)) {
        QMessageBox::warning(this, "警告", "打开文件失败");
        return;
    }

    QTextStream out(&file);
    QString text = ui->textEdit->toPlainText();
    out << text;
    file.flush();
    file.close();

    // ---- 步骤3：更新状态（窗口标题、重置未保存标记）----
    this->setWindowTitle(QFileInfo(filePath).absoluteFilePath());
    textChange_flag = false; // 保存后，“未保存编辑”的标记重置为false
}


void MainWindow::on_actionSaveTo_triggered()
{
    // 弹出“另存为”对话框，强制让用户选择新路径（支持txt和所有文件）
    QString newFilePath = QFileDialog::getSaveFileName(
        this,
        "另存为",  // 对话框标题
        "",        // 默认路径（当前目录）
        tr("Text files (*.txt) ;; All files (*.*)")  // 支持的文件类型
        );

    if (newFilePath.isEmpty()) {  // 用户取消了“另存为”操作
        return;
    }

    // 尝试打开新路径的文件，写入内容
    QFile file(newFilePath);
    if (!file.open(QFile::WriteOnly | QFile::Text)) {  // 打开失败（权限/路径错误等）
        QMessageBox::warning(this, "警告", "无法创建/打开文件，保存失败！");
        return;
    }

    // 写入文本编辑区的内容
    QTextStream out(&file);
    QString text = ui->textEdit->toPlainText();
    out << text;

    // 刷新并关闭文件
    file.flush();
    file.close();

    // 更新核心状态：filePath 指向新保存路径，窗口标题显示新路径
    filePath = newFilePath;
    this->setWindowTitle(QFileInfo(newFilePath).absoluteFilePath());

    // 提示保存成功
    QMessageBox::information(this, "提示", "文件另存为成功！");
    this->textChange_flag = false;
}


void MainWindow::on_textEdit_textChanged()
{
    textChange_flag = true; // 标记为“已编辑未保存”
    QString currentTitle = this->windowTitle();
    if(!currentTitle.startsWith("*")){ // 避免重复添加星号
        this->setWindowTitle("*" + currentTitle);
    }

    statusLabel.setText("length: " + QString::number(ui->textEdit->toPlainText().length()) +
                        "    lines: " +
                        QString::number(ui->textEdit->document()->lineCount()));
}

int MainWindow::getTextChange_flag() const
{
    return textChange_flag;
}

void MainWindow::setTextChange_flag(int newTextChange_flag)
{
    textChange_flag = newTextChange_flag;
}

void MainWindow::closeEvent(QCloseEvent *event)
{
    if (textChange_flag) { // 有未保存的编辑
        QMessageBox::StandardButton btn = QMessageBox::question(
            this,
            "保存提示",
            "有未保存的内容，是否保存？",
            QMessageBox::Save | QMessageBox::Discard | QMessageBox::Cancel
            );
        if (btn == QMessageBox::Save) {
            on_actionSave_triggered();
            if (filePath.isEmpty()) { // 若用户取消了保存对话框（仍为新文件），则不关闭窗口
                event->ignore();
                return;
            }
        } else if (btn == QMessageBox::Cancel) {
            event->ignore(); // 取消关闭操作
            return;
        }
        // 选择“Discard”则直接关闭，无需额外操作
    }
    event->accept(); // 允许关闭窗口
}


void MainWindow::on_actionPasta_triggered()
{
    this->ui->textEdit->paste();
}


void MainWindow::on_actionCover_triggered()
{
    this->ui->textEdit->copy();
    ui->actionPasta->setEnabled(true);
}


void MainWindow::on_actionCut_triggered()
{
    this->ui->textEdit->cut();
    ui->actionPasta->setEnabled(true);
}


void MainWindow::on_actionBack_triggered()
{
    this->ui->textEdit->undo();
}


void MainWindow::on_actionRecover_triggered()
{
    this->ui->textEdit->redo();
}


void MainWindow::on_textEdit_undoAvailable(bool b)
{
    ui->actionBack->setEnabled(b);
}


void MainWindow::on_textEdit_copyAvailable(bool b)
{
    ui->actionCover->setEnabled(b);
    ui->actionCut->setEnabled(b);
}


void MainWindow::on_textEdit_redoAvailable(bool b)
{
    ui->actionRecover->setEnabled(b);
}


void MainWindow::on_actionLetterColor_triggered()
{
    QColor color = QColorDialog::getColor(Qt::black, this, "选择颜色");
    if (color.isValid()) {
        ui->textEdit->setStyleSheet(QString("QPlainTextEdit {color: %1}").arg(color.name()));
    }
}

void MainWindow::on_actionEditBackgroundColor_triggered()
{
    QColor color = QColorDialog::getColor(Qt::black, this, "选择颜色");
    if (color.isValid()) {
        ui->textEdit->setStyleSheet(QString("QPlainTextEdit {background-color: %1}").arg(color.name()));
    }
}

void MainWindow::on_actionLetterBackgroundColor_triggered()
{

}




void MainWindow::on_actionAutoChangeLine_triggered()
{
    QPlainTextEdit::LineWrapMode mode = ui->textEdit->lineWrapMode();
    if (mode == QTextEdit::NoWrap ) {
        ui->textEdit->setLineWrapMode(QPlainTextEdit::WidgetWidth);
        ui->actionAutoChangeLine->setChecked(true);
    }
    else {
        ui->textEdit->setLineWrapMode(QPlainTextEdit::NoWrap);
        ui->actionAutoChangeLine->setChecked(false);
    }
}


void MainWindow::on_actionLetter_triggered()
{
    bool ok = false;
    QFont font = QFontDialog::getFont(&ok, this);
    if (ok)
        ui->textEdit->setFont(font);
}


void MainWindow::on_actionToolBar_triggered()
{
    bool visible = ui->toolBar->isVisible();
    ui->toolBar->setVisible(!visible);
    ui->actionToolBar->setChecked(!visible);
}


void MainWindow::on_actionStatus_triggered()
{
    bool visible = ui->statusbar->isVisible();
    ui->statusbar->setVisible(!visible);
    ui->actionStatus->setChecked(!visible);
}


void MainWindow::on_actionAll_triggered()
{
    ui->textEdit->selectAll();
}


void MainWindow::on_actionExit_triggered()
{
    if (textChange_flag) { // 存在未保存的编辑内容
        QMessageBox::StandardButton btn = QMessageBox::question(
            this,
            "保存提示",
            "有未保存的内容，是否保存？",
            QMessageBox::Save | QMessageBox::Discard | QMessageBox::Cancel
            );

        switch (btn) {
        case QMessageBox::Save:
            // 调用保存函数
            on_actionSave_triggered();
            // 若用户取消了保存对话框（filePath仍为空），则不退出
            if (filePath.isEmpty()) {
                return;
            }
            break;
        case QMessageBox::Cancel:
            // 取消退出操作，直接返回
            return;
        case QMessageBox::Discard:
            // 放弃保存，直接退出（无需额外处理）
            break;
        default:
            return;
        }
    }

    // 正常退出程序（会自动调用MainWindow析构函数释放资源）
    qApp->quit();
}


void MainWindow::on_textEdit_cursorPositionChanged()
{
    int col = 0;
    int ln = 0;
    int flg = -1;
    int pos = ui->textEdit->textCursor().position();
    QString text = ui->textEdit->toPlainText();
    for (int i = 0; i < pos; i++) {
        if (text[i] == '\n') {
            ln ++;
            flg = i;
        }
    }
    flg ++;
    col = pos - flg;
    statusCursorLabel.setText("Ln: " + QString::number(ln + 1) + "    Col: " + QString::number(col + 1));
}

