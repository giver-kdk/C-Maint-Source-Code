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
void system_hide(char argument[]);

void refreshprocess::Reload(Ui::MainWindow* ui)
{
    ui->process_table->setRowCount(0);
    char process[] = "tasklist > C_Maint_Data/process.txt";
//    char process[] = "tasklist > />C_Maint_Data/process.txt";
    system_hide(process);
    QFile file3("C_Maint_Data/process.txt");
    if(!file3.open(QFile::ReadOnly | QFile::Text))
    {
        qDebug() << "Error Opening File";
    }
    else
    {
        int row = 0, column = 0, position = 0;
        qDebug() << "Refresh File Opened Successfully";
        QTextStream in(&file3);
        QString activities, name, pid, session, memory;
        activities = in.readLine();
        activities = in.readLine();
        activities = in.readLine();

        while (!activities.isNull())
        {
            activities = in.readLine();
            if(!activities.isEmpty())
            {
                ui->process_table->insertRow(position);
                name = activities.left(25);
                pid = activities.sliced(26, 8);
                session = activities.sliced(35, 16);
                memory = activities.right(12);
                ui->process_table->setItem(row, column, new QTableWidgetItem(name));
                column++;
                ui->process_table->setItem(row, column, new QTableWidgetItem(pid));
                column++;
                ui->process_table->setItem(row, column, new QTableWidgetItem(session));
                column++;
                ui->process_table->setItem(row, column, new QTableWidgetItem(memory));
                row++;
                position++;
                column = 0;
            }

        }

        activities = in.readLine();
        file3.close();
    }
}
void system_hide(char argument[])
{
    // Execute cmd without windows popup
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
    CreateProcess (NULL, command, NULL, NULL, 0, CREATE_NO_WINDOW, NULL, NULL, &si, &pi);
}
