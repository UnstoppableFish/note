AXI协议  
1、通道信号  
写请求：携带地址和控制信号  
AWVALID//主机  
AWREADY//从机  
AWADDR  
AWLEN  
写数据：携带数据和控制信号  
WVALID//主机  
WREADY//从机  
WDATA  
WLAST//主机  
写相应  
BVALID//从机  
BREADY//主机  
读请求  
AWVALID//主机  
AWREADY//从机  
ARADDR  
读数据  
RVALID//从机  
RREADY//主机  
RLAST//从机  
除了写相应和读数据通道，其他都是VALID为主机，RAEADY为从机  
![1.png](./figure/1.png)  
2、数据传输握手协议  
VALID 和 READY信号握手  
READY信号等待VALID拉高后传输数据  
3、写请求过程  
写相应通道的握手只有 一个时钟周期，目的主要是将写地址传递给从机，并且握手成功自增突发长度*数据位宽（Byte）的长度  
4、写数据过程  
握手周期持续直到最后一个数据写入，WLAST信号在写到突发长度-2时拉高，因为要延迟一个时钟周期  
5、写响应过程  
BREADY持续拉高，BVALID在从机接收到完整数据后拉高，两者共同拉低当握手成功  


