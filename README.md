# ORVIBO-CT30W

欧瑞博 CT30W 智能红外遥控器主板焊有一片 OW8266-02Q、一颗白色 LED、一颗红外接收头（未被使用）、四颗红外发射头。支持通过 2.4G WiFi 和家亲 APP 连接，目前售价 10 元左右。

![board](.assets/board.png)

官方固件默认波特率：74880

## 引脚定义

| 功能名称     | GPIO 引脚 |
|-------------|-----------|
| 板载按钮     | GPIO4     |
| 板载白色 LED | GPIO15    |
| 红外接收     | GPIO5     |
| 红外发送     | GPIO14    |

![pinout](.assets/pinout.png)


OW8266-02Q 与 WT8266-S1 非常相似，资料可从此获得：[WT8266-S1 WiFi Module Based on ESP8266](https://core-electronics.com.au/wt8266-s1-wifi-module-based-on-esp8266.html)。

## 烧录自定义固件

前提条件：

1. CH341 等 USB 转 TTL 工具
2. 五根杜邦线、排针
3. 电烙铁

主板测试点间距 2.0mm，可以买 2.0 排针焊接上去，也可以用 2.54 排针掰一下焊接上去。

以下测试点通过杜邦线分别连接到 CH341 引脚上：

| CT30W       | CH341     |
|-------------|-----------|
| 3V3         | VCC       |
| GND         | GND       |
| RST         | 不接      |
| GPIO0       | GND       |
| RX          | TX        |
| TX          | RX        |

将 CH341 连接电脑，此时 OW8266 模块为下载模式，可以通过 Arduino 或是其他烧录工具直接下载固件到模块。下载完后拔掉 GPIO0 重新上电即为正常启动模式。

可以使用在线烧录 ESP 固件工具（需要使用 Chromium 系浏览器）：https://esp.huhn.me/


## 固件

 - ow8266 文件夹为 Arduino 发送接收红外示例，可以使用 Arduino 工具直接下载；

