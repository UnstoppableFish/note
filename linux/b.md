# 外设
## 输出模式  
推挽输出、开漏输出、复用推挽输出、复用开漏输出、浮空输入、上拉输入、下拉输入和模拟输入
### 推挽输出  
推挽输出(Push-Pull Output)：推挽输出模式是最常见的GPIO输出模式。在该模式下，引脚可以输出高电平或低电平，同时具有一定的驱动能力。引脚在输出低电平时形成低阻抗，输出高电平时形成高阻抗，可以驱动外部电路  
推挽输出(Push-Pull Output)：  
    特点：可以输出高电平和低电平，具有一定的驱动能力。  
    应用场景：用于驱动外部电路，如控制LED灯、驱动其他逻辑电路等  
### 开漏输出  
开漏输出模式是一种能够输出低电平和高阻抗的GPIO模式。在该模式下，引脚只能输出低电平，要输出高电平需要通过外部上拉电阻或其他方式。通常用于与外部器件连接，例如与开漏输出的I2C总线器件进行通信。  
开漏输出(Open-Drain Output)：  
    特点：只能输出低电平，需要外部上拉电阻将引脚拉高；具有一定的驱动能力。  
    应用场景：与外部器件连接时，如I2C总线，用于与其他设备进行通信。  
### 复用推挽  
复用推挽输出模式允许将GPIO引脚用作特定外设功能。在该模式下，引脚可以输出高电平或低电平，并具有一定的驱动能力。  
复用推挽输出(AF Push-Pull Output)：  
    特点：具有推挽输出的特性，可用于将GPIO引脚用作特定外设的功能。  
    应用场景：连接到外设的特殊功能引脚，如UART串口通信引脚、PWM输出等。  
### 复用开漏  
复用开漏输出模式允许将GPIO引脚用作特定外设功能。在该模式下，引脚只能输出低电平，要输出高电平需要通过外部上拉电阻或其他方式  
复用开漏输出(AF Open-Drain Output)：  
    特点：具有开漏输出的特性，可用于将GPIO引脚用作特定外设的功能。  
    应用场景：连接到外设的特殊功能引脚，如I2C总线通信引脚、故障信号输出等。  
### 浮空输入 
浮空输入模式是一种高阻抗输入模式。在该模式下，引脚不连接到外部电路，处于高阻抗状态。可以通过读取引脚电平来检测外部信号。  
浮空输入(Floating Input)：  
    特点：引脚处于高阻抗状态，未连接到外部电路，测量外部信号电平。  
    应用场景：接收外部信号的状态，如按键输入、传感器输入等。  
### 上拉输入  
上拉输入模式是一种具有内部上拉电阻的GPIO输入模式。在该模式下，引脚连接到外部电路，通过内部上拉电阻来维持默认电平为高电平。  
上拉输入(Pull-up Input)：  
    特点：具有内部上拉电阻，引脚的默认电平为高电平。  
    应用场景：检测外部信号为低电平时，例如按键按下。  
### 下拉输入  
下拉输入模式是一种具有内部下拉电阻的GPIO输入模式。在该模式下，引脚连接到外部电路，通过内部下拉电阻来维持默认电平为低电平。  
下拉输入(Pull-down Input)：  
    特点：具有内部下拉电阻，引脚的默认电平为低电平。  
    应用场景：检测外部信号为高电平时，例如按键抬起。  
### 模拟输入  
模拟输入模式是一种用于ADC（模数转换器）输入的特殊模式。在该模式下，引脚可以接收连续变化的模拟信号。  
模拟输入(Analog Input)：  
    特点：用于接收连续变化的模拟信号，通常与ADC（模数转换器）配合使用。  
    应用场景：测量传感器信号、音频输入等模拟信号的变化。  