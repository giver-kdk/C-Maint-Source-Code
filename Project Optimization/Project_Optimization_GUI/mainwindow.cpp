#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "refreshprocess.h"
#include <Windows.h>
#include <qt_windows.h>
#include <QFileInfo>
#include <QDir>
#include <QDebug>
#include <QSysInfo>
#include <QProcess>
#include <fstream>
#include <iostream>
#include <string>
#include <string.h>
#include <time.h>
#include <unistd.h>



refreshprocess refresh;

using namespace std;

QString driveSelect = NULL, processId = NULL;
void system_hidden(char argument[]);
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    // Get System Drive Letters
    foreach(QFileInfo drive, QDir::drives())
    {
        QString letter = drive.absolutePath();
        int pos = 0;
        pos = letter.lastIndexOf(QChar('/'));
        QString driveLetter = letter.left(pos);
        // Add all drives except Local Disk C
        if(driveLetter != "C:")
        {
            ui->disk_2_combo->addItem("Drive " + driveLetter);
        }
    }
    QString host, sys_arch, os;
    host = QSysInfo::machineHostName();
    sys_arch = QSysInfo::currentCpuArchitecture();
    os = QSysInfo::prettyProductName();
    ui->sys_detail_1->setText(host);
    ui->sys_detail_2_os->setText(os);
    ui->sys_detail_5->setText(sys_arch + " based");

    // Create 'C_Maint_Data' folder in temp folder location
    char folder_create[] = "mkdir C_Maint_Data";
    system_hidden(folder_create);
    char processor_info[] = "wmic cpu get name > C_Maint_Data/cpu.txt";
//    char processor_info[] = "wmic cpu get name > />C_Maint_Data/cpu.txt";
    system_hidden(processor_info);
    char ram_info[] = "wmic memorychip get capacity > C_Maint_Data/ram.txt";
//    char ram_info[] = "wmic memorychip get capacity > />C_Maint_Data/ram.txt";
    system_hidden(ram_info);
    QFile file("C_Maint_Data/ram.txt");
    if(!file.open(QFile::ReadOnly | QFile::Text))
    {
        qDebug() << "Error Opening File";
    }
    else
    {
        qDebug() << "File Opened Successfully";
        QTextStream in(&file);
        QString part1, part2, space;
        part1 = in.readLine();
        part1 = in.readLine();
        part2 = in.readLine();
        double ram, ram1, ram2;
        ram1 = part1.toDouble();
        ram2 = part2.toDouble();
        ram = (ram1 + ram2) / 1073741824;
        space = QString::number(ram);
        ui->sys_detail_4->setText(space + "GB");
        file.close();
    }
    QFile file2("C_Maint_Data/cpu.txt");
    if(!file2.open(QFile::ReadOnly | QFile::Text))
    {
        qDebug() << "Error Opening File";
    }
    else
    {
        qDebug() << "File Opened Successfully";
        QTextStream in(&file2);
        QString cpu_spec;
        cpu_spec = in.readLine();
        cpu_spec = in.readLine();
        ui->sys_detail_3_cpu->setText(cpu_spec);
        file2.close();
    }
    refresh.Reload(ui);

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_delete_1_clicked()
{
    if(ui->check_1->isChecked())
    {
        ui->check_1->setChecked(false);
    }
    else
    {
        ui->check_1->setChecked(true);
    }
}


void MainWindow::on_delete_2_clicked()
{
    if(ui->check_2->isChecked())
    {
        ui->check_2->setChecked(false);
    }
    else
    {
        ui->check_2->setChecked(true);
    }
}


void MainWindow::on_delete_3_clicked()
{
    if(ui->check_3->isChecked())
    {
        ui->check_3->setChecked(false);
    }
    else
    {
        ui->check_3->setChecked(true);
    }
}


void MainWindow::on_delete_4_clicked()
{
    if(ui->check_4->isChecked())
    {
        ui->check_4->setChecked(false);
    }
    else
    {
        ui->check_4->setChecked(true);
    }
}


void MainWindow::on_delete_5_clicked()
{
    if(ui->check_5->isChecked())
    {
        ui->check_5->setChecked(false);
    }
    else
    {
        ui->check_5->setChecked(true);
    }
}

void MainWindow::on_select_all_clicked()
{
    if((ui->check_1->isChecked()) && (ui->check_2->isChecked()) &&
    (ui->check_3->isChecked()) && (ui->check_4->isChecked()) && (ui->check_5->isChecked()))
    {
        ui->check_1->setChecked(false);
        ui->check_2->setChecked(false);
        ui->check_3->setChecked(false);
        ui->check_4->setChecked(false);
        ui->check_5->setChecked(false);
    }
    else
    {
        ui->check_1->setChecked(true);
        ui->check_2->setChecked(true);
        ui->check_3->setChecked(true);
        ui->check_4->setChecked(true);
        ui->check_5->setChecked(true);
    }
}


void MainWindow::on_disk_1_clicked()
{
    ui->radio_1->setChecked(true);
}

void MainWindow::on_disk_3_clicked()
{
    ui->radio_3->setChecked(true);
}



void MainWindow::on_disk_2_combo_highlighted(int index)
{
    if(index >= 0)
    {
        ui->radio_2->setChecked(true);
    }
}


void MainWindow::on_dashboard_btn_pressed()
{
    ui->stackedWidget->setCurrentIndex(0);
    ui->dashboard_btn->setStyleSheet(QString("QPushButton { "
                                             "background-color: #29A19C; "
                                             "color: white;"
                                             "border-radius: 10px;"
                                             "}"));
    ui->processes_btn->setStyleSheet(QString("QPushButton { "
                                             "background-color: #BFBFBF; "
                                             "color: black;"
                                             "border-radius: 10px;"
                                             "}"));
}

