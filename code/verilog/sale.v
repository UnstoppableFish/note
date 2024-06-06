module sale 
#(
   parameter N = 3'd7
)
(
   input    wire     clk,
   input    wire     rstn,
   output   wire     clk0,
   output   wire     clk1,
   output   wire     clk2,
   output   wire     clk3
);

reg   [2:0] cnt0;
reg         clk0_reg;
always @(posedge clk or negedge rstn) begin
   if(!rstn)
      cnt0 <= 'd0;
   else if(cnt0 == 'd2)
      cnt0 <= 'd0;
   else
      cnt0 <= cnt0 + 1'b1;
end

always @(posedge clk or negedge rstn) begin
   if(!rstn)
      clk0_reg <= 'd0;
   else if(cnt0 == 'd0 || cnt0 == 'd1)
      clk0_reg <= ~clk0_reg;
   else
      clk0_reg <= clk0_reg;
end

assign clk0 = clk0_reg;

reg   [2:0] cnt1;
reg         clk1_reg0;
reg         clk1_reg1;
always @(posedge clk or negedge rstn) begin
   if(!rstn)
      cnt1 <= 'd0;
   else if(cnt1 == (N - 1))
      cnt1 <= 'd1;
   else
      cnt1 <= cnt1 + 1'b1;
end

always @(posedge clk or negedge rstn) begin
   if(!rstn)
      clk1_reg0 <= 'd0;
   else if(cnt1 == 'd0 || cnt1 == (N - 1) >> 1)
      clk1_reg0 <= ~clk1_reg0;
   else
      clk1_reg0 <= clk1_reg0;
end

always @(negedge clk or negedge rstn) begin
   if(!rstn)
      clk1_reg1 <= 'd0;
   else if(cnt1 == 'd0 || cnt1 == (N - 1) >> 1)
      clk1_reg1 <= ~clk1_reg1;
   else
      clk1_reg1 <= clk1_reg1;
end

assign clk1 = clk1_reg0 & clk1_reg1;

endmodule //sale