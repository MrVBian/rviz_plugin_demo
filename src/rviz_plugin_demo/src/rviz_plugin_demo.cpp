#include "rviz_plugin_demo/rviz_plugin_demo.h"
#include "rviz_plugin_demo/ui_rviz_plugin_demo.h"

namespace rviz_plugin_demo
{
  Widget::Widget(QWidget *parent)
      : rviz_common::Panel(parent)
      , ui(new Ui::Widget)
  {
      ui->setupUi(this);
  }
  Widget::~Widget()
  {
      delete ui;
  }
  void Widget::on_pushButton_clicked()
  {
      close();
      delete(this);
  }
} // namespace rviz_plugin_demo
  //
#include <pluginlib/class_list_macros.hpp>  // plugin宏声明
PLUGINLIB_EXPORT_CLASS(rviz_plugin_demo::Widget, rviz_common::Panel)
