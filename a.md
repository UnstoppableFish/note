# AXI协议  
## 1、通道信号  
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
## 状态机
![状态机](./figure/2.png)  
```
always @ ( posedge M_AXI_ACLK)                                                                            
	  begin                                                                                                     
	    if (M_AXI_ARESETN == 1'b0 )                                                                             
	      begin                                                                                                                               
	        mst_exec_state      <= IDLE;                                                                
	        start_single_burst_write <= 1'b0;                                                                   
	        start_single_burst_read  <= 1'b0;                                                                   
	        compare_done      <= 1'b0;                                                                          
	        ERROR <= 1'b0;   
	      end                                                                                                   
	    else                                                                                                    
	      begin                                                                                                                                                                              
	        case (mst_exec_state)                                                                               
	                                                                                                            
	          IDLE:                                                                                                                                                       
	            if ( init_txn_pulse == 1'b1)                                                      
	              begin                                                                                         
	                mst_exec_state  <= INIT_WRITE;                                                              
	                ERROR <= 1'b0;
	                compare_done <= 1'b0;
	              end                                                                                           
	            else                                                                                            
	              begin                                                                                         
	                mst_exec_state  <= IDLE;                                                            
	              end                                                                                           
	                                                                                                            
	          INIT_WRITE:                                                                                                                                                                   
	            if (writes_done)                                                                                
	              begin                                                                                         
	                mst_exec_state <= INIT_READ;//                                                              
	              end                                                                                           
	            else                                                                                            
	              begin                                                                                         
	                mst_exec_state  <= INIT_WRITE;                                                              
	                                                                                                            
	                if (~axi_awvalid && ~start_single_burst_write && ~burst_write_active)                       
	                  begin                                                                                     
	                    start_single_burst_write <= 1'b1;                                                       
	                  end                                                                                       
	                else                                                                                        
	                  begin                                                                                     
	                    start_single_burst_write <= 1'b0; //Negate to generate a pulse                          
	                  end                                                                                       
	              end                                                                                           
	                                                                                                            
	          INIT_READ:                                                                                                                                                                   
	            if (reads_done)                                                                                 
	              begin                                                                                         
	                mst_exec_state <= INIT_COMPARE;                                                             
	              end                                                                                           
	            else                                                                                            
	              begin                                                                                         
	                mst_exec_state  <= INIT_READ;                                                               
	                                                                                                            
	                if (~axi_arvalid && ~burst_read_active && ~start_single_burst_read)                         
	                  begin                                                                                     
	                    start_single_burst_read <= 1'b1;                                                        
	                  end                                                                                       
	               else                                                                                         
	                 begin                                                                                      
	                   start_single_burst_read <= 1'b0; //Negate to generate a pulse                            
	                 end                                                                                        
	              end                                                                                           
	                                                                                                            
	          INIT_COMPARE:                                                                                                                                                                                
	            begin                                                                                           
	              ERROR <= error_reg;
	              mst_exec_state <= IDLE;                                                               
	              compare_done <= 1'b1;                                                                         
	            end                                                                                             
	          default :                                                                                         
	            begin                                                                                           
	              mst_exec_state  <= IDLE;                                                              
	            end                                                                                             
	        endcase                                                                                             
	      end                                                                                                   
	  end
```
## 2、数据传输握手协议  
VALID 和 READY信号握手  
## 3、写请求过程  
写相应通道的握手只有 一个时钟周期，目的主要是将写地址传递给从机，并且握手成功自增突发长度*数据位宽（Byte）的长度  
```
 always @(posedge M_AXI_ACLK)                                   
	  begin                                                        
	    if (M_AXI_ARESETN == 0 || init_txn_pulse == 1'b1 )                                           
	      begin                                                            
	        axi_awvalid <= 1'b0;                                           
	      end                                                                 
	    else if (~axi_awvalid && start_single_burst_write)                 
	      begin                                                            
	        axi_awvalid <= 1'b1;                                           
	      end                                                                    
	    else if (M_AXI_AWREADY && axi_awvalid)                             
	      begin                                                            
	        axi_awvalid <= 1'b0;                                           
	      end                                                              
	    else                                                               
	      axi_awvalid <= axi_awvalid;                                      
	    end  
```
## 4、写数据过程  
在WVALID和WREADY都有效时写入数据，在最后一个信号写入后拉低WVALID信号
```
assign wnext = M_AXI_WREADY & axi_wvalid;                                                  
	  always @(posedge M_AXI_ACLK)                                                      
	  begin                                                                             
	    if (M_AXI_ARESETN == 0 || init_txn_pulse == 1'b1 )                                                        
	      begin                                                                         
	        axi_wvalid <= 1'b0;                                                         
	      end                                                                                               
	    else if (~axi_wvalid && start_single_burst_write)                               
	      begin                                                                         
	        axi_wvalid <= 1'b1;                                                         
	      end                                                                                                   
	    else if (wnext && axi_wlast)                                                    
	      axi_wvalid <= 1'b0;                                                           
	    else                                                                            
	      axi_wvalid <= axi_wvalid;                                                     
	  end
```
握手周期持续直到最后一个数据写入，WLAST信号在写到突发长度-2时拉高，因为要延迟一个时钟周期  
```
always @(posedge M_AXI_ACLK)                                                      
	  begin                                                                             
	    if (M_AXI_ARESETN == 0 || init_txn_pulse == 1'b1 )                                                        
	      begin                                                                         
	        axi_wlast <= 1'b0;                                                          
	      end                                                                           
	    else if (((write_index == C_M_AXI_BURST_LEN-2 && C_M_AXI_BURST_LEN >= 2) && wnext) || (C_M_AXI_BURST_LEN == 1 ))
	      begin                                                                         
	        axi_wlast <= 1'b1;                                                          
	      end                                                                                                       
	    else if (wnext)                                                                 
	      axi_wlast <= 1'b0;                                                            
	    else if (axi_wlast && C_M_AXI_BURST_LEN == 1)                                   
	      axi_wlast <= 1'b0;                                                            
	    else                                                                            
	      axi_wlast <= axi_wlast;                                                       
	  end   
```
## 5、写响应过程  
BREADY持续拉高，BVALID在从机接收到完整数据后拉高，两者共同拉低当握手成功  
## 6.读请求和读数据
与写请求和写数据类似
![read](./figure/3.png)  




