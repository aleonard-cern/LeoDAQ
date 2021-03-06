#ifndef EFFICIENCY_H
#define EFFICIENCY_H

#include <QWidget>
#include <QTimer>
#include "hvmodule.h"
#include "scalermodule.h"
#include "graph.h"

namespace Ui {
class Efficiency;
}

class Efficiency : public QWidget
{
    Q_OBJECT

public:
    explicit Efficiency(QWidget *parent = 0, int handleChef_ = 0);
    ~Efficiency();

    void updateHVBaseAddress(int rotSw);

    void updateScalerBaseAddress(int rotSw);

    void updateVMAX();

    void updateIMAX();
    void pauseTimer();
    void restartTimer();


private slots:
    void on_spinBox_efficiency_hv_rotary_switches_valueChanged(int rotSw);

    void on_spinBox_efficiency_scaler_rotary_switches_valueChanged(int rotSw);

    void on_spinBox_efficiency_hvmin_valueChanged(int hvmin);

    void on_spinBox_efficiency_hvmax_valueChanged(int hvmax);

    void on_pushButton_efficiency_clear_clicked();

    void on_pushButton_efficiency_start_clicked();

    void on_pushButton_efficiency_stop_clicked();

    void updateUI();

    void on_pushButton_efficiency_file_name_clicked();

    void setFileName();

    void on_pushButton_save_graph_clicked();

private:
    Ui::Efficiency *ui;
    HVModule *hvModule;
    ScalerModule *scalerModule;
    void makeItNice();
    void setPulserMode(unsigned char width, int unitIndex, int repeat = 1);
    graph* grEfficiency;
    bool stopRun;
    void updateHV(int channel, int hv);
    // members
    QTimer* timer;
    int interval;
    void launchTimer(int interval);


};

#endif // EFFICIENCY_H
