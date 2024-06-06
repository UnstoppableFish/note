module haddr(
   input    wire  a,
   input    wire  b,
   output   wire  s,
   output   wire  co
);

assign s = a ^ b;
assign co = a & b;

endmodule //sale

module fadd 
(
   input a,
   input b,
   input ci,
   output   s,
   output   co

);

wire  sum1;
wire  co1;
wire  co2;

assign   co = co1 | co2;
haddr add1(
   .a(a),
   .b(b),
   .s(sum1),
   .co(co1)
);

haddr add2(
   .a(sum1),
   .b(ci),
   .s(s),
   .co(co2)
);
endmodule //sale

module add(
   input    wire     [3:0]    a,
   input    wire     [3:0]    b,
   input    wire              ci,
   output   wire     [3:0]    s,
   output   wire              co
); 

wire  [4:0]    c;
assign c[0] = ci;

genvar i;

generate
   for(i = 0;i < 4;i = i + 1)begin:me
      fadd add(
         .a (a[i]),
         .b (b[i]),
         .ci(c[i]),
         .s (s[i]),
         .co(c[i + 1])
      );
   end
endgenerate

assign co = c[4];
endmodule