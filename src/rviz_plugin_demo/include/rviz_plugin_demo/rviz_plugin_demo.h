#ifndef WIDGET_H
#define WIDGET_H

#include<rclcpp/rclcpp.hpp>
#include<rviz_common/panel.hpp>
#include <QWidget>

// QT_BEGIN_NAMESPACE
namespace Ui { class Widget; }
// QT_END_NAMESPACE

namespace rviz_plugin_demo
{
  class Widget : public rviz_common::Panel
  {
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();

private slots:
    void on_pushButton_clicked();

private:
    Ui::Widget *ui;
  };
} // namespace rvzi_plugin_demo
#endif // WIDGET_H
