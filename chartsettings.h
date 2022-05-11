#ifndef CHARTSETTINGS_H
#define CHARTSETTINGS_H
#include "chart.h"
#include <QObject>
#include <QWidget>
#include <QWidgetAction>
#include <QStringList>
#include <QColorDialog>
#include <QtCharts>
#include <QWindow>
#include <QMenuBar>
#include <QMenu>
#include <QToolBar>
#include <QToolButton>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QFrame>


class ChartSettings : public QWidget
{
        Q_OBJECT
protected:
    QGroupBox *_Settings;
private:
    QChartView *_ChartView;
    Chart *_Chart;
    QLabel *_Title;
    QComboBox * _Color;
public:
    ChartSettings(Chart* =nullptr, QWidget* = nullptr);
    QChart* getChart();

    void setTitleTag(QString = "");
    QString getTitleTag() const;
};

#endif // CHARTSETTINGS_H