void MainWindow::on_processes_btn_pressed()
{
    ui->stackedWidget->setCurrentIndex(1);
    ui->dashboard_btn->setStyleSheet(QString("QPushButton { "
                                             "background-color: #BFBFBF; "
                                             "color: black;"
                                             "border-radius: 10px;"
                                             "}"));
    ui->processes_btn->setStyleSheet(QString("QPushButton { "
                                             "background-color: #29A19C; "
                                             "color: white;"
                                             "border-radius: 10px;"
                                             "}"));
}




void MainWindow::on_delete_selected_clicked()
{
    ui->progressBar->setValue(0);
    // Temp File Delete Command
    if(ui->check_1->isChecked())
    {
        char cmd1[] = "rmdir /s /q cd %temp%\\ > deleted_info.txt";
            system_hidden(cmd1);
            usleep(1000*200);
            ui->progressBar->setValue(20);
        }

    if(ui->check_2->isChecked())
    {
        char cmd2[] = "rmdir /s /q \"C:/Windows/Temp/\" > deleted_info.txt && mkdir C:\\Windows\\Temp";
        system_hidden(cmd2);
        usleep(1000*200);
        ui->progressBar->setValue(35);
    }
    if(ui->check_3->isChecked())
    {
        char cmd3[] = "rmdir /s /q \"C:/Windows/Prefetch/\" > deleted_info.txt && mkdir C:\\Windows\\Prefetch";
        system_hidden(cmd3);
        usleep(1000*200);
        ui->progressBar->setValue(50);
    }

    if(ui->check_4->isChecked())
    {
        char cmd4[] = "rmdir /s /q \"C:/Windows/SoftwareDistribution/\" > deleted_info.txt && mkdir C:\\Windows\\SoftwareDistribution";
        system_hidden(cmd4);
        usleep(1000*200);
        ui->progressBar->setValue(65);
    }

    if(ui->check_5->isChecked())
    {
        char cmd5[] = "ipconfig/FlushDNS > deleted_info.txt";
        system_hidden(cmd5);
        usleep(1000*200);
        ui->progressBar->setValue(80);
    }
    // Only complete the progress if atleast one option is selected
    if(ui->progressBar->value() != 0)
    {
        usleep(1000*200);
        ui->progressBar->setValue(100);
    }
}
void system_hidden(char argument[])
{
    // Execute cmd without windows popup
    bool result;
    STARTUPINFO si;
    PROCESS_INFORMATION pi;
    ZeroMemory(&si, sizeof(si));
    si.cb = sizeof(si);
    ZeroMemory(&pi, sizeof(pi));
    // CMD command here
    char arg[500] = "cmd.exe /c ";
    strncat(arg, argument, 450);
    // Convert char string to required LPWSTR string
    wchar_t text[500];
    mbstowcs(text, arg, strlen(arg) + 1);
    LPWSTR command = text;
    // Run process
    result = CreateProcess (NULL, command, NULL, NULL, 0, CREATE_NO_WINDOW, NULL, NULL, &si, &pi);
    if(!result)
    {
        qDebug() << "Unable to create process";
    }
    else
    {
        WaitForSingleObject(pi.hProcess, INFINITE);
    }
}

void MainWindow::on_defrag_clicked()
{
    ui->progressBar->setValue(0);
    usleep(1000*200);
    ui->progressBar->setValue(25);
    if(ui->radio_1->isChecked())
    {
        usleep(1000*200);
        ui->progressBar->setValue(40);
        char cmd6[] = "C:/Windows/System32/defrag C: > defrag.txt";
        system_hidden(cmd6);
    }
    else if(ui->radio_2->isChecked())
    {
        // 've' from last two characters of Custom Drive
        if(driveSelect != "ve")
        {
//            QString command to char * string conversion
            QString instruction = "C:/Windows/System32/defrag " + driveSelect + " > defrag.txt";
            char *cmd7;
            QByteArray instruct = instruction.toLocal8Bit();
            cmd7 = instruct.data();
            system_hidden(cmd7);
            usleep(1000*200);
            ui->progressBar->setValue(40);
        }
    }
    else if(ui->radio_3->isChecked())
    {
        char cmd8[] = "C:/Windows/System32/defrag /C > defrag.txt";
        system_hidden(cmd8);
        usleep(1000*200);
        ui->progressBar->setValue(40);
    }
    if(ui->progressBar->value() > 25)
    {
        usleep(1000*200);
        ui->progressBar->setValue(75);
        usleep(1000*200);
        ui->progressBar->setValue(100);
    }
}



void MainWindow::on_disk_2_combo_textActivated(const QString &arg1)
{
    int pos = 2;
    driveSelect = arg1.right(pos);
    qDebug() << driveSelect;
}



void MainWindow::on_process_table_cellClicked(int row, int column)
{
    if(column >= 0)
    {
        QTableWidgetItem* item = ui->process_table->item( row, 1);
        processId = item->text();
        // Remove useless whitespaces
        processId = processId.simplified();
        processId.replace( " ", "" );
        qDebug() << processId;
    }
}


void MainWindow::on_end_process_clicked()
{
    if(!processId.isEmpty())
    {
        QString command = "taskkill /f /pid " + processId;
        qDebug() << "end process cmd:" << command;
        char *cmd1;
        QByteArray number = command.toLocal8Bit();
        cmd1 = number.data();
        system_hidden(cmd1);
        qDebug() << "Task Ended";
    }
}


void MainWindow::on_refresh_btn_clicked()
{

    refresh.Reload(ui);
}

