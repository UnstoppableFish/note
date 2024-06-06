`timescale 1ns/1ns
module tb_sim();

reg     clk;
reg    rstn;
reg   din;
wire  out;

initial begin
   clk = 1'b1;
   rstn <= 1'b0;
   din <= 1'b0;
   #20
   rstn <= 1'b1;
   #20
   din <= 1'b1;
   #20
   din <= 1'b0;
   #20
   din <= 1'b1;
   #20
   din <= 1'b1;
   #20
   din <= 1'b0;
end

always #10 clk = ~clk;

sale sa
(
   .clk (clk ),
   .rstn(rstn),
   .din (din ),
   .out (out )

);

endmodule