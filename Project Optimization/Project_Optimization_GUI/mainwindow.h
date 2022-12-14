#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT
public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_delete_1_clicked();

    void on_delete_2_clicked();

    void on_delete_3_clicked();

    void on_delete_4_clicked();

    void on_delete_5_clicked();

    void on_select_all_clicked();

    void on_disk_1_clicked();

    void on_disk_3_clicked();

    void on_disk_2_combo_highlighted(int index);

    void on_dashboard_btn_pressed();

    void on_processes_btn_pressed();

    void on_delete_selected_clicked();

    void on_defrag_clicked();

    void on_disk_2_combo_textActivated(const QString &arg1);

    void on_process_table_cellClicked(int row, int column);

    void on_end_process_clicked();

    void on_refresh_btn_clicked();

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
