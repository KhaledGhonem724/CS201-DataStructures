#ifndef MAINHEADER_H
#define MAINHEADER_H
#include <QListWidgetItem>
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
    void on_show_report_clicked();
    void on_show_sourceCode_on_github_clicked();
    void on_show_sourceCode_on_drive_clicked();

    void on_array_insert_button_clicked();
    void on_array_deleteByIndex_button_clicked();
    void on_array_deleteByValue_button_clicked();
    void on_array_Enlarge_button_clicked();
    void on_array_sort_button_clicked();
    void on_array_display_button_clicked();

    void on_SLL_insertFirst_button_clicked();
    void on_SLL_insertLast_button_clicked();
    void on_SLL_deleteByValue_button_clicked();
    void on_SLL_display_button_clicked();
    void on_SLL_deleteFirst_button_clicked();
    void on_SLL_deleteLast_button_clicked();

    void on_CLL_insertFirst_button_clicked();
    void on_CLL_insertLast_button_clicked();
    void on_CLL_deleteByValue_button_clicked();
    void on_CLL_display_button_clicked();
    void on_CLL_circular_display_button_clicked();

    void on_DLL_insertFirst_button_clicked();
    void on_DLL_insertLast_button_clicked();
    void on_DLL_deleteByValue_button_clicked();
    void on_DLL_display_button_clicked();
    void on_DLL_reverse_display_button_clicked();

    void on_DCLL_insertFirst_button_clicked();
    void on_DCLL_insertLast_button_clicked();
    void on_DCLL_deleteByValue_button_clicked();
    void on_DCLL_display_button_clicked();
    void on_DCLL_circular_display_button_clicked();
    void on_DCLL_reverse_display_button_clicked();

    void on_stack_Push_button_clicked();
    void on_stack_Pop_button_clicked();
    void on_stack_Peek_button_clicked();
    void on_stack_Display_button_clicked();

    void on_SQ_enqueue_buttom_clicked();
    void on_SQ_dequeue_buttom_clicked();
    void on_SQ_getfront_buttom_clicked();
    void on_SQ_display_buttom_clicked();

    void on_CQ_enqueue_buttom_clicked();
    void on_CQ_dequeue_buttom_clicked();
    void on_CQ_getfront_buttom_clicked();
    void on_CQ_display_buttom_clicked();
    void on_CQ_circular_display_buttom_clicked();

    void on_DQ_enqueue_back_buttom_clicked();
    void on_DQ_enqueue_front_buttom_clicked();
    void on_DQ_dequeue_front_button_clicked();
    void on_DQ_dequeue_back_button_clicked();
    void on_DQ_getfront_buttom_clicked();
    void on_DQ_getrear_buttom_clicked();
    void on_DQ_display_buttom_clicked();

private:
    Ui::MainWindow *ui;
};
#endif
